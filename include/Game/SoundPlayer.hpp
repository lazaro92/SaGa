#ifndef GAME_SOUNDPLAYER_HPP
#define GAME_SOUNDPLAYER_HPP

#include <Game/ResourceHolder.hpp>
#include <Game/ResourceIdentifiers.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include <list>


class SoundPlayer
{
    public:
                                    SoundPlayer();
                                    SoundPlayer(const SoundPlayer& temp_obj) = delete; 
                                    SoundPlayer& operator=(const SoundPlayer& temp_obj) = delete; 

        void                        play(SoundEffect::ID effect);
        void                        play(SoundEffect::ID effect, sf::Vector2f position);

        void                        removeStoppedSounds();
        void                        setListenerPosition(sf::Vector2f position);
        sf::Vector2f                getListenerPosition() const;


    private:
        SoundBufferHolder           mSoundBuffers;
        std::list<sf::Sound>        mSounds;
};

#endif // GAME_SOUNDPLAYER_HPP
