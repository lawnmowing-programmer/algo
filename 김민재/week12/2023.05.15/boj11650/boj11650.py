import sys

inputs = sys.stdin.read().split()[1:]

pos = sorted(zip(inputs[::2], inputs[1::2]), key=lambda x: (int(x[0]), int(x[1])))

sys.stdout.write('\n'.join('{} {}'.format(*p) for p in pos))
