class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int freq[26] = {0};

        int maxLen = 0;
        int maxFreq = 0;
        int left = 0, right = 0;

        while (right < n) {
            char ch = s[right];

            freq[ch - 'A']++;
            maxFreq = max(maxFreq, freq[ch - 'A']);

            if ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};