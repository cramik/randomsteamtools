#include <iostream>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

int main() {
	for (int i=1; i<pow(2,32); i++) {
		unsigned long decimal = bitset<64>("1000100000000000000000001").to_ulong(); // Defaults all account details other than AccountID
		string start = bitset<32>(decimal).to_string();
		string add = bitset<32>(i).to_string(); //Converts I to binary with 32 bit width
		string steamid = start+add;
		unsigned long final = bitset<64>(steamid).to_ulong();
		cout<<final<<"\n";
	}
	return 0;
}


