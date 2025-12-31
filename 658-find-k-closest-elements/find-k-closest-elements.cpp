class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>diff_arr;
        vector<int>ans;

        for(int i=0 ; i<arr.size() ; i++){
            int diff = abs(x-arr[i]);
            diff_arr.push_back({diff,arr[i]});
        }

        sort(diff_arr.begin() , diff_arr.end());

        for(int i=0 ; i<k ; i++){
            ans.push_back(diff_arr[i].second);
        }

        sort(ans.begin() , ans.end());
        return ans;
    }
};