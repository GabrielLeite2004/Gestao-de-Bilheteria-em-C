#include <stdio.h>
#include <locale.h>
int PoltronasCompradas = 0;
float valor = 50;

struct Poltrona {
    char nome[50];
    float valor;
    int status;
};

struct Poltrona poltronas[7][7];

void ExibirStatus() {
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            printf("%d ", poltronas[x][y].status);
        }
        printf("\n");
    }
}

void Reservar() {
    system("cls");
    int x, y;
    printf("\nDetermine a poltrona a ser reservada: ");
    scanf("%d %d", &x, &y);

    if (poltronas[x][y].status == 2) {
        printf("\nEssa poltrona já está reservada");
        return;
    }
    if (poltronas[x][y].status == 3) {
        printf("\nEssa poltrona está comprada");
        return;
    }
    if (poltronas[x][y].status == 4) {
        printf("\nEssa poltrona está bloqueada");
        return;
    }
    PoltronasCompradas++;
    poltronas[x][y].status = 2;
    printf("Poltrona reservada com sucesso\n\n");
}

void Comprar() {
    system("cls");
    int x, y;
    printf("Determine a poltrona a ser comprada: ");
    scanf("%d %d", &x, &y);

    if (poltronas[x][y].status == 2) {
        printf("\nEssa poltrona está reservada");
        return;
    }
    if (poltronas[x][y].status == 3) {
        printf("\nEssa poltrona já está comprada");
        return;
    }
    if (poltronas[x][y].status == 4) {
        printf("\nEssa poltrona está bloqueada");
        return;
    }
    PoltronasCompradas++;
    poltronas[x][y].status = 3;
    printf("Poltrona comprada com sucesso\n\n");
}

void Bloquear() {
    system("cls");
    int x, y;
    printf("Determine a poltrona a ser bloqueada: ");
    scanf("%d %d", &x, &y);

    if (poltronas[x][y].status == 2) {
        printf("\nEssa poltrona está reservada");
        return;
    }
    if (poltronas[x][y].status == 3) {
        printf("\nEssa poltrona está comprada");
        return;
    }
    if (poltronas[x][y].status == 4) {
        printf("\nEssa poltrona já está bloqueada");
        return;
    }
    poltronas[x][y].status = 4;
    printf("Poltrona bloqueada com sucesso\n\n");
}

void Salvar() {
    FILE *arq = fopen("Bilheteria.bin", "wb");
    if (arq) {
        fwrite(poltronas, sizeof(struct Poltrona), 7 * 7, arq);
        fscanf(arq,"%d\n",PoltronasCompradas);
        fclose(arq);
    } else {
        printf("Erro: não foi possível abrir o arquivo para salvar.\n");
    }
}

void Retornar() {
    FILE *arq = fopen("Bilheteria.bin", "rb");
    if (arq) {
        fread(poltronas, sizeof(struct Poltrona), 7 * 7, arq);
        fprintf(arq,"%d\n",PoltronasCompradas);
        fclose(arq);
    } else {
    for (int x = 0; x < 7; x++) {
            for (int y = 0; y < 7; y++) {
                poltronas[x][y].status = 1;
            }
    }
    printf("Erro: não foi possível abrir o arquivo para carregar.\n");
}}

int main() {
    int escolha;
    setlocale(LC_ALL, "portuguese");
    Retornar();
    do {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1 - Exibir status das poltronas (matriz)\n");
        printf("2 - Reservar\n");
        printf("3 - Comprar\n");
        printf("4 - Bloquear\n");
        printf("5 - Total arrecado\n");
        printf("6 - Sair e salvar\n--> ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                ExibirStatus();
                break;
            case 2:
                Reservar();
                break;
            case 3:
                Comprar();
                break;
            case 4:
                Bloquear();
                break;
            case 5:
                printf("\n O total arrecado pela bilheteria foi: R$%.2f\n",PoltronasCompradas*valor);
                break;
            case 6:
                printf("Saindo e salvando...\n");
                break;
            default:
                printf("Escolha inválida. Tente novamente.\n");
        }
    } while (escolha != 6);

    Salvar();
    return 0;
}
