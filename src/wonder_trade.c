#include "global.h"
#include "pokemon.h"
#include "strings.h"
#include "random.h"
#include <stdbool.h>
#include "text.h"
#include "event_data.h"
#include "constants/species.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "data/text/wonder_trade_OT_names.h"
#include "item.h"
#include "constants/item.h"
#include "constants/hold_effects.h"
#include "mail.h"
#include "constants/pokemon.h"
#include "party_menu.h"
#include "constants/weather.h"
#include "battle.h" // A workaround to include the expansion's constants/form_change_types.h without breaking Pret/Pokeemerald compatibility.
#include "string_util.h"
#include "daycare.h"
#include "wonder_trade.h"

// This file's functions.
static u16 PickRandomSpecies(void);
static u8 GetWonderTradeOT(u8 *name);
static u16 GetUnownForm(void);
static u16 GetWonderTradeEvolutionTargetSpecies(struct Pokemon *mon);
// static u32 GetEvolutionSpecies(u16 speciesId);
// static bool32 IsSpeciesFamilyMegaEvolutionCompatible(u16 speciesId);
static u16 GetValidHeldItemForSpecies(u16 speciesId);
static u16 GetMegaStoneForSpecies(u16 speciesId);
static u16 GetArceusPlate(void);
static u16 GetGenesectDrive(void);
static u16 GetOricorioNectar(void);
static u16 GetSilvallyMemory(void);
static u16 GetRandomItem(void);

struct WonderTrade {
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 species;
    u8 ivs[NUM_STATS];
    u8 abilityNum;
    u32 otId;
    u8 conditions[CONTEST_CATEGORIES_COUNT];
    u32 personality;
    u16 heldItem;
    u8 mailNum;
    u8 otName[TRAINER_NAME_LENGTH + 1];
    u8 otGender;
    u8 sheen;
    u16 requestedSpecies;
};

static const u16 sLimitedSpecies[] = {
    // GEN 1
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_RATTATA,
    SPECIES_SANDSHREW,
    SPECIES_VULPIX,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_MEOWTH,
    SPECIES_PSYDUCK,
    SPECIES_GROWLITHE,
    SPECIES_POLIWAG,
    SPECIES_PONYTA,
    SPECIES_MAGNEMITE,
    SPECIES_FARFETCHD,
    SPECIES_GRIMER,
    SPECIES_GASTLY,
    SPECIES_ONIX,
    SPECIES_VOLTORB,
    SPECIES_CUBONE,
    SPECIES_KOFFING,
    SPECIES_HORSEA,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
    SPECIES_TAUROS,
    SPECIES_MAGIKARP,
    SPECIES_LAPRAS,
    SPECIES_EEVEE,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    SPECIES_AERODACTYL,
    SPECIES_DRATINI,

    // GEN 2
    SPECIES_CHIKORITA,
    SPECIES_CYNDAQUIL,
    SPECIES_TOTODILE,
    SPECIES_CHINCHOU,
    SPECIES_PICHU,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_TOGEPI,
    SPECIES_MAREEP,
    SPECIES_YANMA,
    SPECIES_WOOPER,
    SPECIES_MISDREAVUS,
    SPECIES_GLIGAR,
    SPECIES_HERACROSS,
    SPECIES_SNEASEL,
    SPECIES_CORSOLA,
    SPECIES_REMORAID,
    SPECIES_HOUNDOUR,
    SPECIES_PHANPY,

    // GEN 3
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_ZIGZAGOON,
    SPECIES_WURMPLE,
    SPECIES_RALTS,
    SPECIES_SURSKIT,
    SPECIES_SHROOMISH,
    SPECIES_AZURILL,
    SPECIES_MAWILE,
    SPECIES_ARON,
    SPECIES_PLUSLE,
    SPECIES_MINUN,
    SPECIES_CARVANHA,
    SPECIES_NUMEL,
    SPECIES_SWABLU,
    SPECIES_SEVIPER,
    SPECIES_CORPHISH,
    SPECIES_LILEEP,
    SPECIES_ANORITH,
    SPECIES_FEEBAS,
    SPECIES_CASTFORM,
    SPECIES_SHUPPET,
    SPECIES_ABSOL,
    SPECIES_SNORUNT,
    SPECIES_SPHEAL,
    SPECIES_LUVDISC,

    // GEN 4
    SPECIES_TURTWIG,
    SPECIES_CHIMCHAR,
    SPECIES_PIPLUP,
    SPECIES_STARLY,
    SPECIES_CRANIDOS,
    SPECIES_SHIELDON,
    SPECIES_BURMY_PLANT,
    SPECIES_COMBEE,
    SPECIES_BUIZEL,
    SPECIES_SHELLOS_WEST,
    SPECIES_DRIFLOON,
    SPECIES_BONSLY,
    SPECIES_GIBLE,
    SPECIES_MUNCHLAX,
    SPECIES_RIOLU,
    SPECIES_FINNEON,
    SPECIES_MANTYKE,
    SPECIES_ROTOM,

    // GEN 5
    SPECIES_SNIVY,
    SPECIES_TEPIG,
    SPECIES_OSHAWOTT,
    SPECIES_ROGGENROLA,
    SPECIES_AUDINO,
    SPECIES_SEWADDLE,
    SPECIES_COTTONEE,
    SPECIES_PETILIL,
    SPECIES_BASCULIN_RED_STRIPED,
    SPECIES_SANDILE,
    SPECIES_MARACTUS,
    SPECIES_DWEBBLE,
    SPECIES_YAMASK,
    SPECIES_TIRTOUGA,
    SPECIES_ARCHEN,
    SPECIES_ZORUA,
    SPECIES_MINCCINO,
    SPECIES_GOTHITA,
    SPECIES_SOLOSIS,
    SPECIES_DUCKLETT,
    SPECIES_VANILLITE,
    SPECIES_DEERLING,
    SPECIES_EMOLGA,
    SPECIES_FRILLISH,
    SPECIES_ALOMOMOLA,
    SPECIES_JOLTIK,
    SPECIES_LITWICK,
    SPECIES_AXEW,
    SPECIES_RUFFLET,
    SPECIES_VULLABY,

    // GEN 6
    SPECIES_CHESPIN,
    SPECIES_FENNEKIN,
    SPECIES_FROAKIE,
    SPECIES_FLABEBE_RED,
    SPECIES_PANCHAM,
    SPECIES_HONEDGE,
    SPECIES_INKAY,
    SPECIES_SKRELP,
    SPECIES_CLAUNCHER,
    SPECIES_TYRUNT,
    SPECIES_AMAURA,
    SPECIES_CARBINK,
    SPECIES_GOOMY,
    SPECIES_PHANTUMP,
    SPECIES_NOIBAT,

    // GEN 7
    SPECIES_ROWLET,
    SPECIES_LITTEN,
    SPECIES_POPPLIO,
    SPECIES_CUTIEFLY,
    SPECIES_ROCKRUFF,
    SPECIES_WISHIWASHI,
    SPECIES_DEWPIDER,
    SPECIES_MORELULL,
    SPECIES_SALANDIT,
    SPECIES_BOUNSWEET,
    SPECIES_SANDYGAST,
    SPECIES_MINIOR_METEOR_RED,
    SPECIES_TOGEDEMARU,
    SPECIES_MIMIKYU,
    SPECIES_BRUXISH,
    SPECIES_DRAMPA,
    SPECIES_DHELMISE,

    // GEN 8
    SPECIES_GROOKEY,
    SPECIES_SCORBUNNY,
    SPECIES_SOBBLE,
    SPECIES_ROOKIDEE,
    SPECIES_NICKIT,
    SPECIES_CHEWTLE,
    SPECIES_YAMPER,
    SPECIES_ROLYCOLY,
    SPECIES_APPLIN,
    SPECIES_SILICOBRA,
    SPECIES_TOXEL,
    SPECIES_CLOBBOPUS,
    SPECIES_SINISTEA_PHONY,
    SPECIES_MILCERY,
    SPECIES_PINCURCHIN,
    SPECIES_SNOM,
    SPECIES_DRACOZOLT,
    SPECIES_ARCTOZOLT,
    SPECIES_DRACOVISH,
    SPECIES_ARCTOVISH,

    // GEN 9
    SPECIES_SPRIGATITO,
    SPECIES_FUECOCO,
    SPECIES_QUAXLY,
    SPECIES_PAWMI,
    SPECIES_FIDOUGH,
    SPECIES_NACLI,
    SPECIES_CHARCADET,
    SPECIES_WATTREL,
    SPECIES_TOEDSCOOL,
    SPECIES_TINKATINK,
    SPECIES_WIGLETT,
    SPECIES_FINIZEN,
    SPECIES_GLIMMET,
    SPECIES_VELUZA,
    SPECIES_DONDOZO,
    SPECIES_TATSUGIRI_CURLY,
    SPECIES_POLTCHAGEIST_COUNTERFEIT,

    // Alternate Forms
    SPECIES_RATTATA_ALOLA,
    SPECIES_SANDSHREW_ALOLA,
    SPECIES_VULPIX_ALOLA,
    SPECIES_MEOWTH_ALOLA,
    SPECIES_GRIMER_ALOLA,
    SPECIES_MEOWTH_GALAR,
    SPECIES_PONYTA_GALAR,
    SPECIES_FARFETCHD_GALAR,
    SPECIES_CORSOLA_GALAR,
    SPECIES_ZIGZAGOON_GALAR,
    SPECIES_YAMASK_GALAR,
    SPECIES_GROWLITHE_HISUI,
    SPECIES_VOLTORB_HISUI,
    SPECIES_SNEASEL_HISUI,
    SPECIES_ZORUA_HISUI,
    SPECIES_BURMY_SANDY,
    SPECIES_BURMY_TRASH,
    SPECIES_SHELLOS_EAST,
    SPECIES_FLABEBE_YELLOW,
    SPECIES_FLABEBE_ORANGE,
    SPECIES_FLABEBE_BLUE,
    SPECIES_FLABEBE_WHITE,
    SPECIES_BASCULIN_BLUE_STRIPED,
    SPECIES_BASCULIN_WHITE_STRIPED,
    SPECIES_MINIOR_METEOR_ORANGE,
    SPECIES_MINIOR_METEOR_YELLOW,
    SPECIES_MINIOR_METEOR_GREEN,
    SPECIES_MINIOR_METEOR_BLUE,
    SPECIES_MINIOR_METEOR_INDIGO,
    SPECIES_MINIOR_METEOR_VIOLET,
    SPECIES_SINISTEA_ANTIQUE,
    SPECIES_ROCKRUFF_OWN_TEMPO,
    SPECIES_TAUROS_PALDEA_COMBAT,
    SPECIES_TAUROS_PALDEA_BLAZE,
    SPECIES_TAUROS_PALDEA_AQUA,
    SPECIES_WOOPER_PALDEA,
    SPECIES_TATSUGIRI_DROOPY,
    SPECIES_TATSUGIRI_STRETCHY,
    SPECIES_POLTCHAGEIST_ARTISAN,
};

