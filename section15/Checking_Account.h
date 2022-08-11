#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <iostream>
#include "Account.h"

class Checking_Account : public Account {
    friend ostream& operator <<(ostream& os, const Checking_Account& account);

    public:
        bool withdraw(double amount);

    protected:

    private:
        static constexpr const char* def_name = "Unnamed Checking Account";
        static constexpr double def_balance = 0.0;
        static constexpr double withdraw_fee = 1.5;

};

#endif