char* largestGoodInteger(char* num) {
    int n = strlen(num);
    if (n < 3) return strdup("");
    char maxnum = 0;
    for (int i = 2; i < n; i++){
        if(num[i] == num[i-1] && num[i] == num[i-2]){
            maxnum = (maxnum > num[i]) ? maxnum : num[i];
        }
    }
    if (maxnum == 0) return strdup("");
    char *ans = malloc(4);
    ans[0] = maxnum;
    ans[1] = maxnum;
    ans[2] = maxnum;
    ans[3] = '\0';
    return ans;
}
