#ifndef GAME_PANELCHOICES_HPP
#define GAME_PANELCHOICES_HPP

#include <Game/GUI/Panel.hpp>

#include <SFML/Graphics/Text.hpp>

#include <string>


namespace GUI
{

class PanelChoices: public Panel
{
	public:
							PanelChoices(const TextureHolder& textures, unsigned int width, unsigned int height);

        virtual bool		isSelectable() const;
        virtual void		handleEvent(const sf::Event& event);

    private:
        virtual void		draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void                adaptTextToLimits(std::string& textToAdapt);


};

}

#endif // GAME_PANELTEXT_HPP
