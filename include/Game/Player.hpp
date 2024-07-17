#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <Game/Command.hpp>
#include <Game/TilesetNode.hpp>

#include <SFML/Window/Event.hpp>

#include <map>


class CommandQueue;

class Player
{
    public:
        enum Action
        {
            MoveLeft,
            MoveRight,
            MoveUp,
            MoveDown,
            
            FaceNorth,
            FaceEast,
            FaceSouth,
            FaceWest,

            ActionCount
        };

    public:
                                Player();

        void                    handleEvent(const sf::Event& event, CommandQueue& commands);
        void                    handleRealtimeInput(CommandQueue& commands);

        void                    assignKey(Action action, sf::Keyboard::Key key);
        sf::Keyboard::Key       getAssignedKey(Action action) const;

        void                    setCurrentMap(TilesetNode::Map currentMap);
        TilesetNode::Map        getCurrentMap();
        void                    setCurrentSpawnPosition(sf::Vector2i spawnPosition);
        sf::Vector2i            getCurrentSpawnPosition();

    private:
        void                    initializeActions();
        static bool             isRealtimeAction(Action action);


    private:
        std::map<sf::Keyboard::Key, Action>    mKeyBinding;
        std::map<Action, Command>              mActionBinding;

        TilesetNode::Map                       mCurrentMap;
        sf::Vector2i                           mCurrentSpawnPosition;
};

#endif // GAME_PLAYER_HPP
