#include <bits/stdc++.h>
using namespace std;

// Brute force	O(nlogn)
// class Solution{
// public:	
// 	// Function returns the second
// 	// largest elements
// 	int print2largest(int arr[], int n) {
// 	    sort(arr, arr + n, greater<int>());
// 	    int i = 1;
// 	    while (i < n)
// 	    {
// 	        if (arr[i] != arr[i - 1])
// 	            return arr[i];
// 	        i++;
// 	    }
// 	    return -1;
// 	}
// };

// Better approach	O(2n)
// class Solution{
// public:	
// 	// Function returns the second
// 	// largest elements
// 	int print2largest(int arr[], int n) {
// 	    int lg = 0, slg = 0;
// 	    for (int i = 0; i < n; i++) 
// 	        if (lg < arr[i])
// 	            lg = arr[i];
// 	    for (int i = 0; i < n; i++)
// 	        if (slg < arr[i] && arr[i] != lg)
// 	            slg = arr[i];
// 	    if (slg == 0)
// 	        return -1;
// 	    return slg;
// 	}
// };

// Optimal approach	O(n)
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int lg = -1, slg = -1;
	    for (int i = 0; i < n; i++)
	    {
	        if (arr[i] > lg)
	        {
	            slg = lg;
	            lg = arr[i];
	        }
	        else if (arr[i] < lg && arr[i] > slg)
	            slg = arr[i];
	    }
	    return slg;
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