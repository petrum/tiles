#include <vector>
#include <iostream>
#include <bitset>
#include <cassert>
#include <chrono>
#include <ctime>

// $> g++ designs.cpp -std=c++11 -Wall -Wextra -o designs && ./designs 7 < stripes.txt

#define LOG std::cerr << __FUNCTION__ << std::endl

struct Designs
{
    Designs(int s);
    void load();
    void run();
    void solve(int i);
private:
    const int stripes;
    std::vector<int> v;
    typedef std::vector<int> TDesigns;
    TDesigns d;
    std::size_t count = 0;
    friend std::ostream& operator <<(std::ostream& o, const Designs::TDesigns& design);
};

std::ostream& operator <<(std::ostream& o, const Designs::TDesigns& d)
{
    for (int i: d)
    {
        std::cout << "\t- " << i << " " << std::bitset<30>(i).to_string() << std::endl;
    }
    return o;
}

Designs::Designs(int s) : stripes(s), d(s)
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
    if (n >= stripes)
    {
        ++count;
        if (count % 1000000 == 0)
        {
            //std::cout << "- design " << count << ":\n" << d << "\n";
            std::cout << "- design " << count << "\n";
        }
        return;
    }

    for (std::size_t i = 0; i != v.size(); ++i)
    {
        int x = v[i];
        if ((d[n - 1] & x) == 0b100000000000000000000000000000)
        {
            d[n] = x;
            solve(n + 1);
        }
    }
}

int main(int argc, char* argv[])
{
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    assert(argc == 2);
    int stripes = std::stoi(argv[1]);
    Designs d(stripes);
    d.load();
    d.run();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);   
    std::cout << "start at " << std::ctime(&start_time);
    std::cout << "end at " << std::ctime(&end_time);
    std::cout << "elapsed " << elapsed_seconds.count() << " seconds for computing " << stripes << " stripes\n";
	return 0;
}
