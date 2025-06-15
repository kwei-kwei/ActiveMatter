from time import perf_counter
from random import choices

t1_start = perf_counter()

x = choices(range(1000), k=100_000_000)

def prod_f(x):
    prod = 0.0
    for i in x:
       prod *= i
    return prod

prod_f(x)

t1_end = perf_counter()

print(f"total elapsed time {t1_end - t1_start} s")
