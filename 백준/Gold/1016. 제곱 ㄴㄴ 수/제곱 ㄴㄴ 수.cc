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
	long long max; // min <= max <= min + 1,000,000
	long long ans;
	set<long long> prime;
	set<long long> multiple_of_double_prime;

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> min >> max;

	// initialize ans for entire numbers of range(min-max)
	ans = max - min + 1;

	/* logic : 
		제곱수의 배수인지 판단하기 위해서는, 소수들의 제곱수의 배수인지만 판단하면 된다. (소수가 아닌 수의 제곱수는 결국 소수의 제곱수이므로)
		max보다 작은 소수들을 구하고, 범위 내(min-max)에서 그 소수들로 이루어진 제곱수를 multiple_of_double_prime set에 저장한다.
		전체 개수에서 해당 set의 개수를 빼주면 정답이 됨.
	*/

	// prime 2 to sqrt(max)
	long long target_range = (long long)sqrt(max);

	for (long long i = 2; i <= target_range; i++) {
		if (isPrime(i)) prime.insert(i);
	}

	// find and insert the multiples of double of prime in the range(min-max)
	for (set<long long>::iterator iter = prime.begin(); iter != prime.end(); iter++) {
		long long max_range = (long long)floor(max / pow(*iter, 2));
		long long min_range = (long long)ceil(min / pow(*iter, 2));
		for (long long i = min_range; i <= max_range; i++) {
			multiple_of_double_prime.insert(i * (long long)(pow(*iter, 2)));
		}
	}

	// subtract the size of set from ans
	ans -= multiple_of_double_prime.size();

	cout << ans << endl;

	return 0;
}