#include <bits/stdc++.h>

using namespace std;

# define MAX 3000000

int N,M,K;
int board[52][52];
int A[52][52];
tuple<int,int,int> order[52];

// rotate를 진행할 범위에 대한 구조체
struct pos
{
	public:
		int x;
		int y;
        // 구조체에 대한 생성자.
        // 해당 구조체의 변수를 선언할 때 x, y의 값을 전달해주면 해당 값으로 초기화해줌.
        // ex) pos v(5,2); => x가 5이고 y가 2인 pos형 변수 v.
		pos(int x, int y)
			:x(x), y(y) {};
        // cpp에서는 구조체에 대해 연산자 함수를 구현할 수 있다.
        // 연산자의 종류는 operand의 갯수에 따라 unary 연산자와 binary 연산자로 나뉜다.
        // ex) unary 연산자: 전위, 후위 증감자 (a++, b++, ...) => 하나의 operand로 연산
        // ex) binary 연산자: +,-,/,* (a+b, a-b, ...) => 두개의 operand로 연산
        // binary 연산자의 경우 두 가지 형태로 선언이 가능하다.
        // 1. (반환 형) operator (연산자) (인자, 인자)
        // 2. (반환 형) operator (연산자) (인자)
        // (둘 모두 구현할 경우 compiler error 발생)
        // 후자의 경우 연산자의 왼쪽에 오는 값을 해당 함수를 호출한 구조체로 간주하여 연산을 진행한다.
		bool operator >= (const pos& cmp)
		{
			if (x >= cmp.x && y >= cmp.y)
				return (true);
			return (false);
		}
        // 위의 함수를 a >= b 이런식으로 사용을 할 경우
        // a를 해당 함수를 호출한 변수, b를 인자 cmp로 간주한다.
        // 위의 함수에서 x라고만 적혀있는 것은 (this->x)에서 this->를 생략해서 사용해도 되기 때문이다.
		pos operator + (int n)
		{
			pos tmp(x + n, y + n);

			return (tmp);
		}
		pos operator - (int n)
		{
			pos tmp(x - n, y - n);
			return (tmp);
		}
};

// 바깥부터 안쪽 방향으로 rotate 과정을 진행한다.
void board_rotate(pos a, pos b)
{
    // 시작 지점이 종료 지점을 넘어갈 경우 종료
	if (a >= b)
		return ;
    // 4변에 대하여 rotate를 진행
	for (int i = a.x; i < b.x; i++)
		swap(A[i][a.y], A[i+1][a.y]);
	for (int i = a.y; i < b.y; i++)
		swap(A[b.x][i], A[b.x][i+1]);
	for (int i = b.x; i > a.x; i--)
		swap(A[i][b.y], A[i-1][b.y]);
	for (int i = b.y; i > a.y + 1; i--)
		swap(A[a.x][i], A[a.x][i-1]);
	board_rotate(a + 1, b - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			cin >> board[i][j];
	int ans = MAX;
	for (int i=0; i<K; i++)
	{
		int r,c,s; cin >> r >> c >> s;
		order[i] = {r,c,s};
	}
    // next_permutation 함수를 이용해 k개의 연산의 순서를 바꿔가며
    // 연산을 진행해주었다.
    vector<int> brute(K);
	for (int i=0; i<K; i++)
		brute[i] = i;
	do
	{
        // 매 연산마다 새로운 값을 받아준다.
		for (int i=1; i<=N; i++)
			for (int j=1; j<=M; j++)
				A[i][j] = board[i][j];
		for (int i=0; i<K; i++)
		{
			auto [r,c,s] = order[brute[i]];
			// rotate를 진행할 범위의 시작 지점
            pos L(r-s, c-s);
            // rotate를 진행할 범위의 종료 지점
			pos R(r+s, c+s);
			board_rotate(L,R);
		}
        // rotate를 진행한 후 행의 점수의 합을 계산해줌.
        // ans를 제일 작은 값으로 갱신
		for (int i=1; i<=N; i++)
		{
			int cnt = 0;
			for (int j=1; j<=M; j++)
				cnt += A[i][j];
			ans = min(ans, cnt);
		}
	} while (next_permutation(brute.begin(), brute.end()));
	cout << ans;
}
