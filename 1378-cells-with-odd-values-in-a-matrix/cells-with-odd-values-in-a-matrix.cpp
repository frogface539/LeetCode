class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) 
    {
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < indices.size(); i++)
        {
            row[indices[i][0]]++;
            col[indices[i][1]]++;     
        }

        int oddRow = 0;
        int oddCol = 0;
        for(int i = 0; i < m; i++)
            if(row[i]%2 == 1)
                oddRow++;
                
        for(int i = 0; i < n; i++)
            if(col[i]%2 == 1)
                oddCol++;
            
        int evenRow = m - oddRow;
        int evenCol = n - oddCol;

        return oddRow*evenCol + oddCol*evenRow;
    }
};