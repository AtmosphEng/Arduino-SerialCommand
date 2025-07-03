// Demo Code for SerialCommand Library
// Steven Cogswell
// May 2011

#include <SerialCommand.h>

// #define arduinoLED 13   // Arduino LED on board
#define arduinoLED 21 // Arduino LED on my board

SerialCommand sCmd; // The demo SerialCommand object

// FORWARD DELARATION(s) **************************************************************************

void LED_on();
void LED_off();
void sayHello();
void processCommand();
// void unrecognised(const char *command);
void serialPlotter(const char *command);
// void serialPlotter();

void setup() {
	pinMode(arduinoLED, OUTPUT);	 // Configure the onboard LED for output
	digitalWrite(arduinoLED, LOW); // default to LED off

	// Serial.begin(9600);
	Serial.begin(115200);

	// Setup callbacks for SerialCommand commands
	sCmd.addCommand("ON", LED_on);				 // Turns LED on
	sCmd.addCommand("OFF", LED_off);			 // Turns LED off
	sCmd.addCommand("HELLO", sayHello);		 // Echos the string argument back
	sCmd.addCommand("P", processCommand);	 // Converts two arguments to integers and echos them back
	sCmd.setDefaultHandler(serialPlotter); // Handler for command that isn't matched  (says "What?")
	//Serial.println("Ready");
}

void loop() {
	sCmd.readSerial(); // We don't do much, just process serial commands
}

void LED_on() {
	Serial.println("LED on");
	digitalWrite(arduinoLED, HIGH);
}

void LED_off() {
	Serial.println("LED off");
	digitalWrite(arduinoLED, LOW);
}

void sayHello() {
	char *arg;
	arg = sCmd.next(); // Get the next argument from the SerialCommand object buffer
	if (arg != NULL) { // As long as it existed, take it
		Serial.print("Hello ");
		Serial.println(arg);
	} else {
		Serial.println("Hello, whoever you are");
	}
}

void processCommand() {
	int aNumber;
	char *arg;

	Serial.println("We're in processCommand");
	arg = sCmd.next();
	if (arg != NULL) {
		aNumber = atoi(arg); // Converts a char string to an integer
		Serial.print("First argument was: ");
		Serial.println(aNumber);
	} else {
		Serial.println("No arguments");
	}

	arg = sCmd.next();
	if (arg != NULL) {
		// aNumber = atoi(arg);
		aNumber = atol(arg);
		Serial.print("Second argument was: ");
		Serial.println(aNumber);
	} else {
		Serial.println("No second argument");
	}
}

// This gets set as the default handler, and gets called when no other command matches.
// void unregnised(const char *command) {
// void serialPlotter() {
void serialPlotter(const char *command) {
	int aNumber;
	char *arg;

	//Serial.println("We're in serialPlotter");

	// if (arg != NULL) {
	if (1) {
		// aNumber = atoi(arg);    // Converts a char string to an integer
		aNumber = atoi(command); // Converts a char string to an integer
		if (aNumber) {
			//Serial.print("argument 0 was: ");
			Serial.println(aNumber);
		}
		// Serial.println(command);
		// Serial.println(0); // use 0 to mean a var label not to be processed.
	}

	arg = sCmd.next();
	if (arg != NULL) {
		aNumber = atoi(arg); // Converts a char string to an integer
		if (aNumber) {
			//Serial.print("argument 1 was: ");
			Serial.println(aNumber);
		}
	}

	arg = sCmd.next();
	if (arg != NULL) {
		aNumber = atoi(arg);
		if (aNumber) {
			//Serial.print("argument 2 was: ");
			Serial.println(aNumber);
		}
	}

	arg = sCmd.next();
	if (arg != NULL) {
		aNumber = atoi(arg);
		if (aNumber) {
			//Serial.print("argument 3 was: ");
			Serial.println(aNumber);
		}
	}

	arg = sCmd.next();
	if (arg != NULL) {
		aNumber = atoi(arg);
		if (aNumber) {
			//Serial.print("argument 4 was: ");
			Serial.println(aNumber);
		}
	}

	arg = sCmd.next();
	if (arg != NULL) {
		aNumber = atoi(arg);
		if (aNumber) {
			//Serial.print("argument 5 was: ");
			Serial.println(aNumber);
		}
	}
}

// END_OF_FILE
