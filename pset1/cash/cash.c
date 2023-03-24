#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // declaração das moedas
    float moeda_25_centavos = 0.25;
    float moeda_10_centavos = 0.10;
    float moeda_05_centavos = 0.05;
    float moeda_01_centavo  = 0.01;

    // contador de moedas
    int contador_moedas = 0;

    // solicita o troco ao usuário
    float troco;
    do
    {
        troco = get_float("Troco (R$): ");
    }
    while (troco <= 0);

    // calcula o número de moedas enquanto o troco ainda for maior do que '0.001'
    do
    {
        if (troco >= moeda_25_centavos)
        {
            troco = troco - moeda_25_centavos;
        }
        else if (troco >= moeda_10_centavos)
        {
            troco = troco - moeda_10_centavos;
        }
        else if (troco >= moeda_05_centavos)
        {
            troco = troco - moeda_05_centavos;
        }
        else
        {
            troco = troco - moeda_01_centavo;
        }
        // incrementa contador de moedas
        contador_moedas++;
    }
    while (troco > 0.001); // tentei utilizar 'troco > 0', mas devido a imprecisão do valor float,
                           // em alguns casos o contador contava um valor a mais.

    printf("Total de moedas: %i\n", contador_moedas);

}