#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<windows.h>


int main()
{
	
	SetConsoleCP(1250);

	const int q = 1801;
	const int d = 256;
	
	std::fstream plik;
	plik.open("bibliaPL.txt");

	std::string szukane;
	std::getline(std::cin, szukane);

	int n=0, m=0;
	
	m = szukane.size();

	char temp;
	while (!plik.eof())
	{
		plik.get();
		n++;//liczy o jeden wiecej ale to dobrze
	}//zrobic test czy jesli ostani ciag jest w ostani w tekscie to poprawnie wyszuka
	
	plik.close();
	plik.open("bibliaPL.txt");

	int h = d;

	for (int i = 0; i < m - 2; i++)
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
	
	int missed = 0, found = 0;
	for (int s = 0; s < n - m; s++)
	{
		if (p == t0)
		{
			if (szukane == tempString)
			{
				std::cout << s << " ";
				found++;
			}
			else
				missed++;

		}
		if (s < n - m)
		{
			temp = plik.get();
			tempString.push_back(temp);

			t0 = ((d * (((t0 - ((tempString[0] * h) % q)) + q) % q) % q) + temp) % q;
			
			tempString = tempString.substr(1);
		}
	}
	plik.close();
	
	std::cout << std::endl << missed << std::endl << found;
	

	return 0;
}