static const u16 sAllSpecies[] = {
    // GEN 1
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_CATERPIE,
    SPECIES_WEEDLE,
    SPECIES_PIDGEY,
    SPECIES_RATTATA,
    SPECIES_SPEAROW,
    SPECIES_EKANS,
    SPECIES_SANDSHREW,
    SPECIES_NIDORAN_F,
    SPECIES_NIDORAN_M,
    SPECIES_VULPIX,
    SPECIES_ZUBAT,
    SPECIES_ODDISH,
    SPECIES_PARAS,
    SPECIES_VENONAT,
    SPECIES_DIGLETT,
    SPECIES_MEOWTH,
    SPECIES_PSYDUCK,
    SPECIES_MANKEY,
    SPECIES_GROWLITHE,
    SPECIES_POLIWAG,
    SPECIES_ABRA,
    SPECIES_MACHOP,
    SPECIES_BELLSPROUT,
    SPECIES_TENTACOOL,
    SPECIES_GEODUDE,
    SPECIES_PONYTA,
    SPECIES_SLOWPOKE,
    SPECIES_MAGNEMITE,
    SPECIES_FARFETCHD,
    SPECIES_DODUO,
    SPECIES_SEEL,
    SPECIES_GRIMER,
    SPECIES_SHELLDER,
    SPECIES_GASTLY,
    SPECIES_ONIX,
    SPECIES_DROWZEE,
    SPECIES_KRABBY,
    SPECIES_VOLTORB,
    SPECIES_EXEGGCUTE,
    SPECIES_CUBONE,
    SPECIES_LICKITUNG,
    SPECIES_KOFFING,
    SPECIES_RHYHORN,
    SPECIES_TANGELA,
    SPECIES_KANGASKHAN,
    SPECIES_HORSEA,
    SPECIES_GOLDEEN,
    SPECIES_STARYU,
    SPECIES_SCYTHER,
    SPECIES_PINSIR,
    SPECIES_TAUROS,
    SPECIES_MAGIKARP,
    SPECIES_LAPRAS,
    SPECIES_DITTO,
    SPECIES_EEVEE,
    SPECIES_PORYGON,
    SPECIES_OMANYTE,
    SPECIES_KABUTO,
    SPECIES_AERODACTYL,
    SPECIES_ARTICUNO,
    SPECIES_ZAPDOS,
    SPECIES_MOLTRES,
    SPECIES_DRATINI,
    SPECIES_MEWTWO,
    SPECIES_MEW,

    // GEN 2
    SPECIES_CHIKORITA,
    SPECIES_CYNDAQUIL,
    SPECIES_TOTODILE,
    SPECIES_SENTRET,
    SPECIES_HOOTHOOT,
    SPECIES_LEDYBA,
    SPECIES_SPINARAK,
    SPECIES_CHINCHOU,
    SPECIES_PICHU,
    SPECIES_CLEFFA,
    SPECIES_IGGLYBUFF,
    SPECIES_TOGEPI,
    SPECIES_NATU,
    SPECIES_MAREEP,
    SPECIES_HOPPIP,
    SPECIES_AIPOM,
    SPECIES_SUNKERN,
    SPECIES_YANMA,
    SPECIES_WOOPER,
    SPECIES_MURKROW,
    SPECIES_MISDREAVUS,
    SPECIES_UNOWN,
    SPECIES_GIRAFARIG,
    SPECIES_PINECO,
    SPECIES_DUNSPARCE,
    SPECIES_GLIGAR,
    SPECIES_SNUBBULL,
    SPECIES_QWILFISH,
    SPECIES_SHUCKLE,
    SPECIES_HERACROSS,
    SPECIES_SNEASEL,
    SPECIES_TEDDIURSA,
    SPECIES_SLUGMA,
    SPECIES_SWINUB,
    SPECIES_CORSOLA,
    SPECIES_REMORAID,
    SPECIES_DELIBIRD,
    SPECIES_SKARMORY,
    SPECIES_HOUNDOUR,
    SPECIES_PHANPY,
    SPECIES_STANTLER,
    SPECIES_SMEARGLE,
    SPECIES_TYROGUE,
    SPECIES_SMOOCHUM,
    SPECIES_ELEKID,
    SPECIES_MAGBY,
    SPECIES_MILTANK,
    SPECIES_RAIKOU,
    SPECIES_ENTEI,
    SPECIES_SUICUNE,
    SPECIES_LARVITAR,
    SPECIES_LUGIA,
    SPECIES_HO_OH,
    SPECIES_CELEBI,
    // GEN 3
    SPECIES_TREECKO,
    SPECIES_TORCHIC,
    SPECIES_MUDKIP,
    SPECIES_POOCHYENA,
    SPECIES_ZIGZAGOON,
    SPECIES_WURMPLE,
    SPECIES_LOTAD,
    SPECIES_SEEDOT,
    SPECIES_TAILLOW,
    SPECIES_WINGULL,
    SPECIES_RALTS,
    SPECIES_SURSKIT,
    SPECIES_SHROOMISH,
    SPECIES_SLAKOTH,
    SPECIES_NINCADA,
    SPECIES_WHISMUR,
    SPECIES_MAKUHITA,
    SPECIES_AZURILL,
    SPECIES_NOSEPASS,
    SPECIES_SKITTY,
    SPECIES_SABLEYE,
    SPECIES_MAWILE,
    SPECIES_ARON,
    SPECIES_MEDITITE,
    SPECIES_ELECTRIKE,
    SPECIES_PLUSLE,
    SPECIES_MINUN,
    SPECIES_VOLBEAT,
    SPECIES_ILLUMISE,
    SPECIES_GULPIN,
    SPECIES_CARVANHA,
    SPECIES_WAILMER,
    SPECIES_NUMEL,
    SPECIES_TORKOAL,
    SPECIES_SPOINK,
    SPECIES_SPINDA,
    SPECIES_TRAPINCH,
    SPECIES_CACNEA,
    SPECIES_SWABLU,
    SPECIES_ZANGOOSE,
    SPECIES_SEVIPER,
    SPECIES_LUNATONE,
    SPECIES_SOLROCK,
    SPECIES_BARBOACH,
    SPECIES_CORPHISH,
    SPECIES_BALTOY,
    SPECIES_LILEEP,
    SPECIES_ANORITH,
    SPECIES_FEEBAS,
    SPECIES_CASTFORM,
    SPECIES_KECLEON,
    SPECIES_SHUPPET,
    SPECIES_DUSKULL,
    SPECIES_TROPIUS,
    SPECIES_ABSOL,
    SPECIES_WYNAUT,
    SPECIES_SNORUNT,
    SPECIES_SPHEAL,
    SPECIES_CLAMPERL,
    SPECIES_RELICANTH,
    SPECIES_LUVDISC,
    SPECIES_BAGON,
    SPECIES_BELDUM,
    SPECIES_REGIROCK,
    SPECIES_REGICE,
    SPECIES_REGISTEEL,
    SPECIES_LATIAS,
    SPECIES_LATIOS,
    SPECIES_KYOGRE,
    SPECIES_GROUDON,
    SPECIES_RAYQUAZA,
    SPECIES_JIRACHI,
    SPECIES_DEOXYS_NORMAL,
    // GEN 4
    SPECIES_TURTWIG,
    SPECIES_CHIMCHAR,
    SPECIES_PIPLUP,
    SPECIES_STARLY,
    SPECIES_BIDOOF,
    SPECIES_KRICKETOT,
    SPECIES_SHINX,
    SPECIES_BUDEW,
    SPECIES_CRANIDOS,
    SPECIES_SHIELDON,
    SPECIES_BURMY_PLANT,
    SPECIES_COMBEE,
    SPECIES_PACHIRISU,
    SPECIES_BUIZEL,
    SPECIES_CHERUBI,
    SPECIES_SHELLOS_WEST,
    SPECIES_DRIFLOON,
    SPECIES_BUNEARY,
    SPECIES_GLAMEOW,
    SPECIES_CHINGLING,
    SPECIES_STUNKY,
    SPECIES_BRONZOR,
    SPECIES_BONSLY,
    SPECIES_MIME_JR,
    SPECIES_HAPPINY,
    SPECIES_CHATOT,
    SPECIES_SPIRITOMB,
    SPECIES_GIBLE,
    SPECIES_MUNCHLAX,
    SPECIES_RIOLU,
    SPECIES_HIPPOPOTAS,
    SPECIES_SKORUPI,
    SPECIES_CROAGUNK,
    SPECIES_CARNIVINE,
    SPECIES_FINNEON,
    SPECIES_MANTYKE,
    SPECIES_SNOVER,
    SPECIES_ROTOM,
    SPECIES_UXIE,
    SPECIES_MESPRIT,
    SPECIES_AZELF,
    SPECIES_DIALGA,
    SPECIES_PALKIA,
    SPECIES_HEATRAN,
    SPECIES_REGIGIGAS,
    SPECIES_GIRATINA,
    SPECIES_CRESSELIA,
    SPECIES_PHIONE,
    SPECIES_MANAPHY,
    SPECIES_DARKRAI,
    SPECIES_SHAYMIN,
    SPECIES_ARCEUS,
    // GEN 5
    SPECIES_VICTINI,
    SPECIES_SNIVY,
    SPECIES_TEPIG,
    SPECIES_OSHAWOTT,
    SPECIES_PATRAT,
    SPECIES_LILLIPUP,
    SPECIES_PURRLOIN,
    SPECIES_PANSAGE,
    SPECIES_PANSEAR,
    SPECIES_PANPOUR,
    SPECIES_MUNNA,
    SPECIES_PIDOVE,
    SPECIES_BLITZLE,
    SPECIES_ROGGENROLA,
    SPECIES_WOOBAT,
    SPECIES_DRILBUR,
    SPECIES_AUDINO,
    SPECIES_TIMBURR,
    SPECIES_TYMPOLE,
    SPECIES_THROH,
    SPECIES_SAWK,
    SPECIES_SEWADDLE,
    SPECIES_VENIPEDE,
    SPECIES_COTTONEE,
    SPECIES_PETILIL,
    SPECIES_BASCULIN_RED_STRIPED,
    SPECIES_SANDILE,
    SPECIES_DARUMAKA,
    SPECIES_MARACTUS,
    SPECIES_DWEBBLE,
    SPECIES_SCRAGGY,
    SPECIES_SIGILYPH,
    SPECIES_YAMASK,
    SPECIES_TIRTOUGA,
    SPECIES_ARCHEN,
    SPECIES_TRUBBISH,
    SPECIES_ZORUA,
    SPECIES_MINCCINO,
    SPECIES_GOTHITA,
    SPECIES_SOLOSIS,
    SPECIES_DUCKLETT,
    SPECIES_VANILLITE,
    SPECIES_DEERLING_SPRING,
    SPECIES_EMOLGA,
    SPECIES_KARRABLAST,
    SPECIES_FOONGUS,
    SPECIES_FRILLISH,
    SPECIES_ALOMOMOLA,
    SPECIES_JOLTIK,
    SPECIES_FERROSEED,
    SPECIES_KLINK,
    SPECIES_TYNAMO,
    SPECIES_ELGYEM,
    SPECIES_LITWICK,
    SPECIES_AXEW,
    SPECIES_CUBCHOO,
    SPECIES_CRYOGONAL,
    SPECIES_SHELMET,
    SPECIES_STUNFISK,
    SPECIES_MIENFOO,
    SPECIES_DRUDDIGON,
    SPECIES_GOLETT,
    SPECIES_PAWNIARD,
    SPECIES_BOUFFALANT,
    SPECIES_RUFFLET,
    SPECIES_VULLABY,
    SPECIES_HEATMOR,
    SPECIES_DURANT,
    SPECIES_DEINO,
    SPECIES_LARVESTA,
    SPECIES_COBALION,
    SPECIES_TERRAKION,
    SPECIES_VIRIZION,
    SPECIES_TORNADUS,
    SPECIES_THUNDURUS,
    SPECIES_RESHIRAM,
    SPECIES_ZEKROM,
    SPECIES_LANDORUS,
    SPECIES_KYUREM,
    SPECIES_KELDEO,
    SPECIES_MELOETTA,
    SPECIES_GENESECT,
    // GEN 6
    SPECIES_CHESPIN,
    SPECIES_FENNEKIN,
    SPECIES_FROAKIE,
    SPECIES_BUNNELBY,
    SPECIES_FLETCHLING,
    SPECIES_SCATTERBUG_ICY_SNOW,
    SPECIES_LITLEO,
    SPECIES_FLABEBE_RED,
    SPECIES_SKIDDO,
    SPECIES_PANCHAM,
    SPECIES_FURFROU_NATURAL,
    SPECIES_ESPURR,
    SPECIES_HONEDGE,
    SPECIES_SPRITZEE,
    SPECIES_SWIRLIX,
    SPECIES_INKAY,
    SPECIES_BINACLE,
    SPECIES_SKRELP,
    SPECIES_CLAUNCHER,
    SPECIES_HELIOPTILE,
    SPECIES_TYRUNT,
    SPECIES_AMAURA,
    SPECIES_HAWLUCHA,
    SPECIES_DEDENNE,
    SPECIES_CARBINK,
    SPECIES_GOOMY,
    SPECIES_KLEFKI,
    SPECIES_PHANTUMP,
    SPECIES_PUMPKABOO_AVERAGE,
    SPECIES_BERGMITE,
    SPECIES_NOIBAT,
    SPECIES_XERNEAS,
    SPECIES_YVELTAL,
    SPECIES_ZYGARDE,
    SPECIES_DIANCIE,
    SPECIES_HOOPA,
    SPECIES_VOLCANION,
    // GEN 7
    SPECIES_ROWLET,
    SPECIES_LITTEN,
    SPECIES_POPPLIO,
    SPECIES_PIKIPEK,
    SPECIES_YUNGOOS,
    SPECIES_GRUBBIN,
    SPECIES_CRABRAWLER,
    SPECIES_ORICORIO_BAILE,
    SPECIES_CUTIEFLY,
    SPECIES_ROCKRUFF,
    SPECIES_WISHIWASHI,
    SPECIES_MAREANIE,
    SPECIES_MUDBRAY,
    SPECIES_DEWPIDER,
    SPECIES_FOMANTIS,
    SPECIES_MORELULL,
    SPECIES_SALANDIT,
    SPECIES_STUFFUL,
    SPECIES_BOUNSWEET,
    SPECIES_COMFEY,
    SPECIES_ORANGURU,
    SPECIES_PASSIMIAN,
    SPECIES_WIMPOD,
    SPECIES_SANDYGAST,
    SPECIES_PYUKUMUKU,
    SPECIES_TYPE_NULL,
    SPECIES_MINIOR_METEOR_RED,
    SPECIES_KOMALA,
    SPECIES_TURTONATOR,
    SPECIES_TOGEDEMARU,
    SPECIES_MIMIKYU,
    SPECIES_BRUXISH,
    SPECIES_DRAMPA,
    SPECIES_DHELMISE,
    SPECIES_JANGMO_O,
    SPECIES_TAPU_KOKO,
    SPECIES_TAPU_LELE,
    SPECIES_TAPU_BULU,
    SPECIES_TAPU_FINI,
    SPECIES_COSMOG,
    SPECIES_NIHILEGO,
    SPECIES_BUZZWOLE,
    SPECIES_PHEROMOSA,
    SPECIES_XURKITREE,
    SPECIES_CELESTEELA,
    SPECIES_KARTANA,
    SPECIES_GUZZLORD,
    SPECIES_NECROZMA,
    SPECIES_MAGEARNA,
    SPECIES_MARSHADOW,
    SPECIES_POIPOLE,
    SPECIES_STAKATAKA,
    SPECIES_BLACEPHALON,
    SPECIES_ZERAORA,
    SPECIES_MELTAN,
    // GEN 8
    SPECIES_GROOKEY,
    SPECIES_SCORBUNNY,
    SPECIES_SOBBLE,
    SPECIES_SKWOVET,
    SPECIES_ROOKIDEE,
    SPECIES_BLIPBUG,
    SPECIES_NICKIT,
    SPECIES_GOSSIFLEUR,
    SPECIES_WOOLOO,
    SPECIES_CHEWTLE,
    SPECIES_YAMPER,
    SPECIES_ROLYCOLY,
    SPECIES_APPLIN,
    SPECIES_SILICOBRA,
    SPECIES_CRAMORANT,
    SPECIES_ARROKUDA,
    SPECIES_TOXEL,
    SPECIES_SIZZLIPEDE,
    SPECIES_CLOBBOPUS,
    SPECIES_SINISTEA_PHONY,
    SPECIES_HATENNA,
    SPECIES_IMPIDIMP,
    SPECIES_MILCERY,
    SPECIES_FALINKS,
    SPECIES_PINCURCHIN,
    SPECIES_SNOM,
    SPECIES_STONJOURNER,
    SPECIES_EISCUE,
    SPECIES_INDEEDEE_M,
    SPECIES_MORPEKO,
    SPECIES_CUFANT,
    SPECIES_DRACOZOLT,
    SPECIES_ARCTOZOLT,
    SPECIES_DRACOVISH,
    SPECIES_ARCTOVISH,
    SPECIES_DURALUDON,
    SPECIES_DREEPY,
    SPECIES_ZACIAN,
    SPECIES_ZAMAZENTA,
    SPECIES_ETERNATUS,
    SPECIES_KUBFU,
    SPECIES_ZARUDE,
    SPECIES_REGIELEKI,
    SPECIES_REGIDRAGO,
    SPECIES_GLASTRIER,
    SPECIES_SPECTRIER,
    SPECIES_CALYREX,
    SPECIES_ENAMORUS,

    // GEN 9
    SPECIES_SPRIGATITO,
    SPECIES_FUECOCO,
    SPECIES_QUAXLY,
    SPECIES_LECHONK,
    SPECIES_TAROUNTULA,
    SPECIES_NYMBLE,
    SPECIES_PAWMI,
    SPECIES_TANDEMAUS,
    SPECIES_FIDOUGH,
    SPECIES_SMOLIV,
    SPECIES_SQUAWKABILLY_GREEN,
    SPECIES_NACLI,
    SPECIES_CHARCADET,
    SPECIES_TADBULB,
    SPECIES_WATTREL,
    SPECIES_MASCHIFF,
    SPECIES_SHROODLE,
    SPECIES_BRAMBLIN,
    SPECIES_TOEDSCOOL,
    SPECIES_KLAWF,
    SPECIES_CAPSAKID,
    SPECIES_RELLOR,
    SPECIES_FLITTLE,
    SPECIES_TINKATINK,
    SPECIES_WIGLETT,
    SPECIES_BOMBIRDIER,
    SPECIES_FINIZEN,
    SPECIES_VAROOM,
    SPECIES_CYCLIZAR,
    SPECIES_ORTHWORM,
    SPECIES_GLIMMET,
    SPECIES_GREAVARD,
    SPECIES_FLAMIGO,
    SPECIES_CETODDLE,
    SPECIES_VELUZA,
    SPECIES_DONDOZO,
    SPECIES_TATSUGIRI_CURLY,
    SPECIES_GREAT_TUSK,
    SPECIES_SCREAM_TAIL,
    SPECIES_BRUTE_BONNET,
    SPECIES_FLUTTER_MANE,
    SPECIES_SLITHER_WING,
    SPECIES_SANDY_SHOCKS,
    SPECIES_IRON_TREADS,
    SPECIES_IRON_BUNDLE,
    SPECIES_IRON_HANDS,
    SPECIES_IRON_JUGULIS,
    SPECIES_IRON_MOTH,
    SPECIES_IRON_THORNS,
    SPECIES_FRIGIBAX,
    SPECIES_GIMMIGHOUL_CHEST,
    SPECIES_GIMMIGHOUL_ROAMING,
    SPECIES_WO_CHIEN,
    SPECIES_CHIEN_PAO,
    SPECIES_TING_LU,
    SPECIES_CHI_YU,
    SPECIES_ROARING_MOON,
    SPECIES_IRON_VALIANT,
    SPECIES_KORAIDON,
    SPECIES_MIRAIDON,
    SPECIES_WALKING_WAKE,
    SPECIES_IRON_LEAVES,
    SPECIES_POLTCHAGEIST_COUNTERFEIT,
    SPECIES_POLTCHAGEIST_ARTISAN,
    SPECIES_OKIDOGI,
    SPECIES_MUNKIDORI,
    SPECIES_FEZANDIPITI,
    SPECIES_OGERPON,
    SPECIES_GOUGING_FIRE,
    SPECIES_RAGING_BOLT,
    SPECIES_IRON_BOULDER,
    SPECIES_IRON_CROWN,
    SPECIES_TERAPAGOS,
    SPECIES_PECHARUNT,

    // Alternate Forms
    SPECIES_GRENINJA_ASH,
    SPECIES_RATTATA_ALOLA,
    SPECIES_SANDSHREW_ALOLA,
    SPECIES_VULPIX_ALOLA,
    SPECIES_DIGLETT_ALOLA,
    SPECIES_MEOWTH_ALOLA,
    SPECIES_GEODUDE_ALOLA,
    SPECIES_GRIMER_ALOLA,
    SPECIES_MEOWTH_GALAR,
    SPECIES_PONYTA_GALAR,
    SPECIES_SLOWPOKE_GALAR,
    SPECIES_FARFETCHD_GALAR,
    SPECIES_ARTICUNO_GALAR,
    SPECIES_ZAPDOS_GALAR,
    SPECIES_MOLTRES_GALAR,
    SPECIES_DARUMAKA_GALAR,
    SPECIES_YAMASK_GALAR,
    SPECIES_ZORUA_HISUI,
    SPECIES_VOLTORB_HISUI,
    SPECIES_GROWLITHE_HISUI,
    SPECIES_QWILFISH_HISUI,
    SPECIES_SNEASEL_HISUI,
    SPECIES_CORSOLA_GALAR,
    SPECIES_ZIGZAGOON_GALAR,
    SPECIES_TAUROS_PALDEA_COMBAT,
    SPECIES_TAUROS_PALDEA_BLAZE,
    SPECIES_TAUROS_PALDEA_AQUA,
    SPECIES_WOOPER_PALDEA,
    SPECIES_DEOXYS_ATTACK,
    SPECIES_DEOXYS_DEFENSE,
    SPECIES_DEOXYS_SPEED,
    SPECIES_BURMY_SANDY,
    SPECIES_BURMY_TRASH,
    SPECIES_SHELLOS_EAST,
    SPECIES_BASCULIN_BLUE_STRIPED,
    SPECIES_BASCULIN_WHITE_STRIPED,
    SPECIES_DEERLING_SUMMER,
    SPECIES_DEERLING_AUTUMN,
    SPECIES_DEERLING_WINTER,
    SPECIES_STUNFISK_GALAR,
    SPECIES_KYUREM_WHITE,
    SPECIES_KYUREM_BLACK,
    SPECIES_SCATTERBUG_POLAR,
    SPECIES_SCATTERBUG_TUNDRA,
    SPECIES_SCATTERBUG_CONTINENTAL,
    SPECIES_SCATTERBUG_GARDEN,
    SPECIES_SCATTERBUG_ELEGANT,
    SPECIES_SCATTERBUG_MEADOW,
    SPECIES_SCATTERBUG_MODERN,
    SPECIES_SCATTERBUG_MARINE,
    SPECIES_SCATTERBUG_ARCHIPELAGO,
    SPECIES_SCATTERBUG_HIGH_PLAINS,
    SPECIES_SCATTERBUG_SANDSTORM,
    SPECIES_SCATTERBUG_RIVER,
    SPECIES_SCATTERBUG_MONSOON,
    SPECIES_SCATTERBUG_SAVANNA,
    SPECIES_SCATTERBUG_SUN,
    SPECIES_SCATTERBUG_OCEAN,
    SPECIES_SCATTERBUG_JUNGLE,
    SPECIES_SCATTERBUG_FANCY,
    SPECIES_SCATTERBUG_POKEBALL,
    SPECIES_FLABEBE_YELLOW,
    SPECIES_FLABEBE_ORANGE,
    SPECIES_FLABEBE_BLUE,
    SPECIES_FLABEBE_WHITE,
    SPECIES_FLOETTE_ETERNAL,
    SPECIES_FURFROU_HEART,
    SPECIES_FURFROU_STAR,
    SPECIES_FURFROU_DIAMOND,
    SPECIES_FURFROU_DEBUTANTE,
    SPECIES_FURFROU_MATRON,
    SPECIES_FURFROU_DANDY,
    SPECIES_FURFROU_LA_REINE,
    SPECIES_FURFROU_KABUKI,
    SPECIES_FURFROU_PHARAOH,
    SPECIES_PUMPKABOO_SMALL,
    SPECIES_PUMPKABOO_LARGE,
    SPECIES_PUMPKABOO_SUPER,
    SPECIES_ORICORIO_POM_POM,
    SPECIES_ORICORIO_PAU,
    SPECIES_ORICORIO_SENSU,
    SPECIES_ROCKRUFF_OWN_TEMPO,
    SPECIES_MINIOR_METEOR_ORANGE,
    SPECIES_MINIOR_METEOR_YELLOW,
    SPECIES_MINIOR_METEOR_GREEN,
    SPECIES_MINIOR_METEOR_BLUE,
    SPECIES_MINIOR_METEOR_INDIGO,
    SPECIES_MINIOR_METEOR_VIOLET,
    SPECIES_NECROZMA_DUSK_MANE,
    SPECIES_NECROZMA_DAWN_WINGS,
    SPECIES_SINISTEA_ANTIQUE,
    SPECIES_INDEEDEE_F,
    SPECIES_CALYREX_ICE,
    SPECIES_CALYREX_SHADOW,
    SPECIES_SQUAWKABILLY_BLUE,
    SPECIES_SQUAWKABILLY_YELLOW,
    SPECIES_SQUAWKABILLY_WHITE,
    SPECIES_TATSUGIRI_DROOPY,
    SPECIES_TATSUGIRI_STRETCHY,
};

