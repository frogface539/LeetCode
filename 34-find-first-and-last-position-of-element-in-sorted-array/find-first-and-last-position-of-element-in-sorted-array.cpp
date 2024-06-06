class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1); // Initialize the result vector with -1s

        // Find the first occurrence
        int s = 0;
        int e = nums.size() - 1; // Corrected the end boundary to size() - 1

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans[0] = mid;
                e = mid - 1; // Continue to search in the left half
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // Reset the search boundaries
        s = 0;
        e = nums.size() - 1;

        // Find the last occurrence
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                s = mid + 1; // Continue to search in the right half
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};
