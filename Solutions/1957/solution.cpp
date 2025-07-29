class Solution {
public:
    string makeFancyString(string s) {
        string out;
        char last = s[0];
        out.push_back(last);
        int count = 1;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == last){
                count++;
                if (count < 3){
                    out.push_back(s[i]);
                }
            } else {
                last = s[i];
                count = 1;
                out.push_back(s[i]);
            }
        }
        return out;
    }
};
