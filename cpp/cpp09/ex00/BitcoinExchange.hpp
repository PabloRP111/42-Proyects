/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:49:01 by prosas-p          #+#    #+#             */
/*   Updated: 2025/08/20 20:10:16 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_map;

	public:
		class BadInputException : public std::exception {
			private:
				std::string _msg;
			public:
				BadInputException(const std::string &input) {
				_msg = "Error: bad input => " + input;
				}
				virtual const char* what() const throw() {
					return _msg.c_str();
				}
				virtual ~BadInputException() throw() {};
    	};

		class NumberTooLargeException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class NegativeNumberException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class NoDataBaseException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		class CouldNotOpenFileException : public std::exception{
			public:
				virtual const char *what() const throw();
		};

		void addPair(std::string date, std::string value);

		std::string trimStringSpacesAndTabs(const std::string &str);

		bool checkFormat(std::string line);

		void printHistoricalPrices(std::string file);

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &historical);
		BitcoinExchange &operator=(const BitcoinExchange &historical);
		~BitcoinExchange();
};

#endif