static u16 PickRandomSpecies(void) // picks only base forms
{
    u16 species;
    
    if (FlagGet(FLAG_SYS_GAME_CLEAR) != TRUE)
        species = sLimitedSpecies[Random() % NELEMS(sLimitedSpecies)];
    else
        species = sAllSpecies[Random() % NELEMS(sAllSpecies)];

    return species;
}

static u8 GetWonderTradeOT(u8 *name)
{
    u8 randGender = (Random() % 2); // 0 for male, 1 for female
    u8 numOTNames = 250;
    u8 selectedName = Random() %numOTNames;
    u8 i;
    if (randGender == MALE) // male OT selected
    {
        randGender = 0;
        for (i = 0; i < PLAYER_NAME_LENGTH; ++i)
            name[i] = maleWTNames[selectedName][i];
        name[i] = EOS;
    }
    else                    // female OT selected
    {
        randGender = 0xFF;
        for (i = 0; i < PLAYER_NAME_LENGTH; ++i)
            name[i] = femaleWTNames[selectedName][i];
        name[i] = EOS;
    }
    return randGender;
}

void CreateWonderTradePokemon(void)
{
    u16 wonderTradeSpecies = PickRandomSpecies();
    u8 playerMonLevel = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_LEVEL);
    u8 i;
    u8 chanceToEvolve = Random() % 3;
    u16 wonderTradeItem = ITEM_NONE;
    u8 abilityNum;
    u8 monName[POKEMON_NAME_LENGTH + 1];
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u8 genderOT = GetWonderTradeOT(otName);
    u8 metLocation = METLOC_IN_GAME_TRADE;
    struct WonderTrade sWonderTrades[] =
    {
        [0] = {
            .nickname = _(""),
            .species = wonderTradeSpecies,
            .ivs = {(Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32), (Random() % 32)},
            .abilityNum = (Random() % NUM_NORMAL_ABILITY_SLOTS),
            .otId = 0, // Handled by CreateMon->CreateBoxMon.
            .conditions = {0, 0, 0, 0, 0},
            .personality = 0, // Handled by CreateMon->CreateBoxMon.
            .heldItem = wonderTradeItem,
            .mailNum = -1,
            .otName = _("ERROR"),
            .otGender = FEMALE, // Decided by the personality generated in CreateMon->CreateBoxMon.
            .sheen = 0,
            .requestedSpecies = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES)
        },
    };
    struct WonderTrade *wonderTrade = &sWonderTrades[0];

    if (wonderTradeSpecies == SPECIES_UNOWN)
        wonderTradeSpecies = GetUnownForm();

    // Creates the base of a Pokémon in the first slot of a nonexistent enemy's party.
    CreateMon(&gEnemyParty[0], wonderTradeSpecies, playerMonLevel, USE_RANDOM_IVS, FALSE, 0, OT_ID_PRESET, ((Random() << 16) | Random()));

    for (i = 0; i < chanceToEvolve; i++)
    {
        wonderTradeSpecies = GetWonderTradeEvolutionTargetSpecies(&gEnemyParty[0]);
        SetMonData(&gEnemyParty[0], MON_DATA_SPECIES, &wonderTradeSpecies);
    }

    // 10% chance of giving the incoming Pokémon their HA, if they have one
    if (gSpeciesInfo[wonderTradeSpecies].abilities[2] != ABILITY_NONE && (Random() % 10) == 0)
    {
        abilityNum = 2;
        SetMonData(&gEnemyParty[0], MON_DATA_ABILITY_NUM, &abilityNum);
    }

    wonderTradeItem = GetValidHeldItemForSpecies(wonderTradeSpecies);

    SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &wonderTradeItem);
    SetMonData(&gEnemyParty[0], MON_DATA_HP_IV, &wonderTrade->ivs[0]);
    SetMonData(&gEnemyParty[0], MON_DATA_ATK_IV, &wonderTrade->ivs[1]);
    SetMonData(&gEnemyParty[0], MON_DATA_DEF_IV, &wonderTrade->ivs[2]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPEED_IV, &wonderTrade->ivs[3]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPATK_IV, &wonderTrade->ivs[4]);
    SetMonData(&gEnemyParty[0], MON_DATA_SPDEF_IV, &wonderTrade->ivs[5]);
    StringCopy(monName, GetSpeciesName(wonderTradeSpecies));
    SetMonData(&gEnemyParty[0], MON_DATA_NICKNAME, monName);
    SetMonData(&gEnemyParty[0], MON_DATA_OT_NAME, otName);
    SetMonData(&gEnemyParty[0], MON_DATA_BEAUTY, &wonderTrade->conditions[1]);
    SetMonData(&gEnemyParty[0], MON_DATA_CUTE, &wonderTrade->conditions[2]);
    SetMonData(&gEnemyParty[0], MON_DATA_COOL, &wonderTrade->conditions[0]);
    SetMonData(&gEnemyParty[0], MON_DATA_SMART, &wonderTrade->conditions[3]);
    SetMonData(&gEnemyParty[0], MON_DATA_TOUGH, &wonderTrade->conditions[4]);
    SetMonData(&gEnemyParty[0], MON_DATA_SHEEN, &wonderTrade->sheen);
    SetMonData(&gEnemyParty[0], MON_DATA_OT_GENDER, &genderOT);
    SetMonData(&gEnemyParty[0], MON_DATA_MET_LOCATION, &metLocation);
    CalculateMonStats(&gEnemyParty[0]);
}

