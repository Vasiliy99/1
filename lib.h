#include<iostream>

typedef int (CallbackType)(int);

typedef struct Matrix{
int* matr;
int* stl;
int* str;
}Matrix;

int SomeCallback3(int a);

int SomeCallback2(int a);

int SomeCallback1(int a);

int DoWork(int a, CallbackType callback);

int * Realloc(int * old, int k, int old_k);

void output(Matrix & ma, int n, int m);

void deleting(Matrix & m);

void Put_comm();

void make_m1_ex(Matrix & m0, Matrix & m1, int k1, int i, int j);

void make_m1(Matrix & m0, Matrix & m1, int exp, int n);

void input_m0(Matrix & m0, int n, int m);

void ErVVOD ();