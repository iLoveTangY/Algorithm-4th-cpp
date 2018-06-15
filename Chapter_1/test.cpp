#include "StopWatch.hpp"
#include "ThreeSum.hpp"
#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main(void)
{
    uniform_int_distribution<int> u(-1000000, 1000000);
    default_random_engine e;

    int N = 2000;
    vector<int> ivec;
    for(int i = 0; i < N; ++i)
        ivec.push_back(u(e));
    ThreeSum ths;
    StopWatch s;
    int cnt = ths.count(ivec);
    cout << cnt << " triples found in " << s.elapsedTime() << endl;

    return 0;
}
