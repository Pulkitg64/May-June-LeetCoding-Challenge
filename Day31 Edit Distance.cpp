class Solution {
public:
    int minDistance(string word1, string word2) {
   
        int**dp =new int*[word1.size()+1];
        for(int i=0;i<=word1.size();i++)
        {    dp[i]=new int[word2.size()+1];
        }
        
        for(int i=0;i<=word1.size();i++)
        {   
            dp[i][0]=i;
        }

         for(int j=0;j<=word2.size();j++)
         {
             dp[0][j]=j;
         }
        
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                int ans=INT_MAX;
                if(word1[i-1]==word2[j-1])
                    ans=dp[i-1][j-1];
                else
                {
                    int x = 1+dp[i-1][j-1];
                    int y = 1+dp[i][j-1];
                    int z = 1+dp[i-1][j];
                    
                    ans = min(ans,min(x,min(y,z)));
                }
                
                dp[i][j]=ans;
            }
        }
        return dp[word1.size()][word2.size()];

    }
};