impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let n=nums.len();
        let mut ans=vec![false; n];
        let mut msb=0;
        for i in 0..n{
            msb=((msb<<1)+nums[i])%5;// (msb*2+nums[i])%5
            ans[i]=msb==0;
        }
        ans
    }
}
