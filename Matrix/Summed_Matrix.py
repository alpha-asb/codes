class Solution:
    def sumMatrix(self, n, q):
        if q > 2*n:
            return 0
        elif q <= n:
            return q-1
        return n - (q-n) + 1
