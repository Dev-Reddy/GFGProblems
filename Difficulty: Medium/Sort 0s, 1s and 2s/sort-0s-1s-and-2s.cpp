class Solution {
  public:
    void sort012(vector<int>& a) {
        // code here
        // Solved by Dev Reddy
        int n = a.size();
        int i = 0, j = 0, k = n-1;
        // i will keep track of 0s
        // j will keep track of 1s
        // k will keep track of 2s
        
        // we will only move j
        // everytime we encounter a 1 ie a[j]=1, 
        // means we are on the right path
        // and increment by 1
        // if we encounter a 0 ie a[j]=0, 
        // that means we will swap with i, ie swap ai, aj
        // and increment both i and j by 1
        // as we assume everything till j is already sorted
        // and if we encounter a[j]=2, we swap aj, ak
        // and decrease k by 1 as that part is already sorted
        // but we wont inc j, as the number we just sorted may again be 2.
        
        while(j<=k){
            if(a[j]==0){
                swap(a[i], a[j]);
                i++, j++;
            } else if(a[j]==2){
                swap(a[j], a[k]);
                k--;
            } else j++;
        }
    }
};