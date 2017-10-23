#include <cstdio>
#include <vector>
using namespace std;

#define N 1111111

vector <int> vec[N];
int row[N], col[N], s[N];
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++) {
				scanf("%d", &s[i*m + j]);
				int x = s[i*m + j];
				vec[x].push_back(i);
				vec[x].push_back(j);
			}
		int ans = 0;
		for (int ii=0; ii<n; ii++) for (int jj=0; jj<m; jj++) {
			int i = s[ii*m+jj];
			if (vec[i].size()) {
				int row_max = 0;
				int col_max = 0;
				int row_count = 0;
				int col_count = 0;
				for (int j=0; j<vec[i].size(); j+=2) {
					if (++row[vec[i][j]] > row_max)
                        row_max = row[vec[i][j]], row_count = 0;
					if (row[vec[i][j]] == row_max)
					    row_count++;
					if (++col[vec[i][j+1]] > col_max)
					    col_max = col[vec[i][j+1]], col_count = 0;
					if (col[vec[i][j+1]] == col_max)
					    col_count++;
				}
				ans = max(ans, row_max + col_max-1);
				int intersections = row_count * col_count;
				for (int j=0; j<vec[i].size(); j+=2) {
					if (row[vec[i][j]] == row_max && col[vec[i][j+1]] == col_max) intersections--;
				}
				if (intersections) ans = max(ans, row_max + col_max);
				for (int j=0; j<vec[i].size(); j+=2) {
					--row[vec[i][j]]; --col[vec[i][j+1]];
				}
				vec[i].clear();
			}
		}
		printf("%d\n", ans);
	}
}
