#include <bits/stdc++.h>
using namespace std;

//class implemented
struct Item{
    int value;
    int weight;
};

// TC O(n log n + n)    SC O(1)

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, [](const auto &a, const auto &b) {
            return double(a.value) / a.weight > double(b.value) / b.weight;
        });
            
        int w = 0, i = 0;
        double ans = 0;
        while (i < n) {
            if (arr[i].weight + w > W) {
                ans += (double(arr[i].value) / arr[i].weight) * double(W - w);
                break;
            }
            ans += arr[i].value;
            w += arr[i].weight;
            i++;
        }
        return ans;
    }
        
};