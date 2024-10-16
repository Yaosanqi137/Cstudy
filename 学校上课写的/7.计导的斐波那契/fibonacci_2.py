import time

if __name__ == "__main__":
    a, b = 1, 0
    term = int(input("请问你想看到斐波那契数列的第几项: "))
    start = time.time()
    for i in range(1, term + 1):
        print(f"F[{i}] = {a}")
        b, c = a, b
        a += c
    end = time.time()
    print(f"耗时: {(end - start):.10f}ms\n")
