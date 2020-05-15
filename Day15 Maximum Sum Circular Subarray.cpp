class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int i=0;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int sum=0;
        int sum1=0;
        int total =0;
        int flag=0;
        int maximum = INT_MIN;
        
        
        //FIND MAXIMUM CONTINUOUS SUBARRAY--(1)
        //FIND MINIMUM CONTINUOUS SUBARRAY --(2)
        //FIND TOTAL SUM OF ARRAY--(3)
        //MAXIMUM VALUE =  MAX(1,3-2);
        // IF ALL NUMBERS ARE NEGATIVE THEN MAXIMUM ELEMENT  IS THEE ANS
        for(int i=0;i<A.size();i++)
        {
            if(A[i]>0)
                flag=1;
            
            total = total + A[i];
            sum = sum+A[i];
            sum1 = sum1 + A[i];
            
            
            maximum = max(maximum,A[i]);
            mini = min(sum1,mini);
            maxi = max(sum,maxi);
            
            
            if(sum1>0)
                sum1 = 0;
            if(sum<0)
                sum=0;
     
        }
        
        if(flag==1)
            return max(maxi,total-mini);
        
            return maximum;
        
    }
};