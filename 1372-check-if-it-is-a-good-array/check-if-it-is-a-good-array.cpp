class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        for (int a: nums)
            res = gcd(res, a);
        return res == 1;
    }
};