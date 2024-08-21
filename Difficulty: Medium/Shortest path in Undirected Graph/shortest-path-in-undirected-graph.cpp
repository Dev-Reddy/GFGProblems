//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<vector<int>> adj(N);
        
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        
        queue<int> q; 
        q.push(src);
        vector<int> dis(N,-1);
        vector<int> vis(N,0);
        dis[src]=0;
        vis[src]=1;
        int c=0;
        
        while(!q.empty())
        {
            int size=q.size();
            c++;
            for(int i=0;i<size;i++)
            {
                int u = q.front();
                q.pop();
                
                for(auto & it : adj[u])
                {
                    if(!vis[it])
                    {
                      vis[it]=1;  
                    dis[it]=c;
                    q.push(it);
                    }
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends