#include <Game/GUI/PanelText.hpp>

#include <sstream>

namespace GUI
{

PanelText::PanelText(const TextureHolder& textures, const FontHolder& fonts, unsigned int width, unsigned int height)
: Panel(textures, width, height)
, mText()
{
    std::string text = " Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam vestibulum risus sed massa dictum tincidunt. Ut id mi nec nulla condimentum rutrum non at arcu. Praesent pretium tortor ac interdum dictum. Aliquam tristique leo in arcu sollicitudin, non feugiat tortor euismod. Aliquam tellus felis, lacinia nec neque in, semper feugiat risus. Etiam vitae turpis ut elit lobortis aliquet commodo sagittis tellus. Aliquam id laoreet orci, non dapibus arcu. Duis consectetur justo ipsum, non maximus ligula efficitur sed. Nulla a erat in metus maximus viverra. Proin efficitur diam at mauris rutrum tincidunt.";

    adaptTextToLimits(text);

    mText.setFont(fonts.get(Fonts::Main));
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
        unsigned int wordWidth = word.size() * 8;

        if ((currentWidth + wordWidth) > mWidth)
        {
            newText += '\n' + word;
            currentWidth = 0;
        }
        else
        {
            newText += ' ' + word;
            currentWidth += wordWidth + 8;
        }
        textToAdapt = newText;
    }
}

}
