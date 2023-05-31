import sys

L = int(sys.stdin.readline())
string = sys.stdin.readline().rstrip()

hash_result = sum((ord(char) - ord('a') + 1) * (31 ** i) for i, char in enumerate(string)) % 1234567891

sys.stdout.write(str(hash_result))
