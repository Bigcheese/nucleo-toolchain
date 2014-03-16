extern "C"  {
typedef void __vfunc();

extern void (*const __init_array_start)() __attribute__((weak));
extern void (*const __init_array_end)() __attribute__((weak));

void __libc_init() {
  __vfunc *const*lol;
  lol = &__init_array_start;
  for (int i = 0; &lol[i] != &__init_array_end; ++i) {
    lol[i]();
  }
}
}
