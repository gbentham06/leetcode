class Solution:
    MOD = 10**9 + 7
    def possibleStringCount(self, word: str, k: int) -> int:
        n = len(word)
        if not word:
            return 0

        groups = []
        count = 1
        for i in range(1, n):
            if word[i] == word[i-1]:
                count += 1
            else:
                groups.append(count)
                count = 1
        groups.append(count)
        ng = len(groups)

        combos = 1
        for num in groups:
            combos = (combos * num) % self.MOD
        
        if k <= ng:
            return combos

        bad_c = [0]*k
        bad_c[0] = 1

        for num in groups:
            newbad = [0] * k
            sum_v = 0
            for i in range(k):
                if i > 0: sum_v = (sum_v + bad_c[i-1]) % self.MOD
                if i > num: sum_v = (sum_v-bad_c[i-num-1]+self.MOD)%self.MOD
                newbad[i] = sum_v
            bad_c = newbad

        invalid = sum(bad_c[ng:k]) % self.MOD
        return (combos - invalid + self.MOD) % self.MOD

