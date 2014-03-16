#include <mbed.h>

extern "C" void WWDG_IRQHandler() {}
extern "C" void __umoddi3() {}
extern "C" void __aeabi_uldivmod() {}
extern "C" void __aeabi_idivmod() {}

DigitalOut out(LED1);

int main(void) {
  while(1) {
    out.write(out.read() ^ 1);
  }
}
