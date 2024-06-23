#include <Game/SelectMapState.hpp>
#include <Game/MusicPlayer.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


SelectMapState::SelectMapState(StateStack& stack, Context context)
: State(stack, context)
{
    context.music->stop();
}

void SelectMapState::draw()
{
}

bool SelectMapState::update(sf::Time dt)
{
    return true;
}

bool SelectMapState::handleEvent(const sf::Event& event)
{
    return true;
}