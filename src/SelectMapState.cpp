#include <Game/SelectMapState.hpp>
#include <Game/MusicPlayer.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


SelectMapState::SelectMapState(StateStack& stack, Context context)
: State(stack, context)
, mGUIPanelText(*context.textures, *context.fonts, 500, 76)
{
    mGUIPanelText.setText("Lorem Ipsum", true);
    mGUIPanelText.setPosition(100.f, 100.f);
}

void SelectMapState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

    window.draw(mGUIPanelText);
}

bool SelectMapState::update(sf::Time dt)
{
    return true;
}

bool SelectMapState::handleEvent(const sf::Event& event)
{
    return true;
}