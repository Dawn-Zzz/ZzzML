#define pb push_back
#define ll long long
const ll mod = 10e9 + 7;
ios_base::sync_with_stdio(false);
cin.tie(NULL);                    
cout.tie(NULL);

ll gcd(ll m, ll n)
{
    return n == 0 ? m : gcd(n, m % n);
}

ll lcm(ll m, ll n)
{
    return m * n / gcd(m, n);
}

bool prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

ll power(ll a, ll b)
{
    ll ans = 1ll;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        b = b >> 1;
        a = (a * a) % mod;
    }
    return (ans % mod);
}

ll fact[1000001];
void cal_fact()
{
    ll ans = 1ll;
    fact[0] = 1ll;
    for (ll i = 1; i <= 1000000; i++)
    {
        ans = (ans * i) % mod;
        fact[i] = ans;
    }
}

ll bin(ll a, ll b)
{
    ll up = fact[a] % mod;
    ll down = (fact[b] * fact[a - b]) % mod;

    return (up * power(down, mod - 2)) % mod;
}
