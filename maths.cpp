#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;
#define MAXN 1000100
long long fact[MAXN + 1];
long long invfact[MAXN + 1];

long long binpow(long long a , long long b){
    if(b == 0) return 1;
    if(b % 2 == 0){
        long long temp = binpow(a , b / 2);
        return temp * temp % mod;
    }
    return a * binpow(a , b - 1) % mod;
}

long long inv(long long x){
    return binpow(x , mod - 2);
}

long long nCr(long long n , long long r){
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[n-r] % mod * invfact[r] % mod;
}

void precompute(){
    fact[0] = 1;
    for(int i=1 ; i<=MAXN ; i++){
        fact[i] = fact[i-1] * i % mod;
    }
    invfact[MAXN] = inv(fact[MAXN]);
    for(int i=MAXN ; i>=1 ; i--){
        invfact[i-1] = invfact[i] * i % mod;
    }
}
int main(){
    precompute();
    cout << nCr(5, 2) << endl;
}