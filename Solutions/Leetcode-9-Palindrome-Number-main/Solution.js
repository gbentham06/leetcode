/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if (x < 0 || (x>0 && x%10==0)) return false;
    let temp = x, mirror = 0;
    while (temp > 0){
        mirror = mirror * 10 + (temp % 10);
        temp = Math.floor(temp / 10);
    }
    return x == mirror;
};
