
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "bigInt.h"

/**
 * Descrição:  
 *   Retorna o total de dígitos do BIG_INT recebido por parâmetro
 * Parâmetros: 
 *   b - é o BIG_INT  
 * Retorno: 
 *   o total de dígitos do BIG_INT recebido
 */
int big_size(const BIG_INT b) 
{
    return b[0];
}

/**
 *  Descrição:  
 *    Retorna o sinal do BIG_INT recebido por parâmetro
 *  Parâmetros:  
 *    b -  é o BIG_INT  
 *  Retorno:  
 *    POSITIVE ou NEGATIVE
 */
int big_signal (const BIG_INT b) 
{
    return b[1];
}


/**
 * Descrição: 
 *   A função apresenta no standard output (terminal) o BIG_INT recebido por parâmetro
 * Parâmetros: 
 *   big - é o BIG_INT a apresentar
 * Retorno: 
 *   não tem
 */
void big_show (const BIG_INT big) 
{
    int pos = big_size(big) + 1; // Posiciona no digito mais significativo

    if ( big_signal(big) == BIG_NEGATIVE ) putchar('-');
    
    while (pos > 1) {
        putchar('0'+ big[ pos-- ]);
    }
}


/**
 * Descrição: 
 *   Inicia um BIG_INT com o valor de um inteiro longo
 * Parâmetros:
 *   n  - inteiro cujo valor deve ser colocado no BIG_INT
 *   big - BIG_INT que vai conter o valor do inteiro n
 * Retorno: 
 *   não tem
 */
void big_from_long (BIG_INT big, long n) 
{
    if ( n >= 0 ) big[1] = BIG_POSITIVE;
    else {
        big[1] = BIG_NEGATIVE;
        n = -n;
    }
    int i=0;
    // primeiro, guardar todos os dígitos no array, a partir
    // do índice 2, do dígito menos significativo para o mais significativo
    do {
        big[i+2] = n % 10;
        i++; 
        n = n / 10;
    } while (n > 0);
    // agora guardar o número de dígitos na posição 0
    big[0] = i;
}



/*----------------------------------------------------------------------------
 *  Início das funções a realizar
 *--------------------------------------------------------------------------*/

/**
 * Descrição: 
 *   A função preenche um BIG_INT a partir de uma string com a representação de um valor inteiro  
 * Parâmetros:
 *   str - string de caracteres numéricos.
 *   big - é o BIG_INT a construir a partir de str
 * Retorno:
 *   A função retorna true se construiu o BIG_INT "big" com sucesso ou false 
 *   se foi encontrado na string algum caracter não numérico.  
 */
bool big_from_string(BIG_INT big, const char str[]) 
{
   // FALTA IMPLEMNTAR 
   return false;
}

/**
 * Descrição:
 *   A função compara dois BIG_INT, em termos absolutos, e retorna um valor negativo, zero
 *   ou um valor positivo consoante o primeiro BIG_INT seja menor, igual ou superior ao segundo BIG_INT
 * Parâmetros:
 *   b1 - primeiro BIG_INT
 *   b2 - segundo BIG_INT
 * Retorno: 
     valor negativo se b1 < b2, 0 se b1 == b2, valor positivo se b1 > b2
 */
int big_cmp_abs( const BIG_INT b1, const BIG_INT b2 )
{
    // FALTA IMPLEMNTAR 
    return -1;
}


/**
 * Descrição:
 *   A função compara dois BIG_INT e retorna um valor negativo, zero
 *   ou um valor positivo consoante o primeiro BIG_INT seja menor, igual ou superior ao segundo BIG_INT
 * Parâmetros:
 *   b1 - primeiro BIG_INT
 *   b2 - segundo BIG_INT
 * Retorno: 
     valor negativo se b1 < b2, 0 se b1 == b2, valor positivo se b1 > b2
 */
int big_cmp( const BIG_INT b1, const BIG_INT b2 )
{
    // FALTA IMPLEMNTAR 
    return -1;
}


