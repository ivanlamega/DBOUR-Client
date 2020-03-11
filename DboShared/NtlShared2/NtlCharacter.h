#pragma once

#include "NtlItem.h"
#include "NtlSharedDef.h"
#include "NtlCharacterState.h"
#include "NtlAvatar.h"
#include "NtlBitFlag.h"
#include "NtlGuild.h"
#include "NtlActionPattern.h"

#define DBO_RP_CHARGE_INTERVAL_IN_MILLISECS			(Dbo_GetRpChargeIntervalInMilliSecs(CFormulaTable::m_afRate[71][4]))
#define DBO_RP_DIMIMUTION_INTERVAL_IN_MILLISECS		(Dbo_GetRpDiminutionIntervalInMilliSecs(CFormulaTable::m_afRate[72][4]))
#define DBO_BATTLE_REGEN_DURATION_IN_MILLISECS		(Dbo_GetRpDiminutionIntervalInMilliSecs(CFormulaTable::m_afRate[603][1]))

enum eRETURNMODE
{
	 eNORMAL_WALK
	,eNORMAL_RUN
	,eCOMEBACK_RUN
	,eINVALID_RETURNMODE
};

enum eBOTROLETYPE // [11/10/2008]
{
	 BOTROLE_NPC = 0
	,BOTROLE_MOB

	,INVALID_BOTROLE_TYPE = -1
};

enum eBOTPARAMETERSCHANGE_TYPE // [11/6/2008]
{
	BOTPARAMTYPE_NICNAME,
	BOTPARAMTYPE_ROLECHANGE,

	INVALID_BOTPARAMETERSCHANGE_TYPE = -1,
};

enum eDEL_TYPE
{
	DEL_TYPE_NONE,
	DEL_TYPE_DONE,
	DEL_TYPE_WAIT,
	
};
// Á¾Á· Á¤ÀÇ
enum eRACE
{
	RACE_HUMAN,
	RACE_NAMEK,
	RACE_MAJIN,
	//DBONU RACES
	RACE_FREEZA,
	RACE_KAIOSHIN,

	RACE_COUNT,
	RACE_UNKNOWN	= 0xFF,

	RACE_FIRST		= RACE_HUMAN,
	RACE_LAST		= RACE_MAJIN
};

// Á¾Á· Á¤ÀÇ ÇÃ·¡±×
enum eRACE_FLAG
{
	RACE_HUMAN_FLAG = MAKE_BIT_FLAG( RACE_HUMAN ),
	RACE_NAMEK_FLAG	= MAKE_BIT_FLAG( RACE_NAMEK ),
	RACE_MAJIN_FLAG	= MAKE_BIT_FLAG( RACE_MAJIN ),
	RACE_FREEZA_FLAG = MAKE_BIT_FLAG(RACE_FREEZA),
	RACE_KAIOSHIN_FLAG = MAKE_BIT_FLAG(RACE_KAIOSHIN),
};

enum eGENDER
{
	GENDER_MALE,
	GENDER_FEMALE,
	GENDER_ONE_SEX,

	GENDER_COUNT,
	GENDER_UNKNOWN	= 0xFF,

	GENDER_FIRST	= GENDER_MALE,
	GENDER_LAST		= GENDER_ONE_SEX
};

enum eZENNY_CHANGE_TYPE
{
	ZENNY_CHANGE_TYPE_ITEM_BUY	=	0,
	ZENNY_CHANGE_TYPE_ITEM_SELL,
	ZENNY_CHANGE_TYPE_PICK,
	ZENNY_CHANGE_TYPE_TRADE,
	ZENNY_CHANGE_TYPE_REPAIR,
	ZENNY_CHANGE_TYPE_REWARD,
	ZENNY_CHANGE_TYPE_SKILL,
	ZENNY_CHANGE_TYPE_PARTY_VICTIM_ADD,
	ZENNY_CHANGE_TYPE_PARTY_VICTIM_DEL,
	ZENNY_CHANGE_TYPE_PARTY_VICTIM_RETURN,
	ZENNY_CHANGE_TYPE_CHEAT,
	ZENNY_CHANGE_TYPE_BANK_BUY,
	ZENNY_CHANGE_TYPE_PARTY_PICK,
	ZENNY_CHANGE_TYPE_GUILD_CREATE,
	ZENNY_CHANGE_TYPE_DB_REWARD,
	ZENNY_CHANGE_TYPE_PRIVATESHOP_ITEM_BUY,// [7/20/2007]
	ZENNY_CHANGE_TYPE_MAIL_SEND,
	ZENNY_CHANGE_TYPE_MAIL_RECV,
	ZENNY_CHANGE_TYPE_RANKBATTLE,			// RankBattle ´ëÀü·á
	ZENNY_CHANGE_TYPE_PORTAL_ADD,

	ZENNY_CHANGE_TYPE_GUILD_FUNCTION_ADD,
	ZENNY_CHANGE_TYPE_GUILD_GIVE_ZENNY,		// ±æµå Æ÷ÀÎÆ®¸¦ ¿Ã¸®±âÀ§ÇÑ Á¦´Ï
	ZENNY_CHANGE_TYPE_GUILD_MARK_CHANGE,
	ZENNY_CHANGE_TYPE_GUILD_NAME_CHANGE,
	ZENNY_CHANGE_TYPE_RIDE_ON_BUS,
	ZENNY_CHANGE_TYPE_ITEM_IDENTIFY,
	ZENNY_CHANGE_TYPE_SCOUTER_ITEM_SELL,
	ZENNY_CHANGE_TYPE_PARTY_ITEM_INVEST,	// ÆÄÆ¼ÀÎº¥ ¾ÆÀÌÅÛ °æ¸Å
	ZENNY_CHANGE_TYPE_ITEM_MIX_MAKE,		// ¾ÆÀÌÅÛ ¸¸µå´Âµ¥ ¼Ò¸ð
	ZENNY_CHANGE_TYPE_ITEM_MIX_FARE,		// ¾ÆÀÌÅÛ ¸¸µé±â·Î È¹µæ
	ZENNY_CHANGE_TYPE_DOJO_CHANGE,
	ZENNY_CHANGE_TYPE_BANK,					// Ã¢°í ÀÔÃâ±Ý
	ZENNY_CHANGE_TYPE_GUILD_BANK,			// ±æµå Ã¢°í ÀÔÃâ±Ý
	ZENNY_CHANGE_TYPE_DOJO_SCRAMBLE_REQ,	// µµÀåÀïÅ»Àü½ÅÃ»±Ý
	ZENNY_CHANGE_TYPE_DOJO_ANTI_SCRAMBLE_ADD,	// µµÀåÀïÅ»Àü°ÅºÎ±Ý ¹Þ±â
	ZENNY_CHANGE_TYPE_DOJO_ANTI_SCRAMBLE_DEL,	// µµÀåÀïÅ»Àü°ÅºÎ±Ý º¸³»±â
	ZENNY_CHANGE_TYPE_ITEM_RECIPE_JOB_SET,  // Á¦Á¶±â¼úÀ» ¹è¿ì±â À§ÇØ ¼Ò¸ðµÊ

	ZENNY_CHANGE_TYPE_COUNT,
	ZENNY_CHANGE_TYPE_INVALID = 0xFF
};

enum ePC_CLASS
{
	PC_CLASS_HUMAN_FIGHTER,  //(¹«µµ°¡)->(°ÝÅõ°¡,°Ë¼ú°¡)
	PC_CLASS_HUMAN_MYSTIC,   //(±â°ø»ç)->(ÇÐ¼±»ç,±Í¼±»ç)
	PC_CLASS_HUMAN_ENGINEER, //(¿£Áö´Ï¾î)->(°Ç¸Å´Ï¾Æ,¸ÞÄ«¸Þ´Ï¾Æ)
	PC_CLASS_NAMEK_FIGHTER,  //(Àü»ç)->(¸¶°èÀü»ç,¸¶µµÀü»ç)
	PC_CLASS_NAMEK_MYSTIC,   //(¿ëÁ·)->(µ§µ§µµ»ç,Æ÷ÄÚµµ»ç)
	PC_CLASS_MIGHTY_MAJIN,   //(´ë¸¶ÀÎ)->(±×·£¸¶,¾óÆ¼¸¶)
	PC_CLASS_WONDER_MAJIN,   //(ÀÇ¸¶ÀÎ)->(ÇÃ¶óÁî¸¶,Ä«¸£¸¶)
	PC_CLASS_STREET_FIGHTER, //(°ÝÅõ°¡)
	PC_CLASS_SWORD_MASTER,   //(°Ë¼ú°¡)
	PC_CLASS_CRANE_ROSHI,    //(ÇÐ¼±»ç)
	PC_CLASS_TURTLE_ROSHI,   //(±Í¼±»ç)
	PC_CLASS_GUN_MANIA,      //(°Ç¸Å´Ï¾Æ)
	PC_CLASS_MECH_MANIA,     //(¸ÞÄ«¸Å´Ï¾Æ)
	PC_CLASS_DARK_WARRIOR,   //(¸¶°èÀü»ç)
	PC_CLASS_SHADOW_KNIGHT,  //(¸¶µµÀü»ç)
	PC_CLASS_DENDEN_HEALER,  //(µ§µ§µµ»ç)
	PC_CLASS_POCO_SUMMONER,  //(Æ÷ÄÚµµ»ç)
	PC_CLASS_ULTI_MA,        //(¾óÆ¼¸¶)
	PC_CLASS_GRAND_MA,       //(±×·£¸¶)
	PC_CLASS_PLAS_MA,        //(ÇÃ¶óÁî¸¶)
	PC_CLASS_KAR_MA,         //(Ä«¸£¸¶)

	PC_CLASS_COUNT,
	PC_CLASS_UNKNOWN				= 0xFF,
	
