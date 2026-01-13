class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int cnt5=0,cnt10=0,n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]==10) 
            {
                if(cnt5<1) return false;
                else cnt10++,cnt5--;
            }
            else if(arr[i]==20) 
            {
                if(cnt5<1||(cnt10<1 && cnt5<3)) return false;
                else 
                {
                    if(cnt10) cnt10--,cnt5--;
                    else cnt5-=3;
                }
            }
            else 
            {
                cnt5++;
            }
        }
        return true;
    }
};