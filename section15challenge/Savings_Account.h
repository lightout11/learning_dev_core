#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "Account.h"
class Savings_Account : public Account {
    friend std::ostream& operator <<(std::ostream& os, const Savings_Account& account);

    public:
        Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
        bool deposit(double amount);

    protected:
        double int_rate;

    private:
        static constexpr const char* def_name = "Unnamed Saving Account";
        static constexpr double def_balance = 0.0;
        static constexpr double def_int_rate = 0.0;
};
#endif