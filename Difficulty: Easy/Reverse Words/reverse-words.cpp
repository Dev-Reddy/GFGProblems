//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
         reverse(s.begin(), s.end());
       int i=0;
       for(int j=0; j<=s.size(); j++){
           if(s[j] == '.' || j == (s.size())){
               reverse(s.begin()+i, s.begin()+j);
               i = j+1;
           }
       }
       return s;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends