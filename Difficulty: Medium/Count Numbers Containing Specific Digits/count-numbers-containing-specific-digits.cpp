class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
            
       int first=0 ; 
       int second=0 ; 
       for(auto it : arr)
       {
           if(it==0)second++ ; 
           else 
           {
               first++ ; 
               second++ ; 
           }
       }
       
       int ans= (9-first)*(pow(10-second , n-1)) ; 
       int tot=9*(pow(10 , n-1)) ; 
       return tot-ans ; 
    }
};
