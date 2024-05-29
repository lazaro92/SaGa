#ifndef GAME_GAMESTATE_HPP
#define GAME_GAMESTATE_HPP

#include <Game/State.hpp>
#include <Game/World.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>


class GameState : public State
{
	public:
							GameState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);

	private:
	 	World mWorld; 

};

#endif // GAME_GAMESTATE_HPP