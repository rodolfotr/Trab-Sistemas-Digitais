#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
	int x, y;
} ponto;

int area(ponto a, ponto b, ponto c){
	return abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)));
}

int verificacao(ponto a, ponto b, ponto c, ponto d){
	int total = area(a,b,c);
	int A1 = area(a,c,d);
	int A2 = area(a,b,d);
	int A3 = area(c,d,b);

	if(A1+A2+A3 == total){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){

	ponto pt1, pt2, pt3, p;

	scanf("%d %d", &pt1.x, &pt1.y);
	scanf("%d %d", &pt2.x, &pt2.y);
	scanf("%d %d", &pt3.x, &pt3.y);
	scanf("%d %d", &p.x, &p.y);

	if(verificacao(pt1, pt2, pt3, p)){
		printf("Dentro\n");
	}
	else{
		printf("Fora\n");
	}

}
