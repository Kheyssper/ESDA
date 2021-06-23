#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>

/**
*                     Tema: Practica 1.
*                     Versao: 1 (Arrays).
*                     Autor: Gaspar E. Cossa;
*                     2021...
*/


/**
 *                  Comentarios "gerais"
 *
 * gets - Usamos quando queremos receber uma string;
 * fflush - Sabemos que usamos buffers entao ele limpaos
 * exit(0) - Usamos quando queremos sair;
 */


/********************Estruturas*******************************/

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;


typedef struct
{
    int nrDeGolos;
    char apelido[30];
    char nome[30];
    Data dataInicio;
    Data dataFim;
    int idE;
    int idJo;
} Jogador;


typedef struct
{
    char nome[50];
    int ID;
} Equipa;


/******************Assinaturas de Funcoes*************************/
void cadastrarJogadores();
void cadastrarEquipes();
void mostrarJogadores();
void mostrarEquipes();
void eliminaOTerceiro();
int nrDeElementosEquipes();
int nrDeElementosJogadores();
void mostrar();
int existeId(int id);
int idJogador();
void cabecalho();
void organizaDados(Jogador *jogadores);
void recebeDados(Jogador *jogadores);
void menu();
/******************************************/



/**********************Metodo principal*****************************/
int main()
{
    setlocale(LC_ALL,"");
    menu();
    return 0;
}



/********************As Funcoes**********************************/

//Cadastra os jogadores em um arquivo sem precisar guardar em um sitio intermediario como um array
void cadastrarJogadores()
{
    Jogador jogadores;
    int al;
    int auxiliar;
    FILE* arquivo = fopen("testeJ.txt", "ab");
    FILE* arquivoE = fopen("testeE.txt", "rb");
    //Nao podemos criar jogador sem antes criar equipe
    if(arquivoE != NULL) {
        if(arquivo == NULL)
        {
            printf("ERRRRRRRRRRRRRRRO");
        }
        else
        {
            //O arquivo pode sim ter existir mas nao ter equipe cadastrada;
            if(nrDeElementosEquipes()>0) {
                do
                {
                    fflush(stdin);
                    printf("Incira o nome do jogador: ");
                    gets(jogadores.nome);
                    fflush(stdin);
                    printf("Incira nr de golos do jogador: ");
                    scanf("%d", &jogadores.nrDeGolos);
                    fflush(stdin);
                    printf("Incira a data de inicio do contrato do jogador: ");
                    scanf("%d %d %d", &jogadores.dataInicio.dia, &jogadores.dataInicio.mes, &jogadores.dataInicio.ano);
                    fflush(stdin);
                    printf("Incira a data do fim do contrato do jogador: ");
                    scanf("%d %d %d", &jogadores.dataFim.dia, &jogadores.dataFim.mes, &jogadores.dataFim.ano);
                    mostrarEquipes();
                    fflush(stdin);
                    printf("\nEscolha uma equipe: ");
                    scanf("%d", &al);

                    if(existeId(al)==1) {
                        jogadores.idE = al;
                        int auxiliar = idJogador();
                        jogadores.idJo = auxiliar;
                        fwrite(&jogadores, sizeof(Jogador), 1, arquivo);
                        fflush(stdin);
                        cabecalho();
                        printf("\t\t\t\t\t\tCadastrado com sucesso!!\n");
                        printf("Deseja:\n1.Cadastrar outro jogador\n");
                        printf("2.Voltar para o menu\n3.Sair. ");
                        scanf("%d",&auxiliar);
                        if(auxiliar==1) {
                            cabecalho();
                            fclose(arquivo);
                            cadastrarJogadores();
                        }
                        else if(auxiliar==2) {
                            cabecalho();
                            fclose(arquivo);
                            menu();
                        }
                        else if(auxiliar==3) {
                            cabecalho();
                            printf("\t\t\t\t\t\tOBRIGADO\n");
                            fclose(arquivo);
                            exit(0);
                        }
                        else {
                            cabecalho();
                            printf("Nao existe essa opcao;\n");
                            printf("\t\t\t\t\t\tOBRIGADO\n");
                            fclose(arquivo);
                            exit(0);
                        }
                    }
                    else {
                        cabecalho();
                        printf("\nNAO EXISTE ESSE ID\n\n");
                        printf("1. Voltar para o menu?\n2.Sair\n");
                        scanf("%d", &auxiliar);
                        if(auxiliar==1) {
                            fclose(arquivo);
                            menu();
                        } else {
                            fclose(arquivo);
                            exit(0);

                        }

                    }
                    fclose(arquivo);
                }
                while(auxiliar == 3);
            } else {
                printf("\nNao existe nenhuma equipa cadastrada, cadastre quantas quiser\n");
                fclose(arquivo);
                cadastrarEquipes();
            }
        }
    }
    else {
        printf("\nPrimeiro cadastre uma equipe, pois nao tem alguma\n");
        fclose(arquivo);
        cadastrarEquipes();
    }
}


