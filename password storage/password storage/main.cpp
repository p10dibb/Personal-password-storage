#include "PPs.h"


int main() {

	cout << "hello";
	PPS run;
	run.run();






}


int StoI(string h) {
	int ret = 0;
	for (int i = 0; i < h.length() - 1; i++) {
		ret += (h[i] - 48);
		ret = ret * 10;



	}
	ret += (h[h.size() - 1] - 48);
	return ret;
}