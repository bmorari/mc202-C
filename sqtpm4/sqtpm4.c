#include <stdio.h>

int main(void) {

    int n, m, r, s, soma, somaProv; scanf("%d %d %d %d", &n, &m, &r, &s);
    int matriz[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &matriz[i][j]);
        }
    }

    somaProv = 0;
    soma = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i + r <= n && j + s <= m) {
                for (int k = i; k < r + i; k++) {
                    for (int l = j; l < s + j; l++) {
                        somaProv += matriz[k][l];
                    }
                } 
                if (somaProv > soma) {
                    soma = somaProv;
                    somaProv = 0;
                } else { 
                    somaProv = 0; 
                }
            }
        }
    }
    printf("%d\n", soma);
}
