class Solution {
public:
    bool check(vector<int>& arr) {
        int count = 0;
        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i] < arr[i-1]){
                count++;
            }
        }
        if(arr[arr.size()-1] > arr[0]){
            count++;
        }
        return count <= 1;
    }
};