#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int numberOfPairs(std::vector<std::vector<int>>& points) {
        // Sort points: 1st by x-coordinate ascending, 2nd by y-coordinate descending.
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });

        int n = points.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int y1 = points[i][1];
            // Use INT_MIN for the initial lowest possible value.
            int maxY = std::numeric_limits<int>::min();

            for (int j = i + 1; j < n; ++j) {
                int y2 = points[j][1];

                // Check if point j is a potential lower-right partner.
                if (y2 <= y1) {
                    // If its y-coordinate is higher than the highest found so far,
                    // it forms a valid pair.
                    if (y2 > maxY) {
                        count++;
                        maxY = y2;
                    }
                }
            }
        }
        return count;
    }
};
