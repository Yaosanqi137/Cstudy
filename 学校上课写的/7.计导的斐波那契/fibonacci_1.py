import time

def fibonacci(n):
    if n <= 2:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

if __name__ == '__main__':
    n = int(input("你想看到斐波那契数列的第几项: "))
    start = time.time()
    for n in range(1, n + 1):
        print(f"F[{n}] = ", fibonacci(n))
    end = time.time()
    print(f"耗时: {end - start}ms\n")
