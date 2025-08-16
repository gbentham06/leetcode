int maximum69Number(int num) {
    int temp = num;
    int index = -1;
    int pos = 0;

    while (temp > 0) {
        if (temp % 10 == 6) index = pos;
        temp /= 10;
        pos++;
    }

    if (index == -1) 
        return num;
    else
        return num + 3 * ((int)pow(10, index));
}
