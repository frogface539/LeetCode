class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0;
        int right = 0;
        int blanks = 0;
        for(auto&i:moves){
            if(i == 'L'){
                left++;
            }
            if(i == 'R'){
                right++;
            }
            if(i == '_'){
                blanks++;
            }
        }
        return abs(left-right)+blanks;
    }
};