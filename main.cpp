#include <iostream>
#include <vector>
#include <stack>

struct Stripe
{
    Stripe(int l) : v(l) {}
    bool push2();
    void pop();
    bool push3();
    bool fool() const {return len == v.size(); }
private:
    std::stack<int> row;
    std::vector<int> v;
    int len = 0;
};

bool Stripe::push2()
{
    if (len + 2 > len)
        return false;
    row.push(2);
    v[len++] = 0;
    v[len++] = 1;
}

void Stripe::pop()
{
    int i = row.top();
    row.pop();
    len -= i;
}

bool Stripe::push3()
{
    if (len + 3 > len)
        return false;
    row.push(3);
    v[len++] = 0;
    v[len++] = 1;    
    v[len++] = 2;
}

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
    int crtRow = 0;
};

Tiles::Tiles(int r, int l) : rows(r), length(l), stripes(r, l)
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
