//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        // we want to end our meetings as soon as possible so there is time for more
        // so we will sort them according to their end time
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        //pq to store end and start
        
        for(int i = 0; i<start.size(); i++){
            pq.push({end[i], start[i]});
        }
        
        int ans = 0;
        
        int lastEndTime = -1;
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int e = front.first;
            int s = front.second;
            
            if(s > lastEndTime){
                ans++;
                lastEndTime = e;
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends