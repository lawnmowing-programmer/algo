#include <iostream>

using namespace std;

typedef long long ll;

ll X,Y,W,S;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> X >> Y >> W >> S;
	ll ans = 0;
	// 대각선으로 갈 수 있을만큼 이동한 후 직선으로 이동
	ans = min(X,Y) * S + abs(X-Y) * W;
	ans = min(ans, (X+Y) % 2 == 0 ? max(X,Y) * S : (max(X,Y) - 1) * S + W);
	// 그냥 직선으로만 이동
	ans = min(ans, (X+Y) * W);
	cout << ans;
}
