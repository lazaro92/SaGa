#ifndef GAME_DATATABLES_HPP
#define GAME_DATATABLES_HPP

#include <Game/ResourceIdentifiers.hpp>

#include <SFML/Graphics/Rect.hpp>

#include <vector>


class Character;

struct CharacterData
{
	Textures::ID					texture;
	sf::IntRect						textureRect;
};

std::vector<CharacterData>	initializeCharacterData();

#endif // GAME_DATATABLES_HPP
