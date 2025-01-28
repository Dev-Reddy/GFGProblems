//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    
    int ans = 0;
    
    void merge(vector<int>& arr, int l, int mid, int r){
        
        int i = l, j = mid+1;
        
        vector<int> temp;
        
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                temp.push_back(arr[i]);
                i++;
            } else {
                ans+=mid+1-i;
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j<=r){
            temp.push_back(arr[j]);
            j++;
        }
        
        int k = 0;
        
        for(i = l; i<=r; i++){
            arr[i] = temp[k];
            k++;
        }
  }
  
  
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l>=r) return;
        
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        mergeSort(arr, 0, arr.size()-1);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends