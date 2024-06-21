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
, mDestinationPosition(0.f, 0.f)
, mMovementSpriteChangeTime(sf::Time::Zero)
, mIsRightSpriteMovement(false)
, mIsControlledByPlayer(false)
, mIsMoving(0)
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

    if (!mIsControlledByPlayer && !mIsMoving)
    {
        requestMove(static_cast<Direction>(randomInt(Direction::Size)));
    }

    Entity::updateCurrent(dt, commands);
}

unsigned int Character::getCategory() const
{
    return mIsControlledByPlayer ? Category::PlayerCharacter: Category::NPC;
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

unsigned int Character::getDirection()
{
    return mDirection;
}

sf::Vector2f Character::getOriginalPosition()
{
    return mOriginalPosition;
}

sf::Vector2f Character::getDestinationPosition()
{
    return mDestinationPosition;
}

void Character::setIsControlledByPlayer(bool isControlledByPlayer)
{
    mIsControlledByPlayer = isControlledByPlayer;
}

void Character::requestMove(Direction direction)
{
    if (mIsMoving != 0) return;
    
    mOriginalPosition = getPosition();
    mDestinationPosition = getPosition();

    if (direction != mDirection)
        setDirection(direction);

    if (Direction::North == mDirection)
        mDestinationPosition.y -= 16;
    else if (Direction::East == mDirection)
        mDestinationPosition.x += 16;
    else if (Direction::South == mDirection)
        mDestinationPosition.y += 16;
    else
        mDestinationPosition.x -= 16;

    mIsMoving = 1;
}

bool Character::wantToMove()
{
    return mIsMoving == 1;
}

bool Character::isMoving()
{
    return mIsMoving == 2;
}

void Character::startMoving() {
    if (mIsMoving == 2) return;
    mIsMoving = 2;
}

void Character::stopMoving() {
   mIsMoving = 0;
   mDestinationPosition = mOriginalPosition;
}

void Character::updateMovementSprite(sf::Time dt)
{
    mMovementSpriteChangeTime += dt;
    float movementTime = (mIsMoving == 2) ? .4f: .8f;

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
    if (mIsMoving != 2) return;

    mMoveTime += dt.asSeconds();
    float lerpPercent = fmin(mMoveTime * 3.f, 1.f);

    sf::Vector2f nextPosition = getPosition();
    if (Direction::East == mDirection || Direction::West == mDirection)
        nextPosition.x = lerp(mOriginalPosition.x, mDestinationPosition.x, lerpPercent);
    else
        nextPosition.y = lerp(mOriginalPosition.y, mDestinationPosition.y, lerpPercent);

    setPosition(nextPosition);

    if (lerpPercent == 1.f)
    {
        mIsMoving = 0;
        mOriginalPosition = mDestinationPosition;
        mMoveTime = 0.f;
    }

}

