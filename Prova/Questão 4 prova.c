#include <stdio.h>

struct EMOCAO {
   char nome[18];
   int freq;
};

struct NO {
   struct EMOCAO emocao;
   struct NO *ant, *prox;
};

struct LISTA {
   struct NO *inicio, *fim;
};  



void inicializar(LISTA *lst) {
  lst->ini = NULL;
  lst->fim = NULL;
}

struct sNODE *buscar(struct LISTA *lst, char dado[18]){
  struct NO *aux = lst->ini;

  while (aux){
  if (dado == aux->emocao)
        return aux;
  aux = aux->prox;
  }

  return NULL;
}

void emocao_no_controle(struct LISTA *lst, char emocao[18]) {

  struct NO *aux = buscar(emocao[18]);

  aux->emocao->freq = aux->emocao->freq+1;
}


struct sNODE *emocao_dominante(){
  
  struct NO *aux = lst->ini;
  
  while (aux){
    if (aux->emocao->freq > aux->prox->emocao->freq)
      return aux;
    aux = aux->prox;
  }
}

struct sNODE *emocao_submissiva(){

  struct NO *aux = lst->ini;

  while (aux){
    if (aux->emocao->freq < aux->prox->emocao->freq)
      return aux;
    aux = aux->prox;
  }
}



int main(void) {
  printf("Hello World\n");
  return 0;
}