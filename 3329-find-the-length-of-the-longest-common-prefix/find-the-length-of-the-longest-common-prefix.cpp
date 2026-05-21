class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for (int x : arr1) {

            string s = to_string(x);
            string pref = "";

            for (char c : s) {
                pref += c;
                st.insert(pref);
            }
        }

        int ans = 0;

        for (int x : arr2) {

            string s = to_string(x);
            string pref = "";

            for (int i = 0; i < s.size(); i++) {

                pref += s[i];

                if (st.count(pref)) {
                    ans = max(ans, i + 1);
                }
            }
        }

        return ans;
    }
};