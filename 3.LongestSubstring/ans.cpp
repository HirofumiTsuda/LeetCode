class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        
        int ans = 0;
        // char : character, int : position
        unordered_map<char, int> pos;
        int tail=1; // next one
        for(int i=0;i<s.length();i++){
            pos[s[i]] = i;  // head is set.
            tail = (tail <= i)? i+1 : tail; // tail is set. it is far from head.
            int j;
            for(j=tail;j<s.length();j++){
                auto itr = pos.find(s[j]);
                if(itr == pos.end()){
                    pos[s[j]] = j;
                }else{
                    if(itr->second < i){
                        pos[s[j]] = j;
                    } else {
                        tail = j;
                        break;
                    }
                }
            }
            // if j runs over the designated range, tail is set the end of the string
            if(j == s.length()){
                tail = j;
            }
            string substr = s.substr(i, tail - i);
            cout << substr << endl;
            if(ans < substr.length()){
                ans = substr.length();
            }
        }
        return ans;
    }

};
