# Chip 8 emulator

## Concept and ref
Ref: https://austinmorlan.com/posts/chip8_emulator/

Instruction ref: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM

How stack work?

Stack will contains the PC for next instruction when we JMP or CALL orther instruction. So when it RET, it came back to the previours flow.

```
$200: CALL $208
$202: JMP $20E
$204: LD V1, $1
$206: RET
$208: LD V3, $3
$20A: CALL $204
$20C: RET
$20E: LD V4, $4
```

- $200: CALL $208 -> PC += 2 = $202 | SP = 0 | Put $202 in stack[0] and ++SP = 1    | PC = $208 | Next cycle at PC = $208
- $208: LD V3, $3 -> PC += 2 = $20A | SP = 1 | Do not modify stack or SP            | PC = $20A | Next cycle at PC = $20A
- $20A: CALL $204 -> PC += 2 = $20C | SP = 1 | Put $20C on stack[1] and ++SP = 2    | PC = $204 | Next cycle at PC = $204
- $204: LD V1, $1 -> PC += 2 = $206 | SP = 2 | Do not modify stack or SP            | PC = $206 | Next cycle at PC = $206
- $206: RET       -> PC += 2 = $208 | SP = 2 | --SP = 1 and Pull $20C from stack[1] | PC = $20C | Next cycle at PC = $20C
- $20C: RET       -> PC += 2 = $20E | SP = 0 | --SP = 0 and Pull $202 from stack[0] | PC = $202 | Next cycle at PC = $202
- $202: JMP $20E  -> PC += 2 = $204 | SP = 0 | Do not modify stack or SP            | PC = $204 | Next cycle at PC = $204
- $20E: LD V4, $4 -> PC += 2 = $210 | SP = 0 | Do not modify stack or SP            | PC = $210 | Next cycle at PC = $210


**Chip 8 have:**
- 16 8-bit Registers (labeled `V0` to `VF`)
- 4K Bytes of Memory
  - `0x000-0x1FF`: Originally reserved for the CHIP-8 interpreter, but in our modern emulator we will just never write to or read from that area.
  - `0x050-0x0A0`: Storage space for the 16 built-in characters (0 through F), which we will need to manually put into our memory because ROMs will be looking for those characters.
  - `0x200-0xFFF`: Instructions from the ROM will be stored starting at `0x200`, and anything left after the ROM’s space is free to use.
- 16-bit Index Register: A special register used to store memory addresses for use in operations.
- 16-bit Program Counter
- 16-level Stack
- 8-bit Stack Pointer
- 8-bit Delay Timer
- 8-bit Sound Timer
- 16 Input Keys
- `64x32` Monochrome Display Memory

[Code](https://github.com/JamesGriffin/CHIP-8-Emulator/tree/master)

Can write code with octo [Octo](https://github.com/JohnEarnest/Octo)

# My version

**Idea**:

- Chip8 Emulator with raylib as display [Raylib](https://www.raylib.com/)

- Buil system using `nob` [Nob](https://github.com/tsoding/nob.h)

**How to build**

Build with raylib, nob
```bash
mkdir build
gcc nob_raylib.c
./a.out
```

Build with SDL2 and cmake (Original from [JamesGriffin repo](https://github.com/JamesGriffin/CHIP-8-Emulator/tree/master))

```bash
sudo apt-get install cmake libsdl2-dev
mkdir build
cd build
cmake ..
make
```

Build with SDL2 and g++, nob
```bash
mkdir build
gcc nob.c
./a.out
```

**How to code**:

- Use [Octo](https://github.com/JohnEarnest/Octo)
  - Write octo code in the file
  - Complie with `octo <input_file> <output_file>`