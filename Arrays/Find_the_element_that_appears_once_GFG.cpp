#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    int XOR = 0;
	    for (int i = 0; i < N; i++)
	        XOR = XOR ^ A[i];
	    return XOR;
	}
};