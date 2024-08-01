//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int left = 0, right = m-1, top = 0, bottom = n-1;
        vector<int> ans;

        while(top<=bottom && left <=right){

            // left to right
            //no need to check condition for top and bottom
            // as it was just checked above

            for(int i = left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;

            // top to bottom
            //no need to check condition for left and right
            // as it was just checked above and since has not been changed
            // and top and bottom will be checked in the loop

            for(int i = top;i<=bottom;i++){
                ans.push_back(mat[i][right]);
            }
            right--;

            // right to left
            //need to check condition for top and bottom condition
            // as it was just changed above and  has not been checked since
            // and left and right will be checked in the loop

            if(top<=bottom){
                for(int i = right;i>=left;i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            // bottom to top
            //need to check condition for left and right condition
            // as it was just changed above and  has not been checked since
            // and top and bottom will be checked in the loop

            if(left<=right){
                for(int i = bottom;i>=top;i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        } 

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends