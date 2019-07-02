#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SFML/Graphics.hpp>

class Screen {
  public:
    enum ScreenType {
      PlayScreen,
      MenuScreen,
      LoadSaveScreen,
      VictoryScreen
    };
};

#endif