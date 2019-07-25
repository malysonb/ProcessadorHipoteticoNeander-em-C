#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define NOP		0       //Ignorado pelo programa.
#define STA		16      //Armazena o valor contido no ACUMULADOR em um endere�o de DADOS.
#define LDA		32      //Carrega um valor contido num endere�o de DADOS para o ACUMULADOR.
#define ADD		48      //Incrementa o ACUMULADOR com um valor contido num endere�o de DADOS.
#define OR		64      //Usa o calculo OR do acumulador com um valor contido num endere�o de DADOS.
#define AND		80      //Usa o calculo AND do acumulador com um valor contido num endere�o de DADOS.
#define NOT		96      //Inverte o ACUMULADOR/Deixa o ACUMULADOR negativo.
#define JMP		128     //Pula o PC para um endere�o de INSTRU��ES/PROGRAMA.
#define JN		144     //Pula o PC para um endere�o de INSTRU��ES/PROGRAMA se o ACUMULADOR for negativo.
#define JZ		160     //Pula o PC para um endere�o de INSTRU��ES/PROGRAMA se o ACUMULADOR for ZERO.
#define HLT		240     //Termina o Programa.

int main() {
    system("title Processador Hipotetico Neander em C");
    setlocale(LC_ALL,"");
    FILE *processo;         //ARQUIVO
    int memoria[256];       //0-127 para instru��es de programa/128-255 para Dados.
    int PC;                 //Ponteiro Hipotetico e Contador
    int acumulador = 0;     //Espa�o na memoria para acumular valores antes de serem usados. (8-BITS)
    int automatico = 0;     //SE VAI SER PASSO OU AUTOMATICO
    char select[1];
    system("cls || clear");
    printf("\n\t\tProcessador Hipotetico Neander em C\n\n\n\n\nDeseja executar passo a passo?\nS/N: ");
    scanf("%s",&*select);
    if(strcmp(select,"s")== 0 || strcmp(select,"S")== 0) {
        automatico = 0;
    } else {
        automatico = 1;
    }
    fflush(stdin);


    processo = fopen("Processo.txt","rt"); //Irá procurar o arquivo Processo.txt na pasta local, e usar� apenas leitura.
    if(processo == NULL) { //Se n�o encontrar processo.txt.
        printf("N�o foi encontrado o arquivo Processo.txt. Finalizando.");
        getchar();
        return 1;
    }
    /*Ir� armazenar todos os valores dos arquivos na memoria*/
    int i = 0;
    while(!feof(processo)) { //Enquanto conseguir ler.
        fscanf(processo,"%d",&memoria[i]);
        i++;
    }
    for(PC = 0; PC < 127; PC++) {
        if(automatico == 0){
            printf("Pressione ENTER para o proximo passo\n");
            getchar();
            system("@cls || clear");
        }
        else{
			system("@cls || clear");
		}
        int registro = memoria[PC+1];
        int neg = memoria[PC-1];
        switch (memoria[PC]) { //MENSAGENS E A��ES QUE OCORREM A CADA INSTRU��O.
        default:
            printf("|\n|\n|\n");
            break;
 	    case NOP:
 	    	printf("|\n|\n|\n");
  		  	  	break;
        case STA:
            memoria[registro] = acumulador;
            printf("Instru��o 16 = STA: Valor do acumulador: %d\n Foi armazenado no endere�o da memoria %d\n\n",acumulador,memoria[PC+1]);
            break;
        case LDA:
            acumulador = memoria[registro];
            printf("Instru��o 32 = LDA: Valor armazenado no acumulador. Agora �: %d\n Foi definido pelo valor do endere�o de memoria memoria %d\n\n",acumulador,memoria[PC+1]);
            break;
        case ADD:
            if(acumulador + memoria[registro] >= 256){
                acumulador = (acumulador + memoria[registro]) - 256;
            }
            else{
                acumulador += memoria[registro];
            }
            printf("Instru��o 48 = ADD: Valor do acumulador agora �: %d\n Foi incrementado pelo valor do endere�o de memoria %d\n\n",acumulador,memoria[PC+1]);
            break;
        case OR:
            acumulador = acumulador | registro;
            printf("Instru��o 80 = AND: Valor do acumulador agora �: %d\n Foi Calculado o valor do ACUMULADOR OR %d do endere�o %d\n\n",acumulador,registro,memoria[PC]);
            break;
        case AND:
            acumulador = acumulador & registro;
            printf("Instru��o 80 = AND: Valor do acumulador agora �: %d\n Foi Calculado o valor do ACUMULADOR AND %d do endere�o %d\n\n",acumulador,registro,memoria[PC]);
            break;
        case NOT:
            acumulador = 255 - acumulador;
            printf("Instru��o 96 = NOT: O acumulador foi alternado os bits para um valor negativo/positivo Agora �: %d\n\n",acumulador);
            break;
        case JMP:
            if(neg == ADD || neg == LDA) {
                printf("|\n|\n|\n");
                break;
            } else {
                PC = registro;
                printf("Instru��o 128 = JMP: PC pulou para o endere�o %d, PC = %d\n\n\n",registro,PC);
                break;
            }
            break;
        case JN:
            if(neg == LDA || neg == ADD) {
                printf("|\n|\n|\n");
                break;
            } else {
                if(acumulador > 127) {
                    PC = registro;
                    printf("Instru��o 144 = JN: O Acumulador est� negativo\n pulando PC para %d\n\n\n",registro);
                    break;
                } else {
                    printf("Instru��o 144 = JN: O Acumulador N�O est� negativo\n O programa ir� continuar para a proxima instru��o\n\n");
                    break;
                }
            }
            break;
        case JZ:
            if(neg == LDA || neg == ADD) {
                printf("|\n|\n|\n");
                break;
            } else {
                if(acumulador == 0) {
                    PC = registro;
                    printf("Instru��o 160 = JZ: O Acumulador est� vazio\n pulando PC para %d\n\n",registro);
                    break;
                } else {
                    printf("Instru��o 160 = JZ: O Acumulador N�O est� vazio\n O programa ir� continuar para a proxima instru��o\n\n");
                    break;
                }
            }
        }
        /*--------TABELA EXIBIDA NA TELA--------*/
        int temp = 0;
        int temp2 = 0;
        int inst[128];
        int data[128];
        for(temp = 0; temp < 255; temp++){
            if(temp < 127){
                inst[temp] = memoria[temp];
            }
            if(temp >= 128){
                data[temp2] = memoria[temp];
                temp2++;
            }
        }
        printf("Instru��es[0-127]\t\tDados[128-255] ACUMULADOR: %d\n",acumulador);
        for(temp = 0; temp < 127;temp++){
            if(inst[temp] > 0 || data[temp] > 0){
                if(inst[temp] == memoria[PC] && temp == PC){
                    printf("->%d\t\t\t\t%d\n",inst[temp],data[temp]);
                }
            }
            if(inst[temp] > 0 || data[temp] > 0){
                if(inst[temp] == memoria[PC] && temp != PC){
                    printf("%d\t\t\t\t%d\n",inst[temp],data[temp]);
                }
            }
            if(inst[temp] > 0 || data[temp] > 0){
                if(inst[temp] != memoria[PC]){
                    printf("%d\t\t\t\t%d\n",inst[temp],data[temp]);
                }
            }else if(inst[temp-1] > 0 ||data[temp-1] > 0){printf("%d\t\t\t\t%d\n",inst[temp],data[temp]);}
        }
                /*--------FIM DA TABELA--------*/
		if(memoria[PC] == HLT){
            if(neg == LDA || neg == ADD) {

            } else {
                printf("\nInstru��o 240 = HLT: Programa finalizado!\n");
                getchar();
                return 0;
            }
        }
    }
    printf("\nPrograma Finalizado sem HALT/Indefinido.\n");
    getchar();
    return 0;
}