	PC_CLASS_1_FIRST = PC_CLASS_HUMAN_FIGHTER,
	PC_CLASS_1_LAST  = PC_CLASS_WONDER_MAJIN,
	PC_CLASS_2_FIRST = PC_CLASS_STREET_FIGHTER,
	PC_CLASS_2_LAST  = PC_CLASS_KAR_MA,

	PC_CLASS_FIRST = PC_CLASS_HUMAN_FIGHTER,
	PC_CLASS_LAST  = PC_CLASS_COUNT - 1
};

// Class °Ë»ç¿ë ºñÆ® ÇÃ·¡±×
enum ePC_CLASS_FLAG
{
	PC_CLASS_FLAG_HUMAN_FIGHTER = (0x01 << PC_CLASS_HUMAN_FIGHTER),								//(ë¬´ë„ê°€)->(ê²©íˆ¬ê°€,ê²€ìˆ ê°€)
	PC_CLASS_FLAG_HUMAN_MYSTIC = (0x01 << PC_CLASS_HUMAN_MYSTIC),									//(ê¸°ê³µì‚¬)->(í•™ì„ ì‚¬,ê·€ì„ ì‚¬)
	PC_CLASS_FLAG_HUMAN_ENGINEER = (0x01 << PC_CLASS_HUMAN_ENGINEER),								//(ì—”ì§€ë‹ˆì–´)->(ê±´ë§¤ë‹ˆì•„,ë©”ì¹´ë©”ë‹ˆì•„)
	PC_CLASS_FLAG_HUMAN_MIX = (0x01 << PC_CLASS_HUMAN_FIGHTER) | PC_CLASS_FLAG_HUMAN_MYSTIC | PC_CLASS_FLAG_HUMAN_ENGINEER,

	PC_CLASS_FLAG_NAMEK_FIGHTER = (0x01 << PC_CLASS_NAMEK_FIGHTER),								//(ì „ì‚¬)->(ë§ˆê³„ì „ì‚¬,ë§ˆë„ì „ì‚¬)
	PC_CLASS_FLAG_NAMEK_MYSTIC = (0x01 << PC_CLASS_NAMEK_MYSTIC),									//(ìš©ì¡±)->(ë´ë´ë„ì‚¬,í¬ì½”ë„ì‚¬)
	PC_CLASS_FLAG_NAMEK_MIX = (0x01 << PC_CLASS_NAMEK_FIGHTER) | PC_CLASS_FLAG_NAMEK_MYSTIC,

	PC_CLASS_FLAG_MIGHTY_MAJIN = (0x01 << PC_CLASS_MIGHTY_MAJIN),									//(ëŒ€ë§ˆì¸)->(ê·¸ëžœë§ˆ,ì–¼í‹°ë§ˆ)
	PC_CLASS_FLAG_WONDER_MAJIN = (0x01 << PC_CLASS_WONDER_MAJIN),									//(ì˜ë§ˆì¸)->(í”Œë¼ì¦ˆë§ˆ,ì¹´ë¥´ë§ˆ)
	PC_CLASS_FLAG_MAJIN_MIX = (0x01 << PC_CLASS_MIGHTY_MAJIN) | PC_CLASS_FLAG_WONDER_MAJIN,

	PC_CLASS_FLAG_MIX = (0x01 << PC_CLASS_HUMAN_FIGHTER) | PC_CLASS_FLAG_HUMAN_MYSTIC | PC_CLASS_FLAG_NAMEK_FIGHTER | PC_CLASS_FLAG_MIGHTY_MAJIN | PC_CLASS_FLAG_WONDER_MAJIN,
	PC_CLASS_FLAG_FULLMIX = (0x01 << PC_CLASS_HUMAN_FIGHTER) | PC_CLASS_FLAG_HUMAN_MYSTIC | PC_CLASS_FLAG_HUMAN_ENGINEER | PC_CLASS_FLAG_NAMEK_FIGHTER | PC_CLASS_FLAG_NAMEK_MYSTIC | PC_CLASS_FLAG_MIGHTY_MAJIN | PC_CLASS_FLAG_WONDER_MAJIN,

	PC_CLASS_FLAG_STREET_FIGHTER = (0x01 << PC_CLASS_STREET_FIGHTER) | PC_CLASS_HUMAN_FIGHTER,	//(ê²©íˆ¬ê°€)
	PC_CLASS_FLAG_SWORD_MASTER = (0x01 << PC_CLASS_SWORD_MASTER) | PC_CLASS_HUMAN_FIGHTER,	//(ê²€ìˆ ê°€)
	PC_CLASS_FLAG_CRANE_ROSHI = (0x01 << PC_CLASS_CRANE_ROSHI) | PC_CLASS_HUMAN_MYSTIC,	//(í•™ì„ ì‚¬)
	PC_CLASS_FLAG_TURTLE_ROSHI = (0x01 << PC_CLASS_TURTLE_ROSHI) | PC_CLASS_HUMAN_MYSTIC,	//(ê±°ë¶ì„ ì‚¬)
	PC_CLASS_FLAG_GUN_MANIA = (0x01 << PC_CLASS_GUN_MANIA) | PC_CLASS_HUMAN_ENGINEER,//(ê±´ë§¤ë‹ˆì•„)
	PC_CLASS_FLAG_MECH_MANIA = (0x01 << PC_CLASS_MECH_MANIA) | PC_CLASS_HUMAN_ENGINEER,//(ë©”ì¹´ë§¤ë‹ˆì•„)
	PC_CLASS_FLAG_DARK_WARRIOR = (0x01 << PC_CLASS_DARK_WARRIOR) | PC_CLASS_NAMEK_FIGHTER,	//(ë§ˆê³„ì „ì‚¬)
	PC_CLASS_FLAG_SHADOW_KNIGHT = (0x01 << PC_CLASS_SHADOW_KNIGHT) | PC_CLASS_NAMEK_FIGHTER,	//(ë§ˆë„ì „ì‚¬)
	PC_CLASS_FLAG_DENDEN_HEALER = (0x01 << PC_CLASS_DENDEN_HEALER) | PC_CLASS_NAMEK_MYSTIC,	//(ë´ë´ë„ì‚¬)
	PC_CLASS_FLAG_POCO_SUMMONER = (0x01 << PC_CLASS_POCO_SUMMONER) | PC_CLASS_NAMEK_MYSTIC,	//(í¬ì½”ë„ì‚¬)
	PC_CLASS_FLAG_GRAND_MA = (0x01 << PC_CLASS_GRAND_MA) | PC_CLASS_MIGHTY_MAJIN,	//(ê·¸ëžœë§ˆ)
	PC_CLASS_FLAG_ULTI_MA = (0x01 << PC_CLASS_ULTI_MA) | PC_CLASS_MIGHTY_MAJIN,	//(ì–¼í‹°ë§ˆ)
	PC_CLASS_FLAG_PLAS_MA = (0x01 << PC_CLASS_PLAS_MA) | PC_CLASS_WONDER_MAJIN,	//(í”Œë¼ì¦ˆë§ˆ)
	PC_CLASS_FLAG_KAR_MA = (0x01 << PC_CLASS_KAR_MA) | PC_CLASS_WONDER_MAJIN,	//(ì¹´ë¥´ë§ˆ)
};




// ½ºÆù Ä³¸¯ÅÍ ¿òÁ÷ÀÓ Å¸ÀÔ
enum eSPAWN_MOVE_TYPE
{
	SPAWN_MOVE_FIX, // °íÁ¤
	SPAWN_MOVE_WANDER, // ´Ü¼ø ¹èÈ¸
	SPAWN_MOVE_PATROL, // °æ·Î µû¶ó°¡±â ¹Ýº¹
	SPAWN_MOVE_FOLLOW, // Å¸°Ù µû¶ó°¡±â
	SPAWN_MOVE_PATH_ONCE, // °æ·Î µû¶ó°¡±â 1È¸

	SPAWN_MOVE_COUNT,

	SPAWN_MOVE_UNKNOWN = 0xFF,
	SPAWN_MOVE_FIRST = SPAWN_MOVE_FIX,
	SPAWN_MOVE_LAST = SPAWN_MOVE_PATH_ONCE
};


// ½ºÆù ±â´É ÇÃ·¡±×
enum eSPAWN_FUNC_FLAG
{
	SPAWN_FUNC_FLAG_RESPAWN = 0x01, // ¸®½ºÆù
	SPAWN_FUNC_FLAG_NO_SPAWN_WAIT = 0x02, // ½ºÆù ´ë±â ½Ã°£ ¾øÀ½
	SPAWN_FUNC_FLAG_INCORRECT_HEIGHT = 0x04, // Á¤È®ÇÑ ³ôÀÌ°ª º¸Á¤ ÇÊ¿ä
};


// ½ºÆù Á¦°Å Å¸ÀÔ
enum eSPAWN_REMOVE_TYPE
{
	SPAWN_REMOVE_TYPE_CLEAR, // ±×³É »èÁ¦
	SPAWN_REMOVE_TYPE_DESPAWN, // µð½ºÆù ¿¬Ãâ ÈÄ »èÁ¦
	SPAWN_REMOVE_TYPE_FAINT, // »ç¸Á ÈÄ »èÁ¦

	INVALID_SPAWN_REMOVE_TYPE = 0xFF
};


// ¸÷ µî±Þ
enum eMOB_GRADE
{
	MOB_GRADE_NORMAL,// (ÀÏ¹Ý)
	MOB_GRADE_SUPER, // (½´ÆÛ)
	MOB_GRADE_ULTRA, // (¿ïÆ®¶ó)
	MOB_GRADE_BOSS,  // (º¸¾²)
	MOB_GRADE_HERO,  // (È÷¾î·Î)

	MOB_GRADE_UNKNOWN	= 0xFF,

	MOB_GRADE_FIRST		= MOB_GRADE_NORMAL,
	MOB_GRADE_LAST		= MOB_GRADE_HERO
};


