#include "game.hpp"

#include "GL/glu.h"

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

Game::Game()
   : log_("Game"),
     window_(sf::VideoMode(800, 600, 32), "Meditamenum"),
     input_controller_(),
     game_clock_() {}

void Game::Run()
{
   ConfigureOGL();

   while(window_.isOpen())
   {
      ProcessEvents();
      Update();
      HandleInput();
      Render();
   }
}

void Game::ConfigureOGL()
{
   glClearDepth(1.f);
   glClearColor(0.3f, 0.3f, 0.3f, 0.f);
   glEnable(GL_DEPTH_TEST);
   glDepthMask(GL_TRUE);

   //// Setup a perspective projection & Camera position
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(90.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar
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
         if (event.key.code == sf::Keyboard::Escape)
         {
            window_.close();
         }
      }
   }
}

void Game::HandleInput()
{

}

void Game::Update()
{

}

void Game::Render()
{
   DrawRotatingCube();
   window_.display();
}

void Game::DrawRotatingCube()
{
   bool rotate = true;
   float angle = 0.0;

   // Prepare for drawing
   // Clear color and depth buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Apply some transformations for the cube
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.f, 0.f, -200.f);

   if(rotate)
   {
      angle = game_clock_.getElapsedTime().asSeconds();
   }

   glRotatef(angle * 50, 1.f, 0.f, 0.f);
   glRotatef(angle * 30, 0.f, 1.f, 0.f);
   glRotatef(angle * 90, 0.f, 0.f, 1.f);

   float pos = 75.0f;

   //Draw a cube
   glBegin(GL_QUADS);//draw some squares

   glColor3i(0,1,1);
   glVertex3f(-pos, -pos, -pos);
   glVertex3f(-pos,  pos, -pos);
   glVertex3f( pos,  pos, -pos);
   glVertex3f( pos, -pos, -pos);

   glColor3f(0,0,1);
   glVertex3f(-pos, -pos, pos);
   glVertex3f(-pos,  pos, pos);
   glVertex3f( pos,  pos, pos);
   glVertex3f( pos, -pos, pos);

   glColor3f(1,0,1);
   glVertex3f(-pos, -pos, -pos);
   glVertex3f(-pos,  pos, -pos);
   glVertex3f(-pos,  pos,  pos);
   glVertex3f(-pos, -pos,  pos);

   glColor3f(0,1,0);
   glVertex3f(pos, -pos, -pos);
   glVertex3f(pos,  pos, -pos);
   glVertex3f(pos,  pos,  pos);
   glVertex3f(pos, -pos,  pos);

   glColor3f(1,1,0);
   glVertex3f(-pos, -pos,  pos);
   glVertex3f(-pos, -pos, -pos);
   glVertex3f( pos, -pos, -pos);
   glVertex3f( pos, -pos,  pos);

   glColor3f(1,0,0);
   glVertex3f(-pos, pos,  pos);
   glVertex3f(-pos, pos, -pos);
   glVertex3f( pos, pos, -pos);
   glVertex3f( pos, pos,  pos);

   glEnd();

}
