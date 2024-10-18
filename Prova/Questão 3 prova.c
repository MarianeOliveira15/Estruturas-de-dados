#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct NO {
   char emocao[18];
   struct NO *prox;
};


struct sLISTA {
  struct NO *ini, *fim;
};

typedef struct sLISTA LISTA;


void inicializar(LISTA *lst) {
  lst->ini = NULL;
  lst->fim = NULL;
}

void imprimir(LISTA *lst) {
  struct NO *aux = lst->ini;

  printf("[ ");
  while (aux) {
    printf("%s ", aux->emocao);
    aux = aux->prox;
  }
  printf("]\n");
}


void inserir(LISTA *lst, char emocao[18]) {
  struct NO *aux = lst->ini;
  struct NO *novo = (struct NO *)malloc(sizeof(struct NO));
  
  novo->prox = NULL;

  //for(int i = 0; i<18;i++)
  //  novo->emocao[i] = emocao[i];

  
strcpy(novo->emocao, emocao);
  
  if (!lst->ini)
    lst->ini = lst->fim = novo;
  else {
    lst->fim->prox = novo;
    lst->fim = novo;
  }
}

LISTA embate_emocoes(LISTA *lst1, LISTA *lst2) {
  LISTA lst3;
  inicializar(&lst3);

  struct NO *aux = lst1->ini;
  struct NO *aux2 = lst2->ini;
  
  while (aux != NULL) {
   if ((strlen(aux->emocao)) < strlen(aux2->emocao)){
      inserir(&lst3, aux->emocao);
    }else{
      inserir(&lst3, aux2->emocao);
    }
    aux = aux->prox;
    aux2 = aux2->prox;
  }
  return lst3;
}


int main(void) {
  LISTA lst1, lst2, lst3;;

  inicializar(&lst1);
  inicializar(&lst2);
  inicializar(&lst3);
  
  inserir(&lst1, "MEDO");
  inserir(&lst2, "NOJO");
  inserir(&lst1, "ALEGRIA");

  lst3 = embate_emocoes(&lst1,&lst2);

  imprimir(&lst3);
  return 0;
}