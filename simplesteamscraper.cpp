#define CURL_STATICLIB
#include <curl/curl.h>
#include <sys/stat.h>
#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <fstream>

using namespace std;

//FUNCTION STOLEN FROM https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
inline bool fileexists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

// Function stolen for CURL_WriteData so we can parse the response
size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
	//CONST INITIALIZATION
	const string api_key = ""; // INSERT API KEY HERE
	const string access_token = ""; // INSERT ACCESS TOKEN [Check out https://steamapi.xpaw.me/ for this]
	const string base_url = "https://api.steampowered.com/ISteamUser/GetPlayerSummaries/v2/?access_token=" + access_token + "&key=" + api_key + "&steamids=";
	
	//GETTING PROGRESS
	unsigned long ticker;
	if (fileexists("progress.txt")) {
		ifstream progress;
		progress.open("progress.txt");
		progress >> ticker;
		progress.close();
	}
	else ticker = 0;
	
	
	
	for (int i=1; i<pow(2,32); i++) {
	
		string steamids;
		for (int x=0; x<100; x++) {
			unsigned long decimal = bitset<64>("1000100000000000000000001").to_ulong(); 
			string start = bitset<32>(decimal).to_string();
			string add = bitset<32>(ticker).to_string(); 
			string steamid = start+add;
			unsigned long final = bitset<64>(steamid).to_ulong();
			if (x < 99) steamids.append(to_string(final)).append(",");
		else steamids.append(to_string(final));
			ticker++;
		}
		// Curl Initilization
		CURL *curl;
		CURLcode res;
		curl = curl_easy_init();
		struct curl_slist *headers=NULL;
		string url = base_url+steamids;
		char url_char[url.length()]; 
	
		for (int y = 0; y < sizeof(url_char)+1; y++) { 
			url_char[y] = url[y]; 
		}
		string readBuffer;
		curl_easy_setopt(curl, CURLOPT_URL, url_char);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		curl_easy_perform(curl);
		
		ofstream progress;
		progress.open("progress.txt");
		progress << to_string(ticker);
		progress.close();
		ofstream data;
		data.open("steamdata.txt",ofstream::app);
		data << readBuffer << "\n";
		data.close();
		curl_easy_cleanup(curl);
		cout << readBuffer;
	}
	
	return 0;
}