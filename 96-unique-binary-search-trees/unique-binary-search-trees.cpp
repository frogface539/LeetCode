class Solution {
public:
    int solve(int s, int e){
        if(s >= e){
            return 1;
        }

        int count = 0;

        for(int i = s; i <= e; i++){
            int left = solve(s, i - 1);
            int right = solve(i + 1, e);

            count += left * right;
        }

        return count;
    }

    int numTrees(int n) {
        return solve(1, n);
    }
};