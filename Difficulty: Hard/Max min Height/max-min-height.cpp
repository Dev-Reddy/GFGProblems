class Solution {
  public:
     bool isPossible(vector<int> nums, int k, int w, int minHeight)
    {
        int n = nums.size();
        unordered_map<int, int> mp{};
        int curWt = 0;
        
        for(int i = 0; i < n && k >= 0; i++)
        {
            if(mp.count(i))
            {
                curWt += mp[i];
            }
            
            int curHt = nums[i] + curWt;
            
            if(curHt >= minHeight) continue;
            
            if(minHeight - curHt > k) return false;
            
            curWt += (minHeight-curHt);
            k -= (minHeight-curHt);
            mp[i+w] -= (minHeight-curHt);
        }
        
       return true;
    }
    
    int maxMinHeight(vector<int> &nums, int k, int w) {
        // code here
        int n = nums.size();
        int minHeight = INT_MAX;
        int maxHeight = INT_MIN;
        
        for(int i = 0; i < n; i++)
        {
            minHeight = min(minHeight, nums[i]);
            maxHeight = max(maxHeight, nums[i]);
        }
        
        int l = minHeight;
        int h = maxHeight + k;
        
        int res = l;
        
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            
            if(isPossible(nums, k, w, mid))
            {
                res = max(res, mid);
                l = mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
        return res;
    }
};