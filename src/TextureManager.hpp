#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class TextureManager {
  private:
    TextureManager();
    std::map <std::string, sf::Texture> textures;

  public:
    static TextureManager& getInstance(); // Singleton para otimização do uso de memória
    void addTexture(std::string path);
    sf::Texture& getTexture(std::string id);

};

#endif