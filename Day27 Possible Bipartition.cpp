void bfs(vector<vector<int>>&dp,int *color,queue<pair<int,int>> q,int c,int index,int *visited,int n,int &flag)
{
    
    visited[index]=1;
    if(flag==1)
        return;
    for(int i=0;i<dp[index].size();i++)
    {
        int j =dp[index][i];
        if(color[j]==-1)
        {
            color[j]=c^1;
        }
        else if(color[j]!=-1)
        {
            if(color[j]!=(c^1))
            {   
                flag=1;
                return;
            }
        }

        if(visited[j]==0)
        {
            visited[j]=1;
            q.push(make_pair(j,c^1));
            
        }

    }
    if(!q.empty())
    {
        pair x=q.front();
        q.pop();
        
        bfs(dp,color,q,x.second,x.first,visited,n,flag);
    }
    
    return;
}

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        if(dislikes.size()==0)
            return 1;
        vector<vector<int>> dp(n);
        int *color = new int[n];
        int *visited = new int[n]{};
        for(int i=0;i<n;i++)
        {
            color[i] = -1;
        }
        int first,second;
        for(int i=0;i<dislikes.size();i++)
        {
            first = dislikes[i][0]-1;
            second = dislikes[i][1]-1;
            
            dp[first].push_back(second);
            dp[second].push_back(first);
            
        }
        queue<pair<int,int>> q;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                index = i;
                int flag=0;
                bfs(dp,color,q,0,index,visited,n,flag);
                if(flag==1)
                    return 0;
            }
        }
      
        return 1;
    }
};