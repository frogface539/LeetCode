class Solution {
public:
    bool check(vector<int>& arr) {
        int count = 0;
        //[3,4,5,1,2]
        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i-1] > arr[i]){ //[5,1]
                count++;
            }
        }
        if(arr[arr.size()-1] > arr[0]){ //[3,2]
            count++;
        }
        return count<=1;
    }
};