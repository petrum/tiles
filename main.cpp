#include <iostream>

struct Tiles
{
    Tiles(int s, int l) : stripes(s), length(l) {}

private:
    int stripes;
    int length;
    int designCount = 0;
};

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Please provide the number of stripes and length (e.g. $> tiles 11 30)\n";
        return -1;
    }
    Tiles tiles(std::stoi(argv[1]), std::stoi(argv[2]));
    return 0;
}
