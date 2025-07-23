class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0, c1 = 0, c2 = 0;
        char ch1 = 'a', ch2 = 'b';
        if (x < y) {
            swap(x, y);
            ch1 = 'b';
            ch2 = 'a';
        }
        for (char i : s){
            if (i == ch1){
                c1++;
            } else if (i == ch2){
                if (c1 > 0){
                    c1--;
                    score += x;
                } else{
                    c2++;
                }
            } else{
                score += min(c1,c2) * y;
                c1 = 0;
                c2 = 0;
            }
        }
        if (c1 != 0) score += min(c1, c2) * y;
        return score;
    }
};
