#include "TextureManager.hpp"

TextureManager::TextureManager() {
  this->textures = std::map <std::string, sf::Texture>();
}

TextureManager& TextureManager::getInstance() {
  static TextureManager instance;
  return instance;
}

void TextureManager::addTexture(std::string path) {
  sf::Texture newTexture;
  newTexture.loadFromFile(path);
  newTexture.setSmooth(true);
  std::pair <std::string, sf::Texture> newEntry = std::pair<std::string, sf::Texture>(path, newTexture);
  this->textures.insert(newEntry);
}

sf::Texture& TextureManager::getTexture(std::string id) {
  sf::Texture* res = nullptr;
  res = &textures.at(id);
  return *res;
}
