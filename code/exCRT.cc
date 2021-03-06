/*
 * Author:Simon
 * 功能: 模数可以不互质情况下，求解同余方程组。
 * 若返回-1则无解，否则返回最小非负整数解x，通解为x+i*M
 * 复杂度: O(nlog)
 */
int excrt(int mi[],int ai[],int n){ //扩展中国剩余定理
    int M=mi[1],ans=ai[1]; //x=ans+i*M，得到一个通解
    for(int i=2;i<=n;i++){
        int a=M,b=mi[i],c=((ai[i]-ans)%b+b)%b/*将c化为正数*/,x,y; //与第二个方程组成不定方程
        int gcd=exgcd(a,b,x,y); //通过扩展欧几里得解的一组特解（p,q)
        if(c%gcd!=0) return -1;
        a/=gcd,b/=gcd;
        (x*=(c/gcd)%b)%=b; x=(x+b)%b;
        ans+=x*M; //则 新同余方程的解x=ans+p*M
        M*=b; //所有模数的最小公倍数 (M*b)/gcd=M*(b/gcd)
        ans%=M; //最小整数解
    }
    return (ans+M)%M;
}