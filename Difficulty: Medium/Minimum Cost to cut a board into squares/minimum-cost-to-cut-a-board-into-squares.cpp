class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
          int horizontalStrips = 1;
        int verticalStrips = 1;
        int cost = 0;
        // size of x is m-1
        // size of y is n-1
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int l = m - 1 - 1;
        int r = n - 1 - 1;
        while (l >= 0 && r >= 0) {
            if (x[l] >= y[r]) {
                cost += x[l] * horizontalStrips;
                verticalStrips++;
                l--;
            } else {
                cost += y[r] * verticalStrips;
                horizontalStrips++;
                r--;
            }
        }
        while (l >= 0) {
            cost += x[l] * horizontalStrips;
            verticalStrips++;
            l--;
        }

        while (r >= 0) {
            cost += y[r] * verticalStrips;
            horizontalStrips++;
            r--;
        }
        return cost;
    }
};
