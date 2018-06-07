#include "Bag.hpp"

#include <iostream>

using namespace std;

int main(void)
{
    Bag<int> b;
    b.add(1);
    b.add(2);
    
    for(auto i : b)
        cout << i << endl;

    return 0;
}
