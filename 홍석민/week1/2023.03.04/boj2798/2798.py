from itertools import combinations
from typing import List

def solution(cards: List[int], M: int):
    res = 0
    for possible in combinations(cards, 3):
        temp = sum(possible)
        res = temp if temp <= M and temp > res else res
    print(res)

N, M = map(int, input().split())
cards = list(map(int, input().split()))
solution(cards, M)
