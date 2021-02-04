#include <iostream>		
#include <thread>	 
#include <chrono>
#include <conio.h>
#include <map>
#include <string>

using namespace std;			// cout, endl
using namespace this_thread;	// sleep_for
using namespace chrono;			// seconds, milliseconds

int main()
{
	bool program_running = true;
	enum class states { CALM = 1, ALERT = 2, HAPPY = 3, SUPPRISED = 4, AGITATED = 5, ANGRY = 6 } program_state{};
	program_state = states::CALM;
	string input = "";
	

	std::cout << "Starting Finite State Machine" << endl;
	std::cout << "bellow are a list of things you can do." << endl;
	std::cout << "" << endl;
	std::cout << "make noise: noise" << endl;
	std::cout << "Crack a joke: joke" << endl;
	std::cout << "see an enemy: spotted" << endl;

	do {
			switch (program_state)
			{
			case states::CALM:
				if (input == "noise") {
					program_state = states::ALERT;
					break;
				}
				if(input == "joke"){
					program_state = states::HAPPY;
					break;
				}
				if (input == "spotted") {
					program_state = states::AGITATED;
					break;
				}
				break;
			case states::ALERT:
				if (input == "nonoise") {
					program_state = states::CALM;
					break;
				}
				break;
			case states::HAPPY:
				cout << "I'm Happy!" << endl;
				break;
			case states::SUPPRISED:
				if (input == "calm") {
					program_state = states::AGITATED;
					break;
				}
				if (input == "attacked") {
					program_state = states::ANGRY;
					break;
				}
				break;
			case states::AGITATED:
				if (input == "aggresive") {
					program_state = states::SUPPRISED;
					break;
				}
				if (input == "friendly") {
					program_state = states::CALM;
					break;
				}
				break;
			case states::ANGRY:
				if (input == "moveaway") {
					program_state = states::CALM;
					break;
				}
				break;
			}

			//output State

			switch (program_state)
			{
			case states::CALM:
				cout << "-CALM-" << endl;
				break;
			case states::ALERT:
				cout << "-ALERT-" << endl;
				break;
			case states::HAPPY:
				cout << "-HAPPY-" << endl;
				break;
			case states::SUPPRISED:
				cout << "-SUPPRISED-" << endl;
				break;
			case states::AGITATED:
				cout << "-AGITATED-" << endl;
				break;
			case states::ANGRY:
				cout << "-ANGRY-" << endl;
				break;
			}
			input = "";
			cin >> input;

		// Sleep the current thread for 1000 milliseconds. Can be repalce with seconds(1)
		sleep_for(milliseconds(1000));

		if (_kbhit())
		{
			char input_char = _getch();

			// Check for ESC key. See table here http://www.asciitable.com/
			if (input_char == 27)
			{
				program_running = false;
			}
		}

	} while(program_running);

	cout << "Ending Finite State Machine" << endl;
	return 0;
}