class Solution {
public:
    #define MAX 3*(int)1e4
    typedef pair <char, int> p;
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        int dp[MAX+1];
        dp[0] = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                dp[i+1] = 0;
                st.push(i);
            }else{
                if(st.empty()){
                    dp[i+1] = 0;
                }else{
                    dp[i+1] = dp[i] + 2 + dp[st.top()];
                    st.pop();
                }
            }
        }
        for(int i=0;i<s.size();i++){
            if(ans < dp[i+1])
                ans = dp[i+1];
        }
        return ans;   
    }
};
