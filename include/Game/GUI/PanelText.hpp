#ifndef GAME_PANELTEXT_HPP
#define GAME_PANELTEXT_HPP

#include <Game/GUI/Panel.hpp>

#include <SFML/Graphics/Text.hpp>


namespace GUI
{

class PanelText: public Panel
{
	public:
							PanelText(const TextureHolder& textures, const FontHolder& fonts, unsigned int width, unsigned int height);

        virtual bool		isSelectable() const;
        virtual void		handleEvent(const sf::Event& event);
        
    private:
        virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Text            mText;

};

}

#endif // GAME_PANELTEXT_HPP
