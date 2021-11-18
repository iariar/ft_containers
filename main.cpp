#include "Vector.hpp"

int main()
{
    std::vector<int> original(1, 2);
    ft::vector<int> replica(original.begin(), original.end());
    replica.push_back(17);
    replica.push_back(18);
    replica.push_back(19);

    // for (ft::vector<int>::iterator i = replica.begin(); i != replica.end(); i++)
    // {
    //     std::cout << *i << std::endl;
    // }
    // replica.pop_back();
    // replica.pop_back();
    // replica.pop_back();
    // replica.pop_back();
    // for (ft::vector<int>::reverse_iterator i = replica.rbegin(); i != replica.rend(); i++)
    // {
    //     std::cout << *i << std::endl;
    // }
    // original.push_back(17);
    // original.push_back(18);
    // original.push_back(19);

    // for (ft::vector<int>::iterator i = replica.begin(); i != replica.end(); i++)
    // {
    //     std::cout << *i << std::endl;
    // }
    // printf("size = %lu\n", replica.size());
    // replica.resize(20);
    // printf("size = %lu\n", replica.size());
    // for (ft::vector<int>::iterator i = replica.begin(); i != replica.end(); i++)
    // {
    //     std::cout << *i << std::endl;
    // }
    // std::cout << replica.empty() << std::endl;
    // for (int i = 0; i < replica.size(); i++)
    // {
    //    std::cout << replica[i] << std::endl;
    // }
    // std::cout << replica.back() << std::endl;
    // printf("%lu\n", original.size());
    // original.resize(20);
    // for (std::vector<int>::iterator i = original.begin(); i != original.end(); i++)
    // {
    //     std::cout << *i << std::endl;
    // }
    replica.insert(replica.end(), 10, 40);
    for (int i = 0; i < replica.size(); i++)
    {
       std::cout << replica[i] << std::endl;
    }
}