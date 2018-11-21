#include <Servo.h>

/*
 Name:		Servomotor.ino
 Created:	21.11.2018 17:42:52
 Author:	Johannes
*/

Servo servo;

int servopin = 3;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	servo.attach(servopin, 0, 180);
}

// the loop function runs over and over again until power down or reset
void loop() {

	if (Serial.available()) {
		int parse = Serial.parseInt();
		int pos = (parse > 180 || parse < 0 ? 0 : parse); //Prüfen, ob 'parse' zwischen 0 und 180 liegt.

		servo.write(pos);
		delay(500); //Servo benötigt ein bisschen Zeit, bis er die gewünschte Position erreicht hat.

		Serial.println();
		Serial.print("Position des Servomotors: ");
		Serial.print(servo.read()); //Liest die jetzige Position des Servos aus.

	}

}
