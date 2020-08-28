#!/usr/bin/bash
mkdir -p Debug/
g++ CursoCPP/*.cpp -pedantic-errors -Wall -Weffc++ -Wextra \
       	-Wsign-conversion -Werror -std=c++17 -o Debug/salida
