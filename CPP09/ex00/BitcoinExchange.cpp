#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cctype>

std::string BitcoinExchange::trim(const std::string & s) {
    std::string::size_type start = s.find_first_not_of(" \t");
    std::string::size_type end = s.find_last_not_of(" \t");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}

void BitcoinExchange::loadDB(const std::string & filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    (void) std::getline(file, line);
    while (std::getline(file, line)) {
        std::string::size_type comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        double rate;
        std::stringstream ss(line.substr(comma + 1));
        if (!(ss >> rate))
            continue;

        this->_db[line.substr(0, comma)] = rate;
    }
}

bool BitcoinExchange::isValidDateISO(const std::string & date) {
    if (date.length() != 10 || date.at(4) != '-' || date.at(7) != '-')
        return false;
    for (std::string::size_type i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date.at(i))))
            return false;
    }

    int year;
    int month;
    int day;
    std::stringstream ssY(date.substr(0, 4)); ssY >> year;
    std::stringstream ssM(date.substr(5, 2)); ssM >> month;
    std::stringstream ssD(date.substr(8, 2)); ssD >> day;

    if (month > 12 || month < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    int maxDay = daysInMonth[month - 1];
    if (month == 2 && leap)
        maxDay = 29;
    if (day > maxDay || day < 1)
        return false;

    return true;
}

BitcoinExchange::BitcoinExchange() {
    this->loadDB("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & other) {
    if (this != &other)
        this->_db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::computeValues(const std::string & filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            if (BitcoinExchange::trim(line) == "date | value")
                continue;
        }
        if (BitcoinExchange::trim(line).empty())
            continue;

        std::string::size_type pipe = line.find('|');
        if (pipe == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = BitcoinExchange::trim(line.substr(0, pipe));
        std::string amountStr = BitcoinExchange::trim(line.substr(pipe + 1));

        if (!BitcoinExchange::isValidDateISO(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;
        std::stringstream ss(amountStr);
        std::string leftover;
        if (amountStr.empty() || !(ss >> value) || (ss >> leftover)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::const_iterator it = this->_db.upper_bound(date);
        if (it == this->_db.begin()) {
            std::cerr << "Error: no earlier date in database => " << date << std::endl;
            continue;
        }
        --it;

        std::cout << date << " => " << value << " = " << it->second * value << std::endl;
    }
}
