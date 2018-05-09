HEADERS = 
OBJECTS = build/main.o build/level1.o build/soundbank.out build/f_0.o build/f_1.o build/f_2.o build/f_3.o build/f_4.o build/f_5.o build/f_6.o build/f_7.o build/f_8.o build/f_9.o build/f_10.o build/f_11.o build/f_12.o build/f_13.o build/f_14.o build/f_15.o build/f_16.o build/f_17.o build/f_18.o build/f_19.o build/f_20.o build/f_21.o build/f_22.o build/f_23.o build/f_24.o build/f_25.o build/f_full.o build/h_half.o build/h_full.o build/h_head.o build/h_x.o build/h_stage.o build/h_nums.o build/h_flight.o build/h_empty.o build/b_fire.o build/b_idle.o
SOURCES = src/main.c src/level1.c src/strip.c src/f_0.c src/f_1.c src/f_2.c src/f_3.c src/f_4.c src/f_5.c src/f_6.c src/f_7.c src/f_8.c src/f_9.c src/f_10.c src/f_11.c src/f_12.c src/f_13.c src/f_14.c src/f_15.c src/f_16.c src/f_17.c src/f_18.c src/f_19.c src/f_20.c src/f_21.c src/f_22.c src/f_23.c src/f_24.c src/f_25.c src/f_full.c src/h_half.c src/h_full.c src/h_head.c src/h_x.c src/h_stage.c src/h_nums.c src/h_flight.c src/h_empty.c src/b_fire.c src/b_idle.c
ELFS = build/main.elf
ASMS = src/soundbank.s
CFLAGS = -pedantic -Wall -Wextra -Os -march=armv4t -Wno-switch -Wno-multichar -ffast-math -mlong-calls -mcpu=arm7tdmi -mtune=arm7tdmi -marm -faggressive-loop-optimizations -fverbose-asm 
ARCH = -mthumb -mthumb-interwork
SPECS = -specs=gba.specs
PREFIX = C:\devkitPro\devkitARM\bin\arm-none-eabi-

default: bluebird.gba

build/%.out: src/%.s
	$(PREFIX)as  -mthumb -mthumb-interwork -mcpu=arm7tdmi $< -o $@
build/%.o: src/%.c $(HEADERS)
	$(PREFIX)gcc $(CFLAGS) $(ARCH) -c $< -o $@
build/%.o: data/%.c $(HEADERS)
	$(PREFIX)gcc $(CFLAGS) $(ARCH) -c $< -o $@
build/main.elf: $(OBJECTS) 
	$(PREFIX)gcc $(SPECS) $(ARCH) -LC:\devkitPro\devkitARM\lib $(OBJECTS) -lheart -lm -o build/main.elf
bluebird.gba: $(ELFS)
	$(PREFIX)objcopy -O binary $(ELFS) bluebird.gba
	C:\devkitPro\devkitARM\bin\gbafix bluebird.gba
clean:
	-rm -f build/*.o
	-rm -f build/main.elf
	-rm -f bluebird.gba