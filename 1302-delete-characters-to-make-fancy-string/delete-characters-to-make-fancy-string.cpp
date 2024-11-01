class Solution {
public:
    string makeFancyString(string s) {
        string output = "";
        for (int i = 0; i < s.length(); i++) {
            if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2]) {
                continue;
            }
            output += s[i];
        }
        return output;
    }
};
