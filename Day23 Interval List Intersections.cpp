class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        
        vector<vector<int>> result;
     
        int i=0,j=0;
        
        while(i<A.size()&& j<B.size())
        {
            int s1 = A[i][0];
            int e1 = A[i][1];
            int s2 = B[j][0];
            int e2 = B[j][1];
            
            
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            if(e1<s2)
            {
            }
            
            else if(e2<s1)
            {
            }
            
            else if(s1<s2 && e1==s2)
                result.push_back({e1,e1});
            
            else if(s2<s1&& e2==s1)
                result.push_back({e2,e2});
            
            else if(s1<=s2 && e2<=e1 && e2>=s1)
                result.push_back({s2,e2});
         
            else if(s2<=s1 && e1<=e2)
                result.push_back({s1,e1});
         
            else if(s2<s1 && e2<=e1)
                result.push_back({s1,e2});
       
            else if(s1<s2 && e1<e2)
                result.push_back({s2,e1});
                
            if(e1<e2)
                i++;
            else if(e2<e1)
                j++;
            else
            {
                i++;j++;
            }
            
        }
        
        return result;
        
    }
};