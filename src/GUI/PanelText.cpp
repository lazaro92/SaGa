#include <Game/GUI/PanelText.hpp>

#include <sstream>

namespace GUI
{

PanelText::PanelText(const TextureHolder& textures, const FontHolder& fonts, unsigned int width, unsigned int height)
: Panel(textures, width, height)
, mText()
{
    std::string text = "This is a test on long texts that are rendered on the panels. So imagine this is a character saying something interesting or a dialog that explains the history or anything else.";

    adaptTextToLimits(text);

    mText.setFont(fonts.get(Fonts::Pixelart));
    mText.setString(text);
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

void PanelText::adaptTextToLimits(std::string& textToAdapt)
{
    std::string word;
    std::string newText = "";
    unsigned int currentWidth = 0;

    std::istringstream iss(textToAdapt);
    while (std::getline(iss, word, ' '))
    {
        unsigned int wordWidth = word.size() * 15;

        if ((currentWidth + wordWidth) > mWidth)
        {
            newText += '\n' + word + ' ';
            currentWidth = 0;
        }
        else
        {
            newText += word + ' ';
            currentWidth += wordWidth + 15;
        }
        textToAdapt = newText;
    }
}

}
