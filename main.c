#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int line(char caractere, int length){
    int c;
    for (c = 0; c < length; c++){
        printf("%c", caractere);
    }
    printf("\n");
    return 0;
}

int main(void){
    do {
        printf("\e[1;1H\e[2J");
        srand(time(NULL));

        //Definindo as opções e a ordem de resultados
        int options[5] = {3, 1, 2, 3, 1};
        int c, length = sizeof(options)/sizeof(options[0]);
        char *itens[3] = {"Pedra", "Papel", "Tesoura"};
        char restart;
        int usuario, maquina = rand() % 3;

        printf("  JO-KEN-PO!!  \n");
        line('=' ,15);

        //Fazendo um looping na lista onde aparece os itens
        for (c = 1; c < length-1; c++){
            printf("[%d] - %s\n", options[c], itens[c-1]);
        }
        line('=', 15);
        printf("//: ");
        scanf("%d", &usuario);
        usuario--;
        printf("\n\n");

        //Verificando resultado
        if (options[usuario] == maquina+1){ //usuario = 0 = Pedra / oprions[0] == 3 se maquina == 3 é vitória
            printf("Vitoria!");
        }
        else if (usuario+1 == options[maquina]){
            printf("Derrota!");
        }
        else {
            printf("Empate!");
        }
        printf("\n\nO usuario escolheu: %s", itens[usuario]);
        printf("\nO Computador escolheu: %s\n", itens[maquina]);
        printf("\nJogar novamente? [S/N]: ");
        scanf("%s", &restart);
        if (strcmp(&restart, "n") == 0 || strcmp(&restart, "N") == 0){
            break;
        }
    } while (1 == 1);

    return 0;
}
