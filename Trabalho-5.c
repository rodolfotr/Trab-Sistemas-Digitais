#include <stdio.h>
#include <stdlib.h>
#define MAX 200

typedef struct ponto{
	int x, y;
} ponto;

int main(){
    ponto ptA1, ptA2, ptA3, pA, ptB1, ptB2, ptB3, pB;
    int sA, sB;

    FILE *A, *B, *OUT;

    A = fopen("saidas_C.txt","r");
    B = fopen("saidas_V.txt","r");
    OUT = fopen("LinhasErradas.txt","w");

    int j, g = 0;
    for(j = 0; j < MAX; j++){
        fscanf(A, "%d %d %d %d %d %d %d %d = %d", &ptA1.x, &ptA1.y ,&ptA2.x, &ptA2.y, &ptA3.x, &ptA3.y, &pA.x, &pA.y, &sA) != EOF;
        fscanf(B, "%d %d %d %d %d %d %d %d = %d", &ptB1.x, &ptB1.y ,&ptB2.x, &ptB2.y, &ptB3.x, &ptB3.y, &pB.x, &pB.y, &sB) != EOF;

    	if(sA != sB){
			fprintf(OUT,"Diferenca na linha %d\n", j+1);
			g++;
		}
		if(j == 199){
			fprintf(OUT,"%d ERROS\n", g);
        }
    }

    fclose(A);
    fclose(B);
    fclose(OUT);

    return 0;
}
