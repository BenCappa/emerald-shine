#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "level_caps.h"
#include "pokemon.h"

u8 GetCurrentBadgeCount(void)
{
    u16 i, j, badgeCount = 0;
    for (i = FLAG_BADGE01_GET; i < FLAG_BADGE01_GET + NUM_BADGES; i++)
    {
        if(FlagGet(i))
            badgeCount++;
    }
    for (j = FLAG_DEFEATED_ELITE_4_DRAKE; j < FLAG_DEFEATED_ELITE_4_DRAKE + 4; j++)
    {
        if(FlagGet(j))
            badgeCount++;
    }
    return badgeCount;
}

enum LevelCap {
    LEVEL_CAP_NO_BADGES,
    LEVEL_CAP_BADGE_1,
    LEVEL_CAP_BADGE_2,
    LEVEL_CAP_BADGE_3,
    LEVEL_CAP_BADGE_4,
    LEVEL_CAP_BADGE_5,
    LEVEL_CAP_BADGE_6,
    LEVEL_CAP_BADGE_7,
    LEVEL_CAP_BADGE_8,
    LEVEL_CAP_SYDNEY,
    LEVEL_CAP_PHOEBE,
    LEVEL_CAP_GLACIA,
    LEVEL_CAP_DRAKE
};

static const u8 sLevelCapTable[] =
{
    [LEVEL_CAP_NO_BADGES]   = 15,
    [LEVEL_CAP_BADGE_1]     = 19,
    [LEVEL_CAP_BADGE_2]     = 24,
    [LEVEL_CAP_BADGE_3]     = 29,
    [LEVEL_CAP_BADGE_4]     = 31,
    [LEVEL_CAP_BADGE_5]     = 33,
    [LEVEL_CAP_BADGE_6]     = 42,
    [LEVEL_CAP_BADGE_7]     = 46,
    [LEVEL_CAP_BADGE_8]     = 49,
    [LEVEL_CAP_SYDNEY]      = 51,
    [LEVEL_CAP_PHOEBE]      = 53,
    [LEVEL_CAP_GLACIA]      = 55,
    [LEVEL_CAP_DRAKE]       = 58,
};

u32 GetCurrentLevelCap(void)
{
    u8 badgeCount = GetCurrentBadgeCount();

    if (FlagGet(FLAG_IS_CHAMPION))
        return MAX_LEVEL;
    else
        return sLevelCapTable[badgeCount];
    
    return MAX_LEVEL;
}