// ¸÷ Å¸ÀÔ
enum eMOB_TYPE
{
	MOB_TYPE_ANIMAL,
	MOB_TYPE_HUMAN_ANIMAL,
	MOB_TYPE_DINOSAUR,
	MOB_TYPE_ALIEN,
	MOB_TYPE_ANDROID,
	MOB_TYPE_ROBOT,
	MOB_TYPE_DRAGON,
	MOB_TYPE_DEVIL,
	MOB_TYPE_UNDEAD,
	MOB_TYPE_PLANT,
	MOB_TYPE_INSECT,
	MOB_TYPE_HUMAN,
	MOB_TYPE_NAMEC,
	MOB_TYPE_MAJIN,
	MOB_TYPE_BUILDING,

	MOB_TYPE_UNKNOWN	= 0xFF,

	MOB_TYPE_FIRST		= MOB_TYPE_ANIMAL,
	MOB_TYPE_LAST		= MOB_TYPE_INSECT
};

// Avatar Type
//
// Summon Pet°ú Item PetÀº Å¬¶óÀÌ¾ðÆ®¿¡¼­ Á¦¾îÇÏ±â ¶§¹®¿¡ °°Àº avatar·Î °£ÁÖÇÑ´Ù.
// Summon Pet and Item Pet are regarded as 'avatar' because they are controlled by Client.
// by YOSHIKI(2006-12-26)
enum eDBO_AVATAR_TYPE
{
	DBO_AVATAR_TYPE_AVATAR = 0,
	DBO_AVATAR_TYPE_SUMMON_PET_1,
//	DBO_AVATAR_TYPE_SUMMON_PET_2,
	DBO_AVATAR_TYPE_ITEM_PET_1,
//	DBO_AVATAR_TYPE_ITEM_PET_2,

	DBO_AVATAR_TYPE_COUNT,

	DBO_AVATAR_TYPE_INVALID = 0xFF,

	DBO_AVATAR_TYPE_PET_FIRST = DBO_AVATAR_TYPE_SUMMON_PET_1,
//	DBO_AVATAR_TYPE_PET_LAST = DBO_AVATAR_TYPE_ITEM_PET_2,
	DBO_AVATAR_TYPE_PET_LAST = DBO_AVATAR_TYPE_ITEM_PET_1,

	DBO_AVATAR_TYPE_SUMMON_PET_FIRST = DBO_AVATAR_TYPE_SUMMON_PET_1,
//	DBO_AVATAR_TYPE_SUMMON_PET_LAST = DBO_AVATAR_TYPE_SUMMON_PET_2,
	DBO_AVATAR_TYPE_SUMMON_PET_LAST = DBO_AVATAR_TYPE_SUMMON_PET_1,

	DBO_AVATAR_TYPE_ITEM_PET_FIRST = DBO_AVATAR_TYPE_ITEM_PET_1,
//	DBO_AVATAR_TYPE_ITEM_PET_LAST = DBO_AVATAR_TYPE_ITEM_PET_2,
	DBO_AVATAR_TYPE_ITEM_PET_LAST = DBO_AVATAR_TYPE_ITEM_PET_1,

	DBO_AVATAR_TYPE_COUNT_SUMMON_PET = DBO_AVATAR_TYPE_SUMMON_PET_LAST - DBO_AVATAR_TYPE_SUMMON_PET_FIRST + 1,
	DBO_AVATAR_TYPE_COUNT_ITEM_PET = DBO_AVATAR_TYPE_ITEM_PET_LAST - DBO_AVATAR_TYPE_ITEM_PET_FIRST + 1,
};


// AI Function
// ¾Æ·¡ ºñÆ®ÇÃ·¡±×¸¦ ¼öÁ¤ÇÔ [3/31/2008]
//enum eAI_FUNCTION
//{
//	AI_FUNC_NORMAL = 0,
//	AI_FUNC_SECRECY,
//	AI_FUNC_STAGE,
//	AI_FUNC_STARRING,
//
//	AI_FUNC_LEAVING = 5,
//	AI_FUNC_END,
//	AI_FUNC_COMPLETION,
//
//	AI_FUNC_DEFENSIVE = 9,
//	AI_FUNC_OFFENSIVE,	
//
//	AI_FUNC_DESPERATION = 12,
//	AI_FUNC_FLEE,
//
//	AI_FUNC_FOCUS = 17,
//	AI_FUNC_REVENGE,
//	AI_FUNC_MEAN,
//	AI_FUNC_BRAVE,
//
//	AI_FUNC_APATHY = 24,
//	AI_FUNC_HELP,
//	AI_FUNC_CARE,
//	AI_FUNC_HEALING,
//
//	AI_FUNC_SMART_OFFENSIVE,// ¶È¶ÈÇÑ ¼±°ø¸÷ [3/10/2008]
//	AI_FUNC_ALLIANCE_HELP, // Alliance Help  [3/11/2008]
//	AI_FUNC_RETREAT, // Åð°¢ [3/12/2008]
//	AI_FUNC_TIMID, //°ÌÀïÀÌ [3/12/2008]
//
//	AI_FUNC_COUNT,
//
//	AI_FUNC_FIRST = AI_FUNC_NORMAL,
//
//	AI_FUNC_LAST = AI_FUNC_HEALING,
//};

enum eAI_FUNCTION
{
	//»èÁ¦ ¸®½ºÆ®
	//AI_FUNC_NORMAL = 0,
	//AI_FUNC_SECRECY,
	//AI_FUNC_STAGE,
	//AI_FUNC_STARRING,

	//AI_FUNC_LEAVING = 5,
	//AI_FUNC_END,
	//AI_FUNC_COMPLETION,

	//AI_FUNC_APATHY = 24,
	//AI_FUNC_HELP,
	//AI_FUNC_CARE,
	//AI_FUNC_HEALING,

	AI_FUNC_DEFENSIVE = 0,			//ÈÄ°ø
	AI_FUNC_TIMID,					//°ÌÀïÀÌ
	AI_FUNC_OFFENSIVE,				//¼±°ø
	AI_FUNC_SMART_OFFENSIVE,		//¶È¶ÈÇÑ ¼±°ø¸÷
	AI_FUNC_ONLYSKILL,				//½ºÅ³¸¸ »ç¿ë

	AI_FUNC_DESPERATION = 5,		//ÇÊ»ç
	AI_FUNC_FLEE,					//µµ¸Á
	AI_FUNC_RETREAT,				//Åð°¢

	AI_FUNC_REVENGE = 9,			//º¹¼ö
	AI_FUNC_FOCUS,					//ÁýÁß
	AI_FUNC_MEAN,					//ºñ¿­
	AI_FUNC_BRAVE,					//¿ë°¨

	AI_FUNC_ALLIANCE_HELP = 15, // Alliance Help  [3/11/2008]
	AI_FUNC_DEFEND,// °æºñ [11/10/2008]

	AI_FUNC_NOT_CHASE = 20, // ÃßÀû¾ÈÇØ [11/10/2008]
	AI_FUNC_NOT_MOVE, // ÀÌµ¿¾ÈÇØ [11/10/2008]

	AI_FUNC_COUNT,

	AI_FUNC_FIRST = AI_FUNC_DEFENSIVE,
	AI_FUNC_LAST = AI_FUNC_ALLIANCE_HELP,
};


// Ai Function Flag
// ¾Æ·¡ ÄÚµå¸¦ ¼öÁ¤ [3/31/2008]
//enum eAI_FUNCTION_FLAG
//{
//	AI_FUNC_FLAG_NORMAL				= 0x01 << AI_FUNC_NORMAL,
//	AI_FUNC_FLAG_SECRECY			= 0x01 << AI_FUNC_SECRECY,
//	AI_FUNC_FLAG_STAGE				= 0x01 << AI_FUNC_STAGE,
//	AI_FUNC_FLAG_STARRING			= 0x01 << AI_FUNC_STARRING,
//
//	AI_FUNC_FLAG_LEAVING				= 0x01 << AI_FUNC_LEAVING,
//	AI_FUNC_FLAG_END					= 0x01 << AI_FUNC_END,
//	AI_FUNC_FLAG_COMPLETION			= 0x01 << AI_FUNC_COMPLETION,
//
//	AI_FUNC_FLAG_DEFENSIVE			= 0x01 << AI_FUNC_DEFENSIVE,
//	AI_FUNC_FLAG_OFFENSIVE			= 0x01 << AI_FUNC_OFFENSIVE,
//	
//	AI_FUNC_FLAG_DESPERATION		= 0x01 << AI_FUNC_DESPERATION,
//	AI_FUNC_FLAG_FLEE				= 0x01 << AI_FUNC_FLEE,
//
//	AI_FUNC_FLAG_FOCUS				= 0x01 << AI_FUNC_FOCUS,
//	AI_FUNC_FLAG_REVENGE			= 0x01 << AI_FUNC_REVENGE,
//	AI_FUNC_FLAG_MEAN				= 0x01 << AI_FUNC_MEAN,
//	AI_FUNC_FLAG_BRAVE				= 0x01 << AI_FUNC_BRAVE,
//
//	AI_FUNC_FLAG_APATHY				= 0x01 << AI_FUNC_APATHY,
//	AI_FUNC_FLAG_HELP				= 0x01 << AI_FUNC_HELP,
//	AI_FUNC_FLAG_CARE				= 0x01 << AI_FUNC_CARE,
//	AI_FUNC_FLAG_HEALING			= 0x01 << AI_FUNC_HEALING,
//
//	AI_FUNC_FLAG_SMART_OFFENSIVE	= 0x01 << AI_FUNC_SMART_OFFENSIVE, // [3/11/2008]
//	AI_FUNC_FLAG_ALLIANCE_HELP		= 0x01 << AI_FUNC_ALLIANCE_HELP,// [3/11/2008]
//	AI_FUNC_FLAG_RETREAT			= 0x01 << AI_FUNC_RETREAT,// [3/12/2008]
//	AI_FUNC_FLAG_TIMID				= 0x01 << AI_FUNC_TIMID,// [3/12/2008]
//
//};

