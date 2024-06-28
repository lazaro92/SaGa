#include <Game/SelectMapState.hpp>
#include <Game/MusicPlayer.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


SelectMapState::SelectMapState(StateStack& stack, Context context)
: State(stack, context)
, mGUIPanelText(*context.textures, *context.fonts, 600, 76)
, mGUIPanelWorldChoices(*context.textures, 600, 400)
{
    mGUIPanelText.setText("Select a map", true);
    mGUIPanelText.setPosition(100.f, 50.f);
    mGUIPanelWorldChoices.setPosition(100.f, 150.f);
}

void SelectMapState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

    window.draw(mGUIPanelText);
    window.draw(mGUIPanelWorldChoices);
}

bool SelectMapState::update(sf::Time dt)
{
    return true;
}

bool SelectMapState::handleEvent(const sf::Event& event)
{
    return true;
}