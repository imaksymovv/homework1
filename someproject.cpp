#include <iostream>

struct answer {
	int number[3][721];
};

answer function() {
	int c = 12;
	int i = 0;
	answer r;
	do {
			do {
				r.number[2][i] = c % 10;
				r.number[1][i] = (c % 100) / 10;
				r.number[0][i] = c / 100;
				c++;
			} while (r.number[2][i] == r.number[1][i] || r.number[2][i] == r.number[0][i] || r.number[1][i] == r.number[0][i]);
		i++;
	} while (i < 720);
	return r;
}

 int main() {
	auto p = function();
	for (size_t i = 0; i < 720; i++) {
		std::cout << p.number[0][i] << p.number[1][i] << p.number[2][i] << std::endl;
	}
	return 0;
}