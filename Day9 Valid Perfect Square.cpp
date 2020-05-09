class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long long int start = 1;
        long long int end = 1000000000;
        
        
        
        long long mid;
        
        while(start<=end)
        {
        
            mid = (end-start)/2 +start;
            if(mid*mid==num)
                return 1;
            
            else if(mid<num && mid*mid<num)
            {
                start = mid+1;
            }
            
            else
            {
                end = mid-1;
            }
            
            
        }
        
        
        return 0;
        
        
        
    }
};