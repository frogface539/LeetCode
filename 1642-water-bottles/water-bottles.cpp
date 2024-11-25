class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0;
        int emptyBottle = 0;

        while(numBottles > 0){
            res = res + numBottles;
            emptyBottle = emptyBottle + numBottles;
            numBottles = emptyBottle / numExchange;
            emptyBottle = emptyBottle % numExchange;
        }
        return res;
    }
};