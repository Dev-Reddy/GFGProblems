class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int i = 0, n = arr.size(), ans = 0, sum = 0;
        
        while(i<k && i<n){
            sum+=arr[i];
            i++;
        }
        
        if(i!=k) return 0;
        
        int j= 0;
        ans = sum;
        
        for(;i<n;i++){
            sum-=arr[j];
            sum+=arr[i];
            ans = max(ans, sum);
            j++;
        }
        
        return ans;
    }
};