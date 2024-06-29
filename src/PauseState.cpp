#include <Game/PauseState.hpp>
#include <Game/MusicPlayer.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


PauseState::PauseState(StateStack& stack, Context context)
: State(stack, context)
, mGUIPanelText(*context.textures, *context.fonts, 600, 76)
, mGUIPanelChoicesMap(*context.textures, 600, 400, 2)
{
    mGUIPanelText.setText("Pause", true);
    mGUIPanelText.setPosition(100.f, 50.f);

    mGUIPanelChoicesMap.setPosition(100.f, 150.f);

    auto continueOption = std::make_shared<GUI::Option>("Continue", context);
	continueOption->setCallback([this] ()
	{
		requestStackPop();
		getContext().music->setPaused(false);
	});

    auto selectMapOption = std::make_shared<GUI::Option>("Select map", context);
	selectMapOption->setCallback([this] ()
	{
		getContext().music->stop();
		requestStateClear();
		requestStackPush(States::SelectMap);
	});

    auto closeOption = std::make_shared<GUI::Option>("Close", context);
	closeOption->setCallback([this] ()
	{
		requestStateClear();
	});

    mGUIPanelChoicesMap.pack(continueOption);
    mGUIPanelChoicesMap.pack(selectMapOption);
    mGUIPanelChoicesMap.pack(closeOption);

	getContext().music->setPaused(true);
}

void PauseState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

    window.draw(mGUIPanelText);
    window.draw(mGUIPanelChoicesMap);
}

bool PauseState::update(sf::Time dt)
{
    return false;
}

bool PauseState::handleEvent(const sf::Event& event)
{
    mGUIPanelChoicesMap.handleEvent(event);
    return false;
}