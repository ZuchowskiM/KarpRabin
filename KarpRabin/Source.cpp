///////////////////////////
//Nazwa: Karp-Rabin
//Autor: Micha³ ¯uchowski
//Data ost. modyfikacji:
// 12.05.2020
//////////////////////////

#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>

void karpRabin(int d, int q, const std::string& nazwaPliku, const std::string& szukane);

int main()
{
	SetConsoleCP(1250);

	const int q = 7000003;
	const int d = 256;

	int liczbaPrzypadkow;
	std::cin >> liczbaPrzypadkow;
	std::cin.ignore();

	std::string nazwaPliku;
	std::string szukane;

	for (int k = 0; k < liczbaPrzypadkow; k++)
	{
		std::getline(std::cin, nazwaPliku);
		std::getline(std::cin, szukane);
		karpRabin(d, q, nazwaPliku, szukane);
	}


	return 0;
}

void karpRabin(int d, int q, const std::string& nazwaPliku, const std::string& szukane)
{
	std::fstream plik;
	plik.open(nazwaPliku);

	int n = 0, m = 0;

	m = szukane.size();

	char temp;
	while (!plik.eof())
	{
		plik.get();
		n++;//liczy o jeden wiecej ale to dobrze
	}


	plik.close();
	plik.open(nazwaPliku);

	int h = 1;

	for (int i = 0; i < m - 1; i++)
	{
		h = (h * d) % q;
	}

	int p = 0, t0 = 0;
	std::string tempString;

	for (int i = 0; i < m; i++)
	{
		p = (((d * p) % q) + szukane[i]) % q;

		temp = plik.get();
		tempString.push_back(temp);

		t0 = (((d * t0) % q) + temp) % q;

	}

	//int missed = 0, found = 0;
	for (int s = 0; s < n - m; s++)
	{
		if (p == t0)
		{
			if (szukane == tempString)
			{
				std::cout << s << " ";
				//found++;
			}
			//else
				//missed++;

		}
		if (s < n - m)
		{
			temp = plik.get();
			tempString.push_back(temp);

			t0 = ((d * (((t0 - ((tempString[0] * h) % q)) + q) % q) % q) + temp) % q;

			tempString.erase(tempString.begin());
		}
	}
	std::cout << std::endl;
	plik.close();

	//std::cout << std::endl <<"missed: "<< missed << std::endl <<"found: "<< found << std::endl;
}