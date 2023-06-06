#include <bits/stdc++.h>
using namespace std;

class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int left=0, right=m-1;
        int top=0, bottom=n-1;
        
        int cnt=k;
        
        
        while(top<= bottom && left<=right){
            for(int i=left; i<=right; i++){
                cnt--;
                if(cnt==0){
                    return a[top][i];
                }
            }top++;
            
            for(int i=top; i<=bottom; i++){
                cnt--;
                if(cnt==0){
                    return a[i][right];
                }
            }right--;
            
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                    cnt--;
                    if(cnt==0){
                    return a[bottom][i];
                }
                }bottom--;
            }
            
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    cnt--;
                    if(cnt==0){
                    return a[i][left];
                }
                }left++;
            }
        }
        return -1;
    }

};