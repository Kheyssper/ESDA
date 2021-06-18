#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

/**
 * Shoo
 */
/*
typedef struct
{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct
{
	int id;
	char ativo;
	int nrDeGolos;
	char apelido[30];
	char nome[30];
	Data dataInicio;
	Data dataFim;
	int ID;
} Jogador;



typedef struct
{
	char nome[50];
	Jogador jogadores;
	int ID;
} Equipa;

void id()
{
	FILE* arquivo = fopen("practica1.txt", "r");
	Equipa equipas;
	if(arquivo == NULL)
	{
		printf("Arquivo nao encontrados");
	}
	else
	{
		fseek(arquivo, -sizeof(Equipa), SEEK_SET);
		int n = fread(&equipas, sizeof(Equipa), 1, arquivo);
		if(n != 0)
		{
			fclose(arquivo);
			return 0;
		}
		else
		{
			fclose(arquivo);
			printf("A: $s",equipas.ID);
            return equipas.ID;
		}

	}
}


void cadastrar()
{
	FILE* arquivo = fopen("practica1.txt", "ab");
	FILE* aux = fopen("aux.txt", "ab");


	Equipa equipas;
	int aux;
	if(arquivo == NULL)
	{
		printf("Arquivo nao encontrados");
	}
	else
	{
		do
		{
			fflush(stdin);
			printf("Incira o nome da equipa que deseja criar: ");
			gets(equipas.nome);

			fflush(stdin);
			printf("Incira o nome do jogador: ");
			gets(equipas.jogadores.nome);

			fflush(stdin);
			printf("Incira nr de golos do jogador: ");
			scanf("%d", equipas.jogadores.nrDeGolos);
			fflush(stdin);
			printf("Incira a data de inicio do contrato do jogador: ");
			scanf("%d %d %d", &equipas.jogadores.dataInicio.dia, &equipas.jogadores.dataInicio.mes, &equipas.jogadores.dataInicio.ano);
			fflush(stdin);
			printf("Incira a data do fim do contrato do jogador: ");
			scanf("%d %d %d", &equipas.jogadores.dataFim.dia, &equipas.jogadores.dataFim.mes, &equipas.jogadores.dataFim.ano);
//hora de inicirir o id


			fwrite(&equipas, sizeof(Equipa), 1, arquivo);
			fflush(stdin);
			printf("Deseja sair: (s/n)");
		}
		while(getche() != 's');

		fclose(arquivo);

	}
}

void pesquisar()
{
	Equipa equipas;
	int aux;
	char nome[50];
	FILE* arquivo = fopen("practica1.txt", "rb");

	if(arquivo == NULL)
	{
		printf("ERRRRRRRRRRRRRRRO");
	}
	else
	{
		fflush(stdin);
		printf("Digita o nome: ");
		gets(nome);

		while(fread(&equipas, sizeof(Equipa), 1, arquivo) == 1)
		{
			if(strcmp(nome, equipas.nome) == 0)
			{
				printf("Nome: %s\n", equipas.nome);
				printf("Nr de golos: %d\n", equipas.jogadores.nrDeGolos);
				printf("Data Inicio Contrato: %d/%d/%d", equipas.jogadores.dataInicio.dia, equipas.jogadores.dataInicio.mes, equipas.jogadores.dataInicio.ano);
				printf("Data Inicio Contrato: %d/%d/%d", equipas.jogadores.dataFim.dia, equipas.jogadores.dataFim.mes, equipas.jogadores.dataFim.ano);
				printf("\n----------------------------------------------------------------------------------\n");
			}
		}

	}
	fclose(arquivo);
	getch();
}

void mostrar()
{
	Equipa equipas;
	int aux;
	FILE* arquivo = fopen("practica1.txt", "rb");

	if(arquivo == NULL)
	{
		printf("ERRRRRRRRRRRRRRRO");
	}
	else

		char line[1024] = "";
	char c;
	printf("algo : %s", al {i*	ntf("=--------------------------------");
	}
	*/

int main()
{
	printf("dasd");
	return 0;
}