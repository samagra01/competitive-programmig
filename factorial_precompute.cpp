typedef long long int ll;

const int MOD = 1e9 + 7;
const int N = 200000 + 10;
ll fact[N];
ll ifact[N];
ll binpo(ll a, ll b) {
	if (b == 0) return 1;
	ll res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		b >>= 1;
	}
	return res;
}
void pre() {
	fact[0] = fact[1] = 1;
	ifact[0] = ifact[1] = binpo(1, MOD - 2);
	for (int i = 2; i <= 200000; i++) {
		fact[i] = i * fact[i - 1]; fact[i] %= MOD;
		ifact[i] = binpo(fact[i], MOD - 2);
	}

}
ll NCR(ll i, ll j) {
	if (i < j) {
		return 0;
	}
	if (j == 0)return 1;
	ll ans = 1;
	ans *= fact[i]; ans %= MOD;
	ans *= ifact[j]; ans %= MOD;
	ans *= ifact[i - j]; ans %= MOD;
	return ans;
}
