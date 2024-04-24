//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int mod=1e9+7;
class Solution
{
public:
    int ways(int x, int y)
    {
        //code here.
        vector<int> pre(y+1,0);
        pre[0]=1;
        for(int i=0;i<=x;i++)
        {
            vector<int> curr(y+1,0);
            if(i==0)
            curr[0]=1;
            
            for(int j=0;j<=y;j++)
            {
                if(i==0 and j==0)
                continue;
                
                int temp=0;
                if(i-1>=0)
                temp=(temp+pre[j])%mod;
                
                if(j-1>=0)
                temp=(temp+curr[j-1])%mod;
                
                curr[j]=temp;
            }
            pre=curr;
        }
        return pre[y];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends