class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
         int n = arr.size();
        
        int mini = arr[0], maxi = arr[0];
        int ans = 0;
        
        if(arr.size() == 1) return arr[0];
        
        for(int i = 1; i<n; i++){
        
            if(arr[i] < 0) swap(maxi,mini);
        
            mini = min(mini*arr[i], arr[i]);
            maxi = max(maxi*arr[i], arr[i]);
            ans = max(ans,maxi);
        
        }
        
        return ans;
    }
};