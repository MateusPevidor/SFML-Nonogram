#include "ScreenManager.hpp"

ScreenManager::ScreenManager() {}

ScreenManager& ScreenManager::getInstance() {
  static ScreenManager instance;
  return instance;
}

void ScreenManager::drawScreen(sf::RenderWindow &window) {
  if (this->activeScreen == Screen::PlayScreen) {
    PlayScreen *screen = (PlayScreen*) this->screens.at(Screen::PlayScreen);
    screen->draw(window);
  } else if (this->activeScreen == Screen::MenuScreen) {
    MenuScreen *screen = (MenuScreen*) this->screens.at(Screen::MenuScreen);
    screen->draw(window);
  }
}

void ScreenManager::createScreens() {
  void *mem = malloc(sizeof(PlayScreen));
  PlayScreen *playScreen = new(mem) PlayScreen();
  std::pair <Screen::ScreenType, Screen*> playScreenEntry(Screen::PlayScreen, playScreen);
  this->screens.insert(playScreenEntry);

  mem = malloc(sizeof(MenuScreen));
  MenuScreen *menuScreen = new(mem) MenuScreen();
  std::pair <Screen::ScreenType, Screen*> menuScreenEntry(Screen::MenuScreen, menuScreen);
  this->screens.insert(menuScreenEntry);
  
  this->activeScreen = Screen::MenuScreen;
}

Screen* ScreenManager::getScreen(Screen::ScreenType type) {
  return this->screens.at(type);
}

Screen* ScreenManager::getActiveScreen() {
  return this->screens.at(this->activeScreen);
}

void ScreenManager::setActiveScreen(Screen::ScreenType type) {
  this->activeScreen = type;
}