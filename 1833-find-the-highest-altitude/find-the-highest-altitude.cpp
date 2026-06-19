class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> runningSum;
        runningSum.push_back(0);

        int curr = 0;

        for(int x : gain){
            curr += x;
            runningSum.push_back(curr);
        }

        return *max_element(runningSum.begin(), runningSum.end());
    }
};