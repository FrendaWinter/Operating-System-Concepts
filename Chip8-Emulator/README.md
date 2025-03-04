# Chip 8 emulator

Ref: https://austinmorlan.com/posts/chip8_emulator/

Ref: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM

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