#include <iostream>

struct answer {
	int number[3][1];
};

void function(answer& r) {

	r.number[2][0]++;

	if (r.number[2][0] == 10) {
		r.number[1][0]++;
		r.number[2][0] = 0;
	}
	if (r.number[1][0] == 10) {
		r.number[0][0]++;
		r.number[1][0] = 0;
	}
	if (r.number[2][0] == r.number[1][0] || r.number[2][0] == r.number[0][0]) {
		do {
			r.number[2][0]++;
			if (r.number[2][0] == 10) {
				r.number[1][0]++;
				r.number[2][0] = 0;
			}
			if (r.number[1][0] == r.number[0][0]) {
				do {
					r.number[1][0]++;
				} while (r.number[1][0] == r.number[0][0]);
			}
			if (r.number[1][0] == 10) {
				r.number[0][0]++;
				r.number[1][0] = 0;
			}
		} while (r.number[2][0] == r.number[1][0] || r.number[2][0] == r.number[0][0]);
	}
}

int main() {
	bool c = false;
	answer p;
	p.number[0][0] = { 0 };
	p.number[1][0] = { 0 };
	p.number[2][0] = { -1 };
	do {
		function(p);
		if (p.number[0][0] != 10) {
			std::cout << p.number[0][0] << p.number[1][0] << p.number[2][0] << std::endl;
		}
		else {
			c = true;
		}

	} while (!c);
	return 0;
}