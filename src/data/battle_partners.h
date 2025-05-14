//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender =
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 21
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 18
            .ability = ABILITY_CLEAR_BODY,
#line 17
            .lvl = 42,
#line 19
            .ball = ITEM_CHERISH_BALL,
#line 16
            .nature = NATURE_JOLLY,
#line 20
            .isShiny = TRUE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 21
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 26
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 31
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 29
            .ability = ABILITY_STURDY,
#line 28
            .lvl = 43,
#line 30
            .ball = ITEM_PARK_BALL,
#line 27
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 31
                MOVE_CURSE,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 36
            .species = SPECIES_DURALUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 41
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 39
            .ability = ABILITY_STALWART,
#line 38
            .lvl = 44,
#line 40
            .ball = ITEM_HEAVY_BALL,
#line 37
            .nature = NATURE_BOLD,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 41
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_STEEL_BEAM,
                MOVE_BREAKING_SWIPE,
            },
            },
        },
    },
#line 46
    [PARTNER_BEN_BULBASAUR] =
    {
#line 47
        .trainerName = _("Ben"),
#line 48
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 49
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 51
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 53
            .nickname = COMPOUND_STRING("Bella"),
#line 53
            .species = SPECIES_BOLTUND,
#line 53
            .gender = TRAINER_MON_FEMALE,
#line 57
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 56
            .ability = ABILITY_STRONG_JAW,
#line 55
            .lvl = 32,
#line 54
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 57
                MOVE_THUNDER_FANG,
                MOVE_BITE,
                MOVE_BULK_UP,
                MOVE_NUZZLE,
            },
            },
            {
#line 62
            .species = SPECIES_GOOMY,
#line 62
            .gender = TRAINER_MON_FEMALE,
#line 62
            .heldItem = ITEM_CHESTO_BERRY,
#line 67
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 65
            .ability = ABILITY_GOOEY,
#line 64
            .lvl = 30,
#line 66
            .ball = ITEM_GREAT_BALL,
#line 63
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 67
                MOVE_ABSORB,
                MOVE_WATER_PULSE,
                MOVE_DRAGON_BREATH,
                MOVE_REST,
            },
            },
            {
#line 72
            .species = SPECIES_BRAIXEN,
#line 72
            .gender = TRAINER_MON_FEMALE,
#line 72
            .heldItem = ITEM_BINDING_BAND,
#line 76
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 75
            .ability = ABILITY_BLAZE,
#line 74
            .lvl = 33,
#line 73
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 76
                MOVE_SWIFT,
                MOVE_NASTY_PLOT,
                MOVE_PSYBEAM,
                MOVE_FIRE_SPIN,
            },
            },
        },
    },
#line 81
    [PARTNER_BEN_FENNEKIN] =
    {
#line 82
        .trainerName = _("Ben"),
#line 83
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 84
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 86
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 88
            .nickname = COMPOUND_STRING("Bella"),
#line 88
            .species = SPECIES_BOLTUND,
#line 88
            .gender = TRAINER_MON_FEMALE,
#line 92
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 91
            .ability = ABILITY_STRONG_JAW,
#line 90
            .lvl = 32,
#line 89
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 92
                MOVE_THUNDER_FANG,
                MOVE_BITE,
                MOVE_BULK_UP,
                MOVE_NUZZLE,
            },
            },
            {
#line 97
            .species = SPECIES_GOOMY,
#line 97
            .gender = TRAINER_MON_FEMALE,
#line 97
            .heldItem = ITEM_CHESTO_BERRY,
#line 102
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 100
            .ability = ABILITY_GOOEY,
#line 99
            .lvl = 30,
#line 101
            .ball = ITEM_GREAT_BALL,
#line 98
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 102
                MOVE_ABSORB,
                MOVE_WATER_PULSE,
                MOVE_DRAGON_BREATH,
                MOVE_REST,
            },
            },
            {
#line 107
            .species = SPECIES_PRINPLUP,
#line 107
            .gender = TRAINER_MON_MALE,
#line 107
            .heldItem = ITEM_RAZOR_FANG,
#line 111
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 110
            .ability = ABILITY_TORRENT,
#line 109
            .lvl = 33,
#line 108
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 111
                MOVE_METAL_CLAW,
                MOVE_BRINE,
                MOVE_ICY_WIND,
                MOVE_AGILITY,
            },
            },
        },
    },
#line 116
    [PARTNER_BEN_PIPLUP] =
    {
#line 117
        .trainerName = _("Ben"),
#line 118
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 119
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender =
#line 121
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 123
            .nickname = COMPOUND_STRING("Bella"),
#line 123
            .species = SPECIES_BOLTUND,
#line 123
            .gender = TRAINER_MON_FEMALE,
#line 127
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 126
            .ability = ABILITY_STRONG_JAW,
#line 125
            .lvl = 32,
#line 124
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 127
                MOVE_THUNDER_FANG,
                MOVE_BITE,
                MOVE_BULK_UP,
                MOVE_NUZZLE,
            },
            },
            {
#line 132
            .species = SPECIES_GOOMY,
#line 132
            .gender = TRAINER_MON_FEMALE,
#line 132
            .heldItem = ITEM_CHESTO_BERRY,
#line 137
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 135
            .ability = ABILITY_GOOEY,
#line 134
            .lvl = 30,
#line 136
            .ball = ITEM_GREAT_BALL,
#line 133
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 137
                MOVE_ABSORB,
                MOVE_WATER_PULSE,
                MOVE_DRAGON_BREATH,
                MOVE_REST,
            },
            },
            {
#line 142
            .species = SPECIES_IVYSAUR,
#line 142
            .gender = TRAINER_MON_MALE,
#line 142
            .heldItem = ITEM_BLACK_SLUDGE,
#line 146
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 145
            .ability = ABILITY_OVERGROW,
#line 144
            .lvl = 33,
#line 143
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 146
                MOVE_TAKE_DOWN,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
        },
    },
