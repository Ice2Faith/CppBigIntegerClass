#include"BigInteger.h"
#include<conio.h>
void Fibonacci()
{
	BigInteger anum = 1;
	BigInteger bnum = 1;
	cout << "Please input end index\n>/ ";
	int count = 3;
	cin >> count;
	cout << 1 << ":\t" << 1 << ":\t" << 1 << endl;
	cout << 2 << ":\t" << 1 << ":\t" << 1 << endl;
	for (int i = 3; i <= count; i++)
	{
		BigInteger cnum = (anum + bnum);
		string result = cnum.toString();
		cout << i << ":\t" << result.length() << ":\t" << cnum << endl;
		anum = bnum;
		bnum = cnum;
	}
}
void BigIntMul()
{
	string snum1, snum2;
	cout << "Please a mul number:>/ ";
	cin >> snum1;
	cout << "Please a mul number:>/ ";
	cin >> snum2;
	BigInteger anum ( snum1);
	BigInteger bnum ( snum2);
	cout << "result: " << (anum*bnum) << endl;
}
void PowXN()
{
	string snumx, snumn;
	cout << "Please a pow x:>/ ";
	cin >> snumx;
	cout << "Please a pow n:>/ ";
	cin >> snumn;
	BigInteger anum(snumx);
	BigInteger bnum(snumn);
	cout << "result: " << anum.pow(bnum) << endl;
}
void FactorialN()
{
	string snum;
	cout << "Please a Factorial number:>/ ";
	cin >> snum;
	BigInteger anum(snum);
	cout << "result: " << anum.factorial() << endl;
}
void BigIntSub()
{
	string snum1, snum2;
	cout << "Please a sub number:>/ ";
	cin >> snum1;
	cout << "Please a sub number:>/ ";
	cin >> snum2;
	BigInteger anum(snum1);
	BigInteger bnum(snum2);
	cout << "result: " << anum.Sub(bnum) << endl;
}
int main()
{
	system("Color f1");
	system("title Fibonacci Sqe Big Integer dev Ice2Faith");
	//BigInteger fp("52");
	//BigInteger sp(47);
	//cout << fp - sp << endl;
	//cout << sp - fp << endl;
	//cout << fp.Sub( sp) << endl;
	//cout << sp.Sub( fp) << endl;
	//cout << fp-- << endl;
	//cout << --fp << endl;
	//cout << sp - 5 << endl;
	//sp -= BigInteger(10);
	//cout << sp << endl;
	bool flag = true;
	while (flag)
	{
		cout << "1.Fibonacci sqe" << endl;
		cout << "2.Big Integer mul" << endl;
		cout << "3.Pow x ^ n" << endl;
		cout << "4.Factorial X!" << endl;
		cout << "5.Big Integer Sub" << endl;
		cout << "6.clean screen" << endl;
		cout << "0.exit" << endl;
		char sel = 0;
		while (sel<'0' || sel>'6')
			sel = getch();
		switch (sel - '0')
		{
		case 0:
			flag = false;
			break;
		case 1:
			Fibonacci();
			break;
		case 2:
			BigIntMul();
			break;
		case 3:
			PowXN();
			break;
		case 4:
			FactorialN();
			break;
		case 5:
			BigIntSub();
			break;
		case 6:
			system("cls");
			break;
		}
	}
	
	
	
	return 0;
}
