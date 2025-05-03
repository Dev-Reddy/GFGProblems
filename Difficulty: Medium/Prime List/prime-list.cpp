//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    Node *primeList(Node *head) {
        // code here
        Node* curr = head;

    vector<bool> prime(13001, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= 13000; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= 13000; j += i) {
                prime[j] = false;
            }
        }
    }

    curr = head;
    while (curr) {
        if (curr->val < 2) {
            curr->val = 2;
        } else if (!prime[curr->val]) {
            int v = curr->val;
            int pos = v, neg = v;

            while (pos <= 13000 && !prime[pos]) pos++;
            while (neg >= 2 && !prime[neg]) neg--;

            int v1 = abs(neg - v);
            int v2 = (pos <= 13000) ? abs(pos - v) : INT_MAX;

            curr->val = (v1 <= v2) ? neg : pos;
        }
        curr = curr->next;
    }

    return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends