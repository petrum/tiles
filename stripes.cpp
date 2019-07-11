#include <iostream>
#include <bitset>

// $> g++ stripes.cpp -Wall -Wextra -o stripes && ./stripes | wc -l
// 1897

int main()
{
        int MASK000 = 0b111111111111111111111111111000;
        int MASK11  = 0b000000000000000000000000000011;
        int ALL     = 0b111111111111111111111111111111;
        int FIRST   = 0b100000000000000000000000000000;
        int LAST    = 0b000000000000000000000000000001;
        for (int i = 0; i < ALL + 1; ++i)
        //for (int i = 894784852; i < 894784853; ++i)
        {
                //std::string binary = std::bitset<30>(i).to_string();
                //std::cerr << binary << std::endl;
                int tmp = i;
                if (!(tmp & FIRST))
                        continue;
                if (tmp & LAST)
                        continue;
                int n = 0;
                for (; n < 29; ++n)
                {
                        //std::cerr << "-\tn = " << n << ": " << std::bitset<30>(tmp).to_string();
                        if ((tmp | MASK000) == MASK000)
                        {
                                //std::cerr << ": failed1" << std::endl;
                                break;
                        }
                        if ((tmp & MASK11) == MASK11)
                        {
                                //std::cerr << ": failed2" << std::endl;
                                break;
                        }
                        //std::cerr << ": ok" << std::endl;
                        tmp = tmp >> 1;
                }
                //std::cerr << (n == 28 ? "fine" : "fail") << ": " << i << std::endl;
                if (n == 29)
                        std::cout << i << ": " << std::bitset<30>(i).to_string() << std::endl;
        }
        return 0;
}
