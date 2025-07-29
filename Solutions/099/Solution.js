/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSubsequence = function(nums, k) {
        nums = nums.map((v, i) => [v, i]);
        nums.sort((a, b) => b[0] - a[0]);
        let newslice = nums.slice(0, k);
        newslice.sort((a, b) => a[1] - b[1]);
        return newslice.map(pair => pair[0]);
};
