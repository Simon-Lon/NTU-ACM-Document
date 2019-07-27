/*
Author: Simon
其实顾名思义，素数就是因子只有两个的数，那么反素数，就是因子最多的数（并且因子个数相同的时候值最小），所以反素数是相对于一个集合来说的。
反素数的特点。
1. 反素数肯定是从2开始的连续素数的幂次形式的乘积。
2. 数值小的素数的幂次大于等于数值大的素数的幂次，即
    e1>=e2>=e3>=……>=ek
*/
int a[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53}
//给定因子数n，求满足因子数个数等于n的最小数。
void dfs(int dep/*第dep个素数*/,int sum/*当前的数*/,int num/*因子个数*/,int up/*上个素数的幂*/){
    if(dep>=16||num>n) return ;
    if(num==n){
        ans=min(ans,sum);
        return ;
    }
    for(int i=1;i<=up;i++){ //由性质2可知，数值大的素数的幂次小于等于数值小的素数的幂次
        if(sum*fpow(a[dep],i)>ans) break;
        dfs(dep+1,sum*fpow(a[dep],i),num*(i+1),i);
    }
}
//求小于等于n的因子数最多的数。与上面做法相同，只是dfs结束条件改一下。