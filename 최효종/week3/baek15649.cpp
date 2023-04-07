#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
bool visited[9];
int n, m;

void dfs() {
    if (v.size() == m) 
	{
        for (int item : v) cout << item << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
	{
        if (!visited[i]) {
            v.push_back(i);
            visited[i] = true;
            dfs();
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    dfs();
}