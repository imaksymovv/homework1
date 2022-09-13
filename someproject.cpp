#include <iostream>

struct answer {
	int number[3][721];
};

answer function() {
	int c = 0;
	answer r;
	r.number[0][0] = { 0 };
	r.number[1][0] = { 0 };
	r.number[2][0] = { -1 };
	do {
		r.number[2][c]++;

		if (r.number[2][c] == 10) {
			r.number[1][c]++;
			r.number[2][c] = 0;
		}
		if (r.number[1][c] == 10) {
			r.number[0][c]++;
			r.number[1][c] = 0;
		}
		while (r.number[2][c] == r.number[1][c] || r.number[2][c] == r.number[0][c]) {
			r.number[2][c]++;
			if (r.number[2][c] == 10) {
				r.number[1][c]++;
				r.number[2][c] = 0;
			}
			if (r.number[1][c] == r.number[0][c]) {
				do {
					r.number[1][c]++;
				} while (r.number[1][c] == r.number[0][c]);
			}
			if (r.number[1][c] == 10) {
				r.number[0][c]++;
				r.number[1][c] = 0;
			}
		}
		if (c < 720) {
			r.number[2][c + 1] = r.number[2][c];
			r.number[1][c + 1] = r.number[1][c];
			r.number[0][c + 1] = r.number[0][c];
			c++;
		}

	} while (c < 720);
	return r;
}

int main() {
	auto p = function();
	for (size_t i = 0; i < 720; i++) {
		std::cout << p.number[0][i] << p.number[1][i] << p.number[2][i] << std::endl;
	}
	return 0;
}