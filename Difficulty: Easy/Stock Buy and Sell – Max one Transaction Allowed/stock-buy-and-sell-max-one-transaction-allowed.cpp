class Solution {
  public:
    int maxProfit(vector<int> &arr) {
        // code here
         int min=INT_MAX,p=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<min){ 
                min=arr[i];
            }
            else if((arr[i] - min) > p) p =arr[i]-min; 
        }
        return p;
    }
};
