HEADERS = 
OBJECTS = build/main.o build/level1.o build/soundbank.out build/f_0.o build/f_1.o build/f_2.o build/f_3.o build/f_4.o build/f_5.o build/f_6.o build/f_7.o build/f_8.o build/f_9.o build/f_10.o build/f_11.o build/f_12.o build/f_13.o build/f_14.o build/f_15.o build/f_16.o build/f_17.o build/f_18.o build/f_19.o build/f_20.o build/f_21.o build/f_22.o build/f_23.o build/f_24.o build/f_25.o build/f_full.o build/h_half.o build/h_full.o build/h_head.o build/h_x.o build/h_stage.o build/h_nums.o build/h_flight.o build/h_empty.o build/b_fire.o build/b_idle.o build/b_run3.o build/e_cralen1.o build/b_run2.o build/b_run2_f.o build/b_run1_f.o build/b_run1.o build/b_idle_f.o build/b_flap.o build/b_fall.o build/b_fall_f.o build/anim.o build/m_year.o build/m_continue.o build/m_arrow1.o build/m_arrow2.o build/m_arrow3.o build/m_arrow4.o build/menu.o build/disclaimer.o build/level2.o build/credits.o build/colmaps.o build/collision.o build/story1.o build/story2.o build/story3.o build/story4.o build/physics.o build/e_cralen2.o build/level3.o build/lang.o build/menucode.o build/sram.o build/story.o build/worldmap1.o build/worldmap.o build/pause.o build/debug.o build/game.o build/worldmap2.o build/hud.o build/ded.o build/b_die.o
SOURCES = src/main.c src/level1.c src/f_0.c src/f_1.c src/f_2.c src/f_3.c src/f_4.c src/f_5.c src/f_6.c src/f_7.c src/f_8.c src/f_9.c src/f_10.c src/f_11.c src/f_12.c src/f_13.c src/f_14.c src/f_15.c src/f_16.c src/f_17.c src/f_18.c src/f_19.c src/f_20.c src/f_21.c src/f_22.c src/f_23.c src/f_24.c src/f_25.c src/f_full.c src/h_half.c src/h_full.c src/h_head.c src/h_x.c src/h_stage.c src/h_nums.c src/h_flight.c src/h_empty.c src/b_fire.c src/b_idle.c src/b_run3.c src/e_cralen1.c src/b_run2.c src/b_run2_f.c src/b_run1_f.c src/b_run1.c src/b_idle_f.c src/b_flap.c src/b_fall.c src/b_fall_f.c src/anim.c src/m_year.c src/m_arrow1.c src/m_arrow2.c src/m_arrow3.c src/m_arrow4.c src/menu.c src/disclaimer.c src/level2.c src/credits.c src/collision.c src/story1.c  src/story2.c src/story3.c src/story4.c src/continue.c src/physics.c src/m_presstart.c src/m_startgame.c src/e_cralen2.c src/level3.c src/lang.c src/menucode.c src/sram.c src/story.c src/worldmap1.c src/worldmap.c src/game.c src/pause.c src/debug.c src/worldmap2.c src/hud.c src/ded.c src/b_die.c
ELFS = build/main.elf
ASMS = src/soundbank.s
CFLAGS = -DHRT_WITH_LIBHEART -DHRT_USE_MBV2LIB -Wall -Ofast -march=armv4t -Wno-switch -Wno-multichar -ffast-math -mlong-calls -mcpu=arm7tdmi -mtune=arm7tdmi -marm -faggressive-loop-optimizations -fverbose-asm 
ARCH = -mthumb -mthumb-interwork
SPECS = -specs=gba.specs
PREFIX = C:\devkitPro\devkitARM\bin\arm-none-eabi-

default: chirpy.gba

build/%.out: src/%.s
	$(PREFIX)as  -mthumb -mthumb-interwork -mcpu=arm7tdmi $< -o $@
build/%.o: src/%.c $(HEADERS)
	$(PREFIX)gcc $(CFLAGS) $(ARCH) -c $< -o $@
build/%.o: data/%.c $(HEADERS)
	$(PREFIX)gcc $(CFLAGS) $(ARCH) -c $< -o $@
build/main.elf: $(OBJECTS) 
	$(PREFIX)gcc $(SPECS) $(ARCH) $(OBJECTS) -lheart -lm -o build/main.elf
chirpy.gba: $(ELFS)
	$(PREFIX)objcopy -O binary $(ELFS) chirpy.gba
	C:\devkitPro\devkitARM\bin\gbafix -tCHIRPYADV___	-cCPAU -mST -r01 chirpy.gba
clean:
	-rm -f build/*.o
	-rm -f build/main.elf
	-rm -f bluebird.gba