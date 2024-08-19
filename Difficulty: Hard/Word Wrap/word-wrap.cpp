//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int solve(int i, int filled, vector<int> &nums, int n, int k, vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][filled] != -1)
        {
            return dp[i][filled];
        }
        if(filled!=0)
        {
            int temp1 = 1e9, temp2;
            if(filled+1+nums[i] <= k)
            {
                temp1 = solve(i+1, filled+1+nums[i], nums, n, k, dp);
            }
            int count = k-filled;
            temp2 = count*count+solve(i, 0, nums, n, k, dp);
            return dp[i][filled] = min(temp1, temp2);
        }
        else
        {
            return dp[i][filled] = solve(i+1, nums[i], nums, n, k, dp);
        }
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return solve(0, 0, nums, n, k, dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends