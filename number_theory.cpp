#include<bits/stdc++.h>
using namespace std;

#define MAXN 1000000

// O(sqrt(n))
vector<long long>getdivisors(long long n){
    vector<long long> v;
    for(int i=1 ; i*i <= n ; i++){
        if(n % i == 0){
            v.push_back(i);
            if(n/i != i)
                v.push_back(n / i);
        }
    }
    return v;
}

// O(nlog(log n))
vector<bool>getallprimes(){
    vector<bool> isprime(MAXN + 1);
    for (int i = 2; i<=MAXN ; i++)
        isprime[i] = 1;
    for (int i = 2; i <= MAXN; i++){
        if(isprime[i]){
            for (int j = 2*i; j <= MAXN; j+=i){
                isprime[j] = 0;
            }
        }
    }
    return isprime;
}

// prime factorization -
vector<long long> spf(MAXN + 1);
// spf -> smallest prime factor
void pre(){
    for (int i = 2; i <= MAXN; i++){
        spf[i] = i;
    }
    for (int i = 2; i <= MAXN; i++){
        if(spf[i] == i){
            for (int j = 2 * i; j <= MAXN; j+=i){
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}
vector<long long> getspf(long long num){
    vector<long long> v;
    while(num > 1){
        v.push_back(spf[num]);
        num = num / spf[num];
    }
    return v;
}

int main(){
    pre();

    long long n = 60;

    vector<long long> v = getdivisors(n);

    for(auto x : v)
        cout << x << " ";

    cout << '\n';

    vector<long long> factors = getspf(n);

    for(auto x : factors)
        cout << x << " ";
}