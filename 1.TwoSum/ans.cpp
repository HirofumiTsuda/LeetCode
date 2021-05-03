#include <algorithm>
#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int sum = nums[i] + nums[j];
                if(sum == target){
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
    }
};
