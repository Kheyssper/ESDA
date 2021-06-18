#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

//***********************Assinaturas******************************

void cadastrarJogador();
int id();
void cadastrarEquipes();
void mostrarJogador();
int mostrarEquipes();
void cabecalho();
void apagarTerceiro();
int terceiroMaior();
int vectorJogadores(struct Jogador* jogadores);
int contarJogadores();
int idJogador()
{

//***********************Estrutura******************************

	typedef struct
	{
		int dia;
		int mes;
		int ano;
	} Data;

	typedef struct
	{
		char ativo;
		int nrDeGolos;
		char apelido[30];
		char nome[30];
		Data dataInicio;
		Data dataFim;
		int idEqui;
		int id;
	} Jogador;

	typedef struct
	{
		char nome[50];
		int ID;
	} Equipa;

	static int contador = 0;

//***********************Main******************************

	int main()
	{
		int aux;
		printf("1.Cadastrar equipes\n");
		printf("2.Mostrar jogador especifico\n");
		printf("3.Remover");
		scanf("%d", &aux);

		switch(aux)
		{

		case 1:
			cabecalho();

			cadastrarJogador();
			break;

		case 2:
			cabecalho();
			mostrarJogador();
			break;

		case 3:
				cabecalho();
			apagarTerceiro();
			break;

		default:
			cabecalho();
			printf("Desculpe, ocorreu um erro");
		}


		return 0;
	}


	/************************************Funcoes************************************/
	int id()
	{
		FILE* arquivo = fopen("testeNovoE.txt", "r");

		Equipa equipas;
		if(arquivo == NULL)
		{
			printf("Arquivo nao encontrados");
		}

		else
		{
			fseek(arquivo, -sizeof(Equipa), SEEK_END);
			int n = fread(&equipas, sizeof(Equipa), 1, arquivo);
			if(n != 0)
			{
				fclose(arquivo);
				return 1;
			}
			else
			{
				fclose(arquivo);
				return equipas.ID;
			}

		}
	}


	void cadastrarEquipes()
	{
		contador = 1;
		FILE* arquivo = fopen("testeNovoE.txt", "ab");
		Equipa equipas;
		if(arquivo == NULL)
		{
			printf("Arquivo nao encontrados");
		}
		else
		{
			do
			{
				fflush(stdin);
				printf("Incira o nome da equipa: ");
				gets(equipas.nome);
				equipas.ID = id() + 1;
				fwrite(&equipas, sizeof(Equipa), 1, arquivo);
				fflush(stdin);
				printf("Deseja Insirir outro jogador? Se sim s, se nao n.(s/n)\n");
				system("pause");
			}
			while(getche() != 'n');
		}

	}


	void cadastrarJogador()
	{
		FILE* arquivo = fopen("jogadores.txt", "ab");
		Jogador jogadores;
		if(arquivo == NULL)
		{
			printf("Arquivo nao encontrados");
		}
		else
		{
			do
			{

				printf("Incira a equipe pretendida: \n");
				//Mostra as equipes


				if(mostrarEquipes() == 3)
				{
					cadastrarEquipes();
				}

				scanf("%d", &jogadores.idEqui);
				fflush(stdin);
				printf("\nIncira o nome do jogador: ");
				gets(jogadores.nome);
				fflush(stdin);
				printf("\nIncira nr de golos do jogador: ");
				scanf("%d", &jogadores.nrDeGolos);
				fflush(stdin);
				printf("Incira a data de inicio do contrato do jogador: \n");
				scanf("%d %d %d", &jogadores.dataInicio.dia, &jogadores.dataInicio.mes, &jogadores.dataInicio.ano);
				fflush(stdin);
				printf("Incira a data do fim do contrato do jogador: \n");
				scanf("%d %d %d", &jogadores.dataFim.dia, &jogadores.dataFim.mes, &jogadores.dataFim.ano);
				jogadores.id = idJogador() + 1;
				fwrite(&jogadores, sizeof(Jogador), 1, arquivo);
				fflush(stdin);
				printf("Deseja Insirir outro jogador? Se sim s, se nao n.(s/n)");
			}
			while(getche() != 'n');
		}
	}


	void mostrarJogador()
	{
		int id;
		Jogador jogadores;
		FILE* arquivo = fopen("jogadores.txt", "rb");

		if(arquivo == NULL)
		{
			printf("ERRRRRRRRRRRRRRRO");
		}

		else
		{
			fflush(stdin);
			printf("Insira o id da equipe: ");
			scanf("%d", &id);

			while(fread(&jogadores, sizeof(Jogador), 1, arquivo) == 1)
			{
				if(id == jogadores.idEqui)
				{
					printf("Nome: %s\n", jogadores.nome);
					printf("idade: %d\n", jogadores.nrDeGolos);
					printf("Data Inicio Contrato: %d/%d/%d\n", jogadores.dataInicio.dia, jogadores.dataInicio.mes, jogadores.dataInicio.ano);
					printf("Data Inicio Contrato: %d/%d/%d", jogadores.dataFim.dia, jogadores.dataFim.mes, jogadores.dataFim.ano);
					printf("\n----------------------------------------------------------------------------------\n");
				}
			}
		}
		fclose(arquivo);
		getch();
	}


	int mostrarEquipes()
	{
		Equipa equipas;
		int aux;
		FILE* arquivo = fopen("testeNovoE.txt", "rb");

		if(arquivo == NULL)
		{
			printf("ERRRRRRRRRRRRRRRO");
			return 0;
		}

		else
		{
			while(fread(&equipas, sizeof(Equipa), 1, arquivo) == 1)
			{
				printf("Nome: %s\n", equipas.nome);
				printf("ID: %d\n", equipas.ID);
				//printf("Data Inicio Contrato: %d/%d/%d", cadastro.dataI.dia, cadastro.dataI.mes, cadastro.dataI.ano);
				printf("\n----------------------------------------------------------------------------------\n");
			}
			return 1;
		}
		fclose(arquivo);
		getch();
		return 3;
	}


	void cabecalho()
	{
		system("cls");
		printf("***************************************");
		printf("\t\tPRACTICA1\n");

	}

//Como apagar?
//Vamos copiar os dados para um array depois

	int idJogador()
	{
		FILE *arquivo;
		arquivo = fopen("jogadores.txt", "rb");
		if (arquivo == NULL)
		{
			printf("Erro");
			return 0;
		}
		Jogador jogador;

		fseek(arquivo, -sizeof (Jogador), SEEK_END);
		int n = fread(&jogador, sizeof (Jogador), 1, arquivo);
		if (n != 1)
		{
			return 0;
		}

		fclose(arquivo);
		return jogador.id;
	}


	int contarJogadores()
	{
		FILE *arquivo;
		arquivo = fopen("jogadores.txt", "rb");
		if (arquivo == NULL)
		{

		}
Jogador jogadores;
		int i = 0;
		while (fread(&jogadores, sizeof (Jogador), 1, arquivo) == 1)
		{
			i++;
		}
		fclose(arquivo);
		return i;
	}


	int vectorJogadores( Jogador * jogadores)
	{
		FILE *arquivo;
		arquivo = fopen("jogadores.txt", "rb");
		if (arquivo == NULL)
		{
			printf("ERRO");
			return 0;
		}

Jogador jogador;
		int j = 0;

		while (fread(&jogador, sizeof (Jogador), 1, arquivo) == 1)
		{
			jogadores[j] = jogador;
			j++;
		}
		fclose(arquivo);
	}


	int terceiroMaior()
	{

		int nrDeJogadores = contarJogadores();
		Jogador jogadores[];
		vectorJogadores(jogadores);


		 Jogador aux;
		int i = 0, j = 0;

		for (i = 0; i < nrDeJogadores; i++)
		{
			for (j = i + 1; j < nrDeJogadores; j++)
			{
				if (jogadores[i].nrDeGolos < jogadores[j].nrDeGolos)
				{
					aux = jogadores[j];
					jogadores[j] = jogadores[i];
					jogadores[i] = aux;
				}
			}
		}
		return jogadores[2].idEqui;
	}


	void apagarTerceiro()
	{
		int idJog = terceiroMaior();
		int nrDejog = contarJogadores();

		 Jogador jogadores[nrDejog];
		vectorJogadores(jogadores);
		int t;
		for (int j = 0; j < nrDejog; j++)
		{
			if (jogadores[j].id == idJog)
			{
				t = j;
				break;
			}
		}

		 Jogador jog;

		FILE *arquivo;
		arquivo = fopen("jogadores.txt", "w");
		if (arquivo == NULL)
		{
			printf("Erro");
		}

		for (int j = 0; j < nrDejog; j++)
		{
			if (jogadores[j].id != idJog)
			{
				jog = jogadores[j];
				fwrite(&jog, sizeof (Jogador), 1, arquivo);
			}
		}
		printf("Removido com sucesso!");
		fclose(arquivo);


	}
