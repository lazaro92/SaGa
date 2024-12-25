#ifndef GAME_MUSICPLAYER_HPP
#define GAME_MUSICPLAYER_HPP

#include <Game/ResourceHolder.hpp>
#include <Game/ResourceIdentifiers.hpp>

#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>


class MusicPlayer
{
    public:
                                    MusicPlayer();
                                    
                                    MusicPlayer(const MusicPlayer& temp_obj) = delete; 
                                    MusicPlayer& operator=(const MusicPlayer& temp_obj) = delete; 

        void                        play(Music::ID theme);
        void                        stop();

        void                        setPaused(bool paused);
        void                        setVolume(float volume);
        bool                        isPlayingTheme(Music::ID theme);

    private:
        sf::Music                           mMusic;
        std::map<Music::ID, std::string>    mFilenames;
        float                               mVolume;
        Music::ID                           mCurrentTheme;
};

#endif // GAME_MUSICPLAYER_HPP
