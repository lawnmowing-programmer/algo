import sys

users = sys.stdin.read().splitlines()[1:]

users = sorted(users, key=lambda x: int(x.split()[0]))

sys.stdout.write('\n'.join(users))