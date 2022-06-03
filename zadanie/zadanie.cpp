#include <iostream>
#include <vector>
#include <set>

int main()
{
    std::vector<int> v = { 1, 3, 2, 1, 4, 3 };

    for (int x : v) std::cout << x << ' ';
    std::cout << std::endl;

    std::set<int> s;

    for (auto iter = v.begin(); iter != v.end(); ) {
        if (s.find(*iter) == s.end()) {
            s.insert(*iter);
            iter++;
        }
        else {
            iter = v.erase(iter);
        }
    }

    for (int x : v) std::cout << x << ' ';
    std::cout << std::endl;

    return 0;
}