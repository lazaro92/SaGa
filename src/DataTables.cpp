#include <Game/DataTables.hpp>
#include <Game/Character.hpp>
#include <Game/TilesetNode.hpp>


std::vector<CharacterData> initializeCharacterData()
{
    std::vector<CharacterData> data(Character::TypeCount);

    data[Character::HumanMale].texture = Textures::Characters;
    data[Character::HumanMale].textureRect = sf::IntRect(0, 0, 16, 16);

    data[Character::HumanFemale].texture = Textures::Characters;
    data[Character::HumanFemale].textureRect = sf::IntRect(0, 16, 16, 16);

    data[Character::MutantMale].texture = Textures::Characters;
    data[Character::MutantMale].textureRect = sf::IntRect(0, 32, 16, 16);

    data[Character::MutantFemale].texture = Textures::Characters;
    data[Character::MutantFemale].textureRect = sf::IntRect(0, 48, 16, 16);

    return data;
}

std::vector<MapData> initializeMapData()
{
    std::vector<MapData> data(TilesetNode::MapCount);

    data[TilesetNode::Library].texture = Textures::Library;
    data[TilesetNode::Library].width = 19;
    data[TilesetNode::Library].height = 23;
    data[TilesetNode::Library].tiles = {
        0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 1, 52, 52,
        17, 21, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 17, 52, 52,
        17, 30, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 17, 52, 52,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17, 52, 52,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17, 52, 52,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17, 52, 52,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 4, 8, 1,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17, 23, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17, 36, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 11, 45, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 22, 25, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 32, 25, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17,
        17, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 17,
        9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 3, 25, 25, 25, 11,
        18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 38, 25, 39, 20,
        27, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 29, 47, 25, 48, 29,
        40, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 42,
        49, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 51
    };

    return data;
}

