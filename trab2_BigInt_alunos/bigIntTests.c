
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "bigInt.h"


/*-----------------------------------------------------
  Funções auxiliares para os testes 
------------------------------------------------------*/

void pass() 
{ 
    printf("\033[1;32mPASSED!\033[0m\n"); 
}

void fail() 
{ 
    printf("\033[1;31mFAIL!\033[0m\n"); 
}

void check_zero(int v) 
{
    if (v==0) pass(); else fail();
}

void check_false(bool b) 
{
    if (!b) pass(); else fail();
}

void check_true(bool b) 
{
    if (b) pass(); else fail();
}


void check_equal(int i1, int i2) 
{
    if (i1 == i2) pass(); else fail();
}

void check_negative(int i1) 
{
    if (i1 < 0) pass(); else fail();
}

void check_positive(int i1) 
{
    if (i1 > 0) pass(); else fail();
}


void check_equal_string(const char i1[], const char  i2[]) 
{
    if (!strcmp(i1,i2)) pass(); else fail();
}

void check_equals_byte_array(const byte i1[], const byte  i2[], int size) 
{
    for (int i=0; i < size; ++i)  {
        if (i1[i] != i2[i]) {
            fail(); return;
        }
    }
    pass();
}

void test_title(const char t[]) 
{
    printf("%-36s: ", t);
}


void bigInt_fill (BIG_INT big, int signal, int digit)
{
    big[0] = MAX_DIGITS;
    big[1] = signal;
    for (int i = 2; i <= MAX_DIGITS + 1; i++) {
        big[i] = digit;
    }
}

/*--------------------------------------
 * Início dos testes
 *--------------------------------------*/


//
// read from string and write to string BIG_INT tests
//
void test_read_123() 
{
    test_title("test_read_123");

    BIG_INT bi, biReadOk= { 3, BIG_POSITIVE, 3, 2, 1 };

    if (!big_from_string(bi, "123")) fail();
    else check_equals_byte_array( bi, biReadOk, big_size(biReadOk));
}

void test_read_negative_123() 
{
    test_title("test_read_negative_123");

    BIG_INT bi, biReadOk= { 3, BIG_NEGATIVE, 3, 2, 1 };

    if (!big_from_string(bi, "-123")) fail();
    else check_equals_byte_array( bi, biReadOk, big_size(biReadOk));
}

void test_read_0() 
{
    test_title("test_read_0");

    BIG_INT bi, biReadOk= {1, 1, 0};
    
    if (!big_from_string(bi, "0")) fail();
    else check_equals_byte_array( bi, biReadOk, big_size(biReadOk));
}


// 
// compare tests
//
void test_cmp_equals_250000() 
{
    test_title("test_cmp_equals_250000");

    BIG_INT b1 = { 6, BIG_POSITIVE, 0, 0, 0, 0, 5, 2};

    check_zero(big_cmp(b1, b1));
}

void test_cmp_equals_neg_250000() 
{
    test_title("test_cmp_equals_neg_250000");

    BIG_INT b1 = { 6, BIG_NEGATIVE, 0, 0, 0, 0, 5, 2};

    check_zero(big_cmp(b1, b1));
}

void test_cmp_5_and_4() 
{
    test_title("test_cmp_5_and_4");

    BIG_INT b1 = { 1, BIG_POSITIVE, 5};
    BIG_INT b2 = { 1, BIG_POSITIVE, 4};         

    check_positive(big_cmp(b1, b2));
}

void test_cmp_neg_5_and_neg_4() 
{
    test_title("test_cmp_neg_5_and_neg_4");

    BIG_INT b1 = { 1, BIG_NEGATIVE, 5};
    BIG_INT b2 = { 1, BIG_NEGATIVE, 4};         

    check_negative(big_cmp(b1, b2));
}

void test_cmp_neg_4_and_neg_5() 
{
    test_title("test_cmp_neg_4_and_neg_5");

    BIG_INT b1 = { 1, BIG_NEGATIVE, 5};
    BIG_INT b2 = { 1, BIG_NEGATIVE, 4};         

    check_positive(big_cmp(b2, b1));
}


void test_cmp_2501_and_2500() 
{
    test_title("test_cmp_2501_and_2500");

    BIG_INT b1 = { 6, BIG_POSITIVE, 1, 0, 0, 0, 5, 2}; 
    BIG_INT b2 = { 6, BIG_POSITIVE, 0, 0, 0, 0, 5, 2};

    check_positive(big_cmp(b1, b2));
}

void test_cmp_neg_25000_neg_25001() 
{
    test_title("test_cmp_neg_25000_neg_25001");

    BIG_INT b1 = { 6, BIG_NEGATIVE, 0, 0, 0, 0, 5, 2};
    BIG_INT b2 = { 6, BIG_NEGATIVE, 1, 0, 0, 0, 5, 2}; 

    check_positive(big_cmp(b1, b2));
}

