#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++) 
        {
            int flag = 1;
            for (int j = 0; j < n - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    flag = 0;
                }
            }
            if (flag)
                break;
        }
    }
};

int main()
{
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    obj.bubbleSort(arr, n);
    for (auto it : arr)
        cout << it << ' ';
    cout << endl;
    return 0;
}