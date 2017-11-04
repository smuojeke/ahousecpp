#include <vector>
#include "Money.h"
#include "Bank.h"
#include "Wallet.h"
#include <iostream>
#include <array>


// Constructor
    Wallet::Wallet(Bank& banker)
	:theBank(banker), cash(7, 0)
{

}

/**
     * Add money to wallet.
     *
     * @params amt - amount of money to be added to wallet
     *               @pre amt in set {500, 100, 50, 20, 10, 5, 1}
     *
     * @modifies cash - adds new value to cash vector
     */
void Wallet::deposit(Money amt)
{
	std::array<unsigned int,7> notes = {500, 100, 50, 20, 10, 5, 1};
	unsigned int whole = 0;
	unsigned int rem = 0;
	for (unsigned int i = 0; i < notes.size(); i++){
		if(amt >= notes[i]){
			whole = amt / notes[i];
			rem = amt % notes[i];
			amt = rem;
			cash[i] += whole;
		}
	}
	
}
/**
     * Removes specified amount of money from cash vector.     
     *
     * @params amt - amount of money to be taken from wallet
     *               @pre amt in set {500, 100, 50, 20, 10, 5, 1}
     *
     * @modifies cash - removes an item equal to amt from 
     *                  cash vector if possible
     *
     * @returns true if successfully found/removed matching amt,
     *          false otherwise
     */
bool Wallet::withdraw(Money amt)
{
	if(netWorth() >= amt){
		std::array<unsigned int,7> notes = {500, 100, 50, 20, 10, 5, 1};
		unsigned int whole = 0;
		unsigned int rem = 0;
		unsigned int init = 0;
		for (unsigned int i = 0; i < notes.size(); i++){
			unsigned int init = amt / notes[i];
			if(amt >= notes[i] && cash[i] >= init){
				whole = amt / notes[i];
				rem = amt % notes[i];
				amt = rem;
				cash[i] -= whole;
			}else if(amt >= notes[i] && (cash[i] < init)){
				whole = amt / notes[i];
				rem = amt % notes[i];
				amt = rem + ((whole - cash[i]) * notes[i]);
				cash[i] = 0;
			}
		}
		return true;
	}else{
		return false;
	}
}

/**
     * Pays another wallet by removing values from own cash vector
     * and depositing them to payee.  Will have to search cash
     * vector to find appropriate denominations, or request the
     * bank to make change if this wallet doesn't have necessary
     * denominations.  Feel free to pick the easiest approach
     * you can think of for this.
     *
     * @params amt - amount of money to pay to other wallet
     *               @pre amt >= 1
     *
     * @modifies cash - removes items equal to amt from 
     *                  cash vector if possible
     *
     * @returns true if successfully transferred matching amt,
     *          false otherwise (including if netWorth < amt)
     */
bool Wallet::transferTo(Money amt, Wallet& payee)
{
	if(netWorth() >= amt){
		withdraw(amt);

		
		payee.deposit(amt);
		
		
		return true;
	}else{
		return false;
	}
}

//! Returns sum of all values in cash vector
Money Wallet::netWorth() const
{
	unsigned int balance = 0;
	std::array<unsigned int,7> notes = {500, 100, 50, 20, 10, 5, 1};
	for (unsigned int i = 0; i < notes.size(); i++){
		balance += cash[i] * notes[i];
	}
	return balance;
}
