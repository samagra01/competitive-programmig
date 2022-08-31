const int N = 1e5 + 10;
ll fact[N];
ll facti[N];

void pre() {
    fact[0] = fact[1] = 1;
    facti[0] = facti[1] = binpomo(fact[0], MOD - 2, MOD);

    fo(i, 2, 1e5) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
        facti[i] = binpomo(fact[i], MOD - 2, MOD);
    }
}
