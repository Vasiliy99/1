#include "lib.h"

using namespace std;

int * Realloc(int * old, int k, int old_k)
{
    if (k>0)
    {
    	int * New = new int[k];
    	for(int i=0; i<old_k; i++) {
    	    New[i] = old[i];
    	}
    	if(k>1) {
    	    delete [] old;
    	}
    	return New;
    }
    else
    	return NULL;
}

int DoWork(int a, CallbackType callback)
{
    int result = callback(a);
    return result;
}

int SomeCallback1(int a)
{
    int res = 0;
    int s = 0;
    while (a!=0)
    {
	s=s+a%10;
	a=a/10;
    }
    if (s%10>7)
    {
	res = 0;
    }
    else
    {
        res = 1;
    }
    int result = res;
    return result;
}

int SomeCallback2(int a)
{
    int res = 0;
    if (a%10>4)
    {
        res = 0;
    }
    else
    {
        res = 1;
    }
    int result = res;
    return result;
}

int SomeCallback3(int a)
{
    int res = 0;
    if (a>=10)
    {
        res = 0;
    }
    else
    {
        res = 1;
    }
    int result = res;
    return result;
}

void output(Matrix & ma, int n, int m)
{
    int ma_n = 0;

    int ma_ost = 0;
    for (int i = 0; i<n; i++) {
	ma_ost = ma.str[i+1] - ma.str[i];
	for (int j = 0; j<m; j++) {
	    if(ma_ost > 0 and j==ma.stl[ma_n])
	    {
       	        cout<<ma.matr[ma_n]<<" ";
		ma_ost--;
		ma_n++;
	    }
	    else
	    {
		cout<<"0"<<" ";
	    }
	}
    cout<<"\n";
    }
}

void deleting(Matrix & m)
{
    delete [] m.matr;
    delete [] m.stl;
    delete [] m.str;
}

void Put_comm()
{
    cout<<"List of commands: \n";
    cout<<"Command 0 - end programm\n";
    cout<<"Command 1 - print matrixes\n";
    cout<<"Command 2 - input matrix 1\n";
    cout<<"Command 3 - make matrix 2\n";
}
void make_m1_ex(Matrix & m0, Matrix & m1, int k1, int i, int j)
{
    m1.str[i+1] = m1.str[i+1] + 1;
    m1.stl = Realloc(m1.stl, k1, k1-1);
    m1.stl[k1-1] = m0.stl[j];
    m1.matr = Realloc(m1.matr, k1, k1-1);
    m1.matr[k1-1] = m0.matr[j];
}

void make_m1(Matrix & m0, Matrix & m1, int exp, int n)
{
    int k1 = 0;

    Matrix &ma = m0;
    Matrix &mb = m1;

    for (int i = 0; i<n; i++) {
        m1.str[i+1] = m1.str[i];
	for (int j = m0.str[i]; j<m0.str[i+1]; j++) {
	    if(exp == 1) {
                if(DoWork(m0.matr[j], &SomeCallback1)==0)
                {
                    k1++;
 		    make_m1_ex(ma, mb, k1, i, j);
                }
	    }
	    if(exp == 2) {
                if(DoWork(m0.matr[j], &SomeCallback2)==0)
                {
                    k1++;
 		    make_m1_ex(ma, mb, k1, i, j);
                }
	    }
	    if(exp == 3) {
                if(DoWork(m0.matr[j], &SomeCallback3)==0)
                {
                    k1++;
 		    make_m1_ex(ma, mb, k1, i, j);
                }
            }
	}
    }
}

void input_m0(Matrix & m0, int n, int m)
{
    int inp;
    int k0 = 0;
    for (int i = 0; i<n; i++) {
        m0.str[i+1] = m0.str[i];
        for (int j = 0; j<m; j++) {
            cout<<"input matrix["<<i<<"]["<<j<<"] or '0'\n";
	    cin>>inp;

	    while (!cin)
    	    {
		ErVVOD();
	    	cout << "Input Error!" << endl;
	    	cin.clear();
	    	cin>>inp;
    	    }

            if (inp!=0)
            {
 		k0++;
                m0.str[i+1] = m0.str[i+1] + 1;
		m0.stl = Realloc(m0.stl, k0, k0-1);
		m0.stl[k0-1] = j;
		m0.matr = Realloc(m0.matr, k0, k0-1);
		m0.matr[k0-1] = inp;
	    }

        }
    }
}

void ErVVOD ()
{
 	scanf("%*[^\n]%*c");
}
