#include "UF_PathCompression.hpp"
#include "StopWatch.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N, p, q;
    cin >> N;
    UF_PathCompression uf(N);
    StopWatch sw;
    while(cin >> p && cin >> q)
    {
        if(uf.connected(p, q))
            continue;
        uf.union_componet(p, q);
        cout << p << " " << q << endl;
    }
    double t = sw.elapsedTime();
    cout << uf.count_component() << " components." << endl;
    cout << "Used " << t << " secs" << endl;

    return 0;
}
