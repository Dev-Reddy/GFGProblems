/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
    Node* ReverseList (Node* temp) {
        Node* prev = NULL;
        Node* curr = temp;
        Node* nex = temp;
        while (curr) {
            nex = nex->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
  public:
    bool isPalindrome(Node *head) {
        //  code here
        Node* slow = head;
        Node* fast = head;
        Node* temp = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
            }
        }
        if (fast == NULL) {
            slow = slow->next;
        }
        slow = ReverseList(slow);
        while (slow) {
            if (temp->data != slow->data) {
                return false;
            }
            slow = slow->next;
            temp = temp->next;
        }
        return true;
    }
};