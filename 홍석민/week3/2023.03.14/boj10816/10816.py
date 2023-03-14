from collections import Counter
from typing import List

def solution(cards:Counter[int]) -> List[int]:
    show = list(map(int, input().split()))
    return [cards[key] for key in show]    

N = int(input())
cards = Counter(map(int, input().split()))
M = int(input())
print(*solution(cards), sep=' ')
