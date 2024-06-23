#ifndef GAME_PANEL_HPP
#define GAME_PANEL_HPP

#include <Game/GUI/Component.hpp>
#include <Game/ResourceHolder.hpp>
#include <Game/ResourceIdentifiers.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <vector>
#include <memory>


namespace GUI
{

/**
* GUI Component that contains other components
*/
class Panel: public Component
{
	public:
							Panel(const TextureHolder& textures, unsigned int width, unsigned int height);

        virtual bool		isSelectable() const;
        virtual void		handleEvent(const sf::Event& event);


    private:
        virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void                load();

    private:
        const sf::Texture		        mBackground;
        sf::VertexArray                 mVertices;
        unsigned int                    mWidth;
        unsigned int                    mHeight;

};

}

#endif // GAME_CONTAINER_HPP
