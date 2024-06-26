#include <Game/GUI/PanelText.hpp>
#include <Game/Utility.hpp>

#include <sstream>

namespace GUI
{

PanelText::PanelText(const TextureHolder& textures, const FontHolder& fonts, unsigned int width, unsigned int height)
: Panel(textures, width, height)
, mText("", fonts.get(Fonts::Pixelart), 16)
{
}

bool PanelText::isSelectable() const
{
    return false;
}

void PanelText::setText(std::string text, bool centered)
{
    adaptTextToLimits(text);
    mText.setString(text);

    if (centered)
    {
        centerOrigin(mText);
        mText.setPosition(mWidth / 2.f, mHeight / 2.f);
    }
    else
        mText.setPosition(10.f, 10.f);
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

void PanelText::adaptTextToLimits(std::string& textToAdapt)
{
    std::string word;
    std::string newText = "";
    unsigned int currentWidth = 0;

    std::istringstream iss(textToAdapt);
    while (std::getline(iss, word, ' '))
    {
        unsigned int wordWidth = word.size() * 12;

        if ((currentWidth + wordWidth) > mWidth)
        {
            newText += '\n' + word + ' ';
            currentWidth = wordWidth + 10;
        }
        else
        {
            newText += word + ' ';
            currentWidth += wordWidth + 10;
        }
        textToAdapt = newText;
    }
}

}