static u16 GetUnownForm(void)
{
    u16 unownLetter = SPECIES_UNOWN;

    switch (Random() % 28)
    {
    case 1:
        unownLetter = SPECIES_UNOWN_B;
        break;
    case 2:
        unownLetter = SPECIES_UNOWN_C;
        break;
    case 3:
        unownLetter = SPECIES_UNOWN_D;
        break;
    case 4:
        unownLetter = SPECIES_UNOWN_E;
        break;
    case 5:
        unownLetter = SPECIES_UNOWN_F;
        break;
    case 6:
        unownLetter = SPECIES_UNOWN_G;
        break;
    case 7:
        unownLetter = SPECIES_UNOWN_H;
        break;
    case 8:
        unownLetter = SPECIES_UNOWN_I;
        break;
    case 9:
        unownLetter = SPECIES_UNOWN_J;
        break;
    case 10:
        unownLetter = SPECIES_UNOWN_K;
        break;
    case 11:
        unownLetter = SPECIES_UNOWN_L;
        break;
    case 12:
        unownLetter = SPECIES_UNOWN_M;
        break;
    case 13:
        unownLetter = SPECIES_UNOWN_N;
        break;
    case 14:
        unownLetter = SPECIES_UNOWN_O;
        break;
    case 15:
        unownLetter = SPECIES_UNOWN_P;
        break;
    case 16:
        unownLetter = SPECIES_UNOWN_Q;
        break;
    case 17:
        unownLetter = SPECIES_UNOWN_R;
        break;
    case 18:
        unownLetter = SPECIES_UNOWN_S;
        break;
    case 19:
        unownLetter = SPECIES_UNOWN_T;
        break;
    case 20:
        unownLetter = SPECIES_UNOWN_U;
        break;
    case 21:
        unownLetter = SPECIES_UNOWN_V;
        break;
    case 22:
        unownLetter = SPECIES_UNOWN_W;
        break;
    case 23:
        unownLetter = SPECIES_UNOWN_X;
        break;
    case 24:
        unownLetter = SPECIES_UNOWN_Y;
        break;
    case 25:
        unownLetter = SPECIES_UNOWN_Z;
        break;
    case 26:
        unownLetter = SPECIES_UNOWN_EXCLAMATION;
        break;
    case 27:
        unownLetter = SPECIES_UNOWN_QUESTION;
        break;
    default:
        break;
    }

    return unownLetter;
}

