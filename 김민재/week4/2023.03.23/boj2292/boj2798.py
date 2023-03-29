import sys
from itertools import combinations

N, M = map(int, sys.stdin.readline().split())
cards = list(map(int, sys.stdin.readline().split()))

result = 0
for selected_cards in combinations(cards, 3):
    temp = sum(selected_cards)
    if result < temp <= M:
        result = temp

sys.stdout.write(str(result))
