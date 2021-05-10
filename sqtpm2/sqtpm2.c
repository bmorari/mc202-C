#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  int triplas;

  scanf("%d", &triplas);
  
  int *num, *freq;
  char *carac;

  num = (int *) malloc(triplas * sizeof(int));
  freq = (int *) malloc(triplas * sizeof(int));
  carac = (char *) malloc(triplas * sizeof(char));

  for (int i = 0; i < triplas; i++) {
    scanf(" (%d,%d,%c)", &num[i],&freq[i],&carac[i]);

    printf("%4d |", num[i]);

    for (int j = 0; j < freq[i]; j++) {
      printf("%c", carac[i]);
    }
    
    printf(" %d\n", freq[i]);
  }

  return 0;
}