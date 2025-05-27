class Solution {
  public:
    void solve(vector<int>& pre,int &idx,vector<int>&ans,int mini,int maxi){
        if(idx+1 >= pre.size()){
            // for(auto i : ans) cout<<"i : "<<i<<" ";
         return;
        }
        int id = idx; 
        bool ch = 1;
        if( pre[id] > pre[idx+1] && mini < pre[idx+1]){
            ch = 0;
            solve(pre,++idx,ans,mini,pre[idx]);
        }
        if(pre[id] < pre[idx+1] && maxi > pre[idx+1]){
            ch = 0;
            solve(pre,++idx,ans,pre[idx],maxi);
        }
        if(ch){
            // cout<<"SDGs"<<id<<" ->";
           ans.push_back(pre[id]);
        }
    }
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        vector<int> ans;
        int idx = 0;
        solve(preorder,idx,ans,INT_MIN,INT_MAX);
        ans.push_back(preorder[preorder.size()-1]);
        return ans;
    }
};