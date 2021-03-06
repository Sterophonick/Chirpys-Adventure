#include <libheart.h>

const char gl_pause_r[]="Resume";
const char gl_pause_b[]="Return to map";
const char gl_pause_q[]="Quit";
const char gl_choice_a[]="Are you sure?";
const char gl_choice_y[]="Yes";
const char gl_choice_n[]="No";
const char gl_game_over[]="Game Over.";
const char gl_game_lvlcomplete[]="Level Complete!";
const char gl_pause_warn[]="Overwrite the file?";
const char gl_game_saving[]="Saving...";
const char gl_game_saved[]="Game Saved.";
const char gl_generic_press_a[]="Press A to continue.";
const char gl_game_stage_no[]="Stage";
const char gl_complete_a[]="A - Next level";
const char gl_complete_b[]="B - Back to map";
const char gl_options_sndtst[]="Sound Test";
const char gl_newgame_warn[]="You'll lose all data if you overwrite this file.";
const char gl_options_controls[]="Controls";
const char gl_controls_a[]="A - Jump/Fly";
const char gl_controls_b[]="B - Fire";
const char gl_controls_dpad[]="D-Pad - Move";
const char gl_controls_start[]="Start - Pause";
const char gl_game_continue[]="Continue?";

const char gl_continue_percent[]="% complete";

const char gl_options_audio_0[]="|----------";
const char gl_options_audio_1[]="-|---------";
const char gl_options_audio_2[]="--|--------";
const char gl_options_audio_3[]="---|-------";
const char gl_options_audio_4[]="----|------";
const char gl_options_audio_5[]="-----|-----";
const char gl_options_audio_6[]="------|----";
const char gl_options_audio_7[]="-------|---";
const char gl_options_audio_8[]="--------|--";
const char gl_options_audio_9[]="---------|-";
const char gl_options_audio_A[]="----------|";


const char gl_debug_restart[]="The system will now restart.";
const char gl_debug_abort[]="The process was aborted.";
const char gl_debug_erasing[]="Erasing...";
const char gl_debug_all[]="All data will be erased.";

const char gl_continue_fileempty[]="File is Empty.";

const char gl_debug_erase[]="Erase save data?";
const char gl_debug_build[]="Build date: 13530005212020";

const char gl_options_soundtest_music[]="Music ID";
const char gl_options_soundtest_sound[]="Sound ID";

const char gl_debug_saveversion[]="SRAM_V112";

const char gl_debug_savenote_1[]="The game has found that there";
const char gl_debug_savenote_2[]="is no save data.";
const char gl_debug_savenote_3[]="If this is your first time";
const char gl_debug_savenote_4[]="playing then relax!";
const char gl_debug_savenote_5[]="Chirpy's Adventure requires";
const char gl_debug_savenote_6[]="8kb of SRAM.";

const char gl_debug_data_error[]="BACKUP MEMORY ERROR!";

const char gl_story_1_1[]="Chirpy just got home from a";
const char gl_story_1_2[]="good lunch.";

const char gl_story_2_1[]="He went up to the tree where";
const char gl_story_2_2[]="his nest is.";

const char gl_story_3_1[]="But it has gone missing!";

const char gl_story_4_1[]="Chirpy notices tracks nearby";
const char gl_story_4_2[]="the tree, and decides to";
const char gl_story_4_3[]="follow them...";

const char gl_menu_new[]="New Game";
const char gl_menu_cont[]="Continue";
const char gl_menu_opt[]="Options";
const char gl_menu_exit[]="Exit";
const char gl_menu_press[]="Press Start!";
const char gl_menu_name[]="Sterophonick 2020";

const char gl_menu_cont_empt[]="Empty";
const char gl_menu_f1[]="File 1: ";
const char gl_menu_f2[]="File 2: ";
const char gl_menu_f3[]="File 3: ";
const char gl_menu_cont_stage[]="Stage";

