#include <iostream>		
#include <thread>	 
#include <chrono>
#include <conio.h>
#include <map>
#include <string>

using namespace std;			// cout, endl
using namespace this_thread;	// sleep_for
using namespace chrono;			// seconds, milliseconds
string input = "";


int main(){

	bool program_running = true;
	
	class BaseState
	{
	public:
		virtual void run() = 0;
	};
	class ExtendedStateCALM : public BaseState
	{
		virtual void run() { std::cout << "I'm Calm." << std::endl; };
	};
	class ExtendedStateALERT : public BaseState
	{
		virtual void run() { std::cout << "What was that? (ALERT)." << std::endl; };
	};
	class ExtendedStateHAPPY : public BaseState
	{
		virtual void run() { std::cout << "I'm Happy" << std::endl; };
	};
	class ExtendedStateAGITATED : public BaseState
	{
		virtual void run() { std::cout << "I see Someone. (AGITATED)." << std::endl; };
	};
	class ExtendedStateSUPPRISED : public BaseState
	{
		virtual void run() { std::cout << "He's aggressive?? (SUPPRIESED)" << std::endl; };
	};
	class ExtendedStateANGRY : public BaseState
	{
		virtual void run() { std::cout << "I'm ANGRY" << std::endl; };
	};

	ExtendedStateCALM* CALM = new ExtendedStateCALM;
	ExtendedStateALERT* ALERT = new ExtendedStateALERT;
	ExtendedStateHAPPY* HAPPY = new ExtendedStateHAPPY;
	ExtendedStateAGITATED* AGITATED = new ExtendedStateAGITATED;
	ExtendedStateSUPPRISED* SUPPREISED = new ExtendedStateSUPPRISED;
	ExtendedStateANGRY* ANGRY = new ExtendedStateANGRY;

	BaseState* current_state = CALM;

	do{
		
		current_state->run();
		std::this_thread::sleep_for(2000ms);

		if (_kbhit())
		{
			char input_char = _getch();

			// Check for ESC key. See table here http://www.asciitable.com/
			if (input_char == 27)
			{
				program_running = false;
			}
			if (input_char == 97)
			{
				current_state = AGITATED;
			}
			if (input_char == 115)
			{
				current_state = ALERT;
			}
			if (input_char == 51)
			{
				current_state = HAPPY;
			}
			if (input_char == 52)
			{
				current_state = SUPPREISED;
			}
			if (input_char == 53)
			{
				current_state = ANGRY;
			}
			if (input_char == 54)
			{
				current_state = CALM;
			}
		}

	} while(program_running);

	delete CALM;
	delete ALERT;
	delete HAPPY;
	delete AGITATED;
	delete SUPPREISED;
	delete ANGRY;
	std::cout << "Ending Finite State Machine" << endl;
	return 0;
}

	