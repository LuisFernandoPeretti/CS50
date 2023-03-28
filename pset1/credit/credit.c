#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // para coletar cada dígito do cartão, individualmente
    int digito = 0;

    // para contar quantos dígitos o cartão possui
    int contador_digitos = 0;

    // para somar os dígitos
    int soma_digitos = 0;

    // para manipular o número do cartão
    long numero_cartao = 0;
    // para armazenar o número original do cartão
    long numero_cartao_aux = 0;

    // verifica se a entrada é um número 'long' maior do que zero
    do
    {
        numero_cartao = get_long("Número do cartão: ");
    } while (numero_cartao <= 0);

    numero_cartao_aux = numero_cartao;

    while (numero_cartao != 0) {

        // obtém o último dígito do número
        digito = numero_cartao % 10;

        // depois de obte-lo, remove do número
        numero_cartao /= 10;

        // incrementa o contador de dígitos
        contador_digitos++;

        // verifica se o número do contador é par, dessa forma, é possível pegar todos os dígitos alternados, inicindo pelo 'penúltimo'
        if (contador_digitos % 2 == 0)
        {
            // multiplica o dígito por 2
            digito = (digito * 2);

            // se o resultado da multiplicação for maior do que 10, seleciona individualmente cada dígito e atribui na soma
            while (digito != 0)
            {
                soma_digitos += digito % 10;
                digito /= 10;
            }
        }

        // verifica se o número do contador é impar, dessa forma, é possível pegar todos os outros dígitos que não foram multiplicados por 2
        if (contador_digitos % 2 != 0)
        {
            // atribui o dígito que não foi multiplicado á soma total
            soma_digitos += digito;
        }

    }

    // Verifica se o último dígito da soma é '0'. Se for, o cartão é legítimo!
    if (soma_digitos % 10 == 0)
    {
        // Obtem o primeiro dígito
        long primeiro_digito = numero_cartao_aux;
        while (primeiro_digito >= 10)
        {
            primeiro_digito /= 10;
        }

        // Obtem os dois primeiros dígitos
        long dois_primeiros_digitos = numero_cartao_aux;
        while (dois_primeiros_digitos >= 100)
        {
            dois_primeiros_digitos /= 10;
        }

        // Condição para ser American Express
        if ( (contador_digitos == 15) & ((dois_primeiros_digitos == 34) || (dois_primeiros_digitos == 37)) )
        {
            printf("AMEX\n");
        }
        // Condição para ser MasterCard
        else if ( (contador_digitos == 16) & ((dois_primeiros_digitos == 51) || (dois_primeiros_digitos == 52) ||
                                              (dois_primeiros_digitos == 53) || (dois_primeiros_digitos == 54) ||
                                              (dois_primeiros_digitos == 55)) )
        {
            printf("MASTERCARD\n");
        }
        // Condição para ser Visa
        else if ( ((contador_digitos == 13) || (contador_digitos == 16)) & (primeiro_digito == 4) )
        {
            printf("VISA\n");
        }
        // Caso o número seja válido mas não caiba em nenhuma das condições a cima, exibe como inválido também
        else
        {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
}