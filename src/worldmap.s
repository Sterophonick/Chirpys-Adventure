	.cpu arm7tdmi
	.eabi_attribute 23, 1
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"worldmap.c"
	.text
	.align	1
	.p2align 2,,3
	.global	mappause
	.arch armv4t
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	mappause, %function
mappause:
	@ Function supports interworking.
	@ Volatile: function does not return.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	movs	r2, #2
	ldr	r3, .L4
	push	{r4, lr}
	strb	r2, [r3, #5]
	movs	r2, #0
	movs	r1, #0
	strb	r2, [r3]
	movs	r0, #0
	ldr	r2, .L4+4
	ldr	r3, .L4+8
	bl	.L6
	ldr	r4, .L4+12
.L2:
	bl	.L7
	b	.L2
.L5:
	.align	2
.L4:
	.word	menu
	.word	gl_pause_r
	.word	hrt_PrintOnTilemap
	.word	hrt_VblankIntrWait
	.size	mappause, .-mappause
	.align	1
	.p2align 2,,3
	.global	presses1
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	presses1, %function
presses1:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, lr}
	mov	lr, r8
	push	{lr}
	ldr	r7, .L53
	ldrb	r3, [r7]
	cmp	r3, #3
	bls	.L9
	movs	r3, #3
	strb	r3, [r7]
.L9:
	movs	r2, #16
	ldr	r6, .L53+4
	ldrh	r1, [r6]
	tst	r2, r1
	bne	.L11
	ldrh	r1, [r6]
	tst	r2, r1
	bne	.L12
	movs	r3, #16
	mov	r8, r3
	ldr	r5, .L53+8
	ldr	r4, .L53+12
.L13:
	bl	.L55
	bl	.L7
	mov	r2, r8
	ldrh	r3, [r6]
	tst	r2, r3
	beq	.L13
	ldrb	r3, [r7]
.L12:
	cmp	r3, #0
	beq	.L48
	cmp	r3, #1
	beq	.L48
.L11:
	movs	r3, #64
	ldr	r6, .L53+4
	ldrh	r2, [r6]
	tst	r3, r2
	bne	.L17
	ldrh	r2, [r6]
	tst	r3, r2
	bne	.L21
	mov	r8, r3
	ldr	r5, .L53+8
	ldr	r4, .L53+12
.L18:
	bl	.L55
	bl	.L7
	mov	r2, r8
	ldrh	r3, [r6]
	tst	r2, r3
	beq	.L18
.L21:
	ldrb	r3, [r7]
	cmp	r3, #2
	beq	.L50
.L17:
	movs	r3, #32
	ldr	r6, .L53+4
	ldrh	r2, [r6]
	tst	r3, r2
	bne	.L23
	ldrh	r2, [r6]
	tst	r3, r2
	bne	.L27
	mov	r8, r3
	ldr	r5, .L53+8
	ldr	r4, .L53+12
.L24:
	bl	.L55
	bl	.L7
	mov	r2, r8
	ldrh	r3, [r6]
	tst	r2, r3
	beq	.L24
.L27:
	ldrb	r4, [r7]
	cmp	r4, #0
	bne	.LCB165
	b	.L51	@long jump
.LCB165:
	cmp	r4, #1
	beq	.L49
	cmp	r4, #2
	beq	.L49
.L23:
	movs	r3, #128
	ldr	r6, .L53+4
	ldrh	r2, [r6]
	tst	r3, r2
	bne	.L8
	ldrh	r2, [r6]
	tst	r3, r2
	bne	.L35
	mov	r8, r3
	ldr	r5, .L53+8
	ldr	r4, .L53+12
.L32:
	bl	.L55
	bl	.L7
	mov	r2, r8
	ldrh	r3, [r6]
	tst	r2, r3
	beq	.L32
.L35:
	ldrb	r3, [r7]
	cmp	r3, #3
	beq	.L52
.L8:
	@ sp needed
	pop	{r2}
	mov	r8, r2
	pop	{r4, r5, r6, r7}
	pop	{r0}
	bx	r0
