class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starIndex = -1, matchIndex = -1;

        while (i < s.length()) {
            if (j < p.length() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            else if (j < p.length() && p[j] == '*') {
                starIndex = j;
                matchIndex = i;
                j++;
            }
            else if (starIndex != -1) {
                j = starIndex + 1;
                matchIndex++;
                i = matchIndex;
            }
            else {
                return false;
            }
        }

        while (j < p.length() && p[j] == '*') {
            j++;
        }

        return j == p.length();
    }
};