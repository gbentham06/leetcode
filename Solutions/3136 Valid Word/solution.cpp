class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3){
            return false;
        }
        bool vowel = false, cons = false;

        for(char i: word){
            if (!isalnum(i)) return false;

            if (isalpha(i)){
                i = tolower(i);
                if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
                    vowel = true;
                } else {
                    cons = true;
                }
            }
        }
        return vowel && cons;
    }
};
