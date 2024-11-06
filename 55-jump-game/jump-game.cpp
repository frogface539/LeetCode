class Solution {
public:
    bool canJump(vector<int>& nums) {
        int finalPos = nums.size() - 1;
        for(int i = nums.size()-2 ; i>=0 ; i--){
            if(i + nums[i] >=finalPos){
                finalPos = i;
            }
        }
        return finalPos==0;
    }
};