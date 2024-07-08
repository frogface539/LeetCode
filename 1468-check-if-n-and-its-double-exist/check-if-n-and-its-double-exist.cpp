class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        for(int i = 0 ; i<arr.size() ; i++){
            int start = 0;
            int end = arr.size() - 1;
            int mid = (start + end)/2;
            int target = 2 * arr[i];
            while(start <= end){
                int mid = (start + end)/2;
                if(arr[mid] == target && i != mid){
                    return true;
                }

                else if(arr[mid] > target){
                    end = mid - 1;
                }

                else{
                    start = mid + 1;
                }
            }
        }
        return false;
    }
};