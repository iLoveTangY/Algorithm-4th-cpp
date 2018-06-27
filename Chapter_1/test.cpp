#include "WeightedQuickUnion.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, p, q;
    cin >> N;
    WeightedQuickUnion uf(N);
    while(cin >> p && cin >> q)
    {
        if(uf.connected(p, q))
            continue;
        uf.union_componet(p, q);
        cout << p << " " << q << endl;
    }
    cout << uf.count_component() << " components." << endl;

    return 0;
}
