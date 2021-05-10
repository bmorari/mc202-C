#include <stdio.h>
#include <string.h>
#include <ctype.h>

int testCarac(char senha[21]) {
    int tamanho = strlen(senha);
    if (tamanho >= 8) {
        return 1;
    }
    return 0;
}

int testVogal(char senha[21]) {
    int tamanho = strlen(senha);
    for (int i = 0; i < tamanho; i++) {
        if (tolower(senha[i]) == 97 || tolower(senha[i]) == 101 || tolower(senha[i]) == 105 || tolower(senha[i]) == 111 || tolower(senha[i]) == 117) {
            return 1;
        }
    }
    return 0;
}

int testDigit(char senha[21]) {
    int tamanho = strlen(senha);
    for (int i = 0; i < tamanho; i++) {
        if (isdigit((int)senha[i])) {
            return 1;
        }
    }
    return 0;
}

int testUpper(char senha[21]) {
    int tamanho = strlen(senha);
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(senha[i])) {
            if (isupper(senha[i])) {
                return 1;
            }
        }
    }
    return 0;
}

int testLower(char senha[21]) {
    int tamanho = strlen(senha);
    for (int i = 0; i < tamanho; i++) {
        if (isalpha(senha[i]) && islower(senha[i])) {
            return 1;
        }
    }
    return 0;
}

int testVogConsec(char senha[21]) {
    int tamanho = strlen(senha);
    for (int i = 0; i < 21; i++) {
        if (i + 2 < tamanho) {
            if (tolower(senha[i]) == 97 || tolower(senha[i]) == 101 || tolower(senha[i]) == 105 || tolower(senha[i]) == 111 || tolower(senha[i]) == 117) {
                if (tolower(senha[i+1]) == 97 || tolower(senha[i+1]) == 101 || tolower(senha[i+1]) == 105 || tolower(senha[i+1]) == 111 || tolower(senha[i+1]) == 117) {
                    if (tolower(senha[i+2]) == 97 || tolower(senha[i+2]) == 101 || tolower(senha[i+2]) == 105 || tolower(senha[i+2]) == 111 || tolower(senha[i+2]) == 117) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int testConsoConsec(char senha[21]) {
    int tamanho = strlen(senha);
    for (int i = 0; i < 21; i++) {
        if (i + 2 < tamanho) {
            if (isalpha(senha[i]) && tolower(senha[i]) != 97 && tolower(senha[i]) != 101 && tolower(senha[i]) != 105 && tolower(senha[i]) != 111 && tolower(senha[i]) != 117) {
                if (isalpha(senha[i+1]) && tolower(senha[i+1]) != 97 && tolower(senha[i+1]) != 101 && tolower(senha[i+1]) != 105 && tolower(senha[i+1]) != 111 && tolower(senha[i+1]) != 117) {
                    if (isalpha(senha[i+2]) && tolower(senha[i+2]) != 97 && tolower(senha[i+2]) != 101 && tolower(senha[i+2]) != 105 && tolower(senha[i+2]) != 111 && tolower(senha[i+2]) != 117) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}



int main(void) {
    char senha[21];

    for (int i = 1; i != 0; i++) {
        scanf("%s", senha);
        if (strcmp(senha, "fim") == 0) {
            break;
        } else {
            if (testCarac(senha) + testVogal(senha) + testDigit(senha) + testUpper(senha) + testLower(senha) + testVogConsec(senha) + testConsoConsec(senha) == 7) {
                printf("[%s] e' aceitavel.\n", senha);
            } else {
                printf("[%s] e' inaceitavel.\n", senha);
            }
        }
    }
}