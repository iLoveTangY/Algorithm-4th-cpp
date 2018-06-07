#include "Counter.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double binomial1(int N, int k, double p, Counter &c)
{
    c++;
    if(N == 0 && k == 0)
        return 1.0;
    if(N < 0 || k < 0)
        return 0.0;
    return (1.0 - p) * binomial1(N-1, k, p, c) + p * binomial1(N-1, k-1, p, c);
}

// 以空间换时间计算二项分布
double binomial2(int N, int k, double p)
{
    vector<vector<double>> b(N+1);
    for(size_t i = 0; i < b.size(); i++)
        b[i].resize(k+1);
    for(int i = 0; i <= N; i++)
       b[i][0] = pow(static_cast<float>(1.0 - p), i);
    b[0][0] = 1.0;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= k; j++)
            b[i][j] = p * b[i-1][j-1] + (1.0 - p) * b[i-1][j];

    return b[N][k];
}

int main(void)
{
    int N, k;
    double p;
    Counter c("Counter");
    cin >> N >> k >> p;
    cout << binomial1(N, k, p, c) << endl;
    cout << c << endl;
    cout << binomial2(N, k, p) << endl;

    return 0;
}
