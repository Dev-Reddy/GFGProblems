//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:	
    int func(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + func(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j] = max(func(i-1,j,s1,s2,dp), func(i,j-1,s1,s2,dp));
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size();
	    int m = str2.size();
	    vector<vector<int>> dp(n,vector<int>(m,-1));
	    int len = func(n-1,m-1,str1,str2,dp);
	    return n+m -2*len;
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends