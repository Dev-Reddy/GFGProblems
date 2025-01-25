//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        priority_queue<pair<int, pair<int, int>>> pq;
        
        int maxDeadline = 0;
        
        for(int i = 0; i < id.size(); i++){
            maxDeadline = max(maxDeadline, deadline[i]);
            pq.push({profit[i], {deadline[i], id[i]}});
        }
        
        vector<int> days(maxDeadline+1, -1);
        
        int maxProfit = 0, totalJobs = 0;
        
        while(!pq.empty()){
            pair<int, pair<int, int>> front = pq.top();
            pq.pop();
            
            int p = front.first; //profit of job
            int d = front.second.first; //deadline of job
            int i = front.second.second; //id of job
            
            
            for(int j = d; j>0; j--){
                if(days[j]==-1){
                    days[j] = i;
                    maxProfit+=p;
                    totalJobs++;
                    break;
                }
            }
            
        }
        
        return {totalJobs, maxProfit};
    }
};



//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends