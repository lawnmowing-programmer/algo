# [Leetcode 70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/description/)

## 카테고리
* Math
* Dynamic Programming
* Memoization

## 풀이
1. `n`이 2 이하라면 n를 반환
2. `dp` 배열을 `n + 1`만큼 0으로 초기화
3. `dp[1]`는 1 `dp[2]`는 2로 초기화
4. 3 부터 `n`까지 `dp[i] = dp[i - 1] + dp[i - 2]`를 실행
5. `dp[n]`를 반환

## 시간 복잡도
O(n)

## 소감문
Dynamic Programming은 아직도 접근 하는 방법이 쉽지 않다. 접근 하는 태도에 대해서 더 연습이 필요해 보인다.

## 정답
[맞았습니다](https://leetcode.com/problems/climbing-stairs/submissions/908237277/)