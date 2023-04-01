#include <iostream>
#include <cmath>
#include <set>

using namespace std;

bool isPrime(long long n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (long long i = 3; i <= sqrt(n); i += 2) {
		if (n % i == 0) return false;
	}
	return true;
}


int main(void) {
	long long min; // 1<= min <= 1,000,000,000,000
	long long max; //	min <= max <= min + 1,000,000
	long long ans;
	set<long long> prime;
	set<long long> multiple_of_double_prime;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> min >> max;

	ans = max - min + 1;

	long long target_range = (long long)sqrt(max);

	for (long long i = 2; i <= target_range; i++) {
		if (isPrime(i)) prime.insert(i);
	}

	// prime begin to end
	for (set<long long>::iterator iter = prime.begin(); iter != prime.end(); iter++) {
		long long max_range = (long long)floor(max / pow(*iter, 2));
		long long min_range = (long long)ceil(min / pow(*iter, 2));
		for (long long i = min_range; i <= max_range; i++) {
			multiple_of_double_prime.insert(i * (long long)(pow(*iter, 2)));
		}
	}

	ans -= multiple_of_double_prime.size();

	cout << ans << endl;

	return 0;
}