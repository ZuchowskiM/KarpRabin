#include<iostream>
#include<fstream>

int hashfun(std::string s)
{
	int hash = 0;
	for (int i = 0; i < s.length(); i++)
	{
		hash += s[i];
	}
	return hash;
}


int main()
{
	std::fstream plik;
	plik.open("test.txt");

	if (plik.good())
	{
		std::cout << "otwarto" << std::endl;
	}

	std::string szukane;
	std::cin >> szukane;
	
	int liczbaznakow = 0;
	while (!plik.eof())
	{
		plik.get();
		liczbaznakow++;
	}
	plik.close();
	plik.open("test.txt");


	std::string s;
	std::string check;
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
		check.clear();
		
		
	}
	plik.close();
	
	return 0;
}