/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        // Jan 1, 2026 - Dev Reddy
        // Both lists are same size from intersecting node till tail
        // they only differ in length till there.
        // Find this difference, then skip it,
        // then start traversing both till we encounter same node in both.
        // That is the interesection
        
        Node *temp1 = head1, *temp2 = head2;
        int cnt1 = 0, cnt2 = 0;
        
        while(temp1){
            cnt1++;
            temp1=temp1->next;
        }
        
        while(temp2){
            cnt2++;
            temp2=temp2->next;
        }
        
        temp1 = head1;
        temp2 = head2;
        
        if(cnt1>cnt2){
            int diff = cnt1-cnt2;
            while(diff){
                temp1=temp1->next;
                diff--;
            }
        } else {
            int diff = cnt2-cnt1;
            while(diff){
                temp2=temp2->next;
                diff--;
            }
        }
        
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        return temp1;
        
    }
};