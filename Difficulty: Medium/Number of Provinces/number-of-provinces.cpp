//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    
    void dfs(vector<vector<int>>& isConnected, vector<int> & visited, int node){

        for(int i = 0; i < isConnected[node].size(); i++){
            if(isConnected[node][i]==1 && visited[i]==0){
                visited[i]=1;
                dfs(isConnected, visited, i);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<int> visited(V, 0);

        int ans = 0;

        for(int i = 0; i<V; i++){
            if(visited[i]==0){
                dfs(adj, visited, i);
                ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends