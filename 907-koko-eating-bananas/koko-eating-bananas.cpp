class Solution {
public:
    bool canEatBanana(vector<int>& piles, int mid, int h){
        int hours = 0;
        for(int& i : piles){
            hours = hours + (i/mid);

            if(i%mid != 0){
                hours++;
            }
        }
        return hours<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(begin(piles), end(piles));

        while(s<e){
            int mid = (s+e)/2;
            if(canEatBanana(piles,mid,h)){
                e=mid;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};