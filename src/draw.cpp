void Game::DrawQuad(float size, float pos)
{
   // Apply some transformations for the quad
   glMatrixMode(GL_MODELVIEW);

   // Reset the matrix to translate from origin
   glLoadIdentity();
   glTranslatef(0.f, 0.f, -pos);

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   float angle = game_clock_.getElapsedTime().asSeconds();

   glRotatef(angle * rotate, 0.0f, 1.0f, 0.0f);

   // log_.Info() << rotate;

   glBegin(GL_QUADS);//draw some squares

   // Blue
   glColor3f(0,0,1);
   glVertex3f(-size, -size, size);
   glVertex3f(-size,  size, size);
   glVertex3f( size,  size, size);
   glVertex3f( size, -size, size);

   glEnd();
}

void Game::DrawRotatingCube()
{
   bool  rotate = false;
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

   float pos = 75.0f;

   //Draw a cube
   glBegin(GL_QUADS);//draw some squares

   // Orange
   glColor3i(0,1,1);
   glVertex3f(-pos, -pos, -pos);
   glVertex3f(-pos,  pos, -pos);
   glVertex3f( pos,  pos, -pos);
   glVertex3f( pos, -pos, -pos);

   // Blue
   glColor3f(0,0,1);
   glVertex3f(-pos, -pos, pos);
   glVertex3f(-pos,  pos, pos);
   glVertex3f( pos,  pos, pos);
   glVertex3f( pos, -pos, pos);

   // Violet
   glColor3f(1,0,1);
   glVertex3f(-pos, -pos, -pos);
   glVertex3f(-pos,  pos, -pos);
   glVertex3f(-pos,  pos,  pos);
   glVertex3f(-pos, -pos,  pos);

   // Green
   glColor3f(0,1,0);
   glVertex3f(pos, -pos, -pos);
   glVertex3f(pos,  pos, -pos);
   glVertex3f(pos,  pos,  pos);
   glVertex3f(pos, -pos,  pos);

   // Yellow
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
