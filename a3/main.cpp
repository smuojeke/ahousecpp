#include <vector>
#include "Money.h"
#include "Bank.h"
#include "Wallet.h"
#include <iostream>
#include <array>

using namespace std;

int main(){
	
	Bank abank;
	
	Wallet player_1(abank);
	Wallet player_2(abank);
	
	abank.giveStartingMoney(player_1);
	abank.giveStartingMoney(player_2);
	//Wallet::Wallet(Bank& banker)
	//:theBank(banker), cash(7, 0){}

	std::array<unsigned int,7> notes = {500, 100, 50, 20, 10, 5, 1};

	std::cout << "player_1, Your Starting Worth is: " << player_1.netWorth() << std::endl;
	std::cout << "QTY" << "	" << "NOTES" << "	" << "SUB-TOTAL" << std::endl;

	//for (unsigned int j = 0; j < notes.size(); j++){
	//	std::cout << cash[j] << "	" << notes[j] << "	" << cash[j] * notes[j] << std::endl;
	//}

	std::cout << "player_2, Your Starting Worth is: " << player_2.netWorth() << std::endl;
	
	player_1.deposit(10730);
	std::cout << "player_1, You received a deposit, Your net Worth is: " << player_1.netWorth() << std::endl;

	player_2.deposit(9290);
	std::cout << "player_2, You received a deposit, Your net Worth is: " << player_2.netWorth() << std::endl;

	//wallet1.withdraw(300);
	//std::cout << "Your net Worth is: " << wallet1.netWorth() << std::endl;

	player_2.transferTo(12000, player_1);
	std::cout << "player_2, You made a transfer to player_1, Your net Worth is: " << player_2.netWorth() << std::endl;

	std::cout << "player_1, You got a transfer from player_2, Your net Worth is: " << player_1.netWorth() << std::endl;


}
