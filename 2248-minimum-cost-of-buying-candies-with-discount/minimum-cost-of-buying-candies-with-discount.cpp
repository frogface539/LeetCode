class Solution {
public:
    int minimumCost(vector<int>& arr) {
        sort(arr.begin(),arr.end(),greater<int>());
        int total = 0;
        for(int i=0 ; i<arr.size() ; i++){
            if(i%3 != 2){
                total = total+arr[i];
            }
        }
        return total;
    }
};