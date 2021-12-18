
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

    int p=0; //irá percorrer o array de chars str
    big[1] = BIG_POSITIVE;
    if(str[0] == '-'){ 
        big [1] = BIG_NEGATIVE; 
        p=1; 
    }
    if(str[0] == '+'){ 
        big [1] = BIG_POSITIVE; 
        p=1; 
        }
 
    //agora fazer o percurso a cópia e a validação e conversão
    for( ; str[p]!='\0'; ++p ) {
        if (p>=MAX_DIGITS || str[p]<'0' || str[p]>'9' ) return false;
    }
    //acerto ao p caso o str tenha tido sinal no inicio
    if( str[0] == '0' || str[0] == '+'){
        --p;
        big[0] = p;
    } //p foi acertado para o total de digitos
    --p; //o p foi acertado para o ultimo indice de str

    //printf("TESTE valor do p=%d\n",p);
    //copiar de str para big
    for( int i=2 ; p>=0; --p, ++i){// p é para str e o i é para o big
        big[i] = str[p]-'0';
    }

    //printf("\nTESTE o big foi BEM Copiado\n");
    big_show (big);
    printf("\n");

    return true;


    // str = str;
    // printf("%s", str);


    // for (int i = 0; str[i]!= '\0'; i++)
    // {
    //     if(str[i]<'0' || str[i]>'9' || str[0]=='-') {

    
    //         return true; 

    //     }       
    // }
    // //FALTA IMPLEMNTAR 
    // return false;
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

    int r= b1[0] - b2[0];
    if(r !=0) return r;
    int t=b1[0]+1;//é o tamanho convertido em ultimo indice
    for( ; t>=2; --t){
    r = b1[t]-b2[t];
    if(r!=0) return r;
    }
        return 0;

    // // FALTA IMPLEMNTAR 
    // return -1;
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

    int r= b1[1]-b2[1]; //verificar os sinais de b1 e b2
    if(r!=0) return r;
    r = big_cmp_abs( b1, b2); //têm o mesmosinal entre b1 e b2
                            //podem ser 2 positivos ou dois negativos
    if( b1[1] == BIG_POSITIVE) return r;//ambos positivos
    return -r;

    // printf(b1);
    // if (b1 < b2){ return -1;}
    // if (b1 > b2) {return 1;}
    // if (b1 == b2) {return 0;}
 
    // // FALTA IMPLEMNTAR 
    // return -1;
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



bool big_add_aux( const BIG_INT b1, const BIG_INT b2, BIG_INT bm ) {   

    //if (b1[0] > b2[0]); // swap(str1, str2);

    int n1 = b1[0];// n2 = b2[0];
    int carry = 0;
    for (int i = 0; i < n1; i++) {
        int sum = ((b1[i] - '0') + (b2[i] - '0') + carry);
        bm[i] = sum%10 + '0';
        carry = sum/10;
    }
    printf("\n");
    big_show(bm);
    printf("\n");



    // char str[b1[0]];s
    // //printf("\n\n%i\n\n",b1[0]);
    // int p = 2;
    // for( ; b1[p]!='\0'; ++p ) {
    //     if (p>=MAX_DIGITS || b1[p]<'0' || b1[p]>'9' ) return false;
    // }
    // for( int i=2 ; p>=0; --p, ++i){
    //     str[p] = b1[i];
       
    // }
    // big_show(b1);
    // printf("\n%s\npop\n", str);
   
    // if( b1[0] >= MAX_DIGITS  || b2[0] >= MAX_DIGITS ) { 
    //     return false; 
    // }


    // bool reverse(const BIG_INT b, char str[]) { 
    //     int j = b[0];

    //     for (int i = 0; i <= b[0]; ++i, --j) {
            
    //         //big_show(b);
    //         str[i] = b[j]-'0';
    //         //printf("\n%s\n", str);
    //     }
    //     return true;
    // }
    
    // char str1[b1[0]];
    // reverse(b1,str1);
    // printf("\n%s\n", str1);
    // //big_show(b1);

    return true;
}
    // int n1 = b1[0], n2 = b2[0], carry = 0;
    // char str1[n1], str2[n2];
    // int n = 0;
    // for(int i, j = 2; b1[i]!= '\0' && b2[j]!= '\0'; i++, j++) {

    //     int sum = ((b1[i]-'0') + (b2[j]-'0') + carry);


    // }


    // if (b1[0] > b2[0]) {

    //     int s[b1[0]];

    //     for (int i, j = 2; b1[i]!= '\0' && b2[j]!= '\0'; i++, j++) {
            
            
    //     }
        

    // } else if (b1[0] == b2[0]) {

    // } else {
        
    // }
    




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
    if(b1[1] == b2[1]) {
    
        return big_add_aux(b1,b2,bm);
    }
    if(big_cmp_abs(b1,b2)>=0){ 
        return big_sub_aux(b1,b2,bm);
        }                             //subtração entre o b1 e o b2
    else {
        return big_sub_aux(b2,b1,bm); //subtração entre b2 e b1
    }
    return true;
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
bool big_iszero(const BIG_INT b) {

    if(b[2]!= 0) return false;
    else return true;
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