.L48:
	ldr	r3, .L53+16
	ldr	r0, .L53+20
	bl	.L6
	ldr	r3, .L53+24
	strh	r0, [r3, #20]
	ldrb	r3, [r7]
	adds	r3, r3, #1
	ldr	r1, .L53+28
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	ldrb	r2, [r1, r3]
	strb	r3, [r7]
	adds	r3, r1, r3
	ldrb	r1, [r3, #4]
	movs	r0, #0
	ldr	r3, .L53+32
	bl	.L6
	b	.L11
.L50:
	ldr	r3, .L53+16
	ldr	r0, .L53+20
	bl	.L6
	ldr	r3, .L53+24
	strh	r0, [r3, #20]
	ldrb	r3, [r7]
	adds	r3, r3, #1
	ldr	r1, .L53+28
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	ldrb	r2, [r1, r3]
	strb	r3, [r7]
	adds	r3, r1, r3
	ldrb	r1, [r3, #4]
	movs	r0, #0
	ldr	r3, .L53+32
	bl	.L6
	b	.L17
.L52:
	ldr	r3, .L53+16
	ldr	r0, .L53+20
	bl	.L6
	ldr	r3, .L53+24
	strh	r0, [r3, #20]
	ldrb	r3, [r7]
	subs	r3, r3, #1
	ldr	r1, .L53+28
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	ldrb	r2, [r1, r3]
	strb	r3, [r7]
	adds	r3, r1, r3
	ldrb	r1, [r3, #4]
	movs	r0, #0
	ldr	r3, .L53+32
	bl	.L6
	b	.L8
.L49:
	ldr	r3, .L53+16
	ldr	r0, .L53+20
	bl	.L6
	ldr	r3, .L53+24
	strh	r0, [r3, #20]
	ldrb	r3, [r7]
	subs	r3, r3, #1
	ldr	r1, .L53+28
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	ldrb	r2, [r1, r3]
	strb	r3, [r7]
	adds	r3, r1, r3
	ldrb	r1, [r3, #4]
	movs	r0, #0
	ldr	r3, .L53+32
	bl	.L6
	b	.L23
.L51:
	ldr	r3, .L53+16
	ldr	r0, .L53+20
	bl	.L6
	ldr	r3, .L53+24
	movs	r2, #96
	strh	r0, [r3, #20]
	movs	r1, #64
	movs	r0, #0
	ldr	r3, .L53+32
	strb	r4, [r7]
	bl	.L6
	b	.L23
.L54:
	.align	2
.L53:
	.word	.LANCHOR0
	.word	67109168
	.word	animbirdmap
	.word	hrt_VblankIntrWait
	.word	mmEffectEx
	.word	map_select
	.word	audio
	.word	.LANCHOR1
	.word	hrt_SetOBJXY
	.size	presses1, .-presses1
	.align	1
	.p2align 2,,3
	.global	worldmap
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	worldmap, %function
worldmap:
	@ Function supports interworking.
	@ Volatile: function does not return.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, lr}
	mov	lr, r10
	mov	r6, r8
	mov	r7, r9
	movs	r3, #0
	push	{r6, r7, lr}
	sub	sp, sp, #48
	movs	r2, #0
	movs	r1, #0
	str	r3, [sp, #12]
	str	r3, [sp, #8]
	str	r3, [sp, #4]
	str	r3, [sp]
	ldr	r4, .L69
	adds	r3, r3, #1
	movs	r0, #0
	bl	.L7
	ldr	r3, .L69+4
	bl	.L6
	ldr	r3, .L69+8
	movs	r0, #0
	bl	.L6
	ldr	r5, .L69+12
	movs	r0, #0
	bl	.L55
	movs	r0, #1
	bl	.L55
	movs	r0, #2
	bl	.L55
	movs	r0, #3
	bl	.L55
	ldr	r3, .L69+16
	bl	.L6
	ldr	r3, .L69+20
	bl	.L6
	ldr	r3, .L69+24
	bl	.L6
	ldr	r3, .L69+28
	movs	r0, #0
	bl	.L6
	movs	r1, #4
	movs	r0, #2
	ldr	r6, .L69+32
	bl	.L71
	ldr	r4, .L69+36
	movs	r1, #3
	movs	r0, #2
	bl	.L7
	movs	r1, #5
	movs	r0, #1
	bl	.L71
	movs	r1, #2
	movs	r0, #1
	bl	.L7
	movs	r3, #32
	ldr	r4, .L69+40
	ldrb	r2, [r4, r3]
	lsls	r3, r2, #2
	adds	r2, r3, r2
	ldr	r3, .L69+44
	adds	r3, r3, r2
	ldrb	r3, [r3, #6]
	cmp	r3, #3
	bhi	.LCB400
	b	.L68	@long jump
.LCB400:
	ldr	r3, .L69+48
	mov	r10, r3
	ldr	r3, .L69+52
	mov	r9, r3
	ldr	r7, .L69+56
.L57:
	movs	r1, #32
	movs	r0, #3
	bl	.L72
	movs	r3, #128
	lsls	r3, r3, #24
	mov	r8, r3
	str	r3, [sp]
	ldr	r2, .L69+60
	movs	r3, #160
	ldr	r1, .L69+64
	movs	r0, #3
	bl	.L73
	mov	r3, r8
	str	r3, [sp]
	movs	r3, #160
	ldr	r2, .L69+68
	lsls	r3, r3, #2
	ldr	r1, .L69+72
	movs	r0, #3
	bl	.L73
	movs	r1, #16
	ldr	r0, .L69+76
	bl	.L74
	ldr	r3, .L69+80
	ldr	r1, [r3]
	lsls	r7, r1, #30
	lsrs	r7, r7, #31
	bne	.LCB439
	b	.L63	@long jump
.LCB439:
	movs	r2, #128
	movs	r3, #128
	lsls	r2, r2, #7
	ldrh	r0, [r1, r2]
	lsls	r3, r3, #5
	orrs	r3, r0
	strh	r3, [r1, r2]
	movs	r3, #1
	mov	ip, r3
.L58:
	movs	r3, #128
	movs	r2, #128
	lsls	r3, r3, #6
	mov	r8, r3
	lsls	r2, r2, #3
	subs	r2, r2, r7
	lsrs	r3, r2, #1
	ldr	r0, .L69+84
	lsls	r3, r3, #2
	add	r7, r7, r8
	mov	r9, r0
	mov	r8, r3
	movs	r3, #0
	lsls	r7, r7, #1
	adds	r7, r1, r7
.L59:
	mov	r0, r9
	ldr	r6, [r7, r3]
	orrs	r0, r6
	str	r0, [r7, r3]
	adds	r3, r3, #4
	cmp	r3, r8
	bne	.L59
	movs	r3, #1
	movs	r0, r2
	bics	r0, r3
	mov	r3, ip
	adds	r3, r3, r0
	cmp	r2, r0
	beq	.L60
	movs	r2, #128
	lsls	r2, r2, #6
	mov	ip, r2
	movs	r2, #128
	add	r3, r3, ip
	lsls	r3, r3, #1
	adds	r3, r1, r3
	ldrh	r1, [r3]
	lsls	r2, r2, #5
	orrs	r2, r1
	strh	r2, [r3]
.L60:
	movs	r3, #128
	movs	r7, #0
	lsls	r3, r3, #3
	str	r3, [r4, #8]
	movs	r2, #96
	movs	r3, #1
	str	r7, [sp, #40]
	str	r7, [sp, #36]
	str	r7, [sp, #32]
	str	r7, [sp, #28]
	str	r7, [sp, #24]
	str	r7, [sp, #20]
	str	r7, [sp, #16]
	str	r7, [sp, #12]
	str	r7, [sp, #8]
	str	r7, [sp, #4]
	str	r7, [sp]
	movs	r1, #64
	movs	r0, #0
	ldr	r6, .L69+88
	bl	.L71
	movs	r1, #0
	movs	r0, #1
	bl	.L72
	movs	r1, #0
	movs	r0, #0
	bl	.L72
	movs	r1, #64
	ldr	r0, .L69+92
	ldr	r3, .L69+96
	bl	.L6
	movs	r1, #16
	ldr	r0, .L69+100
	ldr	r3, .L69+104
	bl	.L6
	ldr	r3, .L69+108
	movs	r0, #1
	bl	.L6
	ldr	r2, .L69+112
	str	r7, [r4, #8]
	movs	r3, #0
	mov	r8, r2
	movs	r7, #16
	ldr	r6, .L69+116
.L61:
	mov	r2, r8
	subs	r3, r7, r3
	strh	r3, [r2]
	bl	.L71
	ldr	r3, [r4, #8]
	adds	r3, r3, #1
	str	r3, [r4, #8]
	cmp	r3, #15
	bls	.L61
	ldr	r3, .L69+120
	movs	r4, #8
	mov	r8, r3
	ldr	r7, .L69+124
.L62:
	bl	.L71
	bl	.L75
	bl	presses1
	ldrh	r3, [r7]
	tst	r4, r3
	bne	.L62
	movs	r0, #1
	bl	.L55
	ldr	r3, .L69+128
	ldr	r0, .L69+132
	bl	.L6
	ldr	r3, .L69+136
	strh	r0, [r3, #24]
	bl	mappause
.L63:
	movs	r3, #0
	mov	ip, r3
	b	.L58
.L68:
	ldr	r3, .L69+48
	movs	r1, #16
	movs	r0, #3
	mov	r10, r3
	bl	.L6
	movs	r3, #128
	lsls	r3, r3, #24
	mov	r8, r3
	str	r3, [sp]
	movs	r3, #224
	ldr	r7, .L69+56
	lsls	r3, r3, #1
	ldr	r2, .L69+140
	ldr	r1, .L69+144
	movs	r0, #3
	bl	.L73
	mov	r3, r8
	str	r3, [sp]
	movs	r3, #160
	ldr	r2, .L69+148
	lsls	r3, r3, #2
	ldr	r1, .L69+152
	movs	r0, #3
	bl	.L73
	ldr	r3, .L69+52
	movs	r1, #16
	ldr	r0, .L69+156
	mov	r9, r3
	bl	.L6
	b	.L57
.L70:
	.align	2
.L69:
	.word	hrt_ConfigRegisterRamReset
	.word	hrt_RegisterRamReset
	.word	hrt_DSPSetBGMode
	.word	hrt_DSPEnableBG
	.word	hrt_DSPEnableOBJ
	.word	hrt_DSPEnableLinearOBJ
	.word	hrt_DSPDisableForceBlank
	.word	hrt_InitTiledText
	.word	hrt_BGSetMapBase
	.word	hrt_BGSetTileBase
	.word	game
	.word	SaveFiles
	.word	hrt_SetOffset
	.word	hrt_LoadBGPal
	.word	hrt_DMA_Copy
	.word	100696064
	.word	pauseTiles
	.word	100673536
	.word	pauseMap
	.word	pausePal
	.word	VRAM
	.word	268439552
	.word	hrt_CreateOBJ
	.word	b_idleTiles
	.word	hrt_LoadOBJGFX
	.word	b_idlePal
	.word	hrt_LoadOBJPal
	.word	hrt_DSPDisableBG
	.word	67108948
	.word	hrt_VblankIntrWait
	.word	animbirdmap
	.word	67109168
	.word	mmEffectEx
	.word	g_pause
	.word	audio
	.word	100712448
	.word	worldmap1Tiles
	.word	100671488
	.word	worldmap1Map
	.word	worldmap1Pal
	.size	worldmap, .-worldmap
	.global	ychange1
	.global	xchange1
	.comm	map_confirm,12,4
	.comm	map_select,12,4
	.global	mappos
	.comm	continueBitmap,9120,4
	.comm	story4Bitmap,9592,4
	.comm	story3Bitmap,9596,4
	.comm	story2Bitmap,9592,4
	.comm	story1Bitmap,9264,4
	.comm	l1_1colmap,12000,4
	.comm	creditsPal,32,4
	.comm	creditsBitmap,4932,4
	.comm	disclaimerPal,32,4
	.comm	disclaimerBitmap,5028,4
	.comm	m_bgPalette,32,4
	.comm	m_titleTiles,800,4
	.comm	m_titleMap,2048,4
	.comm	m_bg_Tiles,864,4
	.comm	m_bg_Map,2048,4
	.comm	m_pressstartTiles,384,4
	.comm	m_startgameTiles,320,4
	.comm	m_arrow1Tiles,32,4
	.comm	m_arrow2Tiles,32,4
	.comm	m_arrow3Tiles,32,4
	.comm	m_arrow4Pal,32,4
	.comm	m_arrow4Tiles,32,4
	.comm	m_exitTiles,256,4
	.comm	m_continueMap,1280,4
	.comm	m_continueTiles,352,4
	.comm	m_continuePal,32,4
	.comm	m_newgameTiles,512,4
	.comm	m_optionsTiles,512,4
	.comm	m_sfxvolTiles,352,4
	.comm	m_musvolTiles,416,4
	.comm	m_creditsTiles,224,4
	.comm	m_yearTiles,1152,4
	.comm	h_flightTiles,1024,4
	.comm	h_stageTiles,256,4
	.comm	h_xTiles,32,4
	.comm	h_numsTiles,320,4
	.comm	hudTextPal,32,4
	.comm	e_cralen2Tiles,128,4
	.comm	e_cralen1Tiles,128,4
	.comm	b_fireTiles,32,4
	.comm	b_dieTiles,128,4
	.comm	b_fallTiles,128,4
	.comm	b_fall_fTiles,128,4
	.comm	b_flapTiles,128,4
	.comm	b_run1Tiles,128,4
	.comm	b_run1_fTiles,128,4
	.comm	b_run2Tiles,128,4
	.comm	b_run2_fTiles,128,4
	.comm	b_run3Tiles,128,4
	.comm	b_idle_fTiles,128,4
	.comm	b_idleTiles,128,4
	.comm	h_headTiles,32,4
	.comm	b_idlePal,32,4
	.comm	heartPal,32,4
	.comm	h_emptyTiles,128,4
	.comm	h_fullTiles,128,4
	.comm	h_halfTiles,128,4
	.comm	f_fullTiles,128,4
	.comm	f_25Tiles,128,4
	.comm	f_24Tiles,128,4
	.comm	f_23Tiles,128,4
	.comm	f_22Tiles,128,4
	.comm	f_21Tiles,128,4
	.comm	f_20Tiles,128,4
	.comm	f_19Tiles,128,4
	.comm	f_18Tiles,128,4
	.comm	f_17Tiles,128,4
	.comm	f_16Tiles,128,4
	.comm	f_15Tiles,128,4
	.comm	f_14Tiles,128,4
	.comm	f_13Tiles,128,4
	.comm	f_12Tiles,128,4
	.comm	f_11Tiles,128,4
	.comm	f_10Tiles,128,4
	.comm	f_9Tiles,128,4
	.comm	f_8Tiles,128,4
	.comm	f_7Tiles,128,4
	.comm	f_6Tiles,128,4
	.comm	f_5Tiles,128,4
	.comm	f_4Tiles,128,4
	.comm	f_3Tiles,128,4
	.comm	f_2Tiles,128,4
	.comm	f_1Tiles,128,4
	.comm	f_0Pal,32,4
	.comm	f_0Tiles,128,4
	.comm	level2Pal,32,4
	.comm	level2MetaMap,6000,4
	.comm	level2MetaTiles,160,4
	.comm	level2Tiles,1472,4
	.comm	level1Pal,32,4
	.comm	level1MetaMap,6000,4
	.comm	level1MetaTiles,168,4
	.comm	level1Tiles,1632,4
	.comm	sprites,1024,4
	.section	.rodata
	.align	2
	.set	.LANCHOR1,. + 0
	.type	ychange1, %object
	.size	ychange1, 4
ychange1:
	.byte	96
	.byte	96
	.byte	96
	.byte	64
	.type	xchange1, %object
	.size	xchange1, 4
xchange1:
	.byte	64
	.byte	112
	.byte	-80
	.byte	-80
	.bss
	.set	.LANCHOR0,. + 0
	.type	mappos, %object
	.size	mappos, 1
mappos:
	.space	1
	.ident	"GCC: (devkitARM release 49) 8.1.0"
	.text
	.code 16
	.align	1
.L6:
	bx	r3
.L7:
	bx	r4
.L55:
	bx	r5
.L71:
	bx	r6
.L73:
	bx	r7
.L75:
	bx	r8
.L74:
	bx	r9
.L72:
	bx	r10
