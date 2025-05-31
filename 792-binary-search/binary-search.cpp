class Solution {
public:
    int search(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = (s+e)/2;

        while(s <= e){
            mid = (s+e)/2;
            if(arr[mid] == target){
                return mid;
            }

            else if(arr[mid] < target){
                s = mid + 1;
            }

            else if(arr[mid] > target){
                e = mid - 1;
            }
        }
        return -1;
    }
};