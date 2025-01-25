//{ Driver Code Starts
#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node* root) {
    map<Node*, int> link;
    Node* temp = root;
    for (int i = 0; temp != NULL; i++) {
        link[temp] = i;
        temp = temp->next;
    }
    temp = root;
    cout << "[";
    while (temp->next != NULL) {
        if (!temp->random) {
            cout << "[" << temp->data << ", "
                 << "NULL"
                 << "], ";
        } else
            cout << "[" << temp->data << ", " << link[temp->random] + 1 << "], ";
        temp = temp->next;
    }
    if (!temp->random) {
        cout << "[" << temp->data << ", "
             << "NULL"
             << "]]\n";
    } else
        cout << "[" << temp->data << ", " << link[temp->random] + 1 << "]]\n";
}

bool validation(Node* res, map<Node*, int>& orgAddress) {
    Node* temp = res;
    for (int i = 0; temp != NULL; i++) {
        if (orgAddress.find(temp) != orgAddress.end()) {
            return false;
        }
        if (orgAddress.find(temp->random) != orgAddress.end()) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

Node* buildLinkedList(vector<pair<int, int>>& v, map<Node*, int>& orgAddress) {
    vector<Node*> address(v.size());
    Node* head = new Node(v[0].first);
    address[0] = head;
    Node* temp = head;
    orgAddress[head] = 0;
    for (int i = 1; i < v.size(); i++) {
        Node* newNode = new Node(v[i].first);
        orgAddress[newNode] = i;
        address[i] = newNode;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second != -1) {
            temp->random = address[v[i].second - 1];
        }
        temp = temp->next;
    }

    return head;
}

bool validateInput(map<Node*, int>& orgAddress, Node* head, vector<pair<int, int>>& v) {
    vector<Node*> address(v.size());
    Node* temp = head;
    for (int i = 0; i < v.size(); i++) {
        if (orgAddress.find(temp) == orgAddress.end() || orgAddress[temp] != i) {
            return false;
        }
        address[i] = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        return false;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++) {
        int value = v[i].first;
        int randomIndex = v[i].second;

        if (randomIndex == -1) {
            if (temp->random != NULL) {
                return false;
            }
        } else {
            Node* tempNode = address[randomIndex - 1];
            if (temp->random != tempNode) {
                return false;
            }
        }
        temp = temp->next;
    }
    return true;
}


// } Driver Code Ends
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

// DEV REDDY

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        //  Seeing the constraints, we have to solve this using O(1) space
        // This rules out the use of map
        
        // We will try a different approach
        
        // Forget about the random pointers of now
        // For now just create a clone list and put it in between the nodes of the original list
        
        // For eg, say original list is O, and cloned is C
        
        // Suppose the data is represented by a, b, c....
        
        // Then try to do this :- 
        
        // O(a) -> C(a) -> O(b) -> C(b) -> O(c) -> C(c) -> ..... -> NULL
        
        // Yes, nodes can have same values but just forget that now, focus on the concept 
        // that each original node is followed by its clone
        
        
        Node * temp = head;
        
        while(temp){
            Node* clonedNode = new Node(temp->data);
            Node* rest = temp->next;
            temp->next = clonedNode;
            clonedNode->next = rest;
            temp = temp->next->next;
        }
        
        // Now we have this list
        // O(a) -> C(a) -> O(b) -> C(b) -> O(c) -> C(c) -> ..... -> NULL
        
        // Now we traverse the list
        // The next for each cloned node will be equal to cloned->next->next
        
        // And the random for each original node can help us find the random of cloned
        // as we have copied in such a way that
        // (random of current node)->next = (random of cloned)
        
        
        // Let's just take care of the random for now
        
        temp = head;
        
        while(temp){
            if (temp->random) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = nullptr;
            }

            temp=temp->next->next;
        }
        
        // Now we have taken care of random also
        // But our list is still of the following form : -
        // O(a) -> C(a) -> O(b) -> C(b) -> O(c) -> C(c) -> ..... -> NULL
        
        // We need to seperate our lists
        
        Node* newHead = new Node(-1); //dummy node to attach our head to
        
        temp = head; //to traverse the nodes of original list
        
        Node * temp2 = newHead; //to travserse the nodes of our cloned list
        
        while(temp){
            
            temp2->next = temp->next; //attach the cloned node to the new list
            temp2 = temp2->next; //move temp2 to the new list
            
            temp->next = temp->next->next; //attach the correct node to the node of the orignal list
            
            temp2->next = nullptr; //break connection with the orignal list
            
            temp = temp->next;
        }
        
        
        return newHead->next;
        
    }
};








//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n); // node data, random node number
        for (int i = 0; i < n; i++) {
            int x;
            string y;
            cin >> x >> y;
            if (y == "NULL" || y == "N" || y == "null" || y == "n" || y == "Null") {
                v[i] = {x, -1};
            } else {
                v[i] = {x, stoi(y)};
            }
        }
        map<Node*, int> orgAddress;
        Node* head = buildLinkedList(v, orgAddress);

        Solution ob;
        Node* res = ob.cloneLinkedList(head);
        // check if input modified.
        if (validateInput(orgAddress, head, v)) {
            if (validation(res, orgAddress)) {
                print(res);
            } else {
                cout << "Pointing to the original list\n";
            }
        } else {
            cout << "Input list modified\n";
        }
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends