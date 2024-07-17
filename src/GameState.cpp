#include <Game/GameState.hpp>
#include <Game/MusicPlayer.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


GameState::GameState(StateStack& stack, Context context)
: State(stack, context)
, mWorld(*context.window, context.player->getCurrentMap(), context.player->getCurrentSpawnPosition())
, mPlayer(*context.player)
{
    if (!context.music->isPlayingTheme(Music::Dungeon))
        context.music->play(Music::Dungeon);
}

void GameState::draw()
{
    mWorld.draw();
}

bool GameState::update(sf::Time dt)
{
    mWorld.update(dt);

    TilesetNode::Map nextMap = mWorld.getNextMap();
    if (nextMap != TilesetNode::Map::None) {
        requestStackPop();
		requestStackPush(States::Game);
        mPlayer.setCurrentMap(nextMap);
        mPlayer.setCurrentSpawnPosition(mWorld.getNextSpawnPosition());
    }

    CommandQueue& commands = mWorld.getCommandQueue();
    mPlayer.handleRealtimeInput(commands);

    return true;
}

bool GameState::handleEvent(const sf::Event& event)
{
    // Game input handling
    CommandQueue& commands = mWorld.getCommandQueue();
    mPlayer.handleEvent(event, commands);
    
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        requestStackPush(States::Pause);

    return true;
}