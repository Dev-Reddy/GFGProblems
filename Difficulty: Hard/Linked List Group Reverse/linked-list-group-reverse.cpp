//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
    
    pair<Node*, Node*> reverse(Node*head){
        if(!head) return {NULL, NULL};
        if(!head->next) return {head, head};
        
        pair<Node*, Node*> temp = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return {temp.first, head};
    }
    
    int countNodes(Node*head){
        int count = 0;
        
        Node*temp = head;
        
        while(temp){
            count++;
            temp = temp->next;
        }
        
        return count;
    }
    
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here

        if(countNodes(head)<=k){
            return reverse(head).first;
        }

        Node*temp = head;
        
        int i = 1;
        while(i<k){
            temp=temp->next;
            i++;
        }
        
        Node* nextPart = temp->next;
        
        temp->next = nullptr;
        
        pair<Node*, Node*> curr = reverse(head);
        
        
        Node* nextPartReversed = reverseKGroup(nextPart, k);
        
        curr.second->next = nextPartReversed;
        
        return curr.first;
        
    }
};



















//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

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
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends