---
title: Leading and Trailing
date: 2019-08-22 17:01:11
tags:
---

## Leading and Trailing

You are given two integers: **n** and **k**, your task is to find the most significant three digits, and least significant three digits of <img src="http://chart.googleapis.com/chart?cht=tx&chl= n^{k}" style="border:none;">


Input

Input starts with an integer **T (**≤ 1000), denoting the number of test cases.

Each case starts with a line containing two integers: **n (2 ≤ n < 231)** and **k (1 ≤ k ≤ 107)**.

Output

For each case, print the case number and the three leading digits (most significant) and three trailing digits (least significant). You can assume that the input is given such that **nk** contains at least six digits.

Sample Input

5

123456 1

123456 2

2 31

2 32

29 8751919

Sample Output

Case 1: 123 456

Case 2: 152 936

Case 3: 214 648

Case 4: 429 296

Case 5: 665 669

显然，后三位是直接对1000取余，然后找循环节，对幂次取余再从循环节中找即可，听说快速幂也可以，未作尝试

对于前三位，刚开始的想法是和后三位类似，但是我们保留前5位，用来避免进位带来的影响，但是第五组样例就WA掉了，可能是幂次太高的时候，进位的累积效应会影响到前三位，先贴出错误代码：

```c++
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
int a[MAXN],b[MAXN];
int m[(int)1e5+10];
int getTrail(int n , int k){
    memset(m,0,sizeof(m));
    int trail,loop,l;
    trail = n % 1000;
    b[1] = trail;
    for(int i = 2 ; i < 1003 ; i++){
        b[i] = b[i-1]*trail % 1000;
        if(m[b[i]]){
            loop = i-m[b[i]];
            l = m[b[i]];
            break;
        }
        m[b[i]] = i;
    }
    if(k < l) trail = b[k];
    else {
        k -= l - 1 ;
        k %= loop;
        trail = b[l-1+k];
    }
    return trail;
}
int lll5(long long n){
    while(n > 1e5) n/= 10;
    return n;
}
int lll3(long long n){
    while(n > 1e3) n/= 10;
    return n;
}
int getLead(int n,int k){
    int loop,l;
    memset(m,0, sizeof(m));
    long long lead = lll5(n);
    long long last = lll5(n);
    a[1] = lll3(lead);
    for(int i = 2; i < 1e3+5 ; i++){
        a[i] = last = lll5(last * lead);
        if(m[last]){
            loop = i - m[last];
            l = i;
            break;
        }
        m[last] = i;
    }
    if(k < l) lead = a[k];
    else {
        k -= l - 1 ;
        k %= loop;
        lead = a[l-1+k];
    }
    return lll3(lead);
}
int main(){
    int T,Case,lead,trail;
    int n,k;
    cin >> T;
    while(Case < T){
        cin >> n >> k;
        if(k == 0){
            trail = 1;
            lead = 1;
        }else {
            trail = getTrail(n, k);
            lead = getLead(n, k);
        }
        cout <<"Case "<<++Case <<": "<< lead <<" " <<trail << endl;
    }
}
```

后来考虑到使用换底公式，可以比较快的得到正确的答案

<img src="http://chart.googleapis.com/chart?cht=tx&chl= x = lg (n^{k})=klg(n)" style="border:none;">

<img src="http://chart.googleapis.com/chart?cht=tx&chl= x = 10^{x} = 10^{klg(n)}" style="border:none;">

把x的小数部分取出，前三位小数即为所求，取出小数部分可以直接用浮点数减去取整之后的数即可即：

```c++
x = k*log(n);
x = x-(int)x;
x *= 1000;
```

提交后又WA了，可能是尾巴那一部分有问题，直接改用快速幂

AC代码：

```c++
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
int quickpow(long long n,long long k){
    n %= 1000;
    long long ans = 1;
    while(k){
        if(k&1){
            ans *= n;
            ans %= 1000;
        }
        n *= n;
        n %= 1000;
        k >>= 1;
    }
    return ans;
}
int main(){
    int T,Case,lead;
    long long n,k;
    cin >> T;
    while(Case < T){
        cin >> n >> k;
        double x = log10(n) *k;
        x -= (int)x;
        lead = pow(10,x+2.0);
        cout <<"Case "<<++Case <<": "<< lead <<" " ;
        printf("%03d\n",quickpow(n,k));
    }
}
```

注意后三位可能是0开头的情况，因此WA了两发

