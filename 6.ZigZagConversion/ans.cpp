class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int i=0;
        while(i<s.length()){
            for(int j1=0;j1<numRows;j1++){
                if(i < s.length()){
                    v[j1] += s[i];
                    i++;
                }
            }
            
            for(int j2=0;j2<numRows-2;j2++){
                if(i < s.length()){
                    v[numRows - 2 - j2] += s[i];
                    i++;
                }
            }
        }
        string ans = "";
        for(string str : v){
            ans += str;
        }
        return ans;
    }
};
