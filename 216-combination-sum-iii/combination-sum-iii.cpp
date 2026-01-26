class Solution {
public:
    void solve(int index, int target, int k, vector<int>& output, vector<vector<int>>& ans){
        if(output.size() == k){
            if(target == 0){
                ans.push_back(output);
                return;
            }
        }

        for(int i=index ; i<=9 ; i++){
            if(i>target){
                break;
            }
            output.push_back(i);
            solve(i+1, target-i, k, output, ans);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>output;
        vector<vector<int>>ans;

        solve(1,n,k,output,ans);
        return ans;
    }
};