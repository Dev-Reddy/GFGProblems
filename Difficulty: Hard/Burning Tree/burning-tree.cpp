/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        int max_size = 0;
        unordered_map<int,int>parent; // node -> parent
        unordered_map<int,vector<int>>child;// node->{left,ringht}
        queue<Node*>q;
        q.push(root);
        parent[root->data] = -1; 
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            max_size=max(max_size,front->data);
            if(front->left)
            {
                q.push(front->left);
                parent[front->left->data] = front->data;
                child[front->data].push_back(front->left->data);
            }
            if(front->right)
            {
                q.push(front->right);
                parent[front->right->data] = front->data;
                child[front->data].push_back(front->right->data);
            }
        }
        queue<int>nq;
        vector<bool>visited(max_size+1,false);
        int ans = 0;
        visited[target] = true;
        nq.push(target);
        while(!nq.empty())
        {
            int n = nq.size();
            bool burned = false;
            

            for(int i=0; i<n; i++)
            {
                int node = nq.front();
                nq.pop();
                if(parent[node]!=-1 && visited[parent[node]]==false)
                {
                    nq.push(parent[node]);
                    visited[parent[node]]=true;
                    burned = true;
                }
                if(child.find(node)!=child.end())
                {
                    for(auto c : child[node])
                    {
                        if(!visited[c])
                        {
                            nq.push(c);
                            visited[c] = true;
                            burned = true;
                        }
                    }
                }
            }
            if(burned) ans++;
        
        }
        return ans;
        
    }
};