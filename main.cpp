#include <iostream>
#include <vector>
#include <stack>

struct Stripe
{
    std::stack<int> row;
    std::size_t len = 0;
};

struct Tiles
{
    Tiles(int, int);
    void run();
    int getDesignCount() const {return designCount; }
private:
    int rows;
    int length;
    int designCount = 0;
    std::vector<Stripe> stripes;
};

Tiles::Tiles(int r, int l) : rows(r), length(l), stripes(r)
{
}

void Tiles::run()
{

}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Please provide the number of stripes and length (e.g. $> tiles 11 30)\n";
        return -1;
    }
    int rows = std::stoi(argv[1]), length = std::stoi(argv[2]);
    if (rows < 1 || length < 3)
    {
        std::cerr << "Invalid parameters\n";
        return -2;
    }
    Tiles tiles(rows, length);
    tiles.run();
    std::cout << "There were " << tiles.getDesignCount() << " designs for " << rows << " x " << length << " room." << std::endl;
    return 0;
}
