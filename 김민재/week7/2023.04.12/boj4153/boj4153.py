import sys

inputs = [sorted(map(lambda y: pow(int(y), 2), x.split())) for x in sys.stdin.read().splitlines()[:-1]]

result = ["right" if sum(triangle[:2]) == triangle[2] else "wrong" for triangle in inputs]

sys.stdout.write('\n'.join(result))
