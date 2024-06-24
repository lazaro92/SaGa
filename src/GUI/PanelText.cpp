#include <Game/GUI/PanelText.hpp>

namespace GUI
{

PanelText::PanelText(const TextureHolder& textures, const FontHolder& fonts, unsigned int width, unsigned int height)
: Panel(textures, width, height)
, mText()
{
    


    mText.setFont(fonts.get(Fonts::Main));
    mText.setString("El Roc que folla poc. I la Martina que folla com una tremendina");
    mText.setPosition(10.f, 10.f);
    mText.setCharacterSize(16u);
}

bool PanelText::isSelectable() const
{
    return false;
}

void PanelText::handleEvent(const sf::Event& event)
{
}

void PanelText::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Panel::draw(target, states);

    states.transform *= getTransform();

    target.draw(mText, states);
}

}
