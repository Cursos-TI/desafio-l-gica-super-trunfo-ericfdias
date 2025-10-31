/*
  super_trunfo.c
*/
#include <stdio.h>

typedef struct {
    char estado[50];
    char codigo[20];
    char nome[100];
    int populacao;
    double area;
    double pib;
    int pontos_turisticos;
    double densidade;
    double pib_per_capita;
} Carta;

typedef enum {
    POPULACAO = 1,
    AREA,
    PIB,
    DENSIDADE,
    PIB_PER_CAPITA
} AtributoComparacao;

int main(void) {
    Carta carta1 = {
        "SP",
        "C1-SP",
        "São Paulo",
        12300000,
        1521.11,
        700000000.0,
        50
    };

    Carta carta2 = {
        "RJ",
        "C2-RJ",
        "Rio de Janeiro",
        6000000,
        1182.3,
        350000000.0,
        40
    };

    carta1.densidade = (carta1.area != 0) ? (double)carta1.populacao / carta1.area : 0.0;
    carta2.densidade = (carta2.area != 0) ? (double)carta2.populacao / carta2.area : 0.0;
    carta1.pib_per_capita = (carta1.populacao != 0) ? carta1.pib / (double)carta1.populacao : 0.0;
    carta2.pib_per_capita = (carta2.populacao != 0) ? carta2.pib / (double)carta2.populacao : 0.0;

    AtributoComparacao atributo_escolhido = POPULACAO;

    printf("=== Cartas cadastradas ===\n\n");

    printf("Carta 1 - %s (%s)\n", carta1.nome, carta1.estado);
    printf("  Codigo: %s\n", carta1.codigo);
    printf("  Populacao: %d\n", carta1.populacao);
    printf("  Area: %.2f km2\n", carta1.area);
    printf("  PIB: %.2f\n", carta1.pib);
    printf("  Pontos turisticos: %d\n", carta1.pontos_turisticos);
    printf("  Densidade: %.2f hab/km2\n", carta1.densidade);
    printf("  PIB per capita: %.2f\n\n", carta1.pib_per_capita);

    printf("Carta 2 - %s (%s)\n", carta2.nome, carta2.estado);
    printf("  Codigo: %s\n", carta2.codigo);
    printf("  Populacao: %d\n", carta2.populacao);
    printf("  Area: %.2f km2\n", carta2.area);
    printf("  PIB: %.2f\n", carta2.pib);
    printf("  Pontos turisticos: %d\n", carta2.pontos_turisticos);
    printf("  Densidade: %.2f hab/km2\n", carta2.densidade);
    printf("  PIB per capita: %.2f\n\n", carta2.pib_per_capita);

    double valor1 = 0.0, valor2 = 0.0;
    const char *nome_atributo = NULL;
    int menor_vence = 0;

    switch (atributo_escolhido) {
        case POPULACAO:
            nome_atributo = "Populacao";
            valor1 = (double)carta1.populacao;
            valor2 = (double)carta2.populacao;
            menor_vence = 0;
            break;
        case AREA:
            nome_atributo = "Area (km2)";
            valor1 = carta1.area;
            valor2 = carta2.area;
            menor_vence = 0;
            break;
        case PIB:
            nome_atributo = "PIB";
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            menor_vence = 0;
            break;
        case DENSIDADE:
            nome_atributo = "Densidade populacional (hab/km2)";
            valor1 = carta1.densidade;
            valor2 = carta2.densidade;
            menor_vence = 1;
            break;
        case PIB_PER_CAPITA:
            nome_atributo = "PIB per capita";
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            menor_vence = 0;
            break;
        default:
            printf("Atributo invalido. Encerrando.\n");
            return 1;
    }

    printf("Comparacao de cartas (Atributo: %s):\n\n", nome_atributo);
    printf("Carta 1 - %s (%s): ", carta1.nome, carta1.estado);
    if (atributo_escolhido == POPULACAO) printf("%.0f\n", valor1);
    else printf("%.2f\n", valor1);
    printf("Carta 2 - %s (%s): ", carta2.nome, carta2.estado);
    if (atributo_escolhido == POPULACAO) printf("%.0f\n\n", valor2);
    else printf("%.2f\n\n", valor2);

    if (valor1 == valor2) {
        printf("Resultado: Empate! Ambos os valores sao iguais.\n");
    } else if (menor_vence) {
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu! (%.2f < %.2f)\n", carta1.nome, valor1, valor2);
        } else {
            printf("Resultado: Carta 2 (%s) venceu! (%.2f < %.2f)\n", carta2.nome, valor2, valor1);
        }
    } else {
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu! (%.2f > %.2f)\n", carta1.nome, valor1, valor2);
        } else {
            printf("Resultado: Carta 2 (%s) venceu! (%.2f > %.2f)\n", carta2.nome, valor2, valor1);
        }
    }

    return 0;
}
