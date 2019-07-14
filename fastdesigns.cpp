#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cassert>

// $> ./fastdesigns 7 < stripes.txt

#define LOG std::cerr << __FUNCTION__ << std::endl

struct Designs
{
    Designs(int s);
    void load();
    void run();
private:
    const int stripes;
    std::vector<int> v;
    std::size_t count = 0;
};

Designs::Designs(int s) : stripes(s)
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
	std::cerr << "design count = " << count << "\n";    
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
