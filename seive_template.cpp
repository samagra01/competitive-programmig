
const int MAX_SIZE = 2800001;vector<int>isprime(MAX_SIZE , true);vector<int> idx(MAX_SIZE);vector<int> prime;vector<int>SPF(MAX_SIZE);
void manipulated_seive(int N) {  isprime[0] = isprime[1] = false ; for (int i = 2; i < N ; i++) {  if (isprime[i]) { prime.push_back(i);     SPF[i] = i;  }  for (int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {  isprime[i * prime[j]] = false;   SPF[i * prime[j]] = prime[j] ; }  }   for (int i = 0; i < (int)prime.size(); i++) { idx[prime[i]] = i + 1; }}
vector<ll> primeFactors(ll n) { vector<ll> factors; while (n > 1){ factors.push_back(SPF[n]); n /= SPF[n]; } return factors;}
 // complete seive in short is above //                            
const int MAX_SIZE = 2800001;
vector<int>isprime(MAX_SIZE , true);
vector<int> idx(MAX_SIZE);
vector<int> prime;
vector<int>SPF(MAX_SIZE);

void manipulated_seive(int N) {
    isprime[0] = isprime[1] = false ;
    for (int i = 2; i < N ; i++) {
        if (isprime[i]) {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
            isprime[i * prime[j]] = false;
            SPF[i * prime[j]] = prime[j] ;
        }
    }
    for (int i = 0; i < (int)prime.size(); i++) {
        idx[prime[i]] = i + 1;
    }
}
// prime factors in log n using seive // up 1e6
vector<int> primeFactors(int n) {
    vector<int> factors;
    while (n > 1) {
        factors.push_back(SPF[n]);
        n /= SPF[n];
    }
    return factors;
}
// same with ll above uses int // better to use above one 
vector<ll> primeFactors(ll n) {
    vector<ll> factors;
    while (n > 1) {
        factors.push_back(SPF[n]);
        n /= SPF[n];
    }
    return factors;
}
// prime factors in root  n // can work for any range // 
vector<ll> primeFactors(ll n) {
    vector<ll> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 2) factors.push_back(n);
    return factors;
}
