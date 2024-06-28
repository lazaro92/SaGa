#ifndef GAME_PANEL_HPP
#define GAME_PANEL_HPP

#include <Game/GUI/Component.hpp>
#include <Game/ResourceHolder.hpp>
#include <Game/ResourceIdentifiers.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <memory>


namespace GUI
{

/**
* GUI Component that contains other components
*/
class Panel: public Component
{
                            
    public:
                            typedef std::shared_ptr<Panel> Ptr;

    public:
                            Panel(const TextureHolder& textures, unsigned int width, unsigned int height);

        virtual bool        isSelectable() const;
        virtual void        handleEvent(const sf::Event& event);

    protected:
        virtual void        draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void                load();

    protected:
        unsigned int                    mWidth;
        unsigned int                    mHeight;

    private:
        const sf::Texture		        mBackground;
        sf::VertexArray                 mVertices;
};

}

#endif // GAME_PANEL_HPP
