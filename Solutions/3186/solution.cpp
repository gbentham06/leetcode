const int N=256, mask=255, bshift=8;
int freq[N];

void radix_sort(int* nums, int n) {
    int* output = (int*)alloca(n * sizeof(int));  // buffer
    unsigned M=*max_element(nums, nums+n);
    const int Mround = max(1, int(31-countl_zero(M)+bshift)/bshift);
    int* in=nums;
    int* out=output;
    bool swapped=0;

    for (int round=0; round<Mround; round++) {
        const int shift=round*bshift;
        memset(freq, 0, sizeof(freq));

        for (int i = 0; i < n; i++)
            freq[(in[i] >> shift) & mask]++;

        partial_sum(freq, freq+N, freq);

        for (int i = n - 1; i >= 0; i--) {
            int val = in[i];
            int x = (val >> shift) & mask;
            out[--freq[x]] = val;
        }

        swap(in, out);
        swapped = !swapped;
    }

    // If needed, copy back
    if (swapped)
        memcpy(nums, in, n * sizeof(int));
}
class Solution {
public:
    using info=pair<int, long long>;// (power, damage)
    static long long maximumTotalDamage(vector<int>& power) {
        const int n=power.size();
        int* P=power.data();
        radix_sort(P, n);

        vector<info> spell={{P[0], P[0]}};
        for(int i=1; i<n; i++){
            int x=P[i]; 
            if (x!=P[i-1]) spell.emplace_back(x, (long long)x);
            else spell.back().second+=x;
        }
        int sz=spell.size();
        vector<long long> dp(sz+1, 0);

        for(int i=sz-1; i>=0; i--){
            long long notake=dp[i+1];
            long long take=0;
            int j=i+1,  x=spell[i].first;
            for(; j<sz && spell[j].first<=x+2; j++);

            take=spell[i].second+dp[j];
            dp[i]=max(take, notake);
        }
        
        return dp[0];
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();