#include "entity.hpp"


Entity(sf::Texture* tex)
   : texture_(tex)
{
   sprite_.setTexture(&tex);
}
