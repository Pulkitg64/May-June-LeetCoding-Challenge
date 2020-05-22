struct Sol {
    char c;
    int freq;
};


bool compare(Sol a, Sol b) 
{ 
    
        return a.freq >= b.freq; 
  
} 

class Solution {
public:
    string frequencySort(string s) {
        
        
        map<char,int> m;
        map<char,int> ::iterator it;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        
        Sol result[m.size()];
        int k=0;
        for(it = m.begin();it!=m.end();it++)
        {
            result[k].c = (*it).first;
            result[k].freq = (*it).second;
            k++;
        }
        
        sort(result,result + m.size(),compare);
        string ans = "";
        for(int i=0;i<m.size();i++)
        {
            int x = result[i].freq;
            ans = ans + string(x, result[i].c);
            
        }
        
        return ans;
        
    }
};