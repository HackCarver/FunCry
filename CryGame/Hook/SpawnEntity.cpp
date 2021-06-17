/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "SpawnEntity.h"

class Character{
  public:
    char *fileModel;
    char *Material;
    char *SoundPack;
    char *SOUND_TABLE;
    char *fileHelmetModel;

    ////////////

    Character( char *_fileModel , char *_Material , char *_SoundPack , char *_SOUND_TABLE , char *_fileHelmetModel ) : fileModel( _fileModel ), Material( _Material ), SoundPack( _SoundPack ), SOUND_TABLE( _SOUND_TABLE ), fileHelmetModel( _fileHelmetModel ){ }
};

static bool IsThatYouVal = false;

static std::vector<Character> vEntities_Merc;
static std::vector<Character> vEntities_Story;
static std::vector<Character> vEntities_Story_Valerie;
static std::vector<Character> vEntities_Worker;
static std::vector<std::vector<Character> *> vEntities_Human;

#include "../FunCry/Logging.h"

#include "../GRETA/regexpr2.h"
#include "../GRETA/reimpl2.h"
#include "../GRETA/restack.h"
#include "../GRETA/syntax2.h"

#include "../Utility/Utility.h"

#include "../FunCry/Effect.h"

static bool IsInitialized = false;

static std::vector<const char *> vDropPack;
static std::vector<const char *> vEquiptment;

