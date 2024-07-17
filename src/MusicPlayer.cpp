#include <Game/MusicPlayer.hpp>


MusicPlayer::MusicPlayer()
: mMusic()
, mFilenames()
, mVolume(100.f)
,mCurrentTheme(Music::None)
{
    mFilenames[Music::Dungeon] = "media/music/dungeon.ogg";
}

void MusicPlayer::play(Music::ID theme)
{
    std::string filename = mFilenames[theme];

    if (!mMusic.openFromFile(filename))
        throw std::runtime_error("Music " + filename + " could not be loaded.");

    mMusic.setVolume(mVolume);
    mMusic.setLoop(true);
    mMusic.play();

    mCurrentTheme = theme;
}

void MusicPlayer::stop()
{
    mMusic.stop();
}

void MusicPlayer::setVolume(float volume)
{
    mVolume = volume;
}

void MusicPlayer::setPaused(bool paused)
{
    if (paused)
        mMusic.pause();
    else
        mMusic.play();
}

bool MusicPlayer::isPlayingTheme(Music::ID theme)
{
    return mCurrentTheme == theme;
}
