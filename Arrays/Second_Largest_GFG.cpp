#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    sort(arr, arr + n, greater<int>());
	    int i = 1;
	    while (i < n)
	    {
	        if (arr[i] != arr[i - 1])
	            return arr[i];
	        i++;
	    }
	    return -1;
	}
};


int main()
{
    int arr[] = {1, 2, 0, 3, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    int a = obj.print2largest(arr, n);
    if (a != -1)
        cout << "Second largest element in given array is " << a << endl;
    else
        cout << "No second largest element present." << endl;
    return 0;
}