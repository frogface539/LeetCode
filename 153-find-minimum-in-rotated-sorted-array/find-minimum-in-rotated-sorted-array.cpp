class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if(arr[0] < arr[n-1]){
            return arr[0];
        }

        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[0] <= arr[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return arr[start % n];
    }
};