from bisect import bisect_left

def lis(seq):
    n = len(seq)
    subseq = [seq[0]]
    for i in range(1, n):
        if seq[i] > subseq[-1]:
            subseq.append(seq[i])
        else:
            j = bisect_left(subseq, seq[i])
            subseq[j] = seq[i]
    return (len(subseq))

N = int(input())
A = list(map(int, input().split()))
print(lis(A))