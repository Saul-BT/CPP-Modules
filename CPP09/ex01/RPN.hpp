#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {

private:
    std::stack<double> _stack;
    double calc(char, double, double);

public:
    RPN();
    RPN(const RPN &);
    RPN &operator=(const RPN &);
    ~RPN();

    bool compute(const std::string &);
};

bool is_digit(char c);
bool is_op(char c);

#endif
