class Solution {
public:
    int getPivotIndex(vector<int>& arr){
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e-s)/2;
        while(s<=e){
            mid = s+(e-s)/2;
            if(s==e){
                return s; //single element array
            }

            else if(mid < e && arr[mid] > arr[mid+1]){
                return mid;
            }

            else if(mid > s && arr[mid-1] > arr[mid]){
                return mid - 1;
            }

            else if(arr[s] > arr[mid]){
                e = mid - 1;
            }

            else{
                s = mid + 1;
            }
        }
        return -1;
    }

    int BinarySearch(int start , int end , vector<int>& arr , int element){
        int mid = (start + end) /2;

        while(start <= end){
            mid = (start + end) /2;
            if(arr[mid] == element){
                return mid;
            }

            else if(arr[mid] > element){
                end = mid - 1;
            }

            else if(arr[mid] < element){
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& arr, int target) {
       int pivotIndex = getPivotIndex(arr);
       int ans = -1;

       //line A
       if(target >= arr[0] && target <= arr[pivotIndex]){
        int ans = BinarySearch(0, pivotIndex, arr, target);
        return ans;
        }

       //line B
       else{
        int ans = BinarySearch(pivotIndex + 1, arr.size()-1, arr, target);
        return ans;
       }
       return -1;
    }
};