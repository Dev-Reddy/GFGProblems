//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        // code here
        int i=0,j=m-1,ans=-1;
	    while(i<n and j>=0){
	        if(mat[i][j]==1){
			   ans=i;
	            j--;
	        }
	        if(mat[i][j]==0){
	        i++;
	        }
	   }
	    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends