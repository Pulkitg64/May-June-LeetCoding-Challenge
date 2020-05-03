class Solution {
public:
    bool canConstruct(string ransom, string magazine) {
        
     
        map<char,int> m;
        for(int i=0;i<magazine.size();i++)
        {
            m[magazine[i]]++;
        }
        
        for(int i=0;i<ransom.size();i++)
        {
            if(m[ransom[i]]){
                m[ransom[i]]--;
            }
            else{
                return 0;
            }
        }
        
        
        return 1;
        
        
    }
};