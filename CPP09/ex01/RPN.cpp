#include "RPN.hpp"
#include <iostream>
#include <sstream>

double RPN::calc(char op, double st, double nd) {
    switch (op) {
        case '+': return st + nd;
        case '-': return st - nd;
        case '*': return st * nd;
        case '/': return st / nd;
    }
    return 0;
}

RPN::RPN() {}
RPN::RPN(const RPN & other) {
    this->_stack = other._stack;
}
RPN &RPN::operator=(const RPN & other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}
RPN::~RPN() {}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::compute(const std::string & sequence) {
    std::stringstream ss(sequence);
    std::string tok;

    while (ss >> tok) {
        if (tok.length() != 1) {
            std::cerr << "Error: invalid token '" << tok << "'" << std::endl;
            return false;
        }
        if (is_digit(tok[0])) {
            this->_stack.push(tok[0] - '0');
        }
        else if (is_op(tok[0])) {
            if (this->_stack.size() < 2) {
                std::cerr << "Error: not enough operands" << std::endl;
                return false;
            }
            double nd = this->_stack.top();
            this->_stack.pop();
            double st = this->_stack.top();
            this->_stack.pop();

            if (tok[0] == '/' && nd == 0) {
                std::cerr << "Error: division by 0" << std::endl;
                return false;
            }

            this->_stack.push(this->calc(tok[0], st, nd));
        }
        else {
            std::cerr << "Error: invalid token '" << tok[0] << "'" << std::endl;
            return false;
        }
    }
    if (this->_stack.size() != 1) {
        std::cerr << "Error: incomplete sequence" << std::endl;
        return false;
    }

    std::cout << this->_stack.top() << std::endl;
    return true;
}