//Cadastra as equipes em um arquivo sem precisar guardar em um sitio intermediario como um array
void cadastrarEquipes()
{
    Equipa equipas;
    FILE* arquivo = fopen("testeE.txt", "ab");
    int auxiliar;
    if(arquivo == NULL)
    {
        printf("ERRRRRRRRRRRRRRRO");
    }
    else
    {
        do
        {
            fflush(stdin);
            printf("Incira o nome da equipe: ");
            gets(equipas.nome);
            //Atribuimos um id que nos mesmos criamos
            equipas.ID = nrDeElementosEquipes() + 1;
            fwrite(&equipas, sizeof(Equipa), 1, arquivo);
            fflush(stdin);
            printf("Deseja:1.Inserir outra equipa\n");
            printf("2.Voltar para o menu\n3.Sair. ");
            scanf("%d",&auxiliar);
            if(auxiliar==1) {
                cabecalho();
                fclose(arquivo);
                cadastrarEquipes();
            }
            else if(auxiliar==2) {
                cabecalho();
                fclose(arquivo);
                menu();
            }
            else if(auxiliar==3) {
                cabecalho();
                printf("\t\t\t\t\t\tOBRIGADO\n");
                fclose(arquivo);
                exit(0);
            }
            else {
                cabecalho();
                printf("Nao existe essa opcao;\n");
                printf("\t\t\t\t\t\tOBRIGADO\n");
                fclose(arquivo);
                exit(0);
            }
        }
        while(0);

    }
}


//Nr dos elementos que estao no arquivo dos equipes
int nrDeElementosEquipes() {
    Equipa equipas;
    int i=0;
    FILE* arquivo = fopen("testeE.txt", "rb");

    if(arquivo == NULL)
    {
        printf("ERRRRRRRRRRRRRRRRRRRO");
        return 0;
    }
    else
    {
        while(fread(&equipas, sizeof(Equipa), 1, arquivo) == 1)
        {
            /*Como o fread aqui usado vai linha por linha ele vai retornar
            o nr de linhas que significa nr de equipes  */
            i++;
        }
    }
    fclose(arquivo);
    return i;
}


//Nr dos elementos que estao no arquivo dos jogadores
int nrDeElementosJogadores() {
    Jogador jogadores;
    int i=0;
    FILE* arquivo = fopen("testeJ.txt", "rb");

    if(arquivo == NULL)
    {
        printf("ERRRRRRRRRRRRRRRRRRRO");
        return 0;
    }
    else
    {
        while(fread(&jogadores, sizeof(Jogador), 1, arquivo) == 1)
        {
            /*Como o fread aqui usado vai linha por linha ele vai retornar
              o nr de linhas que significa nr de jogadores  */
            i++;
        }
    }
    fclose(arquivo);
    return i;
}


//Mostra os elementos do "vector" Estruturas equipes sem precisar guardar em um sitio
void mostrarEquipes()
{
    Equipa equipas;
    FILE* arquivo = fopen("testeE.txt", "rb");
    if(arquivo == NULL)
    {
        printf("ERRRRRRRRRRRRRRRO");
    }
    else
    {
        while(fread(&equipas, sizeof(Equipa), 1, arquivo) == 1)
        {
            printf("\nNome: %s\n", equipas.nome);
            printf("ID: %d", equipas.ID);
            printf("\n----------------------------------------------------------------------------------\n");
        }
        fclose(arquivo);
    }

}


//Mostra os elementos do "vector" Estruturas jogadores sem precisar guardar em um sitio
void mostrarJogadores()
{
    cabecalho();
    Jogador jogadores;
    FILE* arquivo = fopen("testeJ.txt", "rb");

    if(arquivo == NULL)
    {
        printf("ERRRRRRRRRRRRRRRO");
    }
    else
    {
        while(fread(&jogadores, sizeof(Jogador), 1, arquivo) == 1)
        {

            printf("\nNome: %s\n", jogadores.nome);
            printf("ID: %d\n", jogadores.idE);
            printf("Id Jogador: %d\n", jogadores.idJo);
            printf("Nr de golos: %d\n", jogadores.nrDeGolos);
            printf("Data Inicio Contrato: %d/%d/%d", jogadores.dataInicio.dia, jogadores.dataInicio.mes, jogadores.dataInicio.ano);
            printf("Data Inicio Contrato: %d/%d/%d", jogadores.dataFim.dia,jogadores.dataFim.mes, jogadores.dataFim.ano);
            printf("\n----------------------------------------------------------------------------------\n");
        }
        fclose(arquivo);
    }

}


