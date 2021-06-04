class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int h = (height[l] <= height[r])? height[l] : height[r];
        int score = r*h;
        int width = r;
        while(width > 0){
            if(height[l] < height[r]){
                for(int i=l+1;i<=r;i++){
                    if(height[l] < height[i]){
                        l = i;
                        width = r - l;
                        h = (height[l] <= height[r])? height[l] : height[r];    
                        if(score < width*h)
                            score =  width*h;
                        break;
                    }
                }   
            }else{
                for(int i=r-1;i>=l;i--){
                    if(height[r] <= height[i]){
                        r = i;
                        width = r - l;
                        h = (height[l] <= height[r])? height[l] : height[r];             
                        if(score < width*h)
                            score =  width*h;
                        break;
                    }
                }   
            }
        }
        return score;
    }
};
