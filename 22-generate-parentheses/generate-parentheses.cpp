class Solution {
public:
    bool isValid(string& output){
        int count = 0;

        for(auto& ch:output){
            if(ch == '('){
                count++;
            }
            else{
                count--;
            }
            if(count<0){
                return false;
            }
        }
        return count==0;
    }

    void solve(int n, vector<string>& ans, string& output){
        if(output.size() == 2*n){
            if(isValid(output)){
                ans.push_back(output);
            }
            return;
        }

        output.push_back('(');
        solve(n,ans,output);
        output.pop_back();

        output.push_back(')');
        solve(n,ans,output);
        output.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output;
        solve(n,ans,output);
        return ans;
    }
};