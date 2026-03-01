class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> bitCount(32, 0);
        
        int currentOR = 0;
        int ans = INT_MAX;

        for (int num : nums) {
            
            // Expand window
            dq.push_back(num);
            
            for (int b = 0; b < 32; b++) {
                if (num & (1 << b)) {
                    bitCount[b]++;
                    currentOR |= (1 << b);
                }
            }

            while (!dq.empty() && currentOR >= k) {
                ans = min(ans, (int)dq.size());

                int front = dq.front();
                dq.pop_front();

                for (int b = 0; b < 32; b++) {
                    if (front & (1 << b)) {
                        bitCount[b]--;
                        if (bitCount[b] == 0) {
                            currentOR &= ~(1 << b);
                        }
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};