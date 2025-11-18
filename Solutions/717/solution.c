bool isOneBitCharacter(int* bits, int n) {
    int i=0;
    for(; i<n-1; i++){
        i+=(bits[i]==1);
    }
    return i==n-1;
}