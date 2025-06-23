class Solution {
  public:
    string sm(string &a,string &b){
      string temp="";
      int n=a.size();
      int m=b.size();
      int cary=0;
      int i=n-1,j=m-1;
      while(i>=0 and j>=0){
          int sm=a[i]-'0'+b[j]-'0'+cary;
          temp+=sm%10+'0';
          cary=sm/10;
          i--,j--;
      }
      while(i>=0){
          int sm=a[i]-'0'+cary;
          temp+=sm%10+'0';
          cary=sm/10;
          i--;
      }
      while(j>=0){
          int sm=b[j]-'0'+cary;
          temp+=sm%10+'0';
          cary=sm/10;
          j--;
      }
      if(cary){
          temp+=cary+'0';
      }
      while(temp.back()=='0') temp.pop_back();
      reverse(begin(temp),end(temp));
      return temp;
  }
    string minSum(vector<int> &arr) {
        // code here
        sort(begin(arr),end(arr));
        string a="",b="";
        int n=arr.size();
        for(int i=0;i<n;i+=2){
            a+=arr[i]+'0';
        }
        for(int i=1;i<n;i+=2){
            b+=arr[i]+'0';
        }
        return sm(a,b);
    }
};