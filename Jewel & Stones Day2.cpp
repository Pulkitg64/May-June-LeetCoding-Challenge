class Solution {
public:
    int numJewelsInStones(string J, string S) {
       map<char,int> m;
        
        for(int i=0;i<J.size();i++)
        {
            m[J[i]]++;
        }
        
        int count=0;
        for(int i=0;i<S.size();i++)
        {
            if(m[S[i]])
                count++;
        }
        
        return count;
    }
};