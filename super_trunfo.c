#include <stdio.h>
#include <string.h>

int main(){
    //Saudação inicial do jogo, explicando o que é o jogo e dando as instruções para o usuário digitar as informações das cartas corretamente
    printf("Olá Jogador(a), esse é o jogo Super Trunfo, um jogo de comparação de cartas! Vamos jogar?\n");
    printf("O objetivo do jogo é comparar as cartas e ver qual é a melhor, ou seja, qual tem os melhores atributos. \n");
    printf("Para começar retire duas cartas aleatórias!\n");
    printf("Agora digite CORRETAMENTE as informações contidas nas suas cartas conforme solitadas abaixo:\n");

    //Declarando as variaveis que serão usadas para armazenar as informações das cartas:
    char estado1, estado2, codigo1[10], codigo2[10], cidade1[50], cidade2[50];
    unsigned long int popul1, popul2;
    int pontos_turisticos1, pontos_turisticos2;
    float area1, area2, PIB1, PIB2, dpopul1, dpopul2, PIB_per_capita1, PIB_per_capita2, super_poder1, super_poder2;

    //Solicitando as informações da carta 1 para o usuário:
    printf("Qual o ESTADO da Carta 1 (ex: C): ");
    scanf(" %c", &estado1);

    printf("Qual o CÓDIGO da Carta 1 (ex: C01): ");
    scanf("%s", codigo1);

    getchar(); //Limpa o buffer do teclado para evitar que o fgets leia o \n deixado pelo scanf anterior

    printf("Qual a CIDADE da Carta 1 (ex: ARACAJU): ");
    fgets(cidade1, sizeof(cidade1), stdin);
    cidade1[strcspn(cidade1, "\n")] = '\0';

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

    getchar(); 

    printf("Qual a CIDADE da Carta 2 (ex: FORTALEZA): ");
    fgets(cidade2, sizeof(cidade2), stdin);
    cidade2[strcspn(cidade2, "\n")] = '\0';

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
   

    // Declarando as variaveis para o calculo automatico de qual atributo será comparado pelo computador, usando a soma das populações das duas cartas e o resto da divisão por 7 para escolher um atributo aleatório entre os 7 atributos numéricos (população, área, PIB, pontos turísticos, densidade populacional, PIB per capita e super poder)
    int numBase = popul1 + popul2; //calculo do número base para a escolha do atributo, que é a soma das populações das duas cartas
    int escolhaPC = numBase % 7; //calculo da escolha do computador, que é o resto da divisão do número base por 7, resultando em um número entre 0 e 6, cada um representando um atributo diferente

    //Definindo as regras de comparação das cartas, onde o computador escolhe um atributo aleatório para comparar as cartas e mostra qual carta venceu, considerando que para os atributos população, área, PIB, pontos turísticos, PIB per capita e super poder, a carta com o maior valor vence, enquanto para o atributo densidade populacional, a carta com o menor valor vence
    if (escolhaPC == 0){
        printf("A comparação das Cartas será pelo atributo POPULAÇÃO:\n");
        printf("\n");
        printf("Carta 1 - %s: %lu habitantes\n", cidade1, popul1);
        printf("Carta 2 - %s: %lu habitantes\n", cidade2, popul2);
        if (popul1 > popul2){
            printf("RESULTADO: Carta 1 (%s) venceu!\n", cidade1);
        } else {
                printf("RESULTADO: Carta 2 (%s) venceu!\n", cidade2);
            }
    } else if (escolhaPC == 1){
        printf("A comparação das Cartas será pelo atributo ÁREA:\n");
        printf("\n");
        printf("Carta 1 - %s: %.2f km²\n", cidade1, area1);
        printf("Carta 2 - %s: %.2f km²\n", cidade2, area2);
        if (area1 > area2){
            printf("RESULTADO: Carta 1 (%s) venceu!\n", cidade1);
        } else {
                printf("RESULTADO: Carta 2 (%s) venceu!\n", cidade2);
            }
    } else if (escolhaPC == 2){
        printf("A comparação das Cartas será pelo atributo PIB:\n");
        printf("\n");
        printf("Carta 1 - %s: R$ %.2f Bilhões de Reais\n", cidade1, PIB1);
        printf("Carta 2 - %s: R$ %.2f Bilhões de Reais\n", cidade2, PIB2);
        if (PIB1 > PIB2){
            printf("RESULTADO: Carta 1 (%s) venceu  !\n", cidade1);
        } else {
                printf("RESULTADO: Carta 2 (%s) venceu!\n", cidade2);
            }
    } else if (escolhaPC == 3){
        printf("A comparação das Cartas será pelo atributo PONTOS TURÍSTICOS:\n");
        printf("\n");
        printf("Carta 1 - %s: %d pontos turísticos\n", cidade1, pontos_turisticos1);
        printf("Carta 2 - %s: %d pontos turísticos\n", cidade2, pontos_turisticos2);
        if (pontos_turisticos1 > pontos_turisticos2){
            printf("RESULTADO: Carta 1 (%s) venceu!\n", cidade1);
        } else {
                printf("RESULTADO: Carta 2 (%s) venceu!\n", cidade2);
            }
    } else if (escolhaPC == 4){
        printf("A comparação das Cartas será pelo atributo DENSIDADE POPULACIONAL:\n");
        printf("\n");
        printf("Carta 1 - %s: %.2f habitantes/km²\n", cidade1, dpopul1);
        printf("Carta 2 - %s: %.2f habitantes/km²\n", cidade2, dpopul2);
        if (dpopul1 < dpopul2){
            printf("RESULTADO: Carta 1 (%s) venceu!\n", cidade1);
        } else {
                printf("RESULTADO: Carta 2 (%s) venceu!\n", cidade2);
            }
    } else if (escolhaPC == 5){
        printf("A comparação das Cartas será pelo atributo PIB PER CAPITA:\n");
        printf("\n");
        printf("Carta 1 - %s: R$ %.2f Reais/hab\n", cidade1, PIB_per_capita1);
        printf("Carta 2 - %s: R$ %.2f Reais/hab\n", cidade2, PIB_per_capita2);
        if (PIB_per_capita1 > PIB_per_capita2){
            printf("RESULTADO: Carta 1 (%s) venceu!\n", cidade1);
        } else {
                printf("RESULTADO: Carta 2 (%s) venceu!\n", cidade2);
            }
    } else if (escolhaPC == 6){
        printf("A comparação das Cartas será pelo atributo SUPER PODER:\n");
        printf("\n");
        printf("Carta 1 - %s: %.2f\n", cidade1, super_poder1);
        printf("Carta 2 - %s: %.2f\n", cidade2, super_poder2);
        if (super_poder1 > super_poder2){
            printf("RESULTADO: Carta 1 (%s) venceu!\n", cidade1);
        } else {
                printf("RESULTADO: Carta 2 (%s) venceu!\n", cidade2);
            }
    }
    
    return 0;
}