static u16 GetWonderTradeEvolutionTargetSpecies(struct Pokemon *mon)
{
    int i = 0;
    u16 partnerSpecies = GetMonData(mon, MON_DATA_SPECIES);
    u16 targetSpecies = partnerSpecies;
    u32 partnerPersonality = GetMonData(mon, MON_DATA_PERSONALITY);
    u16 upperPersonality = partnerPersonality >> 16;
    u8 partnerLevel = GetMonData(mon, MON_DATA_LEVEL);
    u16 playerPartySpecies = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
    const struct Evolution *evolutions = GetSpeciesEvolutions(partnerSpecies);

    switch (evolutions[0].method)
    {
    case EVO_FRIENDSHIP:
        switch (partnerSpecies)
        {
        case SPECIES_PICHU:
        case SPECIES_CLEFFA:
        case SPECIES_IGGLYBUFF:
        case SPECIES_AZURILL:
            if (partnerLevel >= 16)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_TOGEPI:
        case SPECIES_WOOBAT:
            if (partnerLevel >= 22)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_BUNEARY:
        case SPECIES_MEOWTH_ALOLA:
            if (partnerLevel >= 28)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_GOLBAT:
        case SPECIES_CHANSEY:
        case SPECIES_MUNCHLAX:
        case SPECIES_SWADLOON:
            if (partnerLevel >= 37)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_TYPE_NULL:
            if (partnerLevel >= 48)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        }
        break;
    case EVO_FRIENDSHIP_DAY:
        switch (partnerSpecies)
        {
        case SPECIES_BUDEW:
            if (partnerLevel >= 16)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_RIOLU:
            if (partnerLevel >= 25)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        }
        break;
    case EVO_FRIENDSHIP_NIGHT:
        if (partnerLevel >= 27)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_LEVEL:
        if (partnerLevel >= evolutions[0].param)
        {
            switch (partnerSpecies)
            {
            case SPECIES_SLOWPOKE:
            case SPECIES_CUBONE:
            case SPECIES_KOFFING:
            case SPECIES_QUILAVA:
            case SPECIES_KIRLIA:
            case SPECIES_SNORUNT:
            case SPECIES_DEWOTT:
            case SPECIES_RUFFLET:
            case SPECIES_GOOMY:
            case SPECIES_BERGMITE:
            case SPECIES_DARTRIX:
                if ((Random() % 2) == 0)
                    targetSpecies = evolutions[0].targetSpecies;
                else
                    targetSpecies = evolutions[1].targetSpecies;
                break;
            default:
                targetSpecies = evolutions[0].targetSpecies;
                break;
            }
        }
        break;
    case EVO_TRADE:
    case EVO_TRADE_ITEM:
        if (partnerLevel >= 35)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_ITEM:
        switch (partnerSpecies)
        {
        case SPECIES_SUNKERN:
        case SPECIES_SKITTY:
        case SPECIES_SANDSHREW_ALOLA:
            if (partnerLevel >= 22)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_CLEFAIRY:
        case SPECIES_JIGGLYPUFF:
        case SPECIES_MUNNA:
        case SPECIES_COTTONEE:
        case SPECIES_MINCCINO:
        case SPECIES_HELIOPTILE:
        case SPECIES_VOLTORB_HISUI:
        case SPECIES_ROCKRUFF_OWN_TEMPO:
        case SPECIES_CAPSAKID:
            if (partnerLevel >= 30)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_PANSAGE:
        case SPECIES_PANSEAR:
        case SPECIES_PANPOUR:
        case SPECIES_SINISTEA_PHONY:
        case SPECIES_DARUMAKA_GALAR:
        case SPECIES_SINISTEA_ANTIQUE:
        case SPECIES_TADBULB:
        case SPECIES_POLTCHAGEIST_COUNTERFEIT:
        case SPECIES_POLTCHAGEIST_ARTISAN:
            if (partnerLevel >= 35)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_WEEPINBELL:
        case SPECIES_SHELLDER:
        case SPECIES_STARYU:
        case SPECIES_TOGETIC:
        case SPECIES_MURKROW:
        case SPECIES_MISDREAVUS:
        case SPECIES_LOMBRE:
        case SPECIES_NUZLEAF:
        case SPECIES_ROSELIA:
            if (partnerLevel >= 37)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_NIDORINA:
        case SPECIES_NIDORINO:
        case SPECIES_VULPIX:
        case SPECIES_GROWLITHE:
        case SPECIES_ONIX:
        case SPECIES_EELEKTRIK:
        case SPECIES_LAMPENT:
        case SPECIES_FLOETTE:
        case SPECIES_DOUBLADE:
        case SPECIES_DURALUDON:
        case SPECIES_VULPIX_ALOLA:
        case SPECIES_GROWLITHE_HISUI:
        case SPECIES_CETODDLE:
            if (partnerLevel >= 48)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_PIKACHU:
        case SPECIES_PETILIL:
        case SPECIES_ROCKRUFF:
            if (partnerLevel >= 26)
                targetSpecies = evolutions[(Random() % 2)].targetSpecies;
            break;
        case SPECIES_GLOOM:
        case SPECIES_POLIWHIRL:
        case SPECIES_EXEGGCUTE:
        case SPECIES_SCYTHER:
        case SPECIES_SLOWPOKE_GALAR:
        case SPECIES_CHARCADET:
            if (partnerLevel >= 37)
                targetSpecies = evolutions[(Random() % 2)].targetSpecies;
            break;
        case SPECIES_EEVEE:
            if (partnerLevel >= 25)
                targetSpecies = evolutions[(Random() % 8)].targetSpecies;
            break;
        case SPECIES_APPLIN:
            if (partnerLevel >= 30)
                targetSpecies = evolutions[(Random() % 3)].targetSpecies;
            break;
        }
        break;
    case EVO_LEVEL_ATK_LT_DEF:
        if (partnerLevel >= evolutions[0].param)
        {
            if (GetMonData(mon, MON_DATA_ATK) < GetMonData(mon, MON_DATA_DEF))
                targetSpecies = evolutions[0].targetSpecies;
            else if (GetMonData(mon, MON_DATA_ATK) > GetMonData(mon, MON_DATA_DEF))
                targetSpecies = evolutions[1].targetSpecies;
            else
                targetSpecies = evolutions[2].targetSpecies;
        }
        break;
    case EVO_LEVEL_SILCOON:
        if (partnerLevel >= evolutions[0].param)
        {
            if ((upperPersonality % 10) <= 4)
                targetSpecies = evolutions[0].targetSpecies;
            else
                targetSpecies = evolutions[1].targetSpecies;
        }
        break;
    case EVO_LEVEL_NINJASK:
        if (partnerLevel >= evolutions[0].param)
            targetSpecies = evolutions[(Random() % 2)].targetSpecies;
        break;
    case EVO_BEAUTY:
        if (partnerLevel >= 20)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_LEVEL_FEMALE:
        if (partnerLevel >= evolutions[0].param)
        {
            switch (partnerSpecies)
            {
            case SPECIES_BURMY_PLANT:
            case SPECIES_BURMY_SANDY:
            case SPECIES_BURMY_TRASH:
                if (GetMonGender(mon) == MON_FEMALE)
                    targetSpecies = evolutions[0].targetSpecies;
                else
                    targetSpecies = evolutions[1].targetSpecies;
                break;
            default:
                if (GetMonGender(mon) == MON_FEMALE)
                    targetSpecies = evolutions[0].targetSpecies;
                break;
            }
        }
        break;
    case EVO_LEVEL_MALE:
        if (partnerLevel >= evolutions[0].param)
        {
            if (GetMonGender(mon) == MON_MALE)
                targetSpecies = evolutions[0].targetSpecies;
            else
                targetSpecies = evolutions[1].targetSpecies;
        }
        break;
    case EVO_LEVEL_NIGHT:
        if (partnerLevel >= evolutions[0].param)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_LEVEL_DAY:
        if (partnerLevel >= evolutions[0].param)
        {
            switch (partnerSpecies)
            {
            case SPECIES_COSMOEM:
                targetSpecies = evolutions[(Random() % 2)].targetSpecies;
                break;
            default:
                targetSpecies = evolutions[0].targetSpecies;
                break;
            }
        }
        break;
    case EVO_ITEM_HOLD_DAY:
        switch (partnerSpecies)
        {
        case SPECIES_HAPPINY:
            if (partnerLevel >= 16)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_SNEASEL_HISUI:
            if (partnerLevel >= 37)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_MILCERY:
            if (partnerLevel >= 25)
                targetSpecies = evolutions[(Random() % 14)].targetSpecies;
            break;
        }
        break;
    case EVO_ITEM_HOLD_NIGHT:
        if (partnerLevel >= 37)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_MOVE:
        switch (partnerSpecies)
        {
        case SPECIES_LICKITUNG:
        case SPECIES_TANGELA:
        case SPECIES_YANMA:
        case SPECIES_PILOSWINE:
        case SPECIES_POIPOLE:
            if (partnerLevel >= 33 || MonKnowsMove(mon, evolutions[0].param))
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_MIME_JR:
            if (partnerLevel >= 18 || MonKnowsMove(mon, evolutions[0].param))
            {
                if ((Random() % 2) == 0)
                    targetSpecies = evolutions[0].targetSpecies;
                else
                    targetSpecies = evolutions[1].targetSpecies;
            }
            break;
        case SPECIES_BONSLY:
            if (partnerLevel >= 17 || MonKnowsMove(mon, evolutions[0].param))
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_AIPOM:
        case SPECIES_GIRAFARIG:
            if (partnerLevel >= 32 || MonKnowsMove(mon, evolutions[0].param))
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_QWILFISH_HISUI:
            if (partnerLevel >= 28 || MonKnowsMove(mon, evolutions[0].param))
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_STEENEE:
            if (partnerLevel >= 29 || MonKnowsMove(mon, evolutions[0].param))
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_CLOBBOPUS:
            if (partnerLevel >= 35 || MonKnowsMove(mon, evolutions[0].param))
                targetSpecies = evolutions[0].targetSpecies;
            break;
        }
        break;
    case EVO_MAPSEC:
        switch (partnerSpecies)
        {
        case SPECIES_MAGNETON:
        case SPECIES_NOSEPASS:
            if (partnerLevel >= 48)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        case SPECIES_CHARJABUG:
            if (partnerLevel >= 37)
                targetSpecies = evolutions[0].targetSpecies;
            break;
        }
        break;
    case EVO_LEVEL_RAIN:
        if (partnerLevel >= evolutions[0].param)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_SPECIFIC_MON_IN_PARTY:
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (playerPartySpecies == evolutions[0].param ||
                (evolutions[1].method != EVOLUTIONS_END && playerPartySpecies == evolutions[1].param))
            {
                targetSpecies = evolutions[0].targetSpecies;
                break;
            }
        }
        break;
    case EVO_LEVEL_DARK_TYPE_MON_IN_PARTY:
            if (partnerLevel >= evolutions[0].param)
            
            {
                for (i = 0; i < PARTY_SIZE; i++)
                {
                    u16 currSpecies = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES, NULL);
                    if (gSpeciesInfo[currSpecies].types[0] == TYPE_DARK ||
                        gSpeciesInfo[currSpecies].types[1] == TYPE_DARK)
                    {
                        targetSpecies = evolutions[0].targetSpecies;
                        break;
                    }
                }
            }
            break;
    case EVO_TRADE_SPECIFIC_MON:
    case EVO_SPECIFIC_MAP:
    case EVO_CRITICAL_HITS:
        if (partnerLevel >= 30)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_LEVEL_NATURE_AMPED:
        if (partnerLevel >= evolutions[0].param)
        {
            switch (GetNature(mon))
            {
            case NATURE_HARDY:
            case NATURE_BRAVE:
            case NATURE_ADAMANT:
            case NATURE_NAUGHTY:
            case NATURE_DOCILE:
            case NATURE_IMPISH:
            case NATURE_LAX:
            case NATURE_HASTY:
            case NATURE_JOLLY:
            case NATURE_NAIVE:
            case NATURE_RASH:
            case NATURE_SASSY:
            case NATURE_QUIRKY:
                targetSpecies = evolutions[0].targetSpecies;
                break;
            default:
                targetSpecies = evolutions[1].targetSpecies;
                break;
            }
        }
        break;
    case EVO_SCRIPT_TRIGGER_DMG:
        if (GetMonData(mon, MON_DATA_HP) > evolutions[0].param)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_DARK_SCROLL:
        if (partnerLevel >= 35)
            targetSpecies = evolutions[(Random() % 2)].targetSpecies;
        break;
    case EVO_ITEM_NIGHT:
        if (partnerLevel >= 48)
            targetSpecies = evolutions[(Random() % 2)].targetSpecies;
        break;
    case EVO_MOVE_TWO_SEGMENT:
        if (partnerLevel >= 32 || MonKnowsMove(mon, evolutions[0].param))
        {
            if ((partnerPersonality % 100) != 0)
                targetSpecies = evolutions[0].targetSpecies;
            else
                targetSpecies = evolutions[1].targetSpecies;
        }
        break;
    case EVO_LEVEL_FAMILY_OF_FOUR:
        if (partnerLevel >= evolutions[0].param)
        {
            if ((partnerPersonality % 100) != 0)
                targetSpecies = evolutions[0].targetSpecies;
            else
                targetSpecies = evolutions[1].targetSpecies;
        }
        break;
    case EVO_USE_MOVE_TWENTY_TIMES:
        if (partnerLevel >= 35 || MonKnowsMove(mon, evolutions[0].param))
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_RECOIL_DAMAGE_MALE:
        if (partnerLevel >= 36)
        {
            if (GetMonGender(mon) == MON_MALE)
                targetSpecies = evolutions[0].targetSpecies;
            else
                targetSpecies = evolutions[0].targetSpecies;
        }
        break;
    case EVO_ITEM_COUNT_999:
        if (partnerLevel >= 49)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_DEFEAT_THREE_WITH_ITEM:
        if ((Random() % 3) == 0)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    case EVO_OVERWORLD_STEPS:
        if (partnerLevel >= 37)
            targetSpecies = evolutions[0].targetSpecies;
        break;
    default:
        break;
    }

    return targetSpecies;
}

