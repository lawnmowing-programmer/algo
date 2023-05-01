import sys
from collections import Counter

cards, predictions = map(lambda x: map(int, x.split()), sys.stdin.read().splitlines()[1::2])

card_count = Counter(cards)

sys.stdout.write(' '.join(str(card_count[prediction]) for prediction in predictions))