enum eAI_FUNCTION_FLAG
{
	AI_FUNC_FLAG_DEFENSIVE			= 0x01 << AI_FUNC_DEFENSIVE,
	AI_FUNC_FLAG_TIMID				= 0x01 << AI_FUNC_TIMID,// [3/12/2008]
	AI_FUNC_FLAG_OFFENSIVE			= 0x01 << AI_FUNC_OFFENSIVE,
	AI_FUNC_FLAG_SMART_OFFENSIVE	= 0x01 << AI_FUNC_SMART_OFFENSIVE, // [3/11/2008]
	AI_FUNC_FLAG_ONLYSKILL			= 0x01 << AI_FUNC_ONLYSKILL, // [11/10/2008]

	AI_FUNC_FLAG_DESPERATION		= 0x01 << AI_FUNC_DESPERATION,
	AI_FUNC_FLAG_FLEE				= 0x01 << AI_FUNC_FLEE,
	AI_FUNC_FLAG_RETREAT			= 0x01 << AI_FUNC_RETREAT,// [3/12/2008]

	AI_FUNC_FLAG_REVENGE			= 0x01 << AI_FUNC_REVENGE,
	AI_FUNC_FLAG_FOCUS				= 0x01 << AI_FUNC_FOCUS,
	AI_FUNC_FLAG_MEAN				= 0x01 << AI_FUNC_MEAN,
	AI_FUNC_FLAG_BRAVE				= 0x01 << AI_FUNC_BRAVE,

	AI_FUNC_FLAG_ALLIANCE_HELP		= 0x01 << AI_FUNC_ALLIANCE_HELP,// [3/11/2008]
	AI_FUNC_FLAG_DEFEND				= 0x01 << AI_FUNC_DEFEND,// °æºñ [3/12/2008]

	AI_FUNC_FLAG_NOT_CHASE			= 0x01 << AI_FUNC_NOT_CHASE, // [11/10/2008]
	AI_FUNC_FLAG_NOT_MOVE			= 0x01 << AI_FUNC_NOT_MOVE, // [11/10/2008]
};


// NPC JOB
enum eNPC_JOB
{
	NPC_JOB_WEAPON_MERCHANT,				// ¹«±â»óÀÎ
	NPC_JOB_ARMOR_MERCHANT,					// ÀÇº¹»óÀÎ
	NPC_JOB_GOODS_MERCHANT,					// ÀâÈ­»óÀÎ
	NPC_JOB_SCOUTER_MERCHANT,				// ½ºÄ«¿ìÅÍ»óÀÎ
	NPC_JOB_GUARD,							// °æºñ
	NPC_JOB_SKILL_TRAINER_HFI,				// ¹«µµ°¡ ±³°ü
	NPC_JOB_SKILL_TRAINER_HMY,				// ±â°ø»ç ±³°ü
	NPC_JOB_SKILL_TRAINER_HEN,				// ¿£Áö´Ï¾î ±³°ü
	NPC_JOB_SKILL_TRAINER_NFI,				// Àü»ç ±³°ü
	NPC_JOB_SKILL_TRAINER_NMY,				// ¿ëÁ· ±³°ü
	NPC_JOB_SKILL_TRAINER_MMI,				// ´ë¸¶ÀÎ ±³°ü
	NPC_JOB_SKILL_TRAINER_MWO,				// ÀÇ¸¶ÀÎ ±³°ü
	NPC_JOB_BANKER,							// Ã¢°íÁö±â
	NPC_JOB_TALKER,							// ÀÌ¾ß±â²Û
	NPC_JOB_GUILD_MANAGER,					// ±æµå¸Å´ÏÀú
	NPC_JOB_SUMMON_PET,						// ¼ÒÈ¯¼ö
	NPC_JOB_DOGI_MERCHANT,					// µµº¹ »óÀÎ
	NPC_JOB_SPECIAL_WEAPON_MERCHANT,		// °í±Þ ¹«±â »óÀÎ
	NPC_JOB_SPECIAL_ARMOR_MERCHANT,			// °í±Þ ÀÇº¹ »óÀÎ
	NPC_JOB_SPECIAL_GOODS_MERCHANT,			// °í±Þ ÀâÈ­ »óÀÎ
	NPC_JOB_SPECIAL_FOODS_MERCHANT,			// °í±Þ ½Ä·áÇ° »óÀÎ
	NPC_JOB_SPECIAL_SCOUTER_MERCHANT,		// °í±Þ ½ºÄ«¿ìÅÍ »óÀÎ
	NPC_JOB_GRAND_SKILL_TRAINER_HFI,		// ¹«µµ°¡ ±×·£µå ½ºÅ³¸¶½ºÅÍ
	NPC_JOB_GRAND_SKILL_TRAINER_HMY,		// ±â°ø»ç ±×·£µå ½ºÅ³¸¶½ºÅÍ
	NPC_JOB_GRAND_SKILL_TRAINER_HEN,		// ¿£Áö´Ï¾î ±×·£µå ½ºÅ³¸¶½ºÅÍ
	NPC_JOB_GRAND_SKILL_TRAINER_NFI,		// Àü»ç ±×·£µå ½ºÅ³¸¶½ºÅÍ
	NPC_JOB_GRAND_SKILL_TRAINER_NMY,		// ¿ëÁ· ±×·£µå ½ºÅ³¸¶½ºÅÍ
	NPC_JOB_GRAND_SKILL_TRAINER_MMI,		// ´ë¸¶ÀÎ ±×·£µå ½ºÅ³¸¶½ºÅÍ
	NPC_JOB_GRAND_SKILL_TRAINER_MWO,		// ÀÇ¸¶ÀÎ ±×·£µå ½ºÅ³¸¶½ºÅÍ
	NPC_JOB_SUB_WEAPON_MERCHANT,			// º¸Á¶ ¹«±â »óÀÎ
	NPC_JOB_GATE_KEEPER,					// ¹®Áö±â
	NPC_JOB_VENDING_MACHINE,				// ÀÚÆÇ±â
	NPC_JOB_TIMEMACHINE_MERCHANT,			// Å¸ÀÓ¸Ó½ÅÁøÀÔ NPC
	NPC_JOB_PORTAL_MAN,						// ¼ø°£ ÀÌµ¿ ¼­ºñ½º¸Ç			
	NPC_JOB_BUS,							// ¹ö½º
	NPC_JOB_RECEPTION,						// ÃµÇÏÁ¦ÀÏ ¹«µµÈ¸ Á¢¼öÀÎ
	NPC_JOB_BUDOHSI_MERCHANT,				// ¹«µµ»ç »óÀÎ
	NPC_JOB_REFEREE,						// ½ÉÆÇ
	NPC_JOB_GAMBLE_MERCHANT,				// »Ì±â »óÀÎ
	NPC_JOB_CHAMPION_MERCHANT,				// Ã¨ÇÇ¾ð »óÀÎ
	NPC_JOB_DOJO_MANAGER,					// µµÀå °ü¸®ÀÎ
	NPC_JOB_DOJO_MERCHANT,					// µµÀå »óÀÎ
	NPC_JOB_DOJO_SEAL,						// µµÀå ÀÎÀå
	NPC_JOB_DOJO_BANKER,					// µµÀå Ã¢°í
	NPC_JOB_MIX_MASTER,						// ¹Í½º ¸¶½ºÅÍ

	NPC_JOB_COUNT,
	NPC_JOB_UNKNOWN	= 0xFF,

	NPC_JOB_FIRST = NPC_JOB_WEAPON_MERCHANT,
	NPC_JOB_LAST = NPC_JOB_COUNT - 1
};


// NPC Function Flag
enum eNPC_FUNCTION
{
	NPC_FUNC_MERCHANT,			// »óÀÎ±â´É
	NPC_FUNC_GUARD,				// °æºñ±â´É
	NPC_FUNC_SKILL_TRAINER,		// ±³°ü±â´É
	NPC_FUNC_BANKER,			// ÀºÇà¿ø±â´É
	NPC_FUNC_TALKER,			// ÀÌ¾ß±â±â´É
	NPC_FUNC_QUEST_GRANTER,		// Äù½ºÆ® ºÎ¿©
	NPC_FUNC_GUILD_MANAGER,		// ±æµå¸Å´ÏÀú
	NPC_FUNC_SUMMON_PET,		// ¼ÒÈ¯¼ö
	NPC_FUNC_GATE_KEEPER,		// ¹®Áö±â
	NPC_FUNC_TIME_QUEST,		// Å¸ÀÓ¸Ó½Å Äù½ºÆ® ±â´É
	NPC_FUNC_PORTAL,			// Teleport Portal
	NPC_FUNC_SCAN_BY_MOB,		// ¸÷¿¡°Ô ¼±°øÀ» ´çÇÒ¼ö ÀÖÀ½
	NPC_FUNC_BUS,				// ¹ö½º
	NPC_FUNC_RECEPTION,			// ÃµÇÏÁ¦ÀÏ ¹«µµÈ¸ Á¢¼öÀÎ
	NPC_FUNC_BUDOHSI_MERCHANT,	// ¹«µµ»ç »óÀÎ
	NPC_FUNC_REFEREE,			// ½ÉÆÇ
	NPC_FUNC_BUILDING,			// ºôµùÇü
	NPC_FUNC_FACING,			// ´ë¸é : ÆÐÆ®·Ñ BOTÀ» Å¬¸¯ÇÏ¸é ¸ØÃß°ÔÇÏ´Â ±â´É
	NPC_FUNC_TURN_OFF,			// °ø°ÝÀ» ´çÇØµµ ±× ¹æÇâÀ» ¾Èº»´Ù
	NPC_FUNC_DISCLOSE_LP,		// LPÇ¥½Ã¿©ºÎ
	NPC_FUNC_GAMBLE_MERCHANT,	// »Ì±â »óÀÎ
	NPC_FUNC_MOVING_NPC,		// ¿òÁ÷ÀÌ´Â NPC (ÆÐ¾² µ¥ÀÌÅÍ)
	NPC_FUNC_SPAWN_NPC,			//Áß°£ ½ºÆù NPC
	NPC_FUNC_DOJO_MANAGER,		// µµÀå °ü¸®ÀÎ
	NPC_FUNC_DOJO_MERCHANT,		// µµÀå »óÀÎ
	NPC_FUNC_DOJO_SEAL,			// µµÀå ÀÎÀå
	NPC_FUNC_DOJO_BANKER,		// µµÀå Ã¢°í

