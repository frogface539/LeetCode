class Solution {
public:
    int trap(vector<int>& height) {
        
        //array me left max and right max nikalne ke liye calculation
        vector<int>leftMax(height.size());
        vector<int>rightMax(height.size());

        leftMax[0] = height[0];
        for(int i=1 ; i<height.size() ; i++){
            leftMax[i] = max(leftMax[i-1] , height[i]);
        }

        rightMax[height.size()-1] = height[height.size()-1];
        for(int i=height.size() - 2; i>=0 ; i--){
            rightMax[i] = max(rightMax[i+1] , height[i]);
        }

        // trapped water ki height nikaal ne ke liye calculation 
        // isme leftmax aur right max ka minimum nikaala jisse minumum water stores nikle and array[i] se         subtract kardiya 

        // do dry run it !!

        int sum = 0;
        for(int i=0 ; i<height.size() ; i++){
            int hw = min(leftMax[i] , rightMax[i]) - height[i];
            sum = sum + hw;
        }
        return sum;











        // //without using extra space 
        
        // int left = 0;
        // int right = height.size()-1;
        // int rightMax = 0;
        // int leftMax = 0;
        // int sum = 0;

        // while(left <= right){
        //     if(height[right] >= height[left]){
        //         if(leftMax <= height[left]){
        //             leftMax = height[left];
        //         }
        //         else{
        //             sum = sum + leftMax - height[left];
        //         }
        //         left++;
        //     }
            
        //     else{
        //         if(rightMax <= height[right]){
        //             rightMax = height[right];
        //         }
        //         else{
        //             sum = sum + rightMax - height[right];
        //         }
        //         right--;
        //     }
        // }
        // return sum;
    }
};