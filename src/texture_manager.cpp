#include "texture_manager.h"

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{

}

int TextureManager::AddTexture(string name, sf::Texture texture)
{
   texture_map_[name] = texture;
}

int TextureManager::AddTexture(string name, string image_path)
{
   sf::Texture* texture;

   if(!(texture->loadFromFile(imagePath)))
   {
      return NULL;
   }

   texture_map_[name] = texture;

   return 1;
}

sf::Texture TextureManager::GetTexture(string name)
{

}

sf::Texture TextureManager::GetTexture(int index)
{

}
