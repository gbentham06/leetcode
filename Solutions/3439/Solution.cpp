class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int count = startTime.size();
        vector<int> sumPrefix(count+1, 0);
        int maxFree = 0;

        for (int i=0; i<count; i++){
            sumPrefix[i+1] = sumPrefix[i] + (endTime[i]-startTime[i]);
        }

        for (int i=k-1; i<count; i++){
            int occupied = sumPrefix[i+1] - sumPrefix[i-k+1];
            int rp = (i==count-1) ? eventTime : startTime[i+1];
            int lp = (i==k-1) ? 0 : endTime[i-k];
            int freeTime = rp - lp - occupied;
            maxFree = max(maxFree, freeTime);
        }
        return maxFree;
    }
};
