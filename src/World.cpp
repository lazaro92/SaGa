#include <Game/World.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


World::World(sf::RenderTarget& outputTarget)
: mTarget(outputTarget)
, mWorldView(outputTarget.getDefaultView())
, mTextures() 
, mSceneGraph()
, mSceneLayers()
, mSpawnPosition(20.0f, 20.0f)
, mPlayerCharacter(nullptr)
{
    loadTextures();
    buildScene();
}

void World::update(sf::Time dt)
{
    mPlayerCharacter->setVelocity(0.f, 0.f);

    // Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
    while (!mCommandQueue.isEmpty())
        mSceneGraph.onCommand(mCommandQueue.pop(), dt);

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
} 

void World::buildScene()
{
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount; ++i)
    {
        Category::Type category = (i == LowerAir) ? Category::SceneAirLayer : Category::None;

        SceneNode::Ptr layer(new SceneNode(category));
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    // Add player's character
    std::unique_ptr<Character> player(new Character(Character::MutantMale, mTextures));
    mPlayerCharacter = player.get();
    mPlayerCharacter->setPosition(mSpawnPosition);
    mSceneLayers[UpperAir]->attachChild(std::move(player));


}
