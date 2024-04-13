//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long helper(long long n){
        vector<int> binary;
        while(n)
        {
            if(n%2)
            binary.push_back(1);
            else
            binary.push_back(0);
            
            n/=2;
        }
        
        for(int i=binary.size();i<31;i++)
        binary.push_back(0);
        
        //reversing the binary 
        //calculate decimal for this binary
        long long ans=0;
        for(int i=binary.size()-1;i>=0;i--)
        {
            if(binary[i])
            ans+=pow(2,binary.size()-i);
        }
        return ans;
    }
  public:
    long long reversedBits(long long x) {
        // code here
        return helper(x);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends