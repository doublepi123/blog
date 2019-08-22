---
title: Goldbach`s Conjecture
date: 2019-08-22 10:35:26
tags:
---

## Goldbach`s Conjecture



Goldbach's conjecture is one of the oldest unsolved problems in number theory and in all of mathematics. It states:

Every even integer, greater than 2, can be expressed as the sum of two primes [1].

Now your task is to check whether this conjecture holds for integers up to **107**.

​              

Input

​         

Input starts with an integer **T (****≤ 300)**, denoting the number of test cases.

Each case starts with a line containing an integer **n (4 ≤ n ≤ 107, n is even)**.

​              

Output

​         

For each case, print the case number and the number of ways you can express **n** as sum of two primes. To be more specific, we want to find the number of **(a, b)** where

1)      Both **a** and **b** are prime

2)      **a + b = n**

3)      **a ≤ b**

​              

Sample Input

​         

2

6

4

​              

Sample Output

​         

Case 1: 1

Case 2: 1

​              

Note

​         

1. An integer is said to be prime, if it is divisible by exactly two different integers. First few primes are 2, 3, 5, 7, 11, 13, ...

第一遍没有看懂题目，先送一发WA，后来发现就是简单的打表就行了，MLE。。。。。没注意内存的限制，因为只有上32MB内存，所以1e7的int显然是开不了的，只好省省内存，写长点代码

代码如下：

```c++
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7;
int prime[(int)1e6];
bool notprime[MAXN];//值为false 表示素数，值为true 表示非素数
void init(){
    memset(notprime,false,sizeof(notprime));
    notprime[0]=notprime[1]=true;
    for(int i=2;i<MAXN;i++)
        if(!notprime[i]){
        if(i>MAXN/i)continue;//防止后面i*i 溢出(或者i,j 用lon
        //直接从i*i 开始就可以，小于i 倍的已经筛选过了, 注意是j+=i
        for(int j=i*i;j<MAXN;j+=i)
            notprime[j]=true;
        }
}
int main(){
    init();
    int T,Case,n;
    for(int i = 2 ; i < MAXN ; i++){
        if(!notprime[i]) prime[++prime[0]] = i;
    }
    cin >> T;
    while(Case < T){
        int cnt = 0;
        cin >> n;
        for(int i = 1 ; i <= prime[0] ; i++){
            //cout <<i << " " << prime[i] <<" "<< p[n-prime[i]]<<endl;
            if(prime[i] > n/2) break;
            if(!notprime[n-prime[i]]) cnt++;
        }
        cout <<"Case "<<++Case <<": "<< cnt <<endl;
    }
}
```