//Mostra os elementos do "vector" Estruturas jogadores sem precisar guardar em um sitio
void mostrarJogadorX()
{
    Jogador jogadores;
    int id;
    int auxiliar;
    FILE* arquivo = fopen("testeJ.txt", "rb");

    if(arquivo == NULL)
    {
        printf("ERRRRRRRRRRRRRRRO");
    }
    else
    {
        printf("Equipes presentes:\n");
        mostrarEquipes();

        fflush(stdin);
        printf("\nDigita o id da equipe que queres: ");
        scanf("%d",&id);
        //Verificamos se existe o id antes!
        if(existeId(id)==1) {
            while(fread(&jogadores, sizeof(Jogador), 1, arquivo) == 1)
            {
                //Verficamos o jogador eespecifico!
                if(id==jogadores.idE)
                {
                    printf("Nome: %s\n", jogadores.nome);
                    printf("Nr de golos: %d\n", jogadores.nrDeGolos);
                    printf("Data Inicio Contrato: %2d/%2d/%4d", jogadores.dataInicio.dia, jogadores.dataInicio.mes, jogadores.dataInicio.ano);
                    printf("Data Fim do Contrato: %2d/%2d/%4d", jogadores.dataFim.dia,jogadores.dataFim.mes, jogadores.dataFim.ano);
                    printf("\n----------------------------------------------------------------------------------\n");
                }
            }

        } else {
            cabecalho();
            printf("\nNAO EXISTE ESSE ID\n\n");
            printf("1. Voltar para o menu?\n2.Voltar a querer mostrar Jogador X\n3. Sair\n");
            scanf("%d", &auxiliar);
            if(auxiliar==1) {
                menu();
            }
            else if(auxiliar==2) {
                cabecalho();
                mostrarJogadorX();
            }
            else if(auxiliar==3) {
                cabecalho();
                printf("\t\t\t\t\t\tOBRIGADO\n");
                fclose(arquivo);
                exit(0);
            }
            else {
                cabecalho();
                printf("Nao existe essa opcao!");
                printf("\t\t\t\t\t\tOBRIGADO\n");
                fclose(arquivo);
                exit(0);
            }
        }
    }

    fclose(arquivo);
}


//Verifica se realmente existe a id que o isiario inseriu;
int existeId(int id) {
    Equipa equipas;
    FILE* arquivo = fopen("testeE.txt", "rb");
    int aux=0;
    if(arquivo == NULL)
    {
        printf("ERRRRRRRRRRRRRRRO");
        return 0;
    }
    else
    {
        while(fread(&equipas, sizeof(Equipa), 1, arquivo) == 1)
        {
            //Igualamos o id do usuario com o que vem do txt
            if(id==equipas.ID)
            {
                aux++;
            }
        }
        //Tem que ter somente uma igualidade, fora disso existe erro;
        if(aux==1) {
            fclose(arquivo);
            return 1;
        }
        fclose(arquivo);
        return 0;
    }


}



//Recebe os dados e como e um vector nao precisamos usar somente um ponteiro mas com o vector
//tambem aceita levar mudar o conteudo de um endereco e nao levar uma copia como as variaveis normais
void recebeDados(Jogador jogadores[]) {

    //Aqui vamos por o que vem do arquivo para depois dar ao arquivo
    Jogador jogador;

    int i = 0;
    FILE* arquivo = fopen("testeJ.txt", "rb");
    if(arquivo == NULL)
    {
        printf("ERRRRRRRRRRRRRRRO");
    }
    else
    {
        //Pomos os valores em um vector de jogadores
        while(fread(&jogador, sizeof(Jogador),1,arquivo)==1) {
            //So vai dar os jogadores de uma certa equipe
            //Aqui com ponteiros podes usar aquilo de *(ponteiro +i)
            jogadores[i] = jogador;
            i++;
        }
        fclose(arquivo);
    }


}


//Organiza em ordem decrescente a lista para nos facilitar a vida
void organizaDados(Jogador jogadores[]) {
    int aux = nrDeElementosJogadores();
    //Auxiliador para podermos organizar o vector para podermos levar o terceiro
    Jogador auxiliador[aux];
    int j;
    int i;
    if(aux<2) {//Caso tenha menos que 3 elementos vai dar erro
        printf("Errrrrrrrrro");
        return 0;
    } else {
        //Aqui organizamos o vectorem forma decrescente;
        for(i = 0; i<aux; i++) {
            for(j= i+1; j<aux; j++) {
                if( jogadores[i].nrDeGolos < jogadores[j].nrDeGolos) {
                    auxiliador[i]=jogadores[i];
                    jogadores[i]=jogadores[j];
                    jogadores[j]=auxiliador[i];
                }
            }

        }
    }
}


