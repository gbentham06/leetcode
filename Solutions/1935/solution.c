int canBeTypedWords(char* text, char* brokenLetters) {
    int count = 0;
    char* word = strtok(text, " ");
    while (word != NULL) {
        bool canType = true;
        for (int i = 0; brokenLetters[i] != '\0'; i++) {
            if (strchr(word, brokenLetters[i]) != NULL) {
                canType = false;
                break;
            }
        }
        if (canType) count++;
        word = strtok(NULL, " ");
    }
    return count;
}