const char gl_menu_opt_music[]="Music Volume";
const char gl_menu_opt_sound[]="Sound Volume";
const char gl_menu_opt_credits[]="Credits";
const char gl_menu_opt_sndtst[]="Sound Test";

const char gl_game_hud_flight[]="Flight";
const char gl_game_hud_x[]="x";

const char gl_debug_px[]="PLAYR_X:";
const char gl_debug_py[]="PLAYR_Y:";
const char gl_debug_sx[]="SCREEN_X:";

const char gl_debug_menu_header[] = "Chirpy's Adventure Debug Menu";
const char gl_debug_menu_sndtst[] = "SOUND_TEST";
const char gl_debug_menu_lvlslt[] = "LEVEL_SELECT";
const char gl_debug_menu_svedtr[] = "SAVE_EDITOR";
const char gl_debug_menu_sprtst[] = "SPRITE_TEST";
const char gl_debug_menu_lvlslt_world1[] = "WORLD_1";
const char gl_debug_menu_lvlslt_world2[] = "WORLD_2";
const char gl_debug_menu_lvlslt_world3[] = "WORLD_3";
const char gl_debug_menu_lvlslt_world4[] = "WORLD_4";
const char gl_debug_menu_lvlslt_world5[] = "WORLD_5";

const char *gl_credits[107] = {
	"Chirpy's Adventure",
	"Sterophonick 2020",
	"",
	"Programming",
	"------------------------------",
	"Sterophonick",
	"github.com/Sterophonick",
	"",
	"Programming Help",
	"------------------------------",
	"Dwedit",
	"DekuTree64",
	"sverx",
	"hot_pengu",
	"exelotl",
	"",
	"Graphics",
	"------------------------------",
	"Sterophonick",
	"Insequearaux",
	"",
	"Level Design",
	"------------------------------",
	"Sterophonick",
	"Insequearaux",
	"",
	"Music & SFX",
	"------------------------------",
	"Purple Motion",
	"DuckyMaster",
	"Terry Cavanagh",
	"FearOfDark",
	"Doh",
	"HAL Laboratory",
	"Nintendo Co, Ltd.",
	"ogge & raina",
	"Valve Software",
	"Mojang",
	"SEGA",
	"Tony (@pressedyes)",
	"",
	"Tools Used",
	"------------------------------",
	"Usenti",
	"PE Map Editor",
	"devkitPro",
	"mmutil",
	"Microsoft Visual Studio",
	"mGBA",
	"EZ-Flash Omega",
	"NO$GBA",
	"",
	"------------------------------",
	"HeartLib API created",
	"by Sterophonick.",
	"Some code and resources",
	"for this engine were borrowed",
	"from Tubooboo, Peter Schraut",
	"LibGBA, Maxmod, and",
	"Mark Holloway.",
	"",
	"Special Thanks",
	"(In no particular order)",
	"------------------------------",
	"DevKitPro",
	"3DSage",
	"Jason Wilkins",
	"hot_pengu",
	"exelotl",
	"quisseh",
	"Tubooboo",
	"Jay Van Hutten",
	"Dwedit",
	"Sasq64",
	"FluBBa",
	"Loopy",
	"Peter Schraut",
	"Coranac",
	"Loirak",
	"sergeeo",
	"",
	"and YOU!",
	"",
	"This game was not licensed by,",
	"endorsed by, or approved by",
	"Nintendo of America, Nintendo",
	"Co. Ltd, or any subsidiaries.",
	"",
	"This game was not developed",
	"with access to any official",
	"SDKs, tools, or information",
	"protected by non-disclosure",
	"agreements.",
	"",
	"Game Boy and Nintendo are",
	"trademarks of Nintendo Co.",
	"Ltd.",
	"",
	"This product is licensed under",
	"the GNU GPL. I will not sell",
	"it; it is for free. If you",
	"paid money for this game, I",
	"suggest you get a refund ASAP.",
	"",
	"In memory of ngine.de",
	" ",
	" ",
	"Thank you for playing!"
};