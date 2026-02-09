class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        if(arr.size() <= 2){
            return arr.size();
        }

        int j=2;
        for(int i=2 ; i<arr.size() ; i++){
            if(arr[i] != arr[j-2]){
                arr[j] = arr[i];
                j++;
            }
        }
        return j;
    }
};