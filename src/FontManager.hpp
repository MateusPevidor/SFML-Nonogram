#ifndef FONT_MANAGER_HPP
#define FONT_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>

class FontManager {
  private:
    FontManager();
    std::map <std::string, sf::Font> fonts;

  public:
    static FontManager& getInstance();
    void addFont(std::string path);
    sf::Font& getFont(std::string id);

};

#endif