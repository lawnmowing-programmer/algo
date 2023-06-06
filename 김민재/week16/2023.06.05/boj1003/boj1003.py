import sys

T, *testcases = map(int, sys.stdin.read().splitlines())

result = []
for testcase in testcases:
    zero_count, one_count = 1, 0
    for _ in range(testcase):
        zero_count, one_count = one_count, zero_count + one_count
    result.append('{} {}'.format(zero_count, one_count))

sys.stdout.write('\n'.join(result))
