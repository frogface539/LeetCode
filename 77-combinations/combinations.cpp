class Solution {
public:
    void solve(int n, int k, int start, vector<vector<int>>& ans, vector<int> output){
        if(output.size() == k){
            ans.push_back(output);
            return;
        }

        for(int i=start ; i<=n ; i++){
            output.push_back(i);
            solve(n,k,i+1,ans,output);
            output.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(n,k,1,ans,output);
        return ans;
    }
};