	NPC_FUNC_COUNT,
	NPC_FUNC_FIRST = NPC_FUNC_MERCHANT,
	NPC_FUNC_LAST = NPC_FUNC_COUNT - 1,
};


// NPC Function Flag
enum eNPC_FUNCTION_FLAG
{
	NPC_FUNC_FLAG_MERCHANT			= MAKE_BIT_FLAG( NPC_FUNC_MERCHANT ),
	NPC_FUNC_FLAG_GUARD				= MAKE_BIT_FLAG( NPC_FUNC_GUARD ),			
	NPC_FUNC_FLAG_SKILL_TRAINER		= MAKE_BIT_FLAG( NPC_FUNC_SKILL_TRAINER ),	
	NPC_FUNC_FLAG_BANKER			= MAKE_BIT_FLAG( NPC_FUNC_BANKER ),			
	NPC_FUNC_FLAG_TALKER			= MAKE_BIT_FLAG( NPC_FUNC_TALKER ),			
	NPC_FUNC_FLAG_QUEST_GRANTER		= MAKE_BIT_FLAG( NPC_FUNC_QUEST_GRANTER ),	
	NPC_FUNC_FLAG_GUILD_MANAGER		= MAKE_BIT_FLAG( NPC_FUNC_GUILD_MANAGER ),
	NPC_FUNC_FLAG_SUMMON_PET		= MAKE_BIT_FLAG( NPC_FUNC_SUMMON_PET ),
	NPC_FUNC_FLAG_GATE_KEEPER		= MAKE_BIT_FLAG( NPC_FUNC_GATE_KEEPER ),
	NPC_FUNC_FLAG_TIME_QUEST		= MAKE_BIT_FLAG( NPC_FUNC_TIME_QUEST ),
	NPC_FUNC_FLAG_PORTAL			= MAKE_BIT_FLAG( NPC_FUNC_PORTAL ),
	NPC_FUNC_FLAG_SCAN_BY_MOB		= MAKE_BIT_FLAG( NPC_FUNC_SCAN_BY_MOB ),
	NPC_FUNC_FLAG_BUS				= MAKE_BIT_FLAG( NPC_FUNC_BUS ),
	NPC_FUNC_FLAG_RECEPTION			= MAKE_BIT_FLAG( NPC_FUNC_RECEPTION ),
	NPC_FUNC_FLAG_BUDOHSI_MERCHANT	= MAKE_BIT_FLAG( NPC_FUNC_BUDOHSI_MERCHANT ),
	NPC_FUNC_FLAG_REFEREE			= MAKE_BIT_FLAG( NPC_FUNC_REFEREE ),
	NPC_FUNC_FLAG_BUILDING			= MAKE_BIT_FLAG( NPC_FUNC_BUILDING ),
	NPC_FUNC_FLAG_FACING			= MAKE_BIT_FLAG( NPC_FUNC_FACING ),	// ¼öÁ¤ ( NPC_FUNC_FLAG_FACING = NPC_FUNC_FLAG_MERCHANT | NPC_FUNC_FLAG_QUEST_GRANTER, // ÀÌµ¿Áß¿¡ ¸Þ´º¸¦ ¶ç¿ì°Ô µÇ´Â NPC ¸ðÀ½ ) [5/19/2008]	
																		// ÀÌ·¸°ÔÇÏ¸é ¹®Á¦µÇ´Â °ÍÀÌ ÇÏ³ª ÀÖ´Âµ¥, °°Àº NPC¸¦ ´Ù¸¥ °÷¿¡¼­ ½èÀ» ¶§ ±×°÷¿¡¼­´Â ¸»À» °É¸é ¸ØÃßÁö ¸»¾Æ¾ß µÉ¶§¿¡´Â NPC¸¦ »õ·Î ¸¸µé¾î¾ß ÇÑ´Ù
	NPC_FUNC_FLAG_TURN_OFF			= MAKE_BIT_FLAG( NPC_FUNC_TURN_OFF ), // [6/2/2008]
	NPC_FUNC_FLAG_DISCLOSE_LP		= MAKE_BIT_FLAG( NPC_FUNC_DISCLOSE_LP ), // [8/21/2008 Peessi]
	NPC_FUNC_FLAG_GAMBLE_MERCHANT	= MAKE_BIT_FLAG( NPC_FUNC_GAMBLE_MERCHANT ),// [7/21/2008]
	NPC_FUNC_FLAG_MOVING_NPC		= MAKE_BIT_FLAG( NPC_FUNC_MOVING_NPC ), // [8/27/2008]
	NPC_FUNC_FLAG_SPAWN_NPC			= MAKE_BIT_FLAG( NPC_FUNC_SPAWN_NPC ),
	NPC_FUNC_FLAG_DOJO_MANAGER		= MAKE_BIT_FLAG( NPC_FUNC_DOJO_MANAGER ),
	NPC_FUNC_FLAG_DOJO_MERCHANT		= MAKE_BIT_FLAG( NPC_FUNC_DOJO_MERCHANT ),
	NPC_FUNC_FLAG_DOJO_SEAL		    = MAKE_BIT_FLAG( NPC_FUNC_DOJO_SEAL ),
	NPC_FUNC_FLAG_DOJO_BANKER		= MAKE_BIT_FLAG( NPC_FUNC_DOJO_BANKER ),


};

// MERCHANT SELL TYPE
enum eMERCHANT_SELL_TYPE
{
	MERCHANT_SELL_TYPE_ITEM,
	MERCHANT_SELL_TYPE_SKILL,
	MERCHANT_SELL_TYPE_HTB_SKILL,
	MERCHANT_SELL_TYPE_BANK,
	MERCHANT_SELL_TYPE_TIMEMACHINE,
	MERCHANT_SELL_TYPE_BUDOKAI,
	MERCHANT_SELL_TYPE_GAMBLE,
	MERCHANT_SELL_TYPE_NETPY,

	MERCHANT_SELL_TYPE_COUNT,
	MERCHANT_SELL_TYPE_FIRST = MERCHANT_SELL_TYPE_ITEM,
	MERCHANT_SELL_TYPE_LAST  = MERCHANT_SELL_TYPE_NETPY,
};

// QuickSlotType Define
enum eQUICK_SLOT_TYPE
{
	QUICK_SLOT_TYPE_ITEM,
	QUICK_SLOT_TYPE_SKILL,
	QUICK_SLOT_TYPE_HTB_SKILL,
	QUICK_SLOT_TYPE_SOCIALACTION,

	QUICK_SLOT_TYPE_COUNT,
	QUICK_SLOT_TYPE_FIRST = QUICK_SLOT_TYPE_ITEM,
	QUICK_SLOT_TYPE_LAST  = QUICK_SLOT_TYPE_SOCIALACTION,
};


enum eMARKING_TYPE
{
	MARKING_TYPE_BUDOKAI_WINNER01 = 1,
	MARKING_TYPE_BUDOKAI_WINNER02,
	MARKING_TYPE_BUDOKAI_WINNER03,

	MARKING_TYPE_BUDOKAI_JUNIOR_WINNER01 = MARKING_TYPE_BUDOKAI_WINNER01,
	MARKING_TYPE_BUDOKAI_JUNIOR_WINNER02 = MARKING_TYPE_BUDOKAI_WINNER02,
	MARKING_TYPE_BUDOKAI_JUNIOR_WINNER03 = MARKING_TYPE_BUDOKAI_WINNER03,

	INVALID_MARKING_TYPE = INVALID_BYTE,
};

enum eMARKING_CONTENTS_TYPE
{
	MARKING_CONTENTS_TYPE_BUDOKAI,		// ÃµÇÏÁ¦ÀÏ¹«µµÈ¸¿¡¼­ È£ÃâÇÔ
	MARKING_CONTENTS_TYPE_COMMUNITY,	// Ä¿¹Â´ÏÆ¼ ¼­¹ö·Î ºÎÅÍ broadcast ¿äÃ»ÀÌ ¿È

	INVALID_MARKING_CONTENTS_TYPE = 0xff
};



//-----------------------------------------------------------------------------------
// Ä³¸¯ÅÍ °ü·Ã »ó¼ö Á¤ÀÇ : [4/25/2006 zeroera] : ¼öÁ¤ÇÊ¿ä : lua·Î ¿Å±æ °Í
//-----------------------------------------------------------------------------------
const DWORD			NTL_CHAR_RP_REGEN_WAIT_TIME					= 15 * 1000; // °æ°ú ÈÄ RP °¨¼Ò ½ÃÀÛ (15)

const DWORD			NTL_CHAR_RP_BALL_UPDATE_INTERVAL			= 30 * 1000; // °æ°ú ÈÄ RP ±¸½½ °¨¼Ò ½ÃÀÛ (30)

const BYTE			NTL_CHAR_RP_BALL_MAX						= 7; // RP ±¸½½ÀÇ ÃÖ´ëÄ¡.

const BYTE			NTL_CHAR_RP_BALL_CHANGE_VALUE				= 1;

const int			NTL_CHAR_RP_BALL_INCREASE_LEVEL				= 10; // RP ball increases every THIS level value

const int			DBO_CHAR_FACE_SHAPE_COUNT			= 10;

const int			DBO_CHAR_HAIR_SHAPE_COUNT			= 10;

