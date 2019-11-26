	.cpu arm7tdmi
	.eabi_attribute 23, 1
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 2
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"menucode.c"
	.text
	.global	__aeabi_uidivmod
	.align	1
	.p2align 2,,3
	.global	animcursor
	.arch armv4t
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	animcursor, %function
animcursor:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, lr}
	ldr	r3, .L21
	sub	sp, sp, #12
	ldr	r0, [r3, #24]
	movs	r1, #3
	ldr	r3, .L21+4
	bl	.L23
	cmp	r1, #0
	bne	.L1
	ldr	r4, .L21+8
	ldrb	r3, [r4, #1]
	adds	r3, r3, #1
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	strb	r3, [r4, #1]
	cmp	r3, #7
	beq	.L14
	cmp	r3, #0
	beq	.L5
	cmp	r3, #1
	beq	.L15
.L7:
	cmp	r3, #2
	beq	.L16
.L8:
	cmp	r3, #3
	beq	.L17
.L9:
	cmp	r3, #4
	beq	.L18
.L10:
	cmp	r3, #5
	beq	.L19
.L11:
	cmp	r3, #6
	beq	.L20
.L1:
	add	sp, sp, #12
	@ sp needed
	pop	{r4, r5}
	pop	{r0}
	bx	r0
.L14:
	strb	r1, [r4, #1]
.L5:
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	ldr	r2, .L21+12
	movs	r3, #16
	ldr	r1, .L21+16
	movs	r0, #3
	ldr	r5, .L21+20
	bl	.L24
	ldrb	r3, [r4, #1]
	cmp	r3, #1
	bne	.L7
.L15:
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	ldr	r2, .L21+12
	movs	r3, #16
	ldr	r1, .L21+24
	movs	r0, #3
	ldr	r5, .L21+20
	bl	.L24
	ldrb	r3, [r4, #1]
	cmp	r3, #2
	bne	.L8
.L16:
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	ldr	r2, .L21+12
	movs	r3, #16
	ldr	r1, .L21+28
	movs	r0, #3
	ldr	r5, .L21+20
	bl	.L24
	ldrb	r3, [r4, #1]
	cmp	r3, #3
	bne	.L9
.L17:
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	ldr	r2, .L21+12
	movs	r3, #16
	ldr	r1, .L21+32
	movs	r0, #3
	ldr	r5, .L21+20
	bl	.L24
	ldrb	r3, [r4, #1]
	cmp	r3, #4
	bne	.L10
.L18:
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	ldr	r2, .L21+12
	movs	r3, #16
	ldr	r1, .L21+28
	movs	r0, #3
	ldr	r5, .L21+20
	bl	.L24
	ldrb	r3, [r4, #1]
	cmp	r3, #5
	bne	.L11
.L19:
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	ldr	r2, .L21+12
	movs	r3, #16
	ldr	r1, .L21+24
	movs	r0, #3
	ldr	r5, .L21+20
	bl	.L24
	ldrb	r3, [r4, #1]
	cmp	r3, #6
	bne	.L1
.L20:
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	ldr	r2, .L21+12
	movs	r3, #16
	ldr	r1, .L21+16
	movs	r0, #3
	ldr	r4, .L21+20
	bl	.L25
	b	.L1
.L22:
	.align	2
.L21:
	.word	game
	.word	__aeabi_uidivmod
	.word	menu
	.word	100746272
	.word	m_arrow1Tiles
	.word	hrt_DMA_Copy
	.word	m_arrow2Tiles
	.word	m_arrow3Tiles
	.word	m_arrow4Tiles
	.size	animcursor, .-animcursor
	.align	1
	.p2align 2,,3
	.global	menucode
	.syntax unified
	.code	16
	.thumb_func
	.fpu softvfp
	.type	menucode, %function
menucode:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 0, uses_anonymous_args = 0
	push	{r4, r5, r6, r7, lr}
	mov	r5, r8
	mov	r6, r9
	mov	lr, fp
	mov	r7, r10
	push	{r5, r6, r7, lr}
	ldr	r3, .L156
	sub	sp, sp, #76
	add	r2, sp, #60
	ldmia	r3!, {r0, r1, r4}
	stmia	r2!, {r0, r1, r4}
	movs	r3, #0
	ldr	r2, .L156+4
	movs	r4, #16
	mov	r8, r2
	ldr	r5, .L156+8
	ldr	r6, .L156+12
	str	r3, [r5, #8]
.L27:
	subs	r3, r4, r3
	strh	r3, [r6]
	bl	.L162
	ldr	r3, [r5, #8]
	adds	r3, r3, #1
	str	r3, [r5, #8]
	cmp	r3, #15
	bls	.L27
	movs	r3, #0
	movs	r2, #0
	movs	r1, #0
	str	r3, [sp, #12]
	str	r3, [sp, #8]
	str	r3, [sp, #4]
	str	r3, [sp]
	ldr	r4, .L156+16
	adds	r3, r3, #1
	movs	r0, #0
	bl	.L25
	ldr	r3, .L156+20
	bl	.L23
	movs	r0, #0
	ldr	r3, .L156+24
	bl	.L23
	ldr	r3, .L156+28
	movs	r0, #0
	mov	r10, r3
	bl	.L23
	movs	r0, #1
	bl	.L163
	movs	r0, #2
	bl	.L163
	movs	r0, #3
	bl	.L163
	ldr	r3, .L156+32
	bl	.L23
	ldr	r3, .L156+36
	bl	.L23
	movs	r0, #0
	ldr	r3, .L156+40
	bl	.L23
	movs	r1, #4
	movs	r0, #2
	ldr	r3, .L156+44
	bl	.L23
	movs	r1, #3
	movs	r0, #2
	ldr	r3, .L156+48
	bl	.L23
	movs	r1, #5
	movs	r0, #1
	ldr	r3, .L156+44
	bl	.L23
	movs	r1, #2
	movs	r0, #1
	ldr	r3, .L156+48
	bl	.L23
	movs	r1, #192
	movs	r0, #2
	lsls	r1, r1, #6
	ldr	r3, .L156+52
	bl	.L23
	movs	r2, #96
	ldr	r3, .L156+56
	movs	r1, #16
	strh	r2, [r3]
	movs	r0, #3
	ldr	r3, .L156+52
	movs	r4, #128
	bl	.L23
	movs	r3, #224
	lsls	r4, r4, #24
	str	r4, [sp]
	lsls	r3, r3, #1
	ldr	r2, .L156+60
	ldr	r1, .L156+64
	movs	r0, #3
	ldr	r6, .L156+68
	bl	.L164
	movs	r3, #128
	str	r4, [sp]
	lsls	r3, r3, #3
	ldr	r2, .L156+72
	ldr	r1, .L156+76
	movs	r0, #3
	ldr	r6, .L156+68
	bl	.L164
	movs	r3, #200
	str	r4, [sp]
	lsls	r3, r3, #2
	ldr	r2, .L156+80
	ldr	r1, .L156+84
	movs	r0, #3
	ldr	r6, .L156+68
	bl	.L164
	movs	r3, #128
	ldr	r2, .L156+88
	str	r4, [sp]
	lsls	r3, r3, #3
	ldr	r1, .L156+92
	movs	r0, #3
	ldr	r4, .L156+68
	bl	.L25
	ldr	r3, .L156+96
	movs	r1, #16
	ldr	r0, .L156+100
	bl	.L23
	ldr	r3, .L156+104
	ldr	r2, [r3]
	lsls	r3, r2, #30
	lsrs	r3, r3, #31
	bne	.LCB307
	bl	.L83	@far jump
.LCB307:
	movs	r0, #128
	movs	r1, #128
	movs	r7, #1
	lsls	r0, r0, #7
	ldrh	r4, [r2, r0]
	lsls	r1, r1, #5
	orrs	r1, r4
	strh	r1, [r2, r0]
.L28:
	movs	r0, #128
	movs	r1, #128
	lsls	r0, r0, #6
	mov	ip, r0
	lsls	r1, r1, #3
	subs	r1, r1, r3
	lsrs	r0, r1, #1
	lsls	r0, r0, #2
	add	r3, r3, ip
	mov	ip, r0
	movs	r0, #0
	lsls	r3, r3, #1
	ldr	r6, .L156+108
	adds	r3, r2, r3
.L29:
	ldr	r4, [r3, r0]
	orrs	r4, r6
	str	r4, [r3, r0]
	adds	r0, r0, #4
	cmp	ip, r0
	bne	.L29
	movs	r3, #1
	movs	r0, r1
	bics	r0, r3
	adds	r3, r0, r7
	cmp	r0, r1
	beq	.L30
	movs	r1, #128
	lsls	r1, r1, #6
	mov	ip, r1
	add	r3, r3, ip
	lsls	r3, r3, #1
	adds	r2, r2, r3
	movs	r3, #128
	ldrh	r1, [r2]
	lsls	r3, r3, #5
	orrs	r3, r1
	strh	r3, [r2]
.L30:
	movs	r3, #128
	movs	r0, #60
	lsls	r3, r3, #3
	ldr	r6, .L156+112
	str	r3, [r5, #8]
	bl	.L164
	movs	r3, #96
	movs	r4, #128
	str	r3, [r5, #8]
	ldr	r7, .L156+56
	lsls	r4, r4, #1
.L31:
	bl	.L162
	ldr	r3, [r5, #8]
	strh	r3, [r7]
	adds	r3, r3, #2
	str	r3, [r5, #8]
	cmp	r3, r4
	bls	.L31
	movs	r1, #144
	ldr	r3, .L156+116
	lsls	r1, r1, #2
	ldr	r0, .L156+120
	bl	.L23
	ldr	r4, .L156+124
	ldr	r1, .L156+128
	movs	r0, #2
	bl	.L25
	ldr	r1, .L156+132
	movs	r0, #1
	bl	.L25
	movs	r0, #30
	movs	r4, #0
	bl	.L164
	movs	r6, #1
	ldr	r7, .L156+136
	str	r6, [sp, #12]
	movs	r3, #0
	movs	r2, #255
	movs	r1, #104
	movs	r0, #0
	str	r4, [sp, #40]
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	bl	.L165
	movs	r3, #4
	str	r6, [sp, #12]
	str	r3, [sp, #40]
	movs	r2, #255
	movs	r3, #0
	movs	r1, #120
	movs	r0, #1
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	bl	.L165
	movs	r3, #8
	str	r6, [sp, #12]
	str	r3, [sp, #40]
	movs	r2, #255
	movs	r3, #0
	movs	r1, #136
	movs	r0, #2
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	bl	.L165
	movs	r3, #12
	str	r6, [sp, #12]
	str	r3, [sp, #40]
	movs	r2, #255
	movs	r3, #0
	movs	r1, #152
	movs	r0, #3
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	bl	.L165
	movs	r3, #16
	str	r6, [sp, #12]
	str	r3, [sp, #40]
	movs	r2, #255
	movs	r3, #0
	movs	r1, #168
	movs	r0, #4
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	bl	.L165
	movs	r3, #20
	str	r6, [sp, #12]
	str	r3, [sp, #40]
	movs	r2, #255
	movs	r3, #0
	movs	r1, #184
	movs	r0, #5
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	bl	.L165
	movs	r3, #24
	str	r6, [sp, #12]
	str	r3, [sp, #40]
	movs	r2, #255
	movs	r3, #0
	movs	r1, #200
	movs	r0, #6
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	bl	.L165
	movs	r3, #28
	str	r6, [sp, #12]
	str	r3, [sp, #40]
	movs	r2, #255
	movs	r3, #0
	movs	r1, #216
	movs	r0, #7
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	bl	.L165
	movs	r3, #32
	movs	r2, #255
	str	r3, [sp, #40]
	str	r4, [sp, #36]
	str	r4, [sp, #32]
	str	r4, [sp, #28]
	str	r4, [sp, #24]
	str	r4, [sp, #20]
	str	r4, [sp, #16]
	str	r4, [sp, #12]
	str	r4, [sp, #8]
	str	r4, [sp, #4]
	str	r4, [sp]
	movs	r3, #0
	movs	r1, #232
	movs	r0, #8
	bl	.L165
	movs	r2, #0
	str	r4, [r5, #8]
	subs	r6, r6, #97
.L34:
	str	r4, [r5, #12]
	movs	r3, #0
	b	.L33
.L125:
	ldr	r2, [r5, #8]
.L33:
	lsls	r3, r3, #24
	lsrs	r0, r3, #24
	movs	r3, #208
	lsls	r3, r3, #23
	mov	ip, r3
	lsls	r1, r0, #28
	subs	r2, r6, r2
	add	r1, r1, ip
	lsls	r2, r2, #24
	ldr	r3, .L156+140
	lsrs	r2, r2, #24
	lsrs	r1, r1, #24
	bl	.L23
	ldr	r3, [r5, #12]
	adds	r3, r3, #1
	str	r3, [r5, #12]
	cmp	r3, #8
	bls	.L125
	bl	.L162
	ldr	r3, [r5, #8]
	adds	r2, r3, #1
	str	r2, [r5, #8]
	cmp	r2, #8
	bls	.L34
	ldr	r2, .L156+144
	movs	r1, #14
	movs	r0, #9
	ldr	r6, .L156+148
	bl	.L164
	movs	r3, #0
	movs	r2, #1
	str	r3, [sp, #28]
	str	r2, [sp, #32]
	str	r3, [sp, #24]
	str	r2, [sp, #20]
	str	r3, [sp, #16]
	str	r3, [sp, #12]
	str	r2, [sp, #8]
	str	r3, [sp, #4]
	str	r3, [sp]
	ldr	r4, .L156+152
	movs	r2, #0
	movs	r1, #0
	movs	r0, #1
	bl	.L25
	movs	r3, #128
	movs	r4, #0
	str	r3, [r5, #8]
	movs	r3, #0
	mov	r9, r4
	mov	fp, r3
	b	.L36
.L157:
	.align	2
.L156:
	.word	.LANCHOR0
	.word	hrt_VblankIntrWait
	.word	game
	.word	67108948
	.word	hrt_ConfigRegisterRamReset
	.word	hrt_RegisterRamReset
	.word	hrt_DSPSetBGMode
	.word	hrt_DSPEnableBG
	.word	hrt_DSPEnableOBJ
	.word	hrt_DSPDisableForceBlank
	.word	hrt_InitTiledText
	.word	hrt_BGSetMapBase
	.word	hrt_BGSetTileBase
	.word	hrt_SetOffset
	.word	67108886
	.word	100712448
	.word	m_bg_Tiles
	.word	hrt_DMA_Copy
	.word	100671488
	.word	m_bg_Map
	.word	100696064
	.word	m_titleTiles
	.word	100673536
	.word	m_titleMap
	.word	hrt_LoadBGPal
	.word	m_bgPalette
	.word	VRAM
	.word	268439552
	.word	hrt_SleepF
	.word	hrt_LoadOBJGFX
	.word	m_yearTiles
	.word	hrt_SetOBJPalEntry
	.word	1057
	.word	32767
	.word	hrt_CreateOBJ
	.word	hrt_SetOBJXY
	.word	gl_menu_press
	.word	hrt_PrintOnTilemap
	.word	hrt_SetFXMode
.L128:
	cmp	r3, #0
	bne	.L126
	movs	r3, #1
	movs	r4, #1
	mov	fp, r3
.L35:
	mov	r3, r9
	movs	r1, #16
	subs	r1, r1, r3
	lsls	r1, r1, #24
	mov	r0, r9
	ldr	r3, .L158
	lsrs	r1, r1, #24
	bl	.L23
	movs	r2, #128
	add	r4, r4, r9
	lsls	r4, r4, #24
	lsrs	r3, r4, #24
	mov	r9, r3
	ldr	r3, [r5, #8]
	adds	r3, r3, #2
	str	r3, [r5, #8]
	lsls	r2, r2, #1
	cmp	r3, r2
	bhi	.L127
.L36:
	bl	.L162
	ldr	r3, [r5, #8]
	ldr	r2, .L158+4
	strh	r3, [r2]
	mov	r3, r9
	cmp	r3, #16
	bne	.L128
	movs	r3, #1
	rsbs	r3, r3, #0
	movs	r4, #255
	mov	fp, r3
	b	.L35
.L127:
	ldr	r3, .L158+8
	ldrh	r3, [r3]
	lsls	r3, r3, #28
	bmi	.L37
	b	.L40
.L130:
	cmp	r3, #0
	bne	.L129
	movs	r3, #1
	movs	r4, #1
	mov	fp, r3
.L39:
	mov	r3, r9
	movs	r1, #16
	subs	r1, r1, r3
	add	r4, r4, r9
	lsls	r1, r1, #24
	mov	r0, r9
	ldr	r3, .L158
	lsrs	r1, r1, #24
	lsls	r4, r4, #24
	bl	.L23
	lsrs	r3, r4, #24
	mov	r9, r3
	ldr	r3, .L158+8
	ldrh	r3, [r3]
	lsls	r3, r3, #28
	bpl	.L40
.L37:
	bl	.L162
	mov	r3, r9
	cmp	r3, #16
	bne	.L130
	movs	r3, #1
	rsbs	r3, r3, #0
	movs	r4, #255
	mov	fp, r3
	b	.L39
.L126:
	mov	r3, fp
	lsls	r4, r3, #24
	lsrs	r4, r4, #24
	b	.L35
.L129:
	mov	r3, fp
	lsls	r4, r3, #24
	lsrs	r4, r4, #24
	b	.L39
.L40:
	movs	r3, #0
	movs	r2, #0
	str	r3, [sp, #32]
	str	r3, [sp, #28]
	str	r3, [sp, #24]
	str	r3, [sp, #20]
	str	r3, [sp, #16]
	str	r3, [sp, #12]
	str	r3, [sp, #8]
	str	r3, [sp, #4]
	str	r3, [sp]
	movs	r1, #0
	movs	r0, #0
	ldr	r4, .L158+12
	bl	.L25
	ldr	r2, .L158+16
	movs	r1, #14
	movs	r0, #9
	bl	.L164
	movs	r3, #96
	ldr	r4, .L158+4
	ldr	r2, .L158+20
	strh	r3, [r4]
	movs	r1, #7
	movs	r0, #1
	bl	.L164
	ldr	r2, .L158+24
	movs	r1, #8
	movs	r0, #1
	bl	.L164
	ldr	r2, .L158+28
	movs	r1, #9
	movs	r0, #1
	bl	.L164
	ldr	r2, .L158+32
	movs	r1, #10
	movs	r0, #1
	bl	.L164
	movs	r3, #128
	str	r3, [r5, #8]
	adds	r3, r3, #128
	mov	r9, r3
.L38:
	bl	.L162
	ldr	r3, [r5, #8]
	strh	r3, [r4]
	adds	r3, r3, #2
	str	r3, [r5, #8]
	cmp	r3, r9
	bls	.L38
	movs	r1, #16
	movs	r0, #1
	ldr	r3, .L158+36
	bl	.L23
	movs	r1, #16
	ldr	r0, .L158+40
	ldr	r3, .L158+44
	bl	.L23
	movs	r3, #33
	movs	r2, #1
	str	r3, [sp, #40]
	movs	r3, #0
	str	r2, [sp, #24]
	str	r3, [sp, #36]
	str	r3, [sp, #32]
	str	r3, [sp, #28]
	str	r3, [sp, #20]
	str	r3, [sp, #16]
	str	r3, [sp, #12]
	str	r3, [sp, #8]
	str	r3, [sp, #4]
	str	r3, [sp]
	adds	r2, r2, #55
	movs	r1, #0
	movs	r0, #9
	bl	.L165
	movs	r3, #3
	str	r3, [sp, #52]
	movs	r3, #0
	str	r3, [sp, #48]
	ldr	r3, .L158+48
	mov	r9, r3
	ldr	r3, .L158+8
	mov	fp, r3
	ldr	r7, .L158+52
.L41:
	movs	r4, #128
	b	.L42
.L43:
	mov	r3, r9
	ldrb	r3, [r3]
	cmp	r3, #0
	beq	.L44
	mov	r2, r9
	ldrb	r2, [r2, #3]
	cmp	r2, #0
	bne	.LCB894
	b	.L131	@long jump
.LCB894:
.L44:
	mov	r2, fp
	movs	r1, #64
	ldrh	r2, [r2]
	tst	r1, r2
	beq	.L45
	movs	r2, #0
	mov	r1, r9
	strb	r2, [r1, #3]
.L45:
	mov	r2, fp
	ldrh	r2, [r2]
	tst	r4, r2
	bne	.L46
	ldr	r2, [sp, #52]
	cmp	r2, r3
	beq	.L46
	mov	r2, r9
	ldrb	r2, [r2, #4]
	cmp	r2, #0
	beq	.L132
.L46:
	mov	r2, fp
	ldrh	r2, [r2]
	tst	r4, r2
	beq	.L47
	movs	r2, #0
	mov	r1, r9
	strb	r2, [r1, #4]
.L47:
	adds	r2, r3, #7
	lsls	r2, r2, #27
	ldr	r3, .L158+56
	lsrs	r2, r2, #24
	movs	r1, #0
	movs	r0, #9
	bl	.L23
	mov	r3, fp
	ldrh	r3, [r3]
	lsls	r3, r3, #31
	bpl	.L133
.L42:
	bl	.L162
	bl	animcursor
	mov	r3, fp
	movs	r2, #64
	ldrh	r3, [r3]
	tst	r2, r3
	beq	.L43
	mov	r3, r9
	ldrb	r3, [r3]
	b	.L44
.L132:
	mov	r2, r9
	adds	r3, r3, #1
	strb	r3, [r2]
	movs	r3, #1
	add	r0, sp, #60
	strb	r3, [r2, #4]
	ldr	r3, .L158+60
	bl	.L23
	ldr	r3, .L158+64
	strh	r0, [r3]
	mov	r3, r9
	ldrb	r3, [r3]
	b	.L46
.L133:
	mov	r3, r9
	ldrb	r2, [r3]
	ldr	r3, [sp, #48]
	cmp	r3, #0
	beq	.LCB998
	b	.L134	@long jump
.LCB998:
	cmp	r2, #2
	beq	.L135
.L51:
	cmp	r2, #1
	bhi	.L41
	ldr	r3, .L158+68
	movs	r0, #0
	bl	.L23
	movs	r0, #0
	bl	.L163
	ldr	r3, .L158+72
	movs	r0, #1
	bl	.L23
	movs	r0, #2
	bl	.L163
	movs	r0, #3
	bl	.L163
	ldr	r3, .L158+76
	bl	.L23
	ldr	r3, .L158+80
	bl	.L23
	movs	r0, #0
	ldr	r3, .L158+84
	bl	.L23
	movs	r1, #4
	movs	r0, #2
	ldr	r3, .L158+88
	bl	.L23
	movs	r1, #3
	movs	r0, #2
	ldr	r3, .L158+92
	bl	.L23
	movs	r1, #5
	movs	r0, #1
	ldr	r3, .L158+88
	bl	.L23
	movs	r1, #2
	movs	r0, #1
	ldr	r3, .L158+92
	bl	.L23
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	ldr	r2, .L158+96
	movs	r3, #176
	ldr	r1, .L158+100
	movs	r0, #3
	ldr	r4, .L158+104
	bl	.L25
	movs	r3, #128
	lsls	r3, r3, #24
	str	r3, [sp]
	movs	r3, #160
	ldr	r2, .L158+108
	lsls	r3, r3, #2
	ldr	r1, .L158+112
	movs	r0, #3
	ldr	r4, .L158+104
	bl	.L25
	movs	r1, #16
	movs	r0, #3
	ldr	r3, .L158+36
	bl	.L23
	movs	r1, #16
	ldr	r0, .L158+116
	ldr	r3, .L158+120
	bl	.L23
	b	.L41
.L131:
	mov	r2, r9
	subs	r3, r3, #1
	strb	r3, [r2]
	movs	r3, #1
	add	r0, sp, #60
	strb	r3, [r2, #3]
	ldr	r3, .L158+60
	bl	.L23
	ldr	r3, .L158+64
	strh	r0, [r3]
	mov	r3, r9
	ldrb	r3, [r3]
	b	.L44
.L135:
	movs	r3, #2
	adds	r3, r3, #255
	str	r3, [r5, #8]
	ldr	r4, .L158+4
.L52:
	bl	.L162
	ldr	r3, [r5, #8]
	strh	r3, [r4]
	subs	r3, r3, #2
	str	r3, [r5, #8]
	cmp	r3, #128
	bhi	.L52
	movs	r2, r7
	movs	r1, #7
	movs	r0, #1
	bl	.L164
	ldr	r2, .L158+124
	movs	r1, #8
	movs	r0, #1
	bl	.L164
	ldr	r2, .L158+128
	movs	r1, #9
	movs	r0, #1
	bl	.L164
	ldr	r2, .L158+132
	movs	r1, #10
	movs	r0, #1
	bl	.L164
	ldr	r2, .L158+32
	movs	r1, #11
	movs	r0, #1
	bl	.L164
	movs	r3, #128
	movs	r4, #128
	str	r3, [r5, #8]
	lsls	r4, r4, #1
.L53:
	bl	.L162
	ldr	r3, [r5, #8]
	ldr	r2, .L158+4
	strh	r3, [r2]
	adds	r3, r3, #2
	str	r3, [r5, #8]
	cmp	r3, r4
	bls	.L53
	mov	r3, r9
	ldrb	r2, [r3]
	movs	r3, #4
	str	r3, [sp, #52]
	subs	r3, r3, #3
	str	r3, [sp, #48]
	b	.L51
.L134:
	ldr	r3, .L158+136
	mov	r8, r3
	movs	r3, #32
	mov	r10, r3
	ldr	r5, .L158+140
	ldr	r4, .L158+8
.L50:
	ldrb	r3, [r5, #2]
.L82:
	cmp	r2, #0
	beq	.L136
.L121:
	b	.L121
.L159:
	.align	2
.L158:
	.word	hrt_SetFXAlphaLevel
	.word	67108882
	.word	67109168
	.word	hrt_SetFXMode
	.word	.LC42
	.word	gl_menu_new
	.word	gl_menu_cont
	.word	gl_menu_opt
	.word	gl_menu_exit
	.word	hrt_SetOffset
	.word	m_arrow4Pal
	.word	hrt_LoadOBJPal
	.word	menu
	.word	gl_menu_opt_music
	.word	hrt_SetOBJXY
	.word	mmEffectEx
	.word	audio
	.word	hrt_DSPSetBGMode
	.word	hrt_DSPDisableBG
	.word	hrt_DSPEnableOBJ
	.word	hrt_DSPDisableForceBlank
	.word	hrt_InitTiledText
	.word	hrt_BGSetMapBase
	.word	hrt_BGSetTileBase
	.word	100712448
	.word	m_continueTiles
	.word	hrt_DMA_Copy
	.word	100671488
	.word	m_continueMap
	.word	m_continuePal
	.word	hrt_LoadBGPal
	.word	gl_menu_opt_sound
	.word	gl_menu_opt_credits
	.word	gl_options_controls
	.word	.LC62
	.word	SaveFiles
.L136:
	adds	r2, r2, #16
	mov	fp, r2
.L55:
	mov	r1, r10
	ldrh	r2, [r4]
	tst	r1, r2
	bne	.L57
	cmp	r3, #0
	bne	.L58
.L60:
	ldr	r3, .L160
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #1
	beq	.L137
.L61:
	cmp	r3, #2
	beq	.L138
.L62:
	cmp	r3, #3
	beq	.L139
.L63:
	cmp	r3, #4
	beq	.L140
.L64:
	cmp	r3, #5
	beq	.L141
.L65:
	cmp	r3, #6
	beq	.L142
.L66:
	cmp	r3, #7
	beq	.L143
.L67:
	cmp	r3, #8
	beq	.L144
.L68:
	cmp	r3, #9
	beq	.L145
.L69:
	cmp	r3, #10
	beq	.L146
.L57:
	mov	r1, fp
	ldrh	r2, [r4]
	tst	r1, r2
	beq	.L70
.L147:
	mov	r2, r9
	ldrb	r2, [r2]
	cmp	r2, #0
	beq	.L55
	b	.L121
.L58:
	subs	r3, r3, #1
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	strb	r3, [r5, #2]
	beq	.L60
	cmp	r3, #1
	bne	.L61
.L137:
	ldr	r3, .L160+4
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #2
	bne	.L62
.L138:
	ldr	r3, .L160+8
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #3
	bne	.L63
.L139:
	ldr	r3, .L160+12
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #4
	bne	.L64
.L140:
	ldr	r3, .L160+16
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #5
	bne	.L65
.L141:
	ldr	r3, .L160+20
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #6
	bne	.L66
.L142:
	ldr	r3, .L160+24
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #7
	bne	.L67
.L143:
	ldr	r3, .L160+28
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #8
	bne	.L68
.L144:
	ldr	r3, .L160+32
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #9
	bne	.L69
.L145:
	ldr	r3, .L160+36
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #10
	bne	.L57
.L146:
	ldr	r3, .L160+40
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	mov	r1, fp
	ldrh	r2, [r4]
	ldrb	r3, [r5, #2]
	tst	r1, r2
	bne	.L147
.L70:
	cmp	r3, #9
	bhi	.L71
	adds	r3, r3, #1
	lsls	r3, r3, #24
	lsrs	r3, r3, #24
	strb	r3, [r5, #2]
	cmp	r3, #1
	bne	.L71
	ldr	r3, .L160+4
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
.L71:
	cmp	r3, #2
	beq	.L148
.L72:
	cmp	r3, #3
	beq	.L149
	cmp	r3, #4
	beq	.L150
.L74:
	cmp	r3, #5
	beq	.L151
.L75:
	cmp	r3, #6
	beq	.L152
.L76:
	cmp	r3, #7
	beq	.L153
.L77:
	cmp	r3, #8
	beq	.L154
.L78:
	cmp	r3, #9
	beq	.L155
	cmp	r3, #10
	beq	.L80
.L81:
	mov	r2, r9
	ldrb	r2, [r2]
	b	.L82
.L155:
	ldr	r3, .L160+36
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #10
	bne	.L81
.L80:
	ldr	r3, .L160+40
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	mov	r3, r9
	ldrb	r2, [r3]
	b	.L50
.L154:
	ldr	r3, .L160+32
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	b	.L78
.L149:
	ldr	r3, .L160+12
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #4
	bne	.L74
.L150:
	ldr	r3, .L160+16
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #5
	bne	.L75
.L151:
	ldr	r3, .L160+20
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #6
	bne	.L76
.L152:
	ldr	r3, .L160+24
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	cmp	r3, #7
	bne	.L77
.L153:
	ldr	r3, .L160+28
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	b	.L77
.L148:
	ldr	r3, .L160+8
	mov	r2, r8
	str	r3, [sp]
	movs	r1, #7
	movs	r3, r7
	movs	r0, #1
	bl	.L164
	ldrb	r3, [r5, #2]
	b	.L72
.L83:
	movs	r7, #0
	bl	.L28	@ far jump
.L161:
	.align	2
.L160:
	.word	gl_options_audio_0
	.word	gl_options_audio_1
	.word	gl_options_audio_2
	.word	gl_options_audio_3
	.word	gl_options_audio_4
	.word	gl_options_audio_5
	.word	gl_options_audio_6
	.word	gl_options_audio_7
	.word	gl_options_audio_8
	.word	gl_options_audio_9
	.word	gl_options_audio_A
	.size	menucode, .-menucode
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
	.set	.LANCHOR0,. + 0
.LC0:
	.word	12
	.short	1024
	.short	0
	.byte	-1
	.byte	-1
	.space	2
	.section	.rodata.str1.4,"aMS",%progbits,1
	.align	2
.LC42:
	.ascii	"            \000"
	.space	3
.LC62:
	.ascii	"%s %s\000"
	.ident	"GCC: (devkitARM release 49) 8.1.0"
	.text
	.code 16
	.align	1
.L23:
	bx	r3
.L25:
	bx	r4
.L24:
	bx	r5
.L164:
	bx	r6
.L165:
	bx	r7
.L162:
	bx	r8
.L163:
	bx	r10
