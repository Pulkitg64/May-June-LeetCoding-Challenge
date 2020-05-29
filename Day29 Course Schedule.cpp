void dfs(vector<vector<int>> & dp,int index,int *color,int n,int & flag)
{
  
    color[index]=1;       
  
    if(flag)
        return;
        
    for(int i=0;i<dp[index].size();i++)
    {
      
        if(color[dp[index][i]]==1)
        {
            flag=1;
            break;
        }
        if(color[dp[index][i]]==2)
            continue;
      
        else
         dfs(dp,dp[index][i],color,n,flag) ;
        
    }

    color[index]=2;
    return;
}
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<vector<int>> dp (numCourses);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            
            int first = prerequisites[i][0];
            int second = prerequisites[i][1];
            
            dp[second].push_back(first);
        }
        
        int flag=0;
      
        int *color = new int[numCourses]();
      
        for(int i=0;i<numCourses;i++)
        {
            if(color[i]==0)
            {
                dfs(dp,i,color,numCourses,flag);
                if(flag)
                    return 0;
            }
        }
        return 1;
    }
};