const int			DBO_CHAR_HAIR_COLOR_COUNT			= 20;//10

const int			DBO_CHAR_SKIN_COLOR_COUNT			= 10;//5

//const int			NTL_CHAR_MAX_LEVEL					= 100;	// Ä³¸¯ÅÍ ÃÖ´ë ·¹º§

const int			NTL_CHAR_CONVERT1_NEED_LEVEL        = 30;	// 1Â÷ÀüÁ÷¿¡ ÇÊ¿ä ·¹º§

const int           NTL_CHAR_QUICK_SLOT_MAX_COUNT	    = 48;   // 12 * 4 Ä­

const int           NTL_GM_USE_LEVEL_NONE				= 0; 

const int           NTL_GM_USE_LEVEL1					= 1;   

const int           NTL_GM_USE_LEVEL2					= 2;   

const DWORD			DBO_CHAR_REPUTATION_DRAGONBALL = 100; // °³ÀÎ µå·¡°ïº¼ ¼öÁý ¸í¼ºÄ¡

extern const char*	DBO_PURE_MAJIN_MODEL_RESOURCE_NAME;

const float			DBO_GREAT_NAMEK_ATTACK_RANGE			= 4.0f;

const DWORD			DBO_NPC_MAX_PARTY_NUMBER			= 100000;

const DWORD			DBO_MAX_PLAY_TIME_TERM				= 300000;	// ½Ç½Ã°£ À§Ä¡ ÀúÀå ÁÖ±â ¹× ÇÑ¹ø¿¡ ÀúÀåÇÏ´Â play time ÃÖ´ë ½Ã°£


const DWORD			NTL_CHAR_MAX_SAVE_ZENNY				= 1000000000;

const DWORD			NTL_CHAR_MAX_BANK_SAVE_ZENNY		= 2000000000;

const int			NTL_MAX_NEWBIE_QUICKSLOT_COUNT		= 5;  // »ý¼º½Ã ºÎ¿©°¡´É Äü½½·Ô

const DWORD			NTL_DELETE_CHAR_MAX_WAIT_TICK		= 5 * 60 * 1000; //»èÁ¦ ´ë±â ½Ã°£

const DWORD			NTL_DELETE_CHAR_CHECK_TICK			= 1 * 1000; //»èÁ¦ ´ë±â Ã¼Å© ½Ã°£

//-----------------------------------------------------------------------------------
const BYTE			GMT_MAX_EFFECT_LIST_SIZE			= 5;		// GMT Àû¿ë È¿°úÀÇ ÃÖ´ë °¹¼ö

const BYTE			GMT_MAX_TIME_SLOT_SIZE				= 3;		// GMT È¿°úÀÇ ½Ã°£ ¼³Á¤ °¹¼ö


#pragma pack(1)


// NewbieQuickData
struct sNEWBIE_QUICKSLOT_DATA
{
	TBLIDX			tbilidx; 
	BYTE			byType;	
	BYTE			byQuickSlot; 
};

struct sDELETE_WAIT_CHARACTER
{
	ACCOUNTID		accountId;
	CHARACTERID		charId;
	DWORD			dwPastTick;
};

struct sDELETE_WAIT_CHARACTER_INFO
{
	CHARACTERID		charId;
	DWORD			dwPastTick;// °æ°ú Æ½
};

struct sMARKING
{
	BYTE byCode;			// eMARKING_TYPE

public:
	sMARKING()
		: byCode( INVALID_MARKING_TYPE )
	{
	}
};//end of sMARKING
	
// Ä³¸¯ÅÍ »ý±è»õ
struct sPC_SHAPE
{
	BYTE			byFace;
	BYTE			byHair;
	BYTE			byHairColor;
	BYTE			bySkinColor;
	FLOAT			fSize;
};

struct sASPECTSTATE_BASE
{
	BYTE							byAspectStateId;
};

union sASPECTSTATE_DETAIL
{
	sASPECTSTATE_SUPER_SAIYAN		sSuperSaiyan;
	sASPECTSTATE_PURE_MAJIN			sPureMajin;
	sASPECTSTATE_GREAT_NAMEK		sGreatNamek;
	sASPECTSTATE_KAIOKEN			sKaioken;
	sASPECTSTATE_SPINNING_ATTACK	sSpinningAttack;
	sASPECTSTATE_VEHICLE			sVehicle;
	sASPECTSTATE_SUPER_SAIYAN_BLUE		sSuperSaiyanBlue;
};

struct sASPECTSTATE
{
	sASPECTSTATE_BASE				sAspectStateBase;
	sASPECTSTATE_DETAIL				sAspectStateDetail;
};

// Ä³¸¯ÅÍ »óÅÂ
struct sCHARSTATE_BASE
{
	BYTE			byStateID;
	DWORD			dwStateTime;
	DWORD			dwConditionFlag;
	sASPECTSTATE	aspectState;
	bool			bFightMode:1;

	sVECTOR3		vCurLoc;
	sVECTOR3		vCurDir;
};


// »óÅÂ¿¡ µû¸¥ ±¸Á¶Ã¼
union sCHARSTATE_DETAIL
{ 
	sCHARSTATE_SPAWNING				sCharStateSpawning;
	sCHARSTATE_DESPAWNING			sCharStateDespawning;
	sCHARSTATE_STANDING				sCharStateStanding;
	sCHARSTATE_SITTING				sCharStateSitting;
	sCHARSTATE_FAINTING				sCharStateFainting;
	sCHARSTATE_CAMPING				sCharStateCamping;
	sCHARSTATE_LEAVING				sCharStateLeaving;

	sCHARSTATE_MOVING				sCharStateMoving;
	sCHARSTATE_DESTMOVE				sCharStateDestMove;
	sCHARSTATE_FOLLOWING			sCharStateFollwing;
	sCHARSTATE_FALLING				sCharStateFalling;
	sCHARSTATE_DASH_PASSIVE			sCharStateDashPassive;
	sCHARSTATE_TELEPORTING			sCharStateTeleporting;
	sCHARSTATE_SLIDING				sCharStateSliding;
	sCHARSTATE_KNOCKDOWN			sCharStateKnockdown;

	sCHARSTATE_FOCUSING				sCharStateFocusing;
	sCHARSTATE_CASTING				sCharStateCasting;
	sCHARSTATE_SKILL_AFFECTING		sCharStateSkillAffecting;
	sCHARSTATE_KEEPING_EFFECT		sCharStateKeepingEffect;
	sCHARSTATE_CASTING_ITEM			sCharStateCastingItem;

	sCHARSTATE_STUNNED				sCharStateStunned;
	sCHARSTATE_SLEEPING				sCharStateSleeping;
	sCHARSTATE_PARALYZED			sCharStateParalyzed;

	sCHARSTATE_HTB					sCharStateHTB;
	sCHARSTATE_SANDBAG				sCharStateSandBag;
	sCHARSTATE_CHARGING				sCharStateCharging;

	sCHARSTATE_PRIVATESHOP			sCharStatePrivateShop;//  [7/16/2007]
	sCHARSTATE_DIRECT_PLAY			sCharStateDirectPlay;
	sCHARSTATE_OPERATING			sCharStateOperating;
	sCHARSTATE_RIDEON				sCharStateRideOn;
	sCHARSTATE_TURNING				sCharStateTurning;
};


// Ä³¸¯ÅÍ »óÅÂ ±¸Á¶Ã¼
struct sCHARSTATE
{
	sCHARSTATE_BASE				sCharStateBase;
	sCHARSTATE_DETAIL			sCharStateDetail;
};

//-----------------------------------------------------------------------------------
// PC ( Player Character = Avatar )
//-----------------------------------------------------------------------------------
//Localize CJ Kor
struct sPC_DATA_LOCALIZE_DEV
{
};

struct sPC_DATA_LOCALIZE_DBONU
{
	NETP	netP;
};

struct sPC_DATA_LOCALIZE_CJIKOR
{
	char   	userCN[NTL_MAX_SIZE_USERCN];
	NETP	netP;
	BYTE	byAge;
	BYTE	bySex;
};

//Localize Data
struct sPC_DATA_LOCALIZE
{
	LOCALIZETYPE type;

	union
	{
		sPC_DATA_LOCALIZE_DEV	pcDataDev;

		sPC_DATA_LOCALIZE_DBONU pcDataDboNu;

		sPC_DATA_LOCALIZE_CJIKOR pcDataCJKor;
	};
};

// Ä³¸¯ÅÍ DB Á¤º¸
struct sPC_DATA
{
	CHARACTERID		charId;
	WCHAR			awchName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];

	BYTE			byRace;
	BYTE			byClass;
	bool			bIsAdult;
	bool			bChangeClass;
	BYTE			byGender;

	float			fPositionX;
	float			fPositionY;
	float			fPositionZ;

	float			fDirX;
	float			fDirY;
	float			fDirZ;

	BYTE			byBindType;
	WORLDID			bindWorldId;
	TBLIDX			bindObjectTblidx;
	sVECTOR3		vBindLoc;
	sVECTOR3		vBindDir;

	TBLIDX			worldTblidx;
	WORLDID			worldId;
	DWORD			dwEXP;
	BYTE			byLevel;
	FLOAT           fSize;
	DWORD			dwLP;
	DWORD			dwEP;
	DWORD			dwRP;
	BYTE			byFace;
	BYTE			byHair;
	BYTE			byHairColor;
	BYTE			bySkinColor;

	DWORD			dwMoney;
	DWORD			dwMoneyBank;
	BYTE			byBlood;

	DWORD			dwGMGroupSerial;
	ACCOUNTID		GMAccountID;

	GUILDID			guildId;
	DWORD			dwTutorialHint;
	DWORD			dwMapInfoIndex;		// Ä³¸¯ÅÍ ¼±ÅÃ½Ã Ãâ·ÂÇØ ÁÙ ÇöÀç Àå¼ÒÀÇ Text Tblidx

	DWORD			dwReputation;
	DWORD			dwMudosaPoint;
	DWORD			dwSpPoint;

	sMARKING		sMarking;
	sHOIPOIMIX_DATA sMixData;

	sPC_DATA_LOCALIZE sLocalize;
};

