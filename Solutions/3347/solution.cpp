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
    using int2=pair<int, int>; // (x, freq)
    static int maxFrequency(vector<int>& nums_, int k, int numOperations)    
    {
        int n=nums_.size();
        int* nums=nums_.data();
        radix_sort(nums, n);
        const int M=nums[n-1];

        vector<int2> nWf; // (x, freq)
        nWf.reserve(n);
        int prev=-1;
        for (int i=0; i<n; i++) {
            const int x=nums[i];
            if (x!=prev) {
                nWf.emplace_back(x, 1);
                prev=x;
            } 
            else nWf.back().second++;
        }

        n = nWf.size();
        int ans=0, cntP=0, cntI=0;
        int l=0, r=0, l2=0;

        for (int i=0; i<n; i++) {
            auto [x, f]=nWf[i];
            const int L=max(1, x-k), R=min(M, x+k),
            L2=max(1, x-2*k);
            
            // extending window for points
            for(; r<n && nWf[r].first<=R; r++)
                cntP+=nWf[r].second;
            // shrinking window  for points
            for(; l<n && nWf[l].first<L; l++) 
                cntP-=nWf[l].second;
            
            ans=max(ans, f+min(cntP-f, numOperations));

            // shrink window for intervals
            cntI+=f;
            for(; l2<r && nWf[l2].first<L2; l2++) 
                cntI-=nWf[l2].second;
                
            ans=max(ans, min(cntI, numOperations));
        }
        return ans;
    }
};


