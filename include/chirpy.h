enum ChirpyState{
	Idle,
	Flight,
	Jump,
	Die,
	Walk,
	Fire
};

typedef struct{
	s32 playerX; //Real X
	s32 playerY; //Real Y
	u16 playerSX; //X Position on Screen
	u16 playerSY; //Y Position on Screen
	u8 playerWIDTH; //Player Width
	u8 playerHEIGHT; //Player Height
	s32 playerAX; //Player Adjust X
	s32 playerAY; //Player Adjust Y
	u32 playerXV; //Player X Velocity
	u32 playerYV; //Player Y Velocity
	u8 playerFlightMeter; //Flight Remaining
	u8 playerHealth; //Player Health
	u8 playerLives; //Player lives remaining
	
}player;