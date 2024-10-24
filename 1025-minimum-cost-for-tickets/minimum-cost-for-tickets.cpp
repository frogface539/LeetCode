class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs , int index , vector<int>& dp){
        if(index >= days.size()){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        //1 day price
        int oneDayPass = costs[0] + solve(days , costs , index + 1 , dp);

        //7 day price + end date
        int passEndDay = days[index] + 7 - 1;
        int j = index;

        //pass end date take iterate karega j
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }

        int sevenDayPass = costs[1] + solve(days , costs , j , dp);

        //30 day price + end date
        passEndDay = days[index] + 30 - 1;
        j = index;

        //pass end date take iterate karega j
        while(j < days.size() && days[j] <= passEndDay){
            j++;
        }

        int thirtyDayPass = costs[2] + solve(days , costs , j , dp);

        dp[index] = min(oneDayPass , min(sevenDayPass , thirtyDayPass));
        return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int index = 0;
        vector<int>dp(days.size()+1 , -1);
        return solve(days , costs , 0 , dp);
    }
};