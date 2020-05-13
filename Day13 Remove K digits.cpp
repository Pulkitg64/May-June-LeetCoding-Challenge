
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int length = num.size();
        if(k>=length)
            return "0";
        
    
        stack<char> st;
        
        for(int i=0;i<num.size();i++)
        {
            
            
            while(!st.empty() && num[i]< st.top() && k>0)
            {
                st.pop();
                k--;
            }
            
            st.push(num[i]);
        }    
       // cout<<k<<" "<<st.top()<<endl;
        while(k>0)
        {
            st.pop();
            k--;
        }
       // cout<<st.top()<<endl;
        string result = "";
        
        while(!st.empty())
        {
            result = result+ st.top();
            //cout<<result<<endl;
            st.pop();
        }
        
        reverse(result.begin(),result.end());
        
        while(result[0]=='0')
        {
            result = result.substr(1,result.size()-1);
        }
        
        if(result.size()==0)
            return "0";
        return result;
    }
};