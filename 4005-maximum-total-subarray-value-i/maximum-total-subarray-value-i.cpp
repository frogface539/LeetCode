class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int a = INT_MIN;
        int b = INT_MAX;

        for(int i=0 ; i<nums.size() ; i++){
            a = max(a,nums[i]);
            b = min(b,nums[i]);
        }
        return (long long)abs((b-a))*k;
    }
};