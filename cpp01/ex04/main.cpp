#include <iostream>
#include <fstream>

static void	failed(std::string str)
{
	std::cout << "Failed to open " << str << "." << std::endl;
	exit(1);
}

static void	replace(char **av, std::string str)
{
	std::ofstream	file_stream;
	int				pos;

	file_stream.open(std:: string (av[1]) + ".replace");
	if (file_stream.fail())
		failed(std::string (av[1]) + ".replace");
	for (int i = 0; i < (int)str.length(); i++)
	{
		pos = str.find(av[2], i);
		if (pos != -1 && pos == i)
		{
			file_stream << av[3];
			i += std::string(av[2]).length() - 1;
		}
		else
			file_stream << str[i];
	}
	file_stream.close();
}


int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	std::ifstream	file_stream(av[1]);
	if (file_stream.fail())
		failed(std::string (av[1]));
	std::string		str;
	while(!file_stream.eof() && !getline(file_stream, str).eof())
		;
	file_stream.close();
	replace(av, str);
	return (0);
}