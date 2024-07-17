#include <Game/SelectMapState.hpp>
#include <Game/MusicPlayer.hpp>
#include <Game/TilesetNode.hpp>

#include <SFML/Graphics/RenderWindow.hpp>


SelectMapState::SelectMapState(StateStack& stack, Context context)
: State(stack, context)
, mGUIPanelText(*context.textures, *context.fonts, 600, 76)
, mGUIPanelChoicesMap(*context.textures, 600, 400, 3)
, mPlayer(*context.player)
{
    mGUIPanelText.setText("Select a map", true);
    mGUIPanelText.setPosition(100.f, 50.f);

    mGUIPanelChoicesMap.setPosition(100.f, 150.f);

    auto library1fOption = std::make_shared<GUI::Option>("Library 1F", context);
	library1fOption->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::Game);
		mPlayer.setCurrentMap(TilesetNode::Library1F);
		mPlayer.setCurrentSpawnPosition(sf::Vector2i(22, 24));
	});

    auto library2fOption = std::make_shared<GUI::Option>("Library 2F", context);
	library2fOption->setCallback([this] ()
	{
		requestStackPop();
		requestStackPush(States::Game);
		mPlayer.setCurrentMap(TilesetNode::Library2F);
		mPlayer.setCurrentSpawnPosition(sf::Vector2i(17, 7));
	});

    mGUIPanelChoicesMap.pack(library1fOption);
    mGUIPanelChoicesMap.pack(library2fOption);
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