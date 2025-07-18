// User function Template for C++
class Solution {
  
  void topo(vector<vector<pair<int, int>>> &adj, stack<int> &s, vector<int>& vis, int node){
      vis[node] = true;
      
      for(auto i: adj[node]){
          int j = i.first;
          if(!vis[j]) topo(adj, s, vis, j);
      }
      
      s.push(node);
  }
  
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int, int>>>adj(V);
        
        for(int i = 0; i < E; i++){
            vector<int> temp = edges[i];
            int a = temp[0];
            int b = temp[1];
            int c = temp[2];
            adj[a].push_back({b,c});
        }
        
        // do topo sort as its dag
        // then find out the distance
        
        stack<int>s;
        vector<int>vis(V, 0);
        
        topo(adj, s, vis, 0);
        
        vector<int>dis(V, INT_MAX);
        
        dis[0] = 0;
        
        while(!s.empty()){
            int node = s.top();
            s.pop();
            for(auto i: adj[node]){
                dis[i.first] = min(dis[i.first], dis[node] + i.second);
            }
        }
        
        for(int i = 0; i < V; i++){
            if (dis[i]==INT_MAX) dis[i]=-1;
        }
        
        
        return dis;
        
    }
};
