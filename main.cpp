#include <iostream>
#include <vector>
#include <stack>

struct Tiles
{
    Tiles(int s, int l) : stripes(s), length(l) {}
    void design();
    int getDesignCount() const {return designCount; }
private:
    int stripes;
    int length;
    int designCount = 0;
    std::vector<std::stack<int>> data;
};

void Tiles::design()
{
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Please provide the number of stripes and length (e.g. $> tiles 11 30)\n";
        return -1;
    }
    int stripes = std::stoi(argv[1]), length = std::stoi(argv[2]);
    Tiles tiles(stripes, length);
    tiles.design();
    std::cout << "There were " << tiles.getDesignCount() << " designs for " << stripes << " x " << length << " room." << std::endl;
    return 0;
}
