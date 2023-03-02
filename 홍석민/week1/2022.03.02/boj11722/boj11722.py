def bisect_left(subseq, target):
    low = 0
    hi = len(subseq) - 1
    while low < hi:
        mid = (low + hi) // 2
        if subseq[mid] > target:
            low = mid + 1
        else:
            hi = mid
    return (low)

def lis(seq):
    n = len(seq)
    subseq = [seq[0]]
    for i in range(1, n):
        if seq[i] < subseq[-1]:
            subseq.append(seq[i])
        else:
            j = bisect_left(subseq, seq[i])
            subseq[j] = seq[i]
    return (len(subseq))

N = int(input())
A = list(map(int, input().split()))
print(lis(A))