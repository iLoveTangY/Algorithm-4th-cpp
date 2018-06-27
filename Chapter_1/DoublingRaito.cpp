#include "ThreeSumFast.hpp"
#include "StopWatch.hpp"
#include <vector>
#include <iostream>
#include <cstdio>
#include <random>

using namespace std;

double timeTrial(int N)
{
    int MAX = 100000;
    uniform_int_distribution<int> u(-MAX, MAX);
    default_random_engine e;
    vector<int> a;
    for(int i = 0; i < N; i++)
        a.push_back(u(e));

    StopWatch timer;
    ThreeSumFast ths;
    int cnt = ths.count(a);
    return timer.elapsedTime();
}

int main(void)
{
    double prev = timeTrial(125);
    for (int N = 250; true; N += N)
    {
        double time = timeTrial(N);
        printf("%7d %5.1f ", N, time);
        printf("%5.1f\n", time/prev);
        prev = time;
    }
}
