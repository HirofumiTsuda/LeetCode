class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left;
        vector<int> right;
        int size = height.size();
        if (size <= 3)
            return 0;
        
        left.push_back(height[0]);
        int prev, curr;
        for(int i=1;i<size;i++){
            prev = height[i-1];
            curr = height[i]
            if(prev >= curr){
                left.push_back(prev);
            }else{
                left.push_back(curr);      
            }
        }
        
        right.push_back(height[size - 1]);   
        for(int i=1;i<size;i++){
            prev = height[size - i];
            curr = height[size - i - 1]
            if(prev >= curr){
                left.push_back(prev);
            }else{
                left.push_back(curr);      
            }
        }
        
        int ans = 0;
        for(int i=0;i<size;i++){
            ans += min(left[i], right[size - 1 - i]) - height[i];
        }
        return ans;
    }
};
