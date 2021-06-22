class Solution {
public:
    #define NUM 13
    typedef pair<int, string> p;
    p nums[NUM] = {p(1000, "M"), p(900, "CM"), p(500, "D"),  p(400, "CD"), p(100, "C"), p(90, "XC"), p(50, "L"),  p(40, "XL"), p(10, "X"), p(9, "IX"), p(5, "V"), p(4, "IV"), p(1, "I")};
    string intToRoman(int num) {
        string s = "";
        for(int i=0;i<NUM;i++){
            int unit = nums[i].first;
            string ch = nums[i].second;
            while(num >= unit){
                num = num - unit;
                s = s + ch;
            }
        }
        return s;
    }
};
