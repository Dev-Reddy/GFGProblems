class Solution {
  
  bool helper(vector<int> &arr, vector<vector<int>> &dp, int target, int i){
      if(target==0) return true;
      
      if(i==arr.size()) return target==0;
      
      if(dp[i][target]!=-1) return dp[i][target];
      
      bool take = false;
      if(arr[i]<=target) take = helper(arr, dp, target - arr[i], i+1);
      
      bool notTake = helper(arr, dp, target, i+1);
      
      dp[i][target] = take | notTake;
      
    //   cout<<i<<" "<<target<<" "<<dp[i][target]<<endl;
      
      return dp[i][target];
      
    }
  
  
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
        helper(arr, dp, sum, 0);
        
        return dp[0][sum];
    }
};