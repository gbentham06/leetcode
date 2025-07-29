class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        int p = 0, t = 0, out = 0;
        while (p < players.size() && t < trainers.size()){
            if (players[p] <= trainers[t]){
                p++;
                out++;
            }
            t++;
        }
        return out;
    }
};