// Character ¼­¹öÃ¢ Á¤º¸ Ç¥½Ã 
struct sPC_SUMMARY
{
	CHARACTERID		charId;
	WCHAR			awchName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	BYTE			byRace;
	BYTE			byClass;
	bool			bIsAdult;
	BYTE			byGender;
	BYTE			byFace;
	BYTE			byHair;
	BYTE			byHairColor;
	BYTE			bySkinColor;
	BYTE			byLevel;
	FLOAT           fScale;
	TBLIDX			worldTblidx;
	WORLDID			worldId;
	float			fPositionX;
	float			fPositionY;
	float			fPositionZ;
	DWORD			dwMoney;
	DWORD			dwMoneyBank;
	sITEM_SUMMARY	sItem[EQUIP_SLOT_TYPE_COUNT]; // ÀåÂø ¾ÆÀÌÅÛ Á¤º¸
	DWORD			dwMapInfoIndex;
	bool			bTutorialFlag;

	sMARKING		sMarking;
	bool			bNeedNameChange;
	sDBO_DOGI_DATA	sDogi;
};

struct sPC_BRIEF
{
	CHARACTERID		charId;
	TBLIDX			tblidx; // pc Å×ÀÌºí ÀÎµ¦½º
	bool			bIsAdult;
	WCHAR			awchName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WCHAR			wszGuildName[NTL_MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];

	sPC_SHAPE		sPcShape; // pc ¿Ü¾ç ( ¾ó±¼/¸Ó¸®/¸Ó¸®»ö )

	WORD			wCurLP;
	WORD			wMaxLP;
	WORD			wCurEP;
	WORD			wMaxEP;
	BYTE			byLevel;
	float			fSpeed;

	sITEM_BRIEF		sItemBrief[EQUIP_SLOT_TYPE_COUNT]; // ÀåÂø ¾ÆÀÌÅÛ Á¤º¸

	WORD			wAttackSpeedRate;

	sDBO_GUILD_MARK	sMark;

	sMARKING		sMarking;

	sDBO_DOGI_DATA	sDogi;

	bool			bIsGameMaster;
};

//Localize CJ Kor
struct sPC_PROFILE_LOCALIZE_DEV
{
};

struct sPC_PROFILE_LOCALIZE_DBONU
{
	NETP	netP;
};

struct sPC_PROFILE_LOCALIZE_CJIKOR
{
	NETP	netP;
};

//Localize Data
struct sPC_PROFILE_LOCALIZE
{
	LOCALIZETYPE type;

	union
	{
		sPC_PROFILE_LOCALIZE_DEV pcProfileDev;

		sPC_PROFILE_LOCALIZE_DBONU pcProfileDboNu;

		sPC_PROFILE_LOCALIZE_CJIKOR pcProfileCJKor;
	};
};

// PC Ä³¸¯ÅÍ ÀüÃ¼ Á¤º¸ ( ¾Æ¹ÙÅ¸ ·ÎµùÀÌ³ª Ä³¸¯ÅÍ Á¶È¸µî¿¡ »ç¿ë )
struct sPC_PROFILE
{
	TBLIDX			tblidx; // pc Å×ÀÌºí ÀÎµ¦½º
	bool			bIsAdult;
	bool			bChangeClass;		// ÀüÁ÷ ±ÇÇÑÀ» °¡Áö°í ÀÖ´ÂÁöÀÇ ¿©ºÎ
	CHARACTERID		charId;		// PC Ä³¸¯ÅÍÀÇ °íÀ¯ ID(DB index)
	WCHAR			awchName[NTL_MAX_SIZE_CHAR_NAME_UNICODE + 1];

	sPC_SHAPE		sPcShape; // pc ¿Ü¾ç ( ¾ó±¼/¸Ó¸®/¸Ó¸®»ö )

	sAVATAR_ATTRIBUTE		avatarAttribute;

	WORD			wCurLP;
	WORD			wCurEP;
	WORD			wCurRP;

//	float			fSpeed;

	BYTE			byLevel;
	DWORD			dwCurExp;
	DWORD			dwMaxExpInThisLevel;

	DWORD			dwZenny;
	DWORD			dwTutorialHint;

	BYTE			byBindType;
	WORLDID			bindWorldId;
	TBLIDX			bindObjectTblidx;

	DWORD			dwReputation;
	DWORD			dwMudosaPoint;
	DWORD			dwSpPoint;

	sMARKING		sMarking;
	sHOIPOIMIX_DATA sMixData;

	bool			bIsGameMaster;		// true : ¿î¿µÀÚ character

	GUILDID			guildId;

	sPC_PROFILE_LOCALIZE sLocalize;
};

//-----------------------------------------------------------------------------------
// BOT ( NPC/MOB/PET µîÀÇ ¼­¹ö°¡ ÄÁÆ®·Ñ ÇÏ´Â Ä³¸¯ÅÍµéÀÇ ÃÑÄª )
//-----------------------------------------------------------------------------------

// bot data
struct sBOT_DATA
{
	TBLIDX			tblidx;

	WORLDID			worldID; // world id
	sVECTOR3		vCurLoc; // ÇöÀçÀ§Ä¡
	sVECTOR3		vCurDir; // ÇöÀç¹æÇâ

	sVECTOR3		vSpawnLoc; // ½ºÆùÀ§Ä¡
	sVECTOR3		vSpawnDir; // ½ºÆù ¹æÇâ
	BYTE			bySpawnRange; // ·£´ý ½ºÆù °Å¸®
	WORD			wSpawnTime; // ½ºÆù ½Ã°£ (ÃÊ)
	BYTE			bySpawnFuncFlag; // ½ºÆù ±â´É ÇÃ·¡±×

	BYTE			byMoveType; // eSPAWN_MOVE_TYPE
	BYTE			byWanderRange; // ¹èÈ¸ °Å¸® (m)
	BYTE			byMoveRange; // ÇÑ¹ø¿¡ ¿òÁ÷ÀÌ´Â °Å¸® (m)

	BYTE			byMoveDelayTime; // ¿òÁ÷ÀÌ´Â µô·¹ÀÌ Å¸ÀÓ
	ACTIONPATTERNTBLIDX actionpatternTblIdx; //ºñÀüÅõ Çàµ¿ ÆÐÅÏ ¼Â¿¡ Å×ÀÌºí ID

	TBLIDX			pathTblidx; // °æ·Î Å×ÀÌºí ¹øÈ£

	TBLIDX			playScript; // ¿¬Ãâ ½ºÅ©¸³Æ® ¹øÈ£
	TBLIDX			playScriptScene; // ¿¬Ãâ ½ºÅ©¸³Æ® ½Å ¹øÈ£

	TBLIDX			tblidxAiScript; // AI ½ºÅ©¸³Æ® ¹øÈ£
	TBLIDX			tblidxAiScriptScene; // AI ½ºÅ©¸³Æ® ½Å ¹øÈ£

	PARTYID			partyID; // ÆÄÆ¼ ¾ÆÀÌµð
	bool			bPartyLeader; // ÆÄÆ¼ ¸®´õ
	sVECTOR3		vPartyLeaderDistance; // ÆÄÆ¼ ¸®´õ¿ÍÀÇ °ø°£ °£°Ý

	DWORD			dwCharConditionFlag; // »ý¼ºµÉ¶§ Àû¿ëµÇ¾ß ÇÏ´Â Ä³¸¯ÅÍ ÄÁµð¼Ç
};


// bot brief
struct sBOT_BRIEF
{
	TBLIDX			tblidx;

	WORD			wCurLP;
	WORD			wCurEP;
	WORD			wMaxLP;
	WORD			wMaxEP;

	float			fLastWalkingSpeed;
	float			fLastRunningSpeed;
	WORD			wAttackSpeedRate;

	ACTIONPATTERNTBLIDX actionpatternTblIdx; //ºñÀüÅõ Çàµ¿ ÆÐÅÏ ¼Â¿¡ Å×ÀÌºí ID
};


// bot profile
struct sBOT_PROFILE
{
	TBLIDX			tblidx;
	WORLDID			worldID; // ¿ùµå

	sVECTOR3		vSpawnLoc; // ½ºÆùÀ§Ä¡
	sVECTOR3		vSpawnDir; // ½ºÆù ¹æÇâ
	BYTE			bySpawnRange; // ·£´ý ½ºÆù °Å¸®
	WORD			wSpawnTime; // ½ºÆù ½Ã°£ (ÃÊ)
	BYTE			bySpawnFuncFlag; // ¸®½ºÆù ¿©ºÎ

	BYTE			byMoveType; // eSPAWN_MOVE_TYPE
	BYTE			byWanderRange; // ¹èÈ¸ °Å¸®
	BYTE			byMoveRange; // ÇÑ¹ø¿¡ ¿òÁ÷ÀÌ´Â °Å¸®

	BYTE			byMoveDelayTime; // ¿òÁ÷ÀÌ´Â ½Ã°£ °£°Ý
	ACTIONPATTERNTBLIDX actionpatternTblIdx; //ºñÀüÅõ Çàµ¿ ÆÐÅÏ ¼Â¿¡ Å×ÀÌºí ID

	TBLIDX			pathTblidx; // °æ·Î Å×ÀÌºí ¹øÈ£

	TBLIDX			playScript; // ¿¬Ãâ ½ºÅ©¸³Æ® ¹øÈ£
	TBLIDX			playScriptScene; // ¿¬Ãâ ½ºÅ©¸³Æ® ½Å ¹øÈ£

