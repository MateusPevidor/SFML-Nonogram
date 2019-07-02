#include "FontManager.hpp"

FontManager::FontManager() {
  this->fonts = std::map <std::string, sf::Font>();
}

FontManager& FontManager::getInstance() {
  static FontManager instance;
  return instance;
}

void FontManager::addFont(std::string path) {
  sf::Font font;
  font.loadFromFile(path);
  std::pair <std::string, sf::Font> newEntry = std::pair <std::string, sf::Font>(path, font);
  this->fonts.insert(newEntry);
}

sf::Font& FontManager::getFont(std::string id) {
  sf::Font *font = &this->fonts.at(id);
  return *font;
}