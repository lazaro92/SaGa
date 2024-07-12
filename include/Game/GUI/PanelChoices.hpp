#ifndef GAME_PANELCHOICES_HPP
#define GAME_PANELCHOICES_HPP

#include <Game/GUI/Panel.hpp>
#include <Game/GUI/Option.hpp>

#include <SFML/Graphics/Text.hpp>

#include <vector>
#include <memory>


namespace GUI
{

class PanelChoices: public Panel
{
    public:
        typedef std::shared_ptr<PanelChoices> Ptr;


    public:
                            PanelChoices(const TextureHolder& textures, unsigned int width, unsigned int height, unsigned int columns);

        void                pack(Option::Ptr option);

        virtual bool        isSelectable() const;
        virtual void        handleEvent(const sf::Event& event);

    private:
        virtual void        draw(sf::RenderTarget& target, sf::RenderStates states) const;

        bool                hasSelection() const;
        void                select(std::size_t index);
        void                selectNext();
        void                selectPrevious();
        void                selectNextLine();
        void                selectPreviousLine();

    private:
        unsigned int                 mColumns;
        std::vector<Option::Ptr>     mChildren;
        int                          mSelectedChild;
};

}

#endif // GAME_PANELTEXT_HPP
