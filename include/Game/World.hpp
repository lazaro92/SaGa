#ifndef GAME_WORLD_HPP
#define GAME_WORLD_HPP

#include <Game/ResourceHolder.hpp>
#include <Game/ResourceIdentifiers.hpp>
#include <Game/SceneNode.hpp>
#include <Game/SpriteNode.hpp>
#include <Game/Character.hpp>
#include <Game/CommandQueue.hpp>
#include <Game/Command.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>



class World : private sf::NonCopyable {
    public:
											World(sf::RenderTarget& outputTarget);
		void								update(sf::Time dt);
		void								draw();
		
		CommandQueue&						getCommandQueue();

	private:
		void                                loadTextures();
		void                                buildScene();

	private:
		enum Layer
		{
			Background,
			LowerAir,
			UpperAir,
			LayerCount
		};

	private:
		sf::RenderTarget&					mTarget;
		sf::View							mWorldView;
		TextureHolder						mTextures;

		sf::Vector2f						mSpawnPosition;

		SceneNode							mSceneGraph;
		std::array<SceneNode*, LayerCount>	mSceneLayers;
		CommandQueue						mCommandQueue;

        Character*							mPlayerCharacter;
};


#endif // GAME_WORLD_HPP