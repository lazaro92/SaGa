#include <Game/TilesetNode.hpp>
#include <Game/DataTables.hpp>
#include <Game/ResourceHolder.hpp>
#include <Game/Constants.hpp>


namespace
{
    const std::vector<MapData> Table = initializeMapData();
}

TilesetNode::TilesetNode(Map map, const TextureHolder& textures)
: mMap(map)
, mTileset(textures.get(Table[map].texture))
{
    load();
}	

void TilesetNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &mTileset;

    // draw the vertex array
    target.draw(mVertices, states);
}

void TilesetNode::load()
{
    unsigned int height = Table[mMap].height;
    unsigned int width = Table[mMap].width;
    std::vector<int> tiles = Table[mMap].tiles;

    mVertices.setPrimitiveType(sf::Quads);
    mVertices.resize(width * height * 4);

    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // get the current tile number
            int tileNumber = tiles[i + j * width] -1;

            if (tileNumber < 0) continue;

            // find its position in the tileset texture
            int tu = tileNumber % (mTileset.getSize().x / constants::TILE_MAP_SIZE);
            int tv = tileNumber / (mTileset.getSize().x / constants::TILE_MAP_SIZE);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &mVertices[(i + j * width) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * constants::TILE_MAP_SIZE, j * constants::TILE_MAP_SIZE);
            quad[1].position = sf::Vector2f((i + 1) * constants::TILE_MAP_SIZE, j * constants::TILE_MAP_SIZE);
            quad[2].position = sf::Vector2f((i + 1) * constants::TILE_MAP_SIZE, (j + 1) * constants::TILE_MAP_SIZE);
            quad[3].position = sf::Vector2f(i * constants::TILE_MAP_SIZE, (j + 1) * constants::TILE_MAP_SIZE);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * constants::TILE_MAP_SIZE, tv * constants::TILE_MAP_SIZE);
            quad[1].texCoords = sf::Vector2f((tu + 1) * constants::TILE_MAP_SIZE, tv * constants::TILE_MAP_SIZE);
            quad[2].texCoords = sf::Vector2f((tu + 1) * constants::TILE_MAP_SIZE, (tv + 1) * constants::TILE_MAP_SIZE);
            quad[3].texCoords = sf::Vector2f(tu * constants::TILE_MAP_SIZE, (tv + 1) * constants::TILE_MAP_SIZE);
        }
}

int TilesetNode::getTile(int tileX, int tileY)
{
    return Table[mMap].tiles[tileX + tileY * Table[mMap].width] -1;
}

bool TilesetNode::isWalkable(int tileX, int tileY)
{
    return Table[mMap].collisions[tileX + tileY * Table[mMap].width] == 0;
}