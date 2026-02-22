class Solution {
public:
    int countHomogenous(string s) {
        long long count = 0;
        long long total = 0;
        long long mod = 1e9 + 7;

        char prev = s[0];

        for (char ch : s) {
            if (ch == prev) {
                count++;              
            } else {
                count = 1;           
                prev = ch;            
            }
            total = (total + count) % mod;
        }

        return total;
    }
};