#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findZeroes(int arr[], int n, int m)
	{
		int flip = m, i = 0, j = 0, k = 0, z = 0, len = 1, maxLen = 0;
		vector<int> zeros;
		while (i < n)
		{
			if (arr[i] == 0)
			{
				zeros.push_back(i);
				if (flip == 0)
				{
					z = j;
					j = zeros[k] + 1;
					k++;
					flip++;
					len = len - j + z;
				}
				flip--;
			}
			len++;
			maxLen = max(maxLen, len);
			i++;
		}
		return maxLen - 1;
	}
};

int main()
{
	int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
	Solution obj;
	cout << obj.findZeroes(arr, 11, 2);
}