# [Leetcode 67 Add Binary](https://leetcode.com/problems/add-binary/description/)

## 카테고리
* Math
* String

## 시간 복잡도
O(MN) - `a`의 길이 `N`, `b`의 길이 `M`

## 풀이
1. `i`, `j`를 통해 `a`와 `b`문자열에 접근
2. `sum`변수를 `up`로 초기화
3. `sum`에 `i`가 0 이상일 경우 `a`문자열의 인덱스를 더함
4. `sum`에 `j`가 0 이상일 경우 `b`문자열의 인덱스를 더함
5. `up`변수에 `sum`이 2 이상일 경우 1 아니면 0으로 초기화
6. `ans`변수 앞에 `sum`을 문자열 형태로 변환하여 더함
7. `i` 또는 `j`가 0 이상일 경우 2번으로 이동
8. `up` 변수가 1일 경우 `ans` 문자열 앞에 1를 더함

## 정답
[맞았습니다](https://leetcode.com/problems/add-binary/submissions/907710361/)