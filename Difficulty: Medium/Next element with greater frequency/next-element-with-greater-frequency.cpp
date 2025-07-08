class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        map<int, int> mp; 
        
        for(int x : arr) {
            mp[x]++;
        }
        
        stack<int> st; 
        vector<int> ans(n, -1); 
        
        for(int i = n-1; i >= 0; --i) {
            if(st.empty()) {
                st.push(arr[i]);
            } else {
                while(!st.empty() && mp[arr[i]] >= mp[st.top()]) {
                    st.pop();
                }
                ans[i] = st.empty() ? -1 : st.top();
                st.push(arr[i]);
            }
        }
        return ans;
    }
};
