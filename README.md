# Processador Hipotetico Neander em C

### Mais informações leia o "Leia-me.txt"

Este programa simula o funcionamento de um processador 8 bits

O programa simula um armazenamento de memoria em 8 bits

Mini-Documentação do Programa:
PROCESSADOR HIPOTETICO NEANDER

O Programa só irá rodar se houver um arquivo de texto chamado "Processo.txt".

O programa já vem com o Processo.txt de exemplo com 256 linhas
sendo dividido em duas partes:

Linha 0 à 127		—Instruções/Programa.

Linha 128 à 255		—Dados/Variaveis.

Recomendo usar NOTEPAD++ para editar o Processo.txt, ou qualquer outro que mostre o numero de linhas.

*LEMBRE-SE: A PRIMEIRA LINHA É RECONHECIDA COMO LINHA 0(ZERO)*

*LEMBRE-SE: ESTE PROGRAMA SIMULA O PROCESSADOR NEANDER QUE É UM PROCESSADOR 8BITS*
________________________________________________________________
Deve tratar os numeros como:

#### Positivo
0-127
#### Negativo
128-255

________________________________________________________________

Legenda:
NOP	0//Ignorado pelo programa.

STA	16//Armazena o valor contido no ACUMULADOR em um endereço de DADOS.

LDA	32//Carrega um valor contido num endereço de DADOS para o ACUMULADOR.

ADD	48//Incrementa ao ACUMULADOR um valor contido num endereço de DADOS.

OR	64//Usa o calculo OR do acumulador com um valor contido num endereço de DADOS.

AND	80//Usa o calculo AND do acumulador com um valor contido num endereço de DADOS.

NOT	96//Inverte o ACUMULADOR/Deixa o ACUMULADOR negativo.

JMP	128//Pula o PC para um endereço de INSTRUÇÃO/PROGRAMA.

JN	144//Pula o PC para um endereço de INSTRUÇÃO/PROGRAMA se o ACUMULADOR for negativo.

JZ	160//Pula o PC para um endereço de INSTRUÇÃO/PROGRAMA se o ACUMULADOR for ZERO.

HLT	240//Termina o Programa

#### Porfavor, se for reutilizar este código em algum trabalho academico, adicione o link desta pagina nas referencias.

#### Se for reutilizar este codigo em algum projeto (monetizado ou não), contate comigo.
