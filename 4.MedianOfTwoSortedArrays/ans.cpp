class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int& e : nums2){
            nums1.push_back(e);
        }
        sort(nums1.begin(), nums1.end(), greater<int>());
        for(int& e : nums1){
            cout << e << endl;
        }
        int num = nums1.size();
        if(num%2 == 1){
            return nums1[(num-1)/2];
        }else{
           return (nums1[num/2 - 1] + nums1[num/2])/2.0; 
        }
        return 0.0;
    }
};
