// MasonBot Arduino library
// 3/3/2017
//
//
// Arduino pins 2-13 and 44-46 for PWM on Arduino Mega
// 2, 3, 18, 19, 20, 21 interrupt pins

#ifndef MASONBOT_H
#define MASONBOT_H

#include "Arduino.h"

/* Pinout definitionsl
 * The following correspond to pins on the Arduino Mega board.
 */

/* Motor pins */
#define _motor1_pwm 2
#define _motor1_dir 25
#define _motor1_halt 22

#define _motor2_pwm 3
#define _motor2_dir 26
#define _motor2_halt 23

#define _motor3_pwm 5
#define _motor3_dir 27
#define _motor3_halt 24

/* IR light gate pins
 *
 * IR receivers are put on interrupt lines.
 */
#define _ir_en_1 11
#define _ir_en_2 12
#define _ir_en_3 13

#define _ir_read_1 19
#define _ir_read_2 20
#define _ir_read_3 21

/* Battery check pins */
#define _battery_read A0 // Analog in header?
#define _battery_en_check 47


/* Other */
#define M1 1
#define M2 2
#define M3 3


class MasonBot {
	public:
		MasonBot();
		// Motor control
		//
		int getBatteryPower();
		void moveForward(int velocity);
		void moveRotateCCW(int velocity);
		void moveRotateCW(int velocity);
		void moveStop();
		void runForward(int *count);
		void runSemiCCW(int u, int w);
		void runSemiCW(int u, int w);
		void fbRunarc(float Xloc, float Yloc, int thetaloc, float Xexpected, float Yexpected, int thetaexpected);
		void feedbackRun(float Xloc, float Yloc, int thetaloc, float Xexpected, float Yexpected, int thetaexpected);
		void controlRun(int *count, float Xloc,float Yloc, float thetaloc, float Xexpected, float Yexpected, float thetaexpected);
		voidangle_control(int theta);



	private:
		void _stop_all_motors();
		void _M1Dirset(double dir);
		void _M2Dirset(double dir);
		void _M3Dirset(double dir);
		void _motor1(int speed);
		void _motor2(int speed);
		void _motor3(int speed);
		int _read_battery();
		void _robo_move(int x, int y, int w, int velocity);
};
#endif
