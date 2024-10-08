#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <Game/SceneNode.hpp>


class Entity : public SceneNode
{
    public:
        explicit            Entity();

        void                setVelocity(sf::Vector2f velocity);
        void                setVelocity(float vx, float vy);
        void                accelerate(sf::Vector2f velocity);
        void                accelerate(float vx, float vy);
        sf::Vector2f        getVelocity() const;

    protected:
        virtual void        updateCurrent(sf::Time dt, CommandQueue& commands);


    private:
        sf::Vector2f        mVelocity;
};

#endif // GAME_ENTITY_HPP
