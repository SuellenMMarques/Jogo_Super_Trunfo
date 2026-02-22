#include <stdio.h>
#include <string.h>

int main(){
    //Saudação inicial do jogo, explicando o que é o jogo e dando as instruções para o usuário digitar as informações das cartas corretamente
    printf("Olá Jogador(a), esse é o jogo Super Trunfo, um jogo de comparação de cartas! Vamos jogar?\n");
    printf("O objetivo do jogo é comparar as cartas e ver qual é a melhor, ou seja, qual tem os melhores atributos. \n");
    printf("Para começar retire duas cartas aleatórias!\n");
    printf("Agora digite CORRETAMENTE as informações contidas nas suas cartas conforme solitadas abaixo:\n");

    //Declarando as variaveis que serão usadas para armazenar as informações das cartas
    char estado1, estado2, codigo1[10], codigo2[10], cidade1[50], cidade2[50];
    int popul1, popul2, pontos_turisticos1, pontos_turisticos2;
    float area1, area2, PIB1, PIB2, dpopul1, dpopul2, PIB_per_capita1, PIB_per_capita2;

    //Solicitando as informações da carta 1 para o usuário
    printf("Qual o ESTADO da Carta 1 (ex: C): ");
    scanf(" %c", &estado1);

    printf("Qual o CÓDIGO da Carta 1 (ex: C01): ");
    scanf("%s", codigo1);

    printf("Qual a CIDADE da Carta 1 (ex: ARACAJU): ");
    scanf("%s", cidade1);

    printf("Qual a POPULAÇÃO da Carta 1 (ex: 12345678): ");
    scanf("%d", &popul1);

    printf("Qual a ÁREA DA CIDADE da Carta 1 em km² (ex: 1234.56): ");
    scanf("%f", &area1);

    printf("Qual o PIB DA CIDADE da Carta 1 em Bilhões de Reais (ex: 12.34): ");
    scanf("%f", &PIB1);

    printf("Quantos PONTOS TURÍSTICOS a cidade da Carta 1 possui (ex: 12): ");
    scanf("%d", &pontos_turisticos1);
    printf("\n");

    //Repetindo o mesmo processo para a Carta 2
    printf("Agora digite as informações da Carta 2, assim como você fez com a Carta 1. \n");

    printf("Qual o ESTADO da Carta 2 (ex: D): ");
    scanf(" %c", &estado2);

    printf("Qual o CÓDIGO da Carta 2 (ex: D03): ");
    scanf("%s", codigo2);

    printf("Qual a CIDADE da Carta 2 (ex: FORTALEZA): ");
    scanf("%s", cidade2);

    printf("Qual a POPULAÇÃO da Carta 2 (ex: 12345678): ");
    scanf("%d", &popul2);

    printf("Qual a ÁREA DA CIDADE da Carta 2 em km² (ex: 1234.56): ");
    scanf("%f", &area2);

    printf("Qual o PIB DA CIDADE da Carta 2 em Bilhões de Reais (ex: 12.34): ");
    scanf("%f", &PIB2);

    printf("Quantos PONTOS TURÍSTICOS a cidade da Carta 2 possui (ex: 12): ");
    scanf("%d", &pontos_turisticos2);
    printf("\n");

    //Calculando a densidade populacional e o PIB per capita para ambas as cartas

    dpopul1 = (float)popul1 / area1;
    dpopul2 = (float)popul2 / area2;

    PIB_per_capita1 = (PIB1 * 1000000000.0) / (float)popul1;
    PIB_per_capita2 = (PIB2 * 1000000000.0) / (float)popul2;

    //Mostrando as informações da carta 1 e 2 para que o usuário faça a comparação
    printf("Essas são as informações das cartas que você digitou: \n");
    printf("\n");

    printf("Carta 1: \n");
    printf("ESTADO: %c\n", estado1);
    printf("CÓDIGO: %s\n", codigo1);
    printf("CIDADE: %s\n", cidade1);
    printf("POPULAÇÃO: %d\n", popul1);
    printf("ÁREA: %.2f km²\n", area1);
    printf("PIB: R$ %.2f Bilhões de Reais\n", PIB1);
    printf("PONTOS TURÍSTICOS: %d\n", pontos_turisticos1);
    printf("DENSIDADE POPULACIONAL: %.2f habitantes/km²\n", dpopul1);
    printf("PIB PER CAPITA: R$ %.2f Reais/hab\n", PIB_per_capita1);

    printf("\nCarta 2: \n");
    printf("ESTADO: %c\n", estado2);
    printf("CÓDIGO: %s\n", codigo2);
    printf("CIDADE: %s\n", cidade2);
    printf("POPULAÇÃO: %d\n", popul2);
    printf("ÁREA: %.2f km²\n", area2);
    printf("PIB: R$ %.2f Bilhões de Reais\n", PIB2);
    printf("PONTOS TURÍSTICOS: %d\n", pontos_turisticos2);
    printf("DENSIDADE POPULACIONAL: %.2f habitantes/km²\n", dpopul2);
    printf("PIB PER CAPITA: R$ %.2f Reais/hab\n", PIB_per_capita2);

    return 0;
}