	TBLIDX			tblidxAiScript; // AI ½ºÅ©¸³Æ® ¹øÈ£
	TBLIDX			tblidxAiScriptScene; // AI ½ºÅ©¸³Æ® ½Å ¹øÈ£

	PARTYID			partyID; // ÆÄÆ¼ ¾ÆÀÌµð
	bool			bPartyLeader; // ÆÄÆ¼ ¸®´õ
	sVECTOR3		vPartyLeaderDistance; // ¸®´õ¿ÍÀÇ °ø°£ °£°Ý

	WORD			wCurLP; // LP
	WORD			wMaxLP; // Max LP

	float			fLastWalkingSpeed; // °È´Â ¼Óµµ
	float			fLastRunningSpeed; // ¶Ù´Â ¼Óµµ

};



//-----------------------------------------------------------------------------------
// Non Player Character ( NPC )
//-----------------------------------------------------------------------------------

// npc data
struct sNPC_DATA : public sBOT_DATA
{
};


// npc brief
struct sNPC_BRIEF : public sBOT_BRIEF
{
	TBLIDX			nicknameTblidx;
};


// npc profile
struct sNPC_PROFILE : public sBOT_PROFILE
{
};


//-----------------------------------------------------------------------------------
// Monster Character ( MOB )
//-----------------------------------------------------------------------------------

// mob data
struct sMOB_DATA : public sBOT_DATA
{
	SPAWNGROUPID	spawnGroupId;
};


// mob brief
struct sMOB_BRIEF : public sBOT_BRIEF
{
	BYTE		byBallType; // ¸÷ »ý¼º½Ã µå·¡°ïº¼À» ¶³±¼¼ö ÀÖ´Â °æ¿ì ÀÎÁö ¾Æ´ÑÁö ¾Æ´Ñ°æ¿ì NtlItem.h cf) eDRAGON_BALL_TYPE
};

// mob profile
struct sMOB_PROFILE : public sBOT_PROFILE
{
	SPAWNGROUPID	spawnGroupId;
};



//-----------------------------------------------------------------------------------
// Pet Character ( PET )
//-----------------------------------------------------------------------------------

// pet data
struct sPET_DATA
{
	BYTE			byPetIndex;

	BYTE			bySourceType;		// eDBO_OBJECT_SOURCE
	TBLIDX			sourceTblidx;
};


// pet brief
struct sPET_BRIEF
{
	BYTE			bySourceType;		// eDBO_OBJECT_SOURCE
	TBLIDX			sourceTblidx;
	TBLIDX			npcTblidx;

	HOBJECT			hOwner;
	float			fLastRunningSpeed;
};

// pet profile
struct sPET_PROFILE
{
	BYTE					bySourceType;		// eDBO_OBJECT_SOURCE
	TBLIDX					sourceTblidx;
	TBLIDX					npcTblidx;

	HOBJECT					hOwner;
	BYTE					byAvatarType;		// eDBO_AVATAR_TYPE

	sAVATAR_ATTRIBUTE		attribute;
};


//-----------------------------------------------------------------------------------
// Summon Pet Character ( SUMMON PET )
//-----------------------------------------------------------------------------------

// summon pet data
struct sSUMMON_PET_DATA : public sPET_DATA
{
	WORD			wCurLP;
	WORD			wCurEP;
};

// summon pet brief
struct sSUMMON_PET_BRIEF : public sPET_BRIEF
{
	WORD			wCurLP;
	WORD			wCurEP;
	WORD			wMaxLP;
	WORD			wMaxEP;

	WORD			wAttackSpeedRate;
};

// summon pet profile
struct sSUMMON_PET_PROFILE : public sPET_PROFILE
{
	WORD			wCurLP;
	WORD			wCurEP;
};


//-----------------------------------------------------------------------------------
// Summon Pet Character ( ITEM PET )
//-----------------------------------------------------------------------------------

// item pet data
struct sITEM_PET_DATA : public sPET_DATA
{
	ITEMID		itemId;
};

// item pet brief
struct sITEM_PET_BRIEF : public sPET_BRIEF
{
};

// item pet profile
struct sITEM_PET_PROFILE : public sPET_PROFILE
{
};


//-----------------------------------------------------------------------------------
// QUICKSLOT
//-----------------------------------------------------------------------------------
struct sQUICK_SLOT_DATA
{
	TBLIDX	tblidx;
	BYTE	bySlot;
	BYTE	byType;
	ITEMID  itemID;
	HOBJECT	hItem;
};

struct sQUICK_SLOT_PROFILE
{
	TBLIDX	tblidx;
	BYTE	bySlot;
	BYTE	byType;
	HOBJECT	hItem;
};

enum eACCEPT_RES_TYPE
{
	ACCEPT_RES_TYPE_DENY = 0,
	ACCEPT_RES_TYPE_OK,
	ACCEPT_RES_TYPE_CANCEL, 
};	


//-----------------------------------------------------------------------------------
// ´ÜÃàÅ°
//-----------------------------------------------------------------------------------
struct sSHORTCUT_UPDATE_DATA
{
	BYTE    byType;		// eSHORTCUT_CHANGE_TYPE 
	WORD	wActionID;	
	WORD	wKey;
};

struct sSHORTCUT_DATA
{
	WORD	wActionID;	
	WORD	wKey;
};

enum eSHORTCUT_CHANGE_TYPE
{
	eSHORTCUT_CHANGE_TYPE_ADD = 0,
	eSHORTCUT_CHANGE_TYPE_DEL,
	eSHORTCUT_CHANGE_TYPE_UPDATE, 
};	

const int		 NTL_SHORTCUT_MAX_COUNT	= 100;   
//-----------------------------------------------------------------------------------
// WARFOG
//-----------------------------------------------------------------------------------
// WARFOG FLAG
struct sCHAR_WAR_FOG_FLAG
{
	char achWarFogFlag[NTL_MAX_SIZE_WAR_FOG];
};


//-----------------------------------------------------------------------------------
// SERVER CHANGE
//-----------------------------------------------------------------------------------
struct sDBO_SERVER_CHANGE_INFO
{
	SERVERCHANNELID		prevServerChannelId;
	WORLDID				destWorldId;
	TBLIDX				destWorldTblidx;
};


//-----------------------------------------------------------------------------------
// Game Mania Time .by Ju-hyeung Lee
//-----------------------------------------------------------------------------------

// from QueryServer
struct sGAME_MANIA_TIME_DATA
{
	DWORD dwSetTime;
	BYTE abyTimeSlot[GMT_MAX_EFFECT_LIST_SIZE][GMT_MAX_TIME_SLOT_SIZE];
};

// to client
struct sGAME_MANIA_TIME
{
	BYTE abyTimeSlot[GMT_MAX_EFFECT_LIST_SIZE][GMT_MAX_TIME_SLOT_SIZE];
};

#pragma pack()


//-----------------------------------------------------------------------------------
// Initialize function for union data
//-----------------------------------------------------------------------------------
void InitBotData(sBOT_DATA & rsBotData);

void InitNpcData(sNPC_DATA & rsNpcData);

void InitMobData(sMOB_DATA & rsMobData);

//-----------------------------------------------------------------------------------
// Copy character state data
//-----------------------------------------------------------------------------------

void CopyCharState( sCHARSTATE* pDest, const sCHARSTATE* pSrc );

//-----------------------------------------------------------------------------------
// Scouter
//-----------------------------------------------------------------------------------
DWORD Dbo_CalculatePowerLevel(
		BYTE byLastStr, BYTE byLastCon, BYTE byLastFoc, BYTE byLastDex, BYTE byLastSol, BYTE byLastEng,
		WORD wLastPhysicalOffence, WORD wLastPhysicalDefence, WORD wLastEnergyOffence, WORD wLastEnergyDefence,
		WORD wLastAttackRate, WORD wLastDodgeRate, WORD wLastCurseSuccessRate, WORD wLastCurseTolerance,
		WORD wLastPhysicalCriticalRate, WORD wLastEnergyCriticalRate,
		WORD wAttackSpeedRate,
		WORD wLastMaxLp, WORD wLastMaxEp, WORD wCurLp, WORD wCurEp, BYTE byCurRpBall,
		BYTE byLevel, BYTE byMobGrade);

float Dbo_ConvertToAgentRadius(float fObjectRadius);

float Dbo_GetTransformScale(eASPECTSTATE eAspect, BYTE byGrade);            ///< º¯½Å½Ã¿¡ º¯°æ ºñÀ²À» ¹ÝÈ¯ÇÑ´Ù.

const BYTE CalculateRPBallMaxByLevel( const BYTE byLevel );

DWORD GetSafeRetAdd( DWORD dwMax, DWORD dwCur, DWORD dwAdd );

// Use DBO_RP_CHARGE_INTERVAL_IN_MILLISECS instead of the following function.
// ¾Æ·¡ÀÇ ÇÔ¼ö ´ë½Å¿¡ DBO_RP_CHARGE_INTERVAL_IN_MILLISECS¸¦ ½á¾ß ÇÑ´Ù.
// by YOSHIKI(2009-07-28)
inline DWORD Dbo_GetRpChargeIntervalInMilliSecs(float fFormulaTableValue)
{
	float fInterval = fFormulaTableValue * 1000.f;

	if (1.0f > fInterval)
	{
		return 1;
	}
	else
	{
		return (DWORD)fInterval;
	}
}

// Use DBO_RP_DIMIMUTION_INTERVAL_IN_MILLISECS instead of the following function.
// ¾Æ·¡ÀÇ ÇÔ¼ö ´ë½Å¿¡ DBO_RP_DIMIMUTION_INTERVAL_IN_MILLISECS¸¦ ½á¾ß ÇÑ´Ù.
inline DWORD Dbo_GetRpDiminutionIntervalInMilliSecs(float fFormulaTableValue)
{
	float fInterval = fFormulaTableValue * 1000.f;

	if (1.0f > fInterval)
	{
		return 1;
	}
	else
	{
		return (DWORD)fInterval;
	}
}
