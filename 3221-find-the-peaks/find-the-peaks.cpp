class Solution {
public:
    vector<int> findPeaks(vector<int>& arr) {
        vector<int>ans;

        for(int i=1 ; i<arr.size() - 1; i++){
            if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])){
                ans.push_back(i);
            }
        }
        return ans;
    }
};