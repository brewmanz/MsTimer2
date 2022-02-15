#ifndef MsTimer2_h
#define MsTimer2_h

#ifdef __AVR__
#include <avr/interrupt.h>
#elif defined(__arm__) && defined(TEENSYDUINO)
#include <Arduino.h>
#else
#error MsTimer2 library only works on AVR architecture
#endif

#include <BrewmanzUtes.h>

namespace MsTimer2 {
	extern unsigned long msecs;
	extern void (*func)();
	extern volatile unsigned long count;
	extern volatile bool overflowing;
	extern volatile unsigned int tcnt2;

	void set(unsigned long ms, void (*f)(), Print* pDebug = nullptr);
	void start();
	void stop();
	void _overflow();
 	unsigned long millis2();
}

#endif
