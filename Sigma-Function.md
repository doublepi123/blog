---
title: Sigma Function
date: 2019-08-22 10:35:26
tags:
---

## Sigma Function

Sigma function is an interesting function in Number Theory. It is denoted by the Greek letter Sigma (σ). This function actually denotes the sum of all divisors of a number. For example σ(24) = 1+2+3+4+6+8+12+24=60. Sigma of small numbers is easy to find but for large numbers it is very difficult to find in a straight forward way. But mathematicians have discovered a formula to find sigma. If the prime power decomposition of an integer is

![img](https://vj.ti12z.cn/a2ab9ccfa8dc3527ba82e70d2d8db6bf?v=1566350558)

Then we can write,

![img](https://vj.ti12z.cn/1510021ce5adea20ba5ebd2baa22e212?v=1566350558)

For some **n** the value of **σ(n)** is odd and for others it is even. Given a value **n**, you will have to find how many integers from **1** to **n** have **even** value of **σ**.Input

Input starts with an integer **T (****≤ 100)**, denoting the number of test cases.

Each case starts with a line containing an integer **n (1 ≤ n ≤ 1012)**.Output

For each case, print the case number and the result.Sample Input

4

3

10

100

1000Sample Output

Case 1: 1

Case 2: 5

Case 3: 83

Case 4: 947

先暴力打表，找规律，发现F(x) = x - sqrt(x)- sqrt(x/2)

直接变成o（1）的题目

注意long long ，因此wa了三发

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long T,n;
    cin >> T;
    int Case = 0;
    while(T--){
        cin >> n;
        long long  ans = n;
        ans -= (long long) (sqrt(n));
        ans -= (long long) (sqrt(n/2));
        cout <<"Case "<<++Case<<": "<< ans << endl;
    }
}
```