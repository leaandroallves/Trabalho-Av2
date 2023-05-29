#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int jogo_da_adivinhacao(){
 int n, num, max=5000, min=1;
srand(time(NULL));
n = (rand() % 5000)+ 1;
printf("O numero esta entre %d e %d\n", min, max);
do{
printf("Digite um numero:");
scanf("%d", &num);
if(num<max &&num>n)
	max=num;

else if(num>min && num<n)
	min=num;

else if(num==n)
	break;
printf("Errou! O numero esta entre %d e %d\n",min,max);	
}while(num!=n);
printf("Parabens! Voce acertou!\n");

}

int jogo_da_velha(){


      // estrutura de dados?
    int l, c, linha, coluna, jogador, ganhou, jogadas, opcao;
    char jogo[3][3];

    do{ // jogar novamente?
        jogador = 1;
        ganhou = 0;
        jogadas = 0;
        
        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                jogo[l][c] = ' ';
            }
        }

        do{ 
            printf("\n\n\t 0   1   2\n\n");
            for(l = 0; l < 3; l++){
                for(c = 0; c < 3; c++){
                    if(c == 0)
                        printf("\t");
                    printf(" %c ", jogo[l][c]);
                    if(c < 2)
                        printf("|");
                    if(c == 2)
                        printf("  %d", l);
                }
                if(l < 2)
                    printf("\n\t-----------");
                printf("\n");
            }

            
            do{
                printf("\n\JOGADOR 1 = 0\nJOGADOR 2 = X\n");
                printf("\nJOGADOR %d: Digite a linha e a coluna que deseja jogar: ", jogador);
                scanf("%d%d", &linha, &coluna);
            }while(linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || jogo[linha][coluna] != ' ');

           
            if(jogador == 1){
                jogo[linha][coluna] = '0';
                jogador++;
            }
            else{
                jogo[linha][coluna] = 'X';
                jogador = 1;
            }
            jogadas++;

           
            if(jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
               jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] == '0' ||
               jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu por linha!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
               jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X' ||
               jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu por linha!\n");
                ganhou = 1;
            }

             
            if(jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
               jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
               jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu por coluna!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
               jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
               jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu por coluna!\n");
                ganhou = 1;
            }

            // alguém ganhou na diagonal principal
            if(jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0'){
                printf("\nParabens! O jogador 1 venceu na diag. principal!\n");
                ganhou = 1;
            }

            if(jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X'){
                printf("\nParabens! O jogador 2 venceu na diag. principal!\n");
                ganhou = 1;
            }

            // alguém ganhou na diagonal secundária
            if(jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[2][0] == '0'){
                printf("\nParabens! O jogador 1 venceu na diag. secindaria!\n");
                ganhou = 1;
            }

            if(jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X'){
                printf("\nParabens! O jogador 2 venceu na diag. secundaria!\n");
                ganhou = 1;
            }
        }while(ganhou == 0 && jogadas < 9);

        // imprimir jogo
        printf("\n\n\t 0   1   2\n\n");
        for(l = 0; l < 3; l++){
            for(c = 0; c < 3; c++){
                if(c == 0)
                    printf("\t");
                printf(" %c ", jogo[l][c]);
                if(c < 2)
                    printf("|");
                if(c == 2)
                    printf("  %d", l);
            }
            if(l < 2)
                printf("\n\t-----------");
            printf("\n");
        }

        if(ganhou == 0)
            printf("\nO jogo finalizou sem gamhador!\n");

        printf("\nDigite 1 para jogar novamente: \n");
        scanf("%d", &opcao);
    }while(opcao == 1);

    return 0;
}

       
int main(void) {
  int jogo;
  printf("Seja Bem-Vindo ao Menu dos Jogos\n\n");
  printf("Escolha um jogo:\n1)Jogo Da Memoria\n2)Jogo Da Velha\n3)Jogo Da Adivinhacao\n ");
  scanf("%d", &jogo);
  switch(jogo){
    case 1:
    printf("\nSeja Bem-Vindo ao Jogo da Memoria");
      
    break;

    case 2:
    printf("\nSeja Bem-Vindo ao Jogo da Velha\n\n");
      jogo_da_velha();
    break;

    case 3:
    printf("\nSeja Bem-Vindo ao Jogo da Adivinhacao\n\n");
    jogo_da_adivinhacao();
    break;
    default:
    printf("ERRO! TENTE DE NOVO");
    break;
  }

  
  return 0;
}