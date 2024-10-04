class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int>map;
        
        for(int i = 0 ; i<nums.size() ; i++){
            int reqElement = target - nums[i];
            if(map.find(reqElement) != map.end()){
                return{i , map[reqElement]};
            }
            map[nums[i]] = i;
        }
        return {-1 , -1};
    }
};