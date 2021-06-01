#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "Usage: increment [amount]\n Example: increment 50\n";
		return 0;
	}
	else {
	int amount;
	sscanf(argv[1], "%d", &amount);
	for (int i=1; i<amount; i++) {
		unsigned long decimal = bitset<64>("1000100000000000000000001").to_ulong(); // Defaults all account details other than AccountID
		string start = bitset<32>(decimal).to_string();
		string add = bitset<32>(i).to_string(); //Converts I to binary with 32 bit width
		string steamid = start+add;
		unsigned long final = bitset<64>(steamid).to_ulong();
		cout<<final<<"\n";
	}
	return 0;
	}
}


