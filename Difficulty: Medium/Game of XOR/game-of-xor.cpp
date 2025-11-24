class Solution {
  public:
    int subarrayXor(vector<int>& A) {
        // code here
        int N = A.size();
        int ans =A[0];
       if(N%2==0)return 0;
       for(int i=2;i<N;i+=2){
           ans^=A[i];
       }
       return ans ;
    }
};