#include <Game/DataTables.hpp>
#include <Game/Constants.hpp>
#include <Game/Character.hpp>
#include <Game/TilesetNode.hpp>


std::vector<CharacterData> initializeCharacterData()
{
    std::vector<CharacterData> data(Character::TypeCount);

    data[Character::HumanMale].texture = Textures::Characters;
    data[Character::HumanMale].textureRect = sf::IntRect(0, 0, constants::TILE_MAP_SIZE, constants::TILE_MAP_SIZE);

    data[Character::HumanFemale].texture = Textures::Characters;
    data[Character::HumanFemale].textureRect = sf::IntRect(0, constants::TILE_MAP_SIZE, constants::TILE_MAP_SIZE, constants::TILE_MAP_SIZE);

    data[Character::MutantMale].texture = Textures::Characters;
    data[Character::MutantMale].textureRect = sf::IntRect(0, 32, constants::TILE_MAP_SIZE, constants::TILE_MAP_SIZE);

    data[Character::MutantFemale].texture = Textures::Characters;
    data[Character::MutantFemale].textureRect = sf::IntRect(0, 48, constants::TILE_MAP_SIZE, constants::TILE_MAP_SIZE);

    data[Character::Soldier].texture = Textures::Characters;
    data[Character::Soldier].textureRect = sf::IntRect(0, 64, constants::TILE_MAP_SIZE, constants::TILE_MAP_SIZE);

    data[Character::GreenSlime].texture = Textures::Characters;
    data[Character::GreenSlime].textureRect = sf::IntRect(0, 80, constants::TILE_MAP_SIZE, constants::TILE_MAP_SIZE);

    data[Character::YellowSlime].texture = Textures::Characters;
    data[Character::YellowSlime].textureRect = sf::IntRect(0, 96, constants::TILE_MAP_SIZE, constants::TILE_MAP_SIZE);

    return data;
}

std::vector<MapData> initializeMapData()
{
    std::vector<MapData> data(TilesetNode::MapCount);

    data[TilesetNode::Library].texture = Textures::Library;
    data[TilesetNode::Library].width = 30;
    data[TilesetNode::Library].height = 31;
    data[TilesetNode::Library].tiles = {
            53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 31, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 18, 35, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 5, 9, 2, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 24, 18, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 37, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 12, 46, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 23, 25, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 33, 34, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 18, 25, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 4, 26, 26, 26, 12, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 21, 39, 26, 40, 21, 35, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 30, 48, 26, 49, 30, 44, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 41, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 43, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 50, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 52, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53,
            53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53
    };
    data[TilesetNode::Library].collisions = {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
            0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    data[TilesetNode::Library].characters = {
        { Character::Type::HumanFemale, Character::Direction::South, sf::Vector2i(22, constants::TILE_MAP_SIZE) },
        { Character::Type::MutantMale , Character::Direction::South, sf::Vector2i(14, 13) },
        { Character::Type::Soldier    , Character::Direction::South, sf::Vector2i(7, 7)   },
        { Character::Type::YellowSlime, Character::Direction::South, sf::Vector2i(8, 20)  },
    };
    data[TilesetNode::Library].playerCharacter = { Character::Type::HumanMale, Character::Direction::North, sf::Vector2i(22, 24) };

    //-------------------------------------

    data[TilesetNode::LibraryTop].texture = Textures::Library;
    data[TilesetNode::LibraryTop].width = 19;
    data[TilesetNode::LibraryTop].height = 21;
    data[TilesetNode::LibraryTop].tiles = {
            1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,
            18,22,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,18,
            18,31,7,7,7,7,7,7,7,7,7,7,7,7,7,33,33,33,18,
            18,25,16,16,16,16,16,16,16,16,16,16,16,16,16,26,26,26,18,
            18,25,7,7,7,7,7,7,7,7,7,7,7,7,7,26,26,26,18,
            18,25,16,16,16,16,16,16,16,16,16,16,16,16,16,26,13,26,18,
            18,25,7,7,7,7,7,7,7,7,7,7,7,7,7,26,18,38,18,
            18,25,16,16,16,16,16,16,16,16,16,16,16,16,16,26,18,47,18,
            18,25,7,7,7,7,7,7,7,7,7,7,7,7,7,26,5,9,11,
            18,25,16,16,16,16,16,16,16,16,16,16,16,16,16,26,18,20,20,
            18,25,7,7,7,7,7,7,7,7,7,7,7,7,7,26,18,29,29,
            18,25,16,16,16,16,16,16,16,16,16,16,16,16,16,26,18,0,0,
            18,25,7,7,7,7,7,7,7,7,7,7,7,7,7,26,18,0,0,
            18,25,16,16,16,16,16,16,16,16,16,16,16,16,16,26,18,0,0,
            18,25,7,7,7,7,7,7,7,7,7,7,7,7,7,26,18,0,0,
            18,25,16,16,16,16,16,16,16,16,16,16,16,16,16,26,18,0,0,
            18,25,7,7,7,7,7,7,7,7,7,7,7,7,7,26,18,0,0,
            18,25,16,16,16,16,16,16,16,16,16,16,16,16,16,26,18,0,0,
            10,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,11,0,0,
            19,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,0,0,
            28,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,0,0

    };
    data[TilesetNode::LibraryTop].collisions = {
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
            1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
            1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,
            1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
            1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
            1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
            1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
            1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,
            1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };
    data[TilesetNode::LibraryTop].characters = {};
    data[TilesetNode::LibraryTop].playerCharacter = { Character::Type::HumanMale, Character::Direction::North, sf::Vector2i(17, 7) };

    return data;
}

