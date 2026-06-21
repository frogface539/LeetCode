class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int count = 0;

        for (auto k : moves) {
            if (k == 'L') x--;
            else if (k == 'R') x++;
            else if (k == 'U') y++;
            else if (k == 'D') y--;
            else count++;
        }

        return abs(x) + abs(y) + count;
    }
};