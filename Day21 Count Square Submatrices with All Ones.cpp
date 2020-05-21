class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        
        int rows = matrix.size();
        int col = matrix[0].size();
        
        int dp[rows][col];
        int horizontal[rows][col];
        
        int vertical[rows][col];
        int **visited = new int*[rows];
        
        for(int i=0;i<rows;i++)
        {    visited[i] = new int[col]{};
            dp[i][col-1] = matrix[i][col-1];
            horizontal[i][col-1] = matrix[i][col-1];
        }
        for(int i=0;i<col;i++)
        {    
            dp[rows-1][i] = matrix[rows-1][i];
            vertical[rows-1][i] = matrix[rows-1][i];
        }
        for(int i=rows-1;i>=0;i--)
        {
            for(int j=col-2;j>=0;j--)
            {
                if(matrix[i][j]==1)
                {
                    horizontal[i][j] = 1+horizontal[i][j+1];
                }
                else
                {
                    horizontal[i][j]=0;
                }
            }
        }
        
        
        for(int i=col-1;i>=0;i--)
        {
            for(int j=rows-2;j>=0;j--)
            {
                if(matrix[j][i]==1)
                {
                    vertical[j][i] = 1+ vertical[j+1][i];
                }
                else
                {
                    vertical[j][i]=0;
                }
            }
        }
        
        for(int i=rows-2;i>=0;i--)
        {
            for(int j=col-2;j>=0;j--)
            {
                if(matrix[i][j])
                {
                    dp[i][j] = min(min(horizontal[i][j+1],vertical[i+1][j]),dp[i+1][j+1])+1;
                }
                else
                    dp[i][j]=0;
            }
        }
        
        int n,count=0;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                n= dp[i][j];
                count = count + n;
            }
        }
        
        return count;
        
    }
};