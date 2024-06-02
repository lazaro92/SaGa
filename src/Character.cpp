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
, mDirectionIndex(0)
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

