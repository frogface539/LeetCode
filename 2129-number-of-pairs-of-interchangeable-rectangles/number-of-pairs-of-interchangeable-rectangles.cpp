class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,long long>mp;
        long long ans = 0;

        for(auto&r : rectangles){
            double ratio = (double)r[0]/r[1];
            ans += mp[ratio];
            mp[ratio]++;
        }
        return ans;
    }
};