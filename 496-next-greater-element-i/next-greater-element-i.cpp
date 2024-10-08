class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        stack<int> stack;

        for (int num : nums2) {
            while (!stack.empty() && stack.top() < num) {
                int prev = stack.top();
                stack.pop();
                if (find(nums1.begin(), nums1.end(), prev) != nums1.end()) {
                    ans[find(nums1.begin(), nums1.end(), prev) - nums1.begin()] = num;
                }
            }
            stack.push(num);
        }

        return ans;
    }
};