import sys

sugar = int(sys.stdin.readline())

if sugar % 5 == 0:
    sys.stdout.write(str(sugar // 5))
else:
    bags_of_5kg = sugar // 5
    remaining_sugar = sugar % 5
    for _ in range(3):
        if remaining_sugar % 3 == 0:
            bags_of_3kg = remaining_sugar // 3
            sys.stdout.write(str(bags_of_5kg + bags_of_3kg))
            break
        remaining_sugar += 5
        bags_of_5kg -= 1
        if bags_of_5kg < 0:
            sys.stdout.write("-1")
            break
