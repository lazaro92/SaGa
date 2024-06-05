#include <Game/Player.hpp>
#include <Game/CommandQueue.hpp>
#include <Game/Character.hpp>

#include <map>
#include <string>
#include <algorithm>

using namespace std::placeholders;

struct PlayerMover
{
	PlayerMover(float vx, float vy)
	: velocity(vx, vy)
	{
	}

	void operator() (Character& character, sf::Time) const
	{
		character.accelerate(velocity * 200.f);
	}

	sf::Vector2f velocity;
};


Player::Player()
{
	// Set initial key bindings
	mKeyBinding[sf::Keyboard::Left] = MoveLeft;
	mKeyBinding[sf::Keyboard::Right] = MoveRight;
	mKeyBinding[sf::Keyboard::Up] = MoveUp;
	mKeyBinding[sf::Keyboard::Down] = MoveDown;

	mKeyBinding[sf::Keyboard::W] = FaceNorth;
	mKeyBinding[sf::Keyboard::A] = FaceWest;
	mKeyBinding[sf::Keyboard::S] = FaceSouth;
	mKeyBinding[sf::Keyboard::D] = FaceEast;
 
	// Set initial action bindings
	initializeActions();	

	// Assign all categories to player's character
	for(auto& pair: mActionBinding)
		pair.second.category = Category::PlayerCharacter;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::KeyPressed)
	{
		// Check if pressed key appears in key binding, trigger command if so
		auto found = mKeyBinding.find(event.key.code);
		if (found != mKeyBinding.end() && !isRealtimeAction(found->second))
			commands.push(mActionBinding[found->second]);
	}
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	// Traverse all assigned keys and check if they are pressed
	for(auto pair: mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
			commands.push(mActionBinding[pair.second]);
	}
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
	for(auto pair: mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Keyboard::Unknown;
}

void Player::initializeActions()
{
	mActionBinding[MoveLeft].action      = derivedAction<Character>(PlayerMover(-1,  0));
	mActionBinding[MoveRight].action     = derivedAction<Character>(PlayerMover(+1,  0));
	mActionBinding[MoveUp].action        = derivedAction<Character>(PlayerMover( 0, -1));
	mActionBinding[MoveDown].action      = derivedAction<Character>(PlayerMover( 0, +1));

	mActionBinding[FaceNorth].action     = derivedAction<Character>([] (Character& c, sf::Time) { c.setDirection(Character::Direction::North); });
	mActionBinding[FaceEast].action      = derivedAction<Character>([] (Character& c, sf::Time) { c.setDirection(Character::Direction::East); });
	mActionBinding[FaceSouth].action     = derivedAction<Character>([] (Character& c, sf::Time) { c.setDirection(Character::Direction::South); });
	mActionBinding[FaceWest].action      = derivedAction<Character>([] (Character& c, sf::Time) { c.setDirection(Character::Direction::West); });

}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
		case MoveLeft:
		case MoveRight:
		case MoveDown:
		case MoveUp:
			return true;

		default:
			return false;
	}
}
