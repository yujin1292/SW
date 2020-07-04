#include <iostream>
#include <vector>

using namespace std;
int const MAX = 5;

int num[MAX] = { -7,-3,-2,5,8 };
int N, S, ans;



// v ->  ���� ��ġ(�ε���)
// sum -> ���ݱ����� ��
// cnt -> ���ݱ��� �� ����

void dfs(int v, int sum, int cnt) {
	if(v == N) {
		if (sum == S && cnt != 0) {
			ans++;// ���� ���� ++
		}
		return;
	}
	dfs(v + 1, sum + num[v], cnt + 1); //������
	dfs(v + 1, sum, cnt);  // ���þ���
}

int main() {
	S = -2;
	N = 5;

	dfs(0, 0, 0);

	cout << ans << endl;

	return 0;
}