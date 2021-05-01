#include <map>
#include <cstdlib>
#include <iostream>
using namespace std;

unsigned long fastFib(int n) {

	//static keyword keeps data available for entire life of the program
	static map<unsigned long, unsigned long> memoized = { {0, 0}, {1, 1} };
	
	//lookup the given n value
	auto lookup = memoized.find(n);

	if (lookup != memoized.end()) {
		return lookup->second;
	} else {
		memoized[n] = fastFib(n - 1) + fastFib(n - 2);
		std::cout<<memoized[n]<<std::endl;
		return memoized[n];
	}
}

int main(int argc, char** argv) {
	
	int n = atoi(argv[1]);
	
	fastFib(n);
	
}
