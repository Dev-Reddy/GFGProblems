//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    void helper(string s, set<string> &ans, int ind){
        if(ind==s.size()){
            ans.insert(s);
            return;
        }
        
        for(int i = ind; i<s.size();i++){
            swap(s[i], s[ind]);
            helper(s, ans, ind+1);
            swap(s[i], s[ind]);
        }
    }
    
    
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        
        set<string>ans;
        
        helper(s, ans, 0);
        
        vector<string> final_ans;
        
        for(auto i:ans){
            final_ans.push_back(i);
        }
        
        return final_ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends