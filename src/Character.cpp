#include <Game/Character.hpp>
#include <Game/DataTables.hpp>
#include <Game/Utility.hpp>
#include <Game/CommandQueue.hpp>
#include <Game/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Rect.hpp>


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
, mMovementSpriteChangeTime(sf::Time::Zero)
, mIsRightSpriteMovement(false)
{
	centerOrigin(mSprite);
}

void Character::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Character::updateCurrent(sf::Time dt, CommandQueue& commands)
{
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

void Character::updateMovementSprite(sf::Time dt)
{
    mMovementSpriteChangeTime += dt;

    if (mMovementSpriteChangeTime >= sf::seconds(.8f))
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

