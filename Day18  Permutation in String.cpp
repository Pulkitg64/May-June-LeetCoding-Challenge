class Solution {
public:
    bool checkInclusion(string p, string s) {
        
        
        map<int,int> m,m1;
        int count=0;
        int len = p.size();
    
        if(s.size()<len)
            return 0;
        
        
        for(int i=0;i<len;i++)
        {
            m[p[i]-'a']++;
        }
        
        

        for(int i=0;i<len;i++)
        {
            if(m1[s[i]-'a']<m[s[i]-'a'])
            {    
                count++;
               
            }
             m1[s[i]-'a']++;
        }
        if(count==len)
            return 1;
        
  
        for(int i = len;i<s.size();i++)
        {
            if(m1[s[i-len]-'a']>0)
            {
                m1[s[i-len]-'a']--;
                if(m[s[i-len]-'a']>0 && m1[s[i-len]-'a']<m[s[i-len]-'a'])
                    count--;
            }
            

            if(m1[s[i]-'a']<m[s[i]-'a'])
            {    
                count++;
                
            }
            m1[s[i]-'a']++;
            
            if(count==len)
                return 1;
            
        }
        
        return 0;

    }
};