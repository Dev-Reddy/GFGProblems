class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
          unordered_map<int,int>map;
        for(int i=0;i<arr.size();i++)
        {
            map[i]=-1;
        }
        stack<pair<int,int>>st;
        for(int i=0;i<arr.size();i++)
        {
             int t=arr[i];
             while(!st.empty())
             {
                 pair<int,int>top=st.top();
                 if(top.first<t)
                 {
                     map[top.second]=t;
                     st.pop();
                 }
                 else
                 break;
             }
             st.push({t,i});
        }
        for(int i=0;i<arr.size();i++)
        {
             int t=arr[i];
             while(!st.empty())
             {
                 pair<int,int>top=st.top();
                 if(top.first<t)
                 {
                     map[top.second]=t;
                     st.pop();
                 }
                 else
                 break;
             }
             st.push({t,i});
        }
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        ans.push_back(map[i]);
        return ans;
    }
};