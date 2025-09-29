/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:49:03 by prosas-p          #+#    #+#             */
/*   Updated: 2025/09/22 10:06:15 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char*  BitcoinExchange::NumberTooLargeException::what() const throw(){
	return "Error: too large a number.";
}

const char*  BitcoinExchange::NegativeNumberException::what() const throw(){
	return "Error: non a positive number.";
}

const char*  BitcoinExchange::NoDataBaseException::what() const throw(){
	return "Error, database filenot found";
}

const char*  BitcoinExchange::CouldNotOpenFileException::what() const throw(){
	return "Error: could not open file.";
}

void BitcoinExchange::addPair(std::string date, std::string value)
{

	std::stringstream	ss(value);
	double				dValue;

	ss >> dValue;
	_map[date] =  dValue;
}

std::string	BitcoinExchange::trimStringSpacesAndTabs(const std::string &str)
{
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

bool BitcoinExchange::checkFormat(std::string line)
{
	bool dotAppeared = false;

	if (line.length() < 14)
		return false;
	for (size_t i = 0; i < line.length(); i++)
	{
		if ((i == line.length() - 1) && !std::isdigit(line[i]))
			return false;
		if (i < 4) {
			if (!std::isdigit(line[i]))
				return false;
		}
		else if (i == 4 || i == 7) {
			if (line[i] != '-')
				return false;
		}
		else if (i == 5) {
			if (line[i] > '1')
				return false;
			if (line[i] == '1' && line[i + 1] > '2')
				return false;
		}
		else if (i == 6 || i == 8 || i == 9) {
			if (!std::isdigit(line[i]))
				return false;
			else if (i == 8 && line[i] > '3')
				return false;
			else if (i == 8 && (line[i] == '3' && line[i + 1] > '1'))
				return false;
		}
		else if (i == 10 || i == 12) {
			if (line[i] != ' ')
				return false;
		}
		else if (i == 13) {
			if (line[i] != '-' && line[i] != '+' && !std::isdigit(line[i]))
				return false;
		}
		else if (i == 14) {
			if (!std::isdigit(line[i]) && line[i] != '.')
				return false;
			if ((line[i] == '.') && !std::isdigit(line [i - 1]))
				return false;
			if (line[i] == '.' && dotAppeared)
				return false;
			if (line[i] == '.' && !dotAppeared)
				dotAppeared = true;
		}
		else if (i > 14) {
			if (!std::isdigit(line[i]) && line[i] != '.')
				return false;
			if (line[i] == '.' && dotAppeared)
				return false;
			if (line[i] == '.' && !dotAppeared)
				dotAppeared = true;
		}
	}
	return true;
}

void BitcoinExchange::printHistoricalPrices(std::string file)
{
	std::fstream fd(file.c_str());
	if (!fd.is_open())
		throw CouldNotOpenFileException();
	std::string		line;

	bool fristLine = true;
	while (std::getline(fd, line))
	{
		line = trimStringSpacesAndTabs(line);
		if (line.empty())
			continue;
		if (fristLine && line == "date | value")
		{
			fristLine = false;
			continue;
		}
		try
		{
			if (!checkFormat(line))
				throw BadInputException(line);
			std::stringstream ss(line);
			std::string	date;
			std::string value;

			if (std::getline(ss, date, '|') && std::getline(ss, value))
			{
				value = trimStringSpacesAndTabs(value);
				std::stringstream	ss2(value);
				double				dValue;
				double				dDefValue;

				ss2 >> dValue;
				if (dValue < 0)
					throw NegativeNumberException();
				if (dValue > 1000)
					throw NumberTooLargeException();

				date = trimStringSpacesAndTabs(date);
				//Get near key pos
				std::map<std::string,double>::iterator it = _map.upper_bound(date);
				if (it != _map.begin())
				{
					--it;
					dDefValue = dValue * it->second;
				}
				else
					throw BadInputException(line);

				std::cout << date << " => " << dValue << " = " << dDefValue << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	fd.close();
}

BitcoinExchange::BitcoinExchange()
{
	std::fstream fd2("data.csv");
	if (!fd2.is_open())
		throw(NoDataBaseException());
	std::string		line;

	while (std::getline(fd2, line))
	{
		if (line.empty())
			continue;

		std::stringstream ss(line);
		std::string	date;
		std::string value;

		if (std::getline(ss, date, ',') && std::getline(ss, value))
			addPair(date, value);
	}
	fd2.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &historical)
{
	this->_map = historical._map;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &historical)
{
	if (this != &historical)
	{
		this->_map = historical._map;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}
