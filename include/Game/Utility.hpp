#ifndef GAME_UTILITY_HPP
#define GAME_UTILITY_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

#include <sstream>


namespace sf
{
    class Sprite;
    class Text;
}

class Animation;

// Convert enumerators to strings
std::string     toString(sf::Keyboard::Key key);

// Call setOrigin() with the center of the object
void            centerOrigin(sf::Sprite& sprite);
void            centerOrigin(sf::Text& text);
void            centerOrigin(Animation& animation);

// Random number generation
int             randomInt(int exclusiveMax);

// Tile operations
sf::Vector2i    pointToTile(float pointX, float pointY);
sf::Vector2f    tileToPoint(int tileX, int tileY);
int             tileToIndex(const sf::Vector2i& tile, int width);
int             tileToIndex(int x, int y, int width);
float           lerp(float origin, float destination, float percentageDistance);

#endif // GAME_UTILITY_HPP
