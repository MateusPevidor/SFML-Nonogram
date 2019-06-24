#include "WindowManager.hpp"

WindowManager::WindowManager() {}

void WindowManager::setWindow(sf::RenderWindow* window) {
  this->window = window;
}

sf::RenderWindow* WindowManager::getWindow() {
  return this->window;
}

WindowManager& WindowManager::getInstance() {
  static WindowManager instance;
  return instance;
}