// Generates an item randomly for a Pokémon received via Wonder Trade to hold, with a few exceptions.
static u16 GetValidHeldItemForSpecies(u16 speciesId)
{
    u16 heldItem = ITEM_NONE;
    u16 baseSpecies = GET_BASE_SPECIES_ID(speciesId);
    u8 rndNum = Random() % 100;
    bool handled = TRUE;
    
    if (rndNum < 75) {
        switch (speciesId) {
        case SPECIES_ARCEUS:
            heldItem = GetArceusPlate();
            break;
        case SPECIES_GENESECT:
            heldItem = GetGenesectDrive();
            break;
        case SPECIES_ORICORIO:
            heldItem = GetOricorioNectar();
            break;
        case SPECIES_SILVALLY:
            heldItem = GetSilvallyMemory();
            break;
        case SPECIES_CHARMANDER:
        case SPECIES_CHARMELEON:
        case SPECIES_CHARIZARD:
        case SPECIES_SQUIRTLE:
        case SPECIES_WARTORTLE:
        case SPECIES_BLASTOISE:
        case SPECIES_WEEDLE:
        case SPECIES_KAKUNA:
        case SPECIES_BEEDRILL:
        case SPECIES_PIDGEY:
        case SPECIES_PIDGEOTTO:
        case SPECIES_PIDGEOT:
        case SPECIES_ABRA:
        case SPECIES_KADABRA:
        case SPECIES_ALAKAZAM:
        case SPECIES_SLOWPOKE:
        case SPECIES_SLOWBRO:
        case SPECIES_PINSIR:
        case SPECIES_AERODACTYL:
        case SPECIES_LARVITAR:
        case SPECIES_PUPITAR:
        case SPECIES_TYRANITAR:
        case SPECIES_TREECKO:
        case SPECIES_GROVYLE:
        case SPECIES_SCEPTILE:
        case SPECIES_TORCHIC:
        case SPECIES_COMBUSKEN:
        case SPECIES_BLAZIKEN:
        case SPECIES_MUDKIP:
        case SPECIES_MARSHTOMP:
        case SPECIES_SWAMPERT:
        case SPECIES_MAWILE:
        case SPECIES_MEDITITE:
        case SPECIES_MEDICHAM:
        case SPECIES_ELECTRIKE:
        case SPECIES_MANECTRIC:
        case SPECIES_BAGON:
        case SPECIES_SHELGON:
        case SPECIES_SALAMENCE:
        case SPECIES_LATIAS:
        case SPECIES_LATIOS:
        case SPECIES_BUNEARY:
        case SPECIES_LOPUNNY:
        case SPECIES_DIANCIE:
            heldItem = GetMegaStoneForSpecies(speciesId);
            break;
        case SPECIES_GREAT_TUSK:
        case SPECIES_SCREAM_TAIL:
        case SPECIES_BRUTE_BONNET:
        case SPECIES_FLUTTER_MANE:
        case SPECIES_SLITHER_WING:
        case SPECIES_SANDY_SHOCKS:
        case SPECIES_IRON_TREADS:
        case SPECIES_IRON_BUNDLE:
        case SPECIES_IRON_HANDS:
        case SPECIES_IRON_JUGULIS:
        case SPECIES_IRON_MOTH:
        case SPECIES_IRON_THORNS:
        case SPECIES_ROARING_MOON:
        case SPECIES_IRON_VALIANT:
        case SPECIES_WALKING_WAKE:
        case SPECIES_IRON_LEAVES:
        case SPECIES_GOUGING_FIRE:
        case SPECIES_RAGING_BOLT:
        case SPECIES_IRON_BOULDER:
        case SPECIES_IRON_CROWN:
            heldItem = ITEM_BOOSTER_ENERGY;
            break;
        case SPECIES_OGERPON:
            switch (Random() % 3) {
            case 0:
                heldItem = ITEM_CORNERSTONE_MASK;
                break;
            case 1:
                heldItem = ITEM_WELLSPRING_MASK;
                break;
            case 2:
                heldItem = ITEM_HEARTHFLAME_MASK;
                break;
            default:
                heldItem = GetRandomItem();
                break;
            }
        default:
            handled = FALSE;
            break;
        }
    }
    
    // 50% chance of getting species-specific items.
    if (!handled && rndNum < 50) {
        switch (baseSpecies) {
        case SPECIES_FARFETCHD:
        case SPECIES_SIRFETCHD:
            heldItem = ITEM_LEEK;
            break;
        case SPECIES_PIKACHU:
            heldItem = ITEM_LIGHT_BALL;
            break;
        case SPECIES_CHANSEY:
            heldItem = ITEM_LUCKY_PUNCH;
            break;
        case SPECIES_DITTO:
            if ((Random() % 2) == 0)
                heldItem = ITEM_METAL_POWDER;
            else
                heldItem = ITEM_QUICK_POWDER;
            break;
        case SPECIES_CUBONE:
        case SPECIES_MAROWAK:
            heldItem = ITEM_THICK_CLUB;
            break;
        case SPECIES_MEWTWO:
            heldItem = ITEM_BERSERK_GENE;
            break;
        case SPECIES_CLAMPERL:
            if ((Random() % 2) == 0)
                heldItem = ITEM_DEEP_SEA_TOOTH;
            else
                heldItem = ITEM_DEEP_SEA_SCALE;
            break;
        case SPECIES_LATIAS:
        case SPECIES_LATIOS:
            heldItem = ITEM_SOUL_DEW;
            break;
        case SPECIES_DIALGA:
            if ((Random() % 2) == 0)
                heldItem = ITEM_ADAMANT_ORB;
            else
                heldItem = ITEM_ADAMANT_CRYSTAL;
            break;
        case SPECIES_PALKIA:
            if ((Random() % 2) == 0)
                heldItem = ITEM_LUSTROUS_ORB;
            else
                heldItem = ITEM_LUSTROUS_GLOBE;
            break;
        case SPECIES_GIRATINA:
            if ((Random() % 2) == 0)
                heldItem = ITEM_GRISEOUS_ORB;
            else
                heldItem = ITEM_GRISEOUS_CORE;
            break;
        case SPECIES_ZACIAN:
            heldItem = ITEM_RUSTED_SWORD;
            break;
        case SPECIES_ZAMAZENTA:
            heldItem = ITEM_RUSTED_SHIELD;
            break;
        default:
            handled = FALSE;
            break;
        }
    }
    // 50% chance of getting special evolution items.
    if (!handled && rndNum < 50) {
        switch (speciesId) {
        case SPECIES_PORYGON:
            heldItem = ITEM_UP_GRADE;
            break;
        case SPECIES_PORYGON2:
            heldItem = ITEM_DUBIOUS_DISC;
            break;
        case SPECIES_RHYHORN:
        case SPECIES_RHYDON:
            heldItem = ITEM_PROTECTOR;
            break;
        case SPECIES_ELEKID:
        case SPECIES_ELECTABUZZ:
            heldItem = ITEM_ELECTIRIZER;
            break;
        case SPECIES_MAGBY:
        case SPECIES_MAGMAR:
            heldItem = ITEM_MAGMARIZER;
            break;
        case SPECIES_HAPPINY:
            heldItem = ITEM_OVAL_STONE;
            break;
        case SPECIES_DUSKULL:
        case SPECIES_DUSCLOPS:
            heldItem = ITEM_REAPER_CLOTH;
            break;
        case SPECIES_SPRITZEE:
            heldItem = ITEM_SACHET;
            break;
        case SPECIES_SWIRLIX:
            heldItem = ITEM_WHIPPED_DREAM;
            break;
        case SPECIES_SLOWPOKE_GALAR:
            if ((Random() % 2) == 0)
                heldItem = ITEM_GALARICA_CUFF;
            else
                heldItem = ITEM_GALARICA_WREATH;
            break;
        case SPECIES_TEDDIURSA:
        case SPECIES_URSARING:
            heldItem = ITEM_PEAT_BLOCK;
            break;
        case SPECIES_POLTCHAGEIST_COUNTERFEIT:
            heldItem = ITEM_UNREMARKABLE_TEACUP;
            break;
        case SPECIES_DURALUDON:
            heldItem = ITEM_METAL_ALLOY;
            break;
        default:
            handled = FALSE;
            break;
        }
    }

    // Guaranteed species-specific items or a random heldItem.
    if (!handled) {
        switch (speciesId) {
        case SPECIES_SINISTEA_ANTIQUE:
            heldItem = ITEM_CHIPPED_POT;
            break;
        case SPECIES_POLTCHAGEIST_ARTISAN:
            heldItem = ITEM_MASTERPIECE_TEACUP;
            break;
        default:
            heldItem = GetRandomItem();
            break;
        }
    }

    return heldItem;
}

