#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

struct Stripe
{
    Stripe(int l) : v(l) {}
    bool push2();
    void pop();
    bool push3();
    bool full() const { return len == v.size(); }
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
    bool isValid() const;
private:
    int rows;
    int length;
    int designCount = 0;
    std::vector<Stripe> stripes;
    int crtRow = 0;
};

bool Tiles::isValid() const
{
    if (crtRow == 0)
        return true;
    const Stripe& s2 = stripes[crtRow];
    const Stripe& s1 = stripes[crtRow - 1];
    assert (s1.full());
    return s1.v[s2.len] != 0;
}

Tiles::Tiles(int r, int l) : rows(r), length(l), stripes(r, l)
{
}


void Tiles::run()
{
    //advance();
}

int main(int argc, char* argv[])
{
    assert(argc == 3);
    int rows = std::stoi(argv[1]), length = std::stoi(argv[2]);
    assert (rows > 0 && length > 1);
    Tiles tiles(rows, length);
    tiles.run();
    std::cout << "There were " << tiles.getDesignCount() << " designs for " << rows << " x " << length << " room." << std::endl;
    return 0;
}
