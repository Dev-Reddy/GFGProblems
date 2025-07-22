class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        int i = 0;

        while (i < n) {
            int correctIndex = arr[i] - 1;
            if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[correctIndex]) {
                swap(arr[i], arr[correctIndex]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};