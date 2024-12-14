class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int start = 0 ;
        int end = arr.size()-1;

        while(start <= end){
            int mid = (start+end)/2;
            if(arr[mid] == target){
                return mid;
            }

            else if(arr[mid] > target){
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }
        return start;
    }
};