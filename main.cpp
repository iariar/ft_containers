#include "Vector.hpp"


// template <typename T>
// struct is_integral
// {
//     static bool value = false;
// };

// template <>
// struct is_integral<int>
// {
//     static bool value = true;
// };


// template <bool, typename T = void>
// struct enable_if{};

// template <>
// struct enable_if<true, T>{
//     typedef T type;
// };

int main ()
{
  // constructors used in the same order as described above:
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int> second (4,100);                       // four ints with value 100
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

// int main()
// {
//     std::vector<int> original(2, 3);
//     ft::vector<int> replica(original.begin(), original.end());
//     replica.push_back(17);
//     replica.push_back(18);
//     replica.push_back(19);
//     // for (ft::vector<int>::iterator i = replica.begin(); i != replica.end(); i++)
//     // {
//     //     std::cout << *i << std::endl;
//     // }
//     // replica.pop_back();
//     // replica.pop_back();
//     // replica.pop_back();
//     // replica.pop_back();
//     // for (ft::vector<int>::reverse_iterator i = replica.rbegin(); i != replica.rend(); i++)
//     // {
//     //     std::cout << *i << std::endl;
//     // }
//     // original.push_back(17);
//     // original.push_back(18);
//     // original.push_back(19);

//     // for (ft::vector<int>::iterator i = replica.begin(); i != replica.end(); i++)
//     // {
//     //     std::cout << *i << std::endl;
//     // }
//     // printf("size = %lu\n", replica.size());
//     // replica.resize(20);
//     // printf("size = %lu\n", replica.size());
//     // for (ft::vector<int>::iterator i = replica.begin(); i != replica.end(); i++)
//     // {
//     //     std::cout << *i << std::endl;
//     // }
//     // std::cout << replica.empty() << std::endl;
//     // for (int i = 0; i < replica.size(); i++)
//     // {
//     //    std::cout << replica[i] << std::endl;
//     // }
//     // std::cout << replica.back() << std::endl;
//     // printf("%lu\n", original.size());
//     // original.resize(20);
//     // for (std::vector<int>::iterator i = original.begin(); i != original.end(); i++)
//     // {
//     //     std::cout << *i << std::endl;
//     // }
//     // replica.insert(replica.end(), replica.begin(), replica.end());
//     // original.insert(original.end(), 10, 40);
//     // for (int i = 0; i < original.size(); i++)
//     // {
//     //    std::cout << original[i] << std::endl;
//     // }
//     replica.erase(replica.begin(), replica.end());
//     for (int i = 0; i < replica.size(); i++)
//     {
//        std::cout<< "size = " << replica.size() << "----" << replica[i] << std::endl;
//     }
// }