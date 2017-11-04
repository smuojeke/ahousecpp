#include <vector>
#include "Money.h"
#include "Bank.h"
#include "Wallet.h"
#include <iostream>
#include <array>

void Bank::giveStartingMoney(Wallet& p){
	// Each player is given $1500 divided as follows: 2 each of $500’s, $100’s and $50’s; 6 $20’s; 5 each of $10’s, $5’s and $1’s
	
	
	for(unsigned int i = 0; i < 2; i++){
	p.deposit(500);
	p.deposit(100);
	p.deposit(50);
	}

	for(unsigned int i = 0; i < 6; i++){
	p.deposit(20);
	}

	for(unsigned int i = 0; i < 5; i++){
	p.deposit(10);
	p.deposit(5);
	p.deposit(1);
	}

}
