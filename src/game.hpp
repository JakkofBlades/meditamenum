#ifndef _GAME_H_
#define _GAME_H_


#include "logger.hpp"
#include "utility.hpp"
#include "input.hpp"

class Game
{
public:
   Game();
   void Run();
   void ConfigureOGL();
   void ProcessEvents();
   void HandleInput();
   void Update();
   void Render();

   void DrawQuad(float size, float pos);
   void DrawRotatingCube();

private:
   void GenerateKeymap();

   sf::RenderWindow window_;
   sf::Clock game_clock_;
   dahl::iris::Logger log_;

   InputController input_controller_;

};

#endif
