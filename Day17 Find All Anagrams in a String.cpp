class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
    
        map<int,int> m,m1;
        int count=0;
        int len = p.size();
        
        vector<int> result;
        if(s.size()<len)
            return result;
        
        
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
            result.push_back(0);
        
  
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
                result.push_back(i-len+1);
            
        }
        
        return result;
        
    }
};