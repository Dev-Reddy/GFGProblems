class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> ans;
        
        
        for (int i=1;i<=n;i++){
            int j=i;
        
             string res="";
              while(j > 0){
            if (j%2==1) 
            { 
                res+='1';
                
            }
            else {
                res+='0';
            }
            
            j=j/2;
        }
        reverse(res.begin(),res.end());
        ans.push_back(res);
    
        }
        
        return ans;
    }
};