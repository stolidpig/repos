#include "../../std_lib_facilities.h"

int main() {
	char ch = 'a';
	int i = 0;
	while (i < 26) {
		cout << char('a' + i) << "\t" << ch + i << "\n";
		++i;
	}
}