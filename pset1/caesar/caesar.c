#include <stdio.h>
#include <cs50.h>
#include <ctype.h> // para verificar se a chave é um algarismo de 1 a 9
#include <string.h> // para saber o tamanho da string
#include <stdlib.h> // para converter a string em inteiro (função 'atoi()')

// Função para realizar a criptografia
void caesar(char *texto, int chave);

int main (int argc, string argv[])
{

    // Verifica se o programa foi inicializado com o número de argumentos corretos
    if (argc != 2)
    {
        printf("./caesar key\n");
        return 1;
    }

    // percorre algarismo da chave
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // verificase o dígito que estiver snedo percorrido não for um número (!isdigit)
        if ( !isdigit(argv[1][i]) )
        {
            printf("./caesar key\n");
            return 1;
        }
    }

    // se chegou até este ponto, a chave é valida. Então, transformamos ela em um valor 'inteiro'
    int chave = atoi(argv[1]);

    // solicita ao usuário o texto a ser criptografado
    string texto = get_string("plaintext: ");

    caesar(texto, chave);

    printf("ciphertext: %s\n", texto);

}

void caesar(char *texto, int chave)
{
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        // Verifica se o caracter é uma letra maíscula
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            texto[i] = ((texto[i] - 'A') + chave) % 26 + 'A';
        }
        // Verifica se o caracter é uma letra minúscula
        else if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = ((texto[i] - 'a') + chave) % 26 + 'a';
        }
    }
}