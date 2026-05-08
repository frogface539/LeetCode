class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        int start = 0;
        int ans = 0;

        vector<int>dp(n);
        for(int i=0 ; i<n ; i++){
            while(prizePositions[i] - prizePositions[start]>k){
                start++;
            }
            ans = max(ans, i - start + 1 + (start > 0 ? dp[start - 1] : 0));
            dp[i] = max((i > 0 ? dp[i - 1] : 0), i - start + 1);
        }
        return ans;
    }
};