void test_cmp_neg_25000_25001() 
{
    test_title("test_cmp_neg_25000_25001");

    BIG_INT b1 = { 6, BIG_NEGATIVE, 0, 0, 0, 0, 5, 2};
    BIG_INT b2 = { 6, BIG_POSITIVE, 1, 0, 0, 0, 5, 2}; 

    check_negative(big_cmp(b1, b2));
}

//
// addition tests
//
void test_add_one_to_nine() 
{
    test_title("test_add_one_to_nine");

    BIG_INT bNine = {1, BIG_POSITIVE, 9};
    BIG_INT bOne  = {1, BIG_POSITIVE, 1};
    BIG_INT bTen, bTenOk = {2, BIG_POSITIVE, 0, 1};

    if (!big_add(bNine, bOne, bTen)) fail();
    else check_equals_byte_array( bTen, bTenOk, big_size(bTenOk));
}

void test_add_very_BIG_INTs() 
{
    test_title("test_add_very_BIG_INTs");

    char n1[] =    "123456789012345678901234567890";
    char n2[] =    "111111111111111111111111111111";
    
    BIG_INT bOk = { 30, 1,  1,0,0,9,7,6,5,4,3,2,1,0,0,9,7,6,5,4,3,2,1,0,0,9,7,6,5,4,3,2};
    
    BIG_INT bi1;
    BIG_INT bi2;
    BIG_INT biRes;
    
    big_from_string(bi1, n1);
    big_from_string(bi2, n2);
    if ( !big_add(bi1, bi2, biRes) ) fail();
    else check_equals_byte_array(bOk, biRes, big_size(bOk));
}

void test_incr_99() 
{
    test_title("test_incr_99");

    BIG_INT bi = {2, 1, 9, 9}, bOne = {1, 1, 1}, bOneHundred = {3, 1, 0, 0, 1};

    big_add(bi, bOne, bi);
    check_equals_byte_array(bi, bOneHundred, big_size(bOneHundred));
}

void test_add_neg_one_to_neg_nine() 
{
    test_title("test_add_neg_one_to_neg_nine");

    BIG_INT bNine = {1, BIG_NEGATIVE, 9};
    BIG_INT bOne  = {1, BIG_NEGATIVE, 1};
    BIG_INT bTen, bTenOk = {2, BIG_NEGATIVE, 0, 1};
    
    if (!big_add(bNine, bOne, bTen)) fail();
    else check_equals_byte_array( bTen, bTenOk, big_size(bTenOk));
}

void test_add_neg_one_to_nine() 
{
    test_title("test_add_neg_one_to_nine");

    BIG_INT bNine = {1, BIG_POSITIVE, 9};
    BIG_INT bOne  = {1, BIG_NEGATIVE, 1};
    BIG_INT bTen, bTenOk = {1, BIG_POSITIVE, 8};

    if (!big_add(bNine, bOne, bTen)) fail();
    else check_equals_byte_array( bTen, bTenOk, big_size(bTenOk));
}

void test_add_one_to_neg_nine() 
{
    test_title("test_add_one_to_neg_nine");

    BIG_INT bNine = {1, BIG_NEGATIVE, 9};
    BIG_INT bOne  = {1, BIG_POSITIVE, 1};
    BIG_INT bTen, bTenOk = {1, BIG_NEGATIVE, 8};
    
    if (!big_add(bNine, bOne, bTen)) fail();
    else check_equals_byte_array( bTen, bTenOk, big_size(bTenOk));
}


void test_add_zero_max_big () 
{
    test_title("test_add_zero_max_big");

    BIG_INT b1;
    BIG_INT b2 = {1, BIG_POSITIVE, 0};
    BIG_INT biRes;

    bigInt_fill(b1, BIG_POSITIVE, 9);
    check_true(big_add(b1, b2, biRes));
}

void test_add_overflow () 
{
    test_title("test_add_overflow");

    BIG_INT b1;
    BIG_INT b2 = {1, BIG_POSITIVE, 1};
    BIG_INT biRes;

    bigInt_fill(b1, BIG_POSITIVE, 9);
    check_false(big_add(b1, b2, biRes));
}


//
// multiplication tests
//
void test_mul_25_by_100() 
{
    test_title("test_mul_25_by_100");

    BIG_INT b1 = { 2, 1, 5, 2}, b2 = { 3, 1, 0, 0, 1}, bRes;
    BIG_INT bResOk = {4, 1, 0, 0, 5, 2};
    
    big_mul(b1, b2, bRes);
    check_equals_byte_array(bRes, bResOk, big_size(bResOk));
}

