class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> first;
        map<int,int> second;
        int count=0;
        first[0]=-1;
        for(int i=0;i<n;i++)
        {
            
            if(nums[i]==0)
                count--;
            else 
                count++;
            
            if(first[count]==0)
                first[count] = i+1;
            
            else
                second[count] = i+1;
        }
        int max = 0;
        for(int i=n*-1;i<=n;i++)
        {
          
            if(first[i] && second[i])
            {
                if(i==0)
                    first[i]=0;
                if(second[i]-first[i]>max)
                    max = second[i]-first[i];
            }
        }
        
        return max;
    }
};