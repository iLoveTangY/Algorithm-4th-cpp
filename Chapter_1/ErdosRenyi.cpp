#include "WeightedQuickUnion.hpp"

#include <iostream>
#include <random>

using namespace std;

int count_edges(int n)
{
    WeightedQuickUnion uf(n);

    uniform_int_distribution<unsigned> u(0, n-1);
    default_random_engine e;
    int edges = 0;

    while(uf.count_component() > 1)
    {
        int p = u(e);
        int q = u(e);
        uf.union_componet(p, q);
        edges++;
    }

    return edges;
}

int main(void)
{
    int N;
    cin >> N;

    cout << count_edges(N) << endl;
    
    return 0;
}