void hkSpawnEntity::StartupEntities( ){
  FunLog::Log( FUNLOG_ALWAYS , "Begin starting entity module" );

  vEntities_Human.reserve( 4 );
  vEntities_Human.push_back( &vEntities_Merc );
  vEntities_Human.push_back( &vEntities_Story );
  vEntities_Human.push_back( &vEntities_Story_Valerie );
  vEntities_Human.push_back( &vEntities_Worker );

  vEntities_Merc.reserve( 277 );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "" , "coreworkerA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "coreworkerA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite_Avni" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite_Black" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite_Endres" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite_Endres" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite_Endres" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite_Magnus" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite_Magnus" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_elite_Magnus" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI" , "voiceA" , "MERC_SCOUT" , "objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceA" , "MERC_SCOUT" , "objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor_haki.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Endres" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Endres" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Endres" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Endres" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Endres" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Endres" , "voiceA" , "MERC_SCOUT" , "objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Magnus" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Magnus" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Magnus" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Magnus" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Magnus" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Magnus" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Avni" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Avni" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Black" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Black" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Black" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Endres" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Endres" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Endres" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc.cgf" , "Mercenaries.Guard.indoor_merc_normal_Magnus" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "coreworkerA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "coreworkerA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_elite_Endres" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI" , "voiceB" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceB" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Avni" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Endres" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Magnus" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_elite.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Magnus" , "voiceB" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "" , "dialog_template" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "coreworkerA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "coreworkerA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_elite_Avni" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_elite_Black" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_elite_Endres" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_elite_Magnus" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_HAKI" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_HAKI_Black" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_normal_Avni" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/indoor_merc/indoor_merc_shield.cgf" , "Mercenaries.Guard.indoor_merc_normal_Black" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_indoor.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceA" , "MERC_COVER" , "objects/characters/mercenaries/accessories/goggles.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceA" , "MERC_COVER" , "objects/characters/mercenaries/accessories/merc_cover_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceB" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/earprotector.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_cover_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_cover_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/earprotector.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceA" , "MERC_COVER" , "objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_offcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceB" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceB" , "MERC_COVER" , "objects/characters/mercenaries/accessories/goggles.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Andrew" , "voiceC" , "MERC_COVER" , "objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "dialog_template" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/earprotector.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceA" , "MERC_COVER" , "objects/characters/mercenaries/accessories/merc_cover_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceB" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceB" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_cover_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Default" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Default" , "voiceB" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Default" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Default" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_offcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceB" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceB" , "MERC_COVER" , "objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_cover_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/cigarette.dds" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_cover_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Cover.Max" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Scout.Black" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_cover/merc_cover.cgf" , "Mercenaries.Scout.Black" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_DefComm/merc_defcomm.cgf" , "" , "voiceA" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_defcomm/merc_defcomm.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_DefComm/merc_defcomm.cgf" , "" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_DefComm/merc_defcomm.cgf" , "Mercenaries.DeffCommander.Default" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_DefComm/merc_defcomm.cgf" , "Mercenaries.DeffCommander.Max" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_OffComm/merc_offcomm.cgf" , "" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_OffComm/merc_offcomm.cgf" , "Mercenaries.OffCommander.Roman" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "dialog_template" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/earprotector.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_offcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceD" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "" , "voiceD" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Black" , "voiceA" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/earprotector.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Black" , "voiceA" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Black" , "voiceC" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Black" , "voiceD" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Default" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Magnus" , "dialog_template" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Magnus" , "voiceC" , "MERC_COVER" , "objects/characters/mercenaries/accessories/beard.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Magnus" , "voiceC" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Magnus" , "voiceD" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Magnus" , "voiceD" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Max" , "dialog_template" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Max" , "voiceC" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Max" , "voiceC" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_rear/merc_rear.cgf" , "Mercenaries.Rear.Max" , "voiceD" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_scout/merc_scout.cgf" , "" , "dialog_template" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_scout/merc_scout.cgf" , "" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "" , "voiceC" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "" , "voiceD" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "" , "voiceD" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "" , "voiceD" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceD" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceD" , "MERC_SCOUT" , "objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceD" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Black" , "voiceD" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Default" , "dialog_template" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Default" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Yellow" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Yellow" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Yellow" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Yellow" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Yellow" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Yellow" , "voiceD" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Yellow" , "voiceD" , "MERC_SCOUT" , "objects/characters/mercenaries/accessories/helmet_army_camo.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.Yellow" , "voiceD" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_offcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_scout/merc_scout.cgf" , "Mercenaries.Scout.YellowA" , "voiceA" , "MERC_COVER" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.YellowA" , "voiceA" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.YellowA" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_offcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.YellowA" , "voiceA" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.YellowA" , "voiceD" , "MERC_SCOUT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.YellowA" , "voiceD" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/Merc_scout/merc_scout.cgf" , "Mercenaries.Scout.YellowA" , "voiceD" , "MERC_SCOUT" , "Objects/characters/mercenaries/accessories/merc_cover_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "" , "dialog_template" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "" , "dialog_template" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "" , "voiceA" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "" , "voiceA" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "" , "voiceB" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "" , "voiceB" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "" , "voiceB" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "" , "voiceB" , "GRUNT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Guard.indoor_merc_elite" , "voiceA" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Black" , "dialog_template" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Black" , "voiceA" , "MERC_REAR" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Black" , "voiceA" , "MERC_REAR" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Black" , "voiceB" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Black" , "voiceB" , "GRUNT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Bold" , "dialog_template" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Bold" , "voiceB" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Bold" , "voiceB" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_army.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Bold" , "voiceB" , "GRUNT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_sniper/merc_sniper.cgf" , "Mercenaries.Sniper.Default" , "dialog_template" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/helmet_army_black.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "" , "voiceA" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "" , "voiceA" , "GRUNT" , "Objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "" , "voiceB" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "" , "voiceB" , "GRUNT" , "objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "" , "voiceC" , "GRUNT" , "Objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "" , "voiceD" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Scout.Yellow" , "voiceA" , "GRUNT" , "objects/characters/mercenaries/accessories/merc_defcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Scout.Yellow" , "voiceB" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Black" , "voiceA" , "GRUNT" , "Objects/characters/mercenaries/accessories/merc_offcomm_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Black_Endres" , "voiceA" , "GRUNT" , "objects/characters/mercenaries/accessories/merc_rear_hat.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Black_Endres" , "voiceC" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Black_Endres" , "voiceD" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Black_Max" , "voiceD" , "GRUNT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Blue_Max" , "voiceD" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Brown_Max" , "voiceB" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Default" , "voiceA" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Green_Endres" , "voiceB" , "GRUNT" , "Objects/characters/mercenaries/accessories/merc_sniper_glasses.cgf" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Mixed_Avni" , "voiceA" , "GRUNT" , "" ) );
  vEntities_Merc.push_back( Character( "Objects/characters/mercenaries/merc_tshirt/merc_tshirt.cgf" , "Mercenaries.Tshirt.Mixed_Endres" , "voiceB" , "GRUNT" , "Objects/characters/mercenaries/accessories/merc_offcomm_hat.cgf" ) );

  vEntities_Worker.reserve( 17 );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/coretech/coretech.cgf" , "" , "coreworkerA" , "coreworker" , "" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/coretech/coretech.cgf" , "" , "coreworkerD" , "coreworker" , "" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/coretech/coretech.cgf" , "" , "coreworkerD" , "coreworker" , "Objects/characters/mercenaries/accessories/earprotector.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/coretech/coretech.cgf" , "" , "coreworkerD" , "coreworker" , "objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceC" , "GRUNT" , "" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceC" , "GRUNT" , "Objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceC" , "GRUNT" , "Objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceD" , "GRUNT" , "" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceD" , "GRUNT" , "Objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceD" , "GRUNT" , "objects/characters/mercenaries/accessories/earprotector.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceD" , "GRUNT" , "Objects/characters/mercenaries/accessories/evil_worker_hat.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceD" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_nightvis.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "" , "voiceD" , "GRUNT" , "Objects/characters/mercenaries/accessories/helmet_white.cgf" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/evil_worker/evil_worker.cgf" , "Mercenaries.Workers.evil_worker_Dead" , "voiceD" , "GRUNT" , "" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/lab_assitant/lab_assistant.cgf" , "" , "voiceA" , "GRUNT" , "" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/lead_scientist/lead_scientist.cgf" , "" , "voiceD" , "GRUNT" , "" ) );
  vEntities_Worker.push_back( Character( "Objects/characters/workers/lead_scientist/lead_scientist.cgf" , "" , "voiceD" , "GRUNT" , "Objects/characters/workers/lead_scientist/scientist_mask.cgf" ) );

  vEntities_Story.reserve( 3 );
  vEntities_Story.push_back( Character( "Objects/characters/story_characters/krieger_mutant/krieger_mutant.cgf" , "" , "" , "KRIEGER" , "" ) );
  vEntities_Story.push_back( Character( "Objects/characters/story_characters/mertz/mertz_ingame.cgf" , "" , "voiceC" , "MERC_COVER" , "" ) );
  vEntities_Story.push_back( Character( "Objects/characters/story_characters/mertz/mertz_ingame.cgf" , "" , "voiceC" , "MERC_COVER" , "Objects/characters/mercenaries/accessories/player_radio_scanhumans.cgf" ) );

  vEntities_Story_Valerie.reserve( 1 );
  vEntities_Story_Valerie.push_back( Character( "Objects/characters/story_characters/valerie/valeri.cgf" , "" , "Valerie" , "Val" , "" ) );

  vDropPack.reserve( 14 );
  vDropPack.push_back( "none" );
  vDropPack.push_back( "Rear_Drop" );
  vDropPack.push_back( "Falcon_Pickup" );
  vDropPack.push_back( "Rear_Drop_Falcon" );
  vDropPack.push_back( "MP5_pickup" );
  vDropPack.push_back( "Shotgun_Pickup" );
  vDropPack.push_back( "M4_pickup" );
  vDropPack.push_back( "Rear_Drop_M4" );
  vDropPack.push_back( "AG36_pickup" );
  vDropPack.push_back( "OICW_pickup" );
  vDropPack.push_back( "M249_pickup" );
  vDropPack.push_back( "Rear_Drop_M249" );
  vDropPack.push_back( "SniperRifle_Pickup" );
  vDropPack.push_back( "RL_pickup" );

  vEquiptment.reserve( 10 );
  vEquiptment.push_back( "none" );
  vEquiptment.push_back( "Falcon" );
  vEquiptment.push_back( "Mp5" );
  vEquiptment.push_back( "shotgun" );
  vEquiptment.push_back( "M4" );
  vEquiptment.push_back( "AG36" );
  vEquiptment.push_back( "OICW" );
  vEquiptment.push_back( "M249" );
  vEquiptment.push_back( "SniperRifle" );
  vEquiptment.push_back( "RL" );

  IsInitialized = true;

  FunLog::Log( FUNLOG_ALWAYS , "Finish starting entity module" );
}

