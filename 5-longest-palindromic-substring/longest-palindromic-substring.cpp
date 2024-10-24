class Solution {
public:
    int start = 0;
    int maxLen = 1;

    bool solve(string& s , int i , int j , vector<vector<bool>>& dp){
        if(i >= j){
            return true;
        }

        if(dp[i][j] != false){
            return dp[i][j];
        }

        bool flag = false;
        if(s[i] == s[j]){
            flag = solve(s , i+1 , j-1 , dp);
        }

        if(flag == true){
            int len = j-i+1;
            if(len > maxLen){
                maxLen = len;
                start = i;
            }
        }
        dp[i][j] = flag;
        return dp[i][j];
    }

    string longestPalindrome(string s) {

        vector<vector<bool>>dp(s.size()+1 , vector<bool>(s.size()+1 , false));
         for(int i = 0 ; i<s.size() ; i++){
            for(int j=i ; j<s.size() ; j++){
                //substring check karna hai
                bool ans = solve(s , i , j , dp);
            }
        }
        return s.substr(start , maxLen);
    }
};