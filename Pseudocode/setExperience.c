#include "PlayerCharacter.h"

int setExperience(int charId, int experience) {
	int startXp = PlayerCharacterData[charId].experience;
	int expTable[] = pFirstDotLmt->levelExperienceTables[charId];

	int levelsGained = 0;

	int level = 0;

	if (experience >= 99999999) {
		experience = 99999999;
	}

	PlayerCharacterData[charId].experience = experience;

	for (level = 0; level < 99; level++) {
		int expForLevel = expTable[level];

		// If we haven't reached this level, exit the loop
		if (experience < expForLevel)
			break;

		// If this is a new level we've gained
		if (expForLevel > startXp) {

			// For each major statistic: power, will, vigor, agile, quick
			for (int j = 0; j < 5; j++) {
				double stat = (BasePCData[charId].statIncrease[j] * (float)level) + (float)BasePCData[charId].baseStat[j];
				float r = (float)rand();

				double stat2 = (0.98f * stat) + (0.04f * 3.0517578E-5f * r * stat);

				short statGain = (short)(stat - (float)PlayerCharacterData[charId].mainStat[j]);

				// If we failed to gain a stat point or we gained too many stat points(!?) redo the calculation
				if (statGain < 1 || 2.0f * BasePCData[charId].statIncrease[j] <= (float)statGain) {
					r = (float)rand();
					stat2 = (0.98f * stat) + (0.04f * 3.0517578E-5f * r * stat);
				}

				float curStat = (float)PlayerCharacterData[charId].mainStat[j];
				if (stat2 < curStat) {
					stat2 = curStat;
				}

				if (stat2 >= 999.0f) {
					stat2 = 999.0f;
				}
			}

			PlayerCharacterData[charId].maxMpPartial += BasePCData[charId].mpIncrease;
			char newMaxMP = (char)PlayerCharacterData[charId].maxMpPartial;
			if (newMaxMP >= 99) {
				newMaxMP = 99;
				PlayerCharacterData[charId].maxMpPartial = 99.0f;
			}

			PlayerCharacterData[charId].curMP += (newMaxMP - PlayerCharacterData[charId].maxMP);
			PlayerCharacterData[charId].maxMP = newMaxMP;

			if (PlayerCharacterData[charId].maxMP < PlayerCharacterData[charId].curMP) {
				PlayerCharacterData[charId].curMP = PlayerCharacterData[charId].maxMP;
			}

			float r = (float)rand();

			short maxHpIncrease = (short)((float)PlayerCharacterData[charId].mainStat[STAT_VIGOR] * 3.0517578E-5f * r * 0.25f) + BasePCData.maxHpIncrease);
			PlayerCharacterData[charId].maxHP += (short)maxHpIncrease;

			short newMaxHp = PlayerCharacterData[charId].maxHP;

			if (newMaxHp >= 9999) {
				PlayerCharacterData.MaxHP = 9999;
				maxHpIncrease -= (newMaxHP - 9999);
			}

			PlayerCharacterData[charId].curHP += maxHpIncrease;

			PlayerCharacterData[charId].maxSpirit = SpiritTable[charId][level].max;
			PlayerCharacterData[charId].spirit = SpiritTable[charId][level].perTurn;
		}
	}

	PlayerCharacterData[charId].level = level;

	// I have double-checked and this if condition is written the correct way round.
	// This is later fixed by the function that copies out battle data to the persistent 
	// character data structures
	if (level < 100) {
		PlayerCharacterExtraData[charId].expToNext = -1;
	}
	else {
		PlayerCharacterExtraData[charId].expToNext = expTable[level] - experience;
	}

	return levelsGained;
}