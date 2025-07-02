class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<bool>vis(adj.size(), false);
        
        queue<int>q;
        
        q.push(0);
        vis[0]=true;
        
        vector<int>ans;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto i: adj[front]){
                if(vis[i]) continue;
                q.push(i);
                vis[i] = true;
            }
        }
        
        
        return ans;
    }
};