typedef tuple<int, int, int> t;
typedef pair<int, int> p;
#define MAX 200

class Solution {
public:
    bool visited[MAX][MAX];
    
    void init() {
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                visited[i][j] = false;
            }
        }
    }
    
    bool isSafe(p &a, p &b, int m, int n) const {
        int w = a.first + b.first;
        int h = a.second + b.second;
        if(0 <= w && w < m && 0 <= h && h < n)
            return true;
        return false;
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        init();
        int m,n;
        m = heightMap.size();
        n = heightMap[0].size();
        priority_queue<t, vector<t>, greater<t>> pq;
        p direct[4] = {p(0,1), p(0,-1), p(1,0), p(-1,0)};
        int ans = 0;
        // push positions at edges pf map;
        for(int i=0;i<m;i++){
            pq.emplace(t(heightMap[i][0],i,0));
            visited[i][0] = true;
            pq.emplace(t(heightMap[i][n-1],i,n-1));
            visited[i][n-1] = true;
        }
        for(int j=1;j<n-1;j++){
            pq.emplace(t(heightMap[0][j],0,j));
            visited[0][j] = true;
            pq.emplace(t(heightMap[m-1][j],m-1,j));
            visited[m-1][j] = true;
        }
        
        while(pq.size() > 0){
            t e = pq.top();
            p curr(get<1>(e), get<2>(e));
            int h = get<0>(e);
            pq.pop();
            for(int i=0;i<4;i++){
                if(isSafe(curr, direct[i], m, n)){
                    p pos(curr.first + direct[i].first, curr.second + direct[i].second);
                    if(!visited[pos.first][pos.second]){
                        visited[pos.first][pos.second] = true;
                        int pos_h = heightMap[pos.first][pos.second];
                        if(h > pos_h){
                            ans += h - pos_h;
                            pos_h = h;
                        }
                        pq.emplace(t(pos_h, pos.first, pos.second));
                    }
                }
            }
        }
        return ans;
    }
};
