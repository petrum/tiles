#!/bin/bash

g++ main.cpp -std=c++11 -DDEBUG -g -Wall -Wextra -o tiles
g++ stripes.cpp -std=c++11 -Wall -Wextra -o stripes 
g++ designs.cpp -std=c++11 -Wall -Wextra -o designs
