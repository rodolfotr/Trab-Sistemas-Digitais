#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
	int x, y;
} ponto;

int area(ponto a, ponto b, ponto c){                                                /// Função verificação da area do triangulo.
	int deter;
	
	deter = ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y));
	
    return deter;
}

int verificacao(ponto a, ponto b, ponto c, ponto p){                                /// Função verificação do ponto dentro do triangulo.
	int total = area(a,b,c);
	int A1 = area(p,b,c)<0;
	int A2 = area(a,p,c)<0;
	int A3 = area(a,b,p)<0;
    return A1 == A2 && A2 == A3;
}

int main(){

    int ver;
	ponto pt1, pt2, pt3, p;

    FILE *pontos;
    FILE *result;

    pontos = fopen("entradas.txt", "r");
    result = fopen("saidas_C.txt", "w");

    if (pontos == NULL){
        printf("\nErro na leitura do arquivo!\n");
        exit(1);
    }
    if (result == NULL){
        printf("\nErro na escrita do arquivo!\n");
        exit(1);
    }

    while (fscanf(pontos, "%d %d %d %d %d %d %d %d", &pt1.x, &pt1.y ,&pt2.x, &pt2.y, &pt3.x, &pt3.y, &p.x, &p.y) != EOF){
       ver = verificacao(pt1, pt2, pt3, p);
       fprintf(result, "%d %d %d %d %d %d %d %d = %d\n", pt1.x, pt1.y ,pt2.x, pt2.y, pt3.x, pt3.y, p.x, p.y, ver);
    }

    free(result);
    free(pontos);

	}
