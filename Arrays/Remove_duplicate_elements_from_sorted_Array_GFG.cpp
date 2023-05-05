#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int remove_duplicate(int a[],int n){
        int i = 0;
        for (int j = 0; j < n; j++)
            if (a[i] != a[j])
                a[++i] = a[j];
        return i + 1;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    Solution obj;
    int k = obj.remove_duplicate(arr, n);
    for (int i = 0; i < k; i++)
        cout << arr[i] << ' ';
    cout << endl;
    }
    return 0;
}