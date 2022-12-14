/*
 Perfect number in C++
 C++による完全数の判定と個数を求めるプログラム
 (i). 入力を1つの整数(Nとする)にし、1以上N以下の範囲で考える場合
 https://github.com/neguseatama
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll POW(ll x,ll y){
    ll ret=1;
    for(ll i=1;i<=y;i++){
        ret*=x;
    }
    return ret;
}
vector<pair<ll,ll>> f(ll n){
    vector<pair<ll,ll>> v;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i!=0){
            continue;
        }else{
            ll cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            v.push_back(pair(i,cnt));
        }
    }
    if(n!=1){
        v.push_back(pair(n,1));
    }
    return v;
}
ll σ(ll n){
    if(n==1){
        return 1;
    }
    ll ans=1;
    vector<pair<ll,ll>> v=f(n);
    for(auto [i,j] : v){
        ll num=(POW(i,j+1)-1)/(i-1);
        ans*=num;
    }
    return ans;
}
int main(void){
    ll n,cnt=0;
    cin>>n;
    for(ll i=1;i<=n;i++){
        ll num=σ(i);
        if(num==i*2){
            cnt++;
        }
    }
    printf("1以上%lld以下の整数には、完全数が%lld個含まれています.\n",n,cnt);
    for(ll i=1;i<=n;i++){
        ll num=σ(i);
        if(num==i*2){
            cnt++;
            printf("%lld: 完全数です.\n",i);
        }else{
            printf("%lld: 完全数ではありません.\n",i);
        }
    }
    return 0; 
}
