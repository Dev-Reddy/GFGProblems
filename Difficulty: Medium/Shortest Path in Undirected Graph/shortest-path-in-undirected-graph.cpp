class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        vector<int>dis(n, INT_MAX);
        
        queue<int>q;
        
        q.push(src);
        dis[src]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i: adj[node]){
                if(dis[i]==INT_MAX) q.push(i);
                dis[i] = min(dis[i], dis[node]+1);
            }
        }
        
        for(int & i: dis){
                if(i==INT_MAX) i = -1;
            }
        
        return dis;
    }
};