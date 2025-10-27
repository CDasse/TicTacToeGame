#include <stdio.h>
#include <stdlib.h>


// Déclaration de l'énumération contenant toute les positions possibles pour chaque case
typedef enum tile_state_e {
    PLAYER1,
    PLAYER2,
    EMPTY
} tile_state_t;


// Fonction qui met à zero la grille
void reset_table(tile_state_t table[3][3]){
    for (int i=0; i < 3; i++){
        for (int j=0; j < 3; j++) {
            table[i][j] = EMPTY;
        }
}
}


// Fonction qui permet d'afficher la grille dans la console
void print_table(tile_state_t table[3][3]) {
    for (int i=0; i < 3; i++){
        for (int j=0; j < 3; j++) {
            char symbole = 0;
            switch (table[i][j]){
                case EMPTY: symbole = '.'; break;
                case PLAYER1: symbole = 'X'; break;
                case PLAYER2: symbole = 'O'; break;
            }
            printf(" %c ", symbole);
        }
        printf("\n");
    }
    printf("\n");
}


// Fonction qui demande au joueur 1 de jouer et modifier la case citée
void move_player1(tile_state_t table[3][3]) {

    int choice_x_player1 = 0;
    int choice_y_player1 = 0;
  
    do {

        printf("Tour du joueur 1 : Dans quelle ligne souhaitez-vous jouer ? (chiffres entre 1 et 3)\n");

        do {
            scanf("%d", &choice_x_player1);
        } while (!((1 <= choice_x_player1) && (choice_x_player1 <= 3)));

        printf("Tour du joueur 1 : Dans quelle colonne souhaitez-vous jouer ? (chiffres entre 1 et 3)\n");

        do {
            scanf("%d", &choice_y_player1);
        } while (!((1 <= choice_y_player1) && (choice_y_player1 <= 3)));

        printf("Voici votre choix : ligne = %d, colonne = %d\n", choice_x_player1, choice_y_player1);

    } while (!(table[choice_x_player1 - 1][choice_y_player1 - 1] == EMPTY));

    table[choice_x_player1 - 1][choice_y_player1 - 1] = PLAYER1;
}


// Fonction qui demande au joueur 2 de jouer et modifier la case citée
void move_player2(tile_state_t table[3][3]) {
       
    int choice_x_player2 = 0;
    int choice_y_player2 = 0;

    do  {

        printf("Tour du joueur 2 : Dans quelle ligne souhaitez-vous jouer ? (chiffres entre 1 et 3)\n");

        do {
            scanf("%d", &choice_x_player2);
        } while (!((1 <= choice_x_player2) && (choice_x_player2 <= 3)));

        printf("Tour du joueur 2 : Dans quelle colonne souhaitez-vous jouer ? (chiffres entre 1 et 3)\n");
        
        do {
            scanf("%d", &choice_y_player2);
        } while (!((1 <= choice_y_player2) && (choice_y_player2 <= 3)));

        printf("Voici votre choix : ligne = %d, colonne = %d\n", choice_x_player2, choice_y_player2);
    
    } while (!(table[choice_x_player2 - 1][choice_y_player2 - 1] == EMPTY));

    table[choice_x_player2 - 1][choice_y_player2 - 1] = PLAYER2;

}


// Fonciton qui vérifie si un joueur à gagné
void is_win(tile_state_t table[3][3]) {
    
    int ligne_1 = (table[0][0]==table[0][1] && table[0][1]==table[0][2] && table[0][0] != EMPTY);
    int ligne_2 = (table[1][0]==table[1][1] && table[1][1]==table[1][2] && table[1][0] != EMPTY);
    int ligne_3 = (table[2][0]==table[2][1] && table[2][1]==table[2][2] && table[2][0] != EMPTY);
    int diag_1 = (table[0][0]==table[1][1] && table[1][1]==table[2][2] && table[0][0] != EMPTY);
    int diag_2 = (table[2][0]==table[1][1] && table[1][1]==table[0][2] && table[2][0] != EMPTY);

    if (ligne_1 || ligne_2 || ligne_3 || diag_1 || diag_2) {
        printf("Félicitation !\n");
    } else {
        printf("Tour suivant !\n");
    }

}


int main(void){

tile_state_t table[3][3];

reset_table(table);

print_table(table);

for (int i = 0; i <= 9; i++) {
move_player1(table);

print_table(table);

is_win(table);

move_player2(table);

print_table(table);

is_win(table);
}

    return 0;
}