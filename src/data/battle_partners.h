//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file see expansion PR #7154
//

#line 1 "src/data/battle_partners.party"

#line 1
    [DIFFICULTY_NORMAL][PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 7
        .trainerBackPic = TRAINER_BACK_PIC_BRENDAN,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 9
    [DIFFICULTY_NORMAL][PARTNER_STEVEN] =
    {
#line 10
        .trainerName = _("Steven"),
#line 11
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 12
        .trainerPic = TRAINER_PIC_STEVEN,
        .encounterMusic_gender =
#line 14
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 0
        .trainerBackPic = TRAINER_PIC_STEVEN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 16
            .species = SPECIES_METANG,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 22
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 19
            .ability = ABILITY_CLEAR_BODY,
#line 18
            .lvl = 42,
#line 20
            .ball = ITEM_CHERISH_BALL,
#line 17
            .nature = NATURE_JOLLY,
#line 21
            .isShiny = TRUE,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 22
                MOVE_LIGHT_SCREEN,
                MOVE_PSYCHIC,
                MOVE_REFLECT,
                MOVE_METAL_CLAW,
            },
            },
            {
#line 27
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 32
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 30
            .ability = ABILITY_STURDY,
#line 29
            .lvl = 43,
#line 31
            .ball = ITEM_PARK_BALL,
#line 28
            .nature = NATURE_IMPISH,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 32
                MOVE_CURSE,
                MOVE_AERIAL_ACE,
                MOVE_PROTECT,
                MOVE_STEEL_WING,
            },
            },
            {
#line 37
            .species = SPECIES_DURALUDON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 42
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 40
            .ability = ABILITY_STALWART,
#line 39
            .lvl = 44,
#line 41
            .ball = ITEM_HEAVY_BALL,
#line 38
            .nature = NATURE_BOLD,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 42
                MOVE_THUNDER,
                MOVE_PROTECT,
                MOVE_STEEL_BEAM,
                MOVE_BREAKING_SWIPE,
            },
            },
        },
    },
#line 47
    [DIFFICULTY_NORMAL][PARTNER_BEN_BULBASAUR] =
    {
#line 48
        .trainerName = _("Ben"),
#line 49
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 50
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
#line 52
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 0
        .trainerBackPic = TRAINER_PIC_BRENDAN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 54
            .nickname = COMPOUND_STRING("Bella"),
#line 54
            .species = SPECIES_BOLTUND,
#line 54
            .gender = TRAINER_MON_FEMALE,
#line 58
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 57
            .ability = ABILITY_STRONG_JAW,
#line 56
            .lvl = 32,
#line 55
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 58
                MOVE_THUNDER_FANG,
                MOVE_BITE,
                MOVE_BULK_UP,
                MOVE_NUZZLE,
            },
            },
            {
#line 63
            .species = SPECIES_GOOMY,
#line 63
            .gender = TRAINER_MON_FEMALE,
#line 63
            .heldItem = ITEM_CHESTO_BERRY,
#line 68
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 66
            .ability = ABILITY_GOOEY,
#line 65
            .lvl = 30,
#line 67
            .ball = ITEM_GREAT_BALL,
#line 64
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 68
                MOVE_ABSORB,
                MOVE_WATER_PULSE,
                MOVE_DRAGON_BREATH,
                MOVE_REST,
            },
            },
            {
#line 73
            .species = SPECIES_BRAIXEN,
#line 73
            .gender = TRAINER_MON_FEMALE,
#line 73
            .heldItem = ITEM_BINDING_BAND,
#line 77
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 76
            .ability = ABILITY_BLAZE,
#line 75
            .lvl = 33,
#line 74
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 77
                MOVE_SWIFT,
                MOVE_NASTY_PLOT,
                MOVE_PSYBEAM,
                MOVE_FIRE_SPIN,
            },
            },
        },
    },
