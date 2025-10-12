/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  int totalMoves = 0; // min number of moves required : Ensuring min becoz we are
    // able to fullfill the demand of childrens from the direct parent only, making the 
    // flow very simple
    
    
    int solve(Node* node) {
        
        if(node == nullptr) {
            return 0;
        }
            
        int left = solve(node -> left);
        int right = solve(node -> right);
        
        int totalVal = left + right + node -> data; // total value at parent node 
        int moves = totalVal - 1; // it can make moves for all values, except 1 value for itself
        
        totalMoves += abs(moves); // move can be in either directions
        
        return moves;
        
    }
  public:
    int distCandy(Node* root) {
        // code here
        solve(root);
        
        return totalMoves;
    }
};