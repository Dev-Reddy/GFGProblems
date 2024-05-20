//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long

class Solution
{
	public:
	ll power(ll base,ll n,ll mod)
	{
	    ll ans=1;
	    while(n)
	    {
	        if(n&1)
	        {
	            ans=(ans*base)%mod;
	            n--;
	        }
	        else
	        {
	            base=(base*base)%mod;
	            n/=2;
	        }
	    }
	    return ans;
	}
	long long int PowMod(long long int x,long long int n,long long int M)
	{
	    return power(x,n,M);
	}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends