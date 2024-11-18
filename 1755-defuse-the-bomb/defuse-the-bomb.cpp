class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code.size(), 0);
        if (k == 0) {
            return ans;
        }

        else if (k > 0) {
            for (int i = 0; i < code.size(); i++) {
                for (int j = 1; j <= k; j++) {
                    ans[i] = ans[i] + (code[(i + j) % code.size()]);
                }
            }
        }

        else {
            for (int i = 0; i < code.size(); i++) {
                for (int j = 1; j <= abs(k); j++) {
                    int index = (i - j + code.size()) % code.size();
                    ans[i] = ans[i]+ code[index];
                }
            }
        }
        return ans;
    }
};