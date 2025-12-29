class Solution {
public:
    int findPivotIndex(vector<int>& arr){
        int n = arr.size();
        int s = 0;
        int e = n - 1;

        while(s <= e){
            int mid = (s + e) / 2;

            if(mid < e && arr[mid] > arr[mid + 1]){
                return mid;
            }

            if(mid > s && arr[mid] < arr[mid - 1]){
                return mid - 1;
            }

            if(arr[s] > arr[mid]){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
    }

    int BS(int start , int end , vector<int>& arr , int element){
        int mid = (start + end) / 2;

        while(start <= end){
            mid = (start + end) / 2;
            if(arr[mid] == element){
                return mid;
            }
            else if(arr[mid] > element){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int>& arr, int target) {
        int pivot = findPivotIndex(arr);

        if(pivot == -1){
            return BS(0, arr.size() - 1, arr, target);
        }

        if(target >= arr[0] && target <= arr[pivot]){
            return BS(0, pivot, arr, target);
        }
        else{
            return BS(pivot + 1, arr.size() - 1, arr, target);
        }
    }
};
