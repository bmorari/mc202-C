#include <stdio.h>

int main(void) {

    int n, maxDias, diaVenda, diaCompra, acoesCompradas, acoesProv;
    double dinheiro, lucroMax, lucroProv, valorVenda, valorCompra; scanf("%d", &n);
    double precos[n];

    for (int i = 0; i < n; i++) {
        scanf("%lf", &precos[i]);
    }

    scanf("%d", &maxDias);
    scanf("%lf", &dinheiro);

    acoesCompradas = dinheiro / precos[0];
    lucroMax = (acoesCompradas * precos[0]) + (dinheiro - acoesCompradas * precos[0]);
    valorVenda = precos[0];
    valorCompra = precos[0];
    diaVenda = 1;
    diaCompra = 1;

    for (int i = 0; i < n; i++) {

        if (i + maxDias < n) {

            for (int j = i + 1; j <= maxDias + i; j++) {

                acoesProv = dinheiro / precos[i];
                lucroProv = (acoesProv * precos[j]) + (dinheiro - acoesProv * precos[i]);
                
                if (lucroProv > lucroMax) {
                    acoesCompradas = acoesProv;
                    lucroMax = lucroProv;
                    diaVenda = j + 1;
                    diaCompra = i + 1;
                    valorCompra = precos[i];
                    valorVenda = precos[j];
                }
            }
        } else {
            for (int k = i; k < n; k++) {
                acoesProv = dinheiro / precos[i];
                lucroProv = (acoesProv * precos[k+1]) + (dinheiro - acoesProv * precos[i]);
                
                if (lucroProv > lucroMax) {
                    acoesCompradas = acoesProv;
                    lucroMax = lucroProv;
                    diaVenda = k + 2;
                    diaCompra = i + 1;
                    valorCompra = precos[i];
                    valorVenda = precos[k+1];
                }
            }
        }
    }

    if (acoesCompradas < 0) {
        acoesCompradas = 0;
    }

    printf("Dia da compra: %d\n", diaCompra);
    printf("Valor de compra: R$ %0.2lf\n", valorCompra);
    printf("Dia da venda: %d\n", diaVenda);
    printf("Valor de venda: R$ %0.2lf\n", valorVenda);
    printf("Quantidade de acoes compradas: %d\n", acoesCompradas);
    printf("Lucro: R$ %0.2lf\n", lucroMax - dinheiro);
}