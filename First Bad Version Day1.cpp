// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int start = 1;
        int end = n;
        int mid = (end-start)/2+(start);
        
        while(start<=end)
        {
            
            if(isBadVersion(mid) && mid==1)
            {
                return 1;
            }
            else if(isBadVersion(mid) && !isBadVersion(mid-1) )
            {
                return mid;
            }
            
            else if(isBadVersion(mid) && isBadVersion(mid-1))
            {
                end = mid-1;
            }
            else if(!isBadVersion(mid))
            {
                start = mid+1;
            }
    
            
            mid = (end-start)/2+(start);
        }
        
        
        return -1;
        
    }
};