class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>res(2050-1950+1, 0);

        for(vector<int>&log: logs) {
            int l = log[0]-1950;
            int r = log[1]-1950;
            res[l] += 1;
            res[r] += -1;
        }
        int curr = 0;
        int mx = -1;
        int ans = 0;
        for(int i = 0; i<=2050-1950; ++i) {
            curr+=res[i];
            if(curr > mx) {
                mx = curr;
                ans = i+1950;
            }
        }
        return ans;

    }
};