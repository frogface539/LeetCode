class Solution {
public:
    void merge(vector<int>&nums , vector<int>&temp , int start , int mid , int end){
        int i = start;
        int j = mid + 1;
        int k = start;

        while(i <= mid && j <= end){
            if(nums[i] <= nums[j]){
                temp[k] = nums[i];
                k++;
                i++;
            }

            else{
                temp[k] = nums[j];
                k++;
                j++;
            }
        }

        while(i <= mid){
            temp[k] = nums[i];
            k++;
            i++;
        }

        while(j <= end){
            temp[k] = nums[j];
            k++;
            j++;
        }

        while(start <= end){
            nums[start] = temp[start];
            start++;
        }
    }

    void mergeSort(vector<int>&nums , vector<int>&temp , int start , int end){
        if(start >=end){
            return;
        }
        int mid = (start + end)/2;
        mergeSort(nums , temp , start , mid);
        mergeSort(nums , temp , mid + 1 , end);
        merge(nums , temp , start , mid , end);
    }


    vector<int> sortArray(vector<int>& nums) {
        vector<int>temp(nums.size() , 0);
        mergeSort(nums , temp , 0 , nums.size()-1);
        return nums;
    }
};