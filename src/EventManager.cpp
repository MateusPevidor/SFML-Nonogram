#include "EventManager.hpp"
#include <iostream>

EventManager::EventManager() {}

EventManager& EventManager::getInstance() {
  static EventManager instance;
  return instance;
}

void EventManager::handleEvent(sf::Event event) {
  if (event.type == sf::Event::Closed)
    WindowManager::getInstance().getWindow()->close();
  
  if (event.type == sf::Event::MouseButtonPressed) {
    if (ScreenManager::getInstance().getActiveScreenType() == Screen::PlayScreen) {
      PlayScreen *p = (PlayScreen*) ScreenManager::getInstance().getActiveScreen();
      p->handleClick(event);
    }
  }
}