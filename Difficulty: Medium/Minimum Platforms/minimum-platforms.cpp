//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    
    static bool comp(pair<int, int> a, pair<int, int> b){
        if(a.first<b.first) return true;
        if(a.first == b.first) return a.second<b.second;
        else return false;
    }
    
    
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int, int>> times;
        
        for(int i = 0; i < arr.size(); i++){
            times.push_back({arr[i], dep[i]});
        }
        
        sort(times.begin(), times.end(), comp);
        
        // for(int i = 0; i < arr.size(); i++){
        //     cout<<times[i].first<<" "<<times[i].second<<endl;
        // }
        
        int ans = 0;
        
        vector<int> endTimes;
        endTimes.push_back(0);
        
        for(int i = 0; i < times.size();i++){
            int start = times[i].first;
            int end = times[i].second;
            
            bool flag = true;
            
            for(int j = 0; j < endTimes.size(); j++){
                if(endTimes[j]<start){
                    endTimes[j] = end;
                    flag = false;
                    break;
                }
            }
            
            if(flag){
                endTimes.push_back(end);
            }
            
        }
        
        return endTimes.size();
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends