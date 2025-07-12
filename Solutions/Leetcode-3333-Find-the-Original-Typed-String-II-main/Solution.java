class Solution {
    private static int MOD = 1_000_000_007;

    public int possibleStringCount(String word, int k) {
        if (word.isEmpty()) return 0;

        int n = word.length();
        List<Integer> groups = new ArrayList<>();
        int count = 1;

        //grouping
        for (int i = 1; i < n; i++){
            if (word.charAt(i) == word.charAt(i-1)) count++;
            else{
                groups.add(count);
                count = 1;
            }
        }
        groups.add(count);

        int ng = groups.size();

        double combos = 1;
        for (int num: groups) combos = (combos*num)%MOD;

        if (k <= ng) return (int) combos;

        int[] bad_combos = new int[k];
        bad_combos[0] = 1;

        for (int num: groups) {
            int[] newbad = new int[k];
            double sum = 0;
            for (int i = 0; i < k; i++){
                if (i > 0) sum = (sum + bad_combos[i-1]) % MOD;
                if (i > num) sum = (sum - bad_combos[i-num-1]+MOD)%MOD;
                newbad[i] = (int) sum;
            }
            bad_combos = newbad;
        }

        double invalid = 0;
        for (int i = ng; i < k; i++){
            invalid = (invalid + bad_combos[i]) % MOD;
        }
        return (int) ((combos - invalid + MOD)%MOD);
    }
}
