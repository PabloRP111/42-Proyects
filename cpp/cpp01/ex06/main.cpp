/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 19:19:24 by femoreno          #+#    #+#             */
/*   Updated: 2025/06/19 09:25:34 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Format error, the usage must be: ./harlFilter <level>\n";
        return 1;
    }

    std::string input = argv[1];
    Harl harl;
    std::string levels[] = {"debug", "info", "warning", "error"};
    int levelIndex = -1;

    for (int i = 0; i < 4; i++) {
        if (levels[i] == toLower(input))
            levelIndex = i;
    }

    switch (levelIndex) {
        case 0:
            harl.complain("DEBUG");
        case 1:
            harl.complain("INFO");
        case 2:
            harl.complain("WARNING");
        case 3:
            harl.complain("ERROR");
            break; //Ruptura
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
    return 0;
}
