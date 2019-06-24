#ifndef SCREEN_MANAGER_HPP
#define SCREEN_MANAGER_HPP

#include <map>

#include "Screen.hpp"
#include "PlayScreen.hpp"
#include "MenuScreen.hpp"

class ScreenManager {
  private:
    ScreenManager();
    Screen::ScreenType activeScreen;
    std::map <Screen::ScreenType, Screen*> screens;

  public:
    static ScreenManager& getInstance();
    Screen* getScreen(Screen::ScreenType);
    Screen* getActiveScreen();
    void drawScreen(sf::RenderWindow &window);
    void setActiveScreen(Screen::ScreenType);
    void createScreens();
};

#endif