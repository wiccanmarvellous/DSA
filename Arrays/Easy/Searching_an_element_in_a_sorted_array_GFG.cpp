#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K)
    {
        for (int i = 0; i < N; i++)
            if (arr[i] == K)
                return 1;
        return -1;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;
    Solution obj;
    if(obj.searchInSorted(arr, n, k) == 1)
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;
    return 0;
}