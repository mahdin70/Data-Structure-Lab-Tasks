#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long

const int N = 2000006;
const ULL hs = 3797;

ULL F[N], H[N];
char in[N];
char check[N];
ULL check_val=0;
int n;

ULL seg(int x, int y) {
    return H[y] - F[y - x + 1] * H[x - 1];
}
void needleHaysack(){
    for(int i=1;i<=strlen(in+1);i++){
            if(seg(i,i+strlen(check+1)-1)==check_val){
                cout<<"index found at "<<i-1<<'\n';
                return;
            }
    }
    cout<<"index could not be found";

}
int main()
{
    F[0] = 1;
    for(int i = 1; i < N; i++)
                F[i] = F[i - 1] * hs; // keeping the powers pre-calculated
    scanf("%s", in + 1); // 1 indexing
    scanf("%s",check+1);
    n = strlen(in + 1);
    H[0] = 0;
    for(int i = 1; i <= n; i++)
        H[i] = H[i - 1] * hs + in[i];
    for(int i=1;i<=strlen(check+1);i++){
        check_val=check_val*hs+check[i];
    }
    needleHaysack();
    return 0;
}

