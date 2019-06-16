#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>

class Level { // Informações sobre o nível
  private:
    std::vector <std::vector <int>> rowHeaders; // Cabeçalhos das linhas
    std::vector <std::vector <int>> colHeaders; // Cabeçalhos das colunas
    int rowCount, colCount, guideSize;

  public:
    Level();
    void insertRowHeader(std::vector <int> values);
    void insertColHeader(std::vector <int> values);
    std::vector <std::vector <int>> getColHeaders();
    std::vector <std::vector <int>> getRowHeaders();

    void setRowCount(int value);
    void setColCount(int value);
    void setGuideSize(int value);
    int getRowCount();
    int getColCount();
    int getGuideSize();

};

#endif