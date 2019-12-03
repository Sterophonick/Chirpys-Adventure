HEADERS = include/main.h
OBJECTS = build/main.o build/soundbank.out build/collisions.o build/debug.o build/enemies.o build/game.o build/lang.o build/menu.o build/scroll.o build/sram.o build/worldmap.o build/menucode.o build/level1.o
SOURCES = src/main.c
ELFS = build/main.elf
ASMS = src/soundbank.s
CFLAGS = -DHRT_WITH_LIBHEART -Wall -Ofast -march=armv4t -Wno-switch -Wno-multichar -ffast-math -mlong-calls -mcpu=arm7tdmi -mtune=arm7tdmi -marm -faggressive-loop-optimizations -fverbose-asm -Iinclude 
ARCH = -mthumb -mthumb-interwork
SPECS = -specs=gba.specs
PREFIX = arm-none-eabi-

default: chirpy.gba

build/%.out: src/%.s
	$(PREFIX)as  -mthumb -mthumb-interwork -mcpu=arm7tdmi $< -o $@
build/%.o: src/%.c $(HEADERS)
	$(PREFIX)gcc $(CFLAGS) $(ARCH) -c $< -o $@
build/main.elf: $(OBJECTS) 
	$(PREFIX)gcc $(SPECS) $(ARCH) $(OBJECTS) -lheart -lm -o build/main.elf
chirpy.gba: $(ELFS)
	$(PREFIX)objcopy -O binary $(ELFS) chirpy.gba
	C:\devkitPro\devkitARM\bin\gbafix -tCHRPYADVNTRE	-cCPAU -mST -r01 chirpy.gba
clean:
	-rm -f build/*.o
	-rm -f build/main.elf
	-rm -f chirpy.gba