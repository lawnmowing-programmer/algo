import sys

while (num_str := sys.stdin.readline().rstrip()) != '0':
    sys.stdout.write(("yes" if num_str == num_str[::-1] else "no") + "\n")
