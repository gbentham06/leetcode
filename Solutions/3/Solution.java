
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        // set based solution with a substring set and 2 pointers
        Set<Character> substring = new HashSet<>();
        int lp = 0, res = 0, end = s.length();
        char selection;

        for (int rp = 0; rp < end; rp++){
            // assignment for less calls in future
            selection = s.charAt(rp);
            
            // shrinks list until no duplicates
            while (substring.contains(selection)) {
                substring.remove(s.charAt(lp));
                lp++;
            }
            // updates result and substring
            substring.add(selection);
            res = Math.max(res, rp - lp + 1);
        }
        return res;
    }
}