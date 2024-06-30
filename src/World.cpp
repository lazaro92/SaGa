#include <Game/World.hpp>
#include <Game/TilesetNode.hpp>
#include <Game/Utility.hpp>
#include <Game/DataTables.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>

namespace
{
    const std::vector<MapData> Table = initializeMapData();
}

World::World(sf::RenderTarget& outputTarget, TilesetNode::Map currentMap)
: mTarget(outputTarget)
, mWorldView(outputTarget.getDefaultView())
, mTextures() 
, mSceneGraph()
, mSceneLayers()
, mPlayerCharacter(nullptr)
, mTileset(nullptr)
{
    loadTextures();
    buildScene(currentMap);

    mWorldView.zoom(0.3f);
    mWorldView.setCenter(mPlayerCharacter->getPosition());
}

void World::update(sf::Time dt)
{
    if (mPlayerCharacter->isMoving())
        mWorldView.setCenter(mPlayerCharacter->getPosition());

    // Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
    while (!mCommandQueue.isEmpty())
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);

    handleCollisions();

    // Regular update step, adapt position (correct if outside view)
    mSceneGraph.update(dt, mCommandQueue);

}

void World::draw()
{
    mTarget.setView(mWorldView);
    mTarget.draw(mSceneGraph);

}

CommandQueue& World::getCommandQueue()
{
    return mCommandQueue;
}

void World::loadTextures()
{
    mTextures.load(Textures::Characters, "media/textures/characters.png");
    mTextures.load(Textures::Library, "media/textures/library.png");
} 

void World::buildScene(TilesetNode::Map currentMap)
{
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode(Category::None));
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    // Add tilemap's node category
    std::unique_ptr<TilesetNode> tilesetNode(new TilesetNode(currentMap, mTextures));
    mTileset = tilesetNode.get();
    mSceneLayers[Background]->attachChild(std::move(tilesetNode));

    addCharacters(currentMap);

    // Add player's character
    std::unique_ptr<Character> player(new Character(Table[currentMap].playerCharacter.type, Table[currentMap].playerCharacter.direction, mTextures));
    mPlayerCharacter = player.get();
    mPlayerCharacter->setPosition(tileToPoint(Table[currentMap].playerCharacter.tilePosition.x, Table[currentMap].playerCharacter.tilePosition.y));
    mPlayerCharacter->setIsControlledByPlayer(true);
    mSceneLayers[Entities]->attachChild(std::move(player));
}

void World::addCharacters(TilesetNode::Map currentMap) {

    for(auto& sceneCharacterData : Table[currentMap].characters)
    {
        std::unique_ptr<Character> character(new Character(sceneCharacterData.type, sceneCharacterData.direction, mTextures));
        character.get()->setPosition(tileToPoint(sceneCharacterData.tilePosition.x, sceneCharacterData.tilePosition.y));
        mSceneLayers[Entities]->attachChild(std::move(character));
    }
}

void World::handleCollisions()
{
    Command command;
    command.category = Category::PlayerCharacter | Category::NPC;
    command.action = derivedAction<Character>([this] (Character& character, sf::Time)
    {
        if (character.wantToMove())
        {
            sf::Vector2f destinationPosition = character.getDestinationPosition();
            sf::Vector2i destinationCell = pointToTile(destinationPosition.x, destinationPosition.y);
            
            if (mTileset->isWalkable(destinationCell.x, destinationCell.y))
                character.startMoving();
            else 
                character.stopMoving();
        }
    });
    
    mCommandQueue.push(command);
}
