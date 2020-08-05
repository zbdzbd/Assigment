using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "CToken.h"
#include "CLex.h"
using namespace std;

class CParser
{
private:
	CLex Lexer;
	CToken ctoken;
	int end;
	void increament()
	{
		cout << ctoken.tokenValue;
		if (!Lexer.GetToken(ctoken))
		{
			end = 1;
		}
		cout << ctoken.tokenValue;
	}

	
	void T()
	{
		TR();
		Tprime();
	}

	void E()
	{
		T();
	}



	void Tprime()
	{
		if (ctoken.tokenValue == "+" || ctoken.tokenValue == "-")
		{
			increament();
			TR();
			Tprime();
		}
	}

	void TR()
	{
		F();
	}

	void F()
	{
		FR();
		Fprime();
	}

	void Fprime()
	{
		if (ctoken.tokenValue == "*" || ctoken.tokenValue == "/")
		{
			increament();
			FR();
			Fprime();
		}
	}

	void FR()
	{
		if (ctoken.tokenType == "int" || ctoken.tokenType == "real" || ctoken.tokenType == "word")
		{
			increament();
		}
		else if (ctoken.tokenValue == "+" || ctoken.tokenValue == "-")
		{
			increament();
			TR();
		}
		else if (ctoken.tokenValue == "(")
		{
			increament();
			E();
			if (ctoken.tokenValue == ")")
			{
				increament();
			}
			else
			{
				cout << "wrong" << endl;
				system("pause");
				exit(0);
			}
		}
		else
		{
			cout << "wrong" << endl;
			system("pause");
			exit(0);
		}
	}
public:
	CParser(string filename) : Lexer(filename)
	{
		Lexer.GetToken(ctoken);
		end = 0;
	}

	void start()
	{
		E();
		if (end)
		{
			cout << "ok" << endl;
			system("pause");
		}
		else
		{
			cout << "error" << endl;
			system("pause");
		}
	}

};
