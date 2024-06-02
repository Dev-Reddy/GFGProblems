//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int sum = 0;
		int temp = n;
		int c = 0;


		//find number of digits i.e. "k"
		while(temp>0)
		{
			c++;
			temp/=10;
		}

		//change temp to original number n again to run the loop
		temp = n;

		//loop to find sum according to given condition
		while(temp>0)
		{
			int ld = temp%10;
			sum+=pow(ld,c);
			temp/=10;
		}

		return sum==n?"Yes":"No";

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends