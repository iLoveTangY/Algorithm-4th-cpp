#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "ShellSort.hpp"
#include "../Chapter_1/StopWatch.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

double computeTime(const string &alg, vector<double> &a)
{
    StopWatch sw;
    if(alg == "Insertion")
        InsertionSort<double>().sort(a);
    else if(alg == "Selection")
        SelectionSort<double>().sort(a);
    else if(alg == "Shell")
        ShellSort<double>().sort(a);
    else if(alg == "Standard")
        sort(a.begin(), a.end());

    return sw.elapsedTime();
}

double timeRandomInput(const string &alg, int N, int T)
{
    double total = 0.0;
    vector<double> a;
    uniform_real_distribution<> u(0, 1);
    default_random_engine e;
    for(int t = 0; t < T; t++)
    {
        for(int i = 0; i < N; i++)
            a.push_back(u(e));
        total += computeTime(alg, a);
    }
    return total;
}

int main(void)
{
    string alg1, alg2;
    int N, T;

    cin >> alg1 >> alg2 >> N >> T;

    double t1 = timeRandomInput(alg1, N, T);
    double t2 = timeRandomInput(alg2, N, T);
    double t3 = timeRandomInput("Standard", N, T);
    cout << "For " << N << " random Doubles" << endl;
    cout << alg1 << " used: " << t1 << " seocnds" << endl;
    cout << alg2 << " used: " << t2 << " seconds" << endl;
    cout << "STL sort used: " << t3 << " seconds" << endl;
    cout << alg1 << " is " << t2/t1 << " times faster than " << alg2 << endl;

    return 0;
}
