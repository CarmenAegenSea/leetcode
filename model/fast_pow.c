// 快速幂 & 快速乘 (Fast Exponentiation & Fast Multiplication)
// 用途: 快速计算 a^b % mod, 防止溢出的大数乘法
// 时间复杂度: O(log b)

typedef long long ll;

// 快速幂: a^b % mod
ll fast_pow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// 快速乘: a * b % mod (防直接乘溢出)
ll fast_mul(ll a, ll b, ll mod) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}
