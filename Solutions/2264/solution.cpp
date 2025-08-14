class Solution {
public:
    string largestGoodInteger(string num) {
        if (num.size() < 3) return "";
        char maxnum = 0;
        for (int i = 2; i < num.size(); i++){
            if (num[i] == num[i-1] && num[i] == num[i-2]){
                maxnum = max(maxnum, num[i]);
            }
        }
        if (maxnum == 0) return "";
        return string(3, maxnum);
    }
};