static u16 GetMegaStoneForSpecies(u16 speciesId)
{
    u16 heldItem;

    switch (speciesId) {
    case SPECIES_CHARMANDER:
    case SPECIES_CHARMELEON:
    case SPECIES_CHARIZARD:
        if ((Random() % 2) == 0)
            heldItem = ITEM_CHARIZARDITE_X;
        else
            heldItem = ITEM_CHARIZARDITE_Y;
        break;
    case SPECIES_SQUIRTLE:
    case SPECIES_WARTORTLE:
    case SPECIES_BLASTOISE:
        heldItem = ITEM_BLASTOISINITE;
        break;
    case SPECIES_WEEDLE:
    case SPECIES_KAKUNA:
    case SPECIES_BEEDRILL:
        heldItem = ITEM_BEEDRILLITE;
        break;
    case SPECIES_PIDGEY:
    case SPECIES_PIDGEOTTO:
    case SPECIES_PIDGEOT:
        heldItem = ITEM_PIDGEOTITE;
        break;
    case SPECIES_ABRA:
    case SPECIES_KADABRA:
    case SPECIES_ALAKAZAM:
        heldItem = ITEM_ALAKAZITE;
        break;
    case SPECIES_SLOWPOKE:
    case SPECIES_SLOWBRO:
        heldItem = ITEM_SLOWBRONITE;
        break;
    case SPECIES_PINSIR:
        heldItem = ITEM_PINSIRITE;
        break;
    case SPECIES_AERODACTYL:
        heldItem = ITEM_AERODACTYLITE;
        break;
    case SPECIES_MEWTWO:
        if ((Random() % 2) == 0)
            heldItem = ITEM_MEWTWONITE_X;
        else
            heldItem = ITEM_MEWTWONITE_Y;
        break;
    case SPECIES_LARVITAR:
    case SPECIES_PUPITAR:
    case SPECIES_TYRANITAR:
        heldItem = ITEM_TYRANITARITE;
        break;
    case SPECIES_TREECKO:
    case SPECIES_GROVYLE:
    case SPECIES_SCEPTILE:
        heldItem = ITEM_SCEPTILITE;
        break;
    case SPECIES_TORCHIC:
    case SPECIES_COMBUSKEN:
    case SPECIES_BLAZIKEN:
        heldItem = ITEM_BLAZIKENITE;
        break;
    case SPECIES_MUDKIP:
    case SPECIES_MARSHTOMP:
    case SPECIES_SWAMPERT:
        heldItem = ITEM_SWAMPERTITE;
        break;
    case SPECIES_MAWILE:
        heldItem = ITEM_MAWILITE;
        break;
    case SPECIES_MEDITITE:
    case SPECIES_MEDICHAM:
        heldItem = ITEM_MEDICHAMITE;
        break;
    case SPECIES_ELECTRIKE:
    case SPECIES_MANECTRIC:
        heldItem = ITEM_MANECTITE;
        break;
    case SPECIES_BAGON:
    case SPECIES_SHELGON:
    case SPECIES_SALAMENCE:
        heldItem = ITEM_SALAMENCITE;
        break;
    case SPECIES_LATIAS:
        heldItem = ITEM_LATIASITE;
        break;
    case SPECIES_LATIOS:
        heldItem = ITEM_LATIOSITE;
        break;
    case SPECIES_BUNEARY:
    case SPECIES_LOPUNNY:
        heldItem = ITEM_LOPUNNITE;
        break;
    case SPECIES_DIANCIE:
        heldItem = ITEM_DIANCITE;
        break;
    default:
        heldItem = GetRandomItem();
        break;
    }

    return heldItem;
}

