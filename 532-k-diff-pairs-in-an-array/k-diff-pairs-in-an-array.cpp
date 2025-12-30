class Solution {
public:
    int findPairs(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        set<pair<int,int>>ans;
        int i=0;
        int j=1;
        while(j<arr.size()){
            int diff = arr[j] - arr[i];
            if(diff == k){
                ans.insert({arr[i],arr[j]});
                i++;
                j++;
            }
            else if(diff > k){
                i++;
            }
            else{
                j++;
            }
            if(i==j){
                j++;
            }
        }
        return ans.size();
    }
};