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
, mSpawnPosition(tileToPoint(7, 7))
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
    std::unique_ptr<Character> player(new Character(Character::MutantMale, mTextures));
    mPlayerCharacter = player.get();
    mPlayerCharacter->setPosition(mSpawnPosition);
    mSceneLayers[Entities]->attachChild(std::move(player));
}

void World::handleCollisions()
{
    if (mPlayerCharacter->wantToMove())
    {
        sf::Vector2f destinationPosition = mPlayerCharacter->getDestinationPosition();
        sf::Vector2i destinationCell = pointToTile(destinationPosition.x, destinationPosition.y);
        
        if (mTileset->isWalkable(destinationCell.x, destinationCell.y))
        {
            mPlayerCharacter->startMoving();
        }
        else {
            mPlayerCharacter->stopMoving();
        }
    }
}
