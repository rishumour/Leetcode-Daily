class Solution {
public:
    int minAddToMakeValid(string s) {
        int opened = 0;
        int closed = 0;
        for (char c : s){
            if (c =='('){
                opened++;
            }else if(c == ')'){
                if (opened > 0){
                    opened --;
                }else{
                    closed++;
                }
            }
        }
        return opened + closed;
    }
};