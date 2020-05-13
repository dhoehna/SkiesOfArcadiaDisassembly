#ifndef INCLUDE_PLAYECHARACTER_H__
#define INCLUDE_PLAYERCHARACTER_H__

#include <stdint.h>

enum {
	STAT_POWER = 0,
	STAT_WILL  = 1,
	STAT_VIGOR = 2,
	STAT_AGILE = 3,
	STAT_QUICK = 4
};

enum {
	DSTAT_ATTACK      = 0,
	DSTAT_DEFENSE     = 1,
	DSTAT_MDEFENSE    = 2,
	DSTAT_HITCHANCE   = 3,
	DSTAT_DODGECHANCE = 4
};

enum {
	ELEM_GREEN  = 0,
	ELEM_RED    = 1,
	ELEM_PURPLE = 2,
	ELEM_BLUE   = 3,
	ELEM_YELLOW = 4,
	ELEM_SILVER = 5
};

enum {
	STATUS_POISON    = 0,
	STATUS_DEATH     = 1,
	STATUS_STONE     = 2,
	STATUS_SLEEP     = 3,
	STATUS_CONFUSION = 4,
	STATUS_SILENCE   = 5,
	STATUS_FATIGUE   = 6,
	STATUS_REVIVAL   = 7,
	STATUS_WEAK      = 8,
	STATUS_UNK1      = 9,
	STATUS_UNK2      = 10,
	STATUS_UNK3      = 11,
	STATUS_UNK4      = 12,
	STATUS_UNK5      = 13,
	STATUS_UNK6      = 14,
	STATUS_UNK7      = 15
};

enum {
	int8_t_VYSE    = 0,
	int8_t_AIKA    = 1,
	int8_t_FINA    = 2,
	int8_t_DRACHMA = 3,
	int8_t_ENRIQUE = 4,
	int8_t_GILDER  = 5
};

typedef struct {
	char name[11];
	int8_t level;
	int8_t timesKnockedOut;
	int8_t curMP;
	int8_t maxMP;
	int8_t weaponElement;
	short equippedWeaponId;
	short equippedArmorId;
	short equippedAccessoryId;
	short numMoonberriesUsed;
	short curHP;
	short maxHP;
	short spirit;
	short maxSpirit;
	short curCounterChance;
	short finalBlowsDealt;
	int experience;
	float maxMP_fractional;
	int8_t abilities[8]; // Actually a bitfield
	int8_t elemRanks[6];
	short mainStat[5];
	int elemExp[6];
} PlayerCharacterData_t;

typedef struct {
	short field_0x00;
	short field_0x02;

	short maxHP;
	short spirit;
	short maxSpirit;

	short field_0x0a;

	short spiritGainMult;
	short baseCounterChance;

	int8_t field_0x10;
	int8_t field_0x11;
	int8_t field_0x12;
	int8_t field_0x13;

	short spiritGainMode;
	short invulnToNormal;
	int expToNextLevel;
	short elemAffinities[6];
	short statusAffinities[16];
	short mainStat[5];
	short derivedStat[5];

	int8_t field_0x5c;
	int8_t field_0x5d;
	int8_t field_0x5e;
	int8_t field_0x5f;

	int elemExpToNext[6];
} PlayerCharacterExtraData_t;

typedef struct {
	char name[11];
	int8_t age;
	int8_t gender;
	int8_t width;
	int8_t depth;
	int8_t baseMP;
	int8_t weaponElement;

	// Added to guarantee padding
	int8_t padding0;

	short weaponId;
	short armorId;
	short accessoryId;
	short movementFlags;
	short curHP;
	short maxHP;
	short maxHpIncrease;
	short spirit;
	short maxSpirit;
	short baseCounterChance;

	// Added to guarantee padding
	short padding1;

	int experience;
	float mpIncrease;

	float field_0x30; // Unknown field

	short elemAffinity[6];
	short statusAffinity[16];

	short mainStat[5];

	// Added to guarantee padding
	short padding2;

	float mainStatIncrease[5];

	int elemExperience[6];
} BasePCData_t;

typedef struct {
	uint8_t perTurn;
	uint8_t max;
} SpiritTableEntry_t;

// Represents the contents of /battle/first.lmt
typedef struct {
	unsigned int levelExperienceTables[6][99];
	unsigned short elementalExperienceTable[6][6][99];

	char unknownData[0x7C];
} FirstDotLmt_t;

extern PlayerCharacterData_t PlayerCharacterData[6];
extern PlayerCharacterExtraData_t PlayerCharacterExtraData[6];
extern BasePCData_t BasePCData[6];
extern SpiritTableEntry_t SpiritTable[6][99];
extern FirstDotLmt_t* pFirstDotLmt;

#endif  //INCLUDE_PLAYERCHARACTER_H__