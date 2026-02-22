#include <stdio.h>
#include <string.h>

//Declarando a função para mostrar o vencedor da comparação entre as cartas, onde o resultado é 1 se a carta 1 vencer, 2 se a carta 2 vencer
void mostrarCartaVencedora(char nome[], int resultado) {

    int cartaVencedora = 2 - resultado;

    printf("%s: A Carta %d venceu (%d)!\n", nome, cartaVencedora, resultado);
}

int main(){
    //Saudação inicial do jogo, explicando o que é o jogo e dando as instruções para o usuário digitar as informações das cartas corretamente
    printf("Olá Jogador(a), esse é o jogo Super Trunfo, um jogo de comparação de cartas! Vamos jogar?\n");
    printf("O objetivo do jogo é comparar as cartas e ver qual é a melhor, ou seja, qual tem os melhores atributos. \n");
    printf("Para começar retire duas cartas aleatórias!\n");
    printf("Agora digite CORRETAMENTE as informações contidas nas suas cartas conforme solitadas abaixo:\n");

    //Declarando as variaveis que serão usadas para armazenar as informações das cartas
    char estado1, estado2, codigo1[10], codigo2[10], cidade1[50], cidade2[50];
    unsigned long int popul1, popul2;
    int pontos_turisticos1, pontos_turisticos2;
    float area1, area2, PIB1, PIB2, dpopul1, dpopul2, PIB_per_capita1, PIB_per_capita2, super_poder1, super_poder2;

    //Solicitando as informações da carta 1 para o usuário
    printf("Qual o ESTADO da Carta 1 (ex: C): ");
    scanf(" %c", &estado1);

    printf("Qual o CÓDIGO da Carta 1 (ex: C01): ");
    scanf("%s", codigo1);

    printf("Qual a CIDADE da Carta 1 (ex: ARACAJU): ");
    scanf("%s", cidade1);

    printf("Qual a POPULAÇÃO da Carta 1 (ex: 12345678): ");
    scanf("%lu", &popul1);

    printf("Qual a ÁREA DA CIDADE da Carta 1 em km² (ex: 1234.56): ");
    scanf("%f", &area1);

    printf("Qual o PIB DA CIDADE da Carta 1 em Bilhões de Reais (ex: 12.34): ");
    scanf("%f", &PIB1);

    printf("Quantos PONTOS TURÍSTICOS a cidade da Carta 1 possui (ex: 12): ");
    scanf("%d", &pontos_turisticos1);
    printf("\n");

    //Repetindo o mesmo processo para a Carta 2
    printf("Agora digite as informações da Carta 2, assim como você fez com a Carta 1: \n");

    printf("Qual o ESTADO da Carta 2 (ex: D): ");
    scanf(" %c", &estado2);

    printf("Qual o CÓDIGO da Carta 2 (ex: D03): ");
    scanf("%s", codigo2);

    printf("Qual a CIDADE da Carta 2 (ex: FORTALEZA): ");
    scanf("%s", cidade2);

    printf("Qual a POPULAÇÃO da Carta 2 (ex: 12345678): ");
    scanf("%lu", &popul2);

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

    //Declarando e calculando o Super Poder de cada carta, que é a soma de todos os atributos numéricos (pontos turísticos, população, área, PIB, densidade populacional e PIB per capita)
    super_poder1 = (float)pontos_turisticos1 + popul1 + area1 + PIB1 + dpopul1 + PIB_per_capita1;
    super_poder2 = (float)pontos_turisticos2 + popul2 + area2 + PIB2 + dpopul2 + PIB_per_capita2;

    //Mostrando as informações das carta 1 e 2 para o usuario visualizar
    printf("Essas são as informações das cartas que você digitou: \n");
    printf("\n");

    printf("Carta 1: \n");
    printf("ESTADO: %c\n", estado1);
    printf("CÓDIGO: %s\n", codigo1);
    printf("CIDADE: %s\n", cidade1);
    printf("POPULAÇÃO: %lu habitantes\n", popul1);
    printf("ÁREA: %.2f km²\n", area1);
    printf("PIB: R$ %.2f Bilhões de Reais\n", PIB1);
    printf("PONTOS TURÍSTICOS: %d\n", pontos_turisticos1);
    printf("DENSIDADE POPULACIONAL: %.2f habitantes/km²\n", dpopul1);
    printf("PIB PER CAPITA: R$ %.2f Reais/hab\n", PIB_per_capita1);
    printf("SUPER PODER: %.2f\n", super_poder1);

    printf("\nCarta 2: \n");
    printf("ESTADO: %c\n", estado2);
    printf("CÓDIGO: %s\n", codigo2);
    printf("CIDADE: %s\n", cidade2);
    printf("POPULAÇÃO: %lu habitantes\n", popul2);
    printf("ÁREA: %.2f km²\n", area2);
    printf("PIB: R$ %.2f Bilhões de Reais\n", PIB2);
    printf("PONTOS TURÍSTICOS: %d\n", pontos_turisticos2);
    printf("DENSIDADE POPULACIONAL: %.2f habitantes/km²\n", dpopul2);
    printf("PIB PER CAPITA: R$ %.2f Reais/hab\n", PIB_per_capita2);
    printf("SUPER PODER: %.2f\n", super_poder2);
    printf("\n");
   
    //Mostrando resultado da comparação ao usuario usando a função mostrarCartaVencedora.

    printf("Comparando as cartas 1 e 2:\n");
    printf("\n");
    mostrarCartaVencedora("POPULAÇÃO", popul1 > popul2);
    mostrarCartaVencedora("ÁREA", area1 > area2);
    mostrarCartaVencedora("PIB", PIB1 > PIB2);
    mostrarCartaVencedora("PONTOS TURÍSTICOS", pontos_turisticos1 > pontos_turisticos2);
    mostrarCartaVencedora("DENSIDADE POPULACIONAL", dpopul1 < dpopul2);
    mostrarCartaVencedora("PIB PER CAPITA", PIB_per_capita1 > PIB_per_capita2);
    mostrarCartaVencedora("SUPER PODER", super_poder1 > super_poder2);

    return 0;
}