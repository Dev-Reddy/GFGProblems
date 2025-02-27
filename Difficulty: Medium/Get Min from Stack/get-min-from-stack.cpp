//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 stack<pair<int, int>> st; // Stack to store pairs of (value, current minimum)
    int curr_min; // Variable to keep track of the current minimum value

public:
    Solution() {
        // Initialize curr_min to the maximum possible integer value
        curr_min = INT_MAX;
    }

    // Add an element to the top of the stack
    void push(int x) {
        // Update the current minimum value
        curr_min = min(curr_min, x);
        // Push the pair (x, curr_min) onto the stack
        st.push(make_pair(x, curr_min));
    }

    // Remove the top element from the stack
    void pop() {
        // If the stack is empty, do nothing
        if (st.empty()) return;
        
        // Remove the top element
        st.pop();
        
        // Update curr_min to the minimum value in the new top pair
        if (!st.empty()) {
            curr_min = st.top().second;
        } else {
            // If the stack is empty, reset curr_min to INT_MAX
            curr_min = INT_MAX;
        }
    }

    // Return the top element of the stack
    int peek() {
        // If the stack is empty, return -1
        if (st.empty()) return -1;
        
        // Return the first element of the top pair (the actual value)
        return st.top().first;
    }

    // Retrieve the minimum element from the stack
    int getMin() {
        // If the stack is empty, return -1
        if (st.empty()) return -1;
        
        // Return the second element of the top pair (the current minimum value)
        return st.top().second;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends