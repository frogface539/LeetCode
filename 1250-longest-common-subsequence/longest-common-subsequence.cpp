class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1 , vector<int>(n+1 , 0));

        for(int i = m -1 ; i>=0 ; i--){
            for(int j = n -1 ; j>=0 ; j--){

                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + dp[i+1][j+1];
                }

                else{
                    ans = 0 + max(dp[i+1][j] , dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};