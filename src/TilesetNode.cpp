#include <Game/TilesetNode.hpp>
#include <Game/DataTables.hpp>
#include <Game/ResourceHolder.hpp>


namespace
{
    const std::vector<MapData> Table = initializeMapData();
}

TilesetNode::TilesetNode(Map map, const TextureHolder& textures)
: mMap(map)
, mTileset(textures.get(Table[map].texture))
, mWidth(Table[map].width)
, mHeight(Table[map].height)
, mTiles(Table[map].tiles)
{
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
    mVertices.setPrimitiveType(sf::Quads);
    mVertices.resize(mWidth * mHeight * 4);

    for (unsigned int i = 0; i < mWidth; ++i)
        for (unsigned int j = 0; j < mHeight; ++j)
        {
            // get the current tile number
            int tileNumber = mTiles[i + j * mWidth];

            // find its position in the tileset texture
            int tu = tileNumber % (mTileset.getSize().x / 16);
            int tv = tileNumber / (mTileset.getSize().x / 16);

            // get a pointer to the current tile's quad
            sf::Vertex* quad = &mVertices[(i + j * mWidth) * 4];

            // define its 4 corners
            quad[0].position = sf::Vector2f(i * 16, j * 16);
            quad[1].position = sf::Vector2f((i + 1) * 16, j * 16);
            quad[2].position = sf::Vector2f((i + 1) * 16, (j + 1) * 16);
            quad[3].position = sf::Vector2f(i * 16, (j + 1) * 16);

            // define its 4 texture coordinates
            quad[0].texCoords = sf::Vector2f(tu * 16, tv * 16);
            quad[1].texCoords = sf::Vector2f((tu + 1) * 16, tv * 16);
            quad[2].texCoords = sf::Vector2f((tu + 1) * 16, (tv + 1) * 16);
            quad[3].texCoords = sf::Vector2f(tu * 16, (tv + 1) * 16);
        }
}