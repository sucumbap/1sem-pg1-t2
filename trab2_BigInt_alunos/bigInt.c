
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
    if (str[0] == '0') {
        big[0] = 1;
        big[2] = 0;
        return true;
    }
    //agora fazer o percurso a cópia e a validação e conversão
    for(int i = p ; str[i]!=0; ++p, ++i) {
        if (p>=MAX_DIGITS || str[p]<'0' || str[p]>'9' ) return false;
        //printf("\n%i\n", p);
    }
    //acerto ao p caso o str tenha tido sinal no inicio
    if(str[0] == '+' || str[0] == '-'){

        big[0] = p-1;
        //printf("\n%i\n", p);
    } else {

        big[0] = p;
        //printf("\n%i\n", p);
    }
    //p foi acertado para o total de digitos
    //o p foi acertado para o ultimo indice de str

    //printf("TESTE valor do p=%d\n",p);
    //copiar de str para big
    for( int i=2, j=1; j<p; ++i, j++ ) {

        char num = str[p-j];

        big[i] = num-'0';
        return true;
    }

    //printf("\nTESTE o big foi BEM Copiado\n");
    big_show (big);


    // //FALTA IMPLEMNTAR 
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
bool big_sub_aux( const BIG_INT b1, const BIG_INT b2, BIG_INT bm ) {
 
    bm[1] = b1[1];
    int lenght = b1[0];
    int carry = 0;
    for(int i = 0;i < lenght;i++) {
		int sum = b1[i+2] - b2[i+2] - carry;
		if(sum < 0) {
			carry = 1;
			sum += 10;
		} else {
			carry = 0;
		}
		bm[i+2] = sum;
	}
	if(carry > 0) { 
		lenght++;
	}
	if(lenght > MAX_DIGITS) return false;
	bm[lenght + 1] = carry;
	bm[0] = lenght;
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
    bm[1] = b1[1];
	int carry = 0;
	bool bg = true;
	int n1 = b1[0];
	int n2 = b2[0];
	if (big_size(b1) > big_size(b2))  {
		bg = false;
		n1 = n2;
		n2 = big_size(b1);

	}
	for(int i = 0;i < n1;i++) {
		int sum = b1[i+2] + b2[i+2] + carry;
		bm[i+2] = sum % 10;
		carry = sum / 10;
	} 

	for(int i = n1;i < n2; i++) {
		int num = 0;
		if(bg) {
			num = b2[i+2];
		} else {
			num = b1[i+2];
		}
		int sum = num + carry;
		bm[i+2] = sum % 10;
		carry = sum / 10;
	}
	if(carry > 0) {
		n2++;
	} else {
		carry = bm[n2+1];
	}
	if(n2 > 255) {
		bm[0] = 255; 
		return false;
	}
	bm[0] = n2;
	bm[n2 + 1] = carry;
   return true; 
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
bool big_add( const BIG_INT b1, const BIG_INT b2, BIG_INT bm ) {
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
bool big_mul_digit( const BIG_INT b1, int n, BIG_INT bm) {
    bm[0] = b1[0];
	if(big_size(b1) < 1 || big_size(b1) >= 255) return false;
	if((big_signal(b1) == BIG_POSITIVE && n >= 0) || (big_signal(b1) == BIG_NEGATIVE && n < 0)) {
		bm[1] = BIG_POSITIVE;
	} else {
		bm[1] = BIG_NEGATIVE;
	}
	if(n < 0) n = -n;
	bool is_zero = true;
	int carry = 0;
	int size = big_size(b1);
	for(int i = 0;i < size;i++) {
		int res = b1[i+2] * n + carry;
		if(is_zero && res != 0) {
			is_zero = false;
		}
		bm[i+2] = res % 10;
		carry = res / 10;
	} 
	for(int i = 0;carry > 0 && size <= 255;i++) {
		bm[size + 2] = carry % 10;
		carry /= 10;
		size++;
	}
	if(is_zero) {
		size = 0;
	}
	if(size > 255) {
		bm[0] = 255; 
		return false;
	}
	bm[0] = size;
   return true; 
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
bool big_mult_power10( BIG_INT b1, int factor ) {

    if(big_size(b1) == 0) {
		b1[0] = 1;
		b1[1] = BIG_POSITIVE;
		b1[2] = 0;		
		return true;
	}
	if(factor == 0) return true;
    int size = big_size(b1) + factor;
    bool bm = false;
    if(size > 255) {size = 255;bm = true;} 
	for(int i = size - factor; >= 0; --) {
		b1[i + factor + 2] = b1[i + 2];
		b1[i + 2] = 0;
	}	
	b1[0] = size;
    return !bm;
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
bool big_mul( const BIG_INT b1, const BIG_INT b2, BIG_INT bm ) {
    
	bool s1 = true;
	BIG_INT carry = {1, BIG_POSITIVE, 0};
	int s = 1;
	if(b2[1] == BIG_NEGATIVE) s = -1;
    bm[0] = 0;
	bm[1] = BIG_POSITIVE;

	for(int i = 0;i < b2[0];i++) {
		s1 &= big_mul_digit(b1, b2[i+2] * s, carry);
		s1 &= big_mult_power10(carry, i);

		for(int j = 1, p = 0; p < i;p++, j *= 10);
		s1 &= big_add_aux(bm, carry, bm);
		bm[1] = carry[1];
	}
    return s1;
}
 
 
/*----------------------------------------------------------------------------
 *  Fim das funções a realizar
 *---------------------------------------------------------------------------*/

