class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0 ; i<nums.size() ; i++){
            int index = abs(nums[i]);
            if(nums[index] < 0){
                return index;
            }
            nums[index] *= -1;
        }
        return -1;
    }
};






//   for(int i=0 ; i<nums.size()-1 ; i++){
//     for(int j=i+1 ; j<nums.size() ; j++){
//         if(nums[i] == nums[j]){
//             return nums[i];
//         }
//     }
// }
// return -1;