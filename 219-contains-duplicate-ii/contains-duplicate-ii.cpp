class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> st;

        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            if (st.count(nums[j]))
                return true;

            st.insert(nums[j]);

            if (j - i >= k) {
                st.erase(nums[i]);
                i++;
            }
        }

        return false;
    }
};