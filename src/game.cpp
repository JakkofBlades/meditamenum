#include "game.hpp"

#include "GL/glu.h"

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <random>
#include <ctime>
#include <vector>

namespace
{
   float zoom = 150.0f;
   float rotate = 10.0f;

   const int WINDOW_WIDTH = 800;
   const int WINDOW_HEIGHT = 600;

   const float GRAVITY = .1;

   const int MAX_ENEMIES = 5;

   sf::Sprite g_PlayerSprite;
   sf::Sprite g_EnemySprites[8];

   sf::Texture g_PlayerTexture;
   sf::Texture g_EnemyTexture;

   sf::Vector2f playerVelX(WINDOW_WIDTH / 10, 0.0);
   sf::Vector2f playerVelY(0.0, GRAVITY);

   int g_NumEntitiesOnScreen = 0;


   int g_CurrentPattern = 0;

   std::vector<std::vector<int>> patterns;

   std::vector<int> spawnPatternOdd = {(WINDOW_WIDTH / 10) * 1 - 16,
                                       (WINDOW_WIDTH / 10) * 3 - 16,
                                       (WINDOW_WIDTH / 10) * 5 - 16,
                                       (WINDOW_WIDTH / 10) * 7 - 16,
                                       (WINDOW_WIDTH / 10) * 9 - 16};

   std::vector<int> spawnPatternEven = {(WINDOW_WIDTH / 10) * 2 - 16,
                                        (WINDOW_WIDTH / 10) * 4 - 16,
                                        (WINDOW_WIDTH / 10) * 6 - 16,
                                        (WINDOW_WIDTH / 10) * 8 - 16};

   std::vector<int> spawnPatternLeft = {(WINDOW_WIDTH / 10) * 1 - 16,
                                        (WINDOW_WIDTH / 10) * 2 - 16,
                                        (WINDOW_WIDTH / 10) * 3 - 16,
                                        (WINDOW_WIDTH / 10) * 4 - 16};

   std::vector<int> spawnPatternRight = {(WINDOW_WIDTH / 10) * 6 - 16,
                                         (WINDOW_WIDTH / 10) * 7 - 16,
                                         (WINDOW_WIDTH / 10) * 8 - 16,
                                         (WINDOW_WIDTH / 10) * 9 - 16};

   std::vector<int> spawnPatternCenter = {(WINDOW_WIDTH / 10) * 3 - 16,
                                          (WINDOW_WIDTH / 10) * 4 - 16,
                                          (WINDOW_WIDTH / 10) * 5 - 16,
                                          (WINDOW_WIDTH / 10) * 6 - 16,
                                          (WINDOW_WIDTH / 10) * 7 - 16};

   int g_Pattern = 0;
}

Game::Game()
   : log_("Game"),
     window_(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Meditamenum"),
     input_controller_(),
     game_clock_() {}

void Game::Run()
{
   log_.Warn() << "Starting Application";

   GenerateKeymap();

   LoadTextures();
   LoadSprites();

   LoadPatterns();

   srand(time(NULL));

   while(window_.isOpen())
   {
      ProcessEvents();
      Update();
      Render();
   }
}

void Game::LoadTextures()
{
   if(!g_PlayerTexture.loadFromFile("../assets/stick_figure.png"))
   {
      log_.Warn() << "Could not load stick_figure texture";
   }

   if(!g_EnemyTexture.loadFromFile("../assets/enemy.png"))
   {
      log_.Warn() << "Could not load stick_figure texture";
   }
}

void Game::LoadSprites()
{
   g_PlayerSprite.setTexture(g_PlayerTexture);
   g_PlayerSprite.setPosition(sf::Vector2f(400.0, 550.0));
   g_PlayerSprite.setOrigin(16.0, 32.0);


   for(int i = 0; i < 5; i++)
   {
      g_EnemySprites[i].setTexture(g_EnemyTexture);
      g_EnemySprites[i].setPosition(spawnPatternEven[i], 0.0);
   }

}

void Game::LoadPatterns()
{
   AddPattern(spawnPatternOdd);
   AddPattern(spawnPatternEven);
   AddPattern(spawnPatternLeft);
   AddPattern(spawnPatternRight);
   AddPattern(spawnPatternCenter);
}

void Game::GenerateKeymap()
{
   input_controller_.AddKeyPrefix("C-z");

   input_controller_.AddKeyCommand("a", new MoveCommand(&g_PlayerSprite, -playerVelX));
   input_controller_.AddKeyCommand("d", new MoveCommand(&g_PlayerSprite, playerVelX));

   input_controller_.AddKeyCommand("C-a", new NullCommand());

   input_controller_.AddKeyCommand("C-p", new PrintCommand("Input"));

   input_controller_.AddKeyCommand("C-z C-a", new PrintCommand("ChainedCommand"));
}

void Game::ProcessEvents()
{
   sf::Event event;

   while(window_.pollEvent(event))
   {
      switch(event.type)
      {
      case sf::Event::Closed:
         window_.close();
         break;
      case sf::Event::KeyPressed:
         input_controller_.HandleKeyPress(event);
         break;
      case sf::Event::KeyReleased:
         input_controller_.HandleKeyRelease(event);
         break;
      default:
         break;
      }
   }
}

void Game::Update()
{
   sf::Vector2f pos = g_EnemySprites[0].getPosition();
   std::vector<int> currPattern;

   if(pos.y > (float)WINDOW_HEIGHT)
   {
      g_CurrentPattern += 1;

      if(g_CurrentPattern > patterns.size())
      {
         g_CurrentPattern = 0;
      }

      currPattern = patterns[g_CurrentPattern];

      for(int i = 0; i < currPattern.size(); i++)
      {
         g_EnemySprites[i].setPosition(currPattern[i], 0.0);
      }
   }
   else
   {
      for(int i = 0; i < 5; i++)
      {
         g_EnemySprites[i].move(0.0, GRAVITY);
      }
   }
}

void Game::Render()
{
   window_.clear(sf::Color::White);
   window_.draw(g_PlayerSprite);

   for(int i = 0; i < MAX_ENEMIES; i++)
   {
      window_.draw(g_EnemySprites[i]);
   }

   window_.display();
}

void Game::AddPattern(std::vector<int> pattern)
{
   patterns.push_back(pattern);
}
