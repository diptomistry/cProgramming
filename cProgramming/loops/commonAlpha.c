#include <stdio.h>
#include <string.h> 

void findCommonAlphabets(char strings[][100], int numStrings) {
    if (numStrings <= 0) {
        printf("###\n"); 
        return;
    }

    char commonAlphabets[26];
    int commonCount = 0;

    char firstString[100];
    strcpy(firstString, strings[0]);

    for (int i = 0; firstString[i] != '\0'; i++) {
        char c = firstString[i];
        int isCommon = 1;

        for (int j = 1; j < numStrings; j++) {
            if (strchr(strings[j], c) == NULL) {
                isCommon = 0;
                break;
            }
        }

        if (isCommon) {
            commonAlphabets[commonCount] = c;
            commonCount++;
        }
    }

    if (commonCount == 0) {
        printf("###\n"); 
        return;
    }

  
    for (int i = 0; i < commonCount - 1; i++) {
        for (int j = i + 1; j < commonCount; j++) {
            if (commonAlphabets[i] > commonAlphabets[j]) {
            
                char temp = commonAlphabets[i];
                commonAlphabets[i] = commonAlphabets[j];
                commonAlphabets[j] = temp;
            }
        }
    }

    for (int i = 0; i < commonCount; i++) {
        printf("%c", commonAlphabets[i]);
    }
    printf("\n");
}

int main() {
    int numStrings;

    scanf("%d", &numStrings);
    getchar(); 

    char strings[numStrings][100];

    for (int i = 0; i < numStrings; i++) {
        scanf("%s", strings[i]);
    }

    findCommonAlphabets(strings, numStrings);

    return 0;
}
