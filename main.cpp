#include "Vector.hpp"

int main()
{
    std::vector<int> original(3, 2);
    original.push_back(17);
    original.push_back(18);
    original.push_back(19);
    ft::vector<int> replica(original.begin(), original.end());

    for (ft::vector<int>::iterator i = replica.begin(); i != replica.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    
}