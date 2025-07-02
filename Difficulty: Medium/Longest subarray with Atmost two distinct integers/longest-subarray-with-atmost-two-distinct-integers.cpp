class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        map<int, int> mp;
        
        int i = 0;
        mp[arr[0]]++;
        
        int ans = 1;
        
        for(int j = 1; j < arr.size(); j++){
            mp[arr[j]]++;
            if(mp.size()<=2){
                ans = max(ans, j-i+1);
            } else if(mp.size()>2){
                while(mp.size()>2){
                    mp[arr[i]]--;
                    if(mp[arr[i]]==0) mp.erase(arr[i]);
                    i++;
                }
            }
        }
        
        return ans;
    }
};