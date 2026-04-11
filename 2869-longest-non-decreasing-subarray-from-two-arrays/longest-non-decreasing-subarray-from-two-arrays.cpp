class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int dp1 = 1, dp2 = 1;
        int ans = 1;

        for(int i = 1; i < n; i++){
            int newDp1 = 1, newDp2 = 1;

            if(nums1[i] >= nums1[i-1])
                newDp1 = max(newDp1, dp1 + 1);

            if(nums1[i] >= nums2[i-1])
                newDp1 = max(newDp1, dp2 + 1);

            if(nums2[i] >= nums1[i-1])
                newDp2 = max(newDp2, dp1 + 1);

            if(nums2[i] >= nums2[i-1])
                newDp2 = max(newDp2, dp2 + 1);

            dp1 = newDp1;
            dp2 = newDp2;

            ans = max(ans, max(dp1, dp2));
        }

        return ans;
    }
};