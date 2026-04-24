class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
          int n = arr.size();
        int maxheight = arr[0];
        int count = 0;
        for(int i =0;i<n;i++){
            if(arr[i]>=maxheight){
                count ++;
                maxheight=arr[i];
            }
        }
        return count;
    }
};