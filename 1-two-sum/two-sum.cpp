class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        // Iterate through each element in the array
        for (int i = 0; i < nums.size(); i++) {
            // Iterate through the remaining elements starting from the next index
            for (int j = i + 1; j < nums.size(); j++) {
                // Check if the sum of the current elements equals the target
                if (nums[i] + nums[j] == target) {
                    // If found, add the indices to the answer vector
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans; // Return the solution early
                }
            }
        }

        // If no solution is found, return an empty vector
        return ans;
    }
};