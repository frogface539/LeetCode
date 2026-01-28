class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& output, vector<vector<int>>& result){
        if(index == nums.size()){
            result.push_back(output);
            return;
        }

        output.push_back(nums[index]);
        solve(nums,index+1,output,result);
        output.pop_back();
        solve(nums,index+1,output,result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>result;
        solve(nums,0,output,result);
        return result;
    }
};