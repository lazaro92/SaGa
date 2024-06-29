#ifndef GAME_PAUSESTATE_HPP
#define GAME_PAUSESTATE_HPP

#include <Game/State.hpp>
#include <Game/GUI/PanelText.hpp>
#include <Game/GUI/PanelChoices.hpp>


class PauseState : public State
{
    public:
                            PauseState(StateStack& stack, Context context);

        virtual void        draw();
        virtual bool        update(sf::Time dt);
        virtual bool        handleEvent(const sf::Event& event);

    private:

        GUI::PanelText   		mGUIPanelText;
        GUI::PanelChoices       mGUIPanelChoicesMap;
        
};

#endif // GAME_PAUSESTATE_HPP