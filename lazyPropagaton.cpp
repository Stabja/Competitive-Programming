#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define mid ((from + to) / 2)
#define left (2 * idx + 1)
#define right (2 * idx + 2)

struct Element {
	int sum;
	int mul;
	int add;
	Element() {
		sum = 0;
		mul = 1;
		add = 0;
	}
};

Element tree[4 * MAXN];
bool lazy[4 * MAXN];
int arr[MAXN];
const int mod = 1000000007;

void build(int idx, int from, int to) {
	if (from == to) {
		tree[idx].sum = arr[from];
		return;
	}
	build(left, from, mid);
	build(right, mid + 1, to);
	tree[idx].sum = (tree[left].sum + tree[right].sum) % mod;
}

void updateAdd(int idx, int from, int to, int a, int b, int v) {
	if (lazy[idx]) {
		tree[idx].sum = (1LL * tree[idx].sum * tree[idx].mul + 1LL * tree[idx].add * (to - from + 1)) % mod;
		if (from != to) {
			lazy[left] = lazy[right] = true;
			tree[left].mul = (1LL * tree[left].mul * tree[idx].mul) % mod;
			tree[right].mul = (1LL * tree[right].mul * tree[idx].mul) % mod;
			tree[left].add = (1LL * tree[left].add * tree[idx].mul + tree[idx].add) % mod;
			tree[right].add = (1LL * tree[right].add * tree[idx].mul + tree[idx].add) % mod;
		}
		lazy[idx] = false;
		tree[idx].mul = 1;
		tree[idx].add = 0;
	}
	if (a > to || b < from || from > to) return;
	if (a <= from && b >= to) {
		tree[idx].sum = (1LL * v * (to - from + 1) + tree[idx].sum) % mod;
		if (from != to) {
			lazy[left] = lazy[right] = true;
			tree[left].add = (tree[left].add + v) % mod;
			tree[right].add = (tree[right].add + v) % mod;
		}
		return;
	}
	updateAdd(left, from, mid, a, b, v);
	updateAdd(right, mid + 1, to, a, b, v);
	tree[idx].sum = (tree[left].sum + tree[right].sum) % mod;
}

void updateMul(int idx, int from, int to, int a, int b, int v) {
	if (lazy[idx]) {
		tree[idx].sum = (1LL * tree[idx].sum * tree[idx].mul + 1LL * tree[idx].add * (to - from + 1)) % mod;
		if (from != to) {
			lazy[left] = lazy[right] = true;
			tree[left].mul = (1LL * tree[left].mul * tree[idx].mul) % mod;
			tree[right].mul = (1LL * tree[right].mul * tree[idx].mul) % mod;
			tree[left].add = (1LL * tree[left].add * tree[idx].mul + tree[idx].add) % mod;
			tree[right].add = (1LL * tree[right].add * tree[idx].mul + tree[idx].add) % mod;
		}
		lazy[idx] = false;
		tree[idx].mul = 1;
		tree[idx].add = 0;
	}
	if (a > to || b < from || from > to) return;
	if (a <= from && b >= to) {
		tree[idx].sum = (1LL * v * tree[idx].sum) % mod;
		if (from != to) {
			lazy[left] = lazy[right] = true;
			tree[left].mul = (1LL * tree[left].mul * v) % mod;
			tree[right].mul = (1LL * tree[right].mul * v) % mod;
			tree[left].add = (1LL * tree[left].add * v) % mod;
			tree[right].add = (1LL * tree[right].add * v) % mod;
		}
		return;
	}
	updateMul(left, from, mid, a, b, v);
	updateMul(right, mid + 1, to, a, b, v);
	tree[idx].sum = (tree[left].sum + tree[right].sum) % mod;
}

void updateSet(int idx, int from, int to, int a, int b, int v) {
	if (lazy[idx]) {
		tree[idx].sum = (1LL * tree[idx].sum * tree[idx].mul + 1LL * tree[idx].add * (to - from + 1)) % mod;
		if (from != to) {
			lazy[left] = lazy[right] = true;
			tree[left].mul = (1LL * tree[left].mul * tree[idx].mul) % mod;
			tree[right].mul = (1LL * tree[right].mul * tree[idx].mul) % mod;
			tree[left].add = (1LL * tree[left].add * tree[idx].mul + tree[idx].add) % mod;
			tree[right].add = (1LL * tree[right].add * tree[idx].mul + tree[idx].add) % mod;
		}
		lazy[idx] = false;
		tree[idx].mul = 1;
		tree[idx].add = 0;
	}
	if (a > to || b < from || from > to) return;
	if (a <= from && b >= to) {
		tree[idx].sum = (1LL * v * (to - from + 1)) % mod;
		if (from != to) {
			lazy[left] = lazy[right] = true;
			tree[left].mul = tree[right].mul = 0;
			tree[left].add = tree[right].add = v;
		}
		return;
	}
	updateSet(left, from, mid, a, b, v);
	updateSet(right, mid + 1, to, a, b, v);
	tree[idx].sum = (tree[left].sum + tree[right].sum) % mod;
}

int query(int idx, int from, int to, int a, int b) {
	if (lazy[idx]) {
		tree[idx].sum = (1LL * tree[idx].sum * tree[idx].mul + 1LL * tree[idx].add * (to - from + 1)) % mod;
		if (from != to) {
			lazy[left] = lazy[right] = true;
			tree[left].mul = (1LL * tree[left].mul * tree[idx].mul) % mod;
			tree[right].mul = (1LL * tree[right].mul * tree[idx].mul) % mod;
			tree[left].add = (1LL * tree[left].add * tree[idx].mul + tree[idx].add) % mod;
			tree[right].add = (1LL * tree[right].add * tree[idx].mul + tree[idx].add) % mod;
		}
		lazy[idx] = false;
		tree[idx].mul = 1;
		tree[idx].add = 0;
	}
	if (a > to || b < from || from > to) return 0;
	if (a <= from && b >= to) return tree[idx].sum;
	int resL = query(left, from, mid, a, b);
	int resR = query(right, mid + 1, to, a, b);
	return (resL + resR) % mod;
}

int main() {
	int N, Q, T, L, R, V;
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", arr + i);
	}
	build(1, 1, N);
	memset(lazy, false, sizeof lazy);
	while (Q--) {
		scanf("%d %d %d", &T, &L, &R);
		if (T == 1) {
			scanf("%d", &V);
			updateAdd(1, 1, N, L, R, V);
		} else if (T == 2) {
			scanf("%d", &V);
			updateMul(1, 1, N, L, R, V);
		} else if (T == 3) {
			scanf("%d", &V);
			updateSet(1, 1, N, L, R, V);
		} else {
			printf("%d\n", query(1, 1, N, L, R));
		}
	}
	return 0;
}
