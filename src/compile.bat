@echo off
g++ -c *.cpp -I ..\dependencies\include\
g++ *.o -L ..\dependencies\lib\ -lsfml-graphics -lsfml-window -lsfml-system -o sfml-app.exe
sfml-app.exe