#line 82
    [DIFFICULTY_NORMAL][PARTNER_BEN_FENNEKIN] =
    {
#line 83
        .trainerName = _("Ben"),
#line 84
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 85
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
#line 87
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 0
        .trainerBackPic = TRAINER_PIC_BRENDAN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 89
            .nickname = COMPOUND_STRING("Bella"),
#line 89
            .species = SPECIES_BOLTUND,
#line 89
            .gender = TRAINER_MON_FEMALE,
#line 93
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 92
            .ability = ABILITY_STRONG_JAW,
#line 91
            .lvl = 32,
#line 90
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 93
                MOVE_THUNDER_FANG,
                MOVE_BITE,
                MOVE_BULK_UP,
                MOVE_NUZZLE,
            },
            },
            {
#line 98
            .species = SPECIES_GOOMY,
#line 98
            .gender = TRAINER_MON_FEMALE,
#line 98
            .heldItem = ITEM_CHESTO_BERRY,
#line 103
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 101
            .ability = ABILITY_GOOEY,
#line 100
            .lvl = 30,
#line 102
            .ball = ITEM_GREAT_BALL,
#line 99
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 103
                MOVE_ABSORB,
                MOVE_WATER_PULSE,
                MOVE_DRAGON_BREATH,
                MOVE_REST,
            },
            },
            {
#line 108
            .species = SPECIES_PRINPLUP,
#line 108
            .gender = TRAINER_MON_MALE,
#line 108
            .heldItem = ITEM_RAZOR_FANG,
#line 112
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 111
            .ability = ABILITY_TORRENT,
#line 110
            .lvl = 33,
#line 109
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 112
                MOVE_METAL_CLAW,
                MOVE_BRINE,
                MOVE_ICY_WIND,
                MOVE_AGILITY,
            },
            },
        },
    },
#line 117
    [DIFFICULTY_NORMAL][PARTNER_BEN_PIPLUP] =
    {
#line 118
        .trainerName = _("Ben"),
#line 119
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 120
        .trainerPic = TRAINER_PIC_BRENDAN,
        .encounterMusic_gender =
#line 122
            TRAINER_ENCOUNTER_MUSIC_MALE,
#line 0
        .trainerBackPic = TRAINER_PIC_BRENDAN,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 124
            .nickname = COMPOUND_STRING("Bella"),
#line 124
            .species = SPECIES_BOLTUND,
#line 124
            .gender = TRAINER_MON_FEMALE,
#line 128
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 127
            .ability = ABILITY_STRONG_JAW,
#line 126
            .lvl = 32,
#line 125
            .nature = NATURE_JOLLY,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 128
                MOVE_THUNDER_FANG,
                MOVE_BITE,
                MOVE_BULK_UP,
                MOVE_NUZZLE,
            },
            },
            {
#line 133
            .species = SPECIES_GOOMY,
#line 133
            .gender = TRAINER_MON_FEMALE,
#line 133
            .heldItem = ITEM_CHESTO_BERRY,
#line 138
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 136
            .ability = ABILITY_GOOEY,
#line 135
            .lvl = 30,
#line 137
            .ball = ITEM_GREAT_BALL,
#line 134
            .nature = NATURE_RELAXED,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 138
                MOVE_ABSORB,
                MOVE_WATER_PULSE,
                MOVE_DRAGON_BREATH,
                MOVE_REST,
            },
            },
            {
#line 143
            .species = SPECIES_IVYSAUR,
#line 143
            .gender = TRAINER_MON_MALE,
#line 143
            .heldItem = ITEM_BLACK_SLUDGE,
#line 147
            .iv = TRAINER_PARTY_IVS(31, 31, 31, 31, 31, 31),
#line 146
            .ability = ABILITY_OVERGROW,
#line 145
            .lvl = 33,
#line 144
            .nature = NATURE_MODEST,
            .dynamaxLevel = MAX_DYNAMAX_LEVEL,
            .moves = {
#line 147
                MOVE_TAKE_DOWN,
                MOVE_LEECH_SEED,
                MOVE_GIGA_DRAIN,
                MOVE_TOXIC,
            },
            },
        },
    },