/**
 * Descrição:  
     Função que subtrai dois numeros BIG_INT, pressupondo que o primeiro é maior em valor absoluto
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   b2 - segundo  operando BIG_INT  
 *   bm - BIG_INT que guarda o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, caso contrário retorna true.
 */
bool big_sub_aux( const BIG_INT b1, const BIG_INT b2, BIG_INT bm )
{
  // FALTA IMPLEMNTAR 
    return true;
}

 /**
 * Descrição:  
     A função calcula a soma de dois BIG_INT e guarda o resultado no terceiro BIG_INT, 
	 sem ter em consideração o sinal  
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   b2 - segundo  operando BIG_INT  
 *   bm - BIG_INT que guarda o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, caso contrário retorna true.
 */
bool big_add_aux( const BIG_INT b1, const BIG_INT b2, BIG_INT bm )
{
    // FALTA IMPLEMNTAR 
    return false;
}


/**
 * Descrição:  
     A função calcula a soma de dois BIG_INT e guarda o resultado no terceiro BIG_INT
 *   tendo em consideração o sinal dos BIG_INT
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   b2 - segundo  operando BIG_INT  
 *   bm - BIG_INT que guarda o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, caso contrário retorna true.
 */
bool big_add( const BIG_INT b1, const BIG_INT b2, BIG_INT bm ) 
{
    // FALTA IMPLEMNTAR 
    return false;
}

/**
 * Descrição: 
 *   A função calcula a diferença entre dois BIG_INT e guarda o resultado no terceiro BIG_INT,
 *   tendo em consideração o sinal dos BIG_INT 
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   b2 - segundo  operando BIG_INT  
 *   bm - BIG_INT que guarda o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, caso contrário retorna true.
 */
bool big_sub( const BIG_INT b1, const BIG_INT b2, BIG_INT bm )
{
    // FALTA IMPLEMNTAR 
    return false;
}

/**
 * Descrição: 
 *   A função retorna true se o BIG_INT em parametro corresponde ao valor zero 
 * Parâmetros:
 *   b - o BIG_INT  
 * Retorno:
 *   A função retorna false se diferente de zero, caso contrário retorna true.
 */
bool big_iszero(const BIG_INT b) 
{
    // FALTA IMPLEMNTAR  
    return true;
}

/**
 * Descrição: 
 *   A função realiza multiplicação do BIG_INT por digito e esta é feita
 *   sem somas sucessivas 
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   n -  segundo  operando  é um inteiro  
 *   bm - BIG_INT que guarda o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, caso contrário retorna true.
 */
bool big_mul_digit( const BIG_INT b1, int n, BIG_INT bm) 
{
    // FALTA IMPLEMNTAR 
    return false;
}


/**
 * Descrição: 
 *   A função que ocupa as posições menos significativas com zeros e copia os digitos para as
 *   mais significativas
 * Parâmetros:
 *      b1 - primeiro operando BIG_INT  
 *  factor - segundo operando  é um inteiro factor de deslocamento
 * Retorno:
 *   A função retorna false se ocorrer overflow, caso contrário retorna true.
 */
bool big_mult_power10( BIG_INT b1, int factor )
{
    // FALTA IMPLEMNTAR 
    return false;
}

/**
 * Descrição: 
 *   A função calcula a multiplicação entre dois BIG_INT e guarda o resultado no terceiro BIG_INT,
 *   tendo em consideração o sinal dos BIG_INT 
 * Parâmetros:
 *   b1 - primeiro operando BIG_INT  
 *   b2 - segundo  operando BIG_INT  
 *   bm - BIG_INT que guarda o resultado
 * Retorno:
 *   A função retorna false se ocorrer overflow, caso contrário retorna true.
 */ 
bool big_mul( const BIG_INT b1, const BIG_INT b2, BIG_INT bm ) 
{
    // FALTA IMPLEMNTAR 
    return true;
}
 
 
/*----------------------------------------------------------------------------
 *  Fim das funções a realizar
 *---------------------------------------------------------------------------*/

