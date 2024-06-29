#include <Game/GUI/Panel.hpp>
#include <Game/Constants.hpp>

#include <SFML/Window/Event.hpp>

namespace GUI
{

Panel::Panel(const TextureHolder& textures, unsigned int width, unsigned int height)
: mBackground(textures.get(Textures::Panel))
, mWidth(width)
, mHeight(height)
{
    load();
}

bool Panel::isSelectable() const
{
    return false;
}

void Panel::handleEvent(const sf::Event& event)
{
}

void Panel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &mBackground;

    // draw the vertex array
    target.draw(mVertices, states);
}

void Panel::load()
{
    unsigned int tilesWidth = mWidth / constants::PANEL_TILE_SIZE;
    unsigned int tilesHeight = mHeight / constants::PANEL_TILE_SIZE;

    mVertices.setPrimitiveType(sf::Quads);
    mVertices.resize(tilesWidth * tilesHeight * 4);

    

    for (unsigned int i = 0; i < tilesWidth; ++i)
        for (unsigned int j = 0; j < tilesHeight; ++j)
        {
            int tileNumber;
           
            if (j == 0) 
            {
                if (i == 0)
                    tileNumber = 0;
                else if (i == tilesWidth - 1)
                    tileNumber = 2;
                else 
                    tileNumber = 1;
            } 
            else if (j == tilesHeight - 1)
            {
                if (i == 0)
                    tileNumber = 6;
                else if (i == tilesWidth - 1)
                    tileNumber = 8;
                else 
                    tileNumber = 7;
            }
            else
            {
                if (i == 0)
                    tileNumber = 3;
                else if (i == tilesWidth - 1)
                    tileNumber = 5;
                else 
                    tileNumber = 4;
            }


            // find its position in the tileset texture
            int tu = tileNumber % (mBackground.getSize().x / constants::PANEL_TILE_SIZE);
            int tv = tileNumber / (mBackground.getSize().x / constants::PANEL_TILE_SIZE);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &mVertices[(i + j * tilesWidth) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * constants::PANEL_TILE_SIZE, j * constants::PANEL_TILE_SIZE);
            quad[1].position = sf::Vector2f((i + 1) * constants::PANEL_TILE_SIZE, j * constants::PANEL_TILE_SIZE);
            quad[2].position = sf::Vector2f((i + 1) * constants::PANEL_TILE_SIZE, (j + 1) * constants::PANEL_TILE_SIZE);
            quad[constants::PANEL_TILE_SIZE].position = sf::Vector2f(i * constants::PANEL_TILE_SIZE, (j + 1) * constants::PANEL_TILE_SIZE);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * constants::PANEL_TILE_SIZE, tv * constants::PANEL_TILE_SIZE);
            quad[1].texCoords = sf::Vector2f((tu + 1) * constants::PANEL_TILE_SIZE, tv * constants::PANEL_TILE_SIZE);
            quad[2].texCoords = sf::Vector2f((tu + 1) * constants::PANEL_TILE_SIZE, (tv + 1) * constants::PANEL_TILE_SIZE);
            quad[constants::PANEL_TILE_SIZE].texCoords = sf::Vector2f(tu * constants::PANEL_TILE_SIZE, (tv + 1) * constants::PANEL_TILE_SIZE);
        }
}

}
