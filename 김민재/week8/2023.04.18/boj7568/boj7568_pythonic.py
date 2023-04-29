import sys

size = [list(map(int, x.split())) for x in sys.stdin.read().splitlines()[1:]]
compare = [sum([person1[0] < person2[0] and person1[1] < person2[1] for person2 in size]) for person1 in size]
sys.stdout.write(' '.join([str(rank + 1) for rank in compare]))
