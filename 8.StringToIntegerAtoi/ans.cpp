#define MAX_STR to_string(INT_MAX)
#define MIN_STR to_string(-INT_MAX-1)

class Solution {
public:
    
    int myAtoi(string s) {
        bool minus = false;
        s = trim(s);
        if(s.length() == 0)
            return 0;
        if (s[0] == '-'){
            s = s.substr(1);
            minus = true;
        }else if (s[0] == '+'){
            s = s.substr(1);
        }
        
        for(int i=0;i<s.length();i++){
            int diff = (int)(s[i] - '0');
            if(diff < 0 || 9 < diff){
                s = s.substr(0,i);
                break;
            }
        }
        
        for(int i=0;i<s.length();i++){
            if(s[i] != '0'){
                s = s.substr(i);
                break;
            }
            if(i == s.length() - 1)
                s = "";
        }
        
        if(s.length() == 0)
            return 0;
        
        if(MAX_STR.length() < s.length()){
            if(!minus){
                s = MAX_STR;
            }else{
                s = MIN_STR.substr(1);
            }
        }
        
        if(s.length() == MAX_STR.length()){
            if (minus &&"-"+s > MIN_STR){
                s = MIN_STR.substr(1);
            } else if(!minus && s > MAX_STR){
                s = MAX_STR;
            }
        }
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans = 10 * ans;
            ans = ans - (int)(s[i] - '0');
        }
        
        if(!minus)
            ans = -ans;
        
        return ans;
    }
    
    string trim(string &s){
        for(int i=0;i<s.length();i++){
            if(s[i] != ' ')
                return s.substr(i);
        }
        return move(s);
    }
};
