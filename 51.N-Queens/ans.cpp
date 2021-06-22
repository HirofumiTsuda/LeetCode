class Solution {
    #define MAX 9
    vector<vector<string>> ans;
    int N;
public:
    bool safe(int x, int y){
        return (0 <= x) && (x < N) && (0 <= y) && (y < N);
    }
    
    void use(int x, int y, vector<vector<bool>> &used){
        for(int i=0;i < N;i++){            
            used[x][i] = true;
            used[i][y] = true;
            if(safe(x-i,y-i))
                used[x-i][y-i] = true;
            if(safe(x+i,y+i))
                used[x+i][y+i] = true;
            if(safe(x-i,y+i))
                used[x-i][y+i] = true;
            if(safe(x+i,y-i))
                used[x+i][y-i] = true;
        }
    }
    
    string create_map(int x){
        string ans = "";
        for(int i=0;i<N;i++){
            if(i == x){
                ans += "Q";
            }else{
                ans += ".";
            }
        }
        return ans;
    }
    
    void solve(int y, vector<vector<bool>> &used,  vector<string> &map){
        if(y >= N){
            ans.push_back(map);
            return;
        }
        for(int i=0;i<N;i++){
            if(!used[i][y]){
                vector<vector<bool>> tmp_used = used;
                use(i,y,tmp_used);
                vector<string> tmp = map;
                tmp.push_back(create_map(i));
                solve(y+1,tmp_used,tmp);
            }
        }
    }
    
    void init(vector<vector<bool>> &v){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                v[i].push_back(false);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<vector<bool>> used(n);
        init(used);
        for(int i=0;i<N;i++){
            vector<vector<bool>> tmp = used;
            vector<string> map;
            use(i, 0, tmp);
            map.push_back(create_map(i));
            solve(1, tmp, map);
        }
        return ans;
    }
};
