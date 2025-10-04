#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findExpr(string num, int target) {
        results.clear();
        seen.clear();
        if (num.empty()) return {};
        dfs(num, target, 0, 0LL, 0LL, "");
        // deterministic order: sort the results
        vector<string> out(results.begin(), results.end());
        sort(out.begin(), out.end());
        return out;
    }

private:
    unordered_set<string> results; // store unique expressions
    unordered_set<string> seen;    // not strictly necessary, kept for clarity

    // pos: current index in num
    // curVal: current evaluated value of expression built so far
    // prev: the last operand (signed) used to handle multiplication
    // expr: expression string built so far
    void dfs(const string &num, int target, int pos, long long curVal, long long prev, const string &expr) {
        int n = num.size();
        if (pos == n) {
            if (curVal == target) results.insert(expr);
            return;
        }

        for (int i = pos; i < n; ++i) {
            // leading zero check: if number has more than 1 digit and starts with '0', break
            if (i > pos && num[pos] == '0') break;

            string curStr = num.substr(pos, i - pos + 1);
            long long curNum = stoll(curStr);

            if (pos == 0) {
                // first number, it becomes the start of expression
                dfs(num, target, i + 1, curNum, curNum, curStr);
            } else {
                // plus
                dfs(num, target, i + 1, curVal + curNum, curNum, expr + "+" + curStr);
                // minus
                dfs(num, target, i + 1, curVal - curNum, -curNum, expr + "-" + curStr);
                // multiply: remove prev then add prev * curNum
                dfs(num, target, i + 1, curVal - prev + prev * curNum, prev * curNum, expr + "*" + curStr);
            }
        }
    }
};

