#include <Game/World.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


World::World(sf::RenderTarget& outputTarget)
: mTarget(outputTarget)
, mWorldView(outputTarget.getDefaultView())
, mTextures() 
, mSceneGraph()
, mSceneLayers()
{
}

void World::update(sf::Time dt)
{
}

void World::draw()
{
}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}
