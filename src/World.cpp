#include <Game/World.hpp>
#include <Game/TilesetNode.hpp>
#include <Game/Utility.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>


World::World(sf::RenderTarget& outputTarget)
: mTarget(outputTarget)
, mWorldView(outputTarget.getDefaultView())
, mTextures() 
, mSceneGraph()
, mSceneLayers()
, mSpawnPosition(tileToPoint(22, 24))
, mPlayerCharacter(nullptr)
, mTileset(nullptr)
{
    loadTextures();
    buildScene();
}

void World::update(sf::Time dt)
{
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

void World::buildScene()
{
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode(Category::None));
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    // Add tilemap's node category
    std::unique_ptr<TilesetNode> tilesetNode(new TilesetNode(TilesetNode::Library, mTextures));
    mTileset = tilesetNode.get();
    mSceneLayers[Background]->attachChild(std::move(tilesetNode));

    // Add player's character
    std::unique_ptr<Character> player(new Character(Character::HumanMale, mTextures));
    mPlayerCharacter = player.get();
    mPlayerCharacter->setPosition(mSpawnPosition);
    mPlayerCharacter->setIsControlledByPlayer(true);
    mSceneLayers[Entities]->attachChild(std::move(player));

    addCharacters();
}

void World::addCharacters() {

    std::unique_ptr<Character> character1(new Character(Character::HumanFemale, mTextures));
    std::unique_ptr<Character> character2(new Character(Character::MutantMale, mTextures));
    std::unique_ptr<Character> character3(new Character(Character::Soldier, mTextures));
    std::unique_ptr<Character> character4(new Character(Character::YellowSlime, mTextures));

    character1.get()->setPosition(tileToPoint(22, 16));
    character2.get()->setPosition(tileToPoint(14, 13));
    character3.get()->setPosition(tileToPoint(7, 7));
    character4.get()->setPosition(tileToPoint(8, 20));

    mSceneLayers[Entities]->attachChild(std::move(character1));
    mSceneLayers[Entities]->attachChild(std::move(character2));
    mSceneLayers[Entities]->attachChild(std::move(character3));
    mSceneLayers[Entities]->attachChild(std::move(character4));

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
            {
                character.startMoving();
            }
            else {
                character.stopMoving();
            }
        }
    });
    
    mCommandQueue.push(command);
}