//Aqui onde eliminamos propriamente dito
void eliminaOTerceiro() {
    int aux = nrDeElementosJogadores();
    Jogador jogadores[aux];
    //Fizemos com que o vector jogadores rebece todos os dados da txt usando vectores
    recebeDados(jogadores);
    organizaDados(jogadores);
    FILE* arquivo1 = fopen("testeJ.txt", "w");
    if(arquivo1 ==NULL) {
        printf("ERRRRRRRRRRRRRRRO");
    } else {
        int y;
        int auxiliador;
        Jogador jogador;
        for(y=0; y<aux; y++) {
            //Escrevemos todos menos o elemento da terceira posicao
            if(y!=2) {
                jogador = jogadores[y];
                fwrite(&jogador, sizeof(Jogador), 1, arquivo1);
            }
        }
        fclose(arquivo1);
        cabecalho();
        printf("\t\t\t\t\t\tExcluido com sucesso!\n\n");
        printf("Deseja: \n");
        printf("1.Voltar ao menu principal\n2.Voltar a eliminar o terceiro maior");
        printf("\n3.Sair\n4.Mostrar Todos jogadores\n: ");
        scanf("%d",&auxiliador);
        if(auxiliador==1) {
            cabecalho();
            menu();
        } else if (auxiliador==2) {
            cabecalho();
            eliminaOTerceiro();
        }
        else if(auxiliador==3) {
            cabecalho();
            printf("\t\t\t\t\t\tOBRIGADO\n");
            exit(0);
        }
        else if(auxiliador==4) {
            cabecalho();
            mostrarJogadores();
        }
        else {
            cabecalho();
            printf("Nao existe essa opcao!");
            printf("\t\t\t\t\t\tOBRIGADO\n");
            exit(0);
        }
    }
}


//Buscamos um jogador especifico
int idJogador() {
    int valor = 0;
    FILE* arquivo = fopen("jogadorId.txt", "rb");

    if(arquivo == NULL)
    {
        //Se nao existir criamos um novo txt se existir o conteúdo anterior será destruído
        FILE* arquivo = fopen("jogadorId.txt", "ab");
        //Inicializamos o arquivo com 0
        fprintf(arquivo,"%d",0);
        fclose(arquivo);
        //Deixamos aberto o arquivo para leitura
        arquivo = fopen("jogadorId.txt", "r");
    }

    //Trazemos o valor do txt
    fscanf(arquivo,"%d",&valor);
    fclose(arquivo);
    //Voltamos a abrir o txt, em um modo que vai apagar todo o conteudo qe tinha la no txt
    arquivo = fopen("jogadorId.txt","w");
    //Depois escrevemos o novo conteudo incrementando 1 e assim nunca sera o mesmo valor
    fprintf(arquivo,"%d",valor+1);
    fclose(arquivo);
    //Devolvemos tambem o mesmo valor da txt, onde semrpe sempre esera unico
    return valor+1;
}


//Menu de navegacao do usuario
void menu() {
    int aux;
    do {
        cabecalho();
        printf("\t\t\t\t1.Cadastrar\n");
        printf("\t\t\t\t2.Mostrar Jogador de equipa X\n");
        printf("\t\t\t\t3.Cadastrar equipas\n");
        printf("\t\t\t\t4.Eliminar o terceiro maior\n\t\t\t\t5.Mostrar Todos jogadores\n: ");
        printf("\t\t\t\t6.Sair\n");
        scanf("%d", &aux);

        switch(aux)
        {
        case 1:
            cabecalho();
            cadastrarJogadores();
            break;

        case 2:
            cabecalho();
            mostrarJogadorX();
            break;
        case 3:
            cabecalho();
            cadastrarEquipes();
            break;
        case 4:
            eliminaOTerceiro();
            break;
        case 5:
            mostrarJogadores();
            break;
        case 6:
            cabecalho();
            printf("\t\t\t\t\t\tOBRIGADO\n");
            exit(0);
        }
        printf("\nDeseja sair?\n s para Sim e n para Nao\n");
    } while(getche() != 's');
    cabecalho();
    printf("\t\t\t\t\t\tOBRIGADO\n");
}


//Cabecalho para evitar escrever o obvio toda hora
void cabecalho()
{
    //Aqui fax com que todo em cima seja apagado!
    system("cls");
    printf("\t***************************************");
    printf(" PRACTICA1 ***************************************\n\n");
}

