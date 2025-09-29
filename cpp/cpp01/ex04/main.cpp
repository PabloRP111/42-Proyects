/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 07:45:08 by prosas-p          #+#    #+#             */
/*   Updated: 2025/06/25 08:15:25 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string replaceString(std::string line, const std::string& s1, const std::string& s2) {
    std::string result;
    std::size_t pos = 0;
    std::size_t found;

    while ((found = line.find(s1, pos)) != std::string::npos) // std::string::npos = no encontrado
	{
        result += line.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += line.substr(pos);
    return result;
}


int	main(int argc, char **argv) {
	if (argc == 4)
	{
		std::ifstream file(argv[1]);
		if (file.is_open())
		{
			std::string line;
			std::string new_file_name = std::string(argv[1]) + ".replace";
			std::ofstream new_file(new_file_name.c_str());

			if (new_file.is_open())
			{
				while (std::getline(file, line))
					new_file << replaceString(line, argv[2], argv[3]) << std::endl;
			} else
				std::cerr << "Error to create file" << std::endl;;
		} else
			std::cerr << "Error to open file" << std::endl;;
	} else
		std::cerr << "Error, numbers of arguments incorrect" << std::endl;;
}