void hkSpawnEntity::ShutdownEntities( ){
  FunLog::Log( FUNLOG_BASIC , "Stop entity module" );

  vEntities_Merc.clear( );
  vEntities_Story.clear( );
  vEntities_Story_Valerie.clear( );
  vEntities_Worker.clear( );
  vEntities_Human.clear( );

  vDropPack.clear( );
  vEquiptment.clear( );

  IsInitialized = false;
}

void hkSpawnEntity::ProcessEntity( CEntityDesc &ed ){
  static const regex::rpattern_c Regex_Human( "^objects.characters.(mercenaries|story_characters|workers|pmodels)" , regex::NOCASE );
  static regex::rpattern_c::backref_type BackRef;
  static regex::match_results_c          Result;

  if( IsInitialized ){

    unsigned int CID = (unsigned int)ed.ClassId;
    if( CID >= 71 && CID <= 83 ){

      if( ed.pUserData ){
        Character *Target;
        if( IsThatYouVal ){
          Target = &vEntities_Story_Valerie[ Utility::getRandomIndex( vEntities_Story_Valerie.size( ) ) ];
        }
        else{
          std::vector<Character> *vList = vEntities_Human[ Utility::getRandomIndex( vEntities_Human.size( ) ) ];
          Target = &vList->at( Utility::getRandomIndex( vList->size( ) ) );
        }

        XDOM::IXMLDOMNode *pEntity = reinterpret_cast<XDOM::IXMLDOMNode *>( ed.pUserData );
        bool CanModify = false;

        XDOM::IXMLDOMNodeListPtr pPropertiesList = pEntity->getElementsByTagName( "Properties" );
        if( pPropertiesList ){
          pPropertiesList->reset( );
          XDOM::IXMLDOMNodePtr pItem = pPropertiesList->nextNode( );
          if( pItem ){
            XDOM::IXMLDOMNode *pTemp = pItem->getAttribute( "fileModel" );
            if( pTemp ){
              BackRef = Regex_Human.match( pTemp->getText( ) , Result );
              if( BackRef.matched ){
                CanModify = true;

                if( Effects::IsAICharacterRandomizer ){
                  pTemp->setText( Target->fileModel );
                }
              }
            }

            if( CanModify ){
              if( Effects::IsAICharacterRandomizer ){
                pTemp = pItem->getAttribute( "SoundPack" );
                if( pTemp ){
                  pTemp->setText( Target->SoundPack );
                }

                pTemp = pItem->getAttribute( "SOUND_TABLE" );
                if( pTemp ){
                  pTemp->setText( Target->SOUND_TABLE );
                }
              }

              if( Effects::IsAIWeaponRandomizer ){
                if( !Effects::IsAIWeaponDropOriginal ){
                  pTemp = pItem->getAttribute( "equipDropPack" );
                  if( pTemp ){
                    pTemp->setText( vDropPack[ Utility::getRandomIndex( vDropPack.size( ) ) ] );
                  }
                }

                pTemp = pItem->getAttribute( "equipEquipment" );
                if( pTemp ){
                  pTemp->setText( vEquiptment[ Utility::getRandomIndex( vEquiptment.size( ) ) ] );
                }
              }
            }
          }
        }

        if( CanModify && Effects::IsAICharacterRandomizer ){
          XDOM::IXMLDOMNode *pMaterial = pEntity->getAttribute( "Material" );
          if( pMaterial ){
            pMaterial->setText( Target->Material );
          }

          XDOM::IXMLDOMNodeListPtr pPropertiesList2 = pEntity->getElementsByTagName( "Properties2" );
          if( pPropertiesList2 ){
            pPropertiesList2->reset( );
            XDOM::IXMLDOMNodePtr pItem2 = pPropertiesList2->nextNode( );
            if( pItem2 ){
              XDOM::IXMLDOMNode *pTemp2 = pItem2->getAttribute( "fileHelmetModel" );
              if( pTemp2 ){
                pTemp2->setText( Target->fileHelmetModel );
              }
            }
          }
        }

      }
    }
    else if(
      Effects::IsInGameCutSceneRandomizer
      &&
      CID == 130
    ){
      if( ed.pUserData ){
        ed.angles = Vec3( -360 , -360 , -360 );
      }
    }
  }
}
