#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector

int check(int a, int b)
{
	if (a == b || a - b == 1 || a - b == - 1) return 1;
	else return 0;
}

int main(void)
{
	while(1) {
		int n;
		cin >> n;
		if (!n) break;
		vec<int> w(n);
		rep(i, n) cin >> w[i];

		vec<vec<int>> dp(n, vec<int>(n, 0));
		rep(i, n - 1) dp[i + 1][i] = 1;
		for (int j = 1; j < n; j ++) {
			rep(i, n - j) {
				if (check(w[i], w[i + j])) dp[i][i + j] += dp[i + 1][i + j - 1];
				for (int k = i + 1; k < i + j - 1; k++) dp[i][i + j] += dp[i][k] * dp[k + 1][i + j];
				// if (i < n - 2 && check(w[i], w[i + 1])) dp[i][i + j] += dp[i + 2][i + j];
				// if (j > 2 && check(w[i + j], w[i + j - 1])) dp[i][i + j] += dp[i][i + j - 2];
			}
		}
		// rep(j, n - 1) rep(i, n - j) {
		// 	for (int k = i; k < i + j; k++) {
		// 		dp[i][i + j] += dp[i][k] * dp[k + 1][i + j];
		// 	}
		// }

		rep(i, n) rep(j, n) if (dp[i][j]) dp[i][j] = j - i + 1;

		vec<int> ans(n, 0);

		for (int i = n - 1; i >= 0; i--) {
			int keep = dp[i][n - 1];
			for (int j = i + 1; j < n; j++) {
				keep = max(keep, dp[i][j - 1] + ans[j]);
			}
			ans[i] = keep;
		}
		cout << ans[0] << endl;
	}
	return 0;
}
	
