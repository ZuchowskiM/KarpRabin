#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<windows.h>

//int hashfun(std::string s)
//{
//	int hash = 0;
//	for (int i = 0; i < s.length(); i++)
//	{
//		hash += s[i]
//	}
//	return hash;
//}


int main()
{
	/*std::fstream plik;
	plik.open("bibliaPL.txt");

	if (plik.good())
	{
		std::cout << "otwarto" << std::endl;
	}

	std::string szukane;
	std::cin >> szukane;
	
	int liczbaznakow = 0;
	char c;
	while (plik >> c)
	{
		liczbaznakow++;
	}
	liczbaznakow++;
	std::cout << "liczba znakow: " << liczbaznakow << std::endl;
	plik.close();
	plik.open("bibliaPL.txt");


	std::string s;
	std::string temp;

	for (int i = 0; i < liczbaznakow - 1; i++)
	{
		for (int j = 0;j < szukane.size(); j++)
		{
			temp = plik.get();
			s.append(temp);
		}

		if (hashfun(szukane) == hashfun(s))
		{
			if (s == szukane)
			{
				std::cout << i << " ";
			}
		}
		plik.seekg(i + 1, std::ios::beg);
		s.clear();
		
	}
	plik.close();*/
	SetConsoleCP(1250);

	const int q = 260144641;
	const int d = 127;
	
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
	}
	//n--;
	//std::cout << "liczba znakow w pliku: " << n << std::endl;


	plik.close();
	plik.open("bibliaPL.txt");

	unsigned long long h = ((int)std::pow(d, (m - 1)));//% q;

	unsigned long long p = 0, t0 = 0;
	std::string tempString;

	for (int i = 0; i < m; i++)
	{
		p = (((d * p) + szukane[i]) % q);
		//p = ((d * p) + szukane[i]);

		temp = plik.get();
		tempString.push_back(temp);

		t0 = (((d * t0) + temp) % q);
		//t0 = ((d * t0) + temp);
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
			//t0 = ((d * (t0 - (tempString[0] * h))) + temp);
			//t0 = ((d * t0  + temp) % q);
			t0 = ((d * (t0 % h)) + temp) % q;
			tempString = tempString.substr(1);
		}
	}
	plik.close();
	
	std::cout << std::endl << missed << std::endl << found;
	

	return 0;
}