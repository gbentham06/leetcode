#pragma GCC optimize("O3")
int totalMoney(int n) {
    div_t x=div(n, 7);
    int q=x.quot, r=x.rem;
    return 28*q+7*q*(q-1)/2+(2*q+r+1)*r/2;
}