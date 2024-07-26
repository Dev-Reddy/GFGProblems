//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int  merge(long long arr[], int low, int mid, int high) {
     vector<long long> temp(high - low + 1); // pre-allocate memory
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner
        long long int cnt = 0;
        int k = 0; // index for temp array

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k++] = arr[left++];
            } else {
                cnt += (mid - left + 1);
                temp[k++] = arr[right++];
            }
        }

        // if elements on the left half are still left
        while (left <= mid) {
            temp[k++] = arr[left++];
        }

        // if elements on the right half are still left
        while (right <= high) {
            temp[k++] = arr[right++];
        }

        // transferring all elements from temporary to arr
        for (int i = 0; i < temp.size(); i++) {
            arr[low + i] = temp[i];
        }
        
        return cnt;
}

long long int mergeSort(long long arr[], int low, int high) {
    long long int  cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt+= mergeSort(arr, low, mid);  // left half
    cnt+= mergeSort(arr, mid + 1, high); // right half
    cnt+= merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        
        return mergeSort(arr, 0 , n-1);
    }
};


//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends