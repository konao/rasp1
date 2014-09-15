#include <wiringPi.h>

#define LED_PORT 4

int main(int argc, char *argv[]) {
  int i;

  if (wiringPiSetupGpio() == -1) return 1;

  pinMode(LED_PORT, OUTPUT);
  for (i=0; i<10; i++) {
    // LED on
    digitalWrite(LED_PORT, 1);
    delay(500);

    // LED off
    digitalWrite(LED_PORT, 0);
    delay(500);
  }

  return 0;
}