static u16 GetArceusPlate(void)
{
    u16 heldItem;

    switch (Random() % 17)
    {
        case 0:
            heldItem = ITEM_FLAME_PLATE;
            break;
        case 1:
            heldItem = ITEM_SPLASH_PLATE;
            break;
        case 2:
            heldItem = ITEM_ZAP_PLATE;
            break;
        case 3:
            heldItem = ITEM_MEADOW_PLATE;
            break;
        case 4:
            heldItem = ITEM_ICICLE_PLATE;
            break;
        case 5:
            heldItem = ITEM_FIST_PLATE;
            break;
        case 6:
            heldItem = ITEM_TOXIC_PLATE;
            break;
        case 7:
            heldItem = ITEM_EARTH_PLATE;
            break;
        case 8:
            heldItem = ITEM_SKY_PLATE;
            break;
        case 9:
            heldItem = ITEM_MIND_PLATE;
            break;
        case 10:
            heldItem = ITEM_INSECT_PLATE;
            break;
        case 11:
            heldItem = ITEM_STONE_PLATE;
            break;
        case 12:
            heldItem = ITEM_SPOOKY_PLATE;
            break;
        case 13:
            heldItem = ITEM_DRACO_PLATE;
            break;
        case 14:
            heldItem = ITEM_DREAD_PLATE;
            break;
        case 15:
            heldItem = ITEM_IRON_PLATE;
            break;
        case 16:
            heldItem = ITEM_PIXIE_PLATE;
            break;
        default:
            heldItem = GetRandomItem();
            break;
    }

    return heldItem;
}

static u16 GetGenesectDrive(void)
{
    u16 heldItem;

    switch (Random() % 4)
    {
        case 0:
            heldItem = ITEM_DOUSE_DRIVE;
            break;
        case 1:
            heldItem = ITEM_BURN_DRIVE;
            break;
        case 2:
            heldItem = ITEM_SHOCK_DRIVE;
            break;
        case 3:
            heldItem = ITEM_CHILL_DRIVE;
            break;
        default:
            heldItem = GetRandomItem();
            break;
    }

    return heldItem;
}

static u16 GetOricorioNectar(void)
{
    u16 heldItem;

    switch (Random() % 4)
    {
        case 0:
            heldItem = ITEM_RED_NECTAR;
            break;
        case 1:
            heldItem = ITEM_YELLOW_NECTAR;
            break;
        case 2:
            heldItem = ITEM_PINK_NECTAR;
            break;
        case 3:
            heldItem = ITEM_PURPLE_NECTAR;
            break;
        default:
            heldItem = GetRandomItem();
            break;
    }

    return heldItem;
}

static u16 GetSilvallyMemory(void)
{
    u16 heldItem;

    switch (Random() % 17)
    {
        case 0:
            heldItem = ITEM_FIRE_MEMORY;
            break;
        case 1:
            heldItem = ITEM_WATER_MEMORY;
            break;
        case 2:
            heldItem = ITEM_ELECTRIC_MEMORY;
            break;
        case 3:
            heldItem = ITEM_GRASS_MEMORY;
            break;
        case 4:
            heldItem = ITEM_ICE_MEMORY;
            break;
        case 5:
            heldItem = ITEM_FIGHTING_MEMORY;
            break;
        case 6:
            heldItem = ITEM_POISON_MEMORY;
            break;
        case 7:
            heldItem = ITEM_GROUND_MEMORY;
            break;
        case 8:
            heldItem = ITEM_FLYING_MEMORY;
            break;
        case 9:
            heldItem = ITEM_PSYCHIC_MEMORY;
            break;
        case 10:
            heldItem = ITEM_BUG_MEMORY;
            break;
        case 11:
            heldItem = ITEM_ROCK_MEMORY;
            break;
        case 12:
            heldItem = ITEM_GHOST_MEMORY;
            break;
        case 13:
            heldItem = ITEM_DRAGON_MEMORY;
            break;
        case 14:
            heldItem = ITEM_DARK_MEMORY;
            break;
        case 15:
            heldItem = ITEM_STEEL_MEMORY;
            break;
        case 16:
            heldItem = ITEM_FAIRY_MEMORY;
            break;
        default:
            heldItem = GetRandomItem();
    }

    return heldItem;
}

static u16 GetRandomItem(void)
{
    u16 heldItem;

    switch (Random() % 8)
    {
        case 0: // Poké Balls
            heldItem = (Random() % ((ITEM_CHERISH_BALL - ITEM_POKE_BALL) + 1)) + ITEM_POKE_BALL;
            break;
        case 1: // Medicine
            heldItem = (Random() % ((ITEM_BIG_MALASADA - ITEM_POTION) + 1)) + ITEM_POTION;
            break;
        case 2: // Stat Change
            heldItem = (Random() % ((ITEM_EXP_CANDY_XL - ITEM_ABILITY_CAPSULE) + 1)) + ITEM_ABILITY_CAPSULE;
            break;
        case 3: // Battle Items
            heldItem = (Random() % ((ITEM_MAX_MUSHROOMS - ITEM_X_ATTACK) + 1)) + ITEM_X_ATTACK;
            break;
        case 4: // Treasures
            heldItem = (Random() % ((ITEM_TINY_BAMBOO_SHOOT - ITEM_BOTTLE_CAP) + 1)) + ITEM_BOTTLE_CAP;
            break;
        case 5: // Gems
            heldItem = (Random() % ((ITEM_FAIRY_GEM - ITEM_NORMAL_GEM) + 1)) + ITEM_NORMAL_GEM;
            break;
        case 6: // Misc Items
            heldItem = (Random() % ((ITEM_MIRROR_HERB - ITEM_BRIGHT_POWDER) + 1)) + ITEM_BRIGHT_POWDER;
            break;
        case 7: // Berries
            heldItem = (Random() % ((ITEM_MARANGA_BERRY - ITEM_CHERI_BERRY) + 1)) + ITEM_CHERI_BERRY;
            break;
        default:
            heldItem = ITEM_NONE;
            break;
    }

    return heldItem;
}