# Build an Emulator and Run Space Invaders ROM (OSU CS 467 Online Capstone Project, Summer 2026)

A complete Intel 8080 emulator, built with input, audio, and video support to run the original _Space Invaders_ ROM.

Created by:

- Lia Launtz
- Nick Bryant
- Yiğit Kolat

## How to install

### Debian (Ubuntu, etc.)
```bash
sudo apt-get install libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libsdl2-mixer-dev
```

### macOS
```bash
brew install sdl2 sdl2_image sdl2_mixer sdl2_ttf pkg-config
```

## How to compile & run

### Debian (Ubuntu, etc.)
```bash
chmod +x ./emulate.sh             # make the launch script executable
./emulate.sh                      # launch the application
```

### Debian (Ubuntu, etc.) on WSL2/Windows 11
Due to issues with the interaction between WSL2 and SDL, if you are running the project within WSL2, the display should render using the CPU, rather than GPU. In addition, VSYNC should be turned off. To do this, run:
```bash
chmod +x ./emulate_WSL.sh                 # make launch script executable
./emulate_WSL.sh                          # launch the application
```

### macOS
```bash
chmod +x ./emulate_mac.sh             # make the launch script executable
./emulate_mac.sh                      # launch the application
```

## How to play

(Note: the inputs are **not** case-sensitive)

### Menu controls
| Up | Down | Select | Quit | 
|---|---|---|---|
| `↑` | `↓` | `Enter/Return` | `Q` `Esc` |

### Shared controls
| Insert Coin | Tilt | Quit | 
|---|---|---|
| `C` | `T` | `Esc` |

### Game controls

| | Left | Right | Fire | Start |
|---|---|---|---|---|
| Player 1 | `←` | `→` | `Space` | `1` |
| Player 2 | `A` | `D` | `Enter/Return` | `2` |


## License

This project is licensed under the MIT License — see [LICENSE](LICENSE) for details.

### Third-party assets

- The _Space Invaders_ ROM and sound effects are **not included** in this repository. They remain the property of their original rights holders.
- The menu's font, [Press Start 2P](https://fonts.google.com/specimen/Press+Start+2P), is licensed separately under the SIL Open Font License — see `hardware/video/fonts/` for the included license file.
