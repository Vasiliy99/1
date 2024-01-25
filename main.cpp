#include "lib.h"

using namespace std;

int main()
{

    int n;
    int m;
    int exp;

    cout<<"Input width of massiv 'n'\n";

    cin >> n;
    while (!cin)
    {
	ErVVOD();
	cout <<"Input Error!" << endl;
	cin.clear();
	cin>>n;
    }

    cout<<"Input length of massiv 'm'\n";

    cin>>m;
    while (!cin)
    {
	ErVVOD();
	cout << "Input Error!" << endl;
	cin.clear();
	cin>>m;
    }

    Matrix m0;
    Matrix m1;

    Matrix & ma = m0;
    Matrix & mb = m1;

    int stop = 0;
    int comm = 0;
    int act1 = 0;
    int act2 = 0;

    while(stop!=1) 
    {
        Put_comm();
	int number;
	cin >> comm;
	while (!cin)
	{
	    ErVVOD();
	    cout << "Input Error!" << endl;
	    cin.clear();
	    cin>>comm;
	}

        switch (comm)
        {
	    case 0:
		if (act1!=0)
		{
		    deleting(ma);
		}
		if(act2!=0)
		{
    		    deleting(mb);
		}
		stop = 1;
		break;
	    case 1:
 		cout<<"Start matrix:\n";
    		output(m0, n, m);
		cout<<"Second matrix:\n";
    		output(m1, n, m);
		cout<<endl;
		break;
	    case 2:
		if(act1==0) {

    		    m0.str = new int[n+1];
    		    for(int i=0; i<=n; i++) {
			m0.str[i]=0;
    		    }

		    input_m0(ma, n, m);
		    act1 = 1;
		}
		else
		    cout<<"already have been used"<<endl;
		break;
	    case 3:
		if(act2==0 and act1==1) {

	    	    m1.str = new int[n+1];
    		    for(int i=0; i<=n; i++) {
			m.str[i]=0;
    		    }

		    cout<<"Input number of experement"<<endl;
		    cin >> exp;
    		    while (!cin)
    		    {
			ErVVOD();
		        cout << "Input Error!" << endl;
		        cin.clear();
		        cin>>exp;
    		    }
		    if(exp>3 or exp<1)
		    {
		        cout<< "error input!" <<endl;
		    }
		    else
		    {
		        make_m1(ma, mb, exp, n);
		    }
		    act2 = 1;
		}
		else
		    cout<<"already have been used or not imput first matrix"<<endl;
		break;
	    default :
		cout<<"error command\n";
		break;
	}
    }
    return 0;
}
