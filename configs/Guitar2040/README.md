# Guitar2040-CE (RP2040)

Nine physical inputs, five discrete active-high LEDs, and two lighting modes. This is a pre-release prototype and requires compilation and device testing.

## GPIO assignment

| Function | RP2040 GPIO | Keyboard output |
|---|---:|---|
| Green fret | GP2 | A |
| Red fret | GP3 | S |
| Yellow fret | GP4 | D |
| Blue fret | GP5 | F |
| Orange fret | GP6 | G |
| Strum up | GP7 | Up arrow |
| Strum down | GP8 | Down arrow |
| Start | GP9 | Enter |
| Select | GP10 | Backspace |
| Green LED | GP11 | Output |
| Red LED | GP12 | Output |
| Yellow LED | GP13 | Output |
| Blue LED | GP14 | Output |
| Orange LED | GP15 | Output |

Use normally-open buttons to ground; GP2040-CE enables input pullups. Each LED should be wired GPIO -> suitable series resistor -> LED anode -> LED cathode -> GND. Do not drive high-current LEDs directly from Pico GPIO.

LED modes: Reactive (default, only pressed frets illuminated); Always On (all five illuminated). Hold Start+Select for 1.5 seconds to switch modes. The LED mode is RAM-only and resets to Reactive on reboot. This combo may overlap GP2040-CE hotkeys.

A keyboard input profile is selected by default for fresh configuration. If the Pico already contains a stored configuration in flash, its mappings/input mode may override defaults: reset the config with caution and back it up first. No hardware testing has been completed.

### Build

On Windows PowerShell from the cloned repository root (Pico SDK and dependencies configured):

```powershell
cmake -S . -B build-guitar -G Ninja -DGP2040_BOARDCONFIG=Guitar2040
& "$env:USERPROFILE\.pico-sdk\ninja\v1.13.2\ninja.exe" -C build-guitar
```

For the existing Windows installation, CMake may also need an explicit Python 3.12 executable if its default selects Python 3.15. Do not flash until compilation succeeds; store a copy of the existing working UF2.
