#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML\Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
  private:
    TextureManager();
    TextureManager(TextureManager const&);

    std::map <std::string, sf::Texture> textures;

  public:
    static TextureManager& getInstance();

    void addTexture(std::string path);
    sf::Texture& getTexture(std::string id);

};

#endif