#ifndef GAME_OPTION_HPP
#define GAME_OPTION_HPP

#include <Game/GUI/Component.hpp>
#include <Game/ResourceIdentifiers.hpp>
#include <Game/ResourceHolder.hpp>
#include <Game/State.hpp>

#include <SFML/Graphics/Text.hpp>

#include <string>
#include <memory>
#include <functional>


namespace GUI
{

class Option : public Component
{
    public:
        typedef std::shared_ptr<Option>            Ptr;
        typedef std::function<void()>              Callback;


    public:
                            Option(const std::string& text, State::Context context);

        void                setCallback(Callback callback);
        void                setText(const std::string& text);
        void                setToggle(bool flag);

        virtual bool        isSelectable() const;
        virtual void        select();
        virtual void        deselect();

        virtual void        activate();
        virtual void        deactivate();

        virtual void        handleEvent(const sf::Event& event);



    private:
        void                draw(sf::RenderTarget& target, sf::RenderStates states) const;


    private:
        Callback            mCallback;
        sf::Text            mText;
        bool                mIsToggle;
};

}

#endif // GAME_OPTION_HPP
