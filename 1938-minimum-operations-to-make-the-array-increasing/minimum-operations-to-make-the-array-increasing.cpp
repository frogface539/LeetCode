class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= prev) {
                int required = prev + 1;
                operations += (required - nums[i]);
                prev = required;
            } else {
                prev = nums[i];
            }
        }

        return operations;
    }
};