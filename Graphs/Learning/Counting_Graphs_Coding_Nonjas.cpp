#include <bits/stdc++.h>
using namespace std;

int countingGraphs(int N)
{
    return pow(2, (N * (N - 1)) / 2);
}