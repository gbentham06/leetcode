class Solution:
    word = ['a']
    def kthCharacter(self, k: int) -> str:
        while len(self.word) < k:
            n = len(self.word)
            for i in range(n):
                newchar = chr(ord('a') + ((ord(self.word[i]) - ord('a') + 1) % 26))
                self.word.append(newchar)
        return self.word[k-1]
