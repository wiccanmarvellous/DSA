#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i, a = arr[i];
            while (j > 0 && arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
    }
};

int main()
{
    int arr[] = {4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    obj.insertionSort(arr, n);
    for (auto it : arr)
        cout << it << ' ';
    cout << endl;
    return 0;
}