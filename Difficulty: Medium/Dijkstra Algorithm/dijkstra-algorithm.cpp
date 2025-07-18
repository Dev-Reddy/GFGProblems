// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector<vector<pair<int, int>>>adj(V);
        
        for(int i = 0; i < edges.size(); i++){
            vector<int> temp = edges[i];
            int a = temp[0];
            int b = temp[1];
            int c = temp[2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        
        vector<int>dis(V, INT_MAX);
        
        dis[src]=0;
        
        // stores {distance, node} so shortest distances come first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            
            int node = front.second;
            int dist = front.first;
            
            for(auto i: adj[node]){
                int node_i = i.first;
                int dist_i = i.second;
                if(dist+dist_i<dis[node_i]){
                    dis[node_i]=dist+dist_i;
                    pq.push({dis[node_i], node_i});
                }
            }
        }
        
        return dis;
    }
};