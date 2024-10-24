class Solution {
public:
    bool check(string& word , vector<string>& wordDict){
        for(auto i:wordDict){
            if(word == i){
                return true;
            }
        }
        return false;
    }

    bool solve(string& s, vector<string>& wordDict , int i , vector<int>& dp){
        if(i == s.size()){
            return true;
        }

        string word = "";
        bool flag = false;

        if(dp[i] != -1){
            return dp[i];
        }

        for(int j=i ; j<s.size() ; j++){
            word = word + s[j];
            if(check(word , wordDict) == true){
                flag = flag || solve(s , wordDict , j+1 , dp);
            }
        }
        dp[i] = flag;
        return dp[i];
    }

    bool wordBreak(string& s, vector<string>& wordDict) {
        vector<int>dp(s.size() , -1);
        return solve(s , wordDict , 0 , dp);
    }
};