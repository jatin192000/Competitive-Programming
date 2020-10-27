#include <bits/stdc++.h>
#define ll long long
#define ee 1000000007
#define pb push_back
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<bool> segSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }
    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
int main() {
	fio;
	ll t;
	cin >> t;
	while(t--) {
		ll l, r;
		cin >> l >> r;
		vector<bool> primes = segSieve(l, r);
		for(ll i=0; i < primes.size(); i++) {
			if(primes[i])
				cout << l + i << "\n";
		}
		cout << "\n";
	}
}
