class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        int n=txt.size(),m=pat.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0),curr(m+1,0);
        prev[0]=1;
        for(int i=1;i<=m;i++){
            if(pat[i-1]=='*'){
                prev[i]=1;
            }
            else break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pat[j-1]=='?'){
                    curr[j]=prev[j-1];
                }
                else if(pat[j-1]=='*'){
                    curr[j]=prev[j-1] || prev[j] || curr[j-1];
                }
                else if(pat[j-1]==txt[i-1]){
                    curr[j]=prev[j-1];
                }
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};