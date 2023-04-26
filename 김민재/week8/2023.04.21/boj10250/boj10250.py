import sys

testcases = [list(map(int, testcase.split())) for testcase in sys.stdin.read().splitlines()[1:]]

result = [str(((testcase[2] - 1) % testcase[0] + 1) * 100 + (testcase[2] - 1) // testcase[0] + 1) for testcase in testcases]

sys.stdout.write('\n'.join(result))
