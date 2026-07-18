#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {

private:
    std::map<std::string, double> _db;
    void loadDB(const std::string &);
    static bool isValidDateISO(const std::string &);
    static std::string trim(const std::string &);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &);
    BitcoinExchange &operator=(const BitcoinExchange &);
    ~BitcoinExchange();

    void computeValues(const std::string &) const;
};

#endif
