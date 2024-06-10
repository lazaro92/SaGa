#ifndef GAME_TILESETNODE_HPP
#define GAME_TILESETNODE_HPP

#include <Game/SceneNode.hpp>
#include <Game/ResourceIdentifiers.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>


class TilesetNode : public SceneNode
{
    public:
         enum Map
        {
            Library,
            MapCount,
        };


    public:
        explicit            TilesetNode(Map map, const TextureHolder& textures);

    public:
        void                load();
        int                 getTile(unsigned int x, unsigned int y);

    private:
        virtual void        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        Map                  mMap;
        sf::Texture          mTileset;
        sf::VertexArray      mVertices;
};

#endif // GAME_TILESETNODE_HPP
