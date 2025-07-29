/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    s = s.trim();
    let pointer = 0, n = s.length, sign = 1, out = 0;
    
    if (pointer < n && (s[pointer] === '+' || s[pointer] === '-')) {
        sign = s[pointer] === '-' ? -1 : 1;
        pointer++;
    }

    while (pointer < n && s[pointer] >= '0' && s[pointer] <= '9') {
        out = out * 10 + (s[pointer].charCodeAt(0) - 48);
        if (out * sign > 2**31 - 1) return 2**31 - 1;
        if (out * sign < (-2)**31) return (-2)**31;
        pointer++;
    }

    return out * sign;
    
};
