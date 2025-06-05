class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e-s)/2;
        int ans = arr[s];

        while(s <= e){
            if(arr[mid] <= target){
                s = mid + 1;
            }

            else if(arr[mid] > target){
                ans = arr[mid];
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};