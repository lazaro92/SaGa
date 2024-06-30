#ifndef GAME_SELECTMAPSTATE_HPP
#define GAME_SELECTMAPSTATE_HPP

#include <Game/State.hpp>
#include <Game/Player.hpp>
#include <Game/GUI/PanelText.hpp>
#include <Game/GUI/PanelChoices.hpp>


class SelectMapState : public State
{
    public:
                            SelectMapState(StateStack& stack, Context context);

        virtual void        draw();
        virtual bool        update(sf::Time dt);
        virtual bool        handleEvent(const sf::Event& event);

    private:

        GUI::PanelText   		mGUIPanelText;
        GUI::PanelChoices       mGUIPanelChoicesMap;
        Player&                 mPlayer;
        
};

#endif // GAME_SELECTMAPSTATE_HPP