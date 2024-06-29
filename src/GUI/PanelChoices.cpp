#include <Game/GUI/PanelChoices.hpp>
#include <Game/Utility.hpp>
#include <Game/Constants.hpp>

#include <SFML/Window/Event.hpp>

#include <cmath>


namespace GUI
{

PanelChoices::PanelChoices(const TextureHolder& textures, unsigned int width, unsigned int height, unsigned int columns)
: Panel(textures, width, height)
, mColumns(columns)
, mChildren()
, mSelectedChild(-1)
{
}

void PanelChoices::pack(Option::Ptr option)
{
    mChildren.push_back(option);

    if (!hasSelection() && option->isSelectable())
        select(mChildren.size() - 1);

    float itemWidth = mWidth / mColumns;

    float x = ((mChildren.size() - 1) % mColumns) * itemWidth + constants::PANEL_PADDING;
    float y = constants::PANEL_ITEM_DISTANCE * ((mChildren.size() - 1) / mColumns) + constants::PANEL_PADDING;
    option->setPosition(x, y);
}


bool PanelChoices::isSelectable() const
{
    return false;
}

void PanelChoices::handleEvent(const sf::Event& event)
{
        // If we have selected a child then give it events
    if (hasSelection() && mChildren[mSelectedChild]->isActive())
    {
        mChildren[mSelectedChild]->handleEvent(event);
    }
    else if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
        {
            selectPrevious();
        }
        else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
        {
            selectNext();
        }
        else if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space)
        {
            if (hasSelection())
                mChildren[mSelectedChild]->activate();
        }
    }
}

void PanelChoices::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Panel::draw(target, states);

    states.transform *= getTransform();

    for (const Option::Ptr& child : mChildren)
        target.draw(*child, states);
}

bool PanelChoices::hasSelection() const
{
    return mSelectedChild >= 0;
}

void PanelChoices::select(std::size_t index)
{
    if (mChildren[index]->isSelectable())
    {
        if (hasSelection())
            mChildren[mSelectedChild]->deselect();

        mChildren[index]->select();
        mSelectedChild = index;
    }
}

void PanelChoices::selectNext()
{
    if (!hasSelection())
        return;

    // Search next component that is selectable, wrap around if necessary
    int next = mSelectedChild;
    do
        next = (next + 1) % mChildren.size();
    while (!mChildren[next]->isSelectable());

    // Select that component
    select(next);
}

void PanelChoices::selectPrevious()
{
    if (!hasSelection())
        return;

    // Search previous component that is selectable, wrap around if necessary
    int prev = mSelectedChild;
    do
        prev = (prev + mChildren.size() - 1) % mChildren.size();
    while (!mChildren[prev]->isSelectable());

    // Select that component
    select(prev);
}

}
