class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;

        //maximum number of candies calculate karne ke liye poori candies array me
        int maxi = candies[0];
        for(int i=0 ; i<candies.size() ; i++){
            if(maxi < candies[i]){
                maxi = candies[i];
            }
        }

        //agar candies at i ka sum + extra candies bada hua maximum candy se to push true else false
        for(int i=0 ; i<candies.size() ; i++){
            if(candies[i] + extraCandies >=maxi){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};