class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        map<int,int> freq;
        for(int num: arr)freq[num]++;
        
        map<int,int> end;
        for(int num: arr){
            if(freq[num] == 0)continue;
            else if(end[num-1]>0){
                end[num-1]--;
                end[num]++;
                freq[num]--;
            }
            else{
                for(int i = 0;i<k;i++){
                    if(freq[num+i] == 0)return false;
                    freq[num+i]--;
                }
                end[num+k-1]++;
            }
        }
        return true;
    }
};
