class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& output, vector<vector<int>>& result){
        result.push_back(output);

        for(int i=index ; i<nums.size() ; i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            output.push_back(nums[i]);
            solve(nums,i+1,output,result);
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int>output;
        vector<vector<int>>result;
        solve(nums,0,output,result);
        return result;
    }
};
