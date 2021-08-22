#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> primes;

bool isPrime(int num) {
	// 주어진 수가 소수인지 확인
	if (num == 2) return true;
	else if (num < 2) return false;
	else if (num % 2 == 0) return false;
	else {
		for (int i = 3; i <= sqrt(num); i++) {
			if (num % i == 0) return false;
		} // num의 제곱근보다 작은 모든 수로 나누었을 때, num이 나누어지지 않는다면 num은 소수이다.
		return true;
	}
}

void check(string numbers) {
	if (isPrime(stoi(numbers))) {
		primes.push_back(stoi(numbers));
	}
}

int solution(string numbers) {
	sort(numbers.begin(), numbers.end());
	int string_length = numbers.length();

	// 순열로 가능한 모든 수의 조합 확인
	do {
		for (int i = 1; i <= string_length; i++) {
			string temp = numbers.substr(0, i); // 앞에서부터 늘려가면서 확인 ex) "011" -> "0" "01" "011"
			check(temp);
		}
	} while (next_permutation(numbers.begin(), numbers.end()));

	sort(primes.begin(), primes.end());
	primes.erase(unique(primes.begin(), primes.end()), primes.end());

	return primes.size();
}