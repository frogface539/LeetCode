class Solution {
public:
    int solve(int n, int currA, int clipA){
        if(currA == n){
            return 0;
        }

        if(currA > n){
            return 1e9;
        }

        int copyPasteAll = 1 + 1 + solve(n,currA+currA,currA);
        int paste = 1+ solve(n,currA+clipA, clipA);

        return min(copyPasteAll,paste);
    }

    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        return 1+solve(n,1,1);
    }
};