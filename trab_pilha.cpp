#include<stdio.h>
#define TAMANHO_MAXIMO 10

typedef struct {
  int id;
  int numerosDePaginas;
  float peso;
} Documento;

typedef struct {
	Documento elementos[TAMANHO_MAXIMO];
	Documento *topo;
  int length;

} PILHA;

void inicializarPilha(PILHA* pilha);
void limpaPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);
int push(PILHA* pilha, int id, int numerosDePaginas, float peso);
void pop(PILHA* pilha);
int length(PILHA* pilha);

int main () {
	PILHA minhaPilha;

	inicializarPilha(&minhaPilha);
	
	push(&minhaPilha, 1, 100, 100.0);
	push(&minhaPilha, 2, 200, 200.0);
	push(&minhaPilha, 3, 300, 5.5);
	
	imprimirPilha(&minhaPilha);

	pop(&minhaPilha);
	
	imprimirPilha(&minhaPilha);
	
	limpaPilha(&minhaPilha);
	
	imprimirPilha(&minhaPilha);	
}

void pop(PILHA* pilha){
	if(length(pilha) > 0){
    pilha->topo->id = 0;
    pilha->topo->numerosDePaginas = 0;
    pilha->topo->peso = 0;
		pilha->topo --;
    pilha->length--;
	}
}

int push(PILHA* pilha, int id, int numerosDePaginas, float peso) {
	if(length(pilha) < TAMANHO_MAXIMO) {
    pilha->length++;
		pilha->topo++;
		pilha->topo->id = id;
    pilha->topo->numerosDePaginas = numerosDePaginas;
    pilha->topo->peso = peso;
		
		return 1;
	}
	
	return 0;
}

void inicializarPilha(PILHA* pilha) {
	pilha->topo = pilha->elementos;
  pilha->topo--;
  pilha->length=0;
}

void limpaPilha(PILHA* pilha) {
	pilha->topo = pilha->elementos;
  pilha->length=0;
}

int length(PILHA* pilha) {
	return pilha->length;
}

void imprimirPilha(PILHA* pilha) {
	printf("PILHA :)\n");
  if(pilha->length==0){
    printf("vazio :)\n");
  }
  else{
    printf(" 'id'  'paginas'   'peso'\n");
  	
  	for(int i = pilha->length-1; i >= 0; i--){
  		printf("|_%d_|___%d___|_%.1f_|\n", pilha->elementos[i].id, pilha->elementos[i].numerosDePaginas, pilha->elementos[i].peso);
    }
  }
  printf("Tamanho: %d", pilha->length);
  printf("\n\n");
}