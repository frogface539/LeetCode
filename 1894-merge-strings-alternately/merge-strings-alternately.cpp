class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output = "";
        int maxLength = max(word1.length(), word2.length());
        for (int i = 0; i < maxLength; i++) {
            if (i < word1.length()) {
                output.push_back(word1[i]);
            }
            if (i < word2.length()) {
                output.push_back(word2[i]);
            }
        }
        return output;
    }
};