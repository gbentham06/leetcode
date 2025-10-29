class Solution {
public:
    int smallestNumber(unsigned n) {
        return (bit_floor(n)<<1)-1;
    }
};
