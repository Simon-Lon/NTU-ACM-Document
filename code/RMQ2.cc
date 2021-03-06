//author: wavator
#include <algorithm>
#include <vector>

template <class T>
struct RMQ {
	std::vector<std::vector<T> > rmq;
	// vector<T> rmq[20]; or T[100002][20] if need speed
	//T kInf = numeric_limits<T>::max(); // if need return a value when the interval fake
	void init(const std::vector<T>& a) { // 0 base
		int n = (int)a.size(), base = 1, depth = 1;
		while (base < n)
			base <<= 1, ++depth;
		rmq.assign((unsigned)depth, a);
		for (int i = 0; i < depth - 1; ++i)
			for (int j = 0; j < n; ++j) {
				rmq[i + 1][j] = std::min(rmq[i][j], rmq[i][std::min(n - 1, j + (1 << i))]);
			}
	}
	T q(int l, int r) { // [l, r)
		if(l>r)return 0x3f3f3f3f;
		int dep = 31 - __builtin_clz(r - l); // log(b - a)
		return min(rmq[dep][l], rmq[dep][r - (1 << dep)]);
	}
};

