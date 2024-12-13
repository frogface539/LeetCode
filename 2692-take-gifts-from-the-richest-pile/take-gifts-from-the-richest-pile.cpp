class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long count = 0;
        for(int i = 0 ; i<k ; i++){
            sort(gifts.begin() , gifts.end());
            gifts[gifts.size()-1] = sqrt(gifts[gifts.size()-1]);
        }

        for(int i = 0 ; i<gifts.size() ; i++){
            count = count + gifts[i];
        }
        return count;
    }
};