A demo triggering a sound on keypress. A first pass toward general-use input handling, not meant to live inside the audio layer permanently.

Run `./run_mixer.sh` to test. 

## Known limitation: `getPort`/`setPort` name collision between `controller.c` and `cpu.c`

`controller.c` and `core/cpu.c` each define their own `getPort`/`setPort` — same names, different signatures:

```c
// controller.h
uint8_t getPort (uint8_t *ports, int portNum);
int setPort (uint8_t *ports, int command);

// core/cpu.h
uint8_t getPort(state *currentState, int portIndex, uint8_t portDirection);
int setPort(state *currentState, int portIndex, uint8_t portDirection, uint8_t value);
```

Including both headers in the same file fails at compile time:

```
./controller.h:41:9: error: conflicting types for 'getPort'
./../core/cpu.h:84:9: note: previous declaration is here
```

This isn't a bug in either file individually — both are correct and tested on their own. It only surfaces the moment something needs *both* modules together in one build, which is exactly what `keyboard_demo.c` does (real CPU dispatch + real keyboard input).

**Workaround in use:** `controller_renamed.c`/`.h` — a copy of `controller.c`/`.h` with only `getPort`->`getControllerPort` and `setPort`->`setControllerPort` renamed. Nothing else changed; same logic, same tests would still pass against it. `keyboard_demo.c` builds against this renamed copy instead of the original.
