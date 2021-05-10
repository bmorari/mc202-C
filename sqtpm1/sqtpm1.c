#include <stdio.h>

int main(void) {

  int inteiro, dias, horas, minutos, segundos;
  scanf("%d", &inteiro);

  if (inteiro >= 86400) {

    dias = inteiro / 86400;
    horas = (inteiro - 86400 * dias) / 3600;
    minutos = (inteiro - 86400 * dias - 3600 * horas) / 60;
    segundos = inteiro - 86400 * dias - 3600 * horas - 60 * minutos;

    printf("%d dia(s), %d hora(s), %d minuto(s) e %d segundo(s).\n", dias, horas, minutos, segundos);

  } 
  else if (inteiro >= 3600) {
    
    horas = inteiro / 3600;
    minutos = (inteiro - horas * 3600) / 60;
    segundos = inteiro - horas * 3600 - minutos * 60;
    printf("0 dia(s), %d hora(s), %d minuto(s) e %d segundo(s).\n", horas, minutos, segundos);

  } 
  else if (inteiro >= 60) {
    
    minutos = inteiro / 60;
    segundos = inteiro - minutos * 60;
    printf("0 dia(s), 0 hora(s), %d minuto(s) e %d segundo(s).\n", minutos, segundos);

  }
  else {

    printf("0 dia(s), 0 hora(s), 0 minuto(s) e %d segundo(s).\n", inteiro);
    
  }
  
  return 0;
}