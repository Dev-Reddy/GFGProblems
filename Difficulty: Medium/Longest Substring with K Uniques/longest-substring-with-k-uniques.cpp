class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
         int n=s.size();
        int i=0;
        int st=0;
        int ans = -1;
        unordered_map<char,int>mp;
        while(i<n)
        {
            mp[s[i]]++;
            while(mp.size()>k)
            {
                mp[s[st]]--;
                if(mp[s[st]]==0)
                {
                    mp.erase(s[st]);
                }
                st++;
            }
            i++;
            if(mp.size()==k)
            {
                ans=max(ans,i-st);
            }
        }
        return ans;
    }
};