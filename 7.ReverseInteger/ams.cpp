class Solution {
public:
    int reverse(int x) {
        bool minus = false;
        long lx = x;
        if(lx < 0){
            minus = true;
            lx = -lx;
        }
        long ans = 0;
        queue<int> q;
        
        // pile digit in stack
        while(lx > 0){
            q.push(lx%10);
            lx = lx/10;
        }
        // put them into an integer
        int size = q.size();
        for(int i=0;i<size;i++){
            ans = 10 * ans;
            ans = ans + q.front();
            q.pop();
        }
        if(minus)
            ans = -ans;
        // check the answer
        if(ans > INT_MAX){
            return 0;
        }else if(ans < -INT_MAX-1){
            return 0;
        }
        cout << ans << endl;
        return (int)ans;
    }
};
