class Solution {
  public:
    
    int fact(int n) {
        int result = 1;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
    
    int vowelCount(string& s) {
        // code here
        // a e i o u
        // 0 1 2 3 4
        
        map<char, int>mp;
        
        for(auto x: s){
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x ==  'u'){
                mp[x]++;
            }
        }
        
        
        if(mp.size()==0) return 0;
        
        int ans = fact(mp.size());
        
        for(auto i: mp){
            ans *= i.second;
        }
        
        return ans;
        
    }
};