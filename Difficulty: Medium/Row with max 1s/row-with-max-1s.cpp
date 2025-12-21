// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n =arr.size();
             int m=arr[0].size();
                int maxi = 0;
                int res =-1;
             for(int i=0;i<n;i++){
                   
                    int l = 0;
                    int r = m-1;
                   int ans =  -1;
                   while (l<=r){
                        int mid = (l+r)/2;
                        
                        if (arr[i][mid]==1){
                             ans = mid;
                            r = mid-1;
                        }
                        else if (arr[i][mid]<1){
                               l =mid+1;
                        }
                        else{
                             r= mid-1;
                        }
                        
                   }
                //   cout<<m-ans<<" "<<maxi <<endl;
                // cout<<ans;
                   if (ans!=-1 && m-ans<=m && m-ans >maxi){
                        res =i;
                        maxi = m-ans;
                   }
             }
             return res ;
             
    }
};