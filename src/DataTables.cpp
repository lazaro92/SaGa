#include <Game/DataTables.hpp>
#include <Game/Character.hpp>


// For std::bind() placeholders _1, _2, ...
using namespace std::placeholders;

std::vector<CharacterData>	initializeCharacterData()
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
