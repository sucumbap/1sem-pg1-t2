
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


#define MAX_DIGITS     255      // máximo de dígitos admitido

#define BIG_POSITIVE     1      // valor positivo

#define BIG_NEGATIVE     0      // valor negativo

typedef unsigned char byte;  

/*
          0         1            2            ...     n. digitos+1
    +------------+-------+----------------+--------+----------------+
    |            |       |  digito        |        |  digito        |
    | n. digitos | sinal |  menos         |   ...  |  mais          |
    |            |       |  significativo |        |  significativo |
    +------------+-------+-------------------------+----------------+
*/
typedef byte BIG_INT[MAX_DIGITS + 2];


// Assinaturas das funções BIG_INT 

int  big_size         ( const BIG_INT b );
int  big_signal       ( const BIG_INT b);
void big_show         ( const BIG_INT big );
void big_from_long    ( BIG_INT big, long n);

bool big_from_string  ( BIG_INT big, const char n[]);

int  big_cmp_abs      ( const BIG_INT b1, const BIG_INT b2 );
int  big_cmp          ( const BIG_INT b1, const BIG_INT b2 );

bool big_add          ( const BIG_INT b1, const BIG_INT b2, BIG_INT bm );
bool big_sub          ( const BIG_INT b1, const BIG_INT b2, BIG_INT bm );

bool big_mul_digit    ( const BIG_INT b1, int n, BIG_INT bm );
bool big_mult_power10 ( BIG_INT b1, int factor );
bool big_mul          ( const BIG_INT b1, const BIG_INT b2, BIG_INT bm );




