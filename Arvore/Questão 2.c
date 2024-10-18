#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL;
struct sNODE *inserir(struct sNODE *no, int dado);
struct sNODE *remover(struct sNODE *no, int dado); 

void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);
void mostrarFolhas( struct sNODE *no);
int getMax(struct sNODE *no);
int getMin(struct sNODE *no);
int distanciaDaRaiz( struct sNODE *no, int elemento);
int alturaArvore(struct sNODE *no); 


int main(){

int lista[]= {11,8,9,7,20,14,25,13,16,17};
for(int i=0; i<10;i++){
    raiz= inserir(raiz,lista[i]);
}
printf("\nfunção emOrdem\n");
emOrdem(raiz);
printf("\nfunção preOrdem\n");
preOrdem(raiz);
printf("\nfunção posOrdem\n");
posOrdem(raiz);
printf("\nfunção mostrarFolhas\n");
mostrarFolhas(raiz);
printf("\nfunção getMax\n");
printf("%d",getMax(raiz));
printf("\nfunção getMin\n");
printf("%d",getMin(raiz));
printf("\nfunção distanciadaRaiz\n");
printf("%d",distanciaDaRaiz(raiz,20));
printf("\nfunção alturaArvore\n");
printf("%d",alturaArvore(raiz));



    return 0;
}

struct sNODE *inserir(struct sNODE *no, int dado){
    if(no == NULL){
        no=malloc(sizeof(struct sNODE));
        no->dado=dado;
        no->esq=NULL;
        no->dir=NULL;
    }
    else if(no->dado> dado){
        no->esq=inserir(no->esq,dado);
    }
    else{
        no->dir=inserir(no->dir,dado);
    }
    return no;
}




void emOrdem(struct sNODE *no){
    if(no){
        emOrdem(no->esq);
        printf("%d",no->dado);
        emOrdem(no->dir);

    }

}

void preOrdem(struct sNODE *no){
    if(no){
        printf("%d",no->dado);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

void posOrdem( struct sNODE *no){
    if(no){
        posOrdem(no->esq);
        posOrdem(no->dir);
        printf("%d",no->dado);


     }
} 

int getMax(struct sNODE *no){
    if(no){
        if(no->dir == NULL){
            return no->dado;
        }
        else{
            return getMax(no->dir);        
        }
    }
    return 0;
}