void test_square_250000() 
{
    test_title("test_mult_2500_by_2500");

    BIG_INT b1 = { 6, 1, 0, 0, 0, 0, 5, 2}, bRes;
    BIG_INT bResOk = {11, 1, 0, 0, 0, 0, 0, 0, 0, 0,  5, 2, 6};
    
    big_mul(b1, b1, bRes);
    check_equals_byte_array(bRes, bResOk, big_size(bResOk));
}


void test_mult_zero () 
{
    test_title("test_mult_zero");
        
    BIG_INT b1 = {1, BIG_POSITIVE, 9};
    BIG_INT b2 = {1, BIG_POSITIVE, 0};
    BIG_INT bRes;
    
    big_mul(b1, b2, bRes);
    check_equals_byte_array(bRes, b2, big_size(b2));
}

void test_mult_one () 
{
    test_title("test_mult_one");
        
    BIG_INT b1 = {1, BIG_POSITIVE, 9};
    BIG_INT b2 = {1, BIG_POSITIVE, 1};
    BIG_INT bRes;

    big_mul(b1, b2, bRes);
    check_equals_byte_array(bRes, b1, big_size(b1));
}

void test_mult_b1_b2 () 
{
    test_title("test_mult_b1_b2");
    
    BIG_INT b1 = { 6, 1, 9, 3, 1, 0, 9, 9};
    BIG_INT b2 = { 6, 1, 9, 9, 9, 3, 1, 5};
    BIG_INT bResOk = {12, 1, 1, 6, 8, 5, 5, 4, 0, 3, 9, 8, 0, 5};
    BIG_INT bRes;

    big_mul(b1, b2, bRes);
    check_equals_byte_array(bRes, bResOk, big_size(bResOk));
}

void test_mult_b1_neg_b2 () 
{
    test_title("test_mult_b1_neg_b2");
    
    BIG_INT b1 = { 6, 1, 9, 3, 1, 0, 9, 9};
    BIG_INT b2 = { 6, 0, 9, 9, 9, 3, 1, 5};
    BIG_INT bResOk = {12, 0, 1, 6, 8, 5, 5, 4, 0, 3, 9, 8, 0, 5};
    BIG_INT bRes;

    big_mul(b1, b2, bRes);
    check_equals_byte_array(bRes, bResOk, big_size(bResOk));
}

void test_mult_neg_b1_b2 () 
{
    test_title("test_mult_neg_b1_b2");
    
    BIG_INT b1 = { 6, 0, 9, 3, 1, 0, 9, 9};
    BIG_INT b2 = { 6, 1, 9, 9, 9, 3, 1, 5};
    BIG_INT bResOk = {12, 0, 1, 6, 8, 5, 5, 4, 0, 3, 9, 8, 0, 5};
    BIG_INT bRes;

    big_mul(b1, b2, bRes);
    check_equals_byte_array(bRes, bResOk, big_size(bResOk));
}

void test_mult_neg_b1_neg_b2 () 
{
    test_title("test_mult_neg_b1_neg_b2");
    
    BIG_INT b1 = { 6, 0, 9, 3, 1, 0, 9, 9};
    BIG_INT b2 = { 6, 0, 9, 9, 9, 3, 1, 5};
    BIG_INT bResOk = {12, 1, 1, 6, 8, 5, 5, 4, 0, 3, 9, 8, 0, 5};
    BIG_INT bRes;

    big_mul(b1, b2, bRes);
    check_equals_byte_array(bRes, bResOk, big_size(bResOk));
}

void test_mult_overflow () 
{
    test_title("test_mult_overflow");

    BIG_INT b1;
    BIG_INT b2 = {1, BIG_POSITIVE, 9};
    BIG_INT biRes;

    bigInt_fill(b1, BIG_POSITIVE, 9);
    check_false(big_mul(b1, b2, biRes));
}

 
int main() 
{    
    // read from string and write to string BIG_INT tests
    test_read_123();
    test_read_negative_123();
    test_read_0();
        

    // compare tests
    test_cmp_equals_250000();
    test_cmp_equals_neg_250000();
    test_cmp_5_and_4();
    test_cmp_neg_5_and_neg_4();
    test_cmp_neg_4_and_neg_5();
    test_cmp_2501_and_2500();
    test_cmp_neg_25000_neg_25001();
    test_cmp_neg_25000_25001();
    
    
    // addition tests
    test_add_one_to_nine();
    test_add_very_BIG_INTs();
    test_incr_99();
    test_add_neg_one_to_neg_nine();
    test_add_neg_one_to_nine();
    test_add_one_to_neg_nine();
    test_add_zero_max_big();
    test_add_overflow();


    // multiplication tests
    test_mul_25_by_100();
    test_square_250000();
    test_mult_zero();
    test_mult_one();
    test_mult_b1_b2();
    test_mult_b1_neg_b2();
    test_mult_neg_b1_b2();
    test_mult_neg_b1_neg_b2();
    test_mult_overflow(); 

    return 0;
}
    
    

    
