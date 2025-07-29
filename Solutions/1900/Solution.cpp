class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int lp = min(firstPlayer, secondPlayer);
        int rp = max(firstPlayer, secondPlayer);

        if (lp + rp == n+1){
            return {1, 1};
        }

        if (n == 3 || n == 4){
            return {2, 2};
        }

        if (lp - 1 > n - rp){
            int temp = n + 1 - lp;
            lp = n + 1 - rp;
            rp = temp;
        }

        int nextRound = (n + 1) / 2;
        int minRound = n, maxRound = 1;

        if (rp*2 <= n+1){
            int plp = lp - 1;
            int mid = rp - lp - 1;

            for (int i = 0; i <= plp; i++){
                for (int j = 0; j <= mid; j++){
                    auto out = earliestAndLatest(nextRound, i+1, i+j+2);
                    minRound = min(minRound, 1+out[0]);
                    maxRound = max(maxRound, 1+out[1]);
                }
            }
        } else {
            int mir = n+1-rp;
            int plp = lp-1;
            int mid = mir - lp - 1;
            int igap = rp-mir-1;

            for (int i = 0; i <= plp; i++){
                for (int j = 0; j <= mid; j++){
                    int p1 = i+1;
                    int p2 = i+j+1+(igap+1)/2+1;
                    auto out = earliestAndLatest(nextRound, p1, p2);
                    minRound = min(minRound, 1+out[0]);
                    maxRound = max(maxRound, 1+out[1]);
                }
            }
        }
        return {minRound, maxRound};
    }
};
