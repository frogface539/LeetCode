class Solution {
public:
    int solve(string& word1, string& word2 , int i , int j , vector<vector<int>>& dp){
        if(i == word1.length()){
            return word2.length() - j;
        }

        if(j == word2.length()){
            return word1.length() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(word1[i] == word2[j]){
            return solve(word1 , word2 , i+1 , j+1 , dp);
        }
        else{
            //insert
            int insert = 1 + solve(word1 , word2 , i , j+1 , dp);
            //delete
            int deleteAns = 1 + solve(word1 , word2 , i+1 , j , dp);
            //replace
            int replace = 1 + solve(word1 , word2 , i+1 , j+1 , dp);

            ans = min(insert , min(deleteAns , replace));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length() , vector<int>(word2.length() , -1));
        return solve(word1, word2 , 0 , 0 , dp);
    }
};