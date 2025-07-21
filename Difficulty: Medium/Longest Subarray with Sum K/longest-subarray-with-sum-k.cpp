class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum = 0;
        
        // store sum, index where it first came
        map<int, int> mp;
        mp[0] = 0;
        
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++){
            sum+=arr[i];
            if(mp.find(sum)==mp.end()) mp[sum]=i+1;
            
            // check if sum - k exists and if yes then where
            int rem = sum - k;
            
            if(mp.find(rem)!=mp.end()) ans = max(ans, i - mp[rem] + 1);
        }
        
        return ans;

    }
};