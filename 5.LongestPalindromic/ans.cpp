// refer : https://leetcode.com/problems/longest-palindromic-substring/discuss/410963/Python-beats-93-solution-with-illustrations

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2 )
            return s;
        int start = 0;
        int maxLen = 1;
        int i = 0;

        while (i < s.length()){
            int l = i;
            int r = i;
            while(r < s.length() - 1 && s[r] == s[r+1]){
                r += 1;
            }
            i = r + 1;
            while(r < s.length()-1 && l > 0 && s[r+1] == s[l-1]){
                l -= 1;
                r += 1;
            }
            if (maxLen < r - l + 1){
                start = l;
                maxLen = r - l + 1;
            }
        }
        return s.substr(start, maxLen);
    }

};
