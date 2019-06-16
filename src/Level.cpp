#include "Level.hpp"

Level::Level() {}

void Level::insertColHeader(std::vector <int> values) {
  this->colHeaders.push_back(values);
}

void Level::insertRowHeader(std::vector <int> values) {
  this->rowHeaders.push_back(values);
}

std::vector <std::vector <int>> Level::getColHeaders() {
  return this->colHeaders;
}

std::vector <std::vector <int>> Level::getRowHeaders() {
  return this->rowHeaders;
}

void Level::setRowCount(int value) {
  this->rowCount = value;
}

void Level::setColCount(int value) {
  this->colCount = value;
}

void Level::setGuideSize(int value) {
  this->guideSize = value;
}

int Level::getRowCount() {
  return this->rowCount;
}

int Level::getColCount() {
  return this->colCount;
}

int Level::getGuideSize() {
  return this->guideSize;
}
