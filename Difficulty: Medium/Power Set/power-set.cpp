//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    
	    void helper(string input, string output, vector<string>&ans){
	        if(input.length()==0){
	            if(output=="") return;
	            ans.push_back(output);
	            return;
	        }
	        
	        helper(input.substr(1), output+input[0], ans); //take
	        
	        helper(input.substr(1), output, ans); //not take
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    helper(s, "", ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends