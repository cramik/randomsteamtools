#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {

	const string s_start = "10001"; // THESE BITS STAY THE SAME FOR ALL STEAMIDS
	
	string input;
	int amount;
	cout << "Input STEAMID64: ";
	cin >> input;
	cout << "Input amount: ";
	cin >> amount;
	unsigned long accountid = stol(input);
	
	string binary = std::bitset<57>(accountid).to_string();  // CONVERT STEAMID 64 TO BINARY
	char c_accountid[33];
	for (int i=0; i<32;i++) { // EXTRACT BITS 25-32 (ACCOUNT ID)
		c_accountid[i] = binary[i+25];
	}
	string s_accountid(c_accountid);
	
	
	for (int i=1; i<amount; i++) { // FOR EVERY STEAM INSTANCE (20-bit worth)
		string s_instance = bitset<20>(i).to_string(); 
		string s_steamid = s_start+s_instance+s_accountid;
		unsigned long u_steamid = bitset<64>(s_steamid).to_ulong(); // CONVERT BACK TO DECIMAL
		cout<<u_steamid<<"\n";
	}
	
	return 0;
}
