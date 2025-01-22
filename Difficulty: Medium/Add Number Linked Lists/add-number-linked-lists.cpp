//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    
    Node * reverse(Node * head){
        if(!head || !head->next) return head;
        
        Node * curr = head;
        Node* prev = nullptr;
        
        while(curr){
            Node*temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        
        Node* n1 = reverse(num1);
        Node* n2 = reverse(num2);
        
        Node*head = new Node(-1);
        
        Node * curr = head;
        
        Node* c1 = n1;
        Node * c2 = n2;
        
        int carry = 0;
        
        while(c1 && c2){
            int sum = c1->data + c2->data + carry;
            
            int toAdd = sum%10;
            
            carry = sum/10;
            
            Node * newNode = new Node(toAdd);
            
            curr->next = newNode;
            
            curr = curr->next;
            
            c1= c1->next;
            c2= c2->next;
        }
        
        while(c1){
            int sum = c1->data + carry;
            
            int toAdd = sum%10;
            
            carry = sum/10;
            
            Node * newNode = new Node(toAdd);
            
            curr->next = newNode;
            
            curr = curr->next;
            
            c1= c1->next;
        }
        
        while(c2){
            int sum = c2->data + carry;
            
            int toAdd = sum%10;
            
            carry = sum/10;
            
            Node * newNode = new Node(toAdd);
            
            curr->next = newNode;
            
            curr = curr->next;
            
            c2= c2->next;
        }
        
        
        if(carry>0){
            Node * newNode = new Node(carry);
            
            curr->next = newNode;
            
            curr = curr->next;
        }
        
        
        
        
        Node * ans =  reverse(head->next);
        
        Node * temp = ans;
        
        while(temp->data==0){
            temp=temp->next;
        }
        
        return temp;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends