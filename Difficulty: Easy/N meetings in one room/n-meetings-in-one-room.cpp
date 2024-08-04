//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        
        vector<pair<int,int>> m(n);
        
        for(int i = 0;i<n;i++){
            m[i] = {end[i],start[i]};
        }
        
        sort(m.begin(),m.end());
        
        int ans = 0;
        int last = -1;
        
        for(auto i: m){
            int s = i.second;
            
            if(s>last){
                ans++;
                last = i.first;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends