class Solution {
public:
    int findComplement(int num) {
        int i=0;
        while(num>((pow(2,i)-1)))
              i++;
              
        return (pow(2,i)-1-num);
        
    }
};