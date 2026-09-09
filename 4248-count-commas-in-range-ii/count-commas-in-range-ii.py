class Solution:
    def countCommas(self, n):
        total = 0
        power = 1000

        while power <= n:
            total += n - power + 1
            power *= 1000

        return total