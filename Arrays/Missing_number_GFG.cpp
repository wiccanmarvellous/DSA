#include <bits/stdc++.h>
using namespace std;

// Breute force O(N * N)
int missingNumber(int A[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        int flag = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (i == A[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
    return -1;
}

// Better approach TC O(N) + O(N)   SC O(N)
int missingNumber(int A[], int N)
{
    int arr[N + 1] = {0};
    for (int i = 0; i < N - 1; i++)
        arr[A[i]] = 1;
    for (int i = 1; i <= N; i++)
        if (arr[i] == 0)
            return i;
}


int missingNumber(int A[], int N)
{
    long int ASum = 0, allSum = (N * (N + 1) / 2);
    for (int i = 0; i < N - 1; i++)
        ASum += A[i];
    return allSum - ASum;
}


int missingNumber(int A[], int N)
{
    int x = 0;
    for (int i = 0; i <= N; i++)
        x = x ^ i;
    for (int i = 0; i < N - 1; i++)
        x = x ^ A[i];
    return x;
}

int missingNumber(int A[], int N)
{
    int x = 0;
    for (int i = 0; i < N - 1; i++)
    {
        x = x ^ (i + 1);
        x = x ^ A[i];
    }
    return x ^ N;
}