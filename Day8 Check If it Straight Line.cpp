class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int x1,x2,y1,y2;
         double m;
        x1 = coordinates[0][0];
        y1 = coordinates[0][1];
        x2 = coordinates[1][0];
        y2 = coordinates[1][1];
        
        if(x1==x2)
        {
            for(int i=2;i<coordinates.size();i++)
            {
                x1 = coordinates[i-1][0];
              
                x2 = coordinates[i][0];
         
                if(x1!=x2)
                    return false;
            }
        }
       
        
        else
        {
            m = double(y2-y1)/double(x2-x1);
            for(int i=2;i<coordinates.size();i++)
            {
              
                x1 = coordinates[i-1][0];
                y1 = coordinates[i-1][1];
                x2 = coordinates[i][0];
                y2 = coordinates[i][1];
                
                if(m !=(double(y2-y1)/double(x2-x1)))
                    return false;
                m = double(y2-y1)/double(x2-x1);
            }
        }
        
        return true;
    }
};