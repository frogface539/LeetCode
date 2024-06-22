class Solution {
public:
    int solve(vector<int>& coins, int amount,unordered_map<int,int>&memo){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        if(memo.find(amount)!=memo.end()) return memo[amount];
        int m = INT_MAX;
        for(auto i: coins){
            int res = solve(coins,amount-i,memo);
            if(res!=INT_MAX){
                m = min(m,res+1);
            }
        }
        memo[amount]=m;
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int>memo;
        return solve(coins,amount,memo)==INT_MAX ? -1 : solve(coins,amount,memo);
    }
};