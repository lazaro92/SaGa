#include <Game/SelectMapState.hpp>
#include <Game/MusicPlayer.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


SelectMapState::SelectMapState(StateStack& stack, Context context)
: State(stack, context)
, mGUIPanelText(*context.textures, *context.fonts, 600, 76)
, mGUIPanelChoicesMap(*context.textures, 600, 400, 3)
{
    mGUIPanelText.setText("Select a map", true);
    mGUIPanelText.setPosition(100.f, 50.f);

    mGUIPanelChoicesMap.setPosition(100.f, 150.f);

    auto libraryOption = std::make_shared<GUI::Option>("Library", context);
	libraryOption->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::Game);
	});

    auto museumOption = std::make_shared<GUI::Option>("Museum", context);
	museumOption->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::Game);
	});

    auto towerOption = std::make_shared<GUI::Option>("Tower", context);
	towerOption->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::Game);
	});

	auto townOption = std::make_shared<GUI::Option>("Town", context);
	townOption->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::Game);
	});

    mGUIPanelChoicesMap.pack(libraryOption);
    mGUIPanelChoicesMap.pack(museumOption);
    mGUIPanelChoicesMap.pack(towerOption);
	mGUIPanelChoicesMap.pack(townOption);
}

void SelectMapState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.setView(window.getDefaultView());

    window.draw(mGUIPanelText);
    window.draw(mGUIPanelChoicesMap);
}

bool SelectMapState::update(sf::Time dt)
{
    return false;
}

bool SelectMapState::handleEvent(const sf::Event& event)
{
    mGUIPanelChoicesMap.handleEvent(event);
    return false;
}