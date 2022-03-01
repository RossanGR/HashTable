#include <stdio.h>
#include <malloc.h>
#define TAMANHO 20


typedef struct data{
  int id;
  int value;
} Data;

Data* hashTable[TAMANHO];

int hashCode(int id){

    
  return id % TAMANHO;
}

void incluir(int id, int valor){
    Data* meusDados = (Data*) malloc(sizeof(Data));
    meusDados->id = id;
    meusDados->value = valor;

    int posicao = hashCode(id);
    // RESOLVER CONFLITOS AQUI
    // LINEAR
    // if(hashTable[posicao] != NULL){
    //   posicao++;
    //   posicao = posicao % TAMANHO;
    // }
    int count = 0;
    while(hashTable[posicao] != NULL && count < TAMANHO){
      
      posicao++;

      posicao = posicao % TAMANHO;

      count++;
    }

    hashTable[posicao] = meusDados;
  }


void pesquisar(int id){
  int posicao = hashCode(id);
  Data* dataAchado = NULL;
  int count = 0;
    while(hashTable[posicao] != NULL && count < TAMANHO){
      if(hashTable[posicao]->id == id){
        dataAchado = hashTable[posicao];
        break;
      } 
    

    posicao++;
    posicao = posicao % TAMANHO;
    count++;
    }
    if(dataAchado != NULL){
      printf("ACHEI O ID %d\n", dataAchado->id);
    }else{
      printf("NAO ACHEI O ID %d\n",id);
    }
    

  
}

void imprimir(){
  int i;
  for(i = 0; i < TAMANHO; i++){
    if(hashTable[i] != NULL ){
      printf("(id: %d, valor: %d)\n",hashTable[i]->id,hashTable[i]->value);
    }
    else{
      printf("----------------\n");
    }
  }
}

int main(void) {
  incluir(4,20);
  incluir(62,13);
  incluir(50,8);

  imprimir();

  pesquisar(62);
  pesquisar(3);
  return 0;
}