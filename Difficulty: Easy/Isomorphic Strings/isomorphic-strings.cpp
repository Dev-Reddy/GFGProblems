class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
         if (s1.length() != s2.length())
            return false;

        vector<int> m1(256, -1), m2(256, -1);

        for (int i = 0; i < s1.length(); i++) {
            char c1 = s1[i], c2 = s2[i];

            if (m1[c1] == -1 && m2[c2] == -1) {
                m1[c1] = c2;
                m2[c2] = c1;
            }
            else if (m1[c1] != c2 || m2[c2] != c1) {
                return false;
            }
        }

        return true;
    }
};