class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        long long ans=0;
        
        for(int i=0 ; i<arr.size() ; i++){
            int mini = arr[i];
            int maxi = arr[i];

            for(int j=i ; j<arr.size() ; j++){
                mini = min(mini,arr[j]);
                maxi = max(maxi,arr[j]);
                ans = ans + maxi-mini;
            }
        }
        return ans;
    }
};