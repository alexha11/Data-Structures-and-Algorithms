from math import factorial
from collections import Counter

stri = input().strip()

counts = Counter(stri)
n = len(stri)

result = factorial(n)
for co in counts.values():
    result //= factorial(co)

print(result)
