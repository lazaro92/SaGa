#include <Game/GUI/PanelChoices.hpp>
#include <Game/Utility.hpp>

#include <sstream>

namespace GUI
{

PanelChoices::PanelChoices(const TextureHolder& textures, unsigned int width, unsigned int height)
: Panel(textures, width, height)
{
}

bool PanelChoices::isSelectable() const
{
    return false;
}

void PanelChoices::handleEvent(const sf::Event& event)
{
}

void PanelChoices::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Panel::draw(target, states);

    states.transform *= getTransform();
}

}
