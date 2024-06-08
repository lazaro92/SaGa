#ifndef GAME_CATEGORY_HPP
#define GAME_CATEGORY_HPP


// Entity/scene node category, used to dispatch commands
namespace Category
{
    enum Type
    {
        None                = 0,
        SceneAirLayer       = 1 << 0,
        PlayerCharacter     = 1 << 1,
        NPC                 = 1 << 2,
    };
}

#endif // GAME_CATEGORY_HPP
