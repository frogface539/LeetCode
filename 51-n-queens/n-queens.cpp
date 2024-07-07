class Solution {
    char q, x;
    int n;
    vector<vector<string>> ans;
    vector<string> board;
    string temp, row;
    vector<int> row_visited,
                col_visited,
                dig_visited1,
                dig_visited2;
    bool safe(int r, int c){
        return !(
                    row_visited[r] ||
                    col_visited[c] ||
                    dig_visited1[n - 1 + r - c] ||
                    dig_visited2[r + c]
                );
    }
    void update(int r, int c, int value){
        if(value)
            row[c] = q,
            board.push_back(row);
        else
            row[c] = x,
            board.pop_back();
        row_visited[r] = value,
        col_visited[c] = value,
        dig_visited1[n - 1 + r - c] = value,
        dig_visited2[r + c] = value;
    }
    void rec(int r){
        if(r == n)
            ans.push_back(board);
        row = temp;
        for(int c = 0; c < n; c++)
            if(safe(r, c))
                update(r, c, 1),
                rec(r + 1),
                update(r, c, 0);
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        q = 'Q', x = '.';
        this->n = n;
        row_visited.resize(n + 1, 0),
        col_visited.resize(n + 1, 0),
        dig_visited1.resize(2*n + 1, 0),
        dig_visited2.resize(2*n + 1, 0);
        for(int i = 0; i < n; i++)
            temp.push_back(x);
        rec(0);
        return ans;
    }
};