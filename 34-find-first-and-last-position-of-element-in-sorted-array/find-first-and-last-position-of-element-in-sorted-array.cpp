class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int>ans(2,-1);
        int start = 0;
        int end = arr.size() - 1;

        //first occ
        while(start <= end){
            int mid = (start+end)/2;
            if(arr[mid]==target){
                ans[0] = mid;
                end = mid - 1;
            }

            else if(arr[mid] > target){
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }

        start = 0;
        end = arr.size() - 1;
        //last occ
        while(start <= end){
            int mid = (start+end)/2;
            if(arr[mid]==target){
                ans[1] = mid;
                start = mid + 1;
            }

            else if(arr[mid] > target){
                end = mid - 1;
            }

            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};