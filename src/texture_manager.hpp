

class TextureManager
{
public:
   TextureManager();
   ~TextureManager();

   int AddTexture(string name, sf::Texture texture);
   int AddTexture(string name, string image_path);

   sf::Texture GetTexture(string name);
   sf::Texture GetTexture(int index);

private:
   std::map<string, sf::Texture> texture_map_;
}
