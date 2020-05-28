class Solution {
public:
    vector<int> countBits(int num) {
        
        int *dp = new int[num+1];
        
        if(num==0)
            return {0};
        if(num==1)
            return {0,1};
        
        dp[0]=0;
        dp[1]=1;
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        int k= 1;
        int x;
        int c;
        for(int i=2;i<=num;i++)
        {
            if(pow(2,k)==i)
            {
                x = pow(2,k);
                k++;
                dp[i] =1;
                result.push_back(1);
            }
            else{
            c = dp[i%x]+1;
            result.push_back(c);
            dp[i]=c;
            }
            
            
        }
        return result;
        
    }
};