#include <Game/Character.hpp>
#include <Game/Utility.hpp>
#include <Game/CommandQueue.hpp>
#include <Game/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


using namespace std::placeholders;

Character::Character(Type type, const TextureHolder& textures)
: Entity()
, mType(type)
, mSprite(textures.get(Textures::Characters), sf::IntRect(0, 0, 16, 16))
, mDirection(Direction::South)
{
	centerOrigin(mSprite);
}

void Character::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}

void Character::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	Entity::updateCurrent(dt, commands);
}

unsigned int Character::getCategory() const
{
    return Category::PlayerCharacter;
}

void Character::setDirection(Direction direction) {
    mDirection = direction;

    if (Direction::North == direction)
        mSprite.setTextureRect(sf::IntRect(96, 0, 16, 16));
    else if (Direction::East == direction)
        mSprite.setTextureRect(sf::IntRect(32, 0, 16, 16));
    else if (Direction::South == direction)
        mSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
    else
        mSprite.setTextureRect(sf::IntRect(64, 0, 16, 16));
}

