#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cassert>

// $> ./dp-designs 7 < stripes.txt

#define LOG std::cerr << __FUNCTION__ << std::endl

typedef std::size_t NUMBER;
const NUMBER NA = -1;
struct Designs
{
    Designs(int s);
    void load();
    void run();    
    NUMBER solve(int i, int level);
    void setCompatible();
private:
    const int stripes;
    std::vector<int> v;
    std::vector<std::vector<int>> compatible;  
    std::vector<std::vector<NUMBER>> cache;
};

Designs::Designs(int s) : stripes(s)
{
    LOG;
    for (std::size_t i = 0; i != 1897; ++i)
    {
        std::vector<NUMBER> v = std::vector<NUMBER>(15, NA);
        cache.push_back(v);
    }
}

void Designs::setCompatible()
{
    LOG;
    for (std::size_t i = 0; i != v.size(); ++i)
    {
        std::vector<int> c;
        for (std::size_t n = 0; n != v.size(); ++n)
        {
            if ((v[i] & v[n]) == 0b100000000000000000000000000000)
            {
                c.push_back(n);
            }
        }
       compatible.push_back(c);
       //std::cerr << "the stripe = " << s << " is compatible with " << c.size() << " other stripes\n";
    }
}

void Designs::load()
{
    LOG;
	int n;
	while(std::cin >> n)
	{
	  	v.push_back(n);
		std::string s;
		std::cin >> s;
	}
	std::cerr << "input size = " << v.size() << "\n";
}

NUMBER Designs::solve(int i, int level)
{
    //LOG;
    //std::cerr << "i = " << i << ", level = " << level << "\n";
    if (level == 0)
    {
        return 0;
    }
    NUMBER& ret = cache[i][level -1];
    if (ret != NA)
        return ret;
    ret = 0;
    for (auto n: compatible[i])
    {
        ret += solve(n, level - 1);
    }
    return ret;
}

void Designs::run()
{
    LOG;
    NUMBER ret = 0;
    for (size_t i = 0; i != v.size(); ++i)
    {
        ret += solve(i, stripes - 1);
    }
	std::cerr << "design count = " << ret << "\n";    
}

int main(int argc, char* argv[])
{
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::cout << "start at " << std::ctime(&start_time);
    assert(argc == 2);
    int stripes = std::stoi(argv[1]);
    Designs d(stripes);
    d.load();
    d.setCompatible();
    d.run();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);   
    std::cout << "start at " << std::ctime(&start_time);
    std::cout << "end at " << std::ctime(&end_time);
    std::cout << "elapsed " << elapsed_seconds.count() << " seconds for computing " << stripes << " stripes\n";
	return 0;
}
