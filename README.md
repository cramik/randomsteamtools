# randomsteamtools

# Some cool tools for STEAMID tomfoolery

incrementn.cpp - increments the AccountID cleanly in order to list all n STEAMIDs where n is less than 2^32

incrementall.cpp - increments and lists STEAMIDs for all possible AccountIDs in the 32bit range (4+ billion which takes awhile, as so there will be no example)

steamidsforninstances.cpp - increments the 20-bit instance section n amount of times in order to create multiple links to a steam profile

steamidsforallinstances.cpp - increments all possible 20-bit instances for an account (I couldn't get this one to work with command line arguments because that first bitset would not accept it, if anyone has a solution please make a pull request, thank you.)

allinstanceids.7z - compressed output of steamidsforallinstances.cpp for an example ID

allinstanceslinks.7z - same as allinstanceids but as links (you can do this either by changing the cout to add the link [cout << "https://steamcommunity.com/profiles/"<<u_steamid<<"\n";] or by replacing every newline with a newline+the beginning of the link in a text editor)

simplesteamscraper.cpp - scrapes ISteamUser/GetPlayerSummaries for incremented sets of 100 accounts and outputs the raw json response to a txt file for the user to parse (Yes I have it output the data as well, this is because it doesn't have any catches in place to stop it when it hits API limit or any errors [Keyword "Simple"])

