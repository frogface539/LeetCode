class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = 0;
        int bobSum = 0;

        int m = aliceSizes.size();
        int n = bobSizes.size();

        vector<int>ans;
        //Sum calculate kiya hai alice and bob ki candies ka 
        //accumulate function ka bhi use kar sakte hai vo tum log khud karna
        for(int i=0 ; i<m ; i++){
            aliceSum = aliceSum + aliceSizes[i];
        }

        for(int i=0 ; i<n ; i++){
            bobSum = bobSum + bobSizes[i];
        }

        //equal exchange ka logic calculate kiya gaya hai yaha par
        //aur final answer array me jo return karna hai vo push kiya hai
        for(int i = m-1 ; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
                int diff = aliceSizes[i] - bobSizes[j];
                if(aliceSum - diff == diff + bobSum){
                    ans.push_back(aliceSizes[i]);
                    ans.push_back(bobSizes[j]);
                    return ans;
                }
            }
        }
        return ans;
    }
};