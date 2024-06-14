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
        void                    startMoving(Direction direction);
        void                    stopMoving();

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
        sf::Time                mMovementSpriteChangeTime;
        bool                    mIsRightSpriteMovement;
        bool                    mIsMoving;
        float                   mMoveTime;
};

#endif // GAME_CHARACTER_HPP
