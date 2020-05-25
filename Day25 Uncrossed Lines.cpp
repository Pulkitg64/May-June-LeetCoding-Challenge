int find(int **dp,vector<int>& A, vector<int>& B,int n,int m, int i,int j)
{
   // cout<<"i: "<<i<<" j: "<<j<<" n: "<<n<<" m: "<<m<<endl;
    if(i>n || j>m)
        return 0;
    int x=0,y=0,z=0;
    
    if(dp[i][j]==-1)
    {
        if(A[i]==B[j])
            x = find(dp,A,B,n,m,i+1,j+1)+1;
        else
        {
            y = find(dp,A,B,n,m,i,j+1);
            z = find(dp,A,B,n,m,i+1,j);
        }
        
        dp[i][j] = max(max(x,y),z);
    }
    
    

    return dp[i][j];
}
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        
        int ** dp = new int *[A.size()];
        for(int i=0;i<A.size();i++)
        {
            dp[i] = new int[B.size()];
            for(int j=0;j<B.size();j++)
            {
                dp[i][j]=-1;
            }
        }
        return find(dp,A,B,A.size()-1,B.size()-1,0,0);
    }
};