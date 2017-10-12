

#ifndef _ENTITY_H_
#define _ENTITY_H_

class Entity {
public:
   Entity(sf::Texture *tex);

private:
   // Render Component
   sf::Texture *texture_;
   sf::Sprite sprite_;

   // Physics Component
   sf::Vector2f position_;
   sf::Vector2f velocity_;
};

#endif
