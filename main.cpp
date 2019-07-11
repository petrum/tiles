#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

#define LOG std::cerr << __FUNCTION__ << std::endl

struct Stripe
{
    Stripe(int l) : v(l) {}
    bool push2();
    void pop();
    bool push3();
    bool full() const { return len == v.size(); }
    std::deque<int> row;
    std::vector<int> v;
    int len = 0;
};

std::ostream& operator <<(std::ostream& o, const Stripe& s)
{
    o << "len = " << s.len << ", row = [";
    for (auto i: s.row)
    {
        o << i << ", ";
    }
    o << "], v = [";
    for (auto i: s.v)
    {
        o << i;
    }
    o << "]"; 
}

bool Stripe::push2()
{
    LOG;
    if (len + 2 > v.size())
        return false;
    row.push_back(2);
    v[len++] = 0;
    v[len++] = 1;
}

void Stripe::pop()
{
    LOG;
    int i = row.back();
    row.pop_back();
    len -= i;
    std::cerr << *this << std::endl;
}

bool Stripe::push3()
{
    LOG;
    if (len + 3 > v.size())
        return false;
    row.push_back(3);
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
    void solve();
private:
    void solve2();
    int rows;
    int length;
    int designCount = 0;
    std::vector<Stripe> stripes;
    int crtRow = 0;
    friend std::ostream& operator <<(std::ostream& o, const Tiles& t);
};

std::ostream& operator <<(std::ostream& o, const Tiles& t)
{
    o << "rows = " << t.rows << ", length = " << t.length << ", designCount = " << t.designCount << ", crtRow = " << t.crtRow;
    for (const auto& s: t.stripes)
    {
        o << "\n\t" << s;
    }
    return o;
}

bool Tiles::isValid() const
{
    LOG;
    if (crtRow == 0)
        return true;
    const Stripe& s2 = stripes[crtRow];
    const Stripe& s1 = stripes[crtRow - 1];
    assert (s1.full());
    if (s2.full())
        return true;
    return s1.v[s2.len] != 0; 
}

Tiles::Tiles(int r, int l) : rows(r), length(l), stripes(r, l)
{
}

void Tiles::solve()
{
    int crtRowTmp = crtRow;
    solve2();
    crtRow = crtRowTmp;
}

void Tiles::solve2()
{
    LOG;
    std::cerr << *this << std::endl;
    {
        Stripe& s = stripes[crtRow];
        if (s.full() && (crtRow == stripes.size() - 1))
        {
            std::cout << "Found design:\n" << *this << std::endl;
            ++designCount;
            return;
        }
        if (s.full())
            ++crtRow;
    }

    Stripe& s = stripes[crtRow]; 
    if (s.push2())
    {
        if (isValid())
            solve();
        s.pop();
    }
    if (s.push3())
    {
        if (isValid())
            solve();
        s.pop();
    }
}

void Tiles::run()
{
    LOG;
    solve();
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
