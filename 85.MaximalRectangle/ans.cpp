class Solution {
    #define MAX 200
    typedef pair<int, int> p;
    p spaces[MAX][MAX];
public:
    void calculate_space(const vector<vector<char>> &matrix){
        int m,n;
        m = matrix.size();
        n = matrix[0].size();
        // horizon
        for(int i=0;i<m;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '1'){
                    sum++;
                }else{
                    for(int s=1;s<=sum;s++){
                        spaces[i][j-s].first = s;
                    }
                    sum = 0;
                }
            }
            for(int s=1;s<=sum;s++){
                spaces[i][n-s].first = s;
            }
            sum = 0;
        }
        // vertical
        for(int j=0;j<n;j++){
            int sum = 0;
            for(int i=0;i<m;i++){
                if(matrix[i][j] == '1'){
                    sum++;
                }else{
                    for(int s=1;s<=sum;s++){
                        spaces[i-s][j].second = s;
                    }
                    sum = 0;
                }
            }
            for(int s=1;s<=sum;s++){
                spaces[m-s][j].second = s;
            }
            sum = 0;
        }
    }
    
    int maxsize(int i, int j){
        p dist = spaces[i][j];
        if(dist.first == 0)
            return 0;
        int min = MAX;
        int size = 0;
        for(int n=0;n<dist.second;n++){
            p loc = spaces[i+n][j];
            if(min > loc.first)
                min = loc.first;
            int sq = (n+1)*min;
            if(sq > size)
                size = sq;
        }
        return size;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int ans = 0;
        int m,n;
        m = matrix.size();
        n = matrix[0].size();
        calculate_space(matrix);
        int tmp = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                tmp = maxsize(i,j);
                if(ans < tmp)
                    ans = tmp;
            }
        }
        return ans;
    }
};
