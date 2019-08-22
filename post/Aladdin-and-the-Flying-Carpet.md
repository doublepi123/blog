---
title: Aladdin and the Flying Carpet
date: 2019-08-22 10:33:46
tags:
---

## Aladdin and the Flying Carpet

It's said that Aladdin had to solve seven mysteries before getting the Magical Lamp which summons a powerful Genie. Here we are concerned about the first mystery.

Aladdin was about to enter to a magical cave, led by the evil sorcerer who disguised himself as Aladdin's uncle, found a strange magical flying carpet at the entrance. There were some strange creatures guarding the entrance of the cave. Aladdin could run, but he knew that there was a high chance of getting caught. So, he decided to use the magical flying carpet. The carpet was rectangular shaped, but not square shaped. Aladdin took the carpet and with the help of it he passed the entrance.

Now you are given the area of the carpet and the length of the minimum possible side of the carpet, your task is to find how many types of carpets are possible. For example, the area of the carpet 12, and the minimum possible side of the carpet is 2, then there can be two types of carpets and their sides are: {2, 6} and {3, 4}.

Input

Input starts with an integer **T** (≤ 4000), denoting the number of test cases.

Each case starts with a line containing two integers: **a** **b** **(1 ≤ b ≤ a ≤ 1012)** where **a** denotes the area of the carpet and **b** denotes the minimum possible side of the carpet.

Output

For each case, print the case number and the number of possible carpets.

Sample Input

2

10 2

12 2

Sample Output

Case 1: 1

Case 2: 2



其实题目很简单，说的是给一个数，求比最小的因数大的因数对有多少对，很简单，利用唯一分解定理，对输入的数进行素因式分解，然后求所有的因数的个数，除以二就是因数对的个数，再暴力求出[1,b]之间的所有的因数，减去即可



注意当b > sqrt(a)的时候，直接返回0即可，否则极有可能在后面的[0,b]的暴力中TLE（血与泪的教训）



AC代码如下

```c++
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int prime[MAXN+1];
void getPrime(){
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++){
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++){
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
long long factor[100][2];
int fatCnt;
int getFactors(long long x){
    fatCnt=0;
    long long tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++){
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0){
            factor[fatCnt][0]=prime[i];
            while(tmp%prime[i]==0){
                factor[fatCnt][1]++;
                tmp/=prime[i];
            }
            fatCnt++;
        }
    }
    if(tmp!=1){
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;
}
long long ans;
long long a,b;
int cnt;
int main(){
    getPrime();
    int T,t,Case = 0;
    long long ans;
    cin >> T;
    while(T--){
        cnt = 0;
        ans = 1;
        cin >> a >> b;
        if(b > sqrt(a)) {
            cout <<"Case "<<++Case<<": "<< 0<< endl;
            continue;
        }
        getFactors(a);
        for(int i = 0 ; i < fatCnt ; i++){
            ans *= factor[i][1]+1;
        }
        ans /= 2;
        for(int i = 1 ; i < b ; i++)
            if(a%i == 0) ans--;
        cout <<"Case "<<++Case<<": "<< ans<< endl;
    }
}
```

