class Solution {
public:
    int repeatedNTimes(vector<int>& arr) {
        for(int i=0 ; i<arr.size()-1 ; i++){
            for(int j=i+1; j<arr.size() ; j++){
                if(arr[i] == arr[j]){
                    return arr[i];
                }
            }
        }
        return -1;
    }
};