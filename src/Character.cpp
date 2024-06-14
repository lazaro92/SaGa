#include <Game/Character.hpp>
#include <Game/DataTables.hpp>
#include <Game/Utility.hpp>
#include <Game/CommandQueue.hpp>
#include <Game/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <cmath>


using namespace std::placeholders;

namespace
{
    const std::vector<CharacterData> Table = initializeCharacterData();
}


Character::Character(Type type, const TextureHolder& textures)
: Entity()
, mType(type)
, mSprite(textures.get(Table[type].texture), Table[type].textureRect)
, mDirection(Direction::South)
, mOriginalPosition(0.f, 0.f)
, mMovementSpriteChangeTime(sf::Time::Zero)
, mIsRightSpriteMovement(false)
, mIsMoving(false)
, mMoveTime(0.f)
{
    centerOrigin(mSprite);
}

void Character::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Character::updateCurrent(sf::Time dt, CommandQueue& commands)
{
    processDisplacement(dt);
    updateMovementSprite(dt);
    Entity::updateCurrent(dt, commands);
}

unsigned int Character::getCategory() const
{
    return Category::PlayerCharacter;
}

void Character::setDirection(Direction direction) {
    mDirection = direction;

    sf::IntRect textureRect = Table[mType].textureRect;

    if (Direction::North == direction)
        textureRect.left = 96;
    else if (Direction::East == direction)
        textureRect.left = 32;
    else if (Direction::South == direction)
        textureRect.left = 0;
    else
        textureRect.left = 64;

    mSprite.setTextureRect(textureRect);
    mIsRightSpriteMovement = false;
}

void Character::startMoving(Direction direction) {
    if (mIsMoving) return;

    mIsMoving = true;
    if (direction != mDirection)
        setDirection(direction);
    mOriginalPosition = getPosition();
}

void Character::stopMoving() {
   mIsMoving = false;
}


void Character::updateMovementSprite(sf::Time dt)
{
    mMovementSpriteChangeTime += dt;
    float movementTime = mIsMoving ? .5f: .8f;

    if (mMovementSpriteChangeTime >= sf::seconds(movementTime))
    {
        sf::IntRect textureRect = mSprite.getTextureRect();

        if (mIsRightSpriteMovement)
            textureRect.left -= 16;
        else
            textureRect.left += 16;
        mSprite.setTextureRect(textureRect);
        mIsRightSpriteMovement = !mIsRightSpriteMovement;
        mMovementSpriteChangeTime = sf::Time::Zero;
    }
}

void Character::processDisplacement(sf::Time dt)
{
    if (mIsMoving) {
        mMoveTime += dt.asSeconds();
        float lerpPercent = fmin(mMoveTime * 3.0f, 1.0f);

        sf::Vector2f destinationPosition = mOriginalPosition;
        if (Direction::North == mDirection)
            destinationPosition.y -= 16;
        else if (Direction::East == mDirection)
            destinationPosition.x += 16;
        else if (Direction::South == mDirection)
            destinationPosition.y += 16;
        else
            destinationPosition.x -= 16;
        
        sf::Vector2f nextPosition = getPosition();
        if (Direction::East == mDirection || Direction::West == mDirection)
        {
            if (nextPosition.x == destinationPosition.x)
            {
                mIsMoving = false;
                mOriginalPosition.x = destinationPosition.x;
                mMoveTime = 0.f;
            }
            else
                nextPosition.x = lerp(mOriginalPosition.x, destinationPosition.x, lerpPercent);
        }
        else
        {
            if (nextPosition.y == destinationPosition.y)
            {
                mIsMoving = false;
                mOriginalPosition.y = destinationPosition.y;
                mMoveTime = 0.f;
            }
            else
                nextPosition.y = lerp(mOriginalPosition.y, destinationPosition.y, lerpPercent);
        }
        setPosition(nextPosition);
    }

}

