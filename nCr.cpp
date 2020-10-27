long long power(long long a,long long b, long long mod) {
    long long ans = 1;
    while(b != 0){
        if(b&1) 
            ans=(ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans % mod;
}

long long modInv(long long A, long long M) {
    return power(A, M - 2, M);
}

long long nCr(long long n, long long k, long long mod) { 
    long long res = 1;
    if (k > n - k) 
        k = n - k;
    for (long long i = 0; i < k; ++i) { 
        res = ((res % mod) * ((n - i) % mod)) % mod; 
        res = ((res % mod) * (modInv(i + 1, mod) % mod)) % mod;
    }
    return res;
}
