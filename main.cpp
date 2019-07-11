#include <iostream>

struct Tiles
{
    Tiles(int stripes, int length) {}
;}

int main(int argc, char* argv)
{
    if (argc != 3)
    {
        std::cerr << "Please provide the number of stripes and length (e.g. 11 30)\n";
        return -1;
    }
    Tiles tiles(std::stoi(argv[1]), stoi(argv[2]));
    return 0;
}
