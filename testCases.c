#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    
    
//=========Question 1==================================
void TestQ1_add(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double actual[5];
	double expected [5] = {5.10, 6.78, 9.30, 19.90, 1.01};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

void TestQ1_add1(CuTest *tc) {

	int n = 10;
	double input1[10] = {3.60, 4.78, 6.00, 10.00, 0.01, 23.00, 67.2, 1.20, 4.66, 8.00};
	double input2[10] = {1.50, 2.00, 3.30, 9.90, 1.00, 5.00, 1.02, 0.34, 6.76, 7.00};
	double actual[10];
	double expected [10] = {5.10, 6.78, 9.30, 19.90, 1.01, 28.00, 68.22, 1.54, 11.42, 15.00};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

void TestQ1_add2(CuTest *tc) {

	int n = 2;
	double input1[2] = {0.01, 23.00};
	double input2[2] = {3.30, 9.90};
	double actual[2];
	double expected [2] = {3.31, 32.90};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

void TestQ1_add3(CuTest *tc) {

	int n = 3;
	double input1[3] = {12345.00, 67890.00, 100.45};
	double input2[3] = {123.00, 456.78, 90.11};
	double actual[3];
	double expected [3] = {12468.00, 68346.78, 190.56};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}
    
void TestQ1_scalar_prod(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double expected=133.770 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_scalar_prod1(CuTest *tc) {

	int n = 3;
	double input1[3] = {12.34, 2.90, 4.00};
	double input2[3] = {5.60, 1.23, 45.00};
	double expected=252.671 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_scalar_prod2(CuTest *tc) {

	int n = 6;
	double input1[6] = {0.00, 2.90, 4.00, 1.00, 899.23, 67.89};
	double input2[6] = {5.60, 0.00, 45.00, 90.99, 67.42, 0.00};
	double expected=60897.0766;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_scalar_prod3(CuTest *tc) {

	int n = 2;
	double input1[2] = {0.00, 1000.00};
	double input2[2] = {9999.99, 0.00};
	double expected=0;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_norm(CuTest *tc) {

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double expected=13.108 ;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_norm1(CuTest *tc) {

	int n = 3;
	double input1[3] = {12.00, 0.00, 78.00};
	double expected=78.918;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_norm2(CuTest *tc) {

	int n = 2;
	double input1[2] = {100000.00, 9999.99};
	double expected=100498.7552;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_norm3(CuTest *tc) {

	int n = 7;
	double input1[7] = {3.00, 2.00, 13.00, -45.00, 7.89, 1.23, 6.543};
	double expected=48.0996;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

//===========================================================
//=================Question 2================================  

void TestQ2(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1, 2, 3},{ 5, 8, 9},{ 0, 3, 5}};
	int expected[9]= {1, 2, 5, 3, 8, 0, 9, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

void TestQ2_1(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{0, 0, 0},{ 0, 0, 0},{ 0, 0, 0}};
	int expected[9]= {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

void TestQ2_2(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{-3, -2, 0},{-1, 1, 3},{2, 4, 5}};
	int expected[9]= {-3, -2, -1, 0, 1, 2, 3, 4, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

void TestQ2_3(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1000, 100, 10},{10, 100, 1000},{-1000, -10, 100}};
	int expected[9]= {1000, 100, 10, 10, 100, -1000, 1000, -10, 100};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}


//===========================================================
//=================Question 3================================   
void TestQ3_1(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{23, 2}, {-7, 4}, {48, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_zeros(CuTest *tc) {
	int n=8;
	int input[]={0,0,0,0,0,0,0,0};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {0};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_combined(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct int_result[8] = {0};
	int expected[8] = {0,0,23,0,-7,0,0,48};
	int actual[8] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 8, int_result, 3);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}

//efficient function additional test #1
void TestQ3_EffAddTest1(CuTest *tc) {
	int n=10;
	int input[]={1,0,0,0,0,0,-9000, 0, 0, -56};
	struct Q3Struct actual[10] = {0};
	struct Q3Struct expected[10] = {{1, 0}, {-9000, 6}, {-56, 9}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

//efficient function additional test #2
void TestQ3_EffAddTest2(CuTest *tc) {
	int n=5;
	int input[]={0,0,10,0,0};
	struct Q3Struct actual[5] = {0};
	struct Q3Struct expected[5] = {{10, 2}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

//efficient function additional test #3
void TestQ3_EffAddTest3(CuTest *tc) {
	int n=12;
	int input[]={0,0,0,1,0,888, 0, 0, -3, 51, 0, 0};
	struct Q3Struct actual[12] = {0};
	struct Q3Struct expected[12] = {{1, 3}, {888, 5}, {-3, 8}, {51, 9}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

//reconstruct function additional test #1
void TestQ3_RecAddTest1(CuTest *tc) {
	int n=12;
	int input[]={0,0,0,1,0,888, 0, 0, -3, 51, 0, 0};
	struct Q3Struct int_result[12] = {0};
	int expected[12]={0,0,0,1,0,888, 0, 0, -3, 51, 0, 0};
	int actual[12] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 12, int_result, 4);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}

//reconstruct function additional test #2
void TestQ3_RecAddTest2(CuTest *tc) {
	int n=5;
	int input[]={0,0,10,0,0};
	struct Q3Struct int_result[5] = {0};
	int expected[5]={0,0,10,0,0};
	int actual[5] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 5, int_result, 1);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}

//reconstruct function additional test #3
void TestQ3_RecAddTest3(CuTest *tc) {
	int n=10;
	int input[]={1,0,0,0,0,0,-9000, 0, 0, -56};
	struct Q3Struct int_result[10] = {0};
	int expected[10]={1,0,0,0,0,0,-9000, 0, 0, -56};
	int actual[10] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 10, int_result, 3);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}


//===========================================================
//=================Question 4================================   
void TestQ4_BubbleSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Additional Test Case #1 - Bubble Sort
void TestQ4_BubbleSort_AddTest1(CuTest *tc) 
{
	int n=7;
	struct Q4Struct input[]={{43, '+'}, {76, 'L'}, {33, '!'}, {-10, '@'}, {4, 'y'}, {-73, 'q'}, {90, '<'}};	
	struct Q4Struct expected[]={{-73, 'q'}, {-10, '@'}, {4, 'y'}, {33, '!'}, {43, '+'}, {76, 'L'}, {90, '<'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Additional Test Case #2 - Bubble Sort
void TestQ4_BubbleSort_AddTest2(CuTest *tc) 
{
	int n=3;
	struct Q4Struct input[]={{0, '='}, {-23, 'b'}, {12, 'x'}};	
	struct Q4Struct expected[]={{-23, 'b'}, {0, '='}, {12, 'x'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Additional Test Case #3 - Bubble Sort
void TestQ4_BubbleSort_AddTest3(CuTest *tc) 
{
	int n=4;
	struct Q4Struct input[]={{66, '-'}, {100, '$'}, {-99, 'c'}, {-1, '%'}};	
	struct Q4Struct expected[]={{-99, 'c'}, {-1, '%'}, {66, '-'}, {100, '$'}};
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Additional Test Case #1 - Selection Sort
void TestQ4_SelectionSort_AddTest1(CuTest *tc) 
{
	int n=5;
	struct Q4Struct input[]={{5, '!'}, {13, 'g'}, {76, '@'}, {-1, 's'}, {101, '$'}};	
	struct Q4Struct expected[]={{-1, 's'}, {5, '!'}, {13, 'g'}, {76, '@'}, {101, '$'}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Additional Test Case #2 - Selection Sort
void TestQ4_SelectionSort_AddTest2(CuTest *tc) 
{
	int n=4;
	struct Q4Struct input[]={{10001, 'e'}, {1001, '^'}, {101, '='}, {11, 't'}};	
	struct Q4Struct expected[]={{11, 't'}, {101, '='}, {1001, '^'}, {10001, 'e'}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

//Additional Test Case #3 - Selection Sort
void TestQ4_SelectionSort_AddTest3(CuTest *tc) 
{
	int n=3;
	struct Q4Struct input[]={{7, '/'}, {-56, '~'}, {-9, '>'}};	
	struct Q4Struct expected[]={{-56, '~'}, {-9, '>'}, {7, '/'}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}



CuSuite* Lab2GetSuite() {

	CuSuite* suite = CuSuiteNew();

	//Q1 TESTS
	SUITE_ADD_TEST(suite, TestQ1_add);
	SUITE_ADD_TEST(suite, TestQ1_add1);
	SUITE_ADD_TEST(suite, TestQ1_add2);
	SUITE_ADD_TEST(suite, TestQ1_add3);

	SUITE_ADD_TEST(suite, TestQ1_scalar_prod);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod1);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod2);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod3);

	SUITE_ADD_TEST(suite, TestQ1_norm);
	SUITE_ADD_TEST(suite, TestQ1_norm1);
	SUITE_ADD_TEST(suite, TestQ1_norm2);
	SUITE_ADD_TEST(suite, TestQ1_norm3);

	//Q2 TESTS
	SUITE_ADD_TEST(suite, TestQ2);
	SUITE_ADD_TEST(suite, TestQ2_1);
	SUITE_ADD_TEST(suite, TestQ2_2);
	SUITE_ADD_TEST(suite, TestQ2_3);

	//Q3 TESTS
	SUITE_ADD_TEST(suite, TestQ3_1);
	SUITE_ADD_TEST(suite, TestQ3_zeros);
	SUITE_ADD_TEST(suite, TestQ3_combined);

	SUITE_ADD_TEST(suite, TestQ3_EffAddTest1);
	SUITE_ADD_TEST(suite, TestQ3_EffAddTest2);
	SUITE_ADD_TEST(suite, TestQ3_EffAddTest3);	

	SUITE_ADD_TEST(suite, TestQ3_RecAddTest1);
	SUITE_ADD_TEST(suite, TestQ3_RecAddTest2);
	SUITE_ADD_TEST(suite, TestQ3_RecAddTest3);

	//Q4 TESTS
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_1);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_2);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_1);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_2);
	
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_AddTest1);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_AddTest2);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_AddTest3);

	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_AddTest1);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_AddTest2);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_AddTest3);


	return suite;
}  