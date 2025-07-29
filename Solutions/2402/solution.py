import heapq

class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        free = list(range(n))
        heapq.heapify(free)

        busy = []
        count = [0]*n

        for start, end in meetings:
            while busy and busy[0][0] <= start:
                _, r = heapq.heappop(busy)
                heapq.heappush(free,r)
            if free:
                r = heapq.heappop(free)
                newend = end
            else:
                endtime, r = heapq.heappop(busy)
                newend = endtime + (end - start)
            heapq.heappush(busy, (newend, r))
            count[r] += 1
        return max(range(n), key=count.__getitem__)
