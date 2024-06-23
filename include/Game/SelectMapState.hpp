#ifndef GAME_SELECTMAPSTATE_HPP
#define GAME_SELECTMAPSTATE_HPP

#include <Game/State.hpp>
#include <Game/Player.hpp>


class SelectMapState : public State
{
    public:
                            SelectMapState(StateStack& stack, Context context);

        virtual void        draw();
        virtual bool        update(sf::Time dt);
        virtual bool        handleEvent(const sf::Event& event);
};

#endif // GAME_SELECTMAPSTATE_HPP