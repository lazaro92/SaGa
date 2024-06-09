#include <Game/DataTables.hpp>
#include <Game/Character.hpp>


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
    std::vector<MapData> data(1);

    data[Maps::Library].texture = Textures::Library;
    data[Maps::Library].width = 19;
    data[Maps::Library].height = 23;
    data[Maps::Library].tiles = {
        1, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 2, 53, 53,
        18, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 18, 53, 53,
        18, 31, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 33, 18, 53, 53,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 53, 53,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 53, 53,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 53, 53,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 5, 9, 2,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 24, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18, 37, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 12, 46, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 23, 26, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 33, 26, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18,
        18, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 18,
        10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 4, 26, 26, 26, 12,
        19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 21, 39, 26, 40, 21,
        28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 29, 30, 48, 26, 49, 30,
        41, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 43,
        50, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 52
    };

    return data;
}

