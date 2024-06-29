#include <Game/GUI/Option.hpp>
#include <Game/Utility.hpp>
#include <Game/Constants.hpp>

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Color.hpp>


namespace GUI
{

Option::Option(const std::string& text, State::Context context)
: mCallback()
, mIsToggle(false)
, mText(text, context.fonts->get(Fonts::Pixelart), constants::PANEL_FONT_SIZE)
{
}

void Option::setCallback(Callback callback)
{
    mCallback = std::move(callback);
}

void Option::setText(const std::string& text)
{
    mText.setString(text);
}

void Option::setToggle(bool flag)
{
    mIsToggle = flag;
}

bool Option::isSelectable() const
{
    return true;
}

void Option::handleEvent(const sf::Event&)
{
}

void Option::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(mText, states);
}

void Option::activate()
{
    Component::activate();

    // If we are toggle then we should show that the button is pressed and thus "toggled".
    if (mIsToggle)
        mText.setFillColor(sf::Color(158, 131, 46));

    if (mCallback)
        mCallback();

    // If we are not a toggle then deactivate the button since we are just momentarily activated.
    if (!mIsToggle)
        deactivate();
}

void Option::deactivate()
{
    Component::deactivate();

    if (mIsToggle)
    {
        // Reset texture to right one depending on if we are selected or not.
        if (isSelected())
            mText.setFillColor(sf::Color(158, 131, 46));
        else
            mText.setFillColor(sf::Color::White);
    }
}


void Option::select()
{
    Component::select();
    mText.setFillColor(sf::Color(158, 131, 46));
}

void Option::deselect()
{
    Component::deselect();
    mText.setFillColor(sf::Color::White);
}


}