#ifndef GAME_CHARACTER_HPP
#define GAME_CHARACTER_HPP

#include <Game/Entity.hpp>
#include <Game/Command.hpp>
#include <Game/ResourceIdentifiers.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>


class Character : public Entity
{
    public:
        enum Type
        {
            HumanMale,
            HumanFemale,
            MutantMale,
            MutantFemale,
            TypeCount,
        };

        enum Direction
        {
            North,
            East,
            South,
            West,
        };


    public:
                                Character(Type type, const TextureHolder& textures);

        virtual unsigned int    getCategory() const;

    public:
        void                    setDirection(Direction direction);
        unsigned int            getDirection();
        sf::Vector2f            getOriginalPosition();
        sf::Vector2f            getDestinationPosition();
        
        void                    requestMove(Direction direction);
        void                    startMoving();
        void                    stopMoving();
        bool                    wantToMove();

    private:
        virtual void            drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void            updateCurrent(sf::Time dt, CommandQueue& commands);

    private:
        void                    updateMovementSprite(sf::Time dt);
        void                    processDisplacement(sf::Time dt);

    private:
        Type                    mType;
        Direction               mDirection;
        sf::Sprite              mSprite;
        sf::Vector2f            mOriginalPosition;
        sf::Vector2f            mDestinationPosition;
        sf::Time                mMovementSpriteChangeTime;
        bool                    mIsRightSpriteMovement;
        unsigned int            mIsMoving; // 0 not moving | 1 request move | 2 moving
        float                   mMoveTime;
};

#endif // GAME_CHARACTER_HPP
