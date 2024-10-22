class Solution {
public:

    int solve(vector<int>& arr ,  map<pair<int , int >, int >& maxElement , int start , int end , vector<vector<int>>&dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int ans = INT_MAX;
        for(int i = start ; i < end ; i++){
            int leftMax = maxElement[{start , i}];
            int rightMax = maxElement[{i+1 , end}];
            int NonLeafNode = leftMax * rightMax;

            ans = min(ans , NonLeafNode + solve(arr , maxElement , start , i , dp) + solve(arr , maxElement , i+1 , end , dp));
        }
        dp[start][end] = ans;
        return dp[start][end];
    }

    int mctFromLeafValues(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        vector<vector<int>>dp(arr.size() + 1 , vector<int>(arr.size() + 1 , -1));
        map<pair<int , int >, int > maxElement;
        for(int i = 0 ; i<arr.size() ; i++){
            for(int j = i ; j<arr.size() ; j++){

                if(i == j){
                    maxElement[{i,j}] = arr[i];
                }

                else{
                    maxElement[{i,j}] = max(maxElement[{i , j-1}] , arr[j]);
                }
            }
        }
        return solve(arr , maxElement , start , end , dp);
    }
};