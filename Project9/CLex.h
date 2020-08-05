class CLex
{
private:
	int array[128][13];
	ifstream readfile;
	ifstream dfaFile;

public:
	CLex(string fname)
	{
		readfile.open(fname);
		dfaFile.open("DFA.txt");
		for (int row = 0; row <= 127; row++)
		{
			for (int column = 0; column <= 12; column++)
			{
				dfaFile >> array[row][column];
			}
		}
	}
	bool GetToken(CToken& token)
	{
		token.tokenType = "";
		token.tokenValue = "";
		char var;
		int cur = 0;
		int last = 0;
		while (!readfile.eof())
		{
			var = readfile.peek();
			if ((int)var == -1)
			{
				var = '\n';
			}
			last = cur;
			cur = array[var][cur];
			if (cur != 55 && cur != 99)
			{
				readfile.get();
				if (cur != 0)
				{
					token.tokenValue = token.tokenValue + var;
				}
			}
			else if (cur == 55)
			{
				if (last == 1)
				{
					token.tokenType = "word";
				}
				else if (last == 2)
				{
					token.tokenType = "int";
				}
				else if (last == 4 || last == 9)
				{
					token.tokenType = "real";
				}
				else if (last == 10 || last == 11 || last == 12)
				{
					token.tokenType = "special";
				}
				return true;
			}
			else
			{
				cout << "lexerError";
				return false;
			}
		}

		if (readfile.eof())
			return false;

	}
};

