class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int shift = 0;
        for (int i = (int)ceil(log2(k))-1; i >= 0; i--){
            long long half = 1LL << i;
            if (k > half) {
                k -= half;
                shift += operations[i];
            }
        }
        return 'a' + (shift % 26);
    }
};
