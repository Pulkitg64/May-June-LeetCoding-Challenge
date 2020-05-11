void find(vector<vector<int>>& image,int **arr,int x,int row,int col, int sr, int sc, int newColor)
{
    
    
    if(sr>= row || sr<0 || sc >=col || sc<0)
        return;
    
  
    if(image[sr][sc]==x && arr[sr][sc]==0)
    {
        image[sr][sc]=newColor;
        arr[sr][sc] = 1;
        find(image,arr,x,row,col,sr+1,sc,newColor);
        find(image,arr,x,row,col,sr-1,sc,newColor);
        find(image,arr,x,row,col,sr,sc+1,newColor);
        find(image,arr,x,row,col,sr,sc-1,newColor);

      
    }
    
    return;
    
    
}     
     
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int row = image.size();
        int col = image[0].size();
        int x = image[sr][sc];
        int **arr = new int*[row];
        for(int i=0;i<row;i++)
        {
            arr[i] = new int[col];
            for(int j=0;j<col;j++)
            {
                arr[i][j]=0;
            }
        }
     
        find(image,arr,x,row,col,sr,sc,newColor);
        
        return image;
    }
};