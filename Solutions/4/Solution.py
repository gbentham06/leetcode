class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        res = nums1 + nums2
        # i think python uses quicksort
        res.sort()

        # if it works it works
        if len(res) & 1:
            return res[int(len(res)/2 - 0.5)]
        else:
            m1 = res[int(len(res)/2 - 1)]
            m2 = res[int(len(res)/2)]
            return m1 + ((m2 - m1) / 2)
