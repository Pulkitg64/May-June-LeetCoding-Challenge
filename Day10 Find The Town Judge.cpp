class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int *first = new int[N+1]{};
        int *second = new int[N+1]{};
        
        for(int i=0;i<trust.size();i++)
        {
            first[trust[i][0]]++;
            second[trust[i][1]]++;
            
        }
        
        for(int i=1;i<=N;i++)
        {
            if(!first[i])
            {
                if(second[i]==N-1)
                    return i;
            }
        }
        
        
        return -1;
    }
};