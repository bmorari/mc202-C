#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    char stringCod[10001], letraRecorrente = 'a';
    scanf("%[^\n]", stringCod);
    int tamanho = strlen(stringCod), countProv = 0, count = 0;

    for (int i = 0; i < tamanho; i++) {
        if (stringCod[i] == ' ') {
                continue;
            }
            
        for (int j = 0; j < tamanho; j++) {
            if (stringCod[i] == stringCod[j]) {
                countProv += 1;
            }
        }
        if (countProv > count) {
            count = countProv;
            letraRecorrente = stringCod[i];
            countProv = 0;
        } else if (countProv == count) {
            if (stringCod[i] < letraRecorrente) {
                count = countProv;
                letraRecorrente = stringCod[i];
                countProv = 0;
            } else {
                countProv = 0;
            }
        }
        countProv = 0;
    }

    int variacao = letraRecorrente - 'a';
    if (variacao == 0) {
        variacao = 1;
    }

    for (int i = 0; i < tamanho; i++) {

        if (tolower(stringCod[i]) == letraRecorrente) {
            printf("%c", stringCod[i]);
        } else if (stringCod[i] == ' ') {
            printf("%c", stringCod[i]);
        } else {
            char stringDeco = stringCod[i] - variacao;
    
            if (stringDeco <= letraRecorrente) {
                if (stringDeco < 'a') {
                    if (letraRecorrente == 'z') {
                        if (stringCod[i] == 'a') {
                            stringDeco = stringDeco + 49;
                        } else {
                            stringDeco = stringDeco + 24;
                        }
                        printf("%c", stringDeco);
                        continue;
                    } else {
                        stringDeco = stringDeco + 26;
                        if (stringDeco == letraRecorrente) {
                            stringDeco--;
                        } else if (letraRecorrente >= stringDeco) {
                            stringDeco--;
                        }
                        printf("%c", stringDeco);
                        continue;
                    }
                    
                } else if (stringDeco == letraRecorrente) {
                    if (stringDeco == 'a') {
                        stringDeco = stringDeco + 25;
                        printf("%c", stringDeco);
                        continue;
                    } else {
                        stringDeco--;
                    }
                } else {
                    stringDeco--;
                }
            } else {
                if (stringDeco == letraRecorrente) {
                    stringDeco--;
                } else {
                    printf("%c", stringDeco);
                    continue;
                }
            }
            printf("%c", stringDeco);
        }
    }
    printf("\n");
    return 0;
}