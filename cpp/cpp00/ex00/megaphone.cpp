#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			for (int j = 0; argv[i][j] != '\0'; ++j)
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
			i++;
		}
		std::cout << std::endl;
	}
}
