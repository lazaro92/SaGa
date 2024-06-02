#ifndef GAME_CHARACTER_HPP
#define GAME_CHARACTER_HPP

#include <Game/Entity.hpp>
#include <Game/Command.hpp>
#include <Game/ResourceIdentifiers.hpp>

#include <SFML/Graphics/Sprite.hpp>


class Character : public Entity
{
	public:
		enum Type
		{
            HumanMale,
            HumanFemale,
			MutantMale,
			MutantFemale,
			TypeCount
		};


	public:
								Character(Type type, const TextureHolder& textures);

		virtual unsigned int	getCategory() const;

	private:
		virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);

	private:
		Type					mType;
		sf::Sprite				mSprite;

		std::size_t				mDirectionIndex;
};

#endif // GAME_CHARACTER_HPP
