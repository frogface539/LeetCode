class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    std::vector<int> max_in_windows;
    std::deque<int> dq; // Store indices of potential maximum elements
    
    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices that are out of the current window
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove elements from the back of the deque while they are less than or equal to the current element
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        
        // Add the current element's index to the deque
        dq.push_back(i);
        
        // The maximum value for the current window is at the front of the deque
        if (i >= k - 1) {
            max_in_windows.push_back(nums[dq.front()]);
        }
    }
    
    return max_in_windows;
}
};