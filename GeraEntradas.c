#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
	int x, y;
} ponto;

int main(){

    srand( (unsigned)time(NULL) );

    ponto pt1, pt2, pt3, p;

    FILE *result;

    result = fopen("entradas.txt", "w");

    int j = 200;
    while(j--){
        pt1.x = rand()%100;
        pt1.y = rand()%100;
        pt2.x = rand()%100;
        pt2.y = rand()%100;
        pt3.x = rand()%100;
        pt3.y = rand()%100;
        p.x = rand()%100;
        p.y = rand()%100;
        fprintf(result, "%d %d %d %d %d %d %d %d\n", pt1.x, pt1.y ,pt2.x, pt2.y, pt3.x, pt3.y, p.x, p.y);
    }

    free(result);

    return 0;
}
