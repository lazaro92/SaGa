#ifndef GAME_DATATABLES_HPP
#define GAME_DATATABLES_HPP

#include <Game/ResourceIdentifiers.hpp>
#include <Game/Character.hpp>
#include <Game/TilesetNode.hpp>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

#include <map>
#include <vector>



struct CharacterData
{
    Textures::ID                    texture;
    sf::IntRect                     textureRect;
};

struct SceneCharacterData
{
    Character::Type                 type;
    Character::Direction            direction;
    sf::Vector2i                    tilePosition;
};

struct NextMapData
{
    TilesetNode::Map                mapId;
    sf::Vector2i                    spawnPosition;
};

struct MapData
{
    Textures::ID                               texture;
    int                                        width;
    int                                        height;
    std::vector<int>                           tiles;
    std::vector<bool>                          collisions;
    std::vector<SceneCharacterData>            characters;
    SceneCharacterData                         playerCharacter;
    std::map<int, NextMapData>                 actionTiles; // TODO actionTiles should have a function
};

std::vector<CharacterData>          initializeCharacterData();
std::vector<MapData>                initializeMapData();

#endif // GAME_DATATABLES_HPP
