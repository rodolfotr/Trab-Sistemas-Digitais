#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
	int x, y;
} ponto;

int area(ponto a, ponto b, ponto c){                                                /// Função verificação da area do triangulo.
	int valor;
	valor = abs(a.x*(b.y-c.y) + b.x*(c.y-a.y)+ c.x*(a.y-b.y));
	return(valor);
}

int verificacao(ponto a, ponto b, ponto c, ponto p){                                /// Função verificação do ponto dentro do triangulo.
	int total = area(a,b,c);
	int A1 = area(p,b,c);
	int A2 = area(a,p,c);
	int A3 = area(a,b,p);

	if(A1+A2+A3 == total){
		return 1;
	}
	else{
		return 0;
	}
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
       ver = !verificacao(pt1, pt2, pt3, p);
       fprintf(result, "%d %d %d %d %d %d %d %d = %d\n", pt1.x, pt1.y ,pt2.x, pt2.y, pt3.x, pt3.y, p.x, p.y, ver);
    }

    free(result);
    free(pontos);



//
//    printf("Ponto 1 do Triangulo - X e Y\n");                                       /// Obtenção das coordenadas dos 3 pontos que compõe o triangulo.
//	scanf("%d %d", &pt1.x, &pt1.y);
//    printf("Ponto 2 do Triangulo - X e Y\n");
//	scanf("%d %d", &pt2.x, &pt2.y);
//    printf("Ponto 3 do Triangulo - X e Y\n");
//	scanf("%d %d", &pt3.x, &pt3.y);
//    printf("Ponto - X e Y\n");                                                      /// Coordenadas do ponto a ser verificado.
//	scanf("%d %d", &p.x, &p.y);
//
//	if(verificacao(pt1, pt2, pt3, p)){
//		printf("\n\nDentro\n");
//	}
//	else{
//		printf("\n\nFora\n");
//	}

}
