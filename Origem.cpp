#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu();
void InserirInicio(char banda[], char musica[], int duracao);
void Listar();

struct ElementoDaLista_Simples { //Declaração da estrutura de dados
	int duracao;
	char banda[50];
	char musica[50];
	struct ElementoDaLista_Simples *prox;
} *Head;

int main() { //Programa principal
	int op, c, duracao; //Declarando variáveis
	char banda[50], musica[50]; //Declarando variáveis
	Head = NULL; //Iniciando head vazio

	while (1) { //Condicionais para chamada das funções
		op = menu();
		switch (op) {
			case 1:
				printf("Digite o nome da banda: ");
				gets_s(banda);
				while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
				printf("Digite o nome da musica: ");
				gets_s(musica);
				while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
				printf("Digite a duracao da musica: ");
				scanf_s("%d", &duracao);
				while ((c = getchar()) != '\n' && c != EOF) {} // limpando buffer do teclado.
				InserirInicio(banda, musica, duracao); //Executando a função inserir
				break;
	
			case 2:
				Listar(); //Executando função listar
				break;

			case 3:
				return 0; //Finalizar execução
			
			default:
				printf("Invalido\n");
		}
	}	

}	return 0;



int menu() { //Função de menu
	int op, c;
	system("Cls");
	printf("**********Playlist************\n");
	printf("*                            *\n");
	printf("* 1.Inserir nova musica      *\n");
	printf("* 2.Listar musicas           *\n");
	printf("* 3.Sair                     *\n");
	printf("* Digite sua escolha:        *\n");
	printf("*                            *\n");
	printf("******************************\n");
	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.
	system("Cls");
	return op;
}

void InserirInicio(char banda[], char musica[], int duracao) //Função para inserir dados na lista
{
	ElementoDaLista_Simples *NovoElemento; //iniciando elemento na memória
	NovoElemento = (struct ElementoDaLista_Simples *)malloc(sizeof(struct
	ElementoDaLista_Simples));
	strcpy_s(NovoElemento->banda, banda); //passagem de parâmetro para a variável
	strcpy_s(NovoElemento->musica, musica); //passagem de parâmetro para a variável
	NovoElemento->duracao = duracao; //passagem de parâmetro para a variável
	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

void Listar() //Função para exibir os dados da lista
{
	ElementoDaLista_Simples *ElementoVarredura; //iniciando elemento na memória
	ElementoVarredura = (struct ElementoDaLista_Simples *)malloc(sizeof(struct
	ElementoDaLista_Simples));
	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
	return;
	}
	while (ElementoVarredura != NULL) { // Imprimindo elementos da lista
	printf("%s ", ElementoVarredura->banda);
	printf("%s ", ElementoVarredura->musica);
	printf("%d \n", ElementoVarredura->duracao);
	ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");
	system("pause");
	return;
}