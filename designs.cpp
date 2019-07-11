#include <vector>
#include <iostream>

// $> g++ designs.cpp -Wall -Wextra -o designs && ./designs < stripes.txt

#define LOG std::cerr << __FUNCTION__ << std::endl

struct Designs
{
    Designs();
    void load();
    void run();
    void solve(int i);
private:
    std::vector<int> v;
    typedef std::vector<int> TDesigns;
    TDesigns d;
    std::size_t count = 0;
};

Designs::Designs() : d(11)
{
    LOG;
}

void Designs::load()
{
	int n;
	while(std::cin >> n)
	{
	  	v.push_back(n);
		std::string s;
		std::cin >> s;
	}
	std::cerr << "input size = " << v.size() << "\n";    
}

void Designs::run()
{
    LOG;
    int n = 0;
    for (std::size_t i = 0; i != v.size(); ++i)
    {
        d[0] = v[i];
        solve(n + 1);
    }
	std::cerr << "design count = " << count << "\n";    
}

void Designs::solve(int n)
{
    //std::cerr << n << " ";
    //LOG;
    if (n >= 12)
    {
        std::cout << "- design " << count++ << "\n";
        return;
    }

    for (std::size_t i = 0; i != v.size(); ++i)
    {
        int x = v[i];
        if ((d[n-1] & x) == 0b100000000000000000000000000000)
        {
            d[n] = x;
            solve(n + 1);
        }
    }
}

int main()
{
    Designs d;
    d.load();
    d.run();
	return 0;
}
