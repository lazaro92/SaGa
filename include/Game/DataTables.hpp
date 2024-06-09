#ifndef GAME_DATATABLES_HPP
#define GAME_DATATABLES_HPP

#include <Game/ResourceIdentifiers.hpp>

#include <SFML/Graphics/Rect.hpp>

#include <vector>


class Character;

struct CharacterData
{
    Textures::ID                    texture;
    sf::IntRect                     textureRect;
};

struct MapData
{
    Textures::ID                    texture;
    int                             width;
    int                             height;
    std::vector<int>                tiles;
};

std::vector<CharacterData>          initializeCharacterData();
std::vector<MapData>                initializeMapData();

#endif // GAME_DATATABLES_HPP
