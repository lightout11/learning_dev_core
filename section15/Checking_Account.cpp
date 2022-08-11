#include "Account.h"
#include "Checking_Account.h"

bool Checking_Account::withdraw(double amount) {
    if (balance - amount - withdraw_fee >= 0) {
        balance -= (amount + withdraw_fee);
        return true;
    } else {
        return false;
    }
}