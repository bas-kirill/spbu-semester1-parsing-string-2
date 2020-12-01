#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 10'000;



int main() {
    char str[MAXN];
    printf("> Enter string: ");
    fgets(str, MAXN, stdin);


    int idx = 0;
    bool word = false;
    int n = strlen(str);
    for (int i = 0; i < n; ++i) {
        if (str[i] == ' ') {
            if (word)
                str[idx++] = ' ';
            word = false;
        } else {
            str[idx++] = str[i];
            if (str[i] == '.') {
                word = false;
            } else {
                word = true;
            }
        }
    }

    str[idx - 1] = '\0';
    n = strlen(str);
    for (int i = 0; i < n; ++i) {
        if (str[i] == ' ' && str[i + 1] == '.') {
            str[i] = '.';
            str[i + 1] = ' ';
        }
    }

    char *lastWord = strrchr(str, ' ');
    lastWord = strtok(lastWord, " \n");
    printf("Last word: %s\n", lastWord);

    char *currentWord = strtok(str, " .");
    while (currentWord != NULL) {
        if (strcmp(lastWord, currentWord) != 0)
            printf("%s ", currentWord);
        currentWord = strtok (NULL, " .");
    }

    return 0;
}
