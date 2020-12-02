#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 256;



int main() {
    char str[MAXN];
    printf("> Enter string: ");
    fgets(str, MAXN, stdin);


    char words[MAXN];
    memset(words, '\0', MAXN);
    char *word = strtok(str, " .");
    while (word != NULL) {
        strcat(words, word);
        strcat(words, " ");
        word = strtok(NULL, " .\n");
    }

    puts(words);

    char *lastWord = strrchr(str, ' ');
    lastWord = strtok(lastWord, " \n");
    printf("Last word: %s\n", lastWord);

    char *currentWord = strtok(words, " ");
    while (currentWord != NULL) {
        if (strcmp(lastWord, currentWord) != 0)
            printf("%s ", currentWord);
        currentWord = strtok (NULL, " .");
    }

    return 0;
}
