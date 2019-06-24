#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include "WindowManager.hpp"
#include "ScreenManager.hpp"

class EventManager {
  private:
    EventManager();

  public:
    static EventManager& getInstance();
    void handleEvent(sf::Event);
};

#endif