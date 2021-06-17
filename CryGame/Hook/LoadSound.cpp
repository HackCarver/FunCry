/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "../CryGame/StdAfx.h"

#include "LoadSound.h"

#include "../FunCry/Effect.h"

#include "../Utility/Utility.h"
#include "../FunCry/Logging.h"

struct LanguagesSoundDetail{
  const char *path;
  const float duration;
  const bool stereo;
  const int chat;
  const int radio;
};

static const unsigned int aLanguagesLength = 3714;
static const LanguagesSoundDetail aLanguages[ aLanguagesLength ] = {
  { "languages\\voicepacks\\jack\\silence1.wav" , 0.009977f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\silence2.wav" , 0.009977f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\silence3.wav" , 0.009977f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\silence4.wav" , 0.009977f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\silence5.wav" , 0.009977f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_f_1silence.wav" , 0.100000f , false , 0 , -1 },
  { "languages\\missiontalk\\swamp\\radio_fx_in.wav" , 0.116054f , false , -1 , 0 },
  { "languages\\voicepacks\\coreworkerd\\idle_alone_sniffle_1_voiced.wav" , 0.140816f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8g.wav" , 0.177052f , false , 1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_alone_2_voicea.wav" , 0.185760f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\radio_fx_out.wav" , 0.207528f , false , -1 , 1 },
  { "languages\\voicepacks\\voicea\\yell_attention_1_voicea.wav" , 0.214739f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_10_voiced.wav" , 0.214785f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_10_voicea.wav" , 0.216916f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_6_voicea.wav" , 0.223447f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_alone_8_voicea.wav" , 0.223447f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_alone_1_voicea.wav" , 0.229252f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\yell_attention_2_voicea.wav" , 0.233605f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8i.wav" , 0.233946f , false , 2 , -1 },
  { "languages\\voicepacks\\voicea\\yell_attention_5_voicea.wav" , 0.235057f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\yell_attention_3_voicea.wav" , 0.236508f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_2_voicea.wav" , 0.239410f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_i_8.wav" , 0.241814f , false , 3 , -1 },
  { "languages\\voicepacks\\val\\pain_8.wav" , 0.247120f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_l_6.wav" , 0.253288f , false , 4 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_8_voicea.wav" , 0.257007f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_5_voicea.wav" , 0.259728f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_1_voicea.wav" , 0.261088f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_generic_1r_voicea.wav" , 0.261224f , true , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_generic_1_voicea.wav" , 0.261224f , true , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_7.wav" , 0.261270f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alarm_alone_1_voicea.wav" , 0.264082f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_13_voicea.wav" , 0.264082f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_11_voicea.wav" , 0.272063f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_alone_8_voicec.wav" , 0.275692f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_alone_4_voicec.wav" , 0.278050f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_4_voicec.wav" , 0.282812f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8h.wav" , 0.283832f , false , 5 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_20_voicec.wav" , 0.284354f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_alone_8_voiced.wav" , 0.285896f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_alone_4_voicea.wav" , 0.290204f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_g_2.wav" , 0.290295f , false , 6 , -1 },
  { "languages\\voicepacks\\voicec\\pain_2_voicec.wav" , 0.291973f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_1_voicec.wav" , 0.292744f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\yell_attention_4_voicea.wav" , 0.293107f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\yell_fear_5_voicea.wav" , 0.293107f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_alone_2_voicec.wav" , 0.294104f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_g_2.wav" , 0.295828f , false , 7 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_g_2.wav" , 0.295828f , false , 8 , -1 },
  { "languages\\voicepacks\\val\\pain_2.wav" , 0.298413f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_f_2.wav" , 0.298912f , false , 9 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alone_spit_1_voicea.wav" , 0.298957f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_19_voicec.wav" , 0.304308f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_attention_1_voiceb.wav" , 0.305079f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_attention_1_voiced.wav" , 0.305079f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_12.wav" , 0.307891f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_3.wav" , 0.309615f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_8_voicea.wav" , 0.310522f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_8_voicec.wav" , 0.310522f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_11.wav" , 0.311701f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_9.wav" , 0.315782f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_alone_2_voiced.wav" , 0.316871f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_16.wav" , 0.318186f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_10.wav" , 0.318231f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_fear_1_voiceb.wav" , 0.318277f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_fear_1_voiced.wav" , 0.318277f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_4_voicea.wav" , 0.322132f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_18_voicea.wav" , 0.322132f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_7_voicec.wav" , 0.322132f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_18.wav" , 0.327664f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_3.wav" , 0.328163f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_17.wav" , 0.330249f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_5_voicec.wav" , 0.330839f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_9_voicec.wav" , 0.331701f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_3_voiceb.wav" , 0.334785f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_13.wav" , 0.335420f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_alone_4_voiced.wav" , 0.336054f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_10_voicec.wav" , 0.337370f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_fear_3_voiceb.wav" , 0.337460f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_fear_3_voicec.wav" , 0.337460f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_fear_3_voiced.wav" , 0.337460f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_5.wav" , 0.337687f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_15.wav" , 0.338866f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_5.wav" , 0.340590f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_24.wav" , 0.341587f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_1_voiceb.wav" , 0.341723f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_e_5.wav" , 0.343129f , false , 10 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_7_voiced.wav" , 0.344671f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_9.wav" , 0.345714f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_12.wav" , 0.345896f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8j.wav" , 0.353492f , false , 11 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_fear_2_voicea.wav" , 0.354104f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alarm_alone_1_voiced.wav" , 0.354376f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_5_voicea.wav" , 0.355601f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_6_voicea.wav" , 0.355601f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_7_voicea.wav" , 0.357007f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_2_alone_voicea.wav" , 0.357778f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_alone_5_voicea.wav" , 0.359320f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_11_voicec.wav" , 0.360181f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_1.wav" , 0.361179f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_8_voiced.wav" , 0.361361f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_group_2_voicea.wav" , 0.362721f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_2_voicec.wav" , 0.364399f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_al_2_voicea.wav" , 0.365714f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_14_voicec.wav" , 0.367710f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_13.wav" , 0.369615f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_15_voicec.wav" , 0.370748f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\yell_fear_3_voicea.wav" , 0.371474f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_14.wav" , 0.371519f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_5_voicec.wav" , 0.376054f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_2_voicea.wav" , 0.377324f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_8_voicea.wav" , 0.377324f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_k_2.wav" , 0.382721f , false , 12 , -1 },
  { "languages\\voicepacks\\voiced\\pain_1_voiced.wav" , 0.385986f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_attention_5_voicea.wav" , 0.386032f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_5_voiced.wav" , 0.386032f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_16.wav" , 0.387120f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_fear_4_voiceb.wav" , 0.387392f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_fear_4_voicec.wav" , 0.387392f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_fear_4_voiced.wav" , 0.387392f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_19_voiced.wav" , 0.387755f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_fear_5_voiced.wav" , 0.388934f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\yell_fear_1_voicea.wav" , 0.391791f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_alone_4_voicea.wav" , 0.393288f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_attention_2_voiceb.wav" , 0.394150f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_attention_2_voicec.wav" , 0.394150f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_attention_2_voiced.wav" , 0.394150f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_3_voicec.wav" , 0.394694f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_g_1.wav" , 0.394739f , false , 13 , -1 },
  { "languages\\missiontalk\\research\\research_generic_d_3.wav" , 0.395420f , false , 14 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alone_sniffle_1_voicea.wav" , 0.396190f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\vehicle_in_7_voicea.wav" , 0.396281f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_al_8_voicea.wav" , 0.399093f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_3_voicea.wav" , 0.399229f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_18.wav" , 0.399592f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_2_voiceb.wav" , 0.400499f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_4_voicea.wav" , 0.401497f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_23.wav" , 0.402494f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_alone_5_voiced.wav" , 0.403039f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_4_voiced.wav" , 0.405624f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_2_voicea.wav" , 0.405714f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_i_2.wav" , 0.405805f , false , 15 , -1 },
  { "languages\\voicepacks\\val\\affirmative_2.wav" , 0.405805f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_5_voiceb.wav" , 0.406531f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_5_voiced.wav" , 0.408617f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_6_voiced.wav" , 0.408617f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_20_voiced.wav" , 0.408617f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_2_voicea.wav" , 0.409252f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_alone_4_voiced.wav" , 0.409252f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_21.wav" , 0.410159f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_19.wav" , 0.411429f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_2_voicea.wav" , 0.412109f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_al_6_voicea.wav" , 0.415057f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_20.wav" , 0.415737f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_7.wav" , 0.416236f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_alone_6_voicea.wav" , 0.416508f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_11_voiced.wav" , 0.416916f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_6_voicec.wav" , 0.417596f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_9_voicea.wav" , 0.417959f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_a_3.wav" , 0.419683f , false , 16 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_alone_2_voicea.wav" , 0.420136f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_11_voicec.wav" , 0.420544f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_3_voiced.wav" , 0.422494f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_pickup_b_4.wav" , 0.423719f , false , 17 , -1 },
  { "languages\\voicepacks\\jack\\pain_24.wav" , 0.426576f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alarm_alone_5_voicea.wav" , 0.426621f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_9_voicea.wav" , 0.427846f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_alone_6_voiced.wav" , 0.428299f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_attention_1_voiced.wav" , 0.429569f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_alone_8_voiceb.wav" , 0.431066f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_7_voicec.wav" , 0.431746f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_alone_5_voicec.wav" , 0.432426f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_attention_2_voicea.wav" , 0.432472f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_9_voiced.wav" , 0.433923f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_7_voicec.wav" , 0.433923f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_al_4_voicea.wav" , 0.435374f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_1_voicea.wav" , 0.435964f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_attention_4_voiceb.wav" , 0.436372f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_attention_4_voicec.wav" , 0.436372f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_attention_4_voiced.wav" , 0.436372f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_alone_2_voiceb.wav" , 0.437460f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_seen_group_2_voicea.wav" , 0.438912f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_2_voiced.wav" , 0.439184f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_4.wav" , 0.439728f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_8_voicec.wav" , 0.439773f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_6.wav" , 0.441769f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_8_voicec.wav" , 0.442585f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_4_voiceb.wav" , 0.446485f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_attention_3_voiceb.wav" , 0.448345f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_attention_3_voicec.wav" , 0.448345f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_attention_3_voiced.wav" , 0.448345f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_fear_2_voiceb.wav" , 0.449524f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_fear_2_voicec.wav" , 0.449524f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_fear_2_voiced.wav" , 0.449524f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_2_voiced.wav" , 0.449841f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_2_alone_voiced.wav" , 0.450295f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_alone_4_voiceb.wav" , 0.450658f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_14_voiceb.wav" , 0.451247f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_9_voicea.wav" , 0.452744f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_1.wav" , 0.453061f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_3_voicec.wav" , 0.454376f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_17.wav" , 0.455465f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_7_voicea.wav" , 0.455692f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_4_voiced.wav" , 0.455873f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_alone_6_voicea.wav" , 0.456780f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_15_voicea.wav" , 0.456825f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_7_voicea.wav" , 0.457415f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_7_voiceb.wav" , 0.463719f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_4.wav" , 0.464399f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_13_voicec.wav" , 0.465034f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_5.wav" , 0.466984f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_3_voicea.wav" , 0.470159f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_2_voiced.wav" , 0.470204f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_2.wav" , 0.471293f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_12_voicea.wav" , 0.472245f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_20_voiceb.wav" , 0.473605f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_group_1_voicea.wav" , 0.474785f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_2.wav" , 0.475964f , false , 18 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_2_voiced.wav" , 0.476009f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_alone_1_voicec.wav" , 0.476054f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_9.wav" , 0.478866f , false , 19 , -1 },
  { "languages\\voicepacks\\voiced\\vehicle_in_7_voiced.wav" , 0.479501f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_alone_1_voiceb.wav" , 0.481361f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_15_voiced.wav" , 0.481587f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_alone_5_voiceb.wav" , 0.481723f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_7_voicea.wav" , 0.481769f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_c_7.wav" , 0.483220f , false , 20 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_group_3_voicea.wav" , 0.484535f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_20_voicea.wav" , 0.484671f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_18_voicec.wav" , 0.486939f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_10_voiceb.wav" , 0.488027f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\gasp.wav" , 0.489161f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_al_3_voicea.wav" , 0.490522f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_attention_5_voiceb.wav" , 0.492698f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_attention_5_voicec.wav" , 0.492698f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_attention_5_voiced.wav" , 0.492698f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_group_7_voicea.wav" , 0.493424f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\vehicle_in_1_voiced.wav" , 0.494785f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_6.wav" , 0.495374f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_8.wav" , 0.496417f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alarm_alone_1_voicec.wav" , 0.499184f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_attention_1_voicea.wav" , 0.499229f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_5_voiceb.wav" , 0.499819f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\vehicle_in_3_voicea.wav" , 0.501950f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_11_voicec.wav" , 0.502086f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_6_voicea.wav" , 0.504989f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_8_voicec.wav" , 0.506485f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_d_2.wav" , 0.507891f , false , 21 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_fear_3_voicea.wav" , 0.507937f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_25.wav" , 0.510839f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\vehicle_in_1_voicea.wav" , 0.511111f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_group_2_voiced.wav" , 0.512290f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_group_1_voicec.wav" , 0.513696f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_group_3_voicec.wav" , 0.513696f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_8_voiced.wav" , 0.516644f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_2_voiceb.wav" , 0.518776f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_12_voiced.wav" , 0.519410f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_11_voiced.wav" , 0.519773f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_7_voiceb.wav" , 0.522404f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_7.wav" , 0.522902f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_alone_1_voicea.wav" , 0.523900f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_6_voicec.wav" , 0.525306f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_alone_3_voicea.wav" , 0.525351f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_attention_4_voicea.wav" , 0.525351f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_3_voicec.wav" , 0.527120f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_3_voiced.wav" , 0.528118f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_2_alone_voicec.wav" , 0.528209f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_2.wav" , 0.530839f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_flank_left_1_voicea.wav" , 0.531111f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_4_voicea.wav" , 0.531111f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_8_voiceb.wav" , 0.531111f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_8_voiced.wav" , 0.531156f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_1_voicea.wav" , 0.532562f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_8_b.wav" , 0.533605f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_g_2.wav" , 0.534014f , false , 22 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_b_2.wav" , 0.534014f , false , 23 , -1 },
  { "languages\\voicepacks\\voicec\\pain_10_voicec.wav" , 0.534014f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alarm_alone_5_voiced.wav" , 0.534059f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_3_voiced.wav" , 0.534240f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_specific_c_6.wav" , 0.534966f , false , 24 , -1 },
  { "languages\\voicepacks\\voiced\\pain_13_voiced.wav" , 0.536463f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_6_voiceb.wav" , 0.536916f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_attention_3_voiced.wav" , 0.538413f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_14_voicea.wav" , 0.539274f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_14_voicec.wav" , 0.539274f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_14_voiced.wav" , 0.539274f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_2_voicea.wav" , 0.539819f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_5_voicea.wav" , 0.539864f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_8_voicea.wav" , 0.539864f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_2_voicec.wav" , 0.540045f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_fear_5_voiceb.wav" , 0.540227f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_fear_5_voicec.wav" , 0.540227f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_fear_5_voiced.wav" , 0.540227f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_3_voicec.wav" , 0.542721f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_3_voicec.wav" , 0.543401f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_group_2_voicea.wav" , 0.544218f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_3_alone_voicea.wav" , 0.545125f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_7_voiced.wav" , 0.545669f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_15_voiceb.wav" , 0.546259f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_attention_2_voiced.wav" , 0.547120f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_9_voiceb.wav" , 0.548526f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_fear_6_voiced.wav" , 0.548571f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_11_voicea.wav" , 0.551429f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_13_voicec.wav" , 0.551927f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_8_voicea.wav" , 0.552290f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_g_4.wav" , 0.552880f , false , 25 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_group_3_voicea.wav" , 0.552880f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_right_1r_voicea.wav" , 0.554376f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_right_1_voicea.wav" , 0.554376f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\grenade_4_voicea.wav" , 0.554376f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_gp_1_voicea.wav" , 0.554376f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_group_1_voicea.wav" , 0.555374f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_3_voicea.wav" , 0.557098f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_8_voicea.wav" , 0.557279f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_al_6_voicea.wav" , 0.557279f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_13_voicea.wav" , 0.559909f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_6_voiced.wav" , 0.561315f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_6.wav" , 0.563039f , false , 26 , -1 },
  { "languages\\missiontalk\\training\\training_generic_l_5.wav" , 0.563039f , false , 27 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_attention_4_voiced.wav" , 0.564535f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_19_voiceb.wav" , 0.564807f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_5_voicea.wav" , 0.565986f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_5_voicea.wav" , 0.565986f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_12_voicec.wav" , 0.568481f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_7_voicea.wav" , 0.568844f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_4_voicea.wav" , 0.568889f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_gp_3_voicea.wav" , 0.568889f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_3.wav" , 0.570023f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_10_voiceb.wav" , 0.570159f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_3_voiceb.wav" , 0.570295f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_19_voicea.wav" , 0.571746f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_flank_left_1_voicec.wav" , 0.572472f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_8_voiced.wav" , 0.572608f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_1_voicea.wav" , 0.573243f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_10_voicea.wav" , 0.573515f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\yell_fear_4_voicea.wav" , 0.574649f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_14_voiced.wav" , 0.574966f , false , -1 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_b_2.wav" , 0.577959f , false , 28 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_1.wav" , 0.578277f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_fear_7_voiced.wav" , 0.579048f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_specific_a_6.wav" , 0.580544f , false , 29 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_attention_5_voiced.wav" , 0.581950f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alarm_alone_5_voiced.wav" , 0.582358f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_4_voicec.wav" , 0.583356f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_6_voiced.wav" , 0.583401f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_group_2_voicea.wav" , 0.584535f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_6_voicea.wav" , 0.584807f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_8_voicec.wav" , 0.584853f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_2_voicea.wav" , 0.586304f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_3_voicea.wav" , 0.587029f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_11_voiced.wav" , 0.587392f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_1_voicec.wav" , 0.588662f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_12_voicea.wav" , 0.589161f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_1_voicea.wav" , 0.589206f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_al_5_voicea.wav" , 0.589206f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_flank_right_1_voicec.wav" , 0.591247f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_11_voiceb.wav" , 0.591655f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_group_1_voicea.wav" , 0.595011f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_group_3_voiced.wav" , 0.596961f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_group_3_voiceb.wav" , 0.597370f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alarm_alone_4_voicea.wav" , 0.597914f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_al_2_voicea.wav" , 0.597914f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_1_voicea.wav" , 0.597914f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_5_voiced.wav" , 0.597914f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_alone_2_voiced.wav" , 0.597914f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_7_voiced.wav" , 0.597914f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_group_2_voicea.wav" , 0.598231f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_g_4.wav" , 0.598594f , false , 30 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_6.wav" , 0.600000f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_8_voiceb.wav" , 0.600771f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_alone_1_voiced.wav" , 0.600816f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_4_voiced.wav" , 0.600862f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_4_voicea.wav" , 0.603039f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_group_5_voicea.wav" , 0.603265f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_2_voiceb.wav" , 0.603673f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alarm_alone_5_voicec.wav" , 0.603673f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_group_5_voicec.wav" , 0.603673f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_tell_get_1_voicea.wav" , 0.603719f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_1_voiced.wav" , 0.603719f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_6_voiced.wav" , 0.603719f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_group_1_voicea.wav" , 0.606576f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_13_voiceb.wav" , 0.606576f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_fear_4_voicea.wav" , 0.606621f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_i_4.wav" , 0.608027f , false , 31 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_2_voiced.wav" , 0.608753f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\yell_fear_2_voicea.wav" , 0.609478f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\mandown_alone_1_voicec.wav" , 0.609478f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alarm_alone_1_voicea.wav" , 0.609524f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_fear_5_voicea.wav" , 0.609524f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_group_1_voiced.wav" , 0.609524f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_2_voiced.wav" , 0.609524f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\flashbang_1_voiceb.wav" , 0.610385f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_1_voicec.wav" , 0.610930f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_23.wav" , 0.611746f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_5_voiced.wav" , 0.611837f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_group_2_voiced.wav" , 0.612336f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_2_voiced.wav" , 0.612426f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alarm_alone_4_voiced.wav" , 0.615329f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_9_voiced.wav" , 0.616281f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_10_voicec.wav" , 0.616327f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_8_voiced.wav" , 0.616780f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_group_2_voicec.wav" , 0.617732f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\vehicle_in_3_voicec.wav" , 0.618186f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_al_8_voicea.wav" , 0.618231f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alarm_alone_1_voiceb.wav" , 0.618231f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_9_voicea.wav" , 0.619637f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_4_voicec.wav" , 0.622540f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_flank_right_1_voicea.wav" , 0.622630f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_alone_6_voicec.wav" , 0.623991f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_left_1r_voicea.wav" , 0.624036f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_left_1_voicea.wav" , 0.624036f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_fear_8_voiced.wav" , 0.624036f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_group_1_voicec.wav" , 0.624082f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_4.wav" , 0.624444f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_8.wav" , 0.626122f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_rush_2_voicec.wav" , 0.627528f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_2_voicec.wav" , 0.629796f , false , -1 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_4.wav" , 0.631247f , false , 32 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_8_voiceb.wav" , 0.632018f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\mandown_group_4_voicec.wav" , 0.635057f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_15_voicec.wav" , 0.635329f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_10.wav" , 0.636463f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\darkness_5_voicea.wav" , 0.637234f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_right_2r_voicea.wav" , 0.638549f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_right_2_voicea.wav" , 0.638549f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_al_1_voicea.wav" , 0.638549f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_2_voiced.wav" , 0.639320f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_9.wav" , 0.639955f , false , 33 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_10.wav" , 0.640726f , false , 34 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_18_voiced.wav" , 0.640726f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\vehicle_in_3_voiced.wav" , 0.640726f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_rush_2_voicea.wav" , 0.641406f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_group_1_voicea.wav" , 0.644354f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_gp_3_voiced.wav" , 0.644354f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_4.wav" , 0.644444f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_flank_right_1_voiceb.wav" , 0.645760f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_9_voicec.wav" , 0.645805f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\vehicle_in_5_voicea.wav" , 0.646712f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_6.wav" , 0.647619f , false , 35 , -1 },
  { "languages\\voicepacks\\jack\\death_8.wav" , 0.648934f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_4_voiceb.wav" , 0.649705f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_4_voicea.wav" , 0.650159f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_alone_3_voiced.wav" , 0.650159f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_15.wav" , 0.650431f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\darkness_5_voicea.wav" , 0.653061f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\flashbang_1_voiced.wav" , 0.653243f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_10.wav" , 0.653651f , false , 36 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_6_voicea.wav" , 0.654014f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_8_voicea.wav" , 0.654467f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_4.wav" , 0.655011f , false , 37 , -1 },
  { "languages\\voicepacks\\coreworkera\\mandown_group_4_voicea.wav" , 0.657415f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_10_voicea.wav" , 0.658821f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_seen_group_2_voicec.wav" , 0.658821f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_5_voiced.wav" , 0.658866f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_3.wav" , 0.662132f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_11_voiceb.wav" , 0.663583f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_16_voicea.wav" , 0.664082f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_fear_6_voicea.wav" , 0.666122f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_group_2_voicec.wav" , 0.667256f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_retreat_3r_voiced.wav" , 0.667574f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_retreat_3_voiced.wav" , 0.667574f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_alone_6_voiceb.wav" , 0.667891f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_14_voicea.wav" , 0.668707f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_15.wav" , 0.668889f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_12_voiceb.wav" , 0.668980f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_3_voiced.wav" , 0.669025f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_5_voicea.wav" , 0.669161f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_9_voicea.wav" , 0.669569f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_10_voiced.wav" , 0.669932f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_3_alone_voiced.wav" , 0.672698f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_h_4.wav" , 0.672971f , false , 38 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_tell_get_4_voicea.wav" , 0.673379f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_group_5_voicec.wav" , 0.673968f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_pickup_c_1.wav" , 0.676236f , false , 39 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_3_voicea.wav" , 0.676281f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_4_voicea.wav" , 0.676281f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_6_voicec.wav" , 0.677551f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_retreat_3r_voicea.wav" , 0.680635f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_retreat_3_voicea.wav" , 0.680635f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_4.wav" , 0.681043f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alarm_alone_5_voiceb.wav" , 0.682449f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\mandown_alone_3_voicea.wav" , 0.683537f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_8_c.wav" , 0.684172f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_2_voiceb.wav" , 0.684717f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_8_voicec.wav" , 0.684943f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_group_3_voiced.wav" , 0.685351f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_6_voiceb.wav" , 0.685669f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_seen_group_1_voicea.wav" , 0.687120f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_group_1_voicec.wav" , 0.687710f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_fear_7_voicea.wav" , 0.687891f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\grenade_3_voicea.wav" , 0.689342f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_8.wav" , 0.690023f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_1_voicea.wav" , 0.690068f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_1_voiced.wav" , 0.692154f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_2_voicec.wav" , 0.692200f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_1_voicea.wav" , 0.693651f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_flank_left_2_voicea.wav" , 0.693651f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_1_voicec.wav" , 0.693651f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_1_voiced.wav" , 0.693651f , false , -1 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_a_3.wav" , 0.693696f , false , 40 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_7_voiced.wav" , 0.693696f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\affirmative_9_voicec.wav" , 0.693923f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_rush_2_voiced.wav" , 0.694921f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_26.wav" , 0.695782f , false , 41 , -1 },
  { "languages\\voicepacks\\voicea\\comm_flank_left_3_voicea.wav" , 0.696553f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_14_voicea.wav" , 0.696553f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_seen_gp_2_voicea.wav" , 0.696599f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_10_voicea.wav" , 0.696599f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_14.wav" , 0.697914f , false , 42 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_b_3.wav" , 0.698005f , false , 43 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_group_5_voiced.wav" , 0.698639f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_8_voiced.wav" , 0.699410f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_12_voicea.wav" , 0.699456f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_7_voiceb.wav" , 0.699456f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_5_voicec.wav" , 0.699456f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_9_voicec.wav" , 0.699456f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\mandown_alone_2_voicec.wav" , 0.699456f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_fear_1_voicea.wav" , 0.699501f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_20.wav" , 0.699773f , false , 44 , -1 },
  { "languages\\voicepacks\\voicec\\comm_flank_right_3_voicec.wav" , 0.702177f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_13_voicec.wav" , 0.702222f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_2_alone_voiceb.wav" , 0.702358f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_group_3_voicec.wav" , 0.702358f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_1_voicea.wav" , 0.702404f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_3_voicea.wav" , 0.702404f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alone_cough_1_voicea.wav" , 0.702404f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_7_voiced.wav" , 0.702404f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_5_voiced.wav" , 0.703492f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_supress_3_voicea.wav" , 0.703855f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_7_voiceb.wav" , 0.703855f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_7_voicec.wav" , 0.703855f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_7_voiced.wav" , 0.703855f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_group_2_voiceb.wav" , 0.704399f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_10_voicec.wav" , 0.704807f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_c_3.wav" , 0.705261f , false , 45 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_group_2_voiced.wav" , 0.705306f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_4_voicea.wav" , 0.705986f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_4_voiced.wav" , 0.706077f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_15_voiced.wav" , 0.708163f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_al_4_voicea.wav" , 0.708209f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_1_voicea.wav" , 0.708209f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_gp_2_voicea.wav" , 0.708209f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_8_voiced.wav" , 0.708209f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_6.wav" , 0.708844f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_5_voiced.wav" , 0.709342f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_group_4_voicea.wav" , 0.710476f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_2_voiced.wav" , 0.711111f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_3_alone_voicec.wav" , 0.711202f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_11_voicea.wav" , 0.711791f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_2_voiceb.wav" , 0.712381f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_11_voicea.wav" , 0.712971f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_11_voiced.wav" , 0.712971f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\vehicle_in_5_voiced.wav" , 0.712971f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_9_voicea.wav" , 0.713288f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\vehicle_in_7_voicec.wav" , 0.713923f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_6bis.wav" , 0.713968f , false , 46 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_flank_right_3_voiceb.wav" , 0.713968f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alarm_alone_5_voicea.wav" , 0.714014f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_al_7_voicea.wav" , 0.714014f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_3_voiced.wav" , 0.714014f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_3_voiced.wav" , 0.714014f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_5_voiced.wav" , 0.714014f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_1_voiced.wav" , 0.714014f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_g_7.wav" , 0.714376f , false , 47 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_11_voiceb.wav" , 0.714649f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_f_1.wav" , 0.715556f , false , 48 , -1 },
  { "languages\\voicepacks\\voicec\\comm_flank_left_3_voicec.wav" , 0.716281f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\mandown_alone_3_voicec.wav" , 0.716689f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_9_voiced.wav" , 0.716735f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_6_voicec.wav" , 0.718186f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_pickup_a_1.wav" , 0.719773f , false , 49 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_al_8_voicea.wav" , 0.719819f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_group_1_voiced.wav" , 0.719909f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_11.wav" , 0.720000f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_flank_right_3_voicea.wav" , 0.721179f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\vehicle_in_7_voiceb.wav" , 0.721678f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_1_voiceb.wav" , 0.722993f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_13_voiceb.wav" , 0.723447f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_flank_right_2_voicea.wav" , 0.723764f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_a_1bi.wav" , 0.724580f , false , 50 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_group_2_voicea.wav" , 0.725624f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_generic_1r_voiced.wav" , 0.725624f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_generic_1_voiced.wav" , 0.725624f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_12_voiceb.wav" , 0.727029f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_seen_group_1_voicec.wav" , 0.727166f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_4.wav" , 0.728481f , false , 51 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_gp_2_voicea.wav" , 0.728526f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_4_voiced.wav" , 0.728526f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_11_voicec.wav" , 0.728980f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_2_voicea.wav" , 0.730522f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_3_voicea.wav" , 0.730703f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\pain_11_voiceb.wav" , 0.730794f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_e_3.wav" , 0.731383f , false , 52 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_5_voicec.wav" , 0.731383f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_4_voiced.wav" , 0.731429f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alarm_alone_1_voiced.wav" , 0.731429f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_1_voiced.wav" , 0.731429f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_left_1r_voiced.wav" , 0.731429f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_left_1_voiced.wav" , 0.731429f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_1_voiceb.wav" , 0.731429f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_2_voicea.wav" , 0.732290f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_1.wav" , 0.733832f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\vehicle_in_4_voicea.wav" , 0.735737f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_33_voicea.wav" , 0.736100f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_5_voicea.wav" , 0.736961f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_4_group_voiceb.wav" , 0.737052f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alarm_alone_3_voicea.wav" , 0.737234f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_group_1_voicea.wav" , 0.737279f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\pain_14.wav" , 0.737596f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_2.wav" , 0.739637f , false , 53 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_5_voicea.wav" , 0.740091f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_attention_3_voicea.wav" , 0.740136f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\mandown_alone_1_voicea.wav" , 0.740454f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_6_b.wav" , 0.742177f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_10_voicea.wav" , 0.743039f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_left_3r_voicea.wav" , 0.743039f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_left_3_voicea.wav" , 0.743039f , false , -1 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_pickup_e_7.wav" , 0.743084f , false , 54 , -1 },
  { "languages\\voicepacks\\voicea\\searching_generic_7_voicea.wav" , 0.744943f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_generic_7_voiceb.wav" , 0.744943f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_generic_7_voicec.wav" , 0.744943f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_generic_7_voiced.wav" , 0.744943f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_flank_left_2_voicec.wav" , 0.745261f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_3_group_voicea.wav" , 0.745533f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_4_voiceb.wav" , 0.745896f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_1_voiced.wav" , 0.745941f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_10_voiced.wav" , 0.745941f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\pain_12_voicec.wav" , 0.747347f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_group_2_voicea.wav" , 0.747392f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_6.wav" , 0.747982f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_4_voicec.wav" , 0.748299f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_seen_group_2_voiceb.wav" , 0.748798f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_al_5_voicea.wav" , 0.748844f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alone_throatc_1_voicea.wav" , 0.748844f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_fear_1_voiced.wav" , 0.748844f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_17.wav" , 0.749977f , false , 55 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_2.wav" , 0.750023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_5.wav" , 0.750023f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_suppress_1_voicec.wav" , 0.750068f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_supress_1r_voicea.wav" , 0.750295f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_supress_1_voicea.wav" , 0.750295f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_c_1.wav" , 0.750522f , false , 56 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_go_get_1_voiced.wav" , 0.750522f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_10.wav" , 0.750930f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_15_voicea.wav" , 0.751020f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_15_voicec.wav" , 0.751020f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_15_voiced.wav" , 0.751020f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_8_voicea.wav" , 0.751701f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_3_voiced.wav" , 0.751746f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_group_1_voiced.wav" , 0.751746f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_9_voicea.wav" , 0.752018f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_12.wav" , 0.752245f , false , 57 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_alone_5_voicea.wav" , 0.753197f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_flank_right_1_voiced.wav" , 0.753288f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_6_voiced.wav" , 0.753288f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_1.wav" , 0.753379f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_group_5_voicea.wav" , 0.754104f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_9_voicec.wav" , 0.754649f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_9_voiced.wav" , 0.754649f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_group_3_voicea.wav" , 0.755374f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_group_1_voiced.wav" , 0.756372f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\vehicle_in_8_voicea.wav" , 0.756599f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_gp_3_voicea.wav" , 0.757551f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_9_voiced.wav" , 0.757551f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_flank_left_3_voiceb.wav" , 0.758231f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_seen_group_3_voicea.wav" , 0.758685f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_4_voicea.wav" , 0.760454f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_13_voiced.wav" , 0.760454f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\mandown_alone_3_voicea.wav" , 0.761134f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_3.wav" , 0.761587f , false , 58 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_7_voicea.wav" , 0.761678f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_alone_7_voicea.wav" , 0.761814f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_6_voiced.wav" , 0.761905f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_advance_right_1_voicec.wav" , 0.762585f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_1_voiceb.wav" , 0.762676f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_1_voiceb.wav" , 0.762766f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_seen_group_2_voiced.wav" , 0.762766f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_group_3_voicea.wav" , 0.763311f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_flank_left_1_voiceb.wav" , 0.763311f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_8_voiced.wav" , 0.764399f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reloaded_3_voicea.wav" , 0.764807f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_6_voicec.wav" , 0.764989f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_generic_1_voicea.wav" , 0.765805f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_generic_1_voiceb.wav" , 0.765805f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_generic_1_voicec.wav" , 0.765805f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_generic_1_voiced.wav" , 0.765805f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\vehicle_in_2_voicea.wav" , 0.766213f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\darkness_5_voiceb.wav" , 0.766213f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_9_voicec.wav" , 0.766349f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_group_3_voiceb.wav" , 0.768299f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_group_6_voicec.wav" , 0.768526f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_20_voicea.wav" , 0.768844f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_16_voicec.wav" , 0.769116f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_group_2_voicec.wav" , 0.769116f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_6_voicea.wav" , 0.769161f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_alone_5_voiced.wav" , 0.769161f , false , -1 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_6_1.wav" , 0.769524f , false , 59 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_2_voicec.wav" , 0.769660f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_5_voicea.wav" , 0.770431f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reloaded_1_voicea.wav" , 0.770612f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_group_2_voicec.wav" , 0.770658f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_1_voiceb.wav" , 0.771383f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_1_voicec.wav" , 0.771383f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_1_voiced.wav" , 0.771383f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_group_6_voicec.wav" , 0.772018f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\grenade_2_voicea.wav" , 0.772063f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_14.wav" , 0.772336f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_alone_1_voiced.wav" , 0.772744f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_9.wav" , 0.774104f , false , 60 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_9_voiced.wav" , 0.774603f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_20.wav" , 0.774921f , false , 61 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_6_voiced.wav" , 0.775556f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_al_7_voicea.wav" , 0.776417f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_4_voicec.wav" , 0.776871f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_alone_3_voicea.wav" , 0.777098f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_17.wav" , 0.777596f , false , 62 , -1 },
  { "languages\\missiontalk\\training\\training_generic_c_2.wav" , 0.777823f , false , 63 , -1 },
  { "languages\\voicepacks\\voicea\\death_16_voicea.wav" , 0.778912f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_16_voiceb.wav" , 0.778912f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_16_voicec.wav" , 0.778912f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_16_voiced.wav" , 0.778912f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_i_7.wav" , 0.779229f , false , 64 , -1 },
  { "languages\\voicepacks\\voicec\\comm_suppress_4_voicec.wav" , 0.779546f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_7.wav" , 0.780000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_9.wav" , 0.780000f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_alone_6_voiced.wav" , 0.780771f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_6.wav" , 0.780907f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_12.wav" , 0.781814f , false , 65 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_12y.wav" , 0.781814f , false , 66 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_9_voicec.wav" , 0.783628f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_right_3r_voicea.wav" , 0.783673f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_right_3_voicea.wav" , 0.783673f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alarm_alone_3_voiced.wav" , 0.783673f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\vehicle_in_5_voicec.wav" , 0.785760f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_13_voiceb.wav" , 0.786395f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_17.wav" , 0.786531f , false , 67 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_8_voiced.wav" , 0.786576f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_15_voicea.wav" , 0.787982f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_al_3_voicea.wav" , 0.789478f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_group_7_voiced.wav" , 0.789478f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_macho_1_voiced.wav" , 0.789478f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_2_voicea.wav" , 0.790204f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_7_voicec.wav" , 0.790431f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_5_voicea.wav" , 0.791066f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\vehicle_in_8_voiced.wav" , 0.792200f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_9.wav" , 0.792744f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_1_voiced.wav" , 0.794286f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\mandown_group_3_voiceb.wav" , 0.794467f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\mandown_group_4_voiceb.wav" , 0.794467f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_o_2.wav" , 0.794694f , false , 68 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_go_get_1_voiceb.wav" , 0.794694f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_3_voicea.wav" , 0.794830f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_group_2_voiced.wav" , 0.795283f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_alone_3_voicec.wav" , 0.795510f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_11.wav" , 0.796689f , false , 69 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_f_2.wav" , 0.796825f , false , 70 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_group_3_voicec.wav" , 0.797279f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_4_voicea.wav" , 0.798141f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_4_voicec.wav" , 0.798141f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_group_2_voiced.wav" , 0.798186f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_9.wav" , 0.799002f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_seen_group_3_voicec.wav" , 0.799864f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_11.wav" , 0.801270f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_9.wav" , 0.801587f , false , 71 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_d_4.wav" , 0.802494f , false , 72 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_2_group_voicea.wav" , 0.803175f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_5_voiced.wav" , 0.803991f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\grenade_4_voiced.wav" , 0.803991f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_e_5.wav" , 0.805034f , false , 73 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_group_2_voiced.wav" , 0.805488f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_4_alone_voicec.wav" , 0.805669f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\flashbang_1_voicec.wav" , 0.805896f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_21.wav" , 0.806122f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_6_c.wav" , 0.806122f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_10.wav" , 0.806848f , false , 74 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_group_1_voicec.wav" , 0.806848f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_alone_3_voicea.wav" , 0.806893f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_go_get_1_voicea.wav" , 0.806893f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_8_voiced.wav" , 0.808889f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_4_alone_voicea.wav" , 0.809070f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_group_3_voicec.wav" , 0.809433f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_16.wav" , 0.809751f , false , 75 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_2_voicea.wav" , 0.809751f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_alone_1_voicea.wav" , 0.809796f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_group_1.wav" , 0.810023f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\mandown_alone_3_voiced.wav" , 0.811655f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_9_voiced.wav" , 0.811701f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_d_6.wav" , 0.811882f , false , 76 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_14.wav" , 0.812109f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_mercs_a_4.wav" , 0.814104f , false , 77 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_16_voicec.wav" , 0.814875f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_e_4.wav" , 0.815147f , false , 78 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_al_5_voicea.wav" , 0.815601f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_alone_2_voicea.wav" , 0.815601f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_left_2r_voicea.wav" , 0.815601f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_left_2_voicea.wav" , 0.815601f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_group_5_voiceb.wav" , 0.815918f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\vehicle_in_3_voiceb.wav" , 0.816463f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_k_6.wav" , 0.817052f , false , 79 , -1 },
  { "languages\\voicepacks\\voiced\\pain_7_voiced.wav" , 0.817823f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_pickup_b_2.wav" , 0.818458f , false , 80 , -1 },
  { "languages\\voicepacks\\voiceb\\death_14_voiceb.wav" , 0.819456f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_6.wav" , 0.819909f , false , 81 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_b_3.wav" , 0.819955f , false , 82 , -1 },
  { "languages\\voicepacks\\coreworkera\\affirmative_9_voicea.wav" , 0.819955f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_go_get_1_voicea.wav" , 0.820726f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_13_voicea.wav" , 0.820952f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_1_voicec.wav" , 0.821361f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_seen_gp_2_voiced.wav" , 0.821406f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_3_voiceb.wav" , 0.822086f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_18_voicea.wav" , 0.822812f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\flashbang_2_voicea.wav" , 0.822857f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_33_voicec.wav" , 0.823900f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_33_voiced.wav" , 0.823900f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_1.wav" , 0.823946f , false , 83 , -1 },
  { "languages\\voicepacks\\jack\\pain_20.wav" , 0.823946f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alone_sneeze_1_voicea.wav" , 0.824308f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_18.wav" , 0.824717f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_group_6_voicea.wav" , 0.825578f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_4_group_voiced.wav" , 0.825578f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\mandown_alone_1_voiced.wav" , 0.826984f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_group_2_voiceb.wav" , 0.827166f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_group_5_voicea.wav" , 0.827211f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\pain_10_voiced.wav" , 0.827664f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_group_3_voiced.wav" , 0.828345f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_3_group_voicec.wav" , 0.829977f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_2_voicea.wav" , 0.830068f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_2_voicec.wav" , 0.830068f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_al_6_voicea.wav" , 0.830113f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_gp_1_voicea.wav" , 0.830113f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\mandown_group_4_voiced.wav" , 0.831156f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\mandown_group_4_voicea.wav" , 0.831383f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_12_voicec.wav" , 0.831383f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_6_voicec.wav" , 0.831383f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_go_get_1_voicec.wav" , 0.831519f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_8.wav" , 0.832971f , false , 84 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_macho_3_voicea.wav" , 0.833016f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_4_voiced.wav" , 0.833016f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_fear_3_voiced.wav" , 0.833016f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_4_voiced.wav" , 0.833923f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_flank_right_2_voicec.wav" , 0.834104f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_l_7.wav" , 0.834286f , false , 85 , -1 },
  { "languages\\voicepacks\\val\\affirmative_8.wav" , 0.835283f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_advance_right_1_voicea.wav" , 0.835873f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_10.wav" , 0.836009f , false , 86 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_10_voiced.wav" , 0.836689f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_group_4_voicec.wav" , 0.837052f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_group_1_voiced.wav" , 0.837596f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_flank_left_1_voiced.wav" , 0.838095f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_generic_a_3.wav" , 0.838776f , false , 87 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_9_voicea.wav" , 0.838776f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_1_voicec.wav" , 0.838776f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_6_voiced.wav" , 0.838821f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_e_3.wav" , 0.839410f , false , 88 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_2_voiced.wav" , 0.839410f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\vehicle_in_1_voicec.wav" , 0.839592f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_group_2.wav" , 0.840000f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_9_voiceb.wav" , 0.840408f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_alone_3_voiceb.wav" , 0.840408f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_2_voiceb.wav" , 0.840771f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_2_voicec.wav" , 0.840771f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_2_voiced.wav" , 0.840771f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_d_1.wav" , 0.840862f , false , 89 , -1 },
  { "languages\\missiontalk\\training\\training_generic_l_4.wav" , 0.841134f , false , 90 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_11.wav" , 0.841134f , false , 91 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_group_2_voicea.wav" , 0.841678f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_al_4_voicea.wav" , 0.841723f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\mandown_group_1_voicea.wav" , 0.841723f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_2.wav" , 0.842857f , false , 92 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_group_1_voiceb.wav" , 0.843764f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_13_voiceb.wav" , 0.843810f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_g_8.wav" , 0.844580f , false , 93 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_6_voicea.wav" , 0.844626f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_retreat_1r_voicea.wav" , 0.844626f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_retreat_1_voicea.wav" , 0.844626f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_f_1.wav" , 0.845034f , false , 94 , -1 },
  { "languages\\voicepacks\\jack\\pain_22.wav" , 0.845034f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_11_voicec.wav" , 0.845215f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_15.wav" , 0.845351f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_13.wav" , 0.846349f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_flank_right_2_voiced.wav" , 0.847800f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_9_voicea.wav" , 0.848934f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_15_voicea.wav" , 0.848980f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_4_alone_voiceb.wav" , 0.849070f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_15_voicec.wav" , 0.849433f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_12_voicec.wav" , 0.850385f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_1_voiced.wav" , 0.850431f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_13_voiced.wav" , 0.850567f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_group_4_voicec.wav" , 0.851383f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_4_group_voicea.wav" , 0.851837f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_4_voiceb.wav" , 0.853243f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\go_to_waypoint_a2.wav" , 0.853288f , false , 95 , -1 },
  { "languages\\voicepacks\\voicea\\death_10_voicea.wav" , 0.853288f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_10_voiced.wav" , 0.853333f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\darkness_5_voiced.wav" , 0.853333f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_group_1_voiceb.wav" , 0.853560f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_16_voicea.wav" , 0.854150f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_b_3.wav" , 0.854739f , false , 96 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_2_voiced.wav" , 0.856100f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_8_voiceb.wav" , 0.856190f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_macho_1_voicea.wav" , 0.856236f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_2.wav" , 0.858322f , false , 97 , -1 },
  { "languages\\voicepacks\\voicec\\flashbang_2_voicec.wav" , 0.858322f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_g_4.wav" , 0.858549f , false , 98 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_5_voicea.wav" , 0.858639f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_advance_left_1_voicea.wav" , 0.859093f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\darkness_5_voicec.wav" , 0.859093f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_fear_2_voiced.wav" , 0.859138f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_generic_5_voicea.wav" , 0.861723f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_generic_5_voiceb.wav" , 0.861723f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_generic_5_voicec.wav" , 0.861723f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_generic_5_voiced.wav" , 0.861723f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_group_5_voiceb.wav" , 0.861995f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_group_3_voicea.wav" , 0.862041f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_5_voiceb.wav" , 0.862132f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_alone_4_voicea.wav" , 0.862494f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\flashbang_4_voicea.wav" , 0.862585f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_2_group_voicec.wav" , 0.864354f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_4_alone_voiced.wav" , 0.864490f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_suppress_3_voicec.wav" , 0.864580f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_15_voicea.wav" , 0.864898f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_1_voiced.wav" , 0.864943f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_12_voicec.wav" , 0.865261f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_10_voiceb.wav" , 0.865669f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_5_voiceb.wav" , 0.866213f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_5_voicec.wav" , 0.866213f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_5_voiced.wav" , 0.866213f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\flashbang_4_voicec.wav" , 0.866621f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_21.wav" , 0.866939f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_macho_5_voicea.wav" , 0.867846f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_4_voiced.wav" , 0.869660f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_12.wav" , 0.870023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_3.wav" , 0.870023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_8.wav" , 0.870023f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\flashbang_4_voiced.wav" , 0.870068f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_2_voicea.wav" , 0.870249f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_10_voiceb.wav" , 0.870703f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\mandown_alone_3_voiceb.wav" , 0.870703f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_2_voicea.wav" , 0.870748f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alone_schuckl_1_voicea.wav" , 0.870748f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_4_voicea.wav" , 0.870748f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_right_3r_voiced.wav" , 0.870748f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_right_3_voiced.wav" , 0.870748f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_17_voicea.wav" , 0.872154f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_17_voiceb.wav" , 0.872154f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_17_voicec.wav" , 0.872154f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_17_voiced.wav" , 0.872154f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_group_3_voiceb.wav" , 0.873605f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_group_1_voiceb.wav" , 0.873605f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_seen_group_1_voiced.wav" , 0.877234f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_15_voiceb.wav" , 0.879048f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_10_voiceb.wav" , 0.879093f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_group_4_voicea.wav" , 0.879456f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_7.wav" , 0.879637f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_advance_right_1_voiceb.wav" , 0.879683f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_advance_left_1_voicec.wav" , 0.881678f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_10.wav" , 0.882313f , false , 99 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_4_voicea.wav" , 0.882313f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_5_voicea.wav" , 0.882313f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_macho_4_voicea.wav" , 0.882358f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_1_voicea.wav" , 0.883129f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_10.wav" , 0.883356f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_f_2.wav" , 0.883764f , false , 100 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_1_voicea.wav" , 0.883764f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_group_2_voiceb.wav" , 0.883946f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_1.wav" , 0.885215f , false , 101 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_7.wav" , 0.885215f , false , 102 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_5_voiced.wav" , 0.885261f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_group_1_voiceb.wav" , 0.885578f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_combat_group_6_voicea.wav" , 0.886349f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_2_voiced.wav" , 0.886757f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_suppress_6_voicec.wav" , 0.887302f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_13_voicec.wav" , 0.888073f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_3_voicec.wav" , 0.888118f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_7_voicea.wav" , 0.888163f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_al_1_voicea.wav" , 0.888163f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_5_voicea.wav" , 0.888163f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_right_1r_voiced.wav" , 0.888163f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_right_1_voiced.wav" , 0.888163f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_2_voiceb.wav" , 0.888571f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8e.wav" , 0.889365f , false , 103 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_13_voicec.wav" , 0.890930f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_13_voiced.wav" , 0.890930f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_10.wav" , 0.892290f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reloaded_2_voicea.wav" , 0.892517f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_18_voicea.wav" , 0.893515f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_18_voiceb.wav" , 0.893515f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_18_voicec.wav" , 0.893515f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_18_voiced.wav" , 0.893515f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_3_voiced.wav" , 0.893787f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_al_1_voicea.wav" , 0.893968f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_3_voicea.wav" , 0.893968f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_to_alert_al_3_voicea.wav" , 0.893968f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_supress_3_voiced.wav" , 0.893968f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\pain_4_voiced.wav" , 0.893968f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8b.wav" , 0.894512f , false , 104 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_6_voiceb.wav" , 0.894694f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_generic_2r_voicea.wav" , 0.895420f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_generic_2_voicea.wav" , 0.895420f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_16_voiceb.wav" , 0.896281f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_12_voiceb.wav" , 0.896463f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\vehicle_in_4_voicec.wav" , 0.896644f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_5_voicec.wav" , 0.896825f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\flashbang_2_voicea.wav" , 0.896871f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_group_3_voiced.wav" , 0.896871f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_9_voiceb.wav" , 0.897007f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alarm_alone_2_voicea.wav" , 0.897914f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_g_7.wav" , 0.898776f , false , 105 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_3_voiced.wav" , 0.899229f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_group_1_voicea.wav" , 0.899365f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_group_4_voicea.wav" , 0.899365f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\mandown_group_1_voicec.wav" , 0.899365f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_al_1_voicea.wav" , 0.899773f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_2_voicea.wav" , 0.899773f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_generic_2r_voiced.wav" , 0.899773f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_generic_2_voiced.wav" , 0.899773f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_14_voicec.wav" , 0.899909f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\flashbang_2_voiceb.wav" , 0.900454f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\flashbang_2_voiced.wav" , 0.900635f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_retreat_2r_voicea.wav" , 0.901224f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_retreat_2_voicea.wav" , 0.901224f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_e_8.wav" , 0.902630f , false , 106 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_3_voicea.wav" , 0.902630f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_8_voiceb.wav" , 0.902630f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\mandown_alone_1_voicea.wav" , 0.902676f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_4_voiced.wav" , 0.902676f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_f_8.wav" , 0.902902f , false , 107 , -1 },
  { "languages\\voicepacks\\voiceb\\vehicle_in_8_voiceb.wav" , 0.904444f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_19_voicea.wav" , 0.904989f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_19_voiceb.wav" , 0.904989f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_19_voicec.wav" , 0.904989f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_19_voiced.wav" , 0.904989f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_1_voicec.wav" , 0.905442f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\flashbang_1_voicea.wav" , 0.905578f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_2_voiced.wav" , 0.905578f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\darkness_5_voiced.wav" , 0.906168f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_11_voicea.wav" , 0.907710f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\following_player_a3.wav" , 0.908435f , false , 108 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_3_alone_voiceb.wav" , 0.908435f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_12_voiced.wav" , 0.908526f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_generic_2_voicea.wav" , 0.908980f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_generic_2_voiceb.wav" , 0.908980f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_generic_2_voicec.wav" , 0.908980f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_generic_2_voiced.wav" , 0.908980f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\vehicle_in_4_voiced.wav" , 0.908980f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_c_3.wav" , 0.909932f , false , 109 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_generic_3r_voiced.wav" , 0.911383f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_generic_3_voiced.wav" , 0.911383f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_9_voiced.wav" , 0.912109f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_seen_group_1_voiceb.wav" , 0.912517f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\mandown_group_2_voicea.wav" , 0.915057f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_suppress_3_voicea.wav" , 0.915918f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_18_voiceb.wav" , 0.916100f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_9.wav" , 0.916825f , false , 110 , -1 },
  { "languages\\missiontalk\\swamp\\still_someone_a3.wav" , 0.917143f , false , 111 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_7_voicea.wav" , 0.917143f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_suppress_1_voiceb.wav" , 0.917143f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alarm_group_1_voicea.wav" , 0.917188f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_2_voiced.wav" , 0.918685f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\darkness_2_voicea.wav" , 0.919683f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_13_voicec.wav" , 0.920045f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_seen_gp_1_voicea.wav" , 0.920091f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_1_voiced.wav" , 0.920091f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_12.wav" , 0.920091f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_12_voiced.wav" , 0.920091f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8f.wav" , 0.920295f , false , 112 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_1_voiced.wav" , 0.921451f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_group_5_voiced.wav" , 0.921995f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_12_voiceb.wav" , 0.922086f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_3_voiceb.wav" , 0.922177f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_3_voicea.wav" , 0.922902f , false , -1 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_7.wav" , 0.922948f , false , 113 , -1 },
  { "languages\\voicepacks\\voicea\\death_12_voicea.wav" , 0.922948f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_flank_right_2_voiceb.wav" , 0.922948f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_rush_2_voiceb.wav" , 0.922948f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_12_voiced.wav" , 0.922948f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\mandown_alone_3_voiced.wav" , 0.922993f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_7_voicec.wav" , 0.923129f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\mandown_group_2_voicec.wav" , 0.923175f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\mandown_group_3_voicec.wav" , 0.923175f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_11_voiceb.wav" , 0.923991f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_19.wav" , 0.925442f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\pain_6_voicea.wav" , 0.925896f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_3_group_voiceb.wav" , 0.926077f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\flashbang_5_voicec.wav" , 0.926667f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_suppress_4_voiceb.wav" , 0.926984f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_3_voicec.wav" , 0.927800f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_11_voiced.wav" , 0.928435f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_10.wav" , 0.928526f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_generic_3r_voicea.wav" , 0.928798f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_flank_generic_3_voicea.wav" , 0.928798f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_9_voiced.wav" , 0.928798f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_6_voiced.wav" , 0.928798f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_13_voiceb.wav" , 0.928980f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_17.wav" , 0.929705f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_2_alert_seen_group_2.wav" , 0.930023f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_9_voiceb.wav" , 0.930658f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_e_4.wav" , 0.931655f , false , 114 , -1 },
  { "languages\\voicepacks\\coreworkerd\\grenade_3_voiced.wav" , 0.931701f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_35_voicea.wav" , 0.931746f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_group_4_voiced.wav" , 0.931746f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_9.wav" , 0.933288f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_4_voicea.wav" , 0.933605f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_3.wav" , 0.934558f , false , 115 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_9_voiceb.wav" , 0.934558f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_seen_gp_3_voicea.wav" , 0.934603f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_right_2r_voiced.wav" , 0.934603f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_right_2_voiced.wav" , 0.934603f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_gp_2_voiced.wav" , 0.934603f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_10_voicec.wav" , 0.934649f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_4_voicec.wav" , 0.934966f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\flashbang_3_voiced.wav" , 0.936780f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_20.wav" , 0.937143f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_3_voiceb.wav" , 0.938095f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_4_group_voicec.wav" , 0.938639f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_11_voicea.wav" , 0.940363f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\mandown_alone_2_voicea.wav" , 0.940408f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reloaded_1_voiced.wav" , 0.940408f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\mandown_group_1_voicea.wav" , 0.941814f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\mandown_group_3_voicea.wav" , 0.941814f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_12.wav" , 0.941905f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_9_voiced.wav" , 0.942313f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_9_voiced.wav" , 0.943039f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_alone_7_voiced.wav" , 0.943129f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_6.wav" , 0.943265f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_2_voicea.wav" , 0.943265f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_10_voicea.wav" , 0.943311f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_talk_to_5_voicea.wav" , 0.943311f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_group_5_voiced.wav" , 0.943311f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\go_to_waypoint_a3.wav" , 0.944717f , false , 116 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_8_1.wav" , 0.946122f , false , 117 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_1_voicea.wav" , 0.946168f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_left_3r_voiced.wav" , 0.946213f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_left_3_voiced.wav" , 0.946213f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_1_voiceb.wav" , 0.948299f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_3_voicea.wav" , 0.950567f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_4_voiced.wav" , 0.950612f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_b_3.wav" , 0.950635f , false , 118 , -1 },
  { "languages\\voicepacks\\coreworkera\\flashlight_face_3_voicea.wav" , 0.952018f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\vehicle_in_6_voicea.wav" , 0.952698f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_14.wav" , 0.952971f , false , 119 , -1 },
  { "languages\\voicepacks\\voiceb\\mandown_group_2_voiceb.wav" , 0.953197f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_3.wav" , 0.953424f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_4.wav" , 0.953605f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_3_voiceb.wav" , 0.953696f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\flashbang_3_voicec.wav" , 0.953878f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_10_voicea.wav" , 0.954875f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_al_2_voicea.wav" , 0.954921f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_4_voiced.wav" , 0.954921f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_5_voiceb.wav" , 0.956281f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_b_6.wav" , 0.957052f , false , 120 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_10.wav" , 0.957279f , false , 121 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_retreat_2r_voiced.wav" , 0.957823f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_retreat_2_voiced.wav" , 0.957823f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_4_voiced.wav" , 0.957823f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\mandown_alone_1_voiceb.wav" , 0.957823f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_9_voicea.wav" , 0.959138f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_advance_left_1_voiceb.wav" , 0.959909f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_13.wav" , 0.960000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_2.wav" , 0.960000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_5.wav" , 0.960000f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_13_voicea.wav" , 0.962449f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_flank_left_2_voiceb.wav" , 0.962721f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_2_voicec.wav" , 0.963537f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_pickup_d_1.wav" , 0.963583f , false , 122 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_11_voicec.wav" , 0.963583f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_retreat_1r_voiced.wav" , 0.963628f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_retreat_1_voiced.wav" , 0.963628f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_gp_2_voiced.wav" , 0.963628f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_go_get_1_voiced.wav" , 0.963628f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_suppress_3_voiced.wav" , 0.964580f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_10_voiceb.wav" , 0.964762f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_alone_3_voiced.wav" , 0.966531f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_1_voiceb.wav" , 0.966621f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_35_voicec.wav" , 0.967347f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_35_voiced.wav" , 0.967347f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_6.wav" , 0.967619f , false , 123 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_g_5.wav" , 0.967619f , false , 124 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_1_voicea.wav" , 0.967937f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_e_2.wav" , 0.968073f , false , 125 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_5_voicea.wav" , 0.969433f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_10_voiced.wav" , 0.970113f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_10_voicec.wav" , 0.970385f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_10_voiced.wav" , 0.970385f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_group_4_voicea.wav" , 0.970884f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_3_voicea.wav" , 0.970884f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_11.wav" , 0.972744f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_talk_to_4_voicea.wav" , 0.975238f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_supress_1r_voiced.wav" , 0.975238f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_supress_1_voiced.wav" , 0.975238f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_suppress_6_voiceb.wav" , 0.977687f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_19.wav" , 0.978095f , false , 126 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_suppress_3_voiceb.wav" , 0.978095f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_gp_1_voiced.wav" , 0.978141f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_15_voiceb.wav" , 0.979093f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_group_2_voiceb.wav" , 0.979501f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_advance_left_2_voicea.wav" , 0.980136f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_2_voiceb.wav" , 0.980454f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_4.wav" , 0.980998f , false , 127 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_9_voiceb.wav" , 0.980998f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_6_voicea.wav" , 0.981043f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_2_voiced.wav" , 0.981043f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\helicopter_sight_2_voicea.wav" , 0.982268f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_3_voiceb.wav" , 0.982268f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\helicopter_sight_2_voiceb.wav" , 0.982268f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\helicopter_sight_2_voicec.wav" , 0.982268f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\helicopter_sight_2_voiced.wav" , 0.982268f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_suppress_4_voicea.wav" , 0.982358f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_6_voiced.wav" , 0.983991f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_3_group_voiced.wav" , 0.984036f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_group_6_voiceb.wav" , 0.984898f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_2_voiced.wav" , 0.986032f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_advance_right_2_voicec.wav" , 0.986395f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_talk_to_2_voicea.wav" , 0.986848f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_tell_get_2_voicea.wav" , 0.986848f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_left_2r_voiced.wav" , 0.986848f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_flank_left_2_voiced.wav" , 0.986848f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_pickup_a_2.wav" , 0.987347f , false , 128 , -1 },
  { "languages\\voicepacks\\voicec\\comm_advance_left_2_voicec.wav" , 0.988163f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\affirmative_3_voiced.wav" , 0.989569f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_3_voiced.wav" , 0.989569f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_1_voicea.wav" , 0.989751f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_2_voiced.wav" , 0.989751f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_1.wav" , 0.990023f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_33_voiceb.wav" , 0.990204f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_1_voicea.wav" , 0.990930f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_1.wav" , 0.991338f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_1_voicec.wav" , 0.991519f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_19_voicea.wav" , 0.992200f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_5_voiceb.wav" , 0.992562f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_fear_8_voicea.wav" , 0.992653f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\mandown_group_4_voiced.wav" , 0.992653f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\vehicle_in_8_voicec.wav" , 0.994331f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_2_voicea.wav" , 0.995510f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_group_3_voiceb.wav" , 0.998050f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_al_5_voicea.wav" , 0.998458f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_8.wav" , 0.998549f , false , 129 , -1 },
  { "languages\\missiontalk\\training\\silence.wav" , 1.000000f , false , 130 , -1 },
  { "languages\\voicepacks\\voiceb\\flashbang_3_voiceb.wav" , 1.000544f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_8.wav" , 1.000680f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\helicopter_sight_1_voicea.wav" , 1.000726f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\helicopter_sight_1_voiceb.wav" , 1.000726f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\helicopter_sight_1_voicec.wav" , 1.000726f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_flank_left_3_voiced.wav" , 1.000726f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\helicopter_sight_1_voiced.wav" , 1.000726f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_6_voicea.wav" , 1.001361f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_alone_2_voiced.wav" , 1.001361f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\vehicle_in_5_voiceb.wav" , 1.001859f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_8_voiced.wav" , 1.002494f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_1_voiced.wav" , 1.003492f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\flashbang_5_voiced.wav" , 1.003492f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_2_voiced.wav" , 1.004263f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_group_1_voiced.wav" , 1.004308f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_7.wav" , 1.004399f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\pain_11.wav" , 1.004580f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_3_voicea.wav" , 1.005669f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_i_6.wav" , 1.005941f , false , 131 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_5_voicec.wav" , 1.006122f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_group_4_voiceb.wav" , 1.007120f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_5_voiceb.wav" , 1.007120f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_advance_right_2_voicea.wav" , 1.008571f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_17_voicea.wav" , 1.008662f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_2_voiceb.wav" , 1.010023f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_go_get_4_voicea.wav" , 1.010068f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_g_4.wav" , 1.011474f , false , 132 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8a.wav" , 1.011474f , false , 133 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_i_6.wav" , 1.012653f , false , 134 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_35_voiceb.wav" , 1.012925f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_al_3_voicea.wav" , 1.012971f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_22.wav" , 1.013107f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_seen_group_3_voiceb.wav" , 1.013560f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alarm_alone_4.wav" , 1.014195f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_group_3_voicea.wav" , 1.014376f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_14_voicec.wav" , 1.015828f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_1_voicea.wav" , 1.015873f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_2_voiced.wav" , 1.015873f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\mandown_alone_2_voicea.wav" , 1.016327f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_10_voicea.wav" , 1.017324f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_2_group_voiced.wav" , 1.017370f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\mandown_group_1_voiced.wav" , 1.017370f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\flashbang_3_voicea.wav" , 1.017778f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_c_1.wav" , 1.018730f , false , 135 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_group_4_voicea.wav" , 1.018730f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_10_voicec.wav" , 1.018730f , false , -1 , -1 },
  { "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c3_a1.wav" , 1.020000f , false , -1 , 2 },
  { "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c3_d1.wav" , 1.020000f , false , -1 , 3 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_a_2bi.wav" , 1.020181f , false , 136 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_14_voiceb.wav" , 1.021224f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_f_2.wav" , 1.021769f , false , 137 , -1 },
  { "languages\\voicepacks\\voicea\\death_13_voicea.wav" , 1.022086f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_13_voiced.wav" , 1.022086f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_13.wav" , 1.022993f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\affirmative_9.wav" , 1.024444f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_5_voicea.wav" , 1.024580f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_18_voiceb.wav" , 1.024626f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_18_voicec.wav" , 1.024626f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_18_voiced.wav" , 1.024626f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_7.wav" , 1.025215f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_15.wav" , 1.026621f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_16_voiced.wav" , 1.026803f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_12_voicec.wav" , 1.027438f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_9_voicea.wav" , 1.027483f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_al_2_voicea.wav" , 1.027483f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_3_voicec.wav" , 1.029025f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\flashbang_2_voiced.wav" , 1.030385f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_9_voiceb.wav" , 1.031293f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_10.wav" , 1.032880f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alarm_alone_2_voicec.wav" , 1.033243f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\darkness_2_voicec.wav" , 1.033243f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_5_voiced.wav" , 1.033288f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\grenade_2_voiced.wav" , 1.033288f , false , -1 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_3.wav" , 1.034059f , false , 138 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_2_voicec.wav" , 1.034104f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_3_voicec.wav" , 1.034875f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_3_voiced.wav" , 1.034875f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_group_1_voicec.wav" , 1.036145f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_1_voicea.wav" , 1.036190f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_group_4_voicea.wav" , 1.036190f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_macho_7_voicea.wav" , 1.036190f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_seen_gp_3_voiced.wav" , 1.036190f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_10_voiceb.wav" , 1.037370f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\flashbang_1_voicea.wav" , 1.039048f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_group_6_voicea.wav" , 1.039093f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alarm_alone_2_voiced.wav" , 1.039637f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_11_voicec.wav" , 1.040998f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_11_voiced.wav" , 1.040998f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\flashbang_4_voiceb.wav" , 1.041769f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_27_voicea.wav" , 1.041950f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_30_voicea.wav" , 1.041950f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_13_voiceb.wav" , 1.041950f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_7_voiced.wav" , 1.044082f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_13_voicea.wav" , 1.044490f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_4_voiceb.wav" , 1.044853f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_9_voicec.wav" , 1.044853f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_13_voicea.wav" , 1.044898f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\grenade_1_voicea.wav" , 1.044898f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_2_voiceb.wav" , 1.046667f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_l_7.wav" , 1.047755f , false , 139 , -1 },
  { "languages\\voicepacks\\coreworkera\\darkness_2_voicea.wav" , 1.047800f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alarm_group_1_voiced.wav" , 1.047800f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_3_voiced.wav" , 1.047800f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_gp_1_voiced.wav" , 1.047800f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_3.wav" , 1.050023f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_7.wav" , 1.050748f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_6_voicec.wav" , 1.053560f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_4_voiced.wav" , 1.053605f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_15_voiceb.wav" , 1.053832f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_suppress_1_voiced.wav" , 1.054921f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_advance_right_3_voicec.wav" , 1.055601f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_3_voicec.wav" , 1.055646f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\mandown_group_2_voiced.wav" , 1.056281f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_flank_left_2_voiced.wav" , 1.056327f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alarm_group_1_voicec.wav" , 1.056463f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_al_8_voicea.wav" , 1.056508f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_go_get_4_voiceb.wav" , 1.056644f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_4_voicea.wav" , 1.059365f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_g_2.wav" , 1.059592f , false , 140 , -1 },
  { "languages\\voicepacks\\coreworkerd\\flashbang_1_voiced.wav" , 1.060091f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_2.wav" , 1.061814f , false , 141 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_2_group_voiceb.wav" , 1.062268f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alarm_alone_2_voicea.wav" , 1.062313f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_4_voiced.wav" , 1.062313f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_3_voiceb.wav" , 1.062585f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_h_6.wav" , 1.063265f , false , 142 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_macho_6_voicea.wav" , 1.065215f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_11_voicea.wav" , 1.066395f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_3_voiced.wav" , 1.067528f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_group_6_voiced.wav" , 1.067574f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_alone_7_voiceb.wav" , 1.068073f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\darkness_1_voicec.wav" , 1.068073f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_11_voicea.wav" , 1.068118f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\darkness_1_voicea.wav" , 1.068118f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_o_5.wav" , 1.068481f , false , -1 , 4 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_2_voiceb.wav" , 1.069252f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_3_voiced.wav" , 1.069433f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_4_voicec.wav" , 1.069932f , false , -1 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_1.wav" , 1.070249f , false , 143 , -1 },
  { "languages\\voicepacks\\voiceb\\mandown_group_1_voiceb.wav" , 1.070884f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_4_voiceb.wav" , 1.071429f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_4_voicec.wav" , 1.071429f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_4_voiced.wav" , 1.071429f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_13_voiced.wav" , 1.072971f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_6_voicea.wav" , 1.073696f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alarm_group_2_voiced.wav" , 1.073923f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_5_voiced.wav" , 1.075782f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_19.wav" , 1.076372f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_12_voicea.wav" , 1.076599f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_talk_to_4_voiceb.wav" , 1.077098f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_suppress_6_voicea.wav" , 1.077687f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_flank_right_3_voiced.wav" , 1.078549f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_advance_right_2_voiceb.wav" , 1.078685f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alarm_alone_3_voicea.wav" , 1.079683f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_2_voicea.wav" , 1.079728f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_10_voiced.wav" , 1.079728f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\affirmative_6_voiced.wav" , 1.079728f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reloaded_3_voiced.wav" , 1.079728f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_1.wav" , 1.080000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_4.wav" , 1.080000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_6.wav" , 1.080000f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8c.wav" , 1.080249f , false , 144 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_12.wav" , 1.080317f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_talk_to_5_voicec.wav" , 1.082585f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_4_voicea.wav" , 1.082630f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\mandown_group_2_voicea.wav" , 1.082630f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_alone_5_voicec.wav" , 1.082902f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_3_voiceb.wav" , 1.083719f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_11.wav" , 1.084717f , false , 145 , -1 },
  { "languages\\voicepacks\\voicea\\comm_suppress_1_voicea.wav" , 1.085215f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\mandown_alone_2_voiceb.wav" , 1.085488f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_5_voiced.wav" , 1.085533f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_5_voiced.wav" , 1.086712f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_17_voicec.wav" , 1.086848f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_17_voiced.wav" , 1.086848f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_27_voiced.wav" , 1.086848f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\mandown_alone_2_voiced.wav" , 1.086893f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_5_alone_voicec.wav" , 1.087120f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_c_4.wav" , 1.088390f , false , 146 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_3_voicea.wav" , 1.088435f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_15_voicec.wav" , 1.088435f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_4.wav" , 1.088526f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_2_voiceb.wav" , 1.089206f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_34_voicea.wav" , 1.090340f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_1_voicea.wav" , 1.091293f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_group_3_voicea.wav" , 1.091338f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_10_voicea.wav" , 1.091338f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_2_voiced.wav" , 1.091338f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\mandown_group_1_voiced.wav" , 1.091338f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_f_4.wav" , 1.092018f , false , 147 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_4.wav" , 1.094195f , false , 148 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_3_voiced.wav" , 1.094240f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_9_voicea.wav" , 1.094467f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_3_voicec.wav" , 1.094785f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_macho_8_voicea.wav" , 1.095692f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_group_3.wav" , 1.095964f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alarm_alone_2_voiced.wav" , 1.097143f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_a_4.wav" , 1.097460f , false , 149 , -1 },
  { "languages\\missiontalk\\control\\control_generic_a_1.wav" , 1.098005f , false , 150 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_7_voiced.wav" , 1.098005f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_group_1_voiceb.wav" , 1.098141f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_pickup_a_2.wav" , 1.100000f , false , 151 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_go_get_4_voicec.wav" , 1.100000f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_5.wav" , 1.100907f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_a_7.wav" , 1.102177f , false , 152 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_5.wav" , 1.102630f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\mandown_group_3_voicea.wav" , 1.102948f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_11_voiced.wav" , 1.102948f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_15_voiced.wav" , 1.103583f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\darkness_3_voicea.wav" , 1.105850f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\darkness_4_voicea.wav" , 1.105850f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_5.wav" , 1.106077f , false , 153 , -1 },
  { "languages\\voicepacks\\voiced\\comm_advance_right_1_voiced.wav" , 1.106349f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_16_voiced.wav" , 1.106893f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_11_voiceb.wav" , 1.107075f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_1_voiced.wav" , 1.108345f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_1_alone_voicea.wav" , 1.108707f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_talk_to_4_voicea.wav" , 1.108707f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_group_3_voiced.wav" , 1.108753f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\mandown_alone_1_voiced.wav" , 1.108753f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_16.wav" , 1.110023f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_10_voicec.wav" , 1.110975f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_talk_to_4_voicec.wav" , 1.111610f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_4_voiced.wav" , 1.111882f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\affirmative_10_voicea.wav" , 1.112200f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_5_voiced.wav" , 1.112517f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_13.wav" , 1.112925f , false , 154 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_alone_7_voicec.wav" , 1.113696f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_generic_3_voicea.wav" , 1.114558f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_generic_3_voiceb.wav" , 1.114558f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_generic_3_voicec.wav" , 1.114558f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_generic_3_voiced.wav" , 1.114558f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_i_4.wav" , 1.114649f , false , 155 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_1_voicec.wav" , 1.115646f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_seen_group_3_voiced.wav" , 1.115782f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_7_voicea.wav" , 1.117415f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_20_voicec.wav" , 1.117460f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_20_voiced.wav" , 1.117460f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_28_voicea.wav" , 1.118730f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_4_voiced.wav" , 1.120363f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_group_4_voiced.wav" , 1.120363f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_16.wav" , 1.122358f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_13_voiced.wav" , 1.123311f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\affirmative_6_voiceb.wav" , 1.125488f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alarm_group_2_voicec.wav" , 1.126122f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_group_5_voicea.wav" , 1.126168f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_20_voicea.wav" , 1.126621f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_20_voiceb.wav" , 1.126621f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_20_voicec.wav" , 1.126621f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_20_voiced.wav" , 1.126621f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\flashbang_5_voicea.wav" , 1.128254f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\vehicle_in_4_voiceb.wav" , 1.129161f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_4_voiceb.wav" , 1.129206f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_5.wav" , 1.129751f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_alone_7_voicea.wav" , 1.131927f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_7_voiceb.wav" , 1.131927f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_tell_get_5_voicea.wav" , 1.131973f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_g_3.wav" , 1.132336f , false , 156 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_7_voicea.wav" , 1.133424f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_8_voicea.wav" , 1.133424f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_6.wav" , 1.133605f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_1_voiced.wav" , 1.133923f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alarm_group_1_voiceb.wav" , 1.134104f , false , -1 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_a_4.wav" , 1.134875f , false , 157 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_group_1_voicea.wav" , 1.134875f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\mandown_alone_2_voiced.wav" , 1.137778f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_1_voiceb.wav" , 1.138549f , false , -1 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_3.wav" , 1.138730f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_10.wav" , 1.140000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_6.wav" , 1.140000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_4.wav" , 1.140000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_group_3.wav" , 1.140000f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_b_1.wav" , 1.140454f , false , 158 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_pickup_b_1.wav" , 1.140635f , false , 159 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_1_voiced.wav" , 1.140680f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_1_voiceb.wav" , 1.141179f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_3_voiceb.wav" , 1.141723f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\darkness_4_voicea.wav" , 1.141995f , false , -1 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_c_5.wav" , 1.142177f , false , 160 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8d.wav" , 1.142200f , false , 161 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_group_3_voiced.wav" , 1.142721f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_d_1.wav" , 1.142812f , false , 162 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_14_voicea.wav" , 1.143175f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alarm_alone_2_voiceb.wav" , 1.143537f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_5_voiced.wav" , 1.143583f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_go_get_4_voiced.wav" , 1.143583f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_9_voicec.wav" , 1.144263f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_2_voiced.wav" , 1.145261f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_2_voicec.wav" , 1.145397f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_2_voiced.wav" , 1.145397f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_4_voiceb.wav" , 1.146168f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_retreat_2_voicec.wav" , 1.146440f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_alone_1_voiced.wav" , 1.146485f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_6_voiced.wav" , 1.146485f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_14_voiceb.wav" , 1.146803f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_3_voicea.wav" , 1.147075f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_m_3.wav" , 1.147347f , false , 163 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_10_voiced.wav" , 1.148027f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_talk_to_3_voicea.wav" , 1.149388f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_11_voicea.wav" , 1.149433f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\darkness_3_voicea.wav" , 1.150385f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_go_get_4_voiced.wav" , 1.150794f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_1_voiced.wav" , 1.155193f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_15_voiceb.wav" , 1.155873f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_11.wav" , 1.155918f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\receive_fire_group_2.wav" , 1.157551f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_4_voiceb.wav" , 1.157642f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_generic_f_3.wav" , 1.158050f , false , 164 , -1 },
  { "languages\\voicepacks\\val\\yell_1.wav" , 1.158685f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_7_voicec.wav" , 1.158866f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_30_voicec.wav" , 1.159138f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_30_voiced.wav" , 1.159138f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_talk_to_4_voiced.wav" , 1.159138f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_2_voiced.wav" , 1.160998f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_1_voiced.wav" , 1.160998f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_fear_4_voiced.wav" , 1.160998f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_generic_b_1.wav" , 1.161950f , false , 165 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_b_1.wav" , 1.161950f , false , 166 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_d_4.wav" , 1.162812f , false , 167 , -1 },
  { "languages\\voicepacks\\voicec\\comm_suppress_5_voicec.wav" , 1.163537f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_generic_c_4.wav" , 1.164717f , false , 168 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_c_4.wav" , 1.164717f , false , 169 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_4_voiced.wav" , 1.165170f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_12_voiceb.wav" , 1.166485f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_7_voiceb.wav" , 1.166621f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\flashbang_3_voicea.wav" , 1.166803f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\grenade_1_voiced.wav" , 1.166803f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_b_4.wav" , 1.168844f , false , -1 , 5 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_5_voicea.wav" , 1.169660f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_group_4_voiced.wav" , 1.169705f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_2.wav" , 1.170023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_group_6.wav" , 1.171565f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_a_1.wav" , 1.172290f , false , 170 , -1 },
  { "languages\\voicepacks\\coreworkerd\\mandown_group_2_voiced.wav" , 1.172608f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_14_voiced.wav" , 1.173061f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_16_voiceb.wav" , 1.173832f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_h_3.wav" , 1.174014f , false , 171 , -1 },
  { "languages\\voicepacks\\coreworkerd\\flashbang_3_voiced.wav" , 1.175510f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_d_5.wav" , 1.176553f , false , 172 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_12.wav" , 1.178367f , false , 173 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_20_voicea.wav" , 1.178367f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\flashbang_5_voiceb.wav" , 1.178367f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_advance_left_2_voiceb.wav" , 1.179773f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_3_voiceb.wav" , 1.180091f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_3_voicec.wav" , 1.180091f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_3_voiced.wav" , 1.180091f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\comm_advance_left_3_voicec.wav" , 1.180363f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\vehicle_in_1_voiceb.wav" , 1.182268f , false , -1 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_c_4.wav" , 1.183447f , false , 174 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_10.wav" , 1.183628f , false , 175 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_9_voicea.wav" , 1.184218f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_seen_gp_1_voiced.wav" , 1.184218f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_14_voicec.wav" , 1.184853f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_14_voiced.wav" , 1.184853f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_2.wav" , 1.185215f , false , 176 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_19_voiceb.wav" , 1.185215f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_19_voicec.wav" , 1.185215f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_19_voiced.wav" , 1.185215f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\darkness_2_voiceb.wav" , 1.185669f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_4_voiceb.wav" , 1.186168f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_b_2.wav" , 1.186576f , false , 177 , -1 },
  { "languages\\voicepacks\\voiced\\comm_advance_right_2_voiced.wav" , 1.186939f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_2_voiced.wav" , 1.187120f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_gp_3_voiced.wav" , 1.187120f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_attention_3.wav" , 1.187619f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_17_voiceb.wav" , 1.189887f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_b_2_b.wav" , 1.189977f , false , 178 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_b_4.wav" , 1.189977f , false , 179 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_combat_alone_4_voicec.wav" , 1.189977f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_15.wav" , 1.191519f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_9_voiceb.wav" , 1.192608f , false , -1 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_c_2.wav" , 1.192880f , false , 180 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_1_voiceb.wav" , 1.192880f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_attention_2.wav" , 1.193424f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\flashlight_face_1_voicea.wav" , 1.194376f , false , -1 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_b_4.wav" , 1.195782f , false , 181 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_4.wav" , 1.195782f , false , 182 , -1 },
  { "languages\\voicepacks\\voicec\\combat_to_alert_alone_7_voicec.wav" , 1.195782f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_5_voicec.wav" , 1.195782f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_macho_2_voiced.wav" , 1.195828f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_13.wav" , 1.195918f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\receive_fire_alone_5.wav" , 1.195918f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_14_voicea.wav" , 1.196009f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_11_voiceb.wav" , 1.196145f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_1_group_voicea.wav" , 1.196871f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_d_1.wav" , 1.197234f , false , 183 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_group_4_voiceb.wav" , 1.197460f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_group_6_voiced.wav" , 1.198730f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_4_voiceb.wav" , 1.199637f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_14.wav" , 1.199979f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_5.wav" , 1.200000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_11.wav" , 1.200000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_14.wav" , 1.200000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_1.wav" , 1.200000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_5.wav" , 1.200000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_2_alert_seen_group_1.wav" , 1.200000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_4.wav" , 1.200000f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_14_voiced.wav" , 1.200000f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_b_5.wav" , 1.200680f , false , 184 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_group_6_voiceb.wav" , 1.201270f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_3_voicea.wav" , 1.201633f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_4_voicea.wav" , 1.201633f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\receive_fire_group_5_voicea.wav" , 1.201633f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_m_8.wav" , 1.202902f , false , 185 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_1_voiced.wav" , 1.203084f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_1_voiced.wav" , 1.203401f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alarm_group_2_voicea.wav" , 1.204535f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_group_6_voiced.wav" , 1.204535f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_7.wav" , 1.205941f , false , 186 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_8_voicea.wav" , 1.206485f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\grenade_5_alone_voicea.wav" , 1.206893f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_1_alone_voicec.wav" , 1.207392f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_3_voicea.wav" , 1.207438f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_3_voiced.wav" , 1.207438f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_3_voiced.wav" , 1.207438f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_macho_7_voiced.wav" , 1.207438f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_3_voiced.wav" , 1.207800f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_3.wav" , 1.208798f , false , 187 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_group_1_voiced.wav" , 1.209569f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_6_voicea.wav" , 1.210295f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alarm_group_1_voiced.wav" , 1.210567f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_5.wav" , 1.211429f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_alone_12_voiced.wav" , 1.211973f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_5_voiced.wav" , 1.212472f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_e_1.wav" , 1.212698f , false , 188 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_12_voiceb.wav" , 1.212925f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_group_2_voicec.wav" , 1.213197f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_combat_alone_4_voiceb.wav" , 1.213424f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\flashbang_6_voiceb.wav" , 1.213469f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_7.wav" , 1.215692f , false , 189 , -1 },
  { "languages\\voicepacks\\voicea\\darkness_1_voicea.wav" , 1.216100f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\darkness_2_voiced.wav" , 1.216145f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_3_voiced.wav" , 1.216145f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_3.wav" , 1.217506f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_3.wav" , 1.218005f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\darkness_4_voicec.wav" , 1.219002f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_a_7.wav" , 1.219592f , false , 190 , -1 },
  { "languages\\voicepacks\\voicec\\vehicle_in_2_voicec.wav" , 1.220998f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_group_2.wav" , 1.221270f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_a_5.wav" , 1.223039f , false , 191 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_tell_get_3_voicea.wav" , 1.224853f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_10_voiced.wav" , 1.225714f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_8_voiceb.wav" , 1.226077f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alarm_group_1_voicea.wav" , 1.227710f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alarm_alone_3_voicec.wav" , 1.227710f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_3_voiced.wav" , 1.227755f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\flashbang_6_voicec.wav" , 1.228163f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_12_voiced.wav" , 1.228435f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_5_voiceb.wav" , 1.228753f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\death_6_voiced.wav" , 1.229615f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_16.wav" , 1.230023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_9.wav" , 1.230023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_group_2.wav" , 1.230023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_group_1.wav" , 1.230023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_2.wav" , 1.231066f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_6_voiceb.wav" , 1.232744f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_group_2.wav" , 1.233379f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_group_1.wav" , 1.234195f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_8_voicec.wav" , 1.234422f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_8.wav" , 1.236327f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_30_voiceb.wav" , 1.236417f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\yell_macho_2_voicea.wav" , 1.236463f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\vehicle_in_2_voiced.wav" , 1.236961f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_h_2.wav" , 1.238186f , false , 192 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_14_voicea.wav" , 1.238322f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alarm_alone_3_voiced.wav" , 1.238367f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_12.wav" , 1.239320f , false , 193 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_a_1.wav" , 1.240227f , false , 194 , -1 },
  { "languages\\voicepacks\\mutantvoice\\grenade_4.wav" , 1.240816f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_18.wav" , 1.241950f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_3_voiceb.wav" , 1.242222f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_2_voicea.wav" , 1.242268f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_to_alert_al_7_voicea.wav" , 1.242268f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_a_2.wav" , 1.242540f , false , 195 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_3.wav" , 1.243673f , false , 196 , -1 },
  { "languages\\voicepacks\\coreworkera\\flashlight_face_2_voicea.wav" , 1.243719f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_14_voiceb.wav" , 1.243946f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\darkness_4_voiceb.wav" , 1.244535f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_h_4.wav" , 1.244580f , false , 197 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_6_voiceb.wav" , 1.244943f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_6_voicec.wav" , 1.244943f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_6_voiced.wav" , 1.244943f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_c_2.wav" , 1.245125f , false , 198 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_17_voicea.wav" , 1.245125f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_i_2.wav" , 1.245397f , false , 199 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_b_2.wav" , 1.250522f , false , 200 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_14_voiceb.wav" , 1.250658f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\flashbang_6_voicea.wav" , 1.250930f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_suppress_2_voiceb.wav" , 1.250930f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_14_voicec.wav" , 1.250930f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_21.wav" , 1.252290f , false , 201 , -1 },
  { "languages\\voicepacks\\voiced\\flashbang_6_voiced.wav" , 1.253696f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_11.wav" , 1.253832f , false , 202 , -1 },
  { "languages\\voicepacks\\voiced\\comm_advance_left_1_voiced.wav" , 1.253968f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_4_voicea.wav" , 1.254014f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_a_6.wav" , 1.254376f , false , 203 , -1 },
  { "languages\\voicepacks\\voicec\\comm_suppress_2_voicec.wav" , 1.254739f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_a_4.wav" , 1.255057f , false , 204 , -1 },
  { "languages\\voicepacks\\jack\\death_17.wav" , 1.258458f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_10_voiceb.wav" , 1.258821f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_22_voicec.wav" , 1.259229f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_22_voiced.wav" , 1.259229f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_13.wav" , 1.260000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_1.wav" , 1.260181f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_8_voicea.wav" , 1.261088f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_suppress_4_voiced.wav" , 1.261995f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_5.wav" , 1.262540f , false , 205 , -1 },
  { "languages\\voicepacks\\mutantvoice\\grenade_2.wav" , 1.262540f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_a_1.wav" , 1.262585f , false , 206 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reloaded_2_voiced.wav" , 1.262585f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_5.wav" , 1.263628f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_c_5.wav" , 1.264807f , false , 207 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_5_voiced.wav" , 1.265488f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_3_voiced.wav" , 1.265488f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_45_voiceb.wav" , 1.265714f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_5_voicea.wav" , 1.266848f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_i_4.wav" , 1.266893f , false , 208 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_18_voicea.wav" , 1.268345f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_retreat_2_voicea.wav" , 1.269070f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_13.wav" , 1.269478f , false , 209 , -1 },
  { "languages\\voicepacks\\voiceb\\death_5_voiceb.wav" , 1.270522f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_attention_1_voicec.wav" , 1.270658f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_talk_to_5_voiceb.wav" , 1.271111f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_3_voicea.wav" , 1.271247f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_5_voiced.wav" , 1.271293f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_advance_left_3_voiceb.wav" , 1.271338f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_alone_3_voiced.wav" , 1.272018f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\following_player_a1.wav" , 1.274150f , false , 210 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_14_voicea.wav" , 1.274150f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_14_voiced.wav" , 1.274195f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_40_voicea.wav" , 1.275646f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_i_2.wav" , 1.276825f , false , 211 , -1 },
  { "languages\\voicepacks\\voicea\\alarm_group_2_voicea.wav" , 1.277052f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_7_voiced.wav" , 1.278685f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_m_7.wav" , 1.279819f , false , 212 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_45_voicec.wav" , 1.279955f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\darkness_3_voicec.wav" , 1.279955f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_45_voiced.wav" , 1.279955f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_23_voicec.wav" , 1.282313f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_23_voiced.wav" , 1.282313f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_34_voicec.wav" , 1.282358f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_34_voiced.wav" , 1.282358f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_suppress_5_voicea.wav" , 1.283719f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_c_2.wav" , 1.284354f , false , 213 , -1 },
  { "languages\\missiontalk\\swamp\\go_to_waypoint_a1.wav" , 1.287211f , false , 214 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_34_voiceb.wav" , 1.288571f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_9.wav" , 1.288662f , false , 215 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_7_voiced.wav" , 1.289796f , false , -1 , -1 },
  { "languages\\missiontalk\\mp_jungle\\mp_jungle_c3_d1.wav" , 1.290023f , false , -1 , 6 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_3.wav" , 1.290023f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\grenade_1_group_voicec.wav" , 1.291247f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_group_4_voiced.wav" , 1.291610f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_5_alone_voiced.wav" , 1.292562f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_28_voicec.wav" , 1.292608f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_28_voiced.wav" , 1.292608f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_f_4.wav" , 1.293016f , false , 216 , -1 },
  { "languages\\voicepacks\\jack\\death_14.wav" , 1.293696f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_b_7.wav" , 1.293923f , false , 217 , -1 },
  { "languages\\voicepacks\\coreworkerd\\flashlight_face_1_voiced.wav" , 1.294512f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_44_voiceb.wav" , 1.295147f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_4_voicec.wav" , 1.296689f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_25_voicec.wav" , 1.297460f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_25_voiced.wav" , 1.297460f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_18_voiceb.wav" , 1.298095f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_suppress_6_voiced.wav" , 1.298141f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_supress_2r_voicea.wav" , 1.298866f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\comm_supress_2_voicea.wav" , 1.298866f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_group_3_voiced.wav" , 1.300317f , false , -1 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_a_5.wav" , 1.300408f , false , 218 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_12_voiced.wav" , 1.303220f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_group_4_voiced.wav" , 1.303673f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_generic_4_voicea.wav" , 1.304444f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_generic_4_voiceb.wav" , 1.304444f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_generic_4_voicec.wav" , 1.304444f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_generic_4_voiced.wav" , 1.304444f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_1.wav" , 1.304626f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\death_5_voicec.wav" , 1.304671f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_5.wav" , 1.306077f , false , 219 , -1 },
  { "languages\\missiontalk\\training\\training_generic_a_6.wav" , 1.306485f , false , 220 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_8.wav" , 1.308254f , false , 221 , -1 },
  { "languages\\voicepacks\\voicea\\combat_to_alert_alone_10_voicea.wav" , 1.308980f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_suppress_5_voiceb.wav" , 1.311020f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alarm_alone_3_voiceb.wav" , 1.313152f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_9.wav" , 1.313424f , false , -1 , 7 },
  { "languages\\voicepacks\\voiceb\\combat_group_9_voiceb.wav" , 1.314104f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_9_voicec.wav" , 1.314104f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_9_voiced.wav" , 1.314104f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_group_5_voiced.wav" , 1.314830f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\darkness_2_voiced.wav" , 1.314830f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_15_voicea.wav" , 1.315147f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_f_4.wav" , 1.315420f , false , 222 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_3.wav" , 1.320000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_2.wav" , 1.320045f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_40_voicec.wav" , 1.320272f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_40_voiced.wav" , 1.320272f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_4_voiced.wav" , 1.320363f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\seek_target_a2.wav" , 1.320590f , false , 223 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_4_voiced.wav" , 1.320635f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_8_voicea.wav" , 1.322993f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_16_voicea.wav" , 1.323129f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_14.wav" , 1.323175f , false , 224 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_11_voiced.wav" , 1.323175f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_6_voiced.wav" , 1.323175f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\still_someone_a2.wav" , 1.323492f , false , 225 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_6.wav" , 1.323492f , false , 226 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_20_voiceb.wav" , 1.324807f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_39_voicec.wav" , 1.325034f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_39_voiced.wav" , 1.325034f , false , -1 , -1 },
  { "languages\\voicepacks\\jack\\death_21.wav" , 1.325760f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\mandown_group_3_voiced.wav" , 1.326440f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_8.wav" , 1.327937f , false , 227 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_6_voiced.wav" , 1.329342f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_1_voiced.wav" , 1.329342f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\comm_retreat_3.wav" , 1.332063f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_23_voiceb.wav" , 1.332562f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_5_voiced.wav" , 1.334014f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_19.wav" , 1.335102f , false , 228 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_20_voiceb.wav" , 1.335147f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_20_voicec.wav" , 1.335147f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_20_voiced.wav" , 1.335147f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_group_2.wav" , 1.335193f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_alone_7_voiceb.wav" , 1.337007f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_pickup_b_3.wav" , 1.338005f , false , 229 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_g_4.wav" , 1.338277f , false , 230 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_a_2.wav" , 1.340907f , false , 231 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_go_get_5_voicea.wav" , 1.340952f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_3_voiced.wav" , 1.343855f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_h_6bis.wav" , 1.344354f , false , 232 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_16_voicea.wav" , 1.346349f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\darkness_1_voiceb.wav" , 1.346395f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_d_7.wav" , 1.346712f , false , 233 , -1 },
  { "languages\\missiontalk\\research\\research_generic_a_4.wav" , 1.346712f , false , 234 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_c_6.wav" , 1.348617f , false , 235 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_4.wav" , 1.350023f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_2_alert_seen_group_3.wav" , 1.350023f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_43_voiceb.wav" , 1.350794f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_c_7.wav" , 1.350930f , false , 236 , -1 },
  { "languages\\voicepacks\\voiced\\mandown_group_3_voiced.wav" , 1.352336f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_14_voicea.wav" , 1.352562f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_macho_3_voiced.wav" , 1.352562f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_2_alert_seen_group_2.wav" , 1.352608f , false , -1 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_17.wav" , 1.354014f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\grenade_3.wav" , 1.355102f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_c_3.wav" , 1.355420f , false , 237 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_16_voiceb.wav" , 1.355420f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alarm_group_2_voiced.wav" , 1.356508f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_1_group_voiced.wav" , 1.356508f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_39_voiceb.wav" , 1.356735f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_advance_right_3_voiceb.wav" , 1.357868f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_group_2_voiced.wav" , 1.357914f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_12_voicea.wav" , 1.358367f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_advance_left_3_voiced.wav" , 1.359320f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_2_voicea.wav" , 1.361270f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_c_1.wav" , 1.364444f , false , 238 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_c_3.wav" , 1.368254f , false , 239 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_l_7.wav" , 1.368481f , false , 240 , -1 },
  { "languages\\missiontalk\\swamp\\seek_target_a3.wav" , 1.368481f , false , 241 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_5.wav" , 1.369252f , false , 242 , -1 },
  { "languages\\voicepacks\\voiceb\\alarm_group_2_voiceb.wav" , 1.369705f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_j_5.wav" , 1.369932f , false , 243 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_9_voiced.wav" , 1.370431f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_1_group_voiceb.wav" , 1.372018f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_20.wav" , 1.372834f , false , 244 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_f3.wav" , 1.373197f , false , 245 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_group_6_voicea.wav" , 1.375782f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\grenade_1_alone_voiced.wav" , 1.375964f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_to_alert_alone_6_voiceb.wav" , 1.377596f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_1.wav" , 1.378639f , false , 246 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_45_voicea.wav" , 1.378821f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_4.wav" , 1.380000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_6.wav" , 1.380000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_2.wav" , 1.380000f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_37_voiceb.wav" , 1.380363f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\receive_fire_group_4_voicea.wav" , 1.381043f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_go_get_2_voicec.wav" , 1.381542f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_group_3_voicea.wav" , 1.383719f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_generic_6_voicea.wav" , 1.384308f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_generic_6_voiceb.wav" , 1.384308f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_generic_6_voicec.wav" , 1.384308f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_generic_6_voiced.wav" , 1.384308f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_h_2.wav" , 1.384717f , false , 247 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_5_voiceb.wav" , 1.384989f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_4.wav" , 1.386440f , false , 248 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_i_1.wav" , 1.387347f , false , 249 , -1 },
  { "languages\\voicepacks\\coreworkerd\\flashlight_face_2_voiced.wav" , 1.387392f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\vehicle_in_6_voicec.wav" , 1.389070f , false , -1 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_17.wav" , 1.389252f , false , 250 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_11_voiceb.wav" , 1.390476f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_11_voicec.wav" , 1.390476f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_11_voiced.wav" , 1.390476f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_suppress_2_voicea.wav" , 1.390748f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_advance_left_3_voicea.wav" , 1.393061f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_22_voiceb.wav" , 1.393152f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\darkness_1_voiced.wav" , 1.393197f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_j_4.wav" , 1.393333f , false , 251 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_27_voiceb.wav" , 1.393333f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_28_voiceb.wav" , 1.393333f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_7_voicec.wav" , 1.398367f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_7_voiced.wav" , 1.398367f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_b_4.wav" , 1.398957f , false , 252 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_25_voicea.wav" , 1.398957f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_al_6_voicea.wav" , 1.399002f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_5_voiceb.wav" , 1.399955f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\vehicle_in_6_voiceb.wav" , 1.400998f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_m_1.wav" , 1.403220f , false , 253 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_group_6_voiced.wav" , 1.403311f , false , -1 , -1 },
  { "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c3_d1.wav" , 1.403900f , false , -1 , 8 },
  { "languages\\voicepacks\\voicea\\yell_macho_4_voicea.wav" , 1.404762f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\bulletrain_alone_4_voicea.wav" , 1.404807f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_3_voiced.wav" , 1.404807f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_7_voiced.wav" , 1.404807f , false , -1 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_b_3.wav" , 1.407075f , false , 254 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_8_voiceb.wav" , 1.408798f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_c_3.wav" , 1.409342f , false , 255 , -1 },
  { "languages\\voicepacks\\voiced\\comm_advance_right_3_voiced.wav" , 1.409342f , false , -1 , -1 },
  { "languages\\missiontalk\\mp_lake\\mp_lake_c3_d1.wav" , 1.410023f , false , -1 , 9 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_2.wav" , 1.410023f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_6.wav" , 1.410295f , false , 256 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_2.wav" , 1.410522f , false , 257 , -1 },
  { "languages\\voicepacks\\mutantvoice\\receive_fire_group_1.wav" , 1.410522f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\darkness_4_voiced.wav" , 1.410612f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_macho_4_voiced.wav" , 1.410612f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_b_1.wav" , 1.411111f , false , 258 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_41_voicec.wav" , 1.411655f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_41_voiced.wav" , 1.411655f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_5.wav" , 1.413061f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_b_1.wav" , 1.413469f , false , 259 , -1 },
  { "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_6_voicec.wav" , 1.413469f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_6_voicec.wav" , 1.416372f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_15_voicea.wav" , 1.416417f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_e_4.wav" , 1.417415f , false , 260 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_e_4.wav" , 1.417415f , false , 261 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_group_2_voicea.wav" , 1.417823f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\receive_fire_group_3.wav" , 1.418186f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_h_2.wav" , 1.418231f , false , 262 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_43_voicea.wav" , 1.418503f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_10_voicea.wav" , 1.418503f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_18.wav" , 1.419274f , false , 263 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_7_voiced.wav" , 1.419320f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_a_11.wav" , 1.420000f , false , 264 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_25_voiceb.wav" , 1.422041f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_31_voicea.wav" , 1.422313f , false , -1 , -1 },
  { "languages\\missiontalk\\mp_lake\\mp_lake_c3_a1.wav" , 1.423039f , false , -1 , 10 },
  { "languages\\missiontalk\\fort\\fort_specific_a_4.wav" , 1.423401f , false , 265 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_group_3_voicec.wav" , 1.425079f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\receive_fire_group_5_voicec.wav" , 1.425578f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_32_voiceb.wav" , 1.427075f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_23_voicea.wav" , 1.427846f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\following_player_a2.wav" , 1.427982f , false , 266 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_12_voiceb.wav" , 1.427982f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_9_voiceb.wav" , 1.430295f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_15_voiced.wav" , 1.431247f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_player_2_voicea.wav" , 1.431565f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_player_2_voiceb.wav" , 1.431565f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_player_2_voicec.wav" , 1.431565f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_8_voiced.wav" , 1.431565f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_player_2_voiced.wav" , 1.431565f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_10_voiced.wav" , 1.432562f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_16_voiceb.wav" , 1.433560f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_combat_al_4_voicea.wav" , 1.433832f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_6.wav" , 1.434376f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_go_get_4_voicea.wav" , 1.434422f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_22_voicea.wav" , 1.435147f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_d_5.wav" , 1.435964f , false , 267 , -1 },
  { "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_6_voicea.wav" , 1.439592f , false , -1 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_c_2.wav" , 1.439773f , false , 268 , -1 },
  { "languages\\voicepacks\\val\\yell_8.wav" , 1.439909f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_15.wav" , 1.440000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_12.wav" , 1.440000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_4.wav" , 1.440000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_6.wav" , 1.440000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_group_3.wav" , 1.440363f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_4.wav" , 1.440635f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\comm_advance_right_3_voicea.wav" , 1.441043f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\receive_fire_group_8_voiceb.wav" , 1.441043f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_16.wav" , 1.441497f , false , 269 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_g_3.wav" , 1.441497f , false , 270 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_talk_to_5_voicea.wav" , 1.442494f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_7_voiced.wav" , 1.442540f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_b_4.wav" , 1.444354f , false , 271 , -1 },
  { "languages\\voicepacks\\voicea\\death_3_voicea.wav" , 1.445261f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_5.wav" , 1.446848f , false , 272 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_12_voicea.wav" , 1.452880f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_19_voiceb.wav" , 1.453016f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_8_voiceb.wav" , 1.454966f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_8_voicec.wav" , 1.454966f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_8_voiced.wav" , 1.454966f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_5_alone_voiceb.wav" , 1.455102f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_16_voiced.wav" , 1.455193f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_c_6.wav" , 1.456281f , false , 273 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_6_voicea.wav" , 1.456553f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_12_voicec.wav" , 1.456599f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_12_voiced.wav" , 1.456599f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_c_8.wav" , 1.457007f , false , 274 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_b_1.wav" , 1.459365f , false , 275 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_1.wav" , 1.462358f , false , -1 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_b_3.wav" , 1.462812f , false , 276 , -1 },
  { "languages\\voicepacks\\jack\\death_2.wav" , 1.463039f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_37_voicec.wav" , 1.463946f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_37_voiced.wav" , 1.463946f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\darkness_1_voiced.wav" , 1.464943f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_a_4.wav" , 1.464989f , false , 277 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_19_voicea.wav" , 1.465714f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_9.wav" , 1.470023f , false , -1 , 11 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_7.wav" , 1.470023f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_a_1.wav" , 1.470748f , false , 278 , -1 },
  { "languages\\missiontalk\\training\\training_generic_l_8.wav" , 1.472018f , false , 279 , -1 },
  { "languages\\voicepacks\\voicea\\searching_mutants_3_voicea.wav" , 1.473288f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_mutants_3_voiceb.wav" , 1.473288f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_mutants_3_voicec.wav" , 1.473288f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_mutants_3_voiced.wav" , 1.473288f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_retreat_2_voiceb.wav" , 1.473379f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_5_voicea.wav" , 1.474467f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_1_voiced.wav" , 1.474467f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\mandown_group_4.wav" , 1.480045f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_40_voiceb.wav" , 1.480680f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_14.wav" , 1.481043f , false , 280 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alarm_alone_3.wav" , 1.482721f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_31_voiceb.wav" , 1.483129f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_42_voiceb.wav" , 1.483311f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_17_voiceb.wav" , 1.483628f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_17_voicec.wav" , 1.483628f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_17_voiced.wav" , 1.483628f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_generic_b_2.wav" , 1.487483f , false , 281 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_4_voiced.wav" , 1.488571f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_3.wav" , 1.491383f , false , 282 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_12_voicea.wav" , 1.491837f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_6_voicea.wav" , 1.491882f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\receive_fire_group_5_voiced.wav" , 1.494785f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_h_3.wav" , 1.495510f , false , 283 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_supress_2r_voiced.wav" , 1.497687f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\comm_supress_2_voiced.wav" , 1.497687f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_11.wav" , 1.498231f , false , 284 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_1.wav" , 1.500000f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\comm_supress_2.wav" , 1.500680f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_a_2.wav" , 1.500816f , false , 285 , -1 },
  { "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c3_a1.wav" , 1.500907f , false , -1 , 12 },
  { "languages\\voicepacks\\voicec\\combat_alone_29_voicec.wav" , 1.501088f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_29_voiced.wav" , 1.501088f , false , -1 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_15.wav" , 1.501315f , false , 286 , -1 },
  { "languages\\voicepacks\\voiceb\\alarm_alone_4_voiceb.wav" , 1.503175f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_18.wav" , 1.503401f , false , 287 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_1.wav" , 1.504853f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_d_4.wav" , 1.507800f , false , 288 , -1 },
  { "languages\\missiontalk\\training\\training_generic_m_5.wav" , 1.508571f , false , 289 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_6_voicea.wav" , 1.508571f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_alone_2.wav" , 1.509116f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_1.wav" , 1.510295f , false , 290 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_18_voicec.wav" , 1.512200f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_18_voiced.wav" , 1.512200f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_b_6.wav" , 1.513741f , false , 291 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_group_6.wav" , 1.513923f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_8_voiced.wav" , 1.514966f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_13_voicea.wav" , 1.515057f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_talk_to_1_voicec.wav" , 1.515057f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_5_voicea.wav" , 1.515102f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_talk_to_1_voicea.wav" , 1.515102f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_5_voiced.wav" , 1.515102f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_d_2.wav" , 1.516372f , false , 292 , -1 },
  { "languages\\voicepacks\\voiceb\\darkness_3_voiceb.wav" , 1.516961f , false , -1 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_a_5.wav" , 1.517370f , false , -1 , 13 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_group_5_voicec.wav" , 1.520862f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\combat_alone_8_voicea.wav" , 1.520907f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_2.wav" , 1.521859f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_8_voiceb.wav" , 1.522540f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_15_voicec.wav" , 1.523764f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_d_2.wav" , 1.524082f , false , 293 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_c_6.wav" , 1.526032f , false , -1 , 14 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_3.wav" , 1.527483f , false , 294 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_pickup_e_4.wav" , 1.528118f , false , 295 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_4_voicec.wav" , 1.528889f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_4_voiced.wav" , 1.528889f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_10_voiceb.wav" , 1.529206f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_10_voicec.wav" , 1.529206f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_10_voiced.wav" , 1.529206f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\flashlight_face_3_voiced.wav" , 1.529615f , false , -1 , -1 },
  { "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_10.wav" , 1.530023f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_2.1.wav" , 1.530612f , false , 296 , -1 },
  { "languages\\voicepacks\\voiced\\vehicle_in_6_voiced.wav" , 1.531655f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_7.wav" , 1.532472f , false , 297 , -1 },
  { "languages\\voicepacks\\voiced\\comm_suppress_5_voiced.wav" , 1.534422f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_7.wav" , 1.535601f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_8.wav" , 1.536236f , false , 298 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_8.wav" , 1.536236f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_attention_4.wav" , 1.536463f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_f_4.wav" , 1.538277f , false , -1 , 15 },
  { "languages\\voicepacks\\coreworkera\\reinforce_go_get_3_voicea.wav" , 1.538322f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_1_voiced.wav" , 1.538322f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_8_voiced.wav" , 1.538322f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_10.wav" , 1.539093f , false , 299 , -1 },
  { "languages\\voicepacks\\coreworkerd\\darkness_3_voiced.wav" , 1.541224f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\pain_12_voicea.wav" , 1.542630f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\reinforce_go_get_2_voicea.wav" , 1.544127f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_macho_5_voiced.wav" , 1.544127f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_19_voicec.wav" , 1.548345f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_19_voiced.wav" , 1.548345f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_talk_to_5_voiced.wav" , 1.548345f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_16_voicec.wav" , 1.548934f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_fear_1_voicec.wav" , 1.549116f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_3_voiced.wav" , 1.549932f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_6_voiced.wav" , 1.550748f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_advance_left_2_voiced.wav" , 1.551111f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_suppress_2_voiced.wav" , 1.553878f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_4_voiced.wav" , 1.555737f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_6_voiced.wav" , 1.555737f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_37_voicea.wav" , 1.555918f , false , -1 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_c_4.wav" , 1.557143f , false , 300 , -1 },
  { "languages\\voicepacks\\voicec\\alarm_group_3_voicec.wav" , 1.558594f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_group_3_voiced.wav" , 1.558866f , false , -1 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_a_4.wav" , 1.559320f , false , 301 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_5.wav" , 1.560000f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_16.wav" , 1.561043f , false , 302 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_4.wav" , 1.561043f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\alarm_group_3_voicea.wav" , 1.561542f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_32_voicea.wav" , 1.562132f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\death_6_voiceb.wav" , 1.565442f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_44_voicec.wav" , 1.566576f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_44_voiced.wav" , 1.566576f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_e_3.wav" , 1.568753f , false , 303 , -1 },
  { "languages\\missiontalk\\training\\training_generic_m_9.wav" , 1.568753f , false , 304 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_3.wav" , 1.570295f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_1.wav" , 1.571655f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_group_1_voiced.wav" , 1.573152f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\receive_fire_group_5_voiced.wav" , 1.573379f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_13.wav" , 1.576009f , false , 305 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_42_voicec.wav" , 1.578231f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_42_voiced.wav" , 1.578231f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_13.wav" , 1.579093f , false , 306 , -1 },
  { "languages\\missiontalk\\control\\control_generic_b_5.wav" , 1.585941f , false , 307 , -1 },
  { "languages\\voicepacks\\mutantvoice\\comm_retreat_1.wav" , 1.587029f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_16_voicec.wav" , 1.587256f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_16_voiced.wav" , 1.587256f , false , -1 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_14.wav" , 1.587528f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_11.wav" , 1.587710f , false , 308 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_e_5.wav" , 1.588345f , false , 309 , -1 },
  { "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_3.wav" , 1.590023f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_mutants_4_voicea.wav" , 1.592381f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_mutants_4_voiceb.wav" , 1.592381f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_mutants_4_voicec.wav" , 1.592381f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_mutants_4_voiced.wav" , 1.592381f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_group_1.wav" , 1.592426f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_12_voiceb.wav" , 1.593243f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_12_voicec.wav" , 1.593243f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_12_voiced.wav" , 1.593243f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_n_5.wav" , 1.593424f , false , 310 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_group_4.wav" , 1.594512f , false , -1 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_21.wav" , 1.602132f , false , 311 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_5.wav" , 1.603810f , false , -1 , 16 },
  { "languages\\voicepacks\\voicec\\combat_alone_32_voicec.wav" , 1.609478f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_group_2_voiced.wav" , 1.609478f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_32_voiced.wav" , 1.609478f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_2.wav" , 1.609841f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_4.wav" , 1.609841f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_6.wav" , 1.610884f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_5_voicea.wav" , 1.611066f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\vehicle_in_2_voiceb.wav" , 1.612154f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_to_alert_alone_14_voiced.wav" , 1.612245f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_go_get_2_voiced.wav" , 1.612290f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_4.wav" , 1.612925f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alarm_alone_4_voicec.wav" , 1.613741f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_9.wav" , 1.616644f , false , 312 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_d_2bis.wav" , 1.617823f , false , 313 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_6_voiced.wav" , 1.619592f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\mandown_group_2.wav" , 1.620317f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_7_voicec.wav" , 1.622449f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_i_6.wav" , 1.623401f , false , 314 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_d_2.wav" , 1.626168f , false , 315 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_6.wav" , 1.627256f , false , 316 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_44_voicea.wav" , 1.628254f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_16_voicea.wav" , 1.628254f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_talk_to_1_voiceb.wav" , 1.628254f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alarm_alone_1.wav" , 1.629478f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_5.wav" , 1.632426f , false , 317 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_6.wav" , 1.633288f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_e_6.wav" , 1.636961f , false , 318 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_n_1.wav" , 1.636961f , false , 319 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_4_voicea.wav" , 1.637007f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_go_get_2_voiceb.wav" , 1.637778f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_4.wav" , 1.642585f , false , -1 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_a_6.wav" , 1.646984f , false , 320 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_6.wav" , 1.648435f , false , -1 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_15.wav" , 1.648481f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_2_voiced.wav" , 1.648617f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\grenade_1.wav" , 1.648980f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_group_3.wav" , 1.650975f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_20.wav" , 1.651202f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_macho_1_voiceb.wav" , 1.651383f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_macho_1_voicec.wav" , 1.651383f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_macho_1_voiced.wav" , 1.651383f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_macho_6_voiced.wav" , 1.651519f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_1.wav" , 1.654376f , false , 321 , -1 },
  { "languages\\missiontalk\\jack_10.wav" , 1.657460f , false , 322 , -1 },
  { "languages\\voicepacks\\jack\\death_3.wav" , 1.657959f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_21.wav" , 1.658730f , false , 323 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_combat_alone_15_voiced.wav" , 1.659501f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_1_voiced.wav" , 1.660227f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_group_5.wav" , 1.663084f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_macho_2_voiceb.wav" , 1.665079f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_macho_2_voicec.wav" , 1.665079f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_macho_2_voiced.wav" , 1.665079f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\grenade_1_alone_voiceb.wav" , 1.668481f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_rush_1_voiceb.wav" , 1.671701f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_29_voiceb.wav" , 1.671837f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_29_voicea.wav" , 1.672562f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_23.wav" , 1.673696f , false , 324 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_5_voiceb.wav" , 1.674150f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_43_voicec.wav" , 1.674376f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_43_voiced.wav" , 1.674376f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_31_voicec.wav" , 1.674467f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_31_voiced.wav" , 1.674467f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_group_4_voicec.wav" , 1.674694f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_5.wav" , 1.676735f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_d_3.wav" , 1.677370f , false , 325 , -1 },
  { "languages\\voicepacks\\coreworkera\\idle_alone_song_1_voicea.wav" , 1.677642f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_9.wav" , 1.678730f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_mutants_1_voicea.wav" , 1.684036f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_mutants_1_voiceb.wav" , 1.684036f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_mutants_1_voicec.wav" , 1.684036f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_mutants_1_voiced.wav" , 1.684036f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_4.wav" , 1.684626f , false , -1 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_e_2.wav" , 1.687029f , false , 326 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_4.wav" , 1.687302f , false , 327 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_8_voicec.wav" , 1.687302f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_8_voiced.wav" , 1.687302f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alarm_group_3_voicea.wav" , 1.689206f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\helicopter_sight_8_voicea.wav" , 1.690113f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\helicopter_sight_8_voiceb.wav" , 1.690113f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\helicopter_sight_8_voicec.wav" , 1.690113f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\helicopter_sight_8_voiced.wav" , 1.690113f , false , -1 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_a_2.wav" , 1.690930f , false , 328 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_2.wav" , 1.691338f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_4.wav" , 1.692608f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_7_voiced.wav" , 1.692880f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\darkness_4_voiced.wav" , 1.692880f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_6.wav" , 1.693923f , false , 329 , -1 },
  { "languages\\voicepacks\\mutantvoice\\receive_fire_group_4.wav" , 1.694150f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_3.wav" , 1.694921f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_group_2_voiceb.wav" , 1.697823f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_2.wav" , 1.699909f , false , 330 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_8.wav" , 1.700680f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_alone_6_voiced.wav" , 1.701859f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_6_voiceb.wav" , 1.703537f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_5.wav" , 1.705170f , false , 331 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_f_1.wav" , 1.705397f , false , 332 , -1 },
  { "languages\\voicepacks\\voicec\\death_1_voicec.wav" , 1.705533f , false , -1 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_4.wav" , 1.706621f , false , 333 , -1 },
  { "languages\\voicepacks\\voiced\\darkness_3_voiced.wav" , 1.706757f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\alert_to_idle_alone_8_voicec.wav" , 1.707982f , false , -1 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_e_4.wav" , 1.709252f , false , 334 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_1.wav" , 1.709342f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_4_voiced.wav" , 1.711020f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_1_voicea.wav" , 1.712472f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_1.wav" , 1.712517f , false , 335 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_39_voicea.wav" , 1.712971f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_group_3.wav" , 1.713651f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_10.wav" , 1.715011f , false , 336 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_talk_to_1_voicea.wav" , 1.715329f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_2.wav" , 1.715828f , false , 337 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_3.wav" , 1.716735f , false , 338 , -1 },
  { "languages\\missiontalk\\training\\_training_pickup_a_3.wav" , 1.716735f , false , 339 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_go_get_3_voiced.wav" , 1.717914f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_talk_to_2_voicec.wav" , 1.718231f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alarm_group_3_voiceb.wav" , 1.720680f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_k_2.wav" , 1.720952f , false , -1 , 17 },
  { "languages\\missiontalk\\training\\training_generic_f_2.wav" , 1.723311f , false , 340 , -1 },
  { "languages\\voicepacks\\mutantvoice\\comm_supress_3.wav" , 1.725034f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\comm_rush_1_voiced.wav" , 1.726259f , false , -1 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_11.wav" , 1.726757f , false , -1 , 18 },
  { "languages\\missiontalk\\carrier\\carrier_generic_a_3.wav" , 1.726939f , false , 341 , -1 },
  { "languages\\voicepacks\\voicea\\alarm_alone_4_voicea.wav" , 1.726939f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_41_voicea.wav" , 1.726939f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_group_5_voiceb.wav" , 1.727800f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_a_3.wav" , 1.727937f , false , 342 , -1 },
  { "languages\\missiontalk\\research\\research_specific_d_1b.wav" , 1.729025f , false , 343 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_5_voiced.wav" , 1.729887f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_14_voiceb.wav" , 1.730431f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_14_voicec.wav" , 1.730431f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_14_voiced.wav" , 1.730431f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_a_2.wav" , 1.731293f , false , 344 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_h_6.wav" , 1.733333f , false , 345 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_7.wav" , 1.733923f , false , 346 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_15.wav" , 1.733923f , false , 347 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_2.wav" , 1.735420f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_alone_7_voicea.wav" , 1.735646f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_8_voiced.wav" , 1.735692f , false , -1 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_a_3.wav" , 1.736463f , false , 348 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_13.wav" , 1.738231f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_2_alert_seen_group_1.wav" , 1.738413f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_j_1.wav" , 1.738549f , false , 349 , -1 },
  { "languages\\voicepacks\\voicea\\helicopter_sight_4_voicea.wav" , 1.740136f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\helicopter_sight_4_voiceb.wav" , 1.740136f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\helicopter_sight_4_voicec.wav" , 1.740136f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\helicopter_sight_4_voiced.wav" , 1.740136f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_newpickup_a_6.wav" , 1.740544f , false , -1 , 19 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_7.wav" , 1.740816f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_b_5.wav" , 1.742902f , false , 350 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_group_3_voiceb.wav" , 1.744308f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\alert_to_idle_group_5_voicea.wav" , 1.744354f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_group_4.wav" , 1.745170f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alarm_group_1.wav" , 1.746168f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_c_1.wav" , 1.746395f , false , 351 , -1 },
  { "languages\\voicepacks\\voicec\\comm_rush_1_voicec.wav" , 1.750159f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_5_voiced.wav" , 1.750204f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_7.wav" , 1.750249f , false , 352 , -1 },
  { "languages\\missiontalk\\control\\control_direction_e_3.wav" , 1.751111f , false , 353 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_11.wav" , 1.751111f , false , 354 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_6_voiceb.wav" , 1.753061f , false , -1 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_b_4.wav" , 1.756281f , false , 355 , -1 },
  { "languages\\missiontalk\\training\\training_generic_k_5.wav" , 1.758866f , false , 356 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_6_voicec.wav" , 1.759592f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_6_voiced.wav" , 1.759592f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_7_voiceb.wav" , 1.760363f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_5.wav" , 1.763764f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\yell_attention_1.wav" , 1.763764f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_alone_3.wav" , 1.764399f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\flashlight_face_4_voicea.wav" , 1.764717f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_11.wav" , 1.767574f , false , 357 , -1 },
  { "languages\\voicepacks\\voiced\\alarm_alone_4_voiced.wav" , 1.767937f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_26_voiceb.wav" , 1.768118f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_talk_to_2_voiceb.wav" , 1.773197f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_27.wav" , 1.776054f , false , 358 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_26_voicea.wav" , 1.776281f , false , -1 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_1.wav" , 1.777687f , false , 359 , -1 },
  { "languages\\voicepacks\\mutantvoice\\comm_retreat_2.wav" , 1.778231f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_3.wav" , 1.778685f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_alone_4.wav" , 1.778776f , false , -1 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_b_4.wav" , 1.782086f , false , 360 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_b_7.wav" , 1.782086f , false , 361 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_9.wav" , 1.788027f , false , 362 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_a_2.wav" , 1.788980f , false , 363 , -1 },
  { "languages\\voicepacks\\voiced\\comm_retreat_2_voiced.wav" , 1.790159f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_2_voicea.wav" , 1.790839f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_i_4.wav" , 1.792381f , false , 364 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_42_voicea.wav" , 1.792880f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_2.wav" , 1.795737f , false , 365 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_b_6.wav" , 1.799501f , false , 366 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_14.wav" , 1.804444f , false , 367 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_e_5.wav" , 1.806032f , false , 368 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_15_voiceb.wav" , 1.808209f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_c_8.wav" , 1.813515f , false , 369 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_2.wav" , 1.814014f , false , 370 , -1 },
  { "languages\\voicepacks\\voicec\\death_2_voicec.wav" , 1.819002f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_c_4.wav" , 1.820045f , false , 371 , -1 },
  { "languages\\voicepacks\\coreworkerd\\bulletrain_alone_4_voiced.wav" , 1.828571f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_41_voiceb.wav" , 1.828571f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\seek_target_a1.wav" , 1.829977f , false , 372 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_talk_to_3_voicec.wav" , 1.831429f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_1.wav" , 1.831927f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_go_get_3_voiceb.wav" , 1.836825f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_b_4.wav" , 1.837234f , false , 373 , -1 },
  { "languages\\missiontalk\\training\\training_generic_h_1.wav" , 1.837234f , false , 374 , -1 },
  { "languages\\voicepacks\\voicea\\comm_rush_1_voicea.wav" , 1.837234f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_talk_to_3_voiceb.wav" , 1.837506f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_f_4.wav" , 1.840227f , false , 375 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_6.wav" , 1.845578f , false , 376 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_10.wav" , 1.845760f , false , 377 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_b_2.wav" , 1.847438f , false , 378 , -1 },
  { "languages\\voicepacks\\voiceb\\death_7_voiceb.wav" , 1.847755f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_b_1bis.wav" , 1.850658f , false , 379 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_2_alert_seen_group_3.wav" , 1.850703f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_6.wav" , 1.852608f , false , 380 , -1 },
  { "languages\\voicepacks\\voiceb\\reinforce_go_get_5_voiceb.wav" , 1.854649f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_go_get_5_voiced.wav" , 1.857596f , false , -1 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_12.wav" , 1.859184f , false , 381 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_alone_2.wav" , 1.863084f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_talk_to_2_voicea.wav" , 1.866259f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_4_voicea.wav" , 1.869206f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_f_6.wav" , 1.870612f , false , 382 , -1 },
  { "languages\\missiontalk\\fort\\fort_specific_g_1.wav" , 1.871338f , false , -1 , 20 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_alone_1.wav" , 1.877007f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_4.wav" , 1.879819f , false , 383 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_a_1.wav" , 1.881859f , false , 384 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_2.wav" , 1.883583f , false , 385 , -1 },
  { "languages\\missiontalk\\training\\training_generic_j_3.wav" , 1.883673f , false , 386 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_group_4_voiced.wav" , 1.884218f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_h_4.wav" , 1.885079f , false , 387 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alarm_group_2.wav" , 1.892925f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_b_2.wav" , 1.894603f , false , 388 , -1 },
  { "languages\\missiontalk\\training\\training_generic_k_1.wav" , 1.898186f , false , 389 , -1 },
  { "languages\\voicepacks\\coreworkera\\alert_to_idle_al_7_voicea.wav" , 1.898231f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_generic_c_2.wav" , 1.904127f , false , 390 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_c_2.wav" , 1.904127f , false , 391 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_2.wav" , 1.904989f , false , -1 , 21 },
  { "languages\\voicepacks\\voicea\\reinforce_go_get_2_voicea.wav" , 1.906893f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_d_2.wav" , 1.916236f , false , 392 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_a_4.wav" , 1.919683f , false , 393 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_7_voiceb.wav" , 1.925669f , false , -1 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_g_1.wav" , 1.930113f , false , 394 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_7.wav" , 1.930839f , false , 395 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_f_2.wav" , 1.933016f , false , 396 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_e_6.wav" , 1.935918f , false , 397 , -1 },
  { "languages\\missiontalk\\research\\research_specific_a_6.wav" , 1.936871f , false , 398 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_a_5.wav" , 1.937460f , false , 399 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_o_4x.wav" , 1.939456f , false , 400 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_7_voiced.wav" , 1.944671f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_5_voicec.wav" , 1.945850f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_5_voiced.wav" , 1.945850f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_talk_to_1_voiced.wav" , 1.945850f , false , -1 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_9.wav" , 1.946259f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_36_voiceb.wav" , 1.947574f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_m_2.wav" , 1.949796f , false , 401 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_a_7.wav" , 1.950658f , false , 402 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_d_5.wav" , 1.951746f , false , 403 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_e_2.wav" , 1.952381f , false , 404 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_e_2.wav" , 1.952381f , false , 405 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_15.wav" , 1.956281f , false , -1 , 22 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_go_get_2_voiced.wav" , 1.956281f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\mandown_group_1.wav" , 1.957007f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_i_4.wav" , 1.958231f , false , 406 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_go_get_3_voicec.wav" , 1.959138f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_5.wav" , 1.961995f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_21_voiceb.wav" , 1.962041f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_6_voiceb.wav" , 1.962630f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_a_1ter.wav" , 1.964399f , false , 407 , -1 },
  { "languages\\voicepacks\\voiced\\alarm_group_3_voiced.wav" , 1.968073f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_d_1.wav" , 1.970748f , false , 408 , -1 },
  { "languages\\missiontalk\\training\\training_generic_m_8.wav" , 1.971293f , false , 409 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_2.wav" , 1.972290f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_1.wav" , 1.975692f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_group_5.wav" , 1.976463f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_macho_4_voiceb.wav" , 1.979184f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_macho_4_voicec.wav" , 1.979184f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_macho_4_voiced.wav" , 1.979184f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_26_voicec.wav" , 1.981995f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_26_voiced.wav" , 1.981995f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_2.wav" , 1.984308f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_generic_g_4.wav" , 1.984762f , false , 410 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_g_4.wav" , 1.984762f , false , 411 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alarm_alone_2.wav" , 1.985079f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_b_4.wav" , 1.986712f , false , 412 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_e_4.wav" , 1.988163f , false , 413 , -1 },
  { "languages\\voicepacks\\coreworkerd\\flashlight_face_4_voiced.wav" , 1.988209f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\death_7_voicea.wav" , 1.988299f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\alert_to_idle_group_5_voiced.wav" , 1.988617f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_player_1_voicea.wav" , 1.990113f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_player_1_voiceb.wav" , 1.990113f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_player_1_voicec.wav" , 1.990113f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_player_1_voiced.wav" , 1.990113f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_e_2.wav" , 1.992426f , false , 414 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_go_get_5_voiced.wav" , 1.995873f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_1.wav" , 1.996871f , false , 415 , -1 },
  { "languages\\voicepacks\\voicea\\searching_player_5_voicea.wav" , 1.997551f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_player_5_voiceb.wav" , 1.997551f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_player_5_voicec.wav" , 1.997551f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_player_5_voiced.wav" , 1.997551f , false , -1 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_c_2.wav" , 1.998322f , false , 416 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_c_2.wav" , 1.999501f , false , 417 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_k_4.wav" , 1.999773f , false , 418 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_10.wav" , 2.005079f , false , -1 , 23 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_5_voiced.wav" , 2.008526f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_10.wav" , 2.009161f , false , 419 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_8.wav" , 2.012562f , false , 420 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_6_voiced.wav" , 2.014331f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_12.wav" , 2.015147f , false , 421 , -1 },
  { "languages\\voicepacks\\voicea\\combat_group_15_voicea.wav" , 2.017188f , false , -1 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_a_6.wav" , 2.019501f , false , 422 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_14.wav" , 2.026349f , false , 423 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_36_voicea.wav" , 2.028753f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\reinforce_go_get_5_voicec.wav" , 2.028798f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_alone_15_voiceb.wav" , 2.029841f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_27_voicec.wav" , 2.032200f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_j_2.wav" , 2.034104f , false , 424 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_36_voicec.wav" , 2.034785f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_36_voiced.wav" , 2.034785f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_mutants_6_voicea.wav" , 2.035873f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_mutants_6_voiceb.wav" , 2.035873f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_mutants_6_voicec.wav" , 2.035873f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_mutants_6_voiced.wav" , 2.035873f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_d_8.wav" , 2.036689f , false , 425 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_5.wav" , 2.038367f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_alone_3.wav" , 2.040136f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_3.wav" , 2.048889f , false , -1 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_19.wav" , 2.049932f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_talk_to_3_voicea.wav" , 2.052018f , false , -1 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_7.wav" , 2.052381f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_i_2.wav" , 2.053016f , false , 426 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_3.wav" , 2.053016f , false , 427 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_13_voiceb.wav" , 2.056417f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_13_voicec.wav" , 2.056417f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_13_voiced.wav" , 2.056417f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_21_voicea.wav" , 2.056463f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_21_voicec.wav" , 2.056463f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_21_voiced.wav" , 2.056463f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_a_9.wav" , 2.059365f , false , 428 , -1 },
  { "languages\\missiontalk\\research\\research_generic_k_2.wav" , 2.067619f , false , 429 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_16_voiceb.wav" , 2.072608f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_16_voicec.wav" , 2.072608f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_16_voiced.wav" , 2.072608f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_2.wav" , 2.074649f , false , 430 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_d_1.wav" , 2.076689f , false , 431 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_c_4.wav" , 2.077415f , false , 432 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alarm_group_3_voiced.wav" , 2.078186f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_i_1.wav" , 2.080544f , false , 433 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_6.wav" , 2.084671f , false , 434 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_10.wav" , 2.090204f , false , 435 , -1 },
  { "languages\\voicepacks\\mutantvoice\\mandown_group_3.wav" , 2.090295f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_e_1.wav" , 2.098458f , false , 436 , -1 },
  { "languages\\voicepacks\\voiceb\\alert_to_idle_group_4_voiceb.wav" , 2.098458f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_b_8.wav" , 2.100317f , false , 437 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_5.wav" , 2.103764f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_8.wav" , 2.105488f , false , -1 , 24 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_2.wav" , 2.110068f , false , 438 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_go_get_3_voicea.wav" , 2.110068f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_9.wav" , 2.112653f , false , 439 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_4.wav" , 2.112971f , false , 440 , -1 },
  { "languages\\voicepacks\\mutantvoice\\receive_fire_group_5.wav" , 2.115782f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_7.wav" , 2.115873f , false , 441 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_8.wav" , 2.116780f , false , 442 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_e_4.wav" , 2.120227f , false , 443 , -1 },
  { "languages\\missiontalk\\archive\\glass.wav" , 2.120930f , false , 444 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_h_1.wav" , 2.122676f , false , 445 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_g_6.wav" , 2.126032f , false , 446 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_2.wav" , 2.130930f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_b_8.wav" , 2.131837f , false , 447 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_6.wav" , 2.132971f , false , 448 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_f_1.wav" , 2.133016f , false , 449 , -1 },
  { "languages\\voicepacks\\voicea\\comm_retreat_1_voicea.wav" , 2.139093f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\reinforce_go_get_5_voicea.wav" , 2.139093f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_alone_1.wav" , 2.141315f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_15.wav" , 2.146757f , false , 450 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_1.wav" , 2.147664f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_5_voicea.wav" , 2.147846f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_f_7.wav" , 2.165442f , false , 451 , -1 },
  { "languages\\voicepacks\\voicea\\helicopter_sight_6_voicea.wav" , 2.168934f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\helicopter_sight_6_voiceb.wav" , 2.168934f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\helicopter_sight_6_voicec.wav" , 2.168934f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\helicopter_sight_6_voiced.wav" , 2.168934f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_6.wav" , 2.170522f , false , -1 , 25 },
  { "languages\\voicepacks\\coreworkerd\\reinforce_go_get_3_voiced.wav" , 2.171066f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_k_4.wav" , 2.171383f , false , -1 , 26 },
  { "languages\\missiontalk\\steam\\steam_direction_c_1j.wav" , 2.171655f , false , 452 , -1 },
  { "languages\\voicepacks\\voicea\\searching_player_6_voicea.wav" , 2.173787f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_player_6_voiceb.wav" , 2.173787f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_player_6_voicec.wav" , 2.173787f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_player_6_voiced.wav" , 2.173787f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_9.wav" , 2.175238f , false , 453 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_e_4.wav" , 2.176825f , false , 454 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_f_1.wav" , 2.179365f , false , 455 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_alone_3.wav" , 2.180454f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_a_4.wav" , 2.182494f , false , 456 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_talk_to_3_voiced.wav" , 2.187664f , false , -1 , -1 },
  { "languages\\missiontalk\\mp_jungle\\mp_jungle_c3_a1.wav" , 2.190023f , false , -1 , 27 },
  { "languages\\missiontalk\\archive\\archive_generic_b_8.wav" , 2.191338f , false , 457 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_c_7.wav" , 2.193243f , false , 458 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_7.wav" , 2.194240f , false , 459 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_e_1.wav" , 2.198594f , false , 460 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_f_5.wav" , 2.200091f , false , 461 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_20.wav" , 2.204490f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_mercs_a_2.wav" , 2.210204f , false , 462 , -1 },
  { "languages\\voicepacks\\voicea\\helicopter_sight_5_voicea.wav" , 2.215510f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\helicopter_sight_5_voiceb.wav" , 2.215510f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\helicopter_sight_5_voicec.wav" , 2.215510f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\helicopter_sight_5_voiced.wav" , 2.215510f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_2.wav" , 2.215782f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\helicopter_sight_3_voicea.wav" , 2.216281f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\helicopter_sight_3_voiceb.wav" , 2.216281f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\helicopter_sight_3_voicec.wav" , 2.216281f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\helicopter_sight_3_voiced.wav" , 2.216281f , false , -1 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_5.wav" , 2.220227f , false , 463 , -1 },
  { "languages\\voicepacks\\mutantvoice\\comm_supress_1.wav" , 2.228662f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_3.wav" , 2.229887f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_a_8.wav" , 2.238503f , false , -1 , 28 },
  { "languages\\missiontalk\\training\\training_pickup_a_18a.wav" , 2.239274f , false , 464 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_14.wav" , 2.240726f , false , 465 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_a_2.wav" , 2.241361f , false , 466 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_o_4.wav" , 2.243084f , false , 467 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_group_15_voiceb.wav" , 2.248526f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\combat_group_15_voicec.wav" , 2.248526f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_group_15_voiced.wav" , 2.248526f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\combat_alone_15_voiced.wav" , 2.261043f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_9.wav" , 2.262721f , false , -1 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_12.wav" , 2.263129f , false , 468 , -1 },
  { "languages\\missiontalk\\training\\training_generic_l_2.wav" , 2.263719f , false , 469 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_1.wav" , 2.265578f , false , -1 , -1 },
  { "languages\\missiontalk\\research\\research_generic_h_3.wav" , 2.275510f , false , 470 , -1 },
  { "languages\\voicepacks\\voiced\\reinforce_talk_to_2_voiced.wav" , 2.279410f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_c_1.wav" , 2.280952f , false , 471 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_c_5.wav" , 2.282812f , false , 472 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_f_1.wav" , 2.283810f , false , 473 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_7.wav" , 2.284399f , false , 474 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_b_6.wav" , 2.287120f , false , 475 , -1 },
  { "languages\\missiontalk\\research\\research_generic_b_5.wav" , 2.290522f , false , 476 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_b_5.wav" , 2.290522f , false , 477 , -1 },
  { "languages\\missiontalk\\research\\research_generic_e_3.wav" , 2.291247f , false , 478 , -1 },
  { "languages\\voicepacks\\voicec\\comm_retreat_1_voicec.wav" , 2.298730f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_3_voiced.wav" , 2.298776f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_d_1.wav" , 2.304444f , false , 479 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_k_3.wav" , 2.304535f , false , -1 , 29 },
  { "languages\\voicepacks\\voicea\\combat_alone_15_voicea.wav" , 2.304535f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_4_voiced.wav" , 2.304580f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_1.wav" , 2.307800f , false , 480 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_16.wav" , 2.307982f , false , 481 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_h_4.wav" , 2.309342f , false , 482 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_pickup_e_3.wav" , 2.312472f , false , 483 , -1 },
  { "languages\\voicepacks\\coreworkerd\\yell_macho_8_voiced.wav" , 2.316190f , false , -1 , -1 },
  { "languages\\voicepacks\\val\\death_16.wav" , 2.316916f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_19.wav" , 2.318776f , false , 484 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_b_4.wav" , 2.320272f , false , 485 , -1 },
  { "languages\\voicepacks\\mutantvoice\\alarm_group_3.wav" , 2.324717f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_f_3.wav" , 2.324853f , false , 486 , -1 },
  { "languages\\voicepacks\\voicea\\yell_macho_5_voicea.wav" , 2.324853f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_macho_5_voiceb.wav" , 2.324853f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_macho_5_voicec.wav" , 2.324853f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_macho_5_voiced.wav" , 2.324853f , false , -1 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_e_3.wav" , 2.325669f , false , 487 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_g_3.wav" , 2.325669f , false , 488 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_h_2.wav" , 2.328073f , false , 489 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_6.wav" , 2.332562f , false , 490 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_b_1.wav" , 2.334376f , false , 491 , -1 },
  { "languages\\voicepacks\\voicec\\combat_alone_15_voicec.wav" , 2.335011f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_15_voiced.wav" , 2.335011f , false , -1 , -1 },
  { "languages\\missiontalk\\mp_dune\\mp_dune_c3_a1.wav" , 2.340000f , false , -1 , 30 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_1.wav" , 2.340590f , false , 492 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_10a.wav" , 2.340952f , false , -1 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_3.wav" , 2.345079f , false , 493 , -1 },
  { "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_2_voiced.wav" , 2.345215f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_direction_d_3.wav" , 2.345442f , false , 494 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_16.wav" , 2.347211f , false , -1 , 31 },
  { "languages\\missiontalk\\training\\training_pickup_a_18b.wav" , 2.360227f , false , 495 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_a_2.wav" , 2.367891f , false , 496 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_3.wav" , 2.376961f , false , 497 , -1 },
  { "languages\\missiontalk\\swamp\\_swamp_specific_f_6bis.wav" , 2.377052f , false , 498 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_3.wav" , 2.380000f , false , 499 , -1 },
  { "languages\\missiontalk\\training\\training_generic_n_2.wav" , 2.380726f , false , 500 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_b_3.wav" , 2.385805f , false , 501 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_h_7.wav" , 2.387256f , false , 502 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_e_7.wav" , 2.387574f , false , 503 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_d_1.wav" , 2.389478f , false , 504 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_6.wav" , 2.390159f , false , 505 , -1 },
  { "languages\\missiontalk\\swamp\\still_someone_a1.wav" , 2.397415f , false , 506 , -1 },
  { "languages\\missiontalk\\carrier\\what_the_hell.wav" , 2.398594f , false , 507 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_e_5.wav" , 2.401361f , false , 508 , -1 },
  { "languages\\missiontalk\\headshot.wav" , 2.401587f , false , 509 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_3.wav" , 2.402404f , false , 510 , -1 },
  { "languages\\missiontalk\\research\\research_specific_c_2a.wav" , 2.406667f , false , -1 , 32 },
  { "languages\\missiontalk\\control\\control_direction_b_2.wav" , 2.419161f , false , 511 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_e_4.wav" , 2.423537f , false , 512 , -1 },
  { "languages\\missiontalk\\mp_dune\\mp_dune_c3_d1.wav" , 2.429977f , false , -1 , 33 },
  { "languages\\voicepacks\\coreworkera\\death_7_voicea.wav" , 2.438095f , false , -1 , -1 },
  { "languages\\voicepacks\\voicea\\searching_mutants_5_voicea.wav" , 2.446213f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_mutants_5_voiceb.wav" , 2.446213f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_mutants_5_voicec.wav" , 2.446213f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_mutants_5_voiced.wav" , 2.446213f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_b_1.wav" , 2.446757f , false , 513 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_3_voicea.wav" , 2.446803f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_a_6.wav" , 2.450385f , false , 514 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_7.wav" , 2.457823f , false , -1 , 34 },
  { "languages\\missiontalk\\training\\training_generic_m_6.wav" , 2.458141f , false , 515 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_d_2.wav" , 2.459819f , false , 516 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_9.wav" , 2.470159f , false , 517 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_7.wav" , 2.475329f , false , 518 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_38_voicea.wav" , 2.476508f , false , -1 , -1 },
  { "languages\\missiontalk\\jack_4.wav" , 2.480862f , false , 519 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_38_voiceb.wav" , 2.485125f , false , -1 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_9.wav" , 2.485941f , false , 520 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_c_2.wav" , 2.490295f , false , 521 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_a_5.wav" , 2.490884f , false , 522 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_2.wav" , 2.498685f , false , 523 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_c_2.wav" , 2.499410f , false , 524 , -1 },
  { "languages\\voicepacks\\voiceb\\yell_macho_3_voiceb.wav" , 2.501814f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\yell_macho_3_voicec.wav" , 2.501814f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\yell_macho_3_voiced.wav" , 2.501814f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_8.wav" , 2.504580f , false , 525 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_2.wav" , 2.506259f , false , 526 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_11.wav" , 2.513152f , false , 527 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_e_2.wav" , 2.514966f , false , 528 , -1 },
  { "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_3.wav" , 2.522993f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_group_1.wav" , 2.523175f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_3.wav" , 2.526576f , false , 529 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_b_3.wav" , 2.540408f , false , -1 , 35 },
  { "languages\\voicepacks\\voicec\\combat_alone_38_voicec.wav" , 2.541950f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_38_voiced.wav" , 2.541950f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_generic_a_3.wav" , 2.543492f , false , 530 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_e_5.wav" , 2.545442f , false , 531 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_a_3.wav" , 2.549342f , false , -1 , 36 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_10b.wav" , 2.551519f , false , -1 , -1 },
  { "languages\\voicepacks\\mutantvoice\\bulletrain_alone_4.wav" , 2.552744f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_m_4.wav" , 2.553152f , false , 532 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_e_3.wav" , 2.564308f , false , 533 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_j_1.wav" , 2.569025f , false , 534 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_a_5.wav" , 2.570113f , false , 535 , -1 },
  { "languages\\voicepacks\\voiceb\\combat_alone_24_voiceb.wav" , 2.575374f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_mercs_a_3.wav" , 2.579546f , false , 536 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_b_2bis.wav" , 2.580227f , false , 537 , -1 },
  { "languages\\voicepacks\\voiceb\\comm_retreat_1_voiceb.wav" , 2.586077f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_21.wav" , 2.587120f , false , 538 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_e_5.wav" , 2.594785f , false , 539 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_b_1.wav" , 2.597687f , false , 540 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_c_5.wav" , 2.599184f , false , 541 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_f_3.wav" , 2.606893f , false , 542 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_1.wav" , 2.608844f , false , 543 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_f_5.wav" , 2.618095f , false , 544 , -1 },
  { "languages\\missiontalk\\training\\training_generic_c_5.wav" , 2.618186f , false , 545 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_h_3.wav" , 2.620907f , false , 546 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_9_voiced.wav" , 2.623855f , false , -1 , -1 },
  { "languages\\missiontalk\\control\\control_mercs_a_5.wav" , 2.624807f , false , 547 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_5.wav" , 2.624989f , false , 548 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_5.wav" , 2.627029f , false , -1 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_4.wav" , 2.629615f , false , 549 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_n_2.wav" , 2.630159f , false , 550 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_3.wav" , 2.632744f , false , 551 , -1 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_10.wav" , 2.634467f , false , 552 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_g_4$.wav" , 2.635964f , false , 553 , -1 },
  { "languages\\missiontalk\\mp_freighter\\mp_freighter_c3_d1.wav" , 2.640000f , false , -1 , 37 },
  { "languages\\voicepacks\\voicec\\combat_alone_24_voicec.wav" , 2.642902f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\combat_alone_24_voiced.wav" , 2.642902f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_g_12.wav" , 2.643900f , false , 554 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_d_3.wav" , 2.645624f , false , 555 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_i_6.wav" , 2.649070f , false , 556 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_g_1.wav" , 2.669524f , false , 557 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_g_2.wav" , 2.673152f , false , 558 , -1 },
  { "languages\\missiontalk\\control\\control_mercs_a_1.wav" , 2.684853f , false , 559 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_4.wav" , 2.686213f , false , 560 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_c_5.wav" , 2.689433f , false , 561 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_8.wav" , 2.690340f , false , 562 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_h_1.wav" , 2.692925f , false , 563 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_a_2bis.wav" , 2.699274f , false , 564 , -1 },
  { "languages\\voicepacks\\voicea\\combat_alone_24_voicea.wav" , 2.701542f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_specific_b_2.wav" , 2.705805f , false , 565 , -1 },
  { "languages\\missiontalk\\carrier6.wav" , 2.706893f , false , -1 , 38 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_8.wav" , 2.712336f , false , 566 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_b_5.wav" , 2.716281f , false , -1 , 39 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_2.wav" , 2.717596f , false , 567 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_b_2.wav" , 2.721315f , false , 568 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_i_3.wav" , 2.722222f , false , 569 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_d_3.wav" , 2.731202f , false , 570 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_c_1bisj.wav" , 2.740227f , false , 571 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_d_2.wav" , 2.741224f , false , -1 , 40 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_9.wav" , 2.743311f , false , 572 , -1 },
  { "languages\\voicepacks\\voicea\\searching_player_3_voicea.wav" , 2.744717f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_player_3_voiceb.wav" , 2.744717f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_player_3_voicec.wav" , 2.744717f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_player_3_voiced.wav" , 2.744717f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_c_2.wav" , 2.747166f , false , 573 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_g_2.wav" , 2.754014f , false , 574 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_b_1.wav" , 2.755692f , false , 575 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_18.wav" , 2.759138f , false , 576 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_c_1.wav" , 2.760227f , false , 577 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_g_2.wav" , 2.762404f , false , 578 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_e_3.wav" , 2.762630f , false , 579 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_18c.wav" , 2.784399f , false , 580 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_1.wav" , 2.787029f , false , -1 , 41 },
  { "languages\\missiontalk\\swamp\\swamp_generic_f_5.wav" , 2.789524f , false , 581 , -1 },
  { "languages\\missiontalk\\60meters.wav" , 2.795918f , false , 582 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_14.wav" , 2.803447f , false , -1 , 42 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_10.wav" , 2.803900f , false , 583 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_f_3.wav" , 2.805578f , false , 584 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_f_1.wav" , 2.808118f , false , 585 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_1.wav" , 2.808118f , false , 586 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_g_5.wav" , 2.809025f , false , 587 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_g_5.wav" , 2.809025f , false , 588 , -1 },
  { "languages\\missiontalk\\control\\control_generic_b_7.wav" , 2.809705f , false , 589 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_3.wav" , 2.811020f , false , 590 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_f_2.wav" , 2.815374f , false , 591 , -1 },
  { "languages\\missiontalk\\training\\training_generic_c_4.wav" , 2.815374f , false , 592 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_7.wav" , 2.824535f , false , 593 , -1 },
  { "languages\\missiontalk\\research\\research_generic_k_1.wav" , 2.824535f , false , 594 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_4.wav" , 2.825850f , false , -1 , 43 },
  { "languages\\missiontalk\\training\\training_generic_c_9.wav" , 2.826984f , false , 595 , -1 },
  { "languages\\missiontalk\\training\\training_generic_i_2.wav" , 2.827120f , false , 596 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_15.wav" , 2.829433f , false , -1 , 44 },
  { "languages\\missiontalk\\carrier\\carrier_generic_c_2.wav" , 2.834830f , false , 597 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_8.wav" , 2.838367f , false , 598 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_a_5.wav" , 2.838594f , false , 599 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_f_3.wav" , 2.842630f , false , 600 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_5.wav" , 2.844853f , false , 601 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_10.wav" , 2.845170f , false , 602 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_c_5.wav" , 2.847302f , false , 603 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_5.wav" , 2.848617f , false , 604 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_2.wav" , 2.848617f , false , 605 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_8.wav" , 2.860635f , false , 606 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_h_2.wav" , 2.862358f , false , 607 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_l_6.wav" , 2.863220f , false , 608 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellione_2process.wav" , 2.863265f , false , 609 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_e_2.wav" , 2.865624f , false , -1 , 45 },
  { "languages\\missiontalk\\fort\\fort_generic_h_8.wav" , 2.865805f , false , 610 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_e_1.wav" , 2.867619f , false , 611 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_18.wav" , 2.870839f , false , -1 , 46 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_4.wav" , 2.874422f , false , 612 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_c_1bis.wav" , 2.874966f , false , -1 , 47 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_20.wav" , 2.879365f , false , 613 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_5.wav" , 2.885306f , false , 614 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_13.wav" , 2.889887f , false , 615 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_l_5.wav" , 2.890839f , false , 616 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_2.wav" , 2.902857f , false , 617 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_e_3.wav" , 2.903447f , false , -1 , 48 },
  { "languages\\missiontalk\\training\\training_specific_d_20.wav" , 2.908118f , false , -1 , 49 },
  { "languages\\missiontalk\\regulator\\regulator_generic_d_2.wav" , 2.908254f , false , 618 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_g_5.wav" , 2.917687f , false , 619 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_9.wav" , 2.923764f , false , -1 , 50 },
  { "languages\\missiontalk\\research\\research_specific_e_1.wav" , 2.926440f , false , 620 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_a_2.wav" , 2.927029f , false , 621 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_i_5.wav" , 2.932698f , false , 622 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_b_7.wav" , 2.936825f , false , 623 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_k_2.wav" , 2.938730f , false , 624 , -1 },
  { "languages\\missiontalk\\mp_freighter\\mp_freighter_c3_a1.wav" , 2.940000f , false , -1 , 51 },
  { "languages\\voicepacks\\voicea\\searching_player_4_voicea.wav" , 2.943810f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_player_4_voiceb.wav" , 2.943810f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_player_4_voicec.wav" , 2.943810f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_player_4_voiced.wav" , 2.943810f , false , -1 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_generic_a_7.wav" , 2.945351f , false , -1 , 52 },
  { "languages\\missiontalk\\training\\training_generic_a_4.wav" , 2.951791f , false , 625 , -1 },
  { "languages\\voicepacks\\voiced\\comm_retreat_1_voiced.wav" , 2.952154f , false , -1 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_6.wav" , 2.953243f , false , 626 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_k_6.wav" , 2.960499f , false , 627 , -1 },
  { "languages\\voicepacks\\voicea\\yell_macho_3_voicea.wav" , 2.960499f , false , -1 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_c_3.wav" , 2.966032f , false , 628 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_h_1.wav" , 2.966304f , false , 629 , -1 },
  { "languages\\missiontalk\\mp_lake\\mp_lake_c2_d1.wav" , 2.970023f , false , -1 , 53 },
  { "languages\\missiontalk\\compound\\compound_pickup_c_2.wav" , 2.972472f , false , 630 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_12.wav" , 2.974694f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_d_4.wav" , 2.982766f , false , 631 , -1 },
  { "languages\\missiontalk\\boat\\boat_newpickup_a_2.wav" , 2.994059f , false , -1 , 54 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_2.wav" , 2.996553f , false , 632 , -1 },
  { "languages\\missiontalk\\research\\research_generic_g_3.wav" , 2.997506f , false , 633 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_d_1.wav" , 3.004036f , false , 634 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_m_8.wav" , 3.012018f , false , 635 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_11.wav" , 3.013424f , false , 636 , -1 },
  { "languages\\missiontalk\\research\\research_specific_a_4.wav" , 3.017188f , false , 637 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_h_3.wav" , 3.022358f , false , 638 , -1 },
  { "languages\\missiontalk\\research\\research_specific_d_2.wav" , 3.030930f , false , 639 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_g_4.wav" , 3.035964f , false , 640 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_4.wav" , 3.039546f , false , 641 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_d_4.wav" , 3.041088f , false , 642 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_15.wav" , 3.042086f , false , -1 , 55 },
  { "languages\\missiontalk\\fort\\fort_generic_h_5.wav" , 3.044717f , false , 643 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_generic_a_1.wav" , 3.049841f , false , -1 , 56 },
  { "languages\\missiontalk\\fort\\fort_generic_n_3.wav" , 3.050476f , false , 644 , -1 },
  { "languages\\missiontalk\\100meters.wav" , 3.058005f , false , 645 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_3.wav" , 3.063810f , false , 646 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_a_4.wav" , 3.072381f , false , 647 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_7.wav" , 3.080680f , false , 648 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_a_2.wav" , 3.081587f , false , 649 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_b_2.wav" , 3.083855f , false , 650 , -1 },
  { "languages\\missiontalk\\mp_jungle\\mp_jungle_c2_a1.wav" , 3.089977f , false , -1 , 57 },
  { "languages\\missiontalk\\training\\training_generic_d_8.wav" , 3.092880f , false , 651 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_b_3.wav" , 3.093469f , false , 652 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_f_3.wav" , 3.105034f , false , -1 , 58 },
  { "languages\\voicepacks\\coreworkerd\\death_7_voiced.wav" , 3.105669f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_8.wav" , 3.108345f , false , 653 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_3.wav" , 3.109116f , false , -1 , 59 },
  { "languages\\missiontalk\\treetop\\treetop_generic_e_1.wav" , 3.111429f , false , 654 , -1 },
  { "languages\\missiontalk\\training\\training_generic_l_3.wav" , 3.123764f , false , 655 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_c_2.wav" , 3.127256f , false , 656 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_1.wav" , 3.131746f , false , 657 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_12.wav" , 3.132426f , false , 658 , -1 },
  { "languages\\voicepacks\\voicea\\searching_mutants_2_voicea.wav" , 3.137234f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\searching_mutants_2_voiceb.wav" , 3.137234f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\searching_mutants_2_voicec.wav" , 3.137234f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\searching_mutants_2_voiced.wav" , 3.137234f , false , -1 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_a_1.wav" , 3.140998f , false , 659 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_b_1.wav" , 3.145896f , false , 660 , -1 },
  { "languages\\voicepacks\\coreworkerd\\death_8_voiced.wav" , 3.152109f , false , -1 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_8_voicea.wav" , 3.157914f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_h_5.wav" , 3.171156f , false , 661 , -1 },
  { "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c2_d1.wav" , 3.171837f , false , -1 , 60 },
  { "languages\\voicepacks\\val\\death_19.wav" , 3.174558f , false , -1 , -1 },
  { "languages\\missiontalk\\training\\training_generic_a_2.wav" , 3.177460f , false , 662 , -1 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_8.wav" , 3.185760f , false , 663 , -1 },
  { "languages\\voicepacks\\voicea\\death_6_voicea.wav" , 3.189569f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_e_3.wav" , 3.190930f , false , 664 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_p_7.wav" , 3.195193f , false , 665 , -1 },
  { "languages\\missiontalk\\training\\training_generic_c_1.wav" , 3.198231f , false , 666 , -1 },
  { "languages\\missiontalk\\pier\\announce1.wav" , 3.204082f , false , -1 , 61 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_10.wav" , 3.204172f , false , 667 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_e_6.wav" , 3.204308f , false , 668 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_8.wav" , 3.209070f , false , 669 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_3.wav" , 3.215646f , false , 670 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_6.wav" , 3.215918f , false , 671 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_a_5.wav" , 3.226077f , false , 672 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_g_5.wav" , 3.227029f , false , 673 , -1 },
  { "languages\\missiontalk\\mp_jungle\\mp_jungle_c2_d1.wav" , 3.227302f , false , -1 , 62 },
  { "languages\\missiontalk\\training\\training_generic_b_5.wav" , 3.227528f , false , 674 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_6.wav" , 3.239138f , false , 675 , -1 },
  { "languages\\missiontalk\\training\\training_generic_c_3.wav" , 3.240590f , false , 676 , -1 },
  { "languages\\voicepacks\\voicea\\helicopter_sight_7_voicea.wav" , 3.244218f , false , -1 , -1 },
  { "languages\\voicepacks\\voiceb\\helicopter_sight_7_voiceb.wav" , 3.244218f , false , -1 , -1 },
  { "languages\\voicepacks\\voicec\\helicopter_sight_7_voicec.wav" , 3.244218f , false , -1 , -1 },
  { "languages\\voicepacks\\voiced\\helicopter_sight_7_voiced.wav" , 3.244218f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_b_3.wav" , 3.247846f , false , 677 , -1 },
  { "languages\\missiontalk\\mp_lake\\mp_lake_c2_a1.wav" , 3.249252f , false , -1 , 63 },
  { "languages\\missiontalk\\compound\\compound_specific_f_3.wav" , 3.264898f , false , 678 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_d_1bis.wav" , 3.268345f , false , 679 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_d_1bisj.wav" , 3.268345f , false , 680 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_2.wav" , 3.276417f , false , 681 , -1 },
  { "languages\\missiontalk\\research\\research_generic_h_1.wav" , 3.278639f , false , 682 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_f_1.wav" , 3.281224f , false , 683 , -1 },
  { "languages\\missiontalk\\research\\research_generic_b_4.wav" , 3.288481f , false , 684 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_b_3.wav" , 3.294059f , false , 685 , -1 },
  { "languages\\missiontalk\\mp_lake\\mp_lake_c1_d1.wav" , 3.300000f , false , -1 , 64 },
  { "languages\\missiontalk\\research\\research_generic_d_2.wav" , 3.308798f , false , 686 , -1 },
  { "languages\\voicepacks\\coreworkera\\death_6_voicea.wav" , 3.308844f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_g_5.wav" , 3.309615f , false , 687 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_20.wav" , 3.316508f , false , 688 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_n_4.wav" , 3.325941f , false , 689 , -1 },
  { "languages\\missiontalk\\training\\training_generic_c_6.wav" , 3.329116f , false , 690 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_g_2spare.wav" , 3.358730f , false , 691 , -1 },
  { "languages\\missiontalk\\boat\\boat_newpickup_a_1.wav" , 3.360045f , false , -1 , 65 },
  { "languages\\missiontalk\\training\\training_generic_a_8.wav" , 3.371202f , false , 692 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_1.wav" , 3.375556f , false , 693 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_12.wav" , 3.376644f , false , -1 , 66 },
  { "languages\\missiontalk\\research\\research_generic_d_1.wav" , 3.381361f , false , 694 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_a_2.wav" , 3.384263f , false , -1 , 67 },
  { "languages\\missiontalk\\river\\templeriver_generic_i_1.wav" , 3.390476f , false , 695 , -1 },
  { "languages\\missiontalk\\carrier3.wav" , 3.413243f , false , -1 , 68 },
  { "languages\\missiontalk\\pier\\pier_mercs_m_7.wav" , 3.439410f , false , 696 , -1 },
  { "languages\\missiontalk\\fort\\fort_specific_a_2.wav" , 3.441179f , false , 697 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_22.wav" , 3.442313f , false , -1 , 69 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_2.wav" , 3.480317f , false , 698 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_3.wav" , 3.485850f , false , 699 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_generic_a_2.wav" , 3.488435f , false , -1 , 70 },
  { "languages\\missiontalk\\pier\\pier_specific_a_5.wav" , 3.488753f , false , -1 , 71 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_6.wav" , 3.488889f , false , 700 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_7.wav" , 3.490204f , false , 701 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_8.wav" , 3.494195f , false , 702 , -1 },
  { "languages\\missiontalk\\training\\training_generic_n_1.wav" , 3.511973f , false , 703 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_e_1.wav" , 3.517778f , false , 704 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_e_1.wav" , 3.519229f , false , 705 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_4.wav" , 3.520317f , false , 706 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_8.wav" , 3.532290f , false , 707 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_12.wav" , 3.537642f , false , -1 , 72 },
  { "languages\\missiontalk\\research\\reserch_specific_b_1.wav" , 3.538685f , false , 708 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_b_2.wav" , 3.542676f , false , 709 , -1 },
  { "languages\\missiontalk\\research\\research_generic_a_1.wav" , 3.552608f , false , 710 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_f_1.wav" , 3.556644f , false , 711 , -1 },
  { "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c2_a1.wav" , 3.556916f , false , -1 , 73 },
  { "languages\\missiontalk\\control\\control_generic_c_12.wav" , 3.563673f , false , 712 , -1 },
  { "languages\\missiontalk\\mp_freighter\\mp_freighter_c1_a1.wav" , 3.563810f , false , -1 , 74 },
  { "languages\\missiontalk\\bunker\\bunker_generic_d_2.wav" , 3.569297f , false , 713 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_5.wav" , 3.574830f , false , 714 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_b_1.wav" , 3.576372f , false , 715 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_9.wav" , 3.577460f , false , -1 , 75 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_7.wav" , 3.583991f , false , 716 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_b_2.wav" , 3.584535f , false , 717 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_a_4.wav" , 3.584853f , false , 718 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_a_1.wav" , 3.602630f , false , 719 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_g_3.wav" , 3.603764f , false , 720 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_newpickup_a_1.wav" , 3.609796f , false , -1 , 76 },
  { "languages\\missiontalk\\steam\\steam_generic_c_6.wav" , 3.610658f , false , 721 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_b_3.wav" , 3.615782f , false , 722 , -1 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_1.wav" , 3.633878f , false , 723 , -1 },
  { "languages\\missiontalk\\pier\\announce6.wav" , 3.640136f , false , -1 , 77 },
  { "languages\\missiontalk\\bunker\\bunker_direction_c_2.wav" , 3.644172f , false , -1 , 78 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_7.wav" , 3.649887f , false , 724 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_a_1.wav" , 3.655374f , false , 725 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_2.wav" , 3.658549f , false , 726 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_c_2.wav" , 3.664127f , false , 727 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_d_1.wav" , 3.670839f , false , 728 , -1 },
  { "languages\\voicepacks\\voicea\\yell_macho_1_voicea.wav" , 3.671610f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_f_4.wav" , 3.674512f , false , -1 , 79 },
  { "languages\\missiontalk\\training\\training_generic_j_4.wav" , 3.674694f , false , 729 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_1.wav" , 3.682041f , false , 730 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_2.wav" , 3.685986f , false , 731 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_m_7.wav" , 3.687574f , false , 732 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_2.wav" , 3.693515f , false , -1 , 80 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_3.wav" , 3.698367f , false , 733 , -1 },
  { "languages\\missiontalk\\research\\research_specific_c_2.wav" , 3.700091f , false , 734 , -1 },
  { "languages\\missiontalk\\compound\\compound_pickup_a_1.wav" , 3.718050f , false , 735 , -1 },
  { "languages\\missiontalk\\bunker\\anouncer.wav" , 3.718776f , false , -1 , 81 },
  { "languages\\missiontalk\\boat\\boat_generic_c_1.wav" , 3.730522f , false , 736 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_a_1.wav" , 3.737823f , false , 737 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_c_10.wav" , 3.740499f , false , 738 , -1 },
  { "languages\\missiontalk\\training\\training_generic_c_8.wav" , 3.754694f , false , 739 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_17.wav" , 3.759365f , false , -1 , 82 },
  { "languages\\missiontalk\\pier\\pier_mercs_c_4.wav" , 3.776145f , false , 740 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_g_1.wav" , 3.776372f , false , 741 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_16.wav" , 3.777506f , false , 742 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_o_3.wav" , 3.777914f , false , -1 , 83 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_5.wav" , 3.779864f , false , 743 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_a_1.wav" , 3.781905f , false , 744 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_12x.wav" , 3.784807f , false , 745 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_6_b.wav" , 3.787755f , false , 746 , -1 },
  { "languages\\missiontalk\\compound\\compound_specific_a_8.wav" , 3.788707f , false , 747 , -1 },
  { "languages\\missiontalk\\doyle_7.wav" , 3.806531f , false , -1 , 84 },
  { "languages\\missiontalk\\mutant\\mutant_specific_a_1.wav" , 3.806757f , false , 748 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_f_7.wav" , 3.810204f , false , 749 , -1 },
  { "languages\\missiontalk\\compound\\compound_pickup_b_1.wav" , 3.813832f , false , 750 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_9.wav" , 3.823991f , false , 751 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_b_4.wav" , 3.828889f , false , -1 , 85 },
  { "languages\\missiontalk\\training\\training_specific_d_6_c.wav" , 3.831066f , false , 752 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_b_2.wav" , 3.835782f , false , 753 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_l_4.wav" , 3.842857f , false , 754 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_4b.wav" , 3.844580f , false , 755 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_h_2.wav" , 3.849751f , false , 756 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_2.wav" , 3.854467f , false , 757 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_a_2.wav" , 3.866531f , false , -1 , 86 },
  { "languages\\missiontalk\\training\\training_generic_e_8.wav" , 3.872109f , false , 758 , -1 },
  { "languages\\missiontalk\\training\\training_generic_j_2.wav" , 3.876871f , false , 759 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_a_3.wav" , 3.882404f , false , 760 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_6_d.wav" , 3.887438f , false , 761 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_2.wav" , 3.892200f , false , 762 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_7.wav" , 3.895329f , false , 763 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_c_1.wav" , 3.897279f , false , 764 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_a_6.wav" , 3.915420f , false , 765 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_4.wav" , 3.921995f , false , 766 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_f_1bis.wav" , 3.923220f , false , 767 , -1 },
  { "languages\\missiontalk\\control\\control_direction_c_5.wav" , 3.927166f , false , 768 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_pickup_e_6.wav" , 3.945351f , false , -1 , 87 },
  { "languages\\missiontalk\\carrier5.wav" , 3.949070f , false , -1 , 88 },
  { "languages\\missiontalk\\mp_lake\\mp_lake_c1_a1.wav" , 3.972063f , false , -1 , 89 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_7.wav" , 3.973469f , false , 769 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_11.wav" , 3.978730f , false , -1 , 90 },
  { "languages\\missiontalk\\carrier7.wav" , 3.986168f , false , -1 , 91 },
  { "languages\\missiontalk\\boat\\boat_generic_c_6.wav" , 3.993787f , false , 770 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_f_4.wav" , 3.998050f , false , -1 , 92 },
  { "languages\\missiontalk\\rebellion\\process.wav" , 4.000000f , true , -1 , 93 },
  { "languages\\missiontalk\\fort\\fort_generic_b_3.wav" , 4.001134f , false , 771 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_h_2_b.wav" , 4.006304f , false , 772 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_17.wav" , 4.015556f , false , -1 , 94 },
  { "languages\\missiontalk\\carrier\\carrier_generic_b_1.wav" , 4.025533f , false , 773 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_21.wav" , 4.026349f , false , 774 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_c_6.wav" , 4.034104f , false , 775 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_f_2.wav" , 4.034422f , false , -1 , 95 },
  { "languages\\missiontalk\\treetop\\treetop_generic_c_2.wav" , 4.047392f , false , 776 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_h_3.wav" , 4.054875f , false , 777 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_c_2.wav" , 4.056190f , false , 778 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_7.wav" , 4.061361f , false , 779 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_f_1.wav" , 4.063900f , false , 780 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_e_2.wav" , 4.079138f , false , -1 , 96 },
  { "languages\\missiontalk\\regulator\\regulator_direction_b_1.wav" , 4.079138f , false , -1 , 97 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_18.wav" , 4.082676f , false , 781 , -1 },
  { "languages\\missiontalk\\swamp\\val typing.wav" , 4.092653f , false , 782 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_b_5.wav" , 4.096825f , false , 783 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_b_4.wav" , 4.124989f , false , 784 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_f_2.wav" , 4.126893f , false , -1 , 98 },
  { "languages\\missiontalk\\compound\\compound_specific_e_6.wav" , 4.127302f , false , -1 , 99 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_6.wav" , 4.132381f , false , 785 , -1 },
  { "languages\\missiontalk\\control\\control_generic_a_5.wav" , 4.134966f , false , 786 , -1 },
  { "languages\\missiontalk\\control\\control_generic_b_6.wav" , 4.141451f , false , 787 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_9.wav" , 4.141814f , false , 788 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_e_5.wav" , 4.153787f , false , 789 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_a_4.wav" , 4.155918f , false , 790 , -1 },
  { "languages\\missiontalk\\research\\research_generic_e_4.wav" , 4.156327f , false , 791 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_g_1.wav" , 4.165034f , false , 792 , -1 },
  { "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_s1_a1.wav" , 4.165125f , false , -1 , 100 },
  { "languages\\missiontalk\\compound\\compound_specific_f_7.wav" , 4.169705f , false , 793 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_d_2.wav" , 4.169705f , false , 794 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_b_6.wav" , 4.170839f , false , 795 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_h_5.wav" , 4.176644f , false , 796 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_3.wav" , 4.181678f , false , 797 , -1 },
  { "languages\\missiontalk\\research\\research_generic_c_3.wav" , 4.188254f , false , 798 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_d_1bis.wav" , 4.191156f , false , 799 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_d_3.wav" , 4.204172f , false , 800 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_b_2.wav" , 4.214376f , false , 801 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_b_2.wav" , 4.214376f , false , 802 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_e_1.wav" , 4.216553f , false , 803 , -1 },
  { "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_s1_d1.wav" , 4.218912f , false , -1 , 101 },
  { "languages\\missiontalk\\boat\\boat_newpickup_a_4.wav" , 4.231655f , false , -1 , 102 },
  { "languages\\missiontalk\\control\\control_generic_c_13.wav" , 4.236145f , false , 804 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_i_3.wav" , 4.236780f , false , 805 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_1.wav" , 4.246259f , false , -1 , 103 },
  { "languages\\missiontalk\\carrier\\carrier_generic_e_7.wav" , 4.250204f , false , 806 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_b_5.wav" , 4.254150f , false , 807 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_e_1.wav" , 4.254331f , false , 808 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_p_6.wav" , 4.264807f , true , -1 , 104 },
  { "languages\\missiontalk\\training\\training_generic_l_1.wav" , 4.270975f , false , 809 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_e_6.wav" , 4.273878f , false , 810 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_b_7.wav" , 4.278231f , false , -1 , 105 },
  { "languages\\missiontalk\\boat\\boat_generic_h_6.wav" , 4.286667f , false , 811 , -1 },
  { "languages\\missiontalk\\carrier4.wav" , 4.304036f , false , -1 , 106 },
  { "languages\\missiontalk\\swamp\\swamp_generic_a_5.wav" , 4.309070f , false , 812 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_pickup_e_2.wav" , 4.309615f , false , -1 , 107 },
  { "languages\\missiontalk\\bunker\\bunker_direction_c_1bis.wav" , 4.314104f , false , -1 , 108 },
  { "languages\\missiontalk\\archive\\archive_generic_a_9.wav" , 4.317415f , false , 813 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_e_2.wav" , 4.320317f , false , 814 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_11.wav" , 4.334104f , false , 815 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_9.wav" , 4.342086f , false , 816 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_e_4.wav" , 4.353197f , false , -1 , 109 },
  { "languages\\missiontalk\\archive\\archive_generic_b_7.wav" , 4.354603f , false , 817 , -1 },
  { "languages\\missiontalk\\training\\training_generic_a_10.wav" , 4.360952f , false , 818 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_h_8.wav" , 4.377868f , false , 819 , -1 },
  { "languages\\missiontalk\\research\\research_specific_c_3.wav" , 4.377914f , true , -1 , 110 },
  { "languages\\missiontalk\\pier\\announce7.wav" , 4.399955f , false , -1 , 111 },
  { "languages\\missiontalk\\swamp\\swamp_specific_g_1.wav" , 4.407574f , false , 820 , -1 },
  { "languages\\missiontalk\\mp_freighter\\mp_freighter_s1_d1.wav" , 4.410023f , false , -1 , 112 },
  { "languages\\missiontalk\\swamp\\swamp_generic_b_2.wav" , 4.410522f , false , 821 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_12.wav" , 4.413696f , false , -1 , 113 },
  { "languages\\missiontalk\\pier\\pier_mercs_f_3.wav" , 4.413968f , false , 822 , -1 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_5.wav" , 4.414014f , false , 823 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_14.wav" , 4.414331f , false , 824 , -1 },
  { "languages\\missiontalk\\mp_jungle\\mp_jungle_c1_d1.wav" , 4.422585f , false , -1 , 114 },
  { "languages\\missiontalk\\swamp\\swamp_generic_d_4.wav" , 4.442358f , false , 825 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_a_3.wav" , 4.459683f , false , -1 , 115 },
  { "languages\\missiontalk\\jack_2.wav" , 4.469751f , false , 826 , -1 },
  { "languages\\missiontalk\\training\\training_generic_e_2.wav" , 4.476281f , false , 827 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_7.wav" , 4.477596f , true , -1 , 116 },
  { "languages\\missiontalk\\carrier\\carrier_generic_h_2.wav" , 4.487982f , false , 828 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_i_1.wav" , 4.501723f , false , 829 , -1 },
  { "languages\\voicepacks\\mission_generic\\mission_generic_a_16.wav" , 4.507120f , false , -1 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_e_1.wav" , 4.508209f , false , 830 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_b_1.wav" , 4.510431f , false , 831 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_5bis.wav" , 4.514059f , false , -1 , 117 },
  { "languages\\missiontalk\\pier\\pier_mercs_k_1.wav" , 4.518912f , false , 832 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_g_2.wav" , 4.520590f , false , 833 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_c_3.wav" , 4.522041f , false , -1 , 118 },
  { "languages\\missiontalk\\research\\research_generic_g_1.wav" , 4.541814f , false , 834 , -1 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_10.wav" , 4.542993f , false , 835 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_d_3.wav" , 4.545442f , false , 836 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_5.wav" , 4.551066f , false , 837 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_1.wav" , 4.556916f , false , -1 , 119 },
  { "languages\\missiontalk\\archive\\archive_specific_b_4.wav" , 4.558503f , false , 838 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_c_3.wav" , 4.558730f , false , -1 , 120 },
  { "languages\\missiontalk\\carrier1.wav" , 4.559320f , false , -1 , 121 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_10.wav" , 4.572200f , false , 839 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_5.wav" , 4.580771f , false , -1 , 122 },
  { "languages\\missiontalk\\training\\training_specific_d_3.wav" , 4.580816f , false , -1 , 123 },
  { "languages\\missiontalk\\treetop\\treetop_generic_g_4.wav" , 4.580816f , false , -1 , 124 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_a_2.wav" , 4.581542f , false , 840 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_h_5bis.wav" , 4.583401f , false , 841 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_b_1.wav" , 4.593424f , false , -1 , 125 },
  { "languages\\missiontalk\\swamp\\swamp_generic_c_4.wav" , 4.600635f , false , 842 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_d_3.wav" , 4.601814f , false , 843 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_5.wav" , 4.609116f , false , 844 , -1 },
  { "languages\\missiontalk\\control\\control_generic_a_4.wav" , 4.625079f , false , 845 , -1 },
  { "languages\\missiontalk\\fort\\fort_specific_f_2.wav" , 4.628118f , false , 846 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_8a.wav" , 4.634603f , false , -1 , 126 },
  { "languages\\missiontalk\\research\\research_generic_b_7.wav" , 4.642268f , false , 847 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_b_7.wav" , 4.642268f , false , 848 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_e_3.wav" , 4.642857f , false , 849 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_10.wav" , 4.646213f , false , 850 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_d_3.wav" , 4.646576f , false , -1 , 127 },
  { "languages\\missiontalk\\steam\\steam_generic_b_2.wav" , 4.646848f , false , 851 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_k_3.wav" , 4.648345f , false , 852 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_6.wav" , 4.649660f , false , 853 , -1 },
  { "languages\\missiontalk\\training\\training_generic_k_3.wav" , 4.659909f , false , 854 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_i_1.wav" , 4.661678f , false , 855 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_k_4.wav" , 4.664989f , false , 856 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_a_1.wav" , 4.681179f , false , -1 , 128 },
  { "languages\\missiontalk\\fort\\fort_generic_c_1.wav" , 4.686485f , false , 857 , -1 },
  { "languages\\missiontalk\\river\\templeriver_specific_a_3.wav" , 4.689977f , false , -1 , 129 },
  { "languages\\missiontalk\\control\\control_direction_e_2.wav" , 4.714558f , false , -1 , 130 },
  { "languages\\missiontalk\\mp_dune\\mp_dune_c1_d1.wav" , 4.715420f , false , -1 , 131 },
  { "languages\\missiontalk\\regulator\\regulator_direction_a_2.wav" , 4.727029f , false , 858 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_6.wav" , 4.731247f , false , 859 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_d_4.wav" , 4.731247f , false , 860 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_a_3.wav" , 4.741678f , false , 861 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_b_2.wav" , 4.742630f , false , 862 , -1 },
  { "languages\\missiontalk\\research\\research_generic_i_1.wav" , 4.745533f , false , 863 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_8.wav" , 4.747166f , false , -1 , 132 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_d_1.wav" , 4.748209f , false , -1 , 133 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_4.wav" , 4.753741f , false , 864 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_d_1.wav" , 4.759002f , false , 865 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_h_1.wav" , 4.771655f , false , 866 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_e_1.wav" , 4.773469f , false , 867 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_o_6.wav" , 4.775238f , false , 868 , -1 },
  { "languages\\missiontalk\\river\\templeriver_specific_a_4.wav" , 4.780363f , false , 869 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_b_1.wav" , 4.781587f , false , -1 , 134 },
  { "languages\\missiontalk\\research\\research_generic_b_6.wav" , 4.800680f , false , 870 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_c_7.wav" , 4.806485f , false , -1 , 135 },
  { "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c1_d1.wav" , 4.811247f , false , -1 , 136 },
  { "languages\\missiontalk\\carrier\\carrier_generic_a_2.wav" , 4.814785f , false , 871 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_3.wav" , 4.814966f , false , -1 , 137 },
  { "languages\\missiontalk\\river\\templeruins_specific_g_3.wav" , 4.817370f , false , -1 , 138 },
  { "languages\\missiontalk\\training\\training_specific_d_6.wav" , 4.830249f , false , 872 , -1 },
  { "languages\\missiontalk\\training\\training_generic_b_6.wav" , 4.835964f , false , 873 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_1.wav" , 4.841315f , false , 874 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_7.wav" , 4.848617f , false , -1 , 139 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_4.wav" , 4.850884f , false , 875 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_b_3.wav" , 4.868889f , false , 876 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_6.wav" , 4.882222f , false , -1 , 140 },
  { "languages\\missiontalk\\river\\templeriver_generic_g_3.wav" , 4.889705f , false , 877 , -1 },
  { "languages\\missiontalk\\doyle_6.wav" , 4.900726f , false , -1 , 141 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_g_3.wav" , 4.902993f , false , 878 , -1 },
  { "languages\\missiontalk\\mp_jungle\\mp_jungle_s1_a1.wav" , 4.909206f , false , -1 , 142 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_8.wav" , 4.913878f , false , 879 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_c_4.wav" , 4.922585f , false , 880 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_d_2.wav" , 4.925805f , false , 881 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_a_2.wav" , 4.931383f , false , 882 , -1 },
  { "languages\\missiontalk\\pier\\announce5.wav" , 4.939274f , false , -1 , 143 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_5.wav" , 4.939501f , false , 883 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_d_1.wav" , 4.944354f , false , 884 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_g_1.wav" , 4.948345f , false , 885 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_g_11.wav" , 4.948707f , false , 886 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_f_6.wav" , 4.960317f , false , 887 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_a_5.wav" , 4.966168f , false , 888 , -1 },
  { "languages\\missiontalk\\command.wav" , 4.966803f , false , -1 , 144 },
  { "languages\\missiontalk\\carrier\\carrier_generic_e_3.wav" , 4.968481f , false , 889 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_5.wav" , 4.982404f , false , -1 , 145 },
  { "languages\\missiontalk\\river\\templeriver_generic_b_5.wav" , 4.983537f , false , 890 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_8.wav" , 4.993968f , false , 891 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_a_1.wav" , 5.015737f , false , -1 , 146 },
  { "languages\\missiontalk\\research\\researcha_specific_a_1.wav" , 5.018367f , false , 892 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_f_3.wav" , 5.023447f , false , 893 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_d_7.wav" , 5.034331f , false , 894 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_c_3.wav" , 5.042313f , false , 895 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_a_1.wav" , 5.049116f , false , -1 , 147 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_c_1.wav" , 5.049297f , false , 896 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_h_4.wav" , 5.050295f , false , 897 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_1.wav" , 5.050431f , false , 898 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_12.wav" , 5.055102f , false , -1 , 148 },
  { "languages\\missiontalk\\archive\\archive_specific_g_1.wav" , 5.056100f , false , -1 , 149 },
  { "languages\\missiontalk\\carrier\\carrier_specific_c_2.wav" , 5.057324f , false , 899 , -1 },
  { "languages\\missiontalk\\research\\research_generic_b_3.wav" , 5.060635f , false , 900 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_b_3.wav" , 5.060635f , false , 901 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_19.wav" , 5.061905f , false , 902 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_1.wav" , 5.067710f , false , 903 , -1 },
  { "languages\\missiontalk\\control\\control_generic_a_7.wav" , 5.070340f , false , 904 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_3.wav" , 5.076417f , false , 905 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_d_3.wav" , 5.077868f , false , 906 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_9.wav" , 5.079320f , false , 907 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_a_2.wav" , 5.080091f , false , 908 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_b_1.wav" , 5.080771f , false , 909 , -1 },
  { "languages\\missiontalk\\training\\training_generic_i_3.wav" , 5.083129f , false , 910 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_e_2.wav" , 5.093016f , false , 911 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_d_1.wav" , 5.094558f , false , 912 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_e_2.wav" , 5.097460f , false , 913 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_4.wav" , 5.102540f , false , 914 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_25.wav" , 5.116145f , false , -1 , 150 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_d_8.wav" , 5.135193f , false , 915 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_g_6.wav" , 5.137370f , false , 916 , -1 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_9.wav" , 5.141587f , false , 917 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_e_1.wav" , 5.164263f , false , 918 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_b_5.wav" , 5.188163f , false , 919 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_a_2.wav" , 5.197506f , false , 920 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_14.wav" , 5.216553f , false , -1 , 151 },
  { "languages\\missiontalk\\fort\\fort_generic_h_6.wav" , 5.219048f , false , 921 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_11.wav" , 5.219592f , false , -1 , 152 },
  { "languages\\missiontalk\\pier\\pier_mercs_n_3.wav" , 5.242721f , false , 922 , -1 },
  { "languages\\missiontalk\\training\\training_generic_n_6.wav" , 5.249116f , false , 923 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_3.wav" , 5.257823f , false , 924 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_5.wav" , 5.265079f , false , 925 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_a_1biss.wav" , 5.271882f , false , 926 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_7.wav" , 5.286984f , false , 927 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_3.wav" , 5.287846f , false , 928 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_4.wav" , 5.292063f , false , -1 , 153 },
  { "languages\\missiontalk\\training\\training_generic_b_2.wav" , 5.294104f , false , 929 , -1 },
  { "languages\\missiontalk\\control\\control_direction_d_2.wav" , 5.316644f , false , -1 , 154 },
  { "languages\\missiontalk\\carrier\\carrier_generic_a_1.wav" , 5.326032f , false , 930 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_m_9.wav" , 5.336190f , false , 931 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_a_6.wav" , 5.340544f , false , 932 , -1 },
  { "languages\\missiontalk\\control\\control_direction_b_4.wav" , 5.346621f , false , 933 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_generic_a_3.wav" , 5.389388f , false , -1 , 155 },
  { "languages\\missiontalk\\swamp\\swamp_generic_c_5.wav" , 5.392834f , false , 934 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_16.wav" , 5.397551f , false , -1 , 156 },
  { "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c1_a1.wav" , 5.420590f , false , -1 , 157 },
  { "languages\\missiontalk\\research\\research_specific_a_2_b.wav" , 5.438730f , false , 935 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d10.wav" , 5.438730f , false , 936 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_9.wav" , 5.440635f , false , 937 , -1 },
  { "languages\\missiontalk\\mp_freighter\\mp_freighter_c2_d1.wav" , 5.441043f , false , -1 , 158 },
  { "languages\\missiontalk\\river\\templeriver_specific_a_2.wav" , 5.478639f , false , -1 , 159 },
  { "languages\\missiontalk\\boat\\boat_generic_i_1.wav" , 5.495692f , false , 938 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_h_1.wav" , 5.508889f , false , -1 , 160 },
  { "languages\\missiontalk\\treetop\\treetop_specific_l_2.wav" , 5.511474f , false , 939 , -1 },
  { "languages\\missiontalk\\control\\control_direction_c_6.wav" , 5.517415f , false , -1 , 161 },
  { "languages\\missiontalk\\compound\\compound_specific_a_2.wav" , 5.517460f , false , 940 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_k_1.wav" , 5.533424f , false , -1 , 162 },
  { "languages\\missiontalk\\research\\research_generic_c_1.wav" , 5.539592f , false , 941 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_b_2.wav" , 5.544127f , false , 942 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_f_1.wav" , 5.562630f , false , -1 , 163 },
  { "languages\\missiontalk\\fort\\fort_generic_d_5.wav" , 5.567029f , false , 943 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_h_1.wav" , 5.587166f , false , 944 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_5.wav" , 5.594875f , false , 945 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_10.wav" , 5.595601f , false , -1 , 164 },
  { "languages\\missiontalk\\pier\\announce3.wav" , 5.601088f , false , -1 , 165 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_3.wav" , 5.601088f , false , -1 , 166 },
  { "languages\\missiontalk\\treetop\\treetop_generic_c_1.wav" , 5.602857f , false , 946 , -1 },
  { "languages\\missiontalk\\mp_freighter\\mp_freighter_s1_a1.wav" , 5.608073f , false , -1 , 167 },
  { "languages\\missiontalk\\training\\training_generic_b_3.wav" , 5.616281f , false , 947 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_b_5.wav" , 5.617823f , false , -1 , 168 },
  { "languages\\missiontalk\\treetop\\treetop_specific_k_1.wav" , 5.624989f , false , -1 , 169 },
  { "languages\\missiontalk\\training\\training_generic_d_10.wav" , 5.648209f , false , 948 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_a_2.wav" , 5.650975f , false , -1 , 170 },
  { "languages\\missiontalk\\training\\training_newpickup_a_1.wav" , 5.651202f , false , -1 , 171 },
  { "languages\\missiontalk\\inbound.wav" , 5.666667f , false , -1 , 172 },
  { "languages\\missiontalk\\bunker\\bunker_generic_a_3.wav" , 5.667075f , false , 949 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_d_2.wav" , 5.669705f , false , 950 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_9.wav" , 5.672880f , false , 951 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_b_4.wav" , 5.674150f , false , 952 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_9.wav" , 5.688844f , false , 953 , -1 },
  { "languages\\missiontalk\\training\\training_generic_a_5.wav" , 5.694649f , false , 954 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_5.wav" , 5.697279f , false , 955 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_a_3.wav" , 5.700454f , false , 956 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_a_1.wav" , 5.710975f , false , 957 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_f_1.wav" , 5.731655f , false , 958 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_b_5.wav" , 5.738186f , false , 959 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_c_1.wav" , 5.751610f , false , -1 , 173 },
  { "languages\\voicepacks\\voicea\\yell_macho_2_voicea.wav" , 5.755601f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_specific_e_1.wav" , 5.755873f , false , -1 , 174 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_f_1.wav" , 5.771565f , false , 960 , -1 },
  { "languages\\missiontalk\\control\\control_generic_b_2.wav" , 5.772109f , false , 961 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_1.wav" , 5.775510f , false , 962 , -1 },
  { "languages\\missiontalk\\river\\templeriver_generic_a_2.wav" , 5.775918f , false , 963 , -1 },
  { "languages\\missiontalk\\research\\research_generic_f_1.wav" , 5.802041f , false , 964 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_b_5.wav" , 5.816553f , false , 965 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_b_4.wav" , 5.860091f , false , 966 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_b_6.wav" , 5.868163f , false , -1 , 175 },
  { "languages\\missiontalk\\boat\\boat_specific_e_1.wav" , 5.875193f , false , -1 , 176 },
  { "languages\\missiontalk\\training\\training_specific_d_7.wav" , 5.885351f , false , -1 , 177 },
  { "languages\\missiontalk\\research\\research_generic_e_1.wav" , 5.887347f , false , 967 , -1 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_6.wav" , 5.897234f , false , -1 , 178 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_10.wav" , 5.908889f , false , -1 , 179 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_19.wav" , 5.922268f , false , -1 , 180 },
  { "languages\\missiontalk\\boat\\boat_generic_b_1.wav" , 5.924671f , false , 968 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_generic_a_4.wav" , 5.932472f , false , -1 , 181 },
  { "languages\\missiontalk\\mp_dune\\mp_dune_c2_a1.wav" , 5.935918f , false , -1 , 182 },
  { "languages\\missiontalk\\mutant\\mutant_specific_b_3.wav" , 5.948390f , false , 969 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_g_5.wav" , 5.957234f , false , 970 , -1 },
  { "languages\\missiontalk\\mp_dune\\mp_dune_c2_d1.wav" , 5.963356f , false , -1 , 183 },
  { "languages\\missiontalk\\steam\\steam_direction_a_1bis.wav" , 5.983220f , false , 971 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_1.wav" , 5.985760f , false , -1 , 184 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_4.wav" , 5.999410f , false , 972 , -1 },
  { "languages\\missiontalk\\bunker\\anouncer2.wav" , 6.000000f , false , -1 , 185 },
  { "languages\\missiontalk\\fort\\fort_generic_k_2.wav" , 6.002313f , false , 973 , -1 },
  { "languages\\missiontalk\\lassie.wav" , 6.015102f , false , -1 , 186 },
  { "languages\\missiontalk\\cooler\\cooler_specific_c_8.wav" , 6.015692f , false , 974 , -1 },
  { "languages\\missiontalk\\research\\research_generic_f_2.wav" , 6.021088f , false , 975 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_f_2.wav" , 6.021088f , false , 976 , -1 },
  { "languages\\missiontalk\\boat\\boat_generic_c_3.wav" , 6.032200f , false , 977 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_e_3.wav" , 6.032789f , false , 978 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_6.wav" , 6.033243f , false , -1 , 187 },
  { "languages\\missiontalk\\swamp\\swamp_generic_b_4.wav" , 6.056735f , false , 979 , -1 },
  { "languages\\missiontalk\\research\\research_specific_a_2.wav" , 6.058503f , false , 980 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_f_3.wav" , 6.060000f , false , 981 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_d_1.wav" , 6.060363f , false , 982 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_l_6.wav" , 6.067937f , false , 983 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_a_6.wav" , 6.090612f , false , 984 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_g_2.wav" , 6.108254f , false , 985 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_e_5.wav" , 6.113152f , false , 986 , -1 },
  { "languages\\missiontalk\\pier\\pier_specific_c_2.wav" , 6.115238f , false , 987 , -1 },
  { "languages\\missiontalk\\mp_freighter\\mp_freighter_c1_d1.wav" , 6.123175f , false , -1 , 188 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_12.wav" , 6.127619f , false , -1 , 189 },
  { "languages\\missiontalk\\boat\\boat_newpickup_a_3.wav" , 6.136825f , false , -1 , 190 },
  { "languages\\voicepacks\\krieger\\krieger2_2.wav" , 6.175011f , false , -1 , -1 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_8.wav" , 6.177188f , false , 988 , -1 },
  { "languages\\missiontalk\\factory\\factory_newpickup_a_10.wav" , 6.182086f , false , -1 , 191 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_9.wav" , 6.194558f , true , -1 , 192 },
  { "languages\\missiontalk\\pier\\pier_mercs_h_5.wav" , 6.214240f , false , 989 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_e_1.wav" , 6.221224f , false , 990 , -1 },
  { "languages\\missiontalk\\training\\training_generic_n_3.wav" , 6.227256f , false , 991 , -1 },
  { "languages\\missiontalk\\training\\training_generic_b_4.wav" , 6.232336f , false , 992 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_7.wav" , 6.240317f , false , -1 , 193 },
  { "languages\\missiontalk\\control\\control_direction_c_4.wav" , 6.246122f , false , -1 , 194 },
  { "languages\\missiontalk\\treetop\\treetop_specific_m_1.wav" , 6.251927f , false , -1 , 195 },
  { "languages\\missiontalk\\compound\\compound_specific_d_1_b.wav" , 6.254603f , false , 993 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_b_8.wav" , 6.263764f , false , -1 , 196 },
  { "languages\\missiontalk\\fort\\fort_generic_b_1.wav" , 6.292426f , false , 994 , -1 },
  { "languages\\missiontalk\\research\\research_generic_h_2.wav" , 6.292562f , false , 995 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_b_1.wav" , 6.292698f , false , 996 , -1 },
  { "languages\\missiontalk\\fort\\fort_specific_b_1.wav" , 6.294921f , false , -1 , 197 },
  { "languages\\missiontalk\\archive\\archive_specific_c_1.wav" , 6.306077f , false , 997 , -1 },
  { "languages\\missiontalk\\archive\\ross.wav" , 6.306077f , false , 998 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_a_3.wav" , 6.320272f , false , -1 , 198 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_3.wav" , 6.322041f , false , 999 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_c_1.wav" , 6.325488f , true , -1 , 199 },
  { "languages\\missiontalk\\fort\\fort_specific_e_2.wav" , 6.328934f , false , -1 , 200 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_3.wav" , 6.348707f , false , -1 , 201 },
  { "languages\\missiontalk\\boat\\boat_specific_a_3.wav" , 6.353515f , false , -1 , 202 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_f_1.wav" , 6.353651f , false , -1 , 203 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_13.wav" , 6.360363f , true , -1 , 204 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_11.wav" , 6.403084f , false , -1 , 205 },
  { "languages\\missiontalk\\swamp\\regulator_direction_a_1.wav" , 6.411927f , false , 1000 , -1 },
  { "languages\\missiontalk\\mp_freighter\\mp_freighter_c2_a1.wav" , 6.415465f , false , -1 , 206 },
  { "languages\\missiontalk\\armstraining.wav" , 6.416417f , false , -1 , 207 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_11.wav" , 6.423175f , false , 1001 , -1 },
  { "languages\\missiontalk\\mp_jungle\\mp_jungle_c1_a1.wav" , 6.429161f , false , -1 , 208 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_17.wav" , 6.431610f , false , -1 , 209 },
  { "languages\\missiontalk\\research\\research_generic_g_2.wav" , 6.438050f , false , 1002 , -1 },
  { "languages\\missiontalk\\research\\reserch_generic_g_2.wav" , 6.438050f , false , 1003 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_1.wav" , 6.440317f , true , -1 , 210 },
  { "languages\\missiontalk\\training\\training_generic_n_4.wav" , 6.441814f , false , 1004 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_e_1.wav" , 6.462721f , false , 1005 , -1 },
  { "languages\\missiontalk\\fort\\fort_specific_e_1.wav" , 6.474331f , false , 1006 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_c_3.wav" , 6.487438f , false , -1 , 211 },
  { "languages\\missiontalk\\steam\\steam_direction_e_4.wav" , 6.487438f , false , -1 , 212 },
  { "languages\\missiontalk\\boat\\boat_generic_g_1.wav" , 6.525760f , false , 1007 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_h_7.wav" , 6.535737f , false , 1008 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_g_4.wav" , 6.541859f , false , 1009 , -1 },
  { "languages\\missiontalk\\research\\research_specific_a_3.wav" , 6.554422f , false , -1 , 213 },
  { "languages\\missiontalk\\fort\\fort_generic_b_6.wav" , 6.556689f , false , 1010 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_h_1.wav" , 6.564218f , false , 1011 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_9.wav" , 6.587800f , false , -1 , 214 },
  { "languages\\missiontalk\\training\\training_generic_g_10.wav" , 6.616689f , false , 1012 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_e_2.wav" , 6.627800f , false , 1013 , -1 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_9.wav" , 6.639683f , false , -1 , 215 },
  { "languages\\missiontalk\\mp_dune\\mp_dune_c1_a1.wav" , 6.653515f , false , -1 , 216 },
  { "languages\\missiontalk\\fort\\fort_generic_f_3.wav" , 6.665714f , false , 1014 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_4.wav" , 6.684263f , false , -1 , 217 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_8.wav" , 6.693243f , false , 1015 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_f_4.wav" , 6.698912f , false , 1016 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_5.wav" , 6.717778f , false , 1017 , -1 },
  { "languages\\missiontalk\\control\\control_mercs_a_6.wav" , 6.729388f , false , 1018 , -1 },
  { "languages\\missiontalk\\mp_lake\\mp_lake_s1_a1.wav" , 6.745261f , false , -1 , 218 },
  { "languages\\missiontalk\\pier\\pier_mercs_g_1.wav" , 6.753424f , false , 1019 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_f_1bis_b.wav" , 6.755873f , false , 1020 , -1 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_7.wav" , 6.757098f , false , -1 , 219 },
  { "languages\\missiontalk\\archive\\archive_specific_b_3.wav" , 6.794694f , false , -1 , 220 },
  { "languages\\missiontalk\\carrier2.wav" , 6.822313f , false , -1 , 221 },
  { "languages\\missiontalk\\fort\\fort_generic_j_3.wav" , 6.829524f , false , 1021 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_g_1.wav" , 6.830703f , false , -1 , 222 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_19.wav" , 6.834286f , false , 1022 , -1 },
  { "languages\\missiontalk\\control\\control_direction_e_1.wav" , 6.837914f , false , -1 , 223 },
  { "languages\\missiontalk\\fort\\fort_generic_m_10.wav" , 6.841179f , false , 1023 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_c_1.wav" , 6.845488f , false , 1024 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_c_5.wav" , 6.849841f , false , -1 , 224 },
  { "languages\\missiontalk\\pier\\announce2.wav" , 6.853061f , false , -1 , 225 },
  { "languages\\missiontalk\\river\\templeriver_generic_c_4.wav" , 6.861633f , false , 1025 , -1 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_2.wav" , 6.870159f , false , 1026 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_e_3.wav" , 6.888662f , false , 1027 , -1 },
  { "languages\\missiontalk\\compound\\compound_pickup_c_1.wav" , 6.889977f , false , 1028 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_d_2.wav" , 6.890476f , false , 1029 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_d_2.wav" , 6.904807f , false , 1030 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_d_1j.wav" , 6.906893f , false , 1031 , -1 },
  { "languages\\missiontalk\\mp_dune\\mp_dune_s1_a1.wav" , 6.960000f , false , -1 , 226 },
  { "languages\\missiontalk\\boat\\boat_generic_d_5.wav" , 6.960136f , false , 1032 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_c_2.wav" , 6.982812f , false , 1033 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_a_1.wav" , 7.012789f , false , -1 , 227 },
  { "languages\\missiontalk\\pier\\pier_mercs_e_2.wav" , 7.015283f , false , 1034 , -1 },
  { "languages\\missiontalk\\pier\\announce8.wav" , 7.022812f , false , -1 , 228 },
  { "languages\\missiontalk\\fort\\fort_generic_i_7.wav" , 7.023991f , false , 1035 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_b_6.wav" , 7.037052f , false , 1036 , -1 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_5.wav" , 7.039002f , true , -1 , 229 },
  { "languages\\missiontalk\\river\\templeriver_generic_d_2.wav" , 7.063084f , false , 1037 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_n_1.wav" , 7.089796f , false , -1 , 230 },
  { "languages\\missiontalk\\control\\control_mercs_b_6.wav" , 7.099093f , false , 1038 , -1 },
  { "languages\\missiontalk\\control\\control_generic_c_8.wav" , 7.141315f , false , 1039 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_c_7.wav" , 7.146984f , false , 1040 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_b_2.wav" , 7.152517f , false , -1 , 231 },
  { "languages\\missiontalk\\regulator\\regulator_generic_b_3.wav" , 7.166213f , false , 1041 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_7.wav" , 7.177823f , false , 1042 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_m_9.wav" , 7.184036f , false , 1043 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_d_3.wav" , 7.189887f , false , -1 , 232 },
  { "languages\\missiontalk\\compound\\compound_specific_a_3.wav" , 7.208526f , false , -1 , 233 },
  { "languages\\missiontalk\\carrier\\carrier_pickup_e_1.wav" , 7.217732f , false , -1 , 234 },
  { "languages\\missiontalk\\research\\research_specific_a_5.wav" , 7.223537f , false , -1 , 235 },
  { "languages\\missiontalk\\regulator\\regulator_pickup_a_1.wav" , 7.241678f , false , -1 , 236 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_2.wav" , 7.243492f , false , 1044 , -1 },
  { "languages\\missiontalk\\research\\research_specific_d_1.wav" , 7.255646f , true , 1045 , -1 },
  { "languages\\missiontalk\\rebellion\\rebellion_mercs_e_5.wav" , 7.267800f , false , 1046 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_f_1.wav" , 7.277868f , false , -1 , 237 },
  { "languages\\missiontalk\\fort\\fort_specific_a_3.wav" , 7.296825f , false , -1 , 238 },
  { "languages\\missiontalk\\carrier\\carrier_specific_e_2.wav" , 7.309887f , false , -1 , 239 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_6.wav" , 7.341814f , false , 1047 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_4.wav" , 7.351111f , false , 1048 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_4.wav" , 7.352063f , false , 1049 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_18.wav" , 7.383900f , false , 1050 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_c_1.wav" , 7.391156f , false , 1051 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_originald_2.wav" , 7.392608f , false , -1 , 240 },
  { "languages\\missiontalk\\control\\control_direction_b_1.wav" , 7.426667f , false , -1 , 241 },
  { "languages\\missiontalk\\bunker\\bunker_direction_b_3.wav" , 7.442449f , false , -1 , 242 },
  { "languages\\missiontalk\\mp_dune\\mp_dune_s1_d1.wav" , 7.481270f , false , -1 , 243 },
  { "languages\\missiontalk\\mutant\\mutant_generic_a_5.wav" , 7.499138f , false , -1 , 244 },
  { "languages\\missiontalk\\mutant\\mutant_specific_c_4.wav" , 7.520045f , false , -1 , 245 },
  { "languages\\missiontalk\\carrier\\carrier_generic_a_4.wav" , 7.551610f , false , 1052 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_g_3.wav" , 7.559365f , false , 1053 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_g_3.wav" , 7.566621f , false , -1 , 246 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_1.wav" , 7.576190f , false , 1054 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_i_5.wav" , 7.594921f , false , 1055 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_f_2.wav" , 7.624807f , false , -1 , 247 },
  { "languages\\missiontalk\\bunker\\bunker_direction_b_2.wav" , 7.624807f , false , -1 , 248 },
  { "languages\\missiontalk\\boat\\boat_generic_g_3.wav" , 7.631882f , false , 1056 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_a_2.wav" , 7.634558f , false , -1 , 249 },
  { "languages\\missiontalk\\pier\\pier_specific_a_3.wav" , 7.641950f , true , -1 , 250 },
  { "languages\\missiontalk\\fort\\fort_specific_c_1.wav" , 7.675283f , false , -1 , 251 },
  { "languages\\missiontalk\\research\\research_generic_e_2.wav" , 7.695193f , false , 1057 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_n_1.wav" , 7.723492f , false , 1058 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_7.wav" , 7.734376f , false , 1059 , -1 },
  { "languages\\missiontalk\\river\\templeriver_specific_a_1.wav" , 7.740181f , false , -1 , 252 },
  { "languages\\missiontalk\\swamp\\swamp_generic_f_6.wav" , 7.753197f , false , 1060 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_c_3.wav" , 7.761224f , false , 1061 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_5.wav" , 7.773741f , false , 1062 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_1.wav" , 7.785578f , false , 1063 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_8.wav" , 7.791973f , false , -1 , 253 },
  { "languages\\missiontalk\\treetop\\treetop_generic_b_1.wav" , 7.802948f , false , 1064 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_g_2.wav" , 7.837143f , false , 1065 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_k_1.wav" , 7.837143f , false , 1066 , -1 },
  { "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c2_d1.wav" , 7.845805f , false , -1 , 254 },
  { "languages\\missiontalk\\fort\\fort_specific_d_1.wav" , 7.849524f , true , -1 , 255 },
  { "languages\\missiontalk\\boat\\boat_generic_i_3.wav" , 7.859955f , false , 1067 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_a_2.wav" , 7.865079f , false , -1 , 256 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_4.wav" , 7.883129f , false , 1068 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_2.wav" , 7.896508f , false , 1069 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_direction_a_3.wav" , 7.925986f , false , -1 , 257 },
  { "languages\\missiontalk\\bunker\\maskboys.wav" , 8.000000f , true , -1 , 258 },
  { "languages\\missiontalk\\mp_lake\\mp_lake_s1_d1.wav" , 8.008481f , false , -1 , 259 },
  { "languages\\missiontalk\\fort\\fort_generic_f_2.wav" , 8.014331f , false , 1070 , -1 },
  { "languages\\missiontalk\\pier\\announce4.wav" , 8.015601f , false , -1 , 260 },
  { "languages\\missiontalk\\pier\\pier_announcers_a_4.wav" , 8.015601f , false , -1 , 261 },
  { "languages\\missiontalk\\pier\\pier_mercs_k_5.wav" , 8.021224f , false , 1071 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_b_1.wav" , 8.077460f , false , -1 , 262 },
  { "languages\\missiontalk\\swamp\\swamp_specific_k_1.wav" , 8.083311f , false , -1 , 263 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_7.wav" , 8.091791f , false , -1 , 264 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_15.wav" , 8.105079f , false , -1 , 265 },
  { "languages\\missiontalk\\steam\\steam_generic_d_3.wav" , 8.110612f , false , 1072 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_g_1.wav" , 8.116009f , false , 1073 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_g_1.wav" , 8.159184f , false , -1 , 266 },
  { "languages\\missiontalk\\training\\training_generic_a_3.wav" , 8.159592f , false , 1074 , -1 },
  { "languages\\missiontalk\\pier\\pier_specific_b_1.wav" , 8.195646f , false , -1 , 267 },
  { "languages\\missiontalk\\rebellion\\rebellion_direction_a_1spare.wav" , 8.214966f , false , -1 , 268 },
  { "languages\\missiontalk\\treetop\\treetop_specific_g_6.wav" , 8.226893f , false , -1 , 269 },
  { "languages\\missiontalk\\fort\\fort_generic_g_3.wav" , 8.238685f , false , 1075 , -1 },
  { "languages\\missiontalk\\doyle_5.wav" , 8.262132f , false , -1 , 270 },
  { "languages\\missiontalk\\steam\\steam_direction_e_3x.wav" , 8.329977f , false , -1 , 271 },
  { "languages\\missiontalk\\treetop\\treetop_generic_f_4.wav" , 8.360635f , false , -1 , 272 },
  { "languages\\missiontalk\\training\\training_specific_d_18.wav" , 8.360680f , false , -1 , 273 },
  { "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c1_a1.wav" , 8.375556f , false , -1 , 274 },
  { "languages\\missiontalk\\archive\\archive_specific_a_3.wav" , 8.394331f , false , -1 , 275 },
  { "languages\\missiontalk\\carrier\\carrier_pickup_e_5.wav" , 8.427438f , true , -1 , 276 },
  { "languages\\missiontalk\\fort\\fort_generic_c_3.wav" , 8.440408f , false , 1076 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_c_6bis.wav" , 8.495510f , false , -1 , 277 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_4.wav" , 8.495556f , false , 1077 , -1 },
  { "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c2_a1.wav" , 8.503900f , false , -1 , 278 },
  { "languages\\missiontalk\\fort\\fort_commchatter_a_6.wav" , 8.521769f , false , 1078 , -1 },
  { "languages\\missiontalk\\mp_airstrip\\mp_airstrip_s1_a1.wav" , 8.540363f , false , -1 , 279 },
  { "languages\\missiontalk\\training\\training_pickup_a_17.wav" , 8.561451f , false , -1 , 280 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_6.wav" , 8.567800f , false , -1 , 281 },
  { "languages\\missiontalk\\bunker\\bunker_generic_a_2.wav" , 8.574331f , false , 1079 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_j_4.wav" , 8.574422f , false , -1 , 282 },
  { "languages\\missiontalk\\pier\\pier_mercs_n_2.wav" , 8.633878f , false , 1080 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_5.wav" , 8.682222f , false , -1 , 283 },
  { "languages\\missiontalk\\treetop\\treetop_specific_a_4.wav" , 8.691973f , false , -1 , 284 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_13.wav" , 8.694830f , false , -1 , 285 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_5.wav" , 8.737642f , false , -1 , 286 },
  { "languages\\missiontalk\\compound\\compound_specific_a_6.wav" , 8.803900f , false , 1081 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_f_3.wav" , 8.833107f , false , 1082 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_13.wav" , 8.861769f , false , -1 , 287 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_11.wav" , 8.885351f , false , 1083 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_13.wav" , 8.893016f , false , 1084 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_g_8.wav" , 8.896009f , false , -1 , 288 },
  { "languages\\missiontalk\\swamp\\swamp_generic_a_3.wav" , 8.900227f , false , 1085 , -1 },
  { "languages\\missiontalk\\river\\templeriver_specific_a_6.wav" , 8.908571f , false , -1 , 289 },
  { "languages\\missiontalk\\swamp\\swamp_specific_a_2.wav" , 8.910522f , false , 1086 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_3.wav" , 8.920000f , false , 1087 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_a_5.wav" , 8.930340f , false , 1088 , -1 },
  { "languages\\missiontalk\\fort\\fort_specific_f_3.wav" , 8.962721f , false , -1 , 290 },
  { "languages\\missiontalk\\treetop\\treetop_specific_j_2.wav" , 9.003492f , false , -1 , 291 },
  { "languages\\missiontalk\\doyle_1.wav" , 9.004172f , false , -1 , 292 },
  { "languages\\missiontalk\\steam\\steam_direction_e_3bis.wav" , 9.011202f , false , 1089 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_e_3bisj.wav" , 9.011202f , false , 1090 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_i_2.wav" , 9.040454f , false , -1 , 293 },
  { "languages\\missiontalk\\steam\\steam_direction_b_1.wav" , 9.063129f , false , -1 , 294 },
  { "languages\\missiontalk\\carrier\\carrier_generic_f_6.wav" , 9.070249f , false , 1091 , -1 },
  { "languages\\missiontalk\\bunker\\bunker_generic_f_2.wav" , 9.073333f , false , 1092 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_4.wav" , 9.128980f , false , 1093 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_8.wav" , 9.160907f , false , -1 , 295 },
  { "languages\\missiontalk\\training\\training_generic_k_4.wav" , 9.202132f , false , 1094 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_7.wav" , 9.210385f , false , 1095 , -1 },
  { "languages\\missiontalk\\mp_jungle\\mp_jungle_s1_d1.wav" , 9.241814f , false , -1 , 296 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_10.wav" , 9.242540f , false , 1096 , -1 },
  { "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c1_d1.wav" , 9.296553f , false , -1 , 297 },
  { "languages\\missiontalk\\mutant\\mutant_generic_a_6.wav" , 9.326893f , false , -1 , 298 },
  { "languages\\missiontalk\\river\\templeriver_generic_i_5.wav" , 9.362993f , false , 1097 , -1 },
  { "languages\\missiontalk\\archive\\archive_specific_e_1.wav" , 9.432698f , false , -1 , 299 },
  { "languages\\missiontalk\\archive\\archive_specific_d_1.wav" , 9.461361f , false , -1 , 300 },
  { "languages\\missiontalk\\steam\\steam_generic_f5.wav" , 9.469433f , false , 1098 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_6.wav" , 9.548707f , false , 1099 , -1 },
  { "languages\\missiontalk\\mp_airstrip\\mp_airstrip_s1_d1.wav" , 9.580590f , false , -1 , 301 },
  { "languages\\missiontalk\\research\\research_specific_c_1.wav" , 9.585986f , true , -1 , 302 },
  { "languages\\missiontalk\\steam\\steam_direction_c_1x.wav" , 9.598503f , false , -1 , 303 },
  { "languages\\missiontalk\\river\\templeriver_specific_a_7.wav" , 9.609615f , false , -1 , 304 },
  { "languages\\missiontalk\\steam\\steam_direction_e_3.wav" , 9.657143f , false , 1100 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_e_3j.wav" , 9.657143f , false , 1101 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_24.wav" , 9.692653f , true , -1 , 305 },
  { "languages\\missiontalk\\swamp\\swamp_generic_i_3.wav" , 9.708707f , false , 1102 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_pickup_b_1.wav" , 9.719002f , false , -1 , 306 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_7b.wav" , 9.765533f , false , 1103 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_h_3.wav" , 9.821088f , false , 1104 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_f_2.wav" , 9.862812f , false , -1 , 307 },
  { "languages\\missiontalk\\regulator\\regulator_generic_c_7.wav" , 9.981633f , false , 1105 , -1 },
  { "languages\\missiontalk\\training\\training_specific_d_4.wav" , 10.013560f , false , -1 , 308 },
  { "languages\\missiontalk\\compound\\compound_specific_e_4.wav" , 10.039229f , false , -1 , 309 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_9.wav" , 10.133560f , false , -1 , 310 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_13.wav" , 10.206621f , false , 1106 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_2.wav" , 10.208934f , false , -1 , 311 },
  { "languages\\missiontalk\\steam\\steam_direction_d_1.wav" , 10.300952f , false , -1 , 312 },
  { "languages\\missiontalk\\fort\\fort_generic_f_4.wav" , 10.395238f , false , 1107 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_4.wav" , 10.407256f , false , 1108 , -1 },
  { "languages\\missiontalk\\research\\research_specific_b_1.wav" , 10.482132f , false , -1 , 313 },
  { "languages\\missiontalk\\boat\\boat_specific_j_8.wav" , 10.489569f , false , -1 , 314 },
  { "languages\\missiontalk\\steam\\steam_direction_d_1x.wav" , 10.540816f , false , -1 , 315 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_4.wav" , 10.611791f , false , -1 , 316 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_3.wav" , 10.723855f , false , -1 , 317 },
  { "languages\\missiontalk\\treetop\\treetop_specific_i_2.wav" , 10.726848f , false , -1 , 318 },
  { "languages\\missiontalk\\treetop\\treetop_specific_g_4.wav" , 10.769252f , false , -1 , 319 },
  { "languages\\missiontalk\\treetop\\treetop_generic_g_7.wav" , 10.779592f , false , -1 , 320 },
  { "languages\\missiontalk\\training\\training_pickujp_a_15.wav" , 10.810748f , false , 1109 , -1 },
  { "languages\\missiontalk\\downed_pilot.wav" , 10.827075f , false , 1110 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_1.wav" , 10.904354f , false , -1 , 321 },
  { "languages\\missiontalk\\control\\control_direction_d_1.wav" , 10.906122f , false , -1 , 322 },
  { "languages\\missiontalk\\treetop\\treetop_generic_a_1bis.wav" , 10.917687f , false , 1111 , -1 },
  { "languages\\missiontalk\\control\\control_direction_a_3.wav" , 10.935283f , false , 1112 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_k_3.wav" , 10.969615f , false , 1113 , -1 },
  { "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_1.wav" , 10.988707f , false , -1 , 323 },
  { "languages\\missiontalk\\boat\\boat_generic_b_3.wav" , 11.023311f , false , 1114 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_a_4.wav" , 11.044444f , false , 1115 , -1 },
  { "languages\\missiontalk\\control\\control_generic_a_6.wav" , 11.055556f , false , 1116 , -1 },
  { "languages\\missiontalk\\pier\\pier_mercs_d_5.wav" , 11.060635f , false , 1117 , -1 },
  { "languages\\missiontalk\\training\\training_pickup_a_15.wav" , 11.072971f , false , -1 , 324 },
  { "languages\\missiontalk\\treetop\\treetop_specific_b_1.wav" , 11.102086f , false , 1118 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_f_6.wav" , 11.151338f , false , -1 , 325 },
  { "languages\\missiontalk\\training\\training_pickup_a_1.wav" , 11.194059f , false , 1119 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_generic_i_5.wav" , 11.334286f , false , 1120 , -1 },
  { "languages\\missiontalk\\fort\\fort_generic_j_5.wav" , 11.340000f , false , 1121 , -1 },
  { "languages\\missiontalk\\cooler\\cooler_specific_c_6.wav" , 11.344490f , false , -1 , 326 },
  { "languages\\missiontalk\\treetop\\treetop_generic_f_5.wav" , 11.348707f , false , -1 , 327 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_9.wav" , 11.380499f , false , -1 , 328 },
  { "languages\\missiontalk\\fort\\fort_specific_a_1.wav" , 11.403492f , false , -1 , 329 },
  { "languages\\missiontalk\\training\\training_specific_d_8.wav" , 11.404717f , false , -1 , 330 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_7.wav" , 11.517370f , false , 1122 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_g_3bis.wav" , 11.538912f , false , -1 , 331 },
  { "languages\\missiontalk\\pier\\pier_specific_d_1.wav" , 11.648889f , false , -1 , 332 },
  { "languages\\missiontalk\\boat\\boat_specific_j_6.wav" , 11.672245f , false , -1 , 333 },
  { "languages\\missiontalk\\regulator\\regulator_generic_b_2.wav" , 11.708617f , false , 1123 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_11.wav" , 11.758141f , false , 1124 , -1 },
  { "languages\\missiontalk\\training\\training_generic_d_5.wav" , 11.793424f , false , 1125 , -1 },
  { "languages\\missiontalk\\steam\\steam_generic_f1.wav" , 11.797551f , false , 1126 , -1 },
  { "languages\\missiontalk\\doyle_11.wav" , 11.904626f , false , -1 , 334 },
  { "languages\\missiontalk\\river\\templeriver_specific_a_5.wav" , 11.932290f , false , -1 , 335 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_6.wav" , 11.981043f , false , 1127 , -1 },
  { "languages\\missiontalk\\research\\research_generic_a_2.wav" , 11.998866f , false , 1128 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_specific_f_1.wav" , 12.005261f , true , -1 , 336 },
  { "languages\\missiontalk\\swamp\\swamp_generic_a_4.wav" , 12.167211f , false , 1129 , -1 },
  { "languages\\missiontalk\\steam\\steam_direction_a_1.wav" , 12.259048f , false , 1130 , -1 },
  { "languages\\missiontalk\\archive\\archive_generic_a_7.wav" , 12.292381f , false , 1131 , -1 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_f_1.wav" , 12.341179f , false , -1 , 337 },
  { "languages\\missiontalk\\river\\templeruins_specific_e_1.wav" , 12.461406f , false , -1 , 338 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_e_1.wav" , 12.485760f , false , -1 , 339 },
  { "languages\\missiontalk\\regulator\\regulator_generic_a_4.wav" , 12.625941f , false , 1132 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_f_1.wav" , 12.891111f , false , -1 , 340 },
  { "languages\\missiontalk\\carrier\\carrier_specific_d_2.wav" , 13.124127f , false , -1 , 341 },
  { "languages\\missiontalk\\ruins\\templeruins_specific_g_4x.wav" , 13.146803f , false , 1133 , -1 },
  { "languages\\missiontalk\\pier\\pier_specific_a_1.wav" , 13.277914f , false , -1 , 342 },
  { "languages\\missiontalk\\swamp\\regulator_direction_d_1.wav" , 13.330975f , false , 1134 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_g_2.wav" , 13.512109f , false , -1 , 343 },
  { "languages\\missiontalk\\river\\templeruins_specific_g_4bis.wav" , 13.534921f , false , 1135 , -1 },
  { "languages\\missiontalk\\treetop\\treetop_generic_g_1.wav" , 13.633469f , false , -1 , 344 },
  { "languages\\missiontalk\\swamp\\swamp_generic_h_3.wav" , 13.730522f , false , 1136 , -1 },
  { "languages\\missiontalk\\dam\\damlab_specific_a_19.wav" , 13.759864f , false , 1137 , -1 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_18.wav" , 13.870204f , false , 1138 , -1 },
  { "languages\\missiontalk\\river\\templeruins_specific_f_3.wav" , 13.953515f , false , -1 , 345 },
  { "languages\\missiontalk\\river\\templeriver_generic_c_3.wav" , 14.149796f , false , 1139 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_f_2.wav" , 14.208027f , false , 1140 , -1 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_11.wav" , 14.274376f , false , -1 , 346 },
  { "languages\\missiontalk\\fort\\fort_pickup_a_1.wav" , 14.653061f , true , -1 , 347 },
  { "languages\\missiontalk\\boat\\boat_specific_c_1.wav" , 14.682902f , false , -1 , 348 },
  { "languages\\missiontalk\\treetop\\treetop_specific_h_1.wav" , 14.682902f , false , -1 , 349 },
  { "languages\\missiontalk\\control\\control_direction_c_2.wav" , 14.709070f , false , -1 , 350 },
  { "languages\\missiontalk\\carrier\\carrier_specific_d_1.wav" , 15.456463f , false , -1 , 351 },
  { "languages\\missiontalk\\boat\\boat_specific_g_1.wav" , 15.596100f , false , -1 , 352 },
  { "languages\\missiontalk\\steam\\steam_direction_c_1.wav" , 15.711066f , false , -1 , 353 },
  { "languages\\missiontalk\\treetop\\treetop_specific_o_1.wav" , 16.139728f , true , -1 , 354 },
  { "languages\\missiontalk\\steam\\steam_direction_a_1v.wav" , 16.227392f , false , -1 , 355 },
  { "languages\\missiontalk\\archive\\archive_specific_a_1.wav" , 16.547574f , false , -1 , 356 },
  { "languages\\missiontalk\\compound\\compound_specific_f_6.wav" , 16.875057f , false , -1 , 357 },
  { "languages\\missiontalk\\regulator\\regulator_direction_a_1.wav" , 17.162857f , false , -1 , 358 },
  { "languages\\missiontalk\\pier\\pier_specific_c_1.wav" , 17.526803f , false , -1 , 359 },
  { "languages\\missiontalk\\steam\\steam_direction_e_1.wav" , 18.073515f , false , -1 , 360 },
  { "languages\\missiontalk\\bunker\\bunker_direction_a_1.wav" , 18.352653f , false , -1 , 361 },
  { "languages\\missiontalk\\carrier\\carrier_announcers_a_3.wav" , 18.498685f , false , -1 , 362 },
  { "languages\\missiontalk\\mutant\\mutant_specific_c_1.wav" , 18.678866f , false , -1 , 363 },
  { "languages\\missiontalk\\compound\\compound_specific_e_2.wav" , 18.761134f , false , -1 , 364 },
  { "languages\\voicepacks\\krieger\\krieger1.wav" , 19.527664f , false , -1 , -1 },
  { "languages\\voicepacks\\krieger\\krieger_specific_2.wav" , 19.689025f , false , -1 , -1 },
  { "languages\\missiontalk\\regulator\\regulator_direction_d_1.wav" , 19.719909f , false , -1 , 365 },
  { "languages\\missiontalk\\river\\templeruins_specific_g_4.wav" , 20.407483f , false , 1141 , -1 },
  { "languages\\missiontalk\\mutant\\mutant_specific_b_2.wav" , 20.971519f , false , -1 , 366 },
  { "languages\\missiontalk\\treetop\\treetop_specific_g_3.wav" , 21.007664f , true , -1 , 367 },
  { "languages\\missiontalk\\research\\research_specific_a_1.wav" , 21.122993f , true , -1 , 368 },
  { "languages\\missiontalk\\training\\training_specific_d_16.wav" , 21.487664f , false , -1 , 369 },
  { "languages\\missiontalk\\fort\\fort_specific_f_1.wav" , 21.542041f , true , -1 , 370 },
  { "languages\\missiontalk\\archive\\archive_specific_f_1.wav" , 23.898322f , false , 1142 , -1 },
  { "languages\\missiontalk\\doyle_3.wav" , 23.952789f , false , -1 , 371 },
  { "languages\\missiontalk\\doyle_9.wav" , 24.062086f , false , -1 , 372 },
  { "languages\\missiontalk\\control\\control_direction_a_1.wav" , 24.456054f , false , -1 , 373 },
  { "languages\\voicepacks\\krieger\\krieger_specific_1.wav" , 24.518730f , false , -1 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_a_1.wav" , 26.800317f , false , -1 , 374 },
  { "languages\\missiontalk\\mutant\\mutant_specific_b_1.wav" , 26.971519f , false , -1 , 375 },
  { "languages\\missiontalk\\boat\\boat_specific_j_13.wav" , 26.995011f , false , -1 , 376 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_1.wav" , 27.632336f , false , 1143 , -1 },
  { "languages\\missiontalk\\doyle_8.wav" , 29.059456f , false , -1 , 377 },
  { "languages\\voicepacks\\krieger\\krieger2.wav" , 29.514014f , false , -1 , -1 },
  { "languages\\missiontalk\\boat\\boat_specific_a_1.wav" , 29.685805f , false , -1 , 378 },
  { "languages\\missiontalk\\lab\\damlab_specific_a_9.wav" , 29.790431f , false , 1144 , -1 },
  { "languages\\missiontalk\\swamp\\swamp_specific_h_6.wav" , 30.934512f , false , -1 , 379 },
  { "languages\\missiontalk\\cooler\\cooler_specific_c_1.wav" , 35.682902f , false , -1 , 380 },
  { "languages\\missiontalk\\compound\\compound_specific_a_1.wav" , 36.986893f , false , -1 , 381 },
  { "languages\\missiontalk\\training\\training_pickup_a_9.wav" , 41.150431f , true , -1 , 382 },
};

static const unsigned int aMercChatterLength = 1145;
static const unsigned int aMercChatter[ aMercChatterLength ] = {
  5,
  8,
  18,
  22,
  24,
  37,
  41,
  47,
  48,
  50,
  86,
  90,
  112,
  128,
  129,
  141,
  159,
  163,
  217,
  220,
  226,
  247,
  274,
  275,
  279,
  305,
  317,
  318,
  337,
  340,
  367,
  383,
  417,
  427,
  428,
  438,
  446,
  449,
  470,
  473,
  499,
  503,
  508,
  509,
  518,
  534,
  555,
  563,
  565,
  570,
  579,
  585,
  592,
  609,
  617,
  635,
  641,
  651,
  669,
  696,
  708,
  710,
  715,
  716,
  721,
  727,
  728,
  735,
  749,
  754,
  755,
  763,
  764,
  768,
  774,
  781,
  787,
  789,
  791,
  798,
  800,
  802,
  803,
  814,
  835,
  841,
  844,
  849,
  853,
  862,
  863,
  864,
  868,
  871,
  875,
  891,
  897,
  901,
  903,
  956,
  962,
  965,
  966,
  980,
  995,
  1007,
  1021,
  1026,
  1037,
  1045,
  1053,
  1054,
  1065,
  1071,
  1097,
  1103,
  1129,
  1130,
  1137,
  1140,
  1150,
  1151,
  1164,
  1176,
  1177,
  1179,
  1191,
  1198,
  1217,
  1236,
  1237,
  1256,
  1264,
  1265,
  1266,
  1281,
  1286,
  1288,
  1311,
  1337,
  1356,
  1358,
  1363,
  1376,
  1399,
  1406,
  1416,
  1427,
  1428,
  1435,
  1436,
  1439,
  1442,
  1449,
  1464,
  1470,
  1495,
  1501,
  1510,
  1511,
  1516,
  1517,
  1519,
  1534,
  1545,
  1554,
  1555,
  1556,
  1558,
  1559,
  1570,
  1574,
  1576,
  1577,
  1586,
  1587,
  1592,
  1598,
  1604,
  1605,
  1609,
  1613,
  1614,
  1623,
  1636,
  1641,
  1646,
  1655,
  1662,
  1667,
  1674,
  1677,
  1701,
  1704,
  1705,
  1711,
  1712,
  1716,
  1720,
  1722,
  1723,
  1728,
  1730,
  1733,
  1735,
  1744,
  1746,
  1749,
  1754,
  1757,
  1765,
  1769,
  1772,
  1781,
  1782,
  1784,
  1793,
  1795,
  1806,
  1815,
  1816,
  1817,
  1828,
  1834,
  1838,
  1841,
  1842,
  1848,
  1854,
  1860,
  1861,
  1862,
  1865,
  1868,
  1869,
  1870,
  1874,
  1881,
  1891,
  1892,
  1893,
  1894,
  1895,
  1897,
  1900,
  1901,
  1905,
  1918,
  1920,
  1921,
  1924,
  1932,
  1937,
  1942,
  1949,
  1951,
  1955,
  1956,
  1960,
  1964,
  1968,
  1969,
  1972,
  1975,
  1977,
  1981,
  1986,
  2001,
  2003,
  2013,
  2014,
  2017,
  2019,
  2027,
  2031,
  2032,
  2034,
  2039,
  2043,
  2044,
  2054,
  2061,
  2063,
  2067,
  2070,
  2073,
  2077,
  2079,
  2081,
  2082,
  2085,
  2088,
  2096,
  2104,
  2106,
  2107,
  2115,
  2117,
  2120,
  2127,
  2144,
  2147,
  2149,
  2156,
  2157,
  2162,
  2165,
  2166,
  2171,
  2172,
  2182,
  2184,
  2198,
  2199,
  2203,
  2204,
  2205,
  2210,
  2212,
  2213,
  2217,
  2228,
  2229,
  2231,
  2242,
  2250,
  2258,
  2259,
  2267,
  2272,
  2276,
  2280,
  2281,
  2283,
  2286,
  2290,
  2293,
  2295,
  2296,
  2297,
  2302,
  2306,
  2310,
  2311,
  2316,
  2317,
  2318,
  2319,
  2323,
  2326,
  2333,
  2338,
  2341,
  2342,
  2343,
  2345,
  2346,
  2354,
  2358,
  2360,
  2364,
  2365,
  2366,
  2367,
  2370,
  2372,
  2373,
  2374,
  2375,
  2377,
  2378,
  2380,
  2383,
  2387,
  2388,
  2391,
  2392,
  2393,
  2394,
  2396,
  2398,
  2401,
  2405,
  2408,
  2409,
  2410,
  2411,
  2413,
  2415,
  2416,
  2418,
  2419,
  2422,
  2423,
  2425,
  2426,
  2427,
  2428,
  2429,
  2430,
  2431,
  2438,
  2439,
  2440,
  2441,
  2442,
  2446,
  2451,
  2453,
  2454,
  2464,
  2465,
  2467,
  2468,
  2476,
  2478,
  2483,
  2484,
  2485,
  2488,
  2489,
  2491,
  2493,
  2494,
  2499,
  2506,
  2513,
  2514,
  2521,
  2522,
  2526,
  2527,
  2528,
  2530,
  2531,
  2532,
  2534,
  2536,
  2539,
  2541,
  2542,
  2544,
  2545,
  2546,
  2547,
  2548,
  2549,
  2551,
  2552,
  2553,
  2557,
  2560,
  2568,
  2573,
  2574,
  2575,
  2577,
  2580,
  2581,
  2582,
  2583,
  2584,
  2586,
  2596,
  2600,
  2601,
  2602,
  2603,
  2609,
  2610,
  2612,
  2614,
  2615,
  2616,
  2617,
  2618,
  2619,
  2620,
  2621,
  2624,
  2628,
  2629,
  2630,
  2631,
  2634,
  2635,
  2637,
  2642,
  2643,
  2644,
  2645,
  2646,
  2650,
  2652,
  2654,
  2656,
  2657,
  2658,
  2659,
  2660,
  2661,
  2662,
  2663,
  2664,
  2665,
  2666,
  2667,
  2668,
  2669,
  2670,
  2671,
  2673,
  2674,
  2681,
  2683,
  2685,
  2686,
  2687,
  2688,
  2690,
  2692,
  2693,
  2694,
  2695,
  2696,
  2700,
  2701,
  2702,
  2703,
  2706,
  2710,
  2711,
  2715,
  2716,
  2717,
  2718,
  2720,
  2721,
  2723,
  2724,
  2725,
  2726,
  2727,
  2728,
  2729,
  2730,
  2731,
  2733,
  2734,
  2736,
  2737,
  2738,
  2739,
  2740,
  2744,
  2745,
  2746,
  2747,
  2748,
  2749,
  2750,
  2751,
  2752,
  2753,
  2754,
  2756,
  2758,
  2760,
  2761,
  2762,
  2763,
  2764,
  2766,
  2771,
  2772,
  2773,
  2774,
  2775,
  2776,
  2777,
  2778,
  2780,
  2781,
  2783,
  2784,
  2785,
  2786,
  2787,
  2788,
  2789,
  2790,
  2791,
  2792,
  2793,
  2794,
  2796,
  2797,
  2799,
  2800,
  2801,
  2802,
  2803,
  2804,
  2805,
  2806,
  2807,
  2808,
  2809,
  2810,
  2811,
  2813,
  2814,
  2816,
  2818,
  2819,
  2820,
  2821,
  2822,
  2825,
  2826,
  2828,
  2829,
  2830,
  2831,
  2832,
  2839,
  2841,
  2842,
  2844,
  2845,
  2847,
  2849,
  2851,
  2852,
  2853,
  2854,
  2855,
  2856,
  2857,
  2858,
  2859,
  2860,
  2861,
  2863,
  2865,
  2866,
  2867,
  2868,
  2869,
  2870,
  2871,
  2873,
  2874,
  2877,
  2879,
  2880,
  2881,
  2882,
  2883,
  2888,
  2889,
  2892,
  2895,
  2896,
  2898,
  2899,
  2900,
  2902,
  2903,
  2904,
  2905,
  2906,
  2907,
  2908,
  2910,
  2911,
  2912,
  2917,
  2919,
  2920,
  2921,
  2922,
  2923,
  2924,
  2925,
  2926,
  2928,
  2930,
  2931,
  2932,
  2933,
  2934,
  2936,
  2937,
  2939,
  2941,
  2943,
  2944,
  2946,
  2947,
  2950,
  2951,
  2952,
  2953,
  2954,
  2955,
  2956,
  2957,
  2959,
  2960,
  2961,
  2962,
  2964,
  2966,
  2967,
  2968,
  2970,
  2971,
  2972,
  2973,
  2974,
  2976,
  2977,
  2978,
  2981,
  2982,
  2983,
  2984,
  2985,
  2988,
  2989,
  2990,
  2991,
  2993,
  2994,
  2995,
  2997,
  2998,
  2999,
  3000,
  3002,
  3003,
  3004,
  3006,
  3007,
  3008,
  3009,
  3010,
  3012,
  3013,
  3014,
  3015,
  3017,
  3018,
  3019,
  3020,
  3021,
  3022,
  3024,
  3025,
  3026,
  3027,
  3028,
  3029,
  3030,
  3031,
  3032,
  3033,
  3034,
  3038,
  3041,
  3044,
  3045,
  3047,
  3048,
  3049,
  3051,
  3052,
  3053,
  3054,
  3055,
  3058,
  3059,
  3060,
  3061,
  3064,
  3065,
  3066,
  3067,
  3068,
  3069,
  3070,
  3071,
  3073,
  3074,
  3075,
  3076,
  3077,
  3078,
  3079,
  3080,
  3081,
  3082,
  3083,
  3086,
  3087,
  3089,
  3090,
  3091,
  3093,
  3094,
  3096,
  3098,
  3101,
  3102,
  3103,
  3104,
  3106,
  3107,
  3108,
  3111,
  3113,
  3115,
  3116,
  3117,
  3119,
  3121,
  3122,
  3124,
  3125,
  3127,
  3128,
  3130,
  3131,
  3133,
  3134,
  3135,
  3136,
  3138,
  3141,
  3145,
  3146,
  3148,
  3149,
  3150,
  3151,
  3152,
  3154,
  3155,
  3156,
  3157,
  3159,
  3160,
  3161,
  3162,
  3163,
  3164,
  3166,
  3170,
  3171,
  3172,
  3173,
  3174,
  3175,
  3178,
  3179,
  3180,
  3181,
  3182,
  3183,
  3185,
  3188,
  3191,
  3192,
  3193,
  3195,
  3196,
  3198,
  3200,
  3202,
  3203,
  3204,
  3205,
  3207,
  3208,
  3209,
  3210,
  3211,
  3212,
  3214,
  3216,
  3217,
  3219,
  3220,
  3221,
  3222,
  3224,
  3225,
  3226,
  3229,
  3230,
  3231,
  3232,
  3233,
  3234,
  3235,
  3236,
  3237,
  3238,
  3239,
  3240,
  3241,
  3242,
  3243,
  3244,
  3246,
  3247,
  3248,
  3249,
  3250,
  3251,
  3253,
  3255,
  3256,
  3257,
  3258,
  3259,
  3260,
  3261,
  3263,
  3265,
  3266,
  3267,
  3268,
  3270,
  3273,
  3274,
  3275,
  3278,
  3280,
  3282,
  3284,
  3285,
  3287,
  3288,
  3289,
  3293,
  3295,
  3298,
  3302,
  3303,
  3304,
  3305,
  3306,
  3307,
  3308,
  3309,
  3310,
  3311,
  3312,
  3316,
  3317,
  3318,
  3319,
  3320,
  3321,
  3322,
  3326,
  3330,
  3333,
  3334,
  3336,
  3338,
  3340,
  3342,
  3343,
  3344,
  3345,
  3346,
  3348,
  3349,
  3350,
  3351,
  3352,
  3353,
  3354,
  3355,
  3356,
  3361,
  3364,
  3365,
  3366,
  3367,
  3371,
  3373,
  3374,
  3375,
  3377,
  3378,
  3380,
  3388,
  3391,
  3394,
  3395,
  3397,
  3398,
  3399,
  3402,
  3403,
  3404,
  3406,
  3407,
  3409,
  3410,
  3413,
  3415,
  3416,
  3417,
  3418,
  3420,
  3421,
  3425,
  3427,
  3429,
  3430,
  3433,
  3434,
  3435,
  3436,
  3437,
  3438,
  3439,
  3441,
  3442,
  3444,
  3446,
  3447,
  3449,
  3451,
  3452,
  3453,
  3455,
  3456,
  3457,
  3463,
  3464,
  3465,
  3469,
  3470,
  3471,
  3472,
  3473,
  3480,
  3481,
  3483,
  3484,
  3487,
  3491,
  3492,
  3493,
  3495,
  3496,
  3497,
  3498,
  3500,
  3501,
  3502,
  3505,
  3507,
  3508,
  3512,
  3515,
  3520,
  3521,
  3523,
  3527,
  3535,
  3537,
  3539,
  3543,
  3545,
  3550,
  3551,
  3553,
  3554,
  3556,
  3558,
  3559,
  3560,
  3564,
  3565,
  3568,
  3569,
  3570,
  3572,
  3573,
  3575,
  3578,
  3581,
  3582,
  3587,
  3588,
  3590,
  3592,
  3593,
  3595,
  3599,
  3602,
  3603,
  3612,
  3613,
  3616,
  3617,
  3618,
  3620,
  3621,
  3622,
  3623,
  3625,
  3627,
  3628,
  3629,
  3635,
  3639,
  3640,
  3641,
  3642,
  3645,
  3646,
  3648,
  3649,
  3650,
  3654,
  3657,
  3659,
  3661,
  3663,
  3664,
  3665,
  3667,
  3668,
  3691,
  3697,
  3705,
  3709,
};

static const unsigned int aRadioChatterLength = 383;
static const unsigned int aRadioChatter[ aRadioChatterLength ] = {
  6,
  10,
  1284,
  1285,
  1372,
  1565,
  1786,
  1821,
  1944,
  1953,
  1980,
  2041,
  2074,
  2098,
  2105,
  2123,
  2185,
  2301,
  2305,
  2331,
  2406,
  2420,
  2443,
  2486,
  2538,
  2565,
  2567,
  2579,
  2599,
  2625,
  2649,
  2655,
  2672,
  2675,
  2684,
  2707,
  2712,
  2741,
  2757,
  2759,
  2765,
  2779,
  2782,
  2795,
  2798,
  2812,
  2815,
  2817,
  2823,
  2824,
  2827,
  2833,
  2838,
  2846,
  2850,
  2862,
  2864,
  2872,
  2875,
  2878,
  2893,
  2901,
  2909,
  2918,
  2927,
  2935,
  2938,
  2940,
  2942,
  2945,
  2948,
  2949,
  2958,
  2963,
  2965,
  2969,
  2975,
  2979,
  2980,
  2987,
  2992,
  2996,
  3001,
  3005,
  3011,
  3016,
  3023,
  3035,
  3036,
  3037,
  3039,
  3040,
  3042,
  3043,
  3046,
  3050,
  3056,
  3057,
  3062,
  3063,
  3072,
  3084,
  3085,
  3088,
  3092,
  3095,
  3097,
  3099,
  3100,
  3105,
  3109,
  3110,
  3112,
  3114,
  3118,
  3120,
  3123,
  3129,
  3132,
  3137,
  3139,
  3140,
  3142,
  3143,
  3144,
  3147,
  3153,
  3158,
  3165,
  3167,
  3168,
  3169,
  3176,
  3177,
  3184,
  3186,
  3187,
  3189,
  3190,
  3194,
  3197,
  3199,
  3201,
  3206,
  3213,
  3215,
  3218,
  3223,
  3227,
  3228,
  3245,
  3252,
  3254,
  3262,
  3264,
  3269,
  3271,
  3272,
  3276,
  3277,
  3279,
  3281,
  3283,
  3286,
  3290,
  3291,
  3292,
  3294,
  3296,
  3297,
  3299,
  3300,
  3301,
  3313,
  3315,
  3323,
  3324,
  3325,
  3327,
  3328,
  3329,
  3331,
  3332,
  3335,
  3337,
  3339,
  3341,
  3347,
  3357,
  3358,
  3359,
  3362,
  3363,
  3368,
  3369,
  3370,
  3372,
  3376,
  3379,
  3381,
  3382,
  3383,
  3384,
  3385,
  3386,
  3387,
  3389,
  3390,
  3392,
  3393,
  3396,
  3400,
  3401,
  3405,
  3408,
  3411,
  3412,
  3414,
  3419,
  3422,
  3423,
  3424,
  3426,
  3428,
  3431,
  3432,
  3440,
  3443,
  3445,
  3448,
  3450,
  3454,
  3458,
  3459,
  3460,
  3461,
  3462,
  3466,
  3467,
  3468,
  3474,
  3475,
  3476,
  3477,
  3478,
  3479,
  3482,
  3485,
  3486,
  3488,
  3489,
  3490,
  3494,
  3499,
  3503,
  3504,
  3506,
  3509,
  3510,
  3511,
  3513,
  3514,
  3516,
  3517,
  3518,
  3519,
  3522,
  3524,
  3525,
  3526,
  3528,
  3529,
  3530,
  3531,
  3532,
  3533,
  3534,
  3536,
  3538,
  3540,
  3541,
  3542,
  3544,
  3546,
  3547,
  3548,
  3549,
  3552,
  3555,
  3557,
  3561,
  3562,
  3563,
  3566,
  3567,
  3571,
  3574,
  3576,
  3577,
  3579,
  3580,
  3583,
  3584,
  3585,
  3586,
  3589,
  3591,
  3594,
  3596,
  3597,
  3598,
  3600,
  3601,
  3604,
  3605,
  3606,
  3607,
  3608,
  3609,
  3610,
  3611,
  3614,
  3615,
  3619,
  3624,
  3626,
  3630,
  3631,
  3632,
  3633,
  3634,
  3636,
  3637,
  3638,
  3643,
  3644,
  3647,
  3651,
  3652,
  3653,
  3655,
  3656,
  3658,
  3660,
  3662,
  3666,
  3669,
  3670,
  3671,
  3672,
  3673,
  3674,
  3675,
  3676,
  3677,
  3678,
  3679,
  3680,
  3681,
  3682,
  3683,
  3684,
  3685,
  3686,
  3687,
  3690,
  3692,
  3693,
  3694,
  3695,
  3696,
  3698,
  3699,
  3700,
  3702,
  3703,
  3704,
  3706,
  3708,
  3710,
  3711,
  3712,
  3713,
};

static const unsigned int aValerie_AffirmativeLength = 12;
static const char *aValerie_Affirmative[ aValerie_AffirmativeLength ] = {
  "languages\\voicepacks\\Val\\affirmative_1.wav",
  "languages\\voicepacks\\Val\\affirmative_2.wav",
  "languages\\voicepacks\\Val\\affirmative_3.wav",
  "languages\\voicepacks\\Val\\affirmative_4.wav",
  "languages\\voicepacks\\Val\\affirmative_5.wav",
  "languages\\voicepacks\\Val\\affirmative_6.wav",
  "languages\\voicepacks\\Val\\affirmative_7.wav",
  "languages\\voicepacks\\Val\\affirmative_8.wav",
  "languages\\voicepacks\\Val\\affirmative_8_b.wav",
  "languages\\voicepacks\\Val\\affirmative_8_c.wav",
  "languages\\voicepacks\\Val\\affirmative_9.wav",
  "languages\\voicepacks\\Val\\affirmative_10.wav"
};

static const unsigned int aValerie_AlarmLength = 8;
static const char *aValerie_Alarm[ aValerie_AlarmLength ] = {
  "languages\\voicepacks\\Val\\yell_attention_1.wav",
  "languages\\voicepacks\\Val\\yell_attention_2.wav",
  "languages\\voicepacks\\Val\\yell_attention_3.wav",
  "languages\\voicepacks\\Val\\yell_attention_4.wav",
  "languages\\missiontalk\\swamp\\still_someone_a2.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_B_1.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_B_3.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_19.wav"
};

static const unsigned int aValerie_AlertToCombatLength = 13;
static const char *aValerie_AlertToCombat[ aValerie_AlertToCombatLength ] = {
  "languages\\missiontalk\\swamp\\swamp_pickup_B_4.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_9.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_7.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_9.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_17.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_4.wav",
  "languages\\voicepacks\\Val\\affirmative_2.wav",
  "languages\\voicepacks\\Val\\affirmative_5.wav",
  "languages\\voicepacks\\Val\\affirmative_8_b.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_7.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_7.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_13.wav",
  "languages\\missiontalk\\ruins\\templeruins_specific_G_4.wav"
};

static const unsigned int aValerie_AlertToIdleLength = 5;
static const char *aValerie_AlertToIdle[ aValerie_AlertToIdleLength ] = {
  "languages\\missiontalk\\swamp\\seek_target_a1.wav",
  "languages\\missiontalk\\swamp\\seek_target_a3.wav",
  "languages\\missiontalk\\swamp\\still_someone_a3.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_F_20.wav",
  "languages\\missiontalk\\ruins\\templeruins_specific_G_1.wav"
};

static const unsigned int aValerie_CombatAloneLength = 9;
static const char *aValerie_CombatAlone[ aValerie_CombatAloneLength ] = {
  "languages\\voicepacks\\Val\\affirmative_10.wav",
  "languages\\voicepacks\\Val\\affirmative_9.wav",
  "languages\\voicepacks\\Val\\affirmative_3.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_5.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_7.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_11.wav",
  "languages\\voicepacks\\Val\\yell_5.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_3.wav",
  "languages\\voicepacks\\Val\\affirmative_1.wav"
};

static const unsigned int aValerie_CombatGroupLength = 14;
static const char *aValerie_CombatGroup[ aValerie_CombatGroupLength ] = {
  "languages\\missiontalk\\swamp\\following_player_a3.wav",
  "languages\\missiontalk\\swamp\\still_someone_a2.wav",
  "languages\\missiontalk\\compound\\compound_specific_A_14.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_B_4.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_B_3.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_17.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_19.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_20.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_4.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_7.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_8.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_4.wav",
  "languages\\missiontalk\\ruins\\templeruins_specific_G_1.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_D_2.wav"
};

static const unsigned int aValerie_CombatToAlertLength = 5;
static const char *aValerie_CombatToAlert[ aValerie_CombatToAlertLength ] = {
  "languages\\missiontalk\\swamp\\seek_target_a1.wav",
  "languages\\missiontalk\\swamp\\seek_target_a3.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_F_20.wav",
  "languages\\missiontalk\\ruins\\templeruins_specific_G_1.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_4.wav"
};

static const unsigned int aValerie_CommandsAllLength = 15;
static const char *aValerie_CommandsAll[ aValerie_CommandsAllLength ] = {
  "languages\\missiontalk\\compound\\compound_specific_A_12.wav",
  "languages\\missiontalk\\compound\\compound_specific_A_7.wav",
  "languages\\missiontalk\\compound\\compound_specific_A_14.wav",
  "languages\\voicepacks\\Val\\affirmative_2.wav",
  "languages\\voicepacks\\Val\\affirmative_6.wav",
  "languages\\voicepacks\\Val\\affirmative_7.wav",
  "languages\\voicepacks\\Val\\affirmative_1.wav",
  "languages\\voicepacks\\Val\\affirmative_4.wav",
  "languages\\missiontalk\\compound\\compound_specific_C_4.wav",
  "languages\\missiontalk\\swamp\\following_player_a2.wav",
  "languages\\missiontalk\\swamp\\go_to_waypoint_a1.wav",
  "languages\\missiontalk\\swamp\\still_someone_a2.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_B_3.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_A_8.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_21.wav"
};

static const unsigned int aValerie_DeathLength = 23;
static const char *aValerie_Death[ aValerie_DeathLength ] = {
  "languages\\voicepacks\\Val\\death_4.wav",
  "languages\\voicepacks\\Val\\death_5.wav",
  "languages\\voicepacks\\Val\\death_6.wav",
  "languages\\voicepacks\\Val\\death_7.wav",
  "languages\\voicepacks\\Val\\death_8.wav",
  "languages\\voicepacks\\Val\\death_9.wav",
  "languages\\voicepacks\\Val\\death_10.wav",
  "languages\\voicepacks\\Val\\death_11.wav",
  "languages\\voicepacks\\Val\\death_12.wav",
  "languages\\voicepacks\\Val\\death_13.wav",
  "languages\\voicepacks\\Val\\death_14.wav",
  "languages\\voicepacks\\Val\\death_15.wav",
  "languages\\voicepacks\\Val\\death_16.wav",
  "languages\\voicepacks\\Val\\death_17.wav",
  "languages\\voicepacks\\Val\\death_18.wav",
  "languages\\voicepacks\\Val\\death_19.wav",
  "languages\\voicepacks\\Val\\death_20.wav",
  "languages\\voicepacks\\Val\\death_21.wav",
  "languages\\voicepacks\\Val\\death_1.wav",
  "languages\\voicepacks\\Val\\death_2.wav",
  "languages\\voicepacks\\Val\\death_3.wav",
  "languages\\voicepacks\\Val\\pain_4.wav",
  "languages\\voicepacks\\Val\\pain_8.wav"
};

static const unsigned int aValerie_GrenadeAnyLength = 13;
static const char *aValerie_GrenadeAny[ aValerie_GrenadeAnyLength ] = {
  "languages\\voicepacks\\Val\\receive_fire_alone_13.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_7.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_B_4.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_C_1.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_17.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_21.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_F_20.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_4.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_7.wav",
  "languages\\voicepacks\\Val\\yell_2.wav",
  "languages\\voicepacks\\Val\\yell_5.wav",
  "languages\\voicepacks\\Val\\yell_9.wav",
  "languages\\voicepacks\\Val\\yell_attention_2.wav"
};

static const unsigned int aValerie_IdleToAlertLength = 9;
static const char *aValerie_IdleToAlert[ aValerie_IdleToAlertLength ] = {
  "languages\\voicepacks\\Val\\receive_fire_alone_1.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_8.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_9.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_10.wav",
  "languages\\voicepacks\\Val\\yell_9.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_A_1.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_B_1.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_6.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_8.wav"
};

static const unsigned int aValerie_ManDownLength = 6;
static const char *aValerie_ManDown[ aValerie_ManDownLength ] = {
  "languages\\missiontalk\\swamp\\still_someone_a3.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_13.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_14.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_15.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_12.wav",
  "languages\\missiontalk\\swamp\\seek_target_a1.wav"
};

static const unsigned int aValerie_PainLength = 21;
static const char *aValerie_Pain[ aValerie_PainLength ] = {
  "languages\\voicepacks\\Val\\pain_10.wav",
  "languages\\voicepacks\\Val\\pain_11.wav",
  "languages\\voicepacks\\Val\\pain_12.wav",
  "languages\\voicepacks\\Val\\pain_13.wav",
  "languages\\voicepacks\\Val\\pain_14.wav",
  "languages\\voicepacks\\Val\\pain_15.wav",
  "languages\\voicepacks\\Val\\pain_16.wav",
  "languages\\voicepacks\\Val\\pain_17.wav",
  "languages\\voicepacks\\Val\\pain_18.wav",
  "languages\\voicepacks\\Val\\pain_19.wav",
  "languages\\voicepacks\\Val\\pain_20.wav",
  "languages\\voicepacks\\Val\\pain_21.wav",
  "languages\\voicepacks\\Val\\pain_1.wav",
  "languages\\voicepacks\\Val\\pain_2.wav",
  "languages\\voicepacks\\Val\\pain_3.wav",
  "languages\\voicepacks\\Val\\pain_4.wav",
  "languages\\voicepacks\\Val\\pain_5.wav",
  "languages\\voicepacks\\Val\\pain_6.wav",
  "languages\\voicepacks\\Val\\pain_7.wav",
  "languages\\voicepacks\\Val\\pain_8.wav",
  "languages\\voicepacks\\Val\\pain_9.wav"
};

static const unsigned int aValerie_ReceiveFireAllLength = 19;
static const char *aValerie_ReceiveFireAll[ aValerie_ReceiveFireAllLength ] = {
  "languages\\voicepacks\\Val\\receive_fire_alone_1.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_2.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_3.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_4.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_5.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_6.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_6_b.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_6_c.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_7.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_8.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_9.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_10.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_11.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_12.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_13.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_14.wav",
  "languages\\voicepacks\\Val\\receive_fire_alone_15.wav",
  "languages\\missiontalk\\swamp\\still_someone_a2.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_6.wav"
};

static const unsigned int aValerie_ReinforceLength = 8;
static const char *aValerie_Reinforce[ aValerie_ReinforceLength ] = {
  "languages\\missiontalk\\swamp\\swamp_pickup_B_3.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_D_2.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_19.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_4.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_F_20.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_6.wav",
  "languages\\missiontalk\\cooler\\cooler_specific_B_1.wav",
  "languages\\missiontalk\\cooler\\cooler_specific_C_4.wav"
};

static const unsigned int aValerie_SearchAllLength = 5;
static const char *aValerie_SearchAll[ aValerie_SearchAllLength ] = {
  "languages\\voicepacks\\Val\\receive_fire_alone_7.wav",
  "languages\\missiontalk\\swamp\\seek_target_a3.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_D_1.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_F_20.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_K_3.wav"
};

static const unsigned int aValerie_VehicleInLength = 5;
static const char *aValerie_VehicleIn[ aValerie_VehicleInLength ] = {
  "languages\\missiontalk\\compound\\compound_specific_A_14.wav",
  "languages\\missiontalk\\swamp\\go_to_waypoint_a1.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_A_1.wav",
  "languages\\missiontalk\\swamp\\swamp_pickup_A_2.wav",
  "languages\\missiontalk\\swamp\\swamp_specific_E_17.wav"
};

static const unsigned int aValerie_YellLength = 10;
static const char *aValerie_Yell[ aValerie_YellLength ] = {
  "languages\\voicepacks\\Val\\yell_1.wav",
  "languages\\voicepacks\\Val\\yell_2.wav",
  "languages\\voicepacks\\Val\\yell_3.wav",
  "languages\\voicepacks\\Val\\yell_4.wav",
  "languages\\voicepacks\\Val\\yell_5.wav",
  "languages\\voicepacks\\Val\\yell_6.wav",
  "languages\\voicepacks\\Val\\yell_7.wav",
  "languages\\voicepacks\\Val\\yell_8.wav",
  "languages\\voicepacks\\Val\\yell_9.wav",
  "languages\\voicepacks\\Val\\yell_10.wav"
};

static const unsigned int aValerie_YellAttentionLength = 4;
static const char *aValerie_YellAttention[ aValerie_YellAttentionLength ] = {
  "languages\\voicepacks\\Val\\yell_attention_1.wav",
  "languages\\voicepacks\\Val\\yell_attention_2.wav",
  "languages\\voicepacks\\Val\\yell_attention_3.wav",
  "languages\\voicepacks\\Val\\yell_attention_4.wav"
};

struct CharKeyCompare{
  bool operator( )( const char *a , const char *b ) const {
    return strcmp( a , b ) < 0;
  }
};

typedef std::map<const char * , const unsigned int , CharKeyCompare> SoundLookup;
static SoundLookup *pLookupLanguages;
static SoundLookup *pLookupSounds;

static bool IsInitialized = false;
static const char *InitTrigger = "%StartUp%";

void hkLoadSound::StartupSoundDB( bool Ready ){
  if( !IsInitialized ){
    if( !Ready ){
      FunLog::Log( FUNLOG_BASIC , "Starting sound module | Begin" );
      hkLoadSound::ProcessSound( InitTrigger );
      return;
    }

    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_1_voiceb.wav" , 1504 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_a_1.wav" , 2888 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_n_5.wav" , 2182 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_6_voiced.wav" , 1840 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\flashbang_6_voicea.wav" , 1725 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_c_2.wav" , 3673 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_2.wav" , 2276 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_b_2.wav" , 2761 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_4.wav" , 2257 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_3.wav" , 3196 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_retreat_2_voiceb.wav" , 2049 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_a_1bis.wav" , 3336 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_4.wav" , 3195 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_3_voicea.wav" , 312 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\helicopter_sight_8_voicea.wav" , 2263 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_8_voicea.wav" , 313 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_attention_3_voiced.wav" , 190 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\flashlight_face_4_voiced.wav" , 2469 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_8_voiceb.wav" , 1023 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_i_3.wav" , 3505 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_4_voiced.wav" , 1148 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_o_5.wav" , 1372 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_4.wav" , 3547 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_c_4.wav" , 3148 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_16.wav" , 2629 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_6.wav" , 1498 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_2_voiced.wav" , 1600 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_i_2.wav" , 3609 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_right_2_voiced.wav" , 1107 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\flashbang_6_voiceb.wav" , 1666 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_5_voicea.wav" , 287 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_1_voicec.wav" , 1471 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_19.wav" , 150 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_4.wav" , 413 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\doyle_8.wav" , 3706 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_jungle\\mp_jungle_c2_a1.wav" , 2872 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_freighter\\mp_freighter_c1_d1.wav" , 3357 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_d_3.wav" , 2654 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_alone_1_voicea.wav" , 16 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_20_voicec.wav" , 1856 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_advance_left_2_voiceb.wav" , 1580 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_9.wav" , 3709 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_12.wav" , 931 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_3.wav" , 3617 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_4.wav" , 3603 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\mandown_alone_1_voicea.wav" , 612 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_7_voicea.wav" , 974 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_suppress_4_voiceb.wav" , 1085 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_pickup_b_2.wav" , 800 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_6.wav" , 3645 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_4_voicea.wav" , 1732 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_f_2.wav" , 755 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_al_3_voicea.wav" , 738 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_5_voicea.wav" , 958 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_b_8.wav" , 2551 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_player_6_voicea.wav" , 2569 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_20_voicec.wav" , 1474 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_c_5.wav" , 3270 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alarm_group_1_voicea.wav" , 1057 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_a_1.wav" , 2982 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\announce5.wav" , 3206 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_group_2_voicec.wav" , 401 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_12_voicec.wav" , 2029 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_4.wav" , 3470 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_1_voicea.wav" , 523 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\darkness_1_voicea.wav" , 1371 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_12_voicea.wav" , 214 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_generic_7_voicec.wav" , 620 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_group_1_voicec.wav" , 412 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_alone_2_voicec.wav" , 46 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_al_6_voicea.wav" , 1939 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_alone_2_voicea.wav" , 160 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_35_voicec.wav" , 1174 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_2.wav" , 2455 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_6_voicec.wav" , 2347 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_1_voicec.wav" , 851 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_group_2_voicec.wav" , 700 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_3.wav" , 1142 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_group_5_voicea.wav" , 1640 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_3.wav" , 3189 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\flashbang_3_voiceb.wav" , 1238 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_macho_4_voiceb.wav" , 2458 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_group_2_voicea.wav" , 101 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_4.wav" , 1907 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_6.wav" , 2191 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_3_voiced.wav" , 265 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_group_2_voiced.wav" , 251 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c2_a1.wav" , 3538 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_1_voiceb.wav" , 675 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\grenade_3_voiced.wav" , 1098 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_14_voicec.wav" , 1590 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_e_6.wav" , 3063 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_6.wav" , 2565 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_7_voiced.wav" , 526 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_9.wav" , 2252 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_i_5.wav" , 3578 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\helicopter_sight_3_voicea.wav" , 2592 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_c_1.wav" , 2338 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_6_voicea.wav" , 872 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_c_2.wav" , 2419 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_lake\\mp_lake_c3_a1.wav" , 1980 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_20_voiceb.wav" , 1485 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\flashbang_2_voiceb.wav" , 1017 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_3_voicea.wav" , 133 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_11.wav" , 3391 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_34_voiceb.wav" , 1783 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\radio_fx_in.wav" , 6 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_e_4.wav" , 3105 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_g_2.wav" , 41 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_b_1.wav" , 2968 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_8_voiceb.wav" , 270 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_lake\\mp_lake_c2_a1.wav" , 2918 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_18_voicec.wav" , 987 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_6_voiced.wav" , 2278 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_5.wav" , 3549 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_8.wav" , 3010 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_1_voiced.wav" , 1850 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_11.wav" , 1977 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_i_1.wav" , 3163 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_6_voiceb.wav" , 281 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_34_voicea.wav" , 1421 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_gp_3_voiced.wav" , 1601 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_3_voiced.wav" , 559 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_group_2_voiceb.wav" , 964 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_13_voiceb.wav" , 734 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_8.wav" , 3024 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_19_voiced.wav" , 1031 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_f_2.wav" , 50 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_8_voiced.wav" , 778 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_attention_1_voiceb.wav" , 53 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_i_6.wav" , 2203 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\jack_4.wav" , 2690 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_a_6.wav" , 2683 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_4_voiced.wav" , 203 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_talk_to_2_voicec.wav" , 2299 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_al_7_voicea.wav" , 558 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_d_2.wav" , 3449 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_d_2.wav" , 3438 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_a_2.wav" , 3319 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_3_voicec.wav" , 127 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_5.wav" , 2350 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_group_1_voiced.wav" , 847 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_b_3.wav" , 1137 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_e_3.wav" , 2156 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_4_voiceb.wav" , 1597 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_1.wav" , 2786 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_f_4.wav" , 2987 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_16.wav" , 3271 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_7.wav" , 2951 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_e_7.wav" , 2664 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_3.wav" , 3685 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_l_3.wav" , 2880 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_4.wav" , 2283 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_fear_1_voiced.wav" , 634 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_i_4.wav" , 1470 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_a_4.wav" , 2039 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\mandown_group_1_voiceb.wav" , 1377 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_mutants_2_voiced.wav" , 2887 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_1.wav" , 2882 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_2_alert_seen_group_3.wav" , 1872 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_30_voicea.wav" , 1328 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_f_5.wav" , 2584 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_j_2.wav" , 3562 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\gasp.wav" , 231 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_4_group_voicec.wav" , 1114 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_d_1b.wav" , 2311 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_2_voiced.wav" , 384 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_10.wav" , 3298 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_f_1.wav" , 3286 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_5.wav" , 2724 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_14_voicec.wav" , 104 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_13.wav" , 2820 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_8.wav" , 439 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_8_voiced.wav" , 1248 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_b_3.wav" , 2926 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_1.wav" , 3233 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_9.wav" , 2521 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_13.wav" , 2324 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_attention_2_voicea.wav" , 17 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_a_4.wav" , 3151 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_6_voicea.wav" , 1382 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_5.wav" , 3136 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_2_alert_seen_group_2.wav" , 1878 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_c_2.wav" , 3229 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_5_voiced.wav" , 1853 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_attention_5_voiceb.wav" , 233 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_4_voiceb.wav" , 890 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\darkness_2_voiceb.wav" , 1596 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alarm_group_3_voiced.wav" , 2529 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_group_2_voicea.wav" , 628 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_9.wav" , 2041 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_4_voiced.wav" , 139 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_4_voicea.wav" , 915 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_2.wav" , 2463 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_7_voicea.wav" , 324 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alarm_group_2_voicea.wav" , 1644 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_20.wav" , 1112 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_14.wav" , 2374 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alone_sniffle_1_voicea.wav" , 130 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_11_voiceb.wav" , 591 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_19_voicea.wav" , 1028 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_1.wav" , 1942 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_8_voicea.wav" , 1647 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_a_6.wav" , 3353 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_7.wav" , 1667 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\grenade_1.wav" , 2221 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_8_voiced.wav" , 736 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_f_2.wav" , 962 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_group_6_voiceb.wav" , 1637 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_3.wav" , 2790 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_c_5.wav" , 3034 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_6.wav" , 726 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_8.wav" , 239 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\seek_target_a1.wav" , 2383 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_4.wav" , 2196 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_g_2.wav" , 47 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_a_3.wav" , 3509 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_12_voicec.wav" , 922 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_2.wav" , 2378 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_12.wav" , 2491 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_1_voiced.wav" , 1552 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_g_8.wav" , 871 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_19_voiceb.wav" , 320 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_go_get_2_voiced.wav" , 2444 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_c_5.wav" , 1749 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_b_1.wav" , 3375 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_3_voicea.wav" , 2682 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_rush_2_voiced.wav" , 502 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_c_3.wav" , 3222 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_f_1.wav" , 3466 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_4.wav" , 2736 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_suppress_3_voiced.wav" , 1170 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_fear_3_voiceb.wav" , 78 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_go_get_5_voiced.wav" , 2477 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_group_4_voicea.wav" , 1317 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_g_10.wav" , 3409 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_macho_1_voiced.wav" , 740 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_3.wav" , 2158 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\mandown_group_2_voiced.wav" , 1350 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_e_2.wav" , 3468 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_2_voicec.wav" , 416 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\announce3.wav" , 3291 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_right_3r_voiced.wav" , 941 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\doyle_7.wav" , 3011 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\jack_10.wav" , 2229 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8f.wav" , 1065 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_i_3.wav" , 2762 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_45_voicea.wav" , 1906 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_15_voicea.wav" , 1967 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_3.wav" , 2947 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\helicopter_sight_6_voiceb.wav" , 2562 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_35_voiced.wav" , 1175 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_16.wav" , 3126 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_c_1.wav" , 3224 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_10.wav" , 1587 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_c_5.wav" , 1516 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_4_voiced.wav" , 1477 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\mandown_group_4_voiceb.wav" , 748 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_k_6.wav" , 798 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_a_2.wav" , 3145 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_e_3.wav" , 2777 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_pickup_e_6.wav" , 3035 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_mercs_a_5.wav" , 2733 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_8.wav" , 2120 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_4_voiced.wav" , 837 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_g_2.wav" , 3394 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_6bis.wav" , 3536 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\mandown_group_4_voiced.wav" , 1231 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_a_4.wav" , 1981 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_player_4_voiced.wav" , 2837 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_6.wav" , 3469 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_e_1.wav" , 2955 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_alone_5_voiced.wav" , 138 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_b_1.wav" , 3567 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_1.wav" , 2558 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_18b.wav" , 2656 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_group_5_voiced.wav" , 510 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\flashbang_4_voiceb.wav" , 1326 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_2_voiceb.wav" , 1197 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_g_1.wav" , 3402 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_b_2.wav" , 3113 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_retreat_1_voicec.wav" , 2622 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reloaded_2_voicea.wav" , 984 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_b_6.wav" , 3192 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\mandown_group_3_voiced.wav" , 1875 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_generic_1_voiced.wav" , 685 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_8.wav" , 933 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_mutants_2_voicea.wav" , 2884 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_12_voicec.wav" , 627 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_seen_gp_2_voicea.wav" , 506 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_14_voiced.wav" , 336 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_a_2.wav" , 1862 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_b_6.wav" , 3406 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_7_voicec.wav" , 1547 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_19.wav" , 3232 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_5.wav" , 3465 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_generic_6_voicec.wav" , 1916 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_group_5_voiced.wav" , 2066 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\mandown_group_1_voiced.wav" , 1426 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_a_4.wav" , 2423 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_h_6bis.wav" , 1865 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_a_5.wav" , 3212 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_a_4.wav" , 1435 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_3.wav" , 2063 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_b_1.wav" , 3128 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_6.wav" , 3550 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_4.wav" , 3244 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_b_5.wav" , 3250 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_10.wav" , 2532 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_a_3.wav" , 3379 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_6_voicea.wav" , 2002 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_5_voiced.wav" , 766 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_h_7.wav" , 3403 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_14_voiceb.wav" , 1714 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_9.wav" , 2608 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_g_2.wav" , 274 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_generic_7_voiceb.wav" , 619 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_6_voiced.wav" , 2200 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_go_get_4_voicea.wav" , 1263 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_f_2.wav" , 3343 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_alone_1_voiceb.wav" , 222 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_28_voicec.wav" , 1791 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_alone_3_voiced.wav" , 442 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_c_3.wav" , 3132 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_6_voiceb.wav" , 2153 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_suppress_1_voicea.wav" , 1407 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_mutants_4_voiceb.wav" , 2175 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reloaded_1_voicea.wav" , 699 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_4_voiceb.wav" , 1528 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_15.wav" , 2077 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_10.wav" , 3134 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_2.wav" , 2591 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_2_voiced.wav" , 426 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_1_alone_voiced.wav" , 1903 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\vehicle_in_3_voiced.wav" , 430 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_f_2.wav" , 3569 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_g_4.wav" , 305 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_advance_right_1_voicea.wav" , 843 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_al_4_voicea.wav" , 1997 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_2_alert_seen_group_1.wav" , 2325 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_right_3r_voicea.wav" , 730 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\silence1.wav" , 0 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_group_3_voiced.wav" , 2146 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_42_voiceb.wav" , 2057 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_k_2.wav" , 3340 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_d_2.wav" , 247 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_fear_2_voiced.wav" , 907 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_c_1.wav" , 3313 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_fear_2_voicea.wav" , 385 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_5_voicec.wav" , 593 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_22_voicec.wav" , 1738 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_9.wav" , 3632 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_13_voicec.wav" , 1060 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_e_5.wav" , 2172 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_k_3.wav" , 2625 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_5.wav" , 3546 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_1.wav" , 338 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_alone_3_voicea.wav" , 714 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_15_voiceb.wav" , 1541 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\mandown_alone_1_voicec.wav" , 386 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_specific_a_5.wav" , 3644 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_3.wav" , 454 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_36_voicec.wav" , 2500 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\_swamp_specific_f_6bis.wav" , 2659 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_macho_5_voiceb.wav" , 2639 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_6_voiced.wav" , 1687 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_44_voicec.wav" , 2154 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\flashlight_face_1_voiced.wav" , 1796 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_41_voiceb.wav" , 2382 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_6.wav" , 3542 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\vehicle_in_8_voicea.wav" , 661 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_5_voiced.wav" , 115 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_10.wav" , 1088 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_15_voiced.wav" , 223 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_2_voiced.wav" , 2653 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_go_get_3_voiceb.wav" , 2386 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_d_7.wav" , 1868 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_9.wav" , 2687 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_a_3.wav" , 3302 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_c_1.wav" , 3671 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_supress_1r_voiced.wav" , 1188 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_7.wav" , 723 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_talk_to_4_voicea.wav" , 1455 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_1.wav" , 2456 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_6.wav" , 3710 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_generic_5_voicea.wav" , 908 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_1.wav" , 2085 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_group_1_voicea.wav" , 216 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_10_voicec.wav" , 533 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_4.wav" , 1143 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\vehicle_in_8_voiceb.wav" , 1027 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_5_voiceb.wav" , 242 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_f_3.wav" , 3413 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_18_voiceb.wav" , 1801 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8j.wav" , 90 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_6_voicea.wav" , 447 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_group_1_voiced.wav" , 1252 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_gp_1_voiced.wav" , 1341 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_c_4.wav" , 2528 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_9.wav" , 745 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_7_voicea.wav" , 1492 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_5.wav" , 3142 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_9.wav" , 760 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_13.wav" , 1291 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_h_4.wav" , 3225 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_b_1.wav" , 3376 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_b_7.wav" , 1795 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\mandown_group_1_voicec.wav" , 1011 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_8_voicea.wav" , 1836 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_f_4.wav" , 3602 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_16.wav" , 1688 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_3.wav" , 2878 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_freighter\\mp_freighter_c1_a1.wav" , 2965 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_4.wav" , 417 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier4.wav" , 3097 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_e_4.wav" , 2574 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_2.wav" , 2760 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_6.wav" , 1842 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_1_voicea.wav" , 963 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_8_voiced.wav" , 400 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_b_1bis.wav" , 2396 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_13.wav" , 1464 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_9.wav" , 1821 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_attention_5_voiced.wav" , 235 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\helicopter_sight_5_voiceb.wav" , 2588 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_4_voicec.wav" , 343 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_3_voicea.wav" , 1417 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_c_3.wav" , 3078 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_3.wav" , 56 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_retreat_1r_voiced.wav" , 1166 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_5.wav" , 3207 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_mutants_1_voicea.wav" , 2253 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\helicopter_sight_7_voicea.wav" , 2913 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_23_voicea.wav" , 1985 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_2_voicea.wav" , 935 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_mercs_b_6.wav" , 3451 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_7_voiced.wav" , 500 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_g_5.wav" , 2787 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_g_12.wav" , 2744 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\comm_retreat_3.wav" , 1851 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\go_to_waypoint_a1.wav" , 1782 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\mandown_alone_3_voicea.wav" , 668 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\helicopter_sight_1_voiced.wav" , 1244 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_attention_5_voicea.wav" , 19 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_group_5_voiceb.wav" , 912 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_16_voicea.wav" , 1866 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_2_voiceb.wav" , 1262 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_generic_1_voicea.wav" , 29 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_5.wav" , 1449 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_16_voiceb.wav" , 1573 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_4_voicea.wav" , 441 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_d_2.wav" , 3074 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_6_voicea.wav" , 245 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\maskboys.wav" , 3510 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alarm_alone_5_voiced.wav" , 342 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_2_voiced.wav" , 390 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_11.wav" , 754 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_39_voiced.wav" , 1845 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_22_voiceb.wav" , 1930 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_19_voicea.wav" , 1228 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_3_voicec.wav" , 293 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_12_voiced.wav" , 2181 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_9.wav" , 3237 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_right_2r_voiced.wav" , 1106 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_d_6.wav" , 787 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_b_5.wav" , 2759 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_13.wav" , 105 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_12.wav" , 3114 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_h_2.wav" , 3374 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_5.wav" , 3497 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_15_voicec.wav" , 106 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_go_get_3_voicea.wav" , 2540 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\darkness_4_voiceb.wav" , 1715 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_b_4.wav" , 3322 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_lake\\mp_lake_c2_d1.wav" , 2846 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_6_voicea.wav" , 1657 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_b_3.wav" , 3044 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_group_4_voiced.wav" , 1567 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_h_1.wav" , 2388 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_9.wav" , 3101 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_11_voicea.wav" , 1115 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_group_5.wav" , 2234 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_1.wav" , 601 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_1.wav" , 1570 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_13_voicea.wav" , 2091 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_advance_right_3_voicea.wav" , 2011 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_13_voicec.wav" , 981 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_group_5_voicea.wav" , 1483 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_1.wav" , 2228 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_mutants_3_voicec.wav" , 2047 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_g_1.wav" , 3111 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_alone_7_voiced.wav" , 1123 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alone_throatc_1_voicea.wav" , 633 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_10_voicea.wav" , 1974 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_b_1.wav" , 3239 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_16_voicec.wav" , 2135 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alarm_alone_1_voiceb.wav" , 404 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_retreat_3_voiced.wav" , 460 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_e_3.wav" , 2823 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_2.wav" , 1358 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_15_voicec.wav" , 645 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_k_1.wav" , 2794 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_fear_2_voiced.wav" , 193 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_group_1.wav" , 784 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_10_voicec.wav" , 2111 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_b_4.wav" , 1613 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_3.wav" , 327 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_group_6_voicea.wav" , 1322 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_fear_2_voiceb.wav" , 191 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_group_2_voiced.wav" , 759 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_f_5.wav" , 2729 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_15_voicea.wav" , 2626 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_3_voiced.wav" , 1340 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_freighter\\mp_freighter_c2_d1.wav" , 3276 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_flank_left_3_voiceb.wav" , 664 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\ross.wav" , 3378 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_e_4.wav" , 1969 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_3_voiceb.wav" , 1203 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\darkness_1_voiceb.wav" , 1867 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_8_voicec.wav" , 2023 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_1_voiced.wav" , 2125 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_g_1.wav" , 3522 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alarm_alone_4_voicec.wav" , 2197 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_group_5_voicea.wav" , 656 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_6.wav" , 3327 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_mutants_2_voiceb.wav" , 2885 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_1.wav" , 3712 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_7.wav" , 2318 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_6_voicea.wav" , 346 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_10_voiceb.wav" , 328 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_10b.wav" , 2713 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_10.wav" , 2293 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_7_voicea.wav" , 1496 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_j_5.wav" , 3629 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\vehicle_in_5_voiceb.wav" , 1247 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_2_alone_voiceb.wav" , 521 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_a_4.wav" , 3648 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_12.wav" , 2401 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_advance_left_3_voiceb.wav" , 1763 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_pickup_e_3.wav" , 2631 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_fear_5_voiceb.wav" , 290 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_b_7.wav" , 3095 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_attention_3_voicec.wav" , 189 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_pickup_b_3.wav" , 1860 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\vehicle_in_5_voiced.wav" , 552 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_c_1bisj.wav" , 2764 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_24.wav" , 3589 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_a_2.wav" , 3205 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_9_voicea.wav" , 166 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_a_3.wav" , 3405 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_o_3.wav" , 3005 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_e_1.wav" , 3181 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_a_2.wav" , 2073 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alone_song_1_voicea.wav" , 2251 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_7.wav" , 3260 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_13.wav" , 2165 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_group_4_voiced.wav" , 1100 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_7_voicea.wav" , 2470 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_e_1.wav" , 2954 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\vehicle_in_8_voicec.wav" , 1232 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_17.wav" , 1879 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_e_1.wav" , 3399 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_16.wav" , 2633 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_a_1.wav" , 3265 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_5.wav" , 1659 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_11_voiced.wav" , 551 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_8_voicec.wav" , 484 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_g_2.wav" , 3354 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_flank_right_3_voiced.wav" , 1389 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_generic_3_voicec.wav" , 1468 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_6_b.wav" , 613 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_25_voiced.wav" , 1800 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_i_1.wav" , 1921 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_7_voicec.wav" , 1615 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\mandown_group_4.wav" , 2052 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_10_voicea.wav" , 1277 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_b_5.wav" , 3296 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_e_2.wav" , 3491 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_2.wav" , 2550 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_7_voicec.wav" , 742 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alarm_alone_4_voicea.wav" , 360 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_f_3.wav" , 2727 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_14_voiceb.wav" , 1287 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_5.wav" , 2210 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_4.wav" , 1614 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_d_5.wav" , 2001 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_2.wav" , 3463 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_5.wav" , 1744 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_12_voiced.wav" , 2030 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alarm_alone_1_voicec.wav" , 240 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_7_voiceb.wav" , 529 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_d_1.wav" , 3674 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_18.wav" , 1707 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\flashlight_face_2_voicea.wav" , 1713 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_15_voicec.wav" , 420 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_al_3_voicea.wav" , 232 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c3_a1.wav" , 1284 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_20_voiced.wav" , 146 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_14.wav" , 2494 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_g_4x.wav" , 3657 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_e_5.wav" , 3355 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\grenade_4_voicea.wav" , 309 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_1.wav" , 3483 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\darkness_2_voiced.wav" , 1669 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_1.wav" , 965 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_2_voicea.wav" , 826 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_3_voiced.wav" , 1652 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_7_voicea.wav" , 95 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reloaded_3_voicea.wav" , 680 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_5_voiced.wav" , 363 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_advance_left_1_voicec.wav" , 955 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_8.wav" , 3452 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_g_4$.wav" , 2740 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_e_3x.wav" , 3529 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_3_group_voicec.wav" , 825 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_31_voicea.wav" , 1979 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_2_voiced.wav" , 212 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_mutants_3_voiced.wav" , 2048 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\darkness_5_voiced.wav" , 1035 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_11_voiced.wav" , 1839 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_a_2.wav" , 2367 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_h_4.wav" , 2413 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_go_get_1_voiced.wav" , 642 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_43_voicec.wav" , 2244 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_12y.wav" , 728 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_c_1.wav" , 3676 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_3.wav" , 1505 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_h_1.wav" , 3672 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\still_someone_a2.wav" , 1841 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_b_1.wav" , 1555 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_5_voicea.wav" , 904 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_2.wav" , 1956 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_8_voiced.wav" , 679 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_c_8.wav" , 2031 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier5.wav" , 3036 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_group_1_voicec.wav" , 775 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_19_voicec.wav" , 1594 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_8_voicea.wav" , 57 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\mandown_group_1_voiced.wav" , 1279 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_9_voiceb.wav" , 1988 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_7_voiced.wav" , 365 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_c_2.wav" , 1720 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_group_4_voiceb.wav" , 1624 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_generic_a_5.wav" , 3478 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_b_1.wav" , 3373 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_5.wav" , 3258 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\silence2.wav" , 1 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_group_5_voicec.wav" , 2099 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_group_2_voicea.wav" , 865 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_6.wav" , 2272 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_9.wav" , 1053 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\helicopter_sight_2_voicec.wav" , 1205 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_8_voiced.wav" , 2261 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_a_2.wav" , 3543 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_group_3.wav" , 1509 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_8.wav" , 2758 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_14.wav" , 1794 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_1_voiced.wav" , 746 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_37_voicec.wav" , 2036 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_d_2.wav" , 2104 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_6_voiced.wav" , 145 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_3.wav" , 2106 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_alone_4_voiced.wav" , 148 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_alone_1_voiced.wav" , 370 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_4.wav" , 3654 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_h_1.wav" , 3180 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_11.wav" , 2354 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_10_voicea.wav" , 1462 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_16_voicea.wav" , 717 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_group_3_voiced.wav" , 1456 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_14.wav" , 2601 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_n_1.wav" , 3492 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_3_voicea.wav" , 1638 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_d_4.wav" , 2849 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_s1_a1.wav" , 3072 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_c_6.wav" , 3049 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_6.wav" , 2666 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_fear_6_voiced.wav" , 301 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\vehicle_in_1_voicec.wav" , 855 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_right_1_voicea.wav" , 308 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_group_1_voiceb.wav" , 895 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_5_voiced.wav" , 1410 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_c_3.wav" , 1881 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_3.wav" , 2230 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_11_voiced.wav" , 1087 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_9_voiceb.wav" , 1199 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_8_voiced.wav" , 254 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_e_1.wav" , 1662 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_1.wav" , 3337 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_4_voiced.wav" , 587 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_f_1bis_b.wav" , 3421 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_9.wav" , 2541 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_5_voicea.wav" , 26 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_16_voicea.wav" , 456 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_f3.wav" , 1901 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_12_voicec.wav" , 1300 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_27.wav" , 2358 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_group_4.wav" , 2183 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_b_2.wav" , 3692 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_12_voicec.wav" , 2180 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_3.wav" , 3383 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_13_voicea.wav" , 1334 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_a_1.wav" , 1746 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_d_1.wav" , 3615 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_left_3_voiced.wav" , 1133 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_e_5.wav" , 86 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_generic_a_6.wav" , 3577 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_8.wav" , 2877 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_a_2.wav" , 3558 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_k_3.wav" , 3162 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_h_1.wav" , 2753 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_e_5.wav" , 3068 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_c_2.wav" , 3053 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\mandown_alone_2_voiced.wav" , 1503 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_mutants_2_voicec.wav" , 2886 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_e_2.wav" , 3168 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_b_8.wav" , 2536 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_a_1.wav" , 2998 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_d_1x.wav" , 3606 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_8.wav" , 1848 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_2.wav" , 2807 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_10_voicea.wav" , 451 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_6.wav" , 2205 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_6_voiceb.wav" , 2450 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_13_voicec.wav" , 2516 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_alone_2_voiceb.wav" , 180 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_c_1.wav" , 3030 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_10_voiceb.wav" , 2110 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_4.wav" , 1428 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_7_voicea.wav" , 206 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alarm_group_2.wav" , 2414 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_fear_2_voicec.wav" , 192 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alarm_group_3_voiceb.wav" , 2300 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_3_alone_voiced.wav" , 469 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_1.wav" , 3226 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_19.wav" , 2894 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\comm_supress_1.wav" , 2597 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_group_1_voicec.wav" , 488 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_macho_7_voicea.wav" , 1318 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_2_voiceb.wav" , 1373 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_8.wav" , 1239 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_11_voiceb.wav" , 1452 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_macho_3_voiceb.wav" , 2697 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_group_2.wav" , 1694 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_20_voiced.wav" , 1857 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_8_voiceb.wav" , 899 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_9_voicec.wav" , 73 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_8.wav" , 2904 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_a_1.wav" , 2973 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_group_5_voiced.wav" , 1128 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_5_voiced.wav" , 2487 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_a_8.wav" , 2599 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_player_5_voiced.wav" , 2482 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_pickup_e_7.wav" , 617 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_9_voiced.wav" , 1898 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_16_voiced.wav" , 1451 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_6_voicea.wav" , 1245 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_5_voicea.wav" , 2093 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_c_3.wav" , 2844 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\grenade_1_voicea.wav" , 1335 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\darkness_5_voiceb.wav" , 687 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_5_voiced.wav" , 1522 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_a_2.wav" , 3238 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_12.wav" , 3227 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_7.wav" , 2617 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_a_3.wav" , 499 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_group_1_voicec.wav" , 1315 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_4.wav" , 479 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_alone_3_voiced.wav" , 1764 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_11.wav" , 3254 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\mandown_alone_1_voiced.wav" , 820 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alarm_group_1_voicea.wav" , 1681 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_3_voiceb.wav" , 809 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_5.wav" , 2537 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_g_3.wav" , 1495 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_suppress_1_voicec.wav" , 638 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alarm_alone_3_voiceb.wav" , 1820 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_2_voiced.wav" , 970 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_1_voiced.wav" , 921 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_player_6_voiceb.wav" , 2570 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_b_1.wav" , 3703 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_a_2.wav" , 3299 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_b_3.wav" , 803 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_15_voicea.wav" , 205 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_4_voiceb.wav" , 1378 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_3_voicea.wav" , 1135 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_10_voiceb.wav" , 1320 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_a_2.wav" , 3251 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_7_voiceb.wav" , 2424 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_12_voicec.wav" , 885 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_attention_1_voicea.wav" , 11 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_8.wav" , 23 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_a_2.wav" , 2267 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_g_3.wav" , 3198 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_a_3.wav" , 3533 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\helicopter_sight_8_voiced.wav" , 2266 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_6_voicea.wav" , 694 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_14_voicea.wav" , 462 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_10_voiced.wav" , 1995 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_3.wav" , 2652 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_6.wav" , 3638 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_c_7.wav" , 3186 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_5.wav" , 2596 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_generic_2r_voiced.wav" , 1014 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\mandown_group_1.wav" , 2445 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_e_3.wav" , 592 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_k_1.wav" , 3502 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8i.wav" , 18 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_9.wav" , 3248 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_17.wav" , 3046 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\vehicle_in_6_voicec.wav" , 1923 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_8.wav" , 2808 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_27_voiceb.wav" , 1933 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_f_6.wav" , 3680 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_9_voicea.wav" , 405 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_7.wav" , 2582 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_i_1.wav" , 2941 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_11_voicec.wav" , 161 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_1.wav" , 1546 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_4_voicea.wav" , 940 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_22.wav" , 876 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_6.wav" , 629 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_7.wav" , 2793 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_supress_2r_voicea.wav" , 1803 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_group_2_voicea.wav" , 1970 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_player_5_voicea.wav" , 2479 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_11_voiceb.wav" , 1080 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_8_voicea.wav" , 288 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_7.wav" , 3368 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_6_voicec.wav" , 476 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_group_5_voicea.wav" , 2335 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_g_1.wav" , 3420 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_retreat_1_voiced.wav" , 1167 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_generic_3_voiceb.wav" , 1467 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_40_voiced.wav" , 1832 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\helicopter_sight_6_voiced.wav" , 2564 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_20_voiceb.wav" , 1855 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_5_voiced.wav" , 2340 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_a_1.wav" , 1436 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_4.wav" , 449 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_e_4.wav" , 2468 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_37_voiceb.wav" , 1910 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_14_voiced.wav" , 1635 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_3_voiced.wav" , 560 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_newpickup_a_6.wav" , 2331 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_o_4.wav" , 2603 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\mandown_group_2.wav" , 2201 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_b_5.wav" , 2166 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_dune\\mp_dune_c3_a1.wav" , 2649 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_7_voiceb.wav" , 258 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_group_3_voiceb.wav" , 689 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_a_5.wav" , 3098 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_1_voiced.wav" , 1062 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_e_1.wav" , 3324 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\darkness_2_voicec.wav" , 1308 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_4.wav" , 2259 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_6_voiced.wav" , 711 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_f_3.wav" , 2637 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alarm_alone_4_voiced.wav" , 2355 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_18.wav" , 2079 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_4_voicea.wav" , 269 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_10_voicea.wav" , 1146 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_3_voiced.wav" , 2623 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_h_3.wav" , 2612 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_k_1.wav" , 3297 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_6.wav" , 1176 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_12_voiced.wav" , 1075 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_fear_4_voiced.wav" , 119 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_27_voicea.wav" , 1327 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_group_2_voiced.wav" , 1887 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_generic_3_voicea.wav" , 1090 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_alone_3.wav" , 2352 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_18_voicec.wav" , 1295 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_player_4_voiceb.wav" , 2835 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_12.wav" , 651 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_c_1.wav" , 2775 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_1_voicec.wav" , 702 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_c_4.wav" , 3369 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\vehicle_in_7_voicec.wav" , 554 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_22.wav" , 2945 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_15_voiceb.wav" , 298 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_12_voiced.wav" , 1039 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_10_voicea.wav" , 892 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_14_voicea.wav" , 1876 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_alone_2.wav" , 2084 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_b_1.wav" , 3330 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_h_6.wav" , 1363 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_d_1.wav" , 3601 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_group_3_voiced.wav" , 1518 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_3.wav" , 2598 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_h_3.wav" , 2731 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_left_2_voiced.wav" , 1216 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_c_6.wav" , 3630 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_11.wav" , 3039 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\vehicle_in_4_voicea.wav" , 602 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_al_6_voicea.wav" , 314 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_4.wav" , 2408 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_6_voicea.wav" , 2897 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_group_4_voiced.wav" , 2412 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_5.wav" , 637 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_g_1.wav" , 3228 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_18c.wav" , 2778 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_8.wav" , 2952 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_6.wav" , 1908 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_c_2.wav" , 2483 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_2.wav" , 2851 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\announce6.wav" , 2979 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_2.wav" , 2990 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_9.wav" , 1784 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_10_voiceb.wav" , 951 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_group_2.wav" , 1690 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_b_7.wav" , 3155 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_9.wav" , 1101 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_group_3_voicea.wav" , 1423 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_15.wav" , 443 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alarm_alone_3_voiced.wav" , 732 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_17_voicea.wav" , 943 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_group_5_voiceb.wav" , 796 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\helicopter_sight_2_voiced.wav" , 1206 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\flashbang_1_voiced.wav" , 445 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_al_5_voicea.wav" , 1235 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_pickup_c_2.wav" , 2847 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_5_voiced.wav" , 2161 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_3_voiced.wav" , 648 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_2_voicec.wav" , 860 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_b_1.wav" , 3500 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_fear_1_voicea.wav" , 122 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_3.wav" , 2173 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_45_voicec.wav" , 1773 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_15.wav" , 3519 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_a_4.wav" , 2868 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_talk_to_1_voicec.wav" , 2092 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_g_1.wav" , 3003 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_1_voicea.wav" , 362 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_al_8_voicea.wav" , 132 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_16.wav" , 781 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_9_voicec.wav" , 729 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_b_2.wav" , 3081 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_group_6.wav" , 1569 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_6_voiceb.wav" , 1481 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_13.wav" , 1757 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_f_1.wav" , 3647 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_mercs_a_1.wav" , 2749 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_5_voiceb.wav" , 1149 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\mandown_alone_2_voicea.wav" , 1276 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_f_7.wav" , 2560 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_alone_6_voicec.wav" , 408 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_1.wav" , 3498 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_c_4.wav" , 2144 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_attention_3_voiced.wav" , 282 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_g_4.wav" , 3144 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_1.wav" , 2159 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_i_4.wav" , 1754 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_group_6_voiced.wav" , 1645 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_7.wav" , 226 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_11_voicea.wav" , 548 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_generic_1r_voiced.wav" , 581 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_retreat_2r_voiced.wav" , 1152 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickujp_a_15.wav" , 3612 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_5.wav" , 2148 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_6.wav" , 3171 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_m_10.wav" , 3429 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_8.wav" , 3634 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_7_voicea.wav" , 202 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_group_2_voiced.wav" , 2187 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\darkness_1_voicea.wav" , 1668 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_h_5.wav" , 2863 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_retreat_1_voicea.wav" , 2554 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_16.wav" , 62 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_12_voicea.wav" , 1386 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_2_voicea.wav" , 1125 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_7b.wav" , 3592 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_f_1.wav" , 3055 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_supress_2_voicea.wav" , 1804 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_7.wav" , 3054 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_6_voiceb.wav" , 1693 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_m_1.wav" , 3370 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_generic_2_voiced.wav" , 1015 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_2.wav" , 142 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_group_5_voicec.wav" , 472 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_13_voicea.wav" , 315 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_18_voiced.wav" , 988 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_b_1.wav" , 2773 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_1_voicea.wav" , 540 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\jack_2.wav" , 3121 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_b_3.wav" , 2977 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_k_6.wav" , 2842 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alarm_alone_2_voicec.wav" , 1307 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_11.wav" , 3669 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_advance_left_3_voiced.wav" , 1889 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_b_7.wav" , 3106 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_6_1.wav" , 696 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_3.wav" , 1671 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\mandown_group_3_voicea.wav" , 1119 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_1.wav" , 3137 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_14_voicea.wav" , 1766 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_left_2r_voicea.wav" , 794 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_2_voicea.wav" , 938 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_alone_3_voiced.wav" , 1172 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_a_1.wav" , 2043 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\downed_pilot.wav" , 3613 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_14.wav" , 108 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_go_get_5_voicea.wav" , 1863 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_1.wav" , 1226 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_3.wav" , 3261 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_20.wav" , 518 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_5.wav" , 3287 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\grenade_1_voiced.wav" , 1564 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_3_voicec.wav" , 1313 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_4_voicec.wav" , 36 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_1.wav" , 2650 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_g_2.wav" , 1356 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_7_voicea.wav" , 1055 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_group_2.wav" , 1676 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_al_1_voicea.wav" , 425 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_9_voicec.wav" , 688 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_2.wav" , 3668 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_5.wav" , 1491 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_b_1.wav" , 1960 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_15.wav" , 2443 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_4.wav" , 2715 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_2_voicea.wav" , 1233 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_i_5.wav" , 2830 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_mutants_1_voiceb.wav" , 2254 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_3_voicec.wav" , 973 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_h_1.wav" , 3279 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_newpickup_a_1.wav" , 2975 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_d_2.wav" , 3437 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_12_voiced.wav" , 1685 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_9.wav" , 60 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_c_7.wav" , 1874 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_14_voiced.wav" , 1591 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_4_voicea.wav" , 2404 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_a_3.wav" , 3556 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_1_voiced.wav" , 703 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_40_voiceb.wav" , 2053 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_7.wav" , 2684 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_4.wav" , 3471 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alarm_group_1_voiceb.wav" , 1500 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_2_alert_seen_group_3.wav" , 2397 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_group_2_voiceb.wav" , 532 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_2_group_voiceb.wav" , 1359 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_15_voicec.wav" , 2647 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_16_voiceb.wav" , 999 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_6.wav" , 1398 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_10_voiceb.wav" , 936 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_12.wav" , 2848 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_9_voicec.wav" , 1333 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_3.wav" , 2067 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_suppress_5_voiceb.wav" , 1819 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_a_7.wav" , 2439 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_group_3_voiceb.wav" , 1234 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_group_4_voiced.wav" , 1478 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_go_get_1_voiced.wav" , 1169 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_d_2.wav" , 2686 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_11.wav" , 1406 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\vehicle_in_7_voicea.wav" , 131 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_f_2.wav" , 2791 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_16_voicec.wav" , 790 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_a_1.wav" , 3223 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_6_voiceb.wav" , 1904 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_3_voiceb.wav" , 1581 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_5_voicec.wav" , 514 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_13_voicea.wav" , 32 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_39_voiceb.wav" , 1885 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_14_voiceb.wav" , 801 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_a_5.wav" , 2430 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_7.wav" , 3221 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_attention_2_voiced.wav" , 126 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_talk_to_3_voiceb.wav" , 2390 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_i_4.wav" , 2370 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_group_4_voicea.wav" , 952 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_a_2.wav" , 2944 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_al_2_voicea.wav" , 1302 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_33_voicec.wav" , 812 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_7.wav" , 2341 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_group_1_voicea.wav" , 311 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_1_voicea.wav" , 1225 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_al_6_voicea.wav" , 828 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_alone_3_voicea.wav" , 262 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_10_voiced.wav" , 845 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_1_voicec.wav" , 497 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_left_3_voicea.wav" , 616 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_e_4.wav" , 3070 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alone_spit_1_voicea.wav" , 51 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_14_voicec.wav" , 1273 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_e_2.wav" , 3102 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_2.wav" , 2695 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8.wav" , 2752 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_e_6.wav" , 2428 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_3.wav" , 2706 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_b_6.wav" , 2373 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_seen_gp_1_voicea.wav" , 1061 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\mandown_group_2_voiced.wav" , 1571 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_5_voicec.wav" , 1814 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_c_4.wav" , 1558 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_4_voicea.wav" , 475 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\flashbang_2_voicec.wav" , 902 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_1.wav" , 3396 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_c_2.wav" , 2771 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_a_1.wav" , 3694 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\mandown_group_4_voiced.wav" , 830 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_16_voicea.wav" , 1837 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_g_2.wav" , 2776 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alarm_group_1.wav" , 2337 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_k_1.wav" , 3283 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_1.wav" , 3627 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_7.wav" , 3493 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_f_5.wav" , 2780 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\receive_fire_group_4.wav" , 2273 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_7_voiced.wav" , 1948 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_4_voicea.wav" , 1355 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_1_voiced.wav" , 1540 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_17.wav" , 735 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_5_voicec.wav" , 1616 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_8.wav" , 2277 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_airstrip\\mp_airstrip_s1_a1.wav" , 3540 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_e_3.wav" , 2642 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_9.wav" , 2766 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_2_voiced.wav" , 396 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_7.wav" , 1343 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_e_3.wav" , 3156 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\comm_retreat_1.wav" , 2167 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_go_get_3_voiced.wav" , 2566 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_pickup_b_1.wav" , 1511 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_b_1.wav" , 1554 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_f_1.wav" , 3697 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_32_voicea.wav" , 2152 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_4_alone_voicec.wav" , 770 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_flank_left_1_voiceb.wav" , 678 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\mandown_group_2_voiceb.wav" , 1141 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_11.wav" , 762 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_1_voicec.wav" , 807 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_alone_1.wav" , 2556 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_9.wav" , 220 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_gp_2_voicea.wav" , 586 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_19.wav" , 1854 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_e_1.wav" , 3249 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_a_1.wav" , 3684 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_10_voicea.wav" , 1818 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_9_voicec.wav" , 436 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_f_1.wav" , 2553 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_suppress_4_voiced.wav" , 1743 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_f_3.wav" , 2875 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_e_1.wav" , 3579 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_2_voiceb.wav" , 374 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_3.wav" , 2912 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_c_1bis.wav" , 2817 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_11_voiced.wav" , 350 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_left_3r_voiced.wav" , 1132 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_e_6.wav" , 2903 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_b_5.wav" , 3321 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_13_voiced.wav" , 280 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_a_2bi.wav" , 1286 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_13.wav" , 3548 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_3.wav" , 2704 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_alone_6_voicea.wav" , 204 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_38_voiced.wav" , 2709 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_4.wav" , 3414 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_2_voicec.wav" , 289 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_generic_1_voiceb.wav" , 683 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_19.wav" , 2510 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_6_voicea.wav" , 2083 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_2.wav" , 2438 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_d_5.wav" , 1576 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_go_get_2_voicec.wav" , 1912 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_a_4.wav" , 1735 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\doyle_1.wav" , 3563 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\flashbang_2_voiced.wav" , 1018 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_14.wav" , 1627 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_4_voiced.wav" , 594 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_8_voicec.wav" , 184 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_d_1.wav" , 3242 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_retreat_3r_voicea.wav" , 477 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_9_voicec.wav" , 1524 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_1_voicea.wav" , 960 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_g_3.wav" , 3487 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_c_1.wav" , 3377 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_c_3.wav" , 3345 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_4_group_voiced.wav" , 819 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_8_voiced.wav" , 332 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_11_voiceb.wav" , 356 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_5.wav" , 1628 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_a_1.wav" , 3012 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_rush_1_voiceb.wav" , 2239 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\mandown_alone_3_voicec.wav" , 567 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_11_voicec.wav" , 1165 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_4_voiced.wav" , 1345 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_20_voiceb.wav" , 215 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_al_1_voicea.wav" , 1012 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_group_3.wav" , 2292 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\mandown_group_3_voiced.wav" , 1847 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_b_3.wav" , 2707 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_7.wav" , 1646 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_group_3_voicea.wav" , 677 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_b_4.wav" , 1937 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_18_voicea.wav" , 67 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_generic_3_voiced.wav" , 1469 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_3_voiced.wav" , 465 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_pickup_d_1.wav" , 1164 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_5_alone_voicea.wav" , 1648 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_11_voicea.wav" , 1365 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_tell_get_5_voicea.wav" , 1494 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\helicopter_sight_5_voicec.wav" , 2589 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\flashbang_3_voicea.wav" , 1280 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\inbound.wav" , 3301 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_6_voiced.wav" , 1849 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_flank_left_3_voicec.wav" , 566 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_attention_3_voicea.wav" , 20 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_1.wav" , 2978 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_3_voicea.wav" , 1761 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_17.wav" , 71 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\seek_target_a2.wav" , 1834 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_6.wav" , 2950 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\helicopter_sight_5_voicea.wav" , 2587 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_d_2.wav" , 2765 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_15_voiceb.wav" , 1194 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_14_voiceb.wav" , 2313 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_2_voiceb.wav" , 859 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_19_voiceb.wav" , 2021 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\darkness_3_voicea.wav" , 1447 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_d_1.wav" , 3504 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_10_voiced.wav" , 12 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_5_voicea.wav" , 698 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_10_voiced.wav" , 626 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\darkness_2_voicea.wav" , 1338 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_freighter\\mp_freighter_s1_d1.wav" , 3112 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_b_1.wav" , 3591 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_retreat_3_voicea.wav" , 478 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_21.wav" , 772 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_g_6.wav" , 2549 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\mandown_group_3_voicea.wav" , 1444 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_group_5_voicea.wav" , 373 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_d_2.wav" , 2422 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_4_voiced.wav" , 1461 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_3.wav" , 2514 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_group_1_voiced.wav" , 572 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_16_voiced.wav" , 1299 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\silence3.wav" , 2 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_5_voiced.wav" , 561 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\grenade_4.wav" , 1706 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_f1.wav" , 3642 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_2.wav" , 3508 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\vehicle_in_5_voicec.wav" , 733 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_left_3r_voicea.wav" , 615 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\vehicle_in_1_voicea.wav" , 250 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_d_2.wav" , 2825 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_p_6.wav" , 3092 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_4_voiceb.wav" , 440 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_5_voicec.wav" , 1002 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_6_voicec.wav" , 261 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_12_voicea.wav" , 2020 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_17_voiced.wav" , 2060 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\flashbang_5_voiceb.wav" , 1579 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_talk_to_2_voicea.wav" , 1213 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_2.wav" , 1692 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_d_4.wav" , 2081 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_generic_4_voiced.wav" , 1812 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_3_voicea.wav" , 1255 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_4_voiced.wav" , 371 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_alone_8_voicea.wav" , 15 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_10.wav" , 2804 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_2.wav" , 2268 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_right_3_voicea.wav" , 731 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_6_voiceb.wav" , 486 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_f_3.wav" , 3350 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_c_3.wav" , 534 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_12.wav" , 2958 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_20.wav" , 2818 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_b_5.wav" , 3312 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_3_voicec.wav" , 294 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_4_voiced.wav" , 2062 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_a_6.wav" , 3031 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\flashlight_face_1_voicea.wav" , 1612 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_2_voiced.wav" , 218 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_rush_2_voiceb.wav" , 1074 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_29_voiceb.wav" , 2240 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alarm_alone_2_voicea.wav" , 1006 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_advance_right_2_voicea.wav" , 1260 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_seen_group_2_voiced.wav" , 676 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_b_2.wav" , 2394 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_2.wav" , 2809 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_17.wav" , 1736 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_b_1.wav" , 2032 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_go_get_2_voiceb.wav" , 2215 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_c_6.wav" , 3041 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_8.wav" , 2936 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_9_voiceb.wav" , 1305 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_15_voicea.wav" , 644 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_8_voicec.wav" , 2260 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_3_alone_voicea.wav" , 296 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_33_voicea.wav" , 603 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_supress_2r_voiced.wav" , 2068 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_d_1.wav" , 1623 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_30_voicec.wav" , 1548 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_lake\\mp_lake_s1_a1.wav" , 3419 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_10.wav" , 1306 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_e_2.wav" , 3382 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_3.wav" , 1829 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\vehicle_in_4_voicec.wav" , 1001 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_flank_right_2_voicec.wav" , 840 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_1_voicea.wav" , 27 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_11_voicea.wav" , 33 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_7_voicea.wav" , 225 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_a_1.wav" , 2961 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_15_voicec.wav" , 2605 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_6.wav" , 2218 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_a_2bis.wav" , 2754 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alarm_group_3.wav" , 2636 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_attention_3.wav" , 1602 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_12_voiceb.wav" , 583 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_3.wav" , 1534 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_24_voiced.wav" , 2743 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_8.wav" , 2489 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_h_5.wav" , 2892 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_right_1r_voicea.wav" , 307 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_9_voiced.wav" , 173 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_alone_4_voicea.wav" , 1946 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_group_2_voiced.wav" , 769 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_43_voicea.wav" , 1973 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_20_voiced.wav" , 1475 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_group_1_voiced.wav" , 389 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_specific_a_6.wav" , 3557 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_c_2.wav" , 2799 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alarm_alone_4.wav" , 1271 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_fear_1_voiced.wav" , 65 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_15_voiced.wav" , 646 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_b_2.wav" , 3263 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_e_1.wav" , 2879 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_2.wav" , 2372 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\grenade_4_voiced.wav" , 767 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_20_voicea.wav" , 1578 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_group_3_voicec.wav" , 1982 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_7_voicec.wav" , 68 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\helicopter_sight_7_voicec.wav" , 2915 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_talk_to_4_voiceb.wav" , 1387 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_c_2.wav" , 2693 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_jungle\\mp_jungle_c2_d1.wav" , 2909 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_25.wav" , 249 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_18.wav" , 69 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_4.wav" , 183 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_8_voicec.wav" , 246 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_seen_gp_3_voicea.wav" , 1105 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\mandown_group_4_voicea.wav" , 831 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_10.wav" , 774 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_6.wav" , 2841 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_group_2_voicea.wav" , 580 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_5_voicea.wav" , 93 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_a_1.wav" , 3702 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_16.wav" , 2655 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_h_2.wav" , 2644 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_g_6.wav" , 3526 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\krieger\\krieger_specific_1.wav" , 3701 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alarm_group_2_voicec.wav" , 1482 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\mandown_group_3.wav" , 2533 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_15.wav" , 82 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_3.wav" , 2993 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_group_6_voicea.wav" , 969 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_d_3.wav" , 3149 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_2_voiceb.wav" , 135 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_mercs_a_6.wav" , 3418 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_5_voicea.wav" , 2559 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_4.wav" , 2839 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\mandown_group_4_voicea.wav" , 450 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_i_2.wav" , 2513 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_talk_to_5_voiceb.wav" , 1760 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_9_voiced.wav" , 1824 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_group_4_voicec.wav" , 2248 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_b_4.wav" , 1605 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\flashbang_1_voicec.wav" , 771 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_7_voiceb.wav" , 1859 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_go_get_4_voicea.wav" , 1999 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_advance_left_3_voicea.wav" , 1929 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_f_1.wav" , 2616 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_12.wav" , 1120 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\flashbang_2_voicea.wav" , 1003 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_mutants_4_voicea.wav" , 2174 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_pickup_c_1.wav" , 3436 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_6_voiced.wav" , 1719 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_newpickup_a_1.wav" , 3300 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_k_1.wav" , 2416 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_d_2.wav" , 2204 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_alone_2_voiced.wav" , 61 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_d_4.wav" , 764 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_a_6.wav" , 2429 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\vehicle_in_4_voiceb.wav" , 1489 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_generic_6_voicea.wav" , 1914 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_g_4.wav" , 2859 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_9_voicea.wav" , 1156 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_5_voicea.wav" , 743 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_c_1.wav" , 3686 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_11.wav" , 864 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_1_voiceb.wav" , 85 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_group_5_voicea.wav" , 822 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_al_5_voicea.wav" , 632 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_10_voiced.wav" , 468 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_5_voiced.wav" , 926 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_c_3.wav" , 3109 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_i_3.wav" , 3590 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_c_2.wav" , 1781 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_7_voiced.wav" , 2876 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_6.wav" , 368 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_1_voiced.wav" , 1512 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_e_4.wav" , 791 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_fear_7_voicea.wav" , 489 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_talk_to_5_voicea.wav" , 1127 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_group_3_voicec.wav" , 756 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_fear_5_voicec.wav" , 291 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_group_2_voicec.wav" , 1664 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_18_voiceb.wav" , 1052 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_4_voicec.wav" , 758 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_d_1.wav" , 2527 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_gp_3_voicea.wav" , 326 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_9_voicea.wav" , 650 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_5_voicea.wav" , 1180 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_4_voiceb.wav" , 624 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_3.wav" , 1342 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_e_1.wav" , 3083 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_d_1.wav" , 3208 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_b_3.wav" , 509 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_c_2.wav" , 3442 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_5_voiceb.wav" , 1919 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_flank_left_1_voiced.wav" , 848 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_flank_right_2_voicea.wav" , 578 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_1_voiced.wav" , 1642 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_13_voiced.wav" , 1290 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_5.wav" , 2019 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_seen_gp_3_voiced.wav" , 1319 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_1.wav" , 1376 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_12_voiceb.wav" , 1000 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_b_6.wav" , 3447 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_1_voiced.wav" , 562 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_5_voicea.wav" , 976 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_advance_right_1_voiceb.wav" , 954 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_flank_left_3_voicea.wav" , 504 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_a_5.wav" , 2694 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_8_voiceb.wav" , 418 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_31_voiced.wav" , 2247 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_generic_2_voicea.wav" , 1040 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_c_2.wav" , 2003 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_g_4.wav" , 3404 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_group_3_voicea.wav" , 913 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_n_3.wav" , 3366 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_player_2_voiceb.wav" , 1991 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_fear_4_voicec.wav" , 118 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_d_3.wav" , 3236 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_27_voicec.wav" , 2498 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_fear_4_voiceb.wav" , 117 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_10_voiced.wav" , 1679 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_3.wav" , 1655 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_9.wav" , 3304 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_f_4.wav" , 3416 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_h_2.wav" , 1918 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_1_voicea.wav" , 1178 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_44_voiceb.wav" , 1797 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\mandown_alone_2_voiced.wav" , 1414 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_c_7.wav" , 3453 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_2_alone_voicec.wav" , 266 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_c_1.wav" , 3430 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_19_voiceb.wav" , 1593 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_advance_left_2_voicec.wav" , 1218 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_15.wav" , 2319 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_f5.wav" , 3581 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_a_3.wav" , 2710 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_flank_right_1_voicec.wav" , 355 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_i_5.wav" , 3628 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_g_4.wav" , 367 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\following_player_a2.wav" , 1986 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_e_1.wav" , 2828 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_group_5_voiceb.wav" , 2309 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\go_to_waypoint_a3.wav" , 1129 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_generic_a_4.wav" , 3331 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_m_7.wav" , 2943 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alarm_alone_5_voiced.wav" , 277 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_22_voiced.wav" , 1739 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_f_2.wav" , 3152 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_8.wav" , 3176 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_h_2.wav" , 1972 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_6.wav" , 543 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_11_voiceb.wav" , 564 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_2.wav" , 1592 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_e_3.wav" , 2898 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_right_3_voiced.wav" , 942 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_8_voicea.wav" , 111 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_1.wav" , 1813 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_macho_8_voicea.wav" , 1432 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_4.wav" , 2007 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_16_voicea.wav" , 2207 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_a_6.wav" , 2493 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_14.wav" , 1140 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\following_player_a3.wav" , 1037 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_7_voicec.wav" , 1077 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_e_1.wav" , 3127 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\_training_pickup_a_3.wav" , 2297 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_left_2r_voiced.wav" , 1215 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\helicopter_sight_1_voicec.wav" , 1242 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_b_1.wav" , 2889 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_9_voiced.wav" , 1048 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_1_voiced.wav" , 596 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_macho_6_voiced.wav" , 2227 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_19.wav" , 3664 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_20_voicec.wav" , 38 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_6.wav" , 2398 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c3_a1.wav" , 2074 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_11_voicec.wav" , 244 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_3_voiced.wav" , 1220 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_generic_7_voiced.wav" , 621 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_32_voicec.wav" , 2186 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_mutants_1_voicec.wav" , 2255 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_10_voiceb.wav" , 923 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_10_voicea.wav" , 1424 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_suppress_5_voicec.wav" , 1557 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_16_voiceb.wav" , 1882 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_32_voiceb.wav" , 1984 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_b_1.wav" , 2646 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier7.wav" , 3040 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_1.wav" , 2385 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_3.wav" , 3235 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_n_2.wav" , 2661 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_4.wav" , 585 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alarm_alone_2.wav" , 2466 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_3_voiceb.wav" , 1144 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_g_1.wav" , 3209 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_d_1j.wav" , 3439 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\radio_fx_out.wav" , 10 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_j_2.wav" , 3025 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alarm_alone_1_voicea.wav" , 387 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_a_2.wav" , 3188 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_generic_5_voiced.wav" , 911 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_flank_right_3_voicec.wav" , 519 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_45_voiceb.wav" , 1752 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_n_1.wav" , 2953 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alarm_alone_3_voicea.wav" , 1391 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_b_1.wav" , 1510 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_6_voiceb.wav" , 1717 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_d_1bis.wav" , 2920 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_group_2.wav" , 1858 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_3_voiceb.wav" , 74 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_16.wav" , 116 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_alone_1.wav" , 2407 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8a.wav" , 1265 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_group_4_voicea.wav" , 1282 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\flashbang_3_voicec.wav" , 1145 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_g_3.wav" , 3693 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_20.wav" , 153 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_13_voiced.wav" , 667 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_group_7_voicea.wav" , 236 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_suppress_4_voicec.wav" , 722 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_i_1.wav" , 3125 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_6_voicec.wav" , 157 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_suppress_6_voicea.wav" , 1388 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_1.wav" , 814 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_6_voicec.wav" , 1344 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_b_1.wav" , 3184 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_group_3.wav" , 2222 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_b_4.wav" , 3367 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_10.wav" , 421 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_6.wav" , 238 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_11_voiced.wav" , 1445 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_a_4.wav" , 2147 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_11_voicec.wav" , 1324 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_14.wav" , 2054 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_42_voicea.wav" , 2371 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_b_2.wav" , 2673 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_group_3_voicea.wav" , 659 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_36_voiced.wav" , 2501 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_b_2.wav" , 3454 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_5_voiceb.wav" , 1940 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\helicopter_sight_7_voiceb.wav" , 2914 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_seen_group_1_voicec.wav" , 584 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_9.wav" , 1689 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_player_2_voiced.wav" , 1994 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_player_1_voicea.wav" , 2472 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_e_4.wav" , 3597 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_c_2.wav" , 3356 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_5_alone_voicec.wav" , 1415 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_al_2_voicea.wav" , 361 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_10_voicec.wav" , 77 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_a_2.wav" , 2870 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_a_1bi.wav" , 579 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_4.wav" , 3537 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\mandown_alone_1_voicea.wav" , 1024 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_2.wav" , 2295 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_b_2.wav" , 2061 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_go_get_2_voiced.wav" , 2195 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_5_voicea.wav" , 604 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_3_alone_voicec.wav" , 547 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_6.wav" , 3191 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alarm_alone_1_voiced.wav" , 595 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\researcha_specific_a_1.wav" , 3219 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_8_voicec.wav" , 347 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_h_1.wav" , 3288 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_attention_3_voiceb.wav" , 188 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_g_5.wav" , 2908 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_4_voiced.wav" , 1380 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\flashbang_3_voiced.wav" , 1111 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_dune\\mp_dune_c1_d1.wav" , 3169 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_9.wav" , 2969 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_g_4.wav" , 2465 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_3.wav" , 2576 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_flank_right_3_voicea.wav" , 574 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_d_2bis.wav" , 2199 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_6_voicea.wav" , 1200 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_g_1.wav" , 3662 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_4.wav" , 1634 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_attention_1_voicec.wav" , 1759 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_4_alone_voiced.wav" , 918 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_generic_1_voicec.wav" , 684 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_7_voiced.wav" , 1936 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_c_5.wav" , 3431 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_attention_3_voicea.wav" , 611 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_11_voiceb.wav" , 455 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_i_7.wav" , 3446 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_b_3.wav" , 2034 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_9_voiced.wav" , 1121 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_a_6.wav" , 3622 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\doyle_11.wav" , 3643 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_macho_3_voicec.wav" , 2698 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_2_voiced.wav" , 1275 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_9.wav" , 2796 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_3.wav" , 3077 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_f_4.wav" , 1793 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\mandown_alone_3_voiced.wav" , 785 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_7.wav" , 2688 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_15_voiced.wav" , 2232 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_11.wav" , 2171 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alarm_alone_5_voicec.wav" , 375 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_5.wav" , 2440 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\vehicle_in_7_voiced.wav" , 221 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_e_2.wav" , 2476 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_fear_8_voicea.wav" , 1230 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_a_3.wav" , 3467 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_d_1.wav" , 3690 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_a_3.wav" , 3384 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\mandown_group_3_voiceb.wav" , 747 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_d_1.wav" , 862 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_4_voiced.wav" , 1560 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_group_2_voicea.wav" , 295 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_c_5.wav" , 2751 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_16_voiceb.wav" , 2523 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_4_voicea.wav" , 1402 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_go_get_1_voicea.wav" , 805 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_18_voiceb.wav" , 1294 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_10.wav" , 2783 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_2_voicea.wav" , 589 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_b_1.wav" , 2681 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_advance_right_3_voicec.wav" , 1348 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_6.wav" , 438 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_i_2.wav" , 141 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_c_1j.wav" , 2568 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_3.wav" , 2509 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alarm_alone_2_voiced.wav" , 1323 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_a_2.wav" , 3506 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_flank_right_1_voicea.wav" , 407 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_2_voiced.wav" , 1527 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_7.wav" , 3650 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_e_2.wav" , 2442 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_3_voicec.wav" , 1431 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_group_2_voicec.wav" , 458 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_attention_2_voicea.wav" , 172 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_f_4.wav" , 1828 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_p_7.wav" , 2899 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_6.wav" , 3582 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_10_voiceb.wav" , 230 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_14.wav" , 608 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_d_1.wav" , 2624 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_gp_3_voicea.wav" , 662 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_9.wav" , 3015 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_j_1.wav" , 2717 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_12.wav" , 2006 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_10_voiced.wav" , 1393 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_8.wav" , 2545 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\receive_fire_group_3.wav" , 1971 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_2_voiced.wav" , 182 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_alone_6_voiced.wav" , 725 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_go_get_3_voiced.wav" , 2298 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_alone_4_voiceb.wav" , 196 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_9.wav" , 2366 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_go_get_1_voicec.wav" , 834 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_29_voicec.wav" , 2075 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_i_2.wav" , 1722 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_19_voiced.wav" , 120 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_macho_2_voicea.wav" , 3314 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_10_voiceb.wav" , 1171 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_mutants_3_voiceb.wav" , 2046 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_2_voicec.wav" , 2379 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_14_voiced.wav" , 2315 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_6_voiceb.wav" , 2279 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_18_voicec.wav" , 2086 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alarm_alone_3_voicec.wav" , 1682 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\helicopter_sight_3_voicec.wav" , 2594 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_a_3.wav" , 2306 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_alone_8_voiced.wav" , 39 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_1_voiced.wav" , 113 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_6_voicea.wav" , 2028 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_mutants_6_voicea.wav" , 2502 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_6_voiced.wav" , 379 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_17_voicec.wav" , 2059 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_10.wav" , 2127 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_go_get_3_voicec.wav" , 2447 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_1_voicec.wav" , 351 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_12.wav" , 3358 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_8.wav" , 414 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_a_4.wav" , 3480 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_12_voicec.wav" , 832 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_group_6_voiced.wav" , 1367 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_8.wav" , 2121 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_tell_get_1_voicea.wav" , 377 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_group_3_voiced.wav" , 1004 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_10_voicec.wav" , 1459 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\darkness_4_voicea.wav" , 1515 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_f_1.wav" , 2785 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_e_5.wav" , 2669 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_1_voicea.wav" , 176 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_5.wav" , 3307 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_c_1.wav" , 3166 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_2_voiced.wav" , 1525 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_2.wav" , 2526 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_e_2.wav" , 3444 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_10_voicec.wav" , 276 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_talk_to_3_voicea.wav" , 2511 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8g.wav" , 8 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\mandown_alone_3_voicea.wav" , 481 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_dune\\mp_dune_c2_a1.wav" , 3332 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_13.wav" , 3599 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_a_2.wav" , 3023 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_11.wav" , 1730 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_13.wav" , 1158 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_29_voicea.wav" , 2241 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_1.wav" , 1741 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\val typing.wav" , 3059 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_group_3_voicec.wav" , 522 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_1.wav" , 2728 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_1.wav" , 3614 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_macho_7_voiced.wav" , 1653 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_15.wav" , 2862 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_1.wav" , 2611 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_macho_8_voiced.wav" , 2632 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_b_5.wav" , 2910 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_1.wav" , 2287 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_1.wav" , 3088 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_al_1_voicea.wav" , 975 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\glass.wav" , 2547 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_c_1.wav" , 641 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_b_5.wav" , 2620 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_2.wav" , 2035 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_18_voicea.wav" , 985 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_group_5_voicec.wav" , 376 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_3_alone_voiceb.wav" , 1038 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_11.wav" , 573 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_b_2.wav" , 3082 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_c_4.wav" , 3433 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_group_3_voiceb.wav" , 2334 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_1.wav" , 2937 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_1_voicea.wav" , 1274 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_g_7.wav" , 1007 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_al_3_voicea.wav" , 992 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_talk_to_1_voicea.wav" , 2294 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_10.wav" , 2739 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_3_voiced.wav" , 1429 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_n_3.wav" , 3255 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_8_voiceb.wav" , 2102 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_n_3.wav" , 2865 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_8_voicea.wav" , 304 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_a_1.wav" , 3218 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alarm_alone_5_voicea.wav" , 557 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_8_voiced.wav" , 2126 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_9_voicec.wav" , 515 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_13_voiceb.wav" , 1093 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_1_voicea.wav" , 495 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_2.wav" , 716 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_macho_4_voicea.wav" , 1945 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_group_1_voiced.wav" , 660 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_generic_3_voicea.wav" , 1466 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_8_voicec.wav" , 186 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_3.wav" , 2867 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_5.wav" , 2280 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_9_voiceb.wav" , 1608 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_c_1.wav" , 1891 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_8_voiced.wav" , 2322 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_1.wav" , 2900 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_group_2_voiced.wav" , 535 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_6_voicec.wav" , 569 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\grenade_2.wav" , 1745 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_jungle\\mp_jungle_c1_a1.wav" , 3392 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_11_voiced.wav" , 257 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_19_voiced.wav" , 2133 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_10.wav" , 2902 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_b_4.wav" , 2925 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_34_voiced.wav" , 1779 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\flashbang_6_voicec.wav" , 1684 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_6_voicea.wav" , 2065 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\grenade_2_voiced.wav" , 1310 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_4_voiced.wav" , 994 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_2_voicea.wav" , 21 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_17_voicec.wav" , 1411 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_left_1r_voicea.wav" , 409 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_e_3.wav" , 3587 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_d_1.wav" , 3464 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_10_voiceb.wav" , 1737 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_al_4_voicea.wav" , 866 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_group_1_voiceb.wav" , 869 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_alone_7_voiceb.wav" , 1368 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_advance_right_2_voicec.wav" , 1212 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_d_1.wav" , 3351 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_11.wav" , 3553 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_alone_4_voiced.wav" , 2381 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_talk_to_4_voicec.wav" , 1460 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_5.wav" , 3076 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_8_voiceb.wav" , 2022 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_generic_4_voiceb.wav" , 1810 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_6.wav" , 3347 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_7.wav" , 3422 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_5.wav" , 1895 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_h_3.wav" , 3663 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_8.wav" , 3499 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_1.wav" , 2779 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\go_to_waypoint_a2.wav" , 891 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_4_voiced.wav" , 1025 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_b_3.wav" , 2662 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_al_2_voicea.wav" , 1147 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_b_5.wav" , 3060 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_suppress_3_voicec.wav" , 919 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_macho_3_voiced.wav" , 1877 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_f_2.wav" , 3512 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_3.wav" , 1103 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_8.wav" , 3361 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_2.wav" , 267 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_b_2.wav" , 2871 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_alone_4.wav" , 2363 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_fear_5_voicea.wav" , 45 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_3.wav" , 2738 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_k_2.wav" , 2522 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\grenade_3_voicea.wav" , 490 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_2.wav" , 3282 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_3_voicea.wav" , 1533 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_f_1.wav" , 3655 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_e_3.wav" , 3346 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_group_1_voicea.wav" , 432 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\darkness_3_voicea.wav" , 1538 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_newpickup_a_3.wav" , 3359 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_21.wav" , 1846 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_3.wav" , 1672 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_h_1.wav" , 2548 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_4_voiced.wav" , 2109 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_a_2.wav" , 2940 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_suppress_3_voiceb.wav" , 1192 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c2_d1.wav" , 3503 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_9_voicea.wav" , 467 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_group_2_voicec.wav" , 693 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_i_3.wav" , 3240 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_8a.wav" , 3153 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_g_1.wav" , 3426 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_5_voiced.wav" , 1309 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_rush_1_voiced.wav" , 2304 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_fear_3_voicec.wav" , 79 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_c_4.wav" , 3002 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\mandown_group_3_voicec.wav" , 1079 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_6_voiced.wav" , 344 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_2.wav" , 2420 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_18_voicea.wav" , 1755 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_attention_2.wav" , 1611 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_f_2.wav" , 3485 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_5.wav" , 2082 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_10_voicea.wav" , 507 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_d_8.wav" , 2506 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_4.wav" , 208 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_b_6.wav" , 3323 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_6.wav" , 2008 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_2_voiced.wav" , 1211 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_1_voicea.wav" , 1131 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_dune\\mp_dune_c2_d1.wav" , 3335 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\darkness_4_voiced.wav" , 2271 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_group_1.wav" , 1691 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_3.wav" , 2274 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reloaded_2_voiced.wav" , 1747 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_c_1.wav" , 3711 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_f_1.wav" , 2575 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_14_voiced.wav" , 285 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_a_2.wav" , 1711 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_8_voicea.wav" , 1497 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c1_a1.wav" , 3532 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_group_3_voiced.wav" , 485 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_10_voiced.wav" , 2112 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_k_5.wav" , 2346 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_a_1.wav" , 3649 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_b_2.wav" , 275 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_1_voicea.wav" , 333 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_7.wav" , 2981 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\flashlight_face_4_voicea.wav" , 2353 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_c_5.wav" , 2726 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_h_3.wav" , 3052 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_4b.wav" , 3020 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_7.wav" , 2426 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\darkness_4_voicec.wav" , 1673 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_fear_1_voicec.wav" , 2136 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_suppress_6_voicec.wav" , 971 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_h_4.wav" , 470 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_al_5_voicea.wav" , 354 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_4.wav" , 2630 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\helicopter_sight_7_voiced.wav" , 2916 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_5.wav" , 1441 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_2_voicea.wav" , 140 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\following_player_a1.wav" , 1765 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\krieger\\krieger_specific_2.wav" , 3689 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c2_a1.wav" , 2963 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_16_voicec.wav" , 2168 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_tell_get_4_voicea.wav" , 471 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_left_1_voicea.wav" , 410 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_group_6_voicea.wav" , 1902 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_1.wav" , 1223 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier1.wav" , 3140 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\silence4.wav" , 3 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_6.wav" , 1955 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_h_8.wav" , 2813 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_g_5.wav" , 1177 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_f_7.wav" , 3013 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_10.wav" , 63 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_13_voiceb.wav" , 381 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_alone_8_voiceb.wav" , 169 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_group_1_voicea.wav" , 1009 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_a_3.wav" , 3026 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_group_2.wav" , 856 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_gp_4_voiced.wav" , 2627 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_e_2.wav" , 2441 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_2_voicec.wav" , 494 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_generic_3r_voiced.wav" , 1046 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_advance_left_2_voicea.wav" , 1196 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_10_voiced.wav" , 1181 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\flashlight_face_3_voiced.wav" , 2113 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_macho_3_voiced.wav" , 2699 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_c_6.wav" , 2027 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_pickup_a_2.wav" , 1439 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_alone_6_voiceb.wav" , 461 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_d_3.wav" , 3458 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_specific_a_3.wav" , 3167 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_generic_a_7.wav" , 2838 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_15_voiceb.wav" , 950 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_c_6.wav" , 2976 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_7.wav" , 2042 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_dune\\mp_dune_c1_a1.wav" , 3412 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alarm_alone_4_voiced.wav" , 397 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_fear_8_voiced.wav" , 411 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_24_voiceb.wav" , 2719 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_3.wav" , 3559 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_specific_a_4.wav" , 3183 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_b_1.wav" , 1964 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_flank_left_1_voicea.wav" , 268 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_3_voicec.wav" , 200 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_9_voiced.wav" , 663 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_15_voiced.wav" , 2606 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_jungle\\mp_jungle_s1_a1.wav" , 3201 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_macho_2_voicea.wav" , 1699 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_alone_6_voicea.wav" , 155 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_10.wav" , 961 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_3.wav" , 2671 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_2.wav" , 2410 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_3_voiced.wav" , 1314 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_c_2.wav" , 2984 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_2.wav" , 2922 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\flashbang_5_voiced.wav" , 1250 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_group_1.wav" , 2705 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_21.wav" , 2231 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_4_voiced.wav" , 1136 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_b_3.wav" , 3295 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\helicopter_sight_1_voiceb.wav" , 1241 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_5.wav" , 2507 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_b_5.wav" , 2619 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_flank_left_2_voiced.wav" , 1351 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\helicopter_sight_8_voicec.wav" , 2265 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_dune\\mp_dune_c3_d1.wav" , 2675 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_b_4.wav" , 1565 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_d_2.wav" , 2966 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_7_voiced.wav" , 1771 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_5_voiced.wav" , 1762 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_15_voicec.wav" , 2103 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_4.wav" , 2816 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\silence.wav" , 1237 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_10_voicea.wav" , 1126 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_attention_4_voiced.wav" , 179 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_go_get_4_voiced.wav" , 1539 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_5.wav" , 2806 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_19.wav" , 2634 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\vehicle_in_6_voiceb.wav" , 1941 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_4_voiced.wav" , 1361 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_1.wav" , 2033 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_alone_4_voicea.wav" , 40 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\60meters.wav" , 2781 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_6_voiced.wav" , 2490 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_advance_right_1_voicec.wav" , 673 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_advance_right_3_voiceb.wav" , 1886 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_6_voiced.wav" , 672 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_10.wav" , 983 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_13.wav" , 2162 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_d_4.wav" , 2861 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_13.wav" , 1740 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_e_1.wav" , 3091 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\regulator_direction_d_1.wav" , 3659 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_15_voiceb.wav" , 2497 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_f_3.wav" , 3220 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\flashbang_4_voiced.wav" , 934 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_4_group_voicea.wav" , 889 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_2_voiced.wav" , 898 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_10.wav" , 3157 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_4.wav" , 3338 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alarm_alone_2_voiced.wav" , 1434 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_3.wav" , 3523 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_9_voicea.wav" , 804 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alarm_alone_5_voiceb.wav" , 480 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_group_5.wav" , 2457 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_g_3.wav" , 3200 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_3_voiced.wav" , 1583 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_4_voicea.wav" , 1102 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_b_4.wav" , 2467 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_2_voicea.wav" , 151 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_suppress_1_voiceb.wav" , 1056 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_30_voiced.wav" , 1549 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_6.wav" , 2906 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_group_1_voicea.wav" , 1502 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_9.wav" , 88 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_15_voicea.wav" , 2492 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_alone_2_voiced.wav" , 364 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_6.wav" , 2933 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_mutants_6_voiced.wav" , 2505 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_retreat_1r_voicea.wav" , 873 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\doyle_6.wav" , 3199 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_1_voiced.wav" , 1066 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_8_voiceb.wav" , 369 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_6.wav" , 3197 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_attention_4_voiced.wav" , 319 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_j_3.wav" , 3425 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_17.wav" , 3001 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_3_voicea.wav" , 1185 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_3.wav" , 3459 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_a_1ter.wav" , 2451 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_n_2.wav" , 3545 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_13.wav" , 3704 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_2_voicec.wav" , 697 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alone_cough_1_voicea.wav" , 525 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_4_voiceb.wav" , 1665 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_5_voiced.wav" , 1409 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_attention_1_voiced.wav" , 168 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_6_voicea.wav" , 2929 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_8_voiced.wav" , 2024 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_10.wav" , 446 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\helicopter_sight_5_voiced.wav" , 2590 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_alone_2_voiced.wav" , 1246 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_8_voicea.wav" , 2891 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\announce2.wav" , 3432 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_5_voicec.wav" , 109 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_group_3_voiceb.wav" , 947 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_b_1.wav" , 3604 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_right_1_voiced.wav" , 978 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_2.wav" , 213 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alarm_alone_1.wav" , 2209 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\doyle_3.wav" , 3698 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_a_3.wav" , 2323 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_14.wav" , 706 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_d_2.wav" , 2858 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_15.wav" , 1298 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_player_3_voiced.wav" , 2770 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_16_voiceb.wav" , 718 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\darkness_3_voiced.wav" , 2128 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_11_voicea.wav" , 302 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_i_4.wav" , 383 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_7.wav" , 154 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_b_4.wav" , 2635 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_generic_3r_voicea.wav" , 1089 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_1.wav" , 3700 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_10.wav" , 3107 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_3.wav" , 1311 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_26_voiceb.wav" , 2356 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_2.wav" , 2701 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_macho_2_voicec.wav" , 2236 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_k_4.wav" , 2485 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_17_voicec.wav" , 945 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_advance_right_3_voiced.wav" , 1952 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_2_voicea.wav" , 600 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_c_4.wav" , 2380 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_al_7_voicea.wav" , 1710 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_2_voiceb.wav" , 255 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_a_4.wav" , 2577 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_18_voicea.wav" , 810 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_40_voicea.wav" , 1768 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_21.wav" , 928 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_c_1.wav" , 2614 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_generic_2_voicea.wav" , 998 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_15.wav" , 1607 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_alone_5_voicec.wav" , 171 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_5_voiced.wav" , 144 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_i_1.wav" , 3278 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_player_1_voiced.wav" , 2475 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_5.wav" , 3289 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_14.wav" , 788 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_m_7.wav" , 2991 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_a_3.wav" , 3120 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_c_3.wav" , 3667 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\regulator_direction_a_1.wav" , 3388 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_10_voicec.wav" , 1109 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\flashbang_3_voicea.wav" , 1563 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_a_3.wav" , 3309 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_12.wav" , 1704 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_g_3.wav" , 2974 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_gp_3_voiced.wav" , 433 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_macho_5_voiced.wav" , 2131 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_h_5.wav" , 3364 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_3_voiceb.wav" , 1405 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_a_5.wav" , 2907 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_2_alone_voiced.wav" , 195 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_b_7.wav" , 2831 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_group_3_voicea.wav" , 1272 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_go_get_5_voiceb.wav" , 2399 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_4.wav" , 1871 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_15_voiced.wav" , 1989 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\darkness_4_voiced.wav" , 1958 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_h_2.wav" , 3124 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_flank_right_1_voiced.wav" , 653 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_fear_4_voicea.wav" , 335 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_12.wav" , 1577 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_retreat_2r_voicea.wav" , 1019 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_1_voicea.wav" , 272 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_1_alone_voiceb.wav" , 2238 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_c_6.wav" , 1870 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_a_3.wav" , 3489 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_3_voiceb.wav" , 1113 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\darkness_1_voicec.wav" , 1369 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\helicopter_sight_2_voiceb.wav" , 1204 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_g_4.wav" , 2464 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_player_1_voiceb.wav" , 2473 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_advance_right_2_voiceb.wav" , 1390 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_c_3.wav" , 1892 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_a_6.wav" , 1733 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_13_voiced.wav" , 887 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_2_group_voicea.wav" , 765 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\headshot.wav" , 2670 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_attention_5_voicec.wav" , 234 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_1_voiced.wav" , 493 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_e_3j.wav" , 3588 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_group_6_voiced.wav" , 1943 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_6.wav" , 2685 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_g_1.wav" , 3675 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_12.wav" , 2964 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_f_1.wav" , 2962 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\grenade_3.wav" , 1880 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_5_voiced.wav" , 2434 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\darkness_3_voicec.wav" , 1774 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_c_2.wav" , 1609 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_group_2_voiceb.wav" , 821 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_12.wav" , 55 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_9_voiced.wav" , 709 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_al_6_voicea.wav" , 152 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_b_3.wav" , 897 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_1_voiced.wav" , 1499 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_attention_2_voiceb.wav" , 124 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_c_8.wav" , 3342 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_originald_2.wav" , 3474 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_9_voiced.wav" , 568 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_6_voicec.wav" , 681 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_b_5.wav" , 3216 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_14.wav" , 1838 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8h.wav" , 37 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_7_voicec.wav" , 530 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\helicopter_sight_3_voiceb.wav" , 2593 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_12_voicea.wav" , 512 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_player_2_voicec.wav" , 1992 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_36_voiceb.wav" , 2437 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_a_2.wav" , 3349 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_advance_right_1_voiced.wav" , 1450 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_supress_1r_voicea.wav" , 639 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_b_2.wav" , 2960 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_k_3.wav" , 3618 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_advance_left_3_voicec.wav" , 1584 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_go_get_5_voicea.wav" , 2555 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_2_voicea.wav" , 782 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_alone_4_voicea.wav" , 123 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_5_voicea.wav" , 1566 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_player_3_voiceb.wav" , 2768 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_4.wav" , 3570 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_c_3.wav" , 3535 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_a_1v.wav" , 3678 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_1.wav" , 2360 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_2.wav" , 2189 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_3_voiced.wav" , 1751 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_2_voicea.wav" , 286 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8e.wav" , 980 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_5_voiceb.wav" , 1259 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_1.wav" , 3619 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_2.wav" , 1568 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alarm_alone_4_voicea.wav" , 2307 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_3.wav" , 2660 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_9.wav" , 2692 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_6_voiced.wav" , 1208 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_group_4.wav" , 2336 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_talk_to_1_voiceb.wav" , 2208 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_15_voicea.wav" , 882 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_b_2bis.wav" , 2721 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_4_voicea.wav" , 1911 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_al_8_voicea.wav" , 571 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_i_7.wav" , 721 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_f_3.wav" , 2784 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_2_voicec.wav" , 1526 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_a_5.wav" , 2801 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_10.wav" , 2393 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_9_voiceb.wav" , 300 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_k_2.wav" , 2832 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_39_voicec.wav" , 1844 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_b_6.wav" , 3185 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_5_voicec.wav" , 2433 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_1_voicec.wav" , 392 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_d_3.wav" , 2763 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_6_voicec.wav" , 1965 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_19_voicea.wav" , 2040 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_15.wav" , 2557 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alert_to_combat_group_4.wav" , 2010 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_go_get_4_voiceb.wav" , 1354 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_pickup_a_1.wav" , 2995 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_4_voicea.wav" , 66 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_group_6_voiced.wav" , 1625 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_5_voiceb.wav" , 1229 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_generic_a_1.wav" , 2864 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_3_voicea.wav" , 211 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_6_voicec.wav" , 833 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_17_voiced.wav" , 1412 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_20.wav" , 2824 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_fear_3_voicea.wav" , 107 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_5.wav" , 83 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_4_voiced.wav" , 930 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_macho_5_voicea.wav" , 929 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_advance_left_1_voiceb.wav" , 1157 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_12_voicea.wav" , 1072 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_5.wav" , 3417 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_30_voiceb.wav" , 1698 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_i_8.wav" , 22 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_d_1.wav" , 3179 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_flank_left_2_voiceb.wav" , 1162 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_mutants_5_voicea.wav" , 2677 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_f_4.wav" , 3530 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_jungle\\mp_jungle_s1_d1.wav" , 3574 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_20_voiceb.wav" , 1843 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_retreat_3r_voiced.wav" , 459 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_8_voiceb.wav" , 1680 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_g_3bis.wav" , 3636 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_alone_5_voicea.wav" , 652 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_6.wav" , 3161 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_6.wav" , 802 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_16_voicec.wav" , 692 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_4_voiced.wav" , 839 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_d_1.wav" , 3637 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_1_voicec.wav" , 1032 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_5.wav" , 1748 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_7_voiceb.wav" , 513 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_fear_3_voiced.wav" , 80 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_7.wav" , 2544 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_4_voicec.wav" , 2108 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_b_1.wav" , 3147 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_1.wav" , 1905 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_b_3.wav" , 3476 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_4_voicec.wav" , 713 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_1_voiceb.wav" , 1134 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_e_7.wav" , 3089 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_11_voicea.wav" , 1036 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_16_voicec.wav" , 719 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_5.wav" , 3641 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_11.wav" , 1542 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_c_1.wav" , 3473 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_6_voicec.wav" , 1718 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_6.wav" , 2645 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_5_voiceb.wav" , 914 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_macho_1_voiceb.wav" , 2224 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\flashbang_4_voicea.wav" , 916 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_12x.wav" , 3008 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_i_1.wav" , 3175 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_6.wav" , 1507 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_5_voiced.wav" , 453 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_11.wav" , 2855 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_a_2.wav" , 2316 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\mandown_alone_3_voiceb.wav" , 937 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_21_voiceb.wav" , 2449 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_8.wav" , 2896 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_f_1.wav" , 3316 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_14_voicec.wav" , 284 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_attention_4_voicea.wav" , 263 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_group_6_voicec.wav" , 704 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_1_voiced.wav" , 886 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_b_4.wav" , 3061 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_1.wav" , 2628 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_13_voicec.wav" , 520 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_11_voicea.wav" , 1537 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_retreat_1_voicea.wav" , 874 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_freighter\\mp_freighter_s1_a1.wav" , 3294 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_pickup_a_2.wav" , 1217 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_d_4.wav" , 1556 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_o_6.wav" , 3182 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alarm_group_3_voicea.wav" , 2151 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_9_voicea.wav" , 850 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_7.wav" , 3123 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_8.wav" , 3246 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_8_voicea.wav" , 1742 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_7_voicec.wav" , 2202 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_group_5_voiced.wav" , 1067 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_8_voicec.wav" , 1696 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_alone_7_voicec.wav" , 1465 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_7.wav" , 1772 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_a_5.wav" , 2098 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_1_voiceb.wav" , 599 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_h_5bis.wav" , 3146 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_4_voiced.wav" , 1835 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_41_voiced.wav" , 1962 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_2.wav" , 2992 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_15_voiced.wav" , 2607 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_alone_3_voicec.wav" , 753 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_10.wav" , 2488 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_e_2.wav" , 3243 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_8_c.wav" , 482 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_8_voiced.wav" , 2090 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_e_5.wav" , 2711 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_macho_4_voiced.wav" , 2460 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_al_3_voicea.wav" , 1268 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_3_voiceb.wav" , 1069 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_alone_6_voiced.wav" , 167 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_8_voiced.wav" , 271 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_1_voiced.wav" , 2233 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_5_voicec.wav" , 1983 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_20.wav" , 710 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier6.wav" , 2757 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\doyle_9.wav" , 3699 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_2_alone_voicea.wav" , 96 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_3.wav" , 3608 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_3_voicea.wav" , 1650 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_player_6_voicec.wav" , 2571 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lassie.wav" , 3341 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alarm_alone_4_voiceb.wav" , 2078 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_f_7.wav" , 3073 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_33_voiced.wav" , 813 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_4_voicea.wav" , 2214 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_j_2.wav" , 2499 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_left_1r_voiced.wav" , 597 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\darkness_5_voicec.wav" , 906 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_attention_4.wav" , 2122 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_a_1.wav" , 3679 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_group_5_voiced.wav" , 2471 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_2_voiceb.wav" , 1336 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_15_voiced.wav" , 538 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_supress_3_voiced.wav" , 993 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_group_1_voiced.wav" , 1656 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_9_voiced.wav" , 786 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_24.wav" , 164 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_g_4.wav" , 3691 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_16_voiceb.wav" , 1996 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_19.wav" , 1191 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_talk_to_2_voicea.wav" , 2403 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\helicopter_sight_1_voicea.wav" , 1240 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_1_voicea.wav" , 1221 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_10_voiced.wav" , 893 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_8.wav" , 2454 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\vehicle_in_8_voiced.wav" , 744 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_14.wav" , 2170 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_o_2.wav" , 749 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_15_voiceb.wav" , 2604 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_generic_a_3.wav" , 3269 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_2_voicec.wav" , 1163 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_13.wav" , 3086 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_1_voicea.wav" , 1422 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_e_1.wav" , 3683 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_3_voicea.wav" , 991 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_b_7.wav" , 1071 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_a_1biss.wav" , 3259 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_2.wav" , 868 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_a_2.wav" , 2602 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_group_1_voiced.wav" , 649 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_e_1.wav" , 3652 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_5.wav" , 1443 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_5_voiced.wav" , 2312 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_seen_group_1_voiceb.wav" , 1049 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_talk_to_1_voiced.wav" , 2435 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\flashbang_1_voicea.wav" , 1033 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_a_2.wav" , 3488 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_12_voiced.wav" , 1660 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_5.wav" , 81 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_3.wav" , 932 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_5.wav" , 3448 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_9_voiced.wav" , 1122 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\flashlight_face_2_voiced.wav" , 1922 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_10.wav" , 3328 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_lake\\mp_lake_c3_d1.wav" , 1953 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_14_voicea.wav" , 1620 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_fear_6_voicea.wav" , 457 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_e_2.wav" , 2703 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_12.wav" , 2883 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_17_voiceb.wav" , 1603 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_talk_to_1_voicea.wav" , 2094 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_f_1.wav" , 3696 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_seen_group_3_voiceb.wav" , 1270 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_22_voicea.wav" , 2000 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_42_voiced.wav" , 2164 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_lake\\mp_lake_s1_d1.wav" , 3511 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_c_4.wav" , 3479 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_alone_1_voiced.wav" , 707 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\darkness_1_voiced.wav" , 2038 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_16_voiced.wav" , 2525 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_player_3_voicea.wav" , 2767 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_a_1.wav" , 1705 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_macho_4_voicec.wav" , 2459 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_9_voicea.wav" , 158 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_group_3_voicea.wav" , 1913 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_11.wav" , 2702 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_9_voiceb.wav" , 1104 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_5.wav" , 3215 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_16_voiced.wav" , 720 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_4.wav" , 3544 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_b_3.wav" , 3230 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_group_2_voicea.wav" , 345 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_9_voicea.wav" , 198 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_b_4.wav" , 2017 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alarm_alone_1_voiced.wav" , 92 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_pickup_e_2.wav" , 3099 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_6_voiceb.wav" , 996 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_b_2.wav" , 337 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\vehicle_in_3_voicec.wav" , 402 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_32_voiced.wav" , 2188 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_7_voiced.wav" , 799 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_8_voicea.wav" , 25 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_e_3.wav" , 853 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_k_4.wav" , 3164 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_b_1.wav" , 3057 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_b_3.wav" , 1949 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_4_voiced.wav" , 1154 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_group_3_voiced.wav" , 358 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_6.wav" , 2392 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_supress_1_voicea.wav" , 640 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_seen_gp_1_voiced.wav" , 1589 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_18.wav" , 3665 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_12_voiced.wav" , 1064 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_2.wav" , 2320 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_e_2.wav" , 3410 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_j_1.wav" , 2326 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\vehicle_in_6_voiced.wav" , 2116 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_f_3.wav" , 3666 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_pickup_e_4.wav" , 2107 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alarm_group_2_voiced.wav" , 1383 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_10.wav" , 2114 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_9_voicea.wav" , 881 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_1.wav" , 3670 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_21.wav" , 3048 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_attention_2_voicec.wav" , 125 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_c_3.wav" , 1951 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_go_get_2_voicea.wav" , 2421 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_5.wav" , 3560 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_d_3.wav" , 129 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_43_voiced.wav" , 2245 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_17_voicea.wav" , 1721 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_l_6.wav" , 2810 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_d_3.wav" , 2250 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_alone_5_voicea.wav" , 97 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_5.wav" , 210 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_3_voiced.wav" , 1651 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_supress_1_voiced.wav" , 1189 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_a_1.wav" , 3443 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_5.wav" , 2448 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\vehicle_in_2_voiceb.wav" , 2193 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\vehicle_in_1_voiceb.wav" , 1585 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_group_3_voiced.wav" , 1008 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_c_5.wav" , 2805 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_j_4.wav" , 2988 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_b_1.wav" , 2725 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_21.wav" , 2184 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\helicopter_sight_6_voicec.wav" , 2563 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_advance_right_2_voiced.wav" , 1599 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_7.wav" , 2119 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_28_voiced.wav" , 1792 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_al_7_voiced.wav" , 1976 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_g_1.wav" , 2747 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_macho_5_voiced.wav" , 2641 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_23_voiced.wav" , 1777 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_flank_right_2_voiced.wav" , 880 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_h_1.wav" , 2923 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_3_voiceb.wav" , 1514 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_al_5_voicea.wav" , 792 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_suppress_6_voiced.wav" , 1802 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_b_2.wav" , 1723 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_2_voicea.wav" , 1013 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_h_3.wav" , 3593 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_g_3.wav" , 3481 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\announce4.wav" , 3513 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_generic_1_voiced.wav" , 582 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_macho_4_voiced.wav" , 1959 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_e_4.wav" , 2674 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_alone_8_voicec.wav" , 34 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_16.wav" , 2149 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_a_2.wav" , 2829 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_5_voiceb.wav" , 1686 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_7.wav" , 3595 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_generic_1r_voicea.wav" , 28 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_macho_1_voicea.wav" , 900 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_flank_right_3_voiceb.wav" , 556 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_2_voiced.wav" , 1222 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\mandown_group_2_voicea.wav" , 1403 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_8.wav" , 3605 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_g_5.wav" , 2930 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_suppress_2_voicea.wav" , 1928 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_23.wav" , 137 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_21_voicec.wav" , 2519 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_7.wav" , 2869 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_15_voiced.wav" , 2648 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_3_voicea.wav" , 590 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\darkness_5_voicea.wav" , 444 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_9.wav" , 3411 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_5_voicea.wav" , 321 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\mandown_alone_1_voiceb.wav" , 1155 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_17.wav" , 715 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_2_voiced.wav" , 1034 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_f_3.wav" , 3115 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_e_1.wav" , 3653 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_10.wav" , 643 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_mutants_5_voiced.wav" , 2680 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_1_voicec.wav" , 43 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_7.wav" , 3635 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_13_voicec.wav" , 972 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_7_voiced.wav" , 2016 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_f_2.wav" , 3594 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_alone_2.wav" , 2402 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_4_voicec.wav" , 1606 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_macho_5_voicea.wav" , 2638 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_13_voicea.wav" , 1289 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_g_1.wav" , 3133 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_4_voiced.wav" , 1833 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_9_voicec.wav" , 501 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_16.wav" , 3695 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_13_voiceb.wav" , 1329 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_go_get_3_voicea.wav" , 2124 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\vehicle_in_3_voiceb.wav" , 797 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_3_voicec.wav" , 1349 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_fear_4_voiced.wav" , 1553 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_7.wav" , 1442 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_b_1.wav" , 3516 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\flashbang_3_voiced.wav" , 1575 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_player_6_voiced.wav" , 2572 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_talk_to_2_voiceb.wav" , 2357 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_macho_4_voicea.wav" , 959 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_a_6.wav" , 2217 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_f_3.wav" , 2919 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_generic_2r_voicea.wav" , 997 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_g_1.wav" , 2406 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_b_4.wav" , 2387 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_group_3_voiceb.wav" , 359 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_gp_6_voiced.wav" , 852 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_g_4.wav" , 3610 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_g_4bis.wav" , 3661 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_seen_group_3_voicec.wav" , 761 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_28_voicea.wav" , 1476 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_gp_5_voicea.wav" , 322 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_attention_2_voiced.wav" , 299 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_9.wav" , 3104 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_17.wav" , 1094 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_12.wav" , 1063 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_9_voiceb.wav" , 857 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_b_1.wav" , 3524 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_i_6.wav" , 2746 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_5.wav" , 1815 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_suppress_4_voicea.wav" , 1207 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_9.wav" , 2827 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_rush_2_voicec.wav" , 415 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_14_voicec.wav" , 2314 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\mandown_group_2_voicea.wav" , 1050 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_5_alone_voiced.wav" , 1790 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_17_voicea.wav" , 1261 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_j_3.wav" , 2411 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_talk_to_3_voiced.wav" , 2578 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_group_7_voiced.wav" , 739 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_5_voiced.wav" , 527 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_9_voiceb.wav" , 1005 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_3_voiced.wav" , 1374 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_e_1.wav" , 2583 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_19.wav" , 1081 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_f_3.wav" , 3551 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_3_voicec.wav" , 264 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_b_4.wav" , 2345 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_10_voicec.wav" , 1283 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_11.wav" , 1254 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_11_voiceb.wav" , 1621 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_2_voicec.wav" , 827 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_6_voicea.wav" , 94 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_d_3.wav" , 3135 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_e_2.wav" , 3056 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_b_4.wav" , 2364 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_2_voiced.wav" , 1058 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_al_5_voicea.wav" , 1293 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_f_1.wav" , 2924 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alarm_group_2_voicea.wav" , 1770 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_3_voicea.wav" , 524 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_13.wav" , 1618 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_45_voiced.wav" , 1775 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\announce8.wav" , 3445 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_14_voiceb.wav" , 197 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\vehicle_in_3_voicea.wav" , 243 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_4_voicea.wav" , 757 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_6.wav" , 2531 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_pickup_c_1.wav" , 473 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_e_1.wav" , 2534 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_6_voicea.wav" , 14 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_3_voicec.wav" , 1303 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_3_voicec.wav" , 1582 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_4_voiceb.wav" , 1490 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_6.wav" , 3568 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_1_voiceb.wav" , 701 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\helicopter_sight_3_voiced.wav" , 2595 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_3_voiced.wav" , 1864 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_generic_5_voicec.wav" , 910 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_b_2.wav" , 3639 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_c_6.wav" , 2105 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_2_voicea.wav" , 1392 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\flashbang_1_voicea.wav" , 1321 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_dune\\mp_dune_s1_a1.wav" , 3440 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_10_voiced.wav" , 1535 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_7_voiced.wav" , 87 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_10.wav" , 428 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_3.wav" , 3257 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_15_voicea.wav" , 737 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_3_group_voicea.wav" , 623 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\krieger\\krieger2.wav" , 3707 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_alone_1_voiced.wav" , 1530 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_group_4_voiced.wav" , 1808 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_b_3.wav" , 3231 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_e_4.wav" , 1968 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_g_5.wav" , 2788 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_1_voicec.wav" , 2282 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_2_b.wav" , 3045 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_c_4.wav" , 1586 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_4_alone_voicea.wav" , 779 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_21_voiced.wav" , 2520 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_group_4_voiced.wav" , 1789 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_suppress_5_voiced.wav" , 2118 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_13_voicea.wav" , 1331 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_l_4.wav" , 3019 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_m_9.wav" , 3266 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c1_d1.wav" , 3576 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_g_5.wav" , 3334 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_f_1.wav" , 875 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_15_voiced.wav" , 1446 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_18.wav" , 3472 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_d_1_b.wav" , 3371 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_9.wav" , 3275 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_freighter\\mp_freighter_c2_a1.wav" , 3389 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_go_get_5_voicec.wav" , 2496 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_e_6.wav" , 3094 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alone_sneeze_1_voicea.wav" , 816 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_h_2.wav" , 3021 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_16.wav" , 2013 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_1_alone_voicec.wav" , 1649 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_gp_2_voiced.wav" , 1108 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_9.wav" , 2198 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_4.wav" , 434 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_7.wav" , 1253 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_13_voicea.wav" , 806 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_4.wav" , 3514 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_7.wav" , 2663 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_g_7.wav" , 563 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_1_voiced.wav" , 1643 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_9.wav" , 3067 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_16_voiced.wav" , 2169 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_f_1.wav" , 3320 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_h_3.wav" , 1574 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_b_6.wav" , 2618 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_1_voiceb.wav" , 1610 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\mandown_alone_2_voicea.wav" , 1116 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_11.wav" , 1186 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_e_4.wav" , 2546 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c2_d1.wav" , 2893 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_b_2.wav" , 3486 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_18.wav" , 2774 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_1_voiced.wav" , 625 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_4.wav" , 1419 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_left_2_voicea.wav" , 795 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_4_group_voiceb.wav" , 605 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_7.wav" , 3194 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_1_group_voicea.wav" , 1622 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_6_voicec.wav" , 1966 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_23_voicec.wav" , 1776 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_8.wav" , 3000 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_2_voicea.wav" , 2369 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_7_voicea.wav" , 2676 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_group_1_voiceb.wav" , 1438 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_freighter\\mp_freighter_c3_d1.wav" , 2741 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_3_voiced.wav" , 1683 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_6.wav" , 1998 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_generic_2_voiceb.wav" , 1041 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_generic_6_voiceb.wav" , 1915 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_9.wav" , 3306 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_c_2.wav" , 2696 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_k_4.wav" , 2567 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_2.wav" , 3122 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_2_voiceb.wav" , 483 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_group_2_voiceb.wav" , 1195 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_11_voiceb.wav" , 1925 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_d_3.wav" , 3080 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_b_7.wav" , 3154 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_5_voiced.wav" , 394 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_27_voiced.wav" , 1413 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_4_voiceb.wav" , 1544 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_10.wav" , 3141 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_mercs_a_2.wav" , 2586 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\darkness_2_voicea.wav" , 1059 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_tell_get_3_voicea.wav" , 1678 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_a_3.wav" , 3173 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_c_1.wav" , 2997 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_2_voiced.wav" , 546 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_4.wav" , 3032 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_b_2.wav" , 3018 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_9.wav" , 427 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_41_voicea.wav" , 2308 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\mandown_alone_1_voiced.wav" , 1457 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_2_voicec.wav" , 42 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_2_voiced.wav" , 2220 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_b_2.wav" , 2756 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_4_voicec.wav" , 1110 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_6_d.wav" , 3027 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_12_voiceb.wav" , 1987 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_8.wav" , 1697 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_3.wav" , 1712 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_b_6.wav" , 2088 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_c_2.wav" , 2881 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alarm_alone_2_voiceb.wav" , 1521 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_8.wav" , 2700 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_3.wav" , 1787 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier2.wav" , 3424 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_20.wav" , 815 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_4.wav" , 2269 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\still_someone_a3.wav" , 1054 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_mutants_4_voiced.wav" , 2177 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_2_voiceb.wav" , 1420 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_f_1.wav" , 2281 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_d_5.wav" , 3441 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_d_1.wav" , 3177 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_1_voicea.wav" , 2289 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\darkness_4_voicea.wav" , 1448 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_5_voicea.wav" , 2050 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_g_3.wav" , 2852 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_1.wav" , 3517 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_b_3.wav" , 2874 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_seen_al_4_voicea.wav" , 666 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_8.wav" , 842 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\doyle_5.wav" , 3528 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_4.wav" , 3607 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_group_4_voicec.wav" , 888 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_c_2.wav" , 2418 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_generic_1_voicea.wav" , 682 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_9.wav" , 3713 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_7.wav" , 3029 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_mercs_a_3.wav" , 2720 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_8.wav" , 3217 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_a_4.wav" , 2972 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_c_1.wav" , 3293 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_g_3.wav" , 2643 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c1_d1.wav" , 3187 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_group_4_voicec.wav" , 1798 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_18.wav" , 1975 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_14_voiced.wav" , 1767 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_e_1.wav" , 3428 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_5.wav" , 3006 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_macho_2_voiced.wav" , 2237 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_l_7.wav" , 841 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_g_2.wav" , 3131 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_5_voiced.wav" , 544 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_3_group_voiced.wav" , 1209 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_talk_to_2_voiced.wav" , 2613 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\anouncer2.wav" , 3339 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_12_voiceb.wav" , 464 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_4.wav" , 1508 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_7_voiced.wav" , 531 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_b_3.wav" , 3423 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\armstraining.wav" , 3390 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_5_voicea.wav" , 466 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_19.wav" , 3427 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_18_voiceb.wav" , 986 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\flashbang_1_voiceb.wav" , 391 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_3_voicea.wav" , 1070 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_group_6_voicea.wav" , 818 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\darkness_1_voiced.wav" , 1931 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_5_voiceb.wav" , 924 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\mandown_group_4_voicec.wav" , 419 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_23.wav" , 2242 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_7_voicea.wav" , 670 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_17.wav" , 3393 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\helicopter_sight_4_voiceb.wav" , 2328 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_40_voicec.wav" , 1831 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_a_5.wav" , 3065 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_7_voiced.wav" , 1785 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_4.wav" , 1198 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_12.wav" , 727 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_2_voicea.wav" , 348 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_15.wav" , 463 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\darkness_3_voiceb.wav" , 2097 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alarm_alone_2_voicea.wav" , 1360 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_c_4.wav" , 1416 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_18_voiced.wav" , 1296 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_macho_2_voiced.wav" , 1617 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_3_voiced.wav" , 278 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_14_voicea.wav" , 283 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_19_voicec.wav" , 52 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_1_voicec.wav" , 1227 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_attention_1_voicea.wav" , 241 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_alone_3_voicea.wav" , 751 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_group_4_voicea.wav" , 1010 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_e_5.wav" , 768 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_f_4.wav" , 2123 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_player_2_voicea.wav" , 1990 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_e_1.wav" , 3326 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_1_voiceb.wav" , 674 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\grenade_2_voicea.wav" , 705 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_group_3_voiced.wav" , 824 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_16.wav" , 3004 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_12_voicea.wav" , 2064 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_3_voiceb.wav" , 1708 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_fear_4_voicea.wav" , 382 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\helicopter_sight_6_voicea.wav" , 2561 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_group_6.wav" , 2089 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_e_3.wav" , 3214 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_9_voiceb.wav" , 1822 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_8_voiced.wav" , 542 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_f_6.wav" , 2405 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_17_voiceb.wav" , 2058 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\krieger\\krieger2_2.wav" , 3360 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_pickup_e_1.wav" , 3460 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_f_4.wav" , 1427 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_13.wav" , 75 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_14.wav" , 3252 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_9_voiced.wav" , 2732 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_7.wav" , 3518 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_d_1.wav" , 2985 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_4.wav" , 2150 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_7.wav" , 3456 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_l_1.wav" , 3093 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_j_5.wav" , 1897 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_2.wav" , 3022 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_1_voiced.wav" , 1453 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_e_3bisj.wav" , 3565 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_25_voicec.wav" , 1799 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_s1_d1.wav" , 3084 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_seen_alone_4.wav" , 2190 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alarm_group_3_voiced.wav" , 2452 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_group_1_voicea.wav" , 357 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_e_1.wav" , 2814 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_9.wav" , 1292 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_26_voicea.wav" , 2359 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_b_7.wav" , 2365 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_17.wav" , 635 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_retreat_1_voiced.wav" , 2840 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_12.wav" , 1400 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_14_voicec.wav" , 1727 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_4.wav" , 1397 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_25.wav" , 3245 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_5_voiced.wav" , 1661 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_go_get_5_voiced.wav" , 2400 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\vehicle_in_1_voiced.wav" , 237 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_a_5.wav" , 3461 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_a_2_b.wav" , 3273 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\still_someone_a1.wav" , 2667 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_g_6.wav" , 3247 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_8.wav" , 1236 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_2.wav" , 901 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_announcers_a_3.wav" , 3292 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_i_4.wav" , 2446 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_1.wav" , 3193 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_f_2.wav" , 3050 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_a_5.wav" , 1677 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_go_get_1_voicea.wav" , 777 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_2_group_voicec.wav" , 917 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_15.wav" , 2798 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_attention_1_voiced.wav" , 54 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_5.wav" , 3623 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_flank_left_2_voicea.wav" , 496 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_3_voiced.wav" , 1670 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_m_9.wav" , 2157 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_13_voiced.wav" , 2517 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_7.wav" , 2970 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_1.wav" , 2845 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_11_voicea.wav" , 1370 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_1_voiced.wav" , 1249 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_player_1_voicec.wav" , 2474 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_macho_3_voicea.wav" , 836 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_10_voiced.wav" , 823 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_5_voiced.wav" , 2095 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\receive_fire_group_2.wav" , 1543 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_g_1.wav" , 3071 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_a_1.wav" , 3681 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_seen_gp_2_voiced.wav" , 808 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_3_voiced.wav" , 1366 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_alone_1_voicea.wav" , 783 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_13.wav" , 3386 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_5_voiced.wav" , 1750 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_i_2.wav" , 3566 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_gp_2_voiced.wav" , 1168 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_player_5_voicec.wav" , 2481 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_10.wav" , 3290 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_group_2_voiceb.wav" , 2275 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_10_voicec.wav" , 1182 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_f_6.wav" , 3495 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\darkness_5_voicea.wav" , 422 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_a_5.wav" , 2949 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_13.wav" , 879 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_18.wav" , 2815 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c3_d1.wav" , 1285 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_5_voiceb.wav" , 2243 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_f_8.wav" , 1026 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_a_7.wav" , 1674 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_c_2.wav" , 3051 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_4_voicea.wav" , 136 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alarm_alone_3_voiced.wav" , 1703 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_newpickup_a_2.wav" , 2850 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_g_2spare.wav" , 2934 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_42_voicec.wav" , 2163 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_10.wav" , 1506 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_i_1.wav" , 2530 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_25_voicea.wav" , 1938 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_19.wav" , 3329 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_supress_3_voicea.wav" , 528 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_gp_2_voicea.wav" , 541 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_g_2.wav" , 3501 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_rush_1_voicea.wav" , 2389 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_8.wav" , 2004 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_11.wav" , 2343 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_7_voiced.wav" , 297 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_h_1.wav" , 3407 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_group_4_voicec.wav" , 846 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_group_3_voicec.wav" , 253 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\mandown_alone_3_voiced.wav" , 1076 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_group_6_voiceb.wav" , 1210 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_e_2.wav" , 1179 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_2.wav" , 3600 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_15_voicec.wav" , 884 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_15_voiceb.wav" , 1346 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\flashlight_face_3_voicea.wav" , 1138 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_12_voicea.wav" , 1888 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\flashbang_1_voiced.wav" , 1357 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_18.wav" , 817 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_go_get_4_voiced.wav" , 1523 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_17_voiced.wav" , 946 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\command.wav" , 3213 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_retreat_2_voicea.wav" , 1020 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_advance_left_1_voicea.wav" , 905 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_e_2.wav" , 3687 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_b_4.wav" , 3016 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alarm_group_2_voiceb.wav" , 1896 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_33_voiceb.wav" , 1224 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reloaded_1_voiced.wav" , 1117 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_e_4.wav" , 3401 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_6bis.wav" , 555 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_3_voiced.wav" , 989 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_newpickup_a_4.wav" , 3085 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_3_voicec.wav" , 1086 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_4_voicea.wav" , 536 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_f_1bis.wav" , 3033 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_15.wav" , 2219 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_talk_to_3_voicea.wav" , 1536 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_g_5.wav" , 2826 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_1.wav" , 3462 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_14_voicec.wav" , 1016 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_d_3.wav" , 2745 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\announce7.wav" , 3110 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_a_5.wav" , 2718 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_macho_1_voicec.wav" , 2225 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_13_voicec.wav" , 209 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_13_voiced.wav" , 982 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_b_2.wav" , 2415 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_f_1silence.wav" , 5 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_jungle\\mp_jungle_c3_a1.wav" , 2579 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_group_5_voiced.wav" , 1825 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_9_voicea.wav" , 1430 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\flashbang_2_voicea.wav" , 811 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_seen_alone_3_voiceb.wav" , 1362 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_e_3.wav" , 3435 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_c_4.wav" , 3203 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_alone_5_voiceb.wav" , 224 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_5.wav" , 2185 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_generic_4_voicec.wav" , 1811 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_18_voiced.wav" , 429 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_7.wav" , 3573 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_group_3_voicec.wav" , 780 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\what_the_hell.wav" , 2668 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\grenade_1_alone_voicea.wav" , 1454 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_4.wav" , 3178 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_a_7.wav" , 3234 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_11.wav" , 1629 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_7_voicec.wav" , 1935 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_38_voiceb.wav" , 2691 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_right_1r_voiced.wav" , 977 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_11_voiced.wav" , 156 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_6_voicea.wav" , 1082 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_4_voiceb.wav" , 1626 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_14_voiceb.wav" , 1724 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_20_voicea.wav" , 1484 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier3.wav" , 2942 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_2.wav" , 1954 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_talk_to_5_voiced.wav" , 2134 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_player_5_voiceb.wav" , 2480 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_c_1.wav" , 1281 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_n_6.wav" , 3256 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_7.wav" , 30 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_8_voiceb.wav" , 1950 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_b_1.wav" , 3475 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_15.wav" , 3624 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\comm_supress_2.wav" , 2072 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_f_3.wav" , 2802 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_c_6.wav" , 279 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_3_voiced.wav" , 1947 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_lake\\mp_lake_c1_a1.wav" , 3037 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alarm_alone_1_voicea.wav" , 31 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_g_3.wav" , 2014 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_suppress_6_voiceb.wav" , 1190 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_group_1_voiceb.wav" , 968 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_44_voicea.wav" , 2206 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_b_2.wav" , 3174 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_jungle\\mp_jungle_c1_d1.wav" , 3118 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_14_voiceb.wav" , 1532 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_2.wav" , 49 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_talk_to_5.wav" , 2249 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_g_3.wav" , 3527 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_28_voiceb.wav" , 1934 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_7_voiced.wav" , 1330 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_f_2.wav" , 3062 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_mutants_3_voicea.wav" , 2045 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_7_voiced.wav" , 2432 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_to_alert_gp_1_voiced.wav" , 1193 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_18.wav" , 134 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_j_4.wav" , 1932 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_specific_a_2.wav" , 3277 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_g_2.wav" , 2748 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_8.wav" , 2800 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_alone_5_voiced.wav" , 695 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_alone_7.wav" , 2332 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_i_5.wav" , 3484 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_b_2.wav" , 3159 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_retreat_2_voicea.wav" , 1756 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_6.wav" , 185 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_freighter\\mp_freighter_c3_a1.wav" , 2833 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\announce1.wav" , 2901 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_16_voiced.wav" , 2026 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\mandown_group_1_voicea.wav" , 1118 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_9_voiced.wav" , 398 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_fear_1_voicea.wav" , 517 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_flank_right_2_voiceb.wav" , 1073 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\mandown_alone_2_voiceb.wav" , 1408 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_attention_5_voicea.wav" , 114 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_9_voiced.wav" , 1091 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_2.wav" , 217 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_group_2.wav" , 636 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_7.wav" , 1297 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_group_2_voicea.wav" , 366 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_12_voiced.wav" , 256 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_k_5.wav" , 3515 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_10_voicec.wav" , 399 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_1.wav" , 3705 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_5.wav" , 2803 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_a_5.wav" , 1806 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_8_voicea.wav" , 2100 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_flank_left_1_voicec.wav" , 331 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_21_voicea.wav" , 2518 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_suppress_2_voiceb.wav" , 1726 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alert_hear_gp_1_voicea.wav" , 829 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_12_voicea.wav" , 352 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_9.wav" , 3363 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_5.wav" , 2730 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_f_2.wav" , 2302 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_17.wav" , 201 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_1_voiced.wav" , 498 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_15_voicea.wav" , 920 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_k_2.wav" , 2301 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_seen_alone_1.wav" , 2071 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_10_voicea.wav" , 13 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alone_sniffle_1_voiced.wav" , 7 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_suppress_2_voiced.wav" , 2140 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_to_alert_al_4_voicea.wav" , 539 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_1_voicea.wav" , 492 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_23_voiceb.wav" , 1852 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_8.wav" , 2873 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_4_voicec.wav" , 1379 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_5_alone_voiceb.wav" , 2025 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_26_voiced.wav" , 2462 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_b_6.wav" , 3075 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8b.wav" , 995 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_8.wav" , 2538 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_group_1_voicea.wav" , 607 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_c_1.wav" , 3284 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_11.wav" , 3640 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d10.wav" , 3274 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_9_voicea.wav" , 1301 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_d_1.wav" , 2665 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_alone_12_voiced.wav" , 1807 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_7.wav" , 3325 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_12_voiceb.wav" , 2179 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\vehicle_in_7_voiceb.wav" , 575 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_2_voiced.wav" , 1201 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_b_4.wav" , 3305 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_37_voicea.wav" , 2143 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_l_5.wav" , 318 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_go_get_2_voicea.wav" , 2130 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_go_get_4_voicec.wav" , 1440 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_b_8.wav" , 3372 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_3.wav" , 2658 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_c_6.wav" , 3064 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_7_voicec.wav" , 170 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_group_3.wav" , 2009 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_5_voicec.wav" , 1257 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_d_2.wav" , 3656 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_right_2_voicea.wav" , 424 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_specific_b_1.wav" , 2959 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_fear_7_voiced.wav" , 339 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_al_7_voicea.wav" , 2417 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_l_4.wav" , 863 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_44_voiced.wav" , 2155 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\receive_fire_group_5.wav" , 2543 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_i_2.wav" , 1769 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_8.wav" , 491 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_5_voicea.wav" , 2192 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_a_1.wav" , 3708 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_a_6.wav" , 340 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_d_4.wav" , 3119 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\flashbang_5_voicec.wav" , 1084 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_7_voiceb.wav" , 1562 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_3_voiced.wav" , 1219 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_l_2.wav" , 3280 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_20_voicea.wav" , 691 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_g_2.wav" , 3660 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_14.wav" , 1630 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_13.wav" , 3554 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_35_voicea.wav" , 1099 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_13_voiceb.wav" , 577 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_tell_get_2_voicea.wav" , 1214 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_6_c.wav" , 3017 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_group_3.wav" , 1433 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\death_9_voicea.wav" , 1588 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_b_7.wav" , 2789 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_5bis.wav" , 3129 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\receive_fire_group_2_voiced.wav" , 752 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alarm_alone_3_voicea.wav" , 606 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_b_5.wav" , 2333 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_13_voiced.wav" , 1480 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_mutants_5_voicec.wav" , 2679 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_37_voiced.wav" , 2037 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_c_2a.wav" , 2672 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_mangoriver\\mp_mangoriver_c1_a1.wav" , 3272 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_suppress_2_voicec.wav" , 1734 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_l_7.wav" , 1893 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_4.wav" , 2795 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_24_voicec.wav" , 2742 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_41_voicec.wav" , 1961 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_11.wav" , 3387 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_e_2.wav" , 2812 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_generic_7_voicea.wav" , 618 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_5_voiced.wav" , 967 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_c_2.wav" , 2484 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_13_voicec.wav" , 303 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_c_2.wav" , 2980 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_11.wav" , 59 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_al_8_voicea.wav" , 1353 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_24_voicea.wav" , 2755 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_mutants_5_voiceb.wav" , 2678 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_l_6.wav" , 24 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_19_voicea.wav" , 330 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_alone_schuckl_1_voicea.wav" , 939 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_to_alert_group_6.wav" , 2211 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_9.wav" , 763 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_d_1.wav" , 2939 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_b_3.wav" , 2917 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_12.wav" , 2609 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\vehicle_in_6_voicea.wav" , 1139 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8d.wav" , 1517 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_f_1.wav" , 3651 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_e_3.wav" , 2621 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_8_1.wav" , 1130 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_generic_2_voicec.wav" , 1042 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_19_voicec.wav" , 1030 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_38_voicea.wav" , 2689 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeruins_specific_g_3.wav" , 3190 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_8_voiced.wav" , 1993 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_3.wav" , 3143 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_10.wav" , 2999 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_12_voiceb.wav" , 1068 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_17.wav" , 3541 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_14_voicea.wav" , 1702 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_9_voicec.wav" , 657 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_generic_3_voiced.wav" , 1047 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_b_5.wav" , 1636 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_3_voicea.wav" , 1022 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_1_voiceb.wav" , 1173 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_4_alone_voiceb.wav" , 883 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_idle_alone_8_voicec.wav" , 2285 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_e_3.wav" , 2342 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_alone_12_voiceb.wav" , 1561 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_19_voiceb.wav" , 1029 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_7.wav" , 259 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_16.wav" , 1458 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\helicopter_sight_4_voiced.wav" , 2330 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_10_voiced.wav" , 1183 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_al_2_voicea.wav" , 103 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_h_6.wav" , 2317 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_retreat_2_voiced.wav" , 2368 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_b_4.wav" , 3268 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\flashbang_6_voiced.wav" , 1729 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_alone_9_voicea.wav" , 553 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_group_1.wav" , 2178 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_c_6.wav" , 3281 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_flank_left_1_voiced.wav" , 598 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_9_voiced.wav" , 658 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_5_voicec.wav" , 925 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\100meters.wav" , 2866 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_f_1.wav" , 565 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\krieger\\krieger1.wav" , 3688 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_1.wav" , 655 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_group_2_voicea.wav" , 741 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_15.wav" , 2005 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_9.wav" , 708 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\pain_1_voiced.wav" , 378 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_6_voiced.wav" , 2138 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_flank_left_3_voiced.wav" , 1243 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_2_voicea.wav" , 147 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_7.wav" , 2117 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\reinforce_go_get_1_voiceb.wav" , 750 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_26.wav" , 503 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_1.wav" , 1631 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_mutants_6_voicec.wav" , 2504 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_attention_1.wav" , 2351 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_fear_2_voicea.wav" , 91 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_alone_3_voicea.wav" , 776 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_10.wav" , 3362 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_2_alert_seen_group_1.wav" , 1633 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_c_1.wav" , 3490 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_1.wav" , 199 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_macho_2_voiceb.wav" , 2235 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_a_1.wav" , 3165 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_3.wav" , 2296 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_18a.wav" , 2600 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_group_4_voiceb.wav" , 1258 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_8c.wav" , 1399 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_f_2.wav" , 2427 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\comm_retreat_2.wav" , 2361 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_13_voicea.wav" , 1161 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_b_2.wav" , 3317 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_pickup_a_1.wav" , 570 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_announcers_a_8.wav" , 3571 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_attention_4_voicea.wav" , 44 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\vehicle_in_4_voiced.wav" , 1044 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_c_1.wav" , 3682 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_9.wav" , 2436 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_14_voicea.wav" , 505 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_9_voiceb.wav" , 1096 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alarm_group_3_voicea.wav" , 2262 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_7_voicea.wav" , 1473 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_10_voicea.wav" , 614 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_11_voicec.wav" , 588 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_4_voicea.wav" , 372 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_rush_2_voicea.wav" , 431 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_7.wav" , 3038 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_8_voiced.wav" , 100 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_macho_3_voicea.wav" , 2843 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_b_6.wav" , 1150 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_a_2.wav" , 2822 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_e_1.wav" , 3365 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_a_1.wav" , 2478 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_14_voiced.wav" , 1572 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_seen_alone_5_voicea.wav" , 610 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_b_4.wav" , 3348 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_f_1.wav" , 3385 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_11.wav" , 3103 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_l_5.wav" , 2821 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_mutants_4_voicec.wav" , 2176 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_group_4_voicea.wav" , 1184 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_12_voicec.wav" , 323 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\flashbang_5_voicea.wav" , 1488 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_fear_5_voiced.wav" , 121 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_1_voiceb.wav" , 576 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_6_voiced.wav" , 2142 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_f_18.wav" , 3058 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\silence5.wav" , 4 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\affirmative_8_voicea.wav" , 647 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_k_1.wav" , 3130 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_a_4.wav" , 2856 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_dune\\mp_dune_s1_d1.wav" , 3477 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\reinforce_tell_get_4.wav" , 2216 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_seen_al_2_voiced.wav" , 1425 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\idle_to_alert_heard_alone_3.wav" , 2508 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_mutants_1_voiced.wav" , 2256 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\process.wav" , 3043 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\helicopter_sight_4_voicec.wav" , 2329 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_advance_left_1_voiced.wav" , 1731 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\affirmative_4_voiceb.wav" , 1332 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_3.wav" , 70 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_21.wav" , 2723 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_f_5.wav" , 3631 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_macho_6_voicea.wav" , 1364 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_5.wav" , 1619 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_5_voiceb.wav" , 1758 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_e_1.wav" , 3398 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_6_voiced.wav" , 2348 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\receive_fire_alone_1_voicea.wav" , 260 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_c_14.wav" , 3117 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_talk_to_5_voicec.wav" , 1401 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_seen_alone_4_voicec.wav" , 630 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_5_voicec.wav" , 72 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_b_3.wav" , 3455 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_e_6.wav" , 2212 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_b_1.wav" , 3047 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_alone_7.wav" , 953 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_16_voicec.wav" , 2524 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_22.wav" , 1269 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_7_voiceb.wav" , 207 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alarm_group_1_voiced.wav" , 1658 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_g_1.wav" , 2425 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_6_b.wav" , 3009 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_43_voiceb.wav" , 1873 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_g_8.wav" , 3555 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\yell_2.wav" , 2101 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_5_voiced.wav" , 1463 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\anouncer.wav" , 2996 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_18.wav" , 3531 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_direction_a_1spare.wav" , 3525 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_generic_2_voiced.wav" , 1043 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_i_6.wav" , 1256 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_seen_group_2_voicea.wav" , 181 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_d_4.wav" , 3172 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_a_2.wav" , 3170 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_10.wav" , 2486 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_airstrip\\mp_airstrip_c3_d1.wav" , 1944 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_al_6_voiced.wav" , 1531 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_mutants_6_voiceb.wav" , 2503 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_combat_alone_3_voiceb.wav" , 329 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_newpickup_a_1.wav" , 2935 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\receive_fire_group_8_voiceb.wav" , 2012 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_9_voicec.wav" , 1823 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_c_3.wav" , 3496 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_16_voicea.wav" , 896 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_23.wav" , 393 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\searching_generic_6_voiced.wav" , 1917 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_alone_20_voicea.wav" , 228 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_e_1.wav" , 3315 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_pickup_a_3.wav" , 2712 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\pain_12_voicea.wav" , 2129 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_group_1_voicec.wav" , 252 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_5.wav" , 3116 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_c_4.wav" , 1559 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_5.wav" , 2735 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_7.wav" , 2512 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_c_5.wav" , 2615 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_c_3.wav" , 1045 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_l_7.wav" , 1337 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_b_2.wav" , 2971 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_pickup_e_5.wav" , 3534 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\bulletrain_alone_4.wav" , 2714 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_4.wav" , 2542 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_f_3.wav" , 1545 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_talk_to_2_voiced.wav" , 1251 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_18_voiced.wav" , 2087 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_e_2.wav" , 2983 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_1.wav" , 2989 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_4.wav" , 3507 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_4_voicea.wav" , 325 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_b_4.wav" , 3138 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_specific_a_1.wav" , 3658 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_d_1bisj.wav" , 2921 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_c_1.wav" , 3584 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_a_3.wav" , 2310 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_d_2.wav" , 3204 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_seen_group_1_voiced.wav" , 949 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_j_1.wav" , 3318 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_suppress_5_voicea.wav" , 1780 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_c_7.wav" , 2581 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_mercs_a_4.wav" , 789 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_g_7.wav" , 3611 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_g_2.wav" , 3395 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_7_voicea.wav" , 2321 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_idle_al_2_voiced.wav" , 1551 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_specific_a_7.wav" , 3586 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_a_4.wav" , 1501 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_19_voiced.wav" , 1595 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_6_voiced.wav" , 316 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_to_alert_alone_14_voiced.wav" , 2194 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_k_3.wav" , 3160 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\grenade_1_group_voicec.wav" , 1788 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_15_voicec.wav" , 1418 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_6.wav" , 1816 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\reserch_generic_f_2.wav" , 3344 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_13_voiced.wav" , 1381 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_alone_4_voiced.wav" , 76 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\affirmative_6_voiced.wav" , 1394 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_a_1.wav" , 3007 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_seen_group_1_voicea.wav" , 487 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_20.wav" , 1900 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\mandown_group_1_voicea.wav" , 867 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_fear_1_voiceb.wav" , 64 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_4_voicec.wav" , 406 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_al_1_voicea.wav" , 990 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\pain_1.wav" , 99 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_8_b.wav" , 273 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_f_6.wav" , 3626 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_flank_right_1_voiceb.wav" , 435 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_h_6.wav" , 3253 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_e_8.wav" , 1021 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_7.wav" , 966 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_6.wav" , 317 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\receive_fire_group_1.wav" , 1957 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_seen_group_3_voiced.wav" , 1472 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_alone_7_voicea.wav" , 671 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\vehicle_in_2_voiced.wav" , 1700 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_9.wav" , 3408 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alarm_group_1_voicec.wav" , 1352 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_d_2.wav" , 2096 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_7_voiceb.wav" , 2349 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_advance_left_2_voiced.wav" , 2139 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_9.wav" , 724 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\darkness_3_voiced.wav" , 2284 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\lab\\damlab_specific_a_17.wav" , 1924 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alert_to_combat_al_4_voiced.wav" , 2288 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_group_11_voicec.wav" , 1926 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_o_4x.wav" , 2431 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_m_8.wav" , 1641 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_8.wav" , 3415 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_f_4.wav" , 2391 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_d_2.wav" , 3303 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\reinforce_talk_to_4_voicea.wav" , 1187 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_21.wav" , 1728 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_1_voicea.wav" , 353 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_a_4.wav" , 1869 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\affirmative_2_voicea.wav" , 110 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_2.wav" , 3028 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\darkness_5_voiced.wav" , 894 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_al_4_voicea.wav" , 175 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\bulletrain_alone_2_voicea.wav" , 793 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_e_2.wav" , 2258 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_al_8_voicea.wav" , 403 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_idle_alone_7_voiced.wav" , 2270 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\vehicle_in_2_voicec.wav" , 1675 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_e_3.wav" , 2716 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_macho_5_voicec.wav" , 2640 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_f_6.wav" , 3211 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_16.wav" , 1479 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_g_2.wav" , 2772 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_26_voicec.wav" , 2461 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_n_1.wav" , 2213 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_e_4.wav" , 2286 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_i_6.wav" , 1266 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_seen_group_2_voiceb.wav" , 631 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\yell_macho_1_voicea.wav" , 2986 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alarm_group_3_voicec.wav" , 2145 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_1_voiceb.wav" , 1513 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_seen_group_3_voicea.wav" , 665 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_15.wav" , 878 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_b_5.wav" , 3090 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_specific_d_4.wav" , 3596 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_4_voicea.wav" , 1639 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_d_1bis.wav" , 3079 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_rush_1_voicec.wav" , 2339 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_f_2.wav" , 1288 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\alarm_group_1_voiced.wav" , 1339 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\comm_retreat_1_voiceb.wav" , 2722 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_34_voicec.wav" , 1778 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_d_2.wav" , 2539 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alarm_alone_5_voicea.wav" , 165 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_generic_d_1.wav" , 2853 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_1_group_voiceb.wav" , 1899 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\searching_generic_5_voiceb.wav" , 909 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\darkness_2_voiced.wav" , 1826 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_20.wav" , 2931 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_1.wav" , 1396 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_35_voiceb.wav" , 1267 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_20_voicec.wav" , 1486 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_10.wav" , 3575 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\affirmative_2_voicec.wav" , 102 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_2.wav" , 1830 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_attention_5_voiced.wav" , 341 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_e_5.wav" , 3150 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_player_4_voicea.wav" , 2834 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_9.wav" , 3598 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_al_7_voicea.wav" , 712 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\yell_fear_3_voiced.wav" , 838 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\alarm_alone_3.wav" , 2055 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\dam\\damlab_specific_a_14.wav" , 2782 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_alone_3_voiceb.wav" , 858 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\vehicle_in_5_voicea.wav" , 437 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_alone_6_voiceb.wav" , 2344 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_specific_c_1.wav" , 3381 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_l_8.wav" , 2044 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\mandown_alone_2_voicec.wav" , 516 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_a_5.wav" , 2819 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_a_4.wav" , 3069 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_10a.wav" , 2651 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_a_2.wav" , 2657 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\comm_suppress_1_voiced.wav" , 1347 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_e_3bis.wav" , 3564 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_9.wav" , 2573 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_12.wav" , 89 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_b_2.wav" , 3285 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_alone_4_voicec.wav" , 35 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_g_3.wav" , 3482 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_specific_d_1.wav" , 3580 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\reinforce_talk_to_3_voicec.wav" , 2384 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_n_2.wav" , 2737 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_n_4.wav" , 3397 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_8_voicec.wav" , 58 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_10.wav" , 956 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_c_4.wav" , 2792 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_4_voicea.wav" , 957 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\combat_group_1.wav" , 1695 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_generic_a_2.wav" , 2948 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_idle_alone_15_voicea.wav" , 1827 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_alone_11_voicec.wav" , 98 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_11_voiced.wav" , 1927 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_direction_c_1x.wav" , 3585 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\bulletrain_group_1_voiced.wav" , 2160 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_g_1.wav" , 128 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_5_voiceb.wav" , 143 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\death_20_voiced.wav" , 1487 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_pickup_a_13.wav" , 3552 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_2_alert_seen_group_2.wav" , 1095 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\searching_generic_4_voicea.wav" , 1809 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\affirmative_4_voiced.wav" , 537 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_g_2.wav" , 48 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_31_voicec.wav" , 2246 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_5.wav" , 2967 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\factory\\factory_newpickup_a_11.wav" , 2305 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_g_4.wav" , 1861 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_8_voiced.wav" , 511 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\combat_alone_2_voicea.wav" , 1709 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_e_6.wav" , 2552 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_a_2.wav" , 2895 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_macho_1_voiced.wav" , 2226 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_2_voicea.wav" , 1890 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_25_voiceb.wav" , 1978 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_specific_d_3.wav" , 3158 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_n_1.wav" , 3450 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_29_voiced.wav" , 2076 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_13_voiceb.wav" , 870 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_direction_c_4.wav" , 3262 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_e_4.wav" , 1097 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_seen_alone_3_voiced.wav" , 1654 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_38_voicec.wav" , 2708 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_2_group_voiced.wav" , 1278 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_8_voiced.wav" , 2890 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_pickup_a_12.wav" , 2938 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_heard_alone_4_voicec.wav" , 1375 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_alone_19_voicec.wav" , 2132 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_11.wav" , 2070 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_a_1.wav" , 3310 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_idle_gp_1_voicea.wav" , 1316 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\yell_fear_5_voiced.wav" , 292 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_alone_2_voicea.wav" , 9 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_flank_left_2_voicec.wav" , 622 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_jungle\\mp_jungle_c3_d1.wav" , 1786 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_24.wav" , 84 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_o_1.wav" , 3677 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_h_2.wav" , 1701 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_a_4.wav" , 2956 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_f_1.wav" , 3311 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_specific_b_1.wav" , 3625 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\reinforce_talk_to_4_voiced.wav" , 1550 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_15_voiceb.wav" , 2376 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\flashbang_4_voicec.wav" , 927 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_l_6.wav" , 3352 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_direction_d_2.wav" , 3264 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_d_3.wav" , 3520 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_8.wav" , 835 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_5_voiced.wav" , 1384 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_generic_d_1.wav" , 1519 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_i_2.wav" , 2797 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_lake\\mp_lake_c1_d1.wav" , 2927 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_a_3.wav" , 159 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_6.wav" , 2911 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_2.wav" , 609 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_player_4_voicec.wav" , 2836 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_3.wav" , 2362 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\affirmative_6.wav" , 1124 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\death_4_voiced.wav" , 2141 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\jack\\death_19.wav" , 1385 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\comm_retreat_2_voicec.wav" , 1529 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\pain_4_voiceb.wav" , 187 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mission_generic\\mission_generic_a_20.wav" , 2585 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_e_2.1.wav" , 2115 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellion_mercs_c_8.wav" , 2957 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_5.wav" , 2734 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_g_1.wav" , 3521 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\alert_to_combat_gp_3_voicea.wav" , 474 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_4.wav" , 1920 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_m_9.wav" , 3457 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_h_3.wav" , 2857 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_h_2.wav" , 2946 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutantvoice\\comm_supress_3.wav" , 2303 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\grenade_3_group_voiceb.wav" , 1083 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_pickup_b_1.wav" , 3014 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_3.wav" , 3380 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_b_3.wav" , 3333 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_g_11.wav" , 3210 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_7_voiced.wav" , 1437 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_a_1.wav" , 3633 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_a_3.wav" , 849 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_n_4.wav" , 2932 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\alert_to_combat_group_6_voicec.wav" , 690 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_group_1_voiceb.wav" , 948 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_c_8.wav" , 2377 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_specific_f_3.wav" , 3561 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_alone_2_voiced.wav" , 854 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_b_2_b.wav" , 1604 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_6.wav" , 3096 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_5_voicec.wav" , 1404 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_c_3.wav" , 669 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_group_5.wav" , 1632 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\receive_fire_alone_6_voiced.wav" , 654 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_alone_10_voicea.wav" , 334 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_seen_group_2_voicec.wav" , 452 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_3_voicea.wav" , 2018 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_17_voiceb.wav" , 944 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\combat_to_alert_alone_5.wav" , 1160 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\steam\\steam_generic_e_5.wav" , 2375 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reinforce_tell_get_3_voiced.wav" , 2137 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_h_8.wav" , 3108 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_2.wav" , 3434 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\reloaded_3_voiced.wav" , 1395 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\cooler\\cooler_specific_c_3.wav" , 3400 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_39_voicea.wav" , 2291 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\alert_to_idle_group_4_voiceb.wav" , 2535 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\pain_2_voiced.wav" , 194 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_12_voiceb.wav" , 1663 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_g_4.wav" , 1264 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_20.wav" , 2223 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_group_3_voicea.wav" , 227 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_k_8.wav" , 1817 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\receive_fire_alone_6_c.wav" , 773 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\carrier\\carrier_generic_f_8.wav" , 3202 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_d_3.wav" , 2905 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_generic_i_3.wav" , 3087 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\reinforce_talk_to_5_voicea.wav" , 2015 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_8_voicea.wav" , 448 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_2.wav" , 1909 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\idle_to_alert_gp_1_voicea.wav" , 310 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\idle_to_alert_heard_alone_2_voiceb.wav" , 979 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_retreat_2_voiced.wav" , 1153 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\death_5.wav" , 1963 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\receive_fire_group_5_voicea.wav" , 1753 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\control\\control_generic_b_6.wav" , 3066 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_d_4.wav" , 2860 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_pickup_b_4.wav" , 163 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_fear_5_voicea.wav" , 388 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alarm_group_2_voiced.wav" , 1883 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_m_8.wav" , 2854 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_g_4.wav" , 903 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\yell_fear_3_voicea.wav" , 248 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_d_10.wav" , 844 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\flashbang_2_voiced.wav" , 1304 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_group_3_voiced.wav" , 1805 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_e_2.wav" , 3241 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\comm_supress_2_voiced.wav" , 2069 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\comm_suppress_3_voicea.wav" , 1051 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_7_voiceb.wav" , 2395 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_group_2_voiced.wav" , 861 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_specific_a_4.wav" , 3621 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\idle_alert_hear_al_1_voiced.wav" , 2051 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_alone_31_voiceb.wav" , 2056 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\regulator\\regulator_pickup_a_14.wav" , 508 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\searching_player_3_voicec.wav" , 2769 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_b_2.wav" , 1598 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\death_11_voicec.wav" , 877 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\alert_to_combat_alone_3_voiced.wav" , 162 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\death_2_voiceb.wav" , 549 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_a_2.wav" , 3646 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\helicopter_sight_8_voiceb.wav" , 2264 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\seek_target_a3.wav" , 1894 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_mercs_a_1.wav" , 2409 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_f_4.wav" , 3042 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\yell_attention_4_voicec.wav" , 178 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\compound\\compound_specific_d_1.wav" , 2453 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\catacombs\\templecatacombs_specific_a_5.wav" , 3308 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\yell_attention_4_voiceb.wav" , 177 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\idle_to_alert_heard_group_3_voicea.wav" , 306 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkerd\\combat_to_alert_gp_6_voiced.wav" , 1092 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_commchatter_a_6.wav" , 3539 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\val\\pain_21.wav" , 149 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\vehicle_in_2_voicea.wav" , 686 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\river\\templeriver_specific_a_1.wav" , 3494 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_a_4.wav" , 2750 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\death_11_voicea.wav" , 550 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\receive_fire_alone_18_voicec.wav" , 229 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\combat_alone_11_voiced.wav" , 1325 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\bunker\\bunker_direction_c_1bis.wav" , 3100 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_to_alert_alone_7_voiceb.wav" , 1493 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\idle_to_alert_alone_1_voicec.wav" , 219 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\mandown_group_2_voicec.wav" , 1078 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\combat_to_alert_alone_2_voicec.wav" , 1312 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mp_airstrip\\mp_airstrip_s1_d1.wav" , 3583 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\helicopter_sight_4_voicea.wav" , 2327 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\comm_flank_right_2r_voicea.wav" , 423 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicec\\pain_7_voicec.wav" , 174 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\idle_to_alert_heard_group_2_voiced.wav" , 395 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\archive\\archive_generic_b_8.wav" , 2580 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_to_alert_group_1_voicea.wav" , 380 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\mutant\\mutant_specific_c_3.wav" , 3139 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_l_2.wav" , 2610 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_k_2.wav" , 112 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\ruins\\templeruins_specific_d_1.wav" , 2290 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\coreworkera\\pain_3_voicea.wav" , 349 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\alert_to_combat_alone_2.wav" , 1159 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiceb\\combat_group_13_voiceb.wav" , 2515 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\mutant_readability\\idle_to_alert_heard_alone_1.wav" , 2080 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\boat\\boat_generic_b_3.wav" , 3620 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\training\\training_generic_k_4.wav" , 3572 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_14_voicea.wav" , 1520 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\swamp\\swamp_generic_h_4.wav" , 1716 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voiced\\grenade_1_group_voiced.wav" , 1884 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\alert_to_combat_group_4_voicea.wav" , 545 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_specific_c_2.wav" , 2994 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\rebellion\\rebellione_2process.wav" , 2811 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\helicopter_sight_2_voicea.wav" , 1202 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\research\\research_generic_d_2.wav" , 2928 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\treetop\\treetop_generic_a_1bis.wav" , 3616 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\pier\\pier_mercs_a_6.wav" , 3267 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\voicepacks\\voicea\\combat_alone_36_voicea.wav" , 2495 ) );
    pLookupLanguages->insert( SoundLookup::value_type( "languages\\missiontalk\\fort\\fort_generic_a_10.wav" , 1151 ) );

    IsInitialized = true;
    FunLog::Log( FUNLOG_BASIC , "Starting sound module | Finish" );
  }
}

void hkLoadSound::ShutdownSoundDB( ){
  FunLog::Log( FUNLOG_BASIC , "Stopping sound module | Begin" );

  pLookupLanguages->clear( );
  pLookupSounds->clear( );

  FunLog::Log( FUNLOG_BASIC , "Stopping sound module | Finish" );
}

static const char *SimilarLanguagesSound( const unsigned int i , const char *Input ){
  static const unsigned int SimilarityRatio = 15; // 20
  static float Current;
  static float Similarity;
  static float Lower;
  static float Upper;
  static unsigned int h;
  static unsigned int j;
  static unsigned int k;
  static unsigned int l;
  static const unsigned int m = 4; /* plenty generous */

  if( i > 4 ){ /* blacklisting and cases of zero */
    Current = aLanguages[ i ].duration;
    Similarity = Current * ( SimilarityRatio / 100.0f );
    Lower = Current - Similarity;
    Upper = Current + Similarity;

    for( h = i; h >= 0; h-- ){
      if( aLanguages[ h ].duration < Lower ){
        h++;
        break;
      }
    }

    for( j = i; j < aLanguagesLength; j++ ){
      if( aLanguages[ j ].duration > Upper ){
        j--;
        break;
      }
    }

    if( j - h > 1 ){
      l = 0;
      while( l++ < m ){
        k = Utility::getRandomInRange( h , j );
        if( !aLanguages[ k ].stereo ){
          return aLanguages[ k ].path;
        }
      }
    }
  }

  return Input;
}

static const char *SimilarMercChatterSound( unsigned int i , const char *Input ){
  static const unsigned int SimilarityRatio = 15; // 20
  static float Current;
  static float Similarity;
  static float Lower;
  static float Upper;
  static unsigned int h;
  static unsigned int j;
  static unsigned int k;
  static unsigned int l;
  static const unsigned int m = 4; /* plenty generous */

  if( i > 4 ){ /* blacklisting and cases of zero */
    Current = aLanguages[ i ].duration;
    Similarity = Current * ( SimilarityRatio / 100.0f );
    Lower = Current - Similarity;
    Upper = Current + Similarity;

    i = aLanguages[ i ].chat;

    for( h = i; h >= 0; h-- ){
      if( aLanguages[ aMercChatter[ h ] ].duration < Lower ){
        h++;
        break;
      }
    }

    for( j = i; j < aMercChatterLength; j++ ){
      if( aLanguages[ aMercChatter[ j ] ].duration > Upper ){
        j--;
        break;
      }
    }

    if( j - h > 1 ){
      l = 0;
      while( l++ < m ){
        k = Utility::getRandomInRange( h , j );
        if( !aLanguages[ aMercChatter[ k ] ].stereo ){
          return aLanguages[ aMercChatter[ k ] ].path;
        }
      }
    }
  }

  return Input;
}

static const char *SimilarRadioSound( unsigned int i , const char *Input ){
  static const unsigned int SimilarityRatio = 15; // 20
  static float Current;
  static float Similarity;
  static float Lower;
  static float Upper;
  static unsigned int h;
  static unsigned int j;
  static unsigned int k;
  static unsigned int l;
  static const unsigned int m = 4; /* plenty generous */

  if( i > 4 ){ /* blacklisting and cases of zero */
    Current = aLanguages[ i ].duration;
    Similarity = Current * ( SimilarityRatio / 100.0f );
    Lower = Current - Similarity;
    Upper = Current + Similarity;

    i = aLanguages[ i ].radio;

    for( h = i; h >= 0; h-- ){
      if( aLanguages[ aRadioChatter[ h ] ].duration < Lower ){
        h++;
        break;
      }
    }

    for( j = i; j < aRadioChatterLength; j++ ){
      if( aLanguages[ aRadioChatter[ j ] ].duration > Upper ){
        j--;
        break;
      }
    }

    if( j - h > 1 ){
      l = 0;
      while( l++ < m ){
        k = Utility::getRandomInRange( h , j );
        if( !aLanguages[ aRadioChatter[ k ] ].stereo ){
          return aLanguages[ aRadioChatter[ k ] ].path;
        }
      }
    }
  }

  return Input;
}

const char *hkLoadSound::RandomSound_Languages( ){ /* not necessarily safe for all uses */
  return aLanguages[ Utility::getRandomIndex( aLanguagesLength ) ].path;
}

#include "../GRETA/regexpr2.h"
#include "../GRETA/reimpl2.h"
#include "../GRETA/restack.h"
#include "../GRETA/syntax2.h"

static void NormalizePath( string &Path ){
  static const regex::rpattern rSlash( "\\/" , "\\\\" , regex::GLOBAL );
  static regex::subst_results code;
  std::transform( Path.begin( ) , Path.end( ) , Path.begin( ) , ::tolower );
  rSlash.substitute( Path , code );

  static const regex::rpattern rDuplicateExtension( "\\.([a-z]{3})\\.[a-z]{3}$" , "\\.$1" , regex::GLOBAL );
  static const regex::rpattern rNoPeriod( "([^\\.])([a-z]{3})$" , "$1\\.$2" , regex::NOCASE  );
  static const regex::rpattern rValidExtension( "[^\\.]{4}\\.[a-z]{3}$" , regex::NOCASE );
  static regex::match_results::backref_type BackRef;
  static regex::match_results Result;
  BackRef = rValidExtension.match( Path , Result );
  if( !BackRef.matched ){
    rDuplicateExtension.substitute( Path , code );
    BackRef = rNoPeriod.match( Path , Result );
    if( BackRef.matched ){
      rNoPeriod.substitute( Path , code );
    }
  }
}

#include <sstream>

const char *hkLoadSound::ProcessSound( const char *Input ){
  static SoundLookup mLookupLanguages;
  static SoundLookup mLookupSounds;

  static const regex::rpattern rIsLanguageCategory( "^languages" , regex::NOCASE );
  static const regex::rpattern rIsMission( "^languages.missiontalk" , regex::NOCASE );
  static const regex::rpattern rIsVoice( "^languages.voicepacks" , regex::NOCASE );
  static const regex::rpattern rIsVoicePackNotJack( "^languages.voicepacks.[^j]" , regex::NOCASE );

  static const regex::rpattern rMercChatter( "(_specific|_generic|mercs_)" , regex::NOCASE );

  static const regex::rpattern rAffirmative( "affirmative" , regex::NOCASE );
  static const regex::rpattern rAlarm( "alarm" , regex::NOCASE );
  static const regex::rpattern rAlertToCombat( "alert_to_combat" , regex::NOCASE );
  static const regex::rpattern rAlertToIdle( "alert_to_idle" , regex::NOCASE );
  static const regex::rpattern rCombatAlone( "combat_alone" , regex::NOCASE );
  static const regex::rpattern rCombatGroup( "combat_group" , regex::NOCASE );
  static const regex::rpattern rCombatToAlert( "combat_to_alert" , regex::NOCASE );
  static const regex::rpattern rCommandsAll( "comm_" , regex::NOCASE );
  static const regex::rpattern rDeath( "death_" , regex::NOCASE );
  static const regex::rpattern rGrenadeAny( "flashbang_|grenade_" , regex::NOCASE );
  static const regex::rpattern rIdleToAlert( "idle_to_alert_" , regex::NOCASE );
  static const regex::rpattern rManDown( "mandown_" , regex::NOCASE );
  static const regex::rpattern rPain( "pain_" , regex::NOCASE );
  static const regex::rpattern rReceiveFireAll( "receive_fire_" , regex::NOCASE );
  static const regex::rpattern rReinforce( "reinforce_" , regex::NOCASE );
  static const regex::rpattern rSearchAll( "searching_" , regex::NOCASE );
  static const regex::rpattern rVehicleIn( "vehicle_in_" , regex::NOCASE );
  static const regex::rpattern rYellAttention( "yell_attention_" , regex::NOCASE );
  static const regex::rpattern rYell( "yell_" , regex::NOCASE );

  static regex::match_results::backref_type BackRef;
  static regex::match_results_c Result;

  static string Normalized;
  static const LanguagesSoundDetail *Detail;

  if( IsInitialized ){
    BackRef = rIsLanguageCategory.match( Input , Result );
    if( BackRef.matched ){ /** languages... **/

      if( Effects::IsConversationRandomizer ){
        BackRef = rIsMission.match( Input , Result );
        if( BackRef.matched ){
          Normalized = string( Input );
          NormalizePath( Normalized );
          SoundLookup::iterator it;
          if( ( it = mLookupLanguages.find( Normalized.c_str( ) ) ) != mLookupLanguages.end( ) ){
            Detail = &aLanguages[ it->second ];
            if( Detail->radio >= 0 ){
              return SimilarRadioSound( it->second , Input );
            }
            else{
              return SimilarMercChatterSound( it->second , Input );
            }
          }
          else{
            std::ostringstream Stream;
            Stream << "ERROR: [IsConversationRandomizer] Could not find entry for [";
            Stream << Input;
            Stream << "] [";
            Stream << Normalized;
            Stream << "] ...";
            FunLog::Log( FUNLOG_DEBUG , Stream.str( ).c_str( ) );
          }
        }
      }

      if( Effects::IsValVoice ){
        BackRef = rIsVoicePackNotJack.match( Input , Result );
        if( BackRef.matched ){
          BackRef = rIsVoicePackNotJack.match( Input , Result );
          if( BackRef.matched ){ /* voice pack [optimized in order of expected usage] */
            const char *VoiceSound = NULL;

            BackRef = rPain.match( Input , Result );
            if( BackRef.matched ){ /* Pain */
              VoiceSound = aValerie_Pain[ Utility::getRandomIndex( aValerie_PainLength ) ];
            }
            else{
              BackRef = rCombatAlone.match( Input , Result );
              if( BackRef.matched ){ /* CombatAlone */
                VoiceSound = aValerie_CombatAlone[ Utility::getRandomIndex( aValerie_CombatAloneLength ) ];
              }
              else{
                BackRef = rCombatGroup.match( Input , Result );
                if( BackRef.matched ){ /* CombatGroup */
                  VoiceSound = aValerie_CombatGroup[ Utility::getRandomIndex( aValerie_CombatGroupLength ) ];
                }
                else{
                  BackRef = rReceiveFireAll.match( Input , Result );
                  if( BackRef.matched ){ /* ReceiveFireAll */
                    VoiceSound = aValerie_ReceiveFireAll[ Utility::getRandomIndex( aValerie_ReceiveFireAllLength ) ];
                  }
                  else{
                    BackRef = rIdleToAlert.match( Input , Result );
                    if( BackRef.matched ){ /* IdleToAlert */
                      VoiceSound = aValerie_IdleToAlert[ Utility::getRandomIndex( aValerie_IdleToAlertLength ) ];
                    }
                    else{
                      BackRef = rAlertToCombat.match( Input , Result );
                      if( BackRef.matched ){ /* AlertToCombat  */
                        VoiceSound = aValerie_AlertToCombat[ Utility::getRandomIndex( aValerie_AlertToCombatLength ) ];
                      }
                      else{
                        BackRef = rAffirmative.match( Input , Result );
                        if( BackRef.matched ){ /* Affirmative */
                          VoiceSound = aValerie_Affirmative[ Utility::getRandomIndex( aValerie_AffirmativeLength ) ];
                        }
                        else{
                          BackRef = rCommandsAll.match( Input , Result );
                          if( BackRef.matched ){ /* CommandsAll */
                            VoiceSound = aValerie_CommandsAll[ Utility::getRandomIndex( aValerie_CommandsAllLength ) ];
                          }
                          else{
                            BackRef = rManDown.match( Input , Result );
                            if( BackRef.matched ){ /* ManDown */
                              VoiceSound = aValerie_ManDown[ Utility::getRandomIndex( aValerie_ManDownLength ) ];
                            }
                            else{
                              BackRef = rDeath.match( Input , Result );
                              if( BackRef.matched ){ /* Death */
                                VoiceSound = aValerie_Death[ Utility::getRandomIndex( aValerie_DeathLength ) ];
                              }
                              else{
                                BackRef = rYellAttention.match( Input , Result ); /* must precede generic yell */
                                if( BackRef.matched ){ /* YellAttention */
                                  VoiceSound = aValerie_YellAttention[ Utility::getRandomIndex( aValerie_YellAttentionLength ) ];
                                }
                                else{
                                  BackRef = rYell.match( Input , Result );
                                  if( BackRef.matched ){ /* Yell */
                                    VoiceSound = aValerie_Yell[ Utility::getRandomIndex( aValerie_YellLength ) ];
                                  }
                                  else{
                                    BackRef = rGrenadeAny.match( Input , Result );
                                    if( BackRef.matched ){ /* GrenadeAny */
                                      VoiceSound = aValerie_GrenadeAny[ Utility::getRandomIndex( aValerie_GrenadeAnyLength ) ];
                                    }
                                    else{
                                      BackRef = rAlarm.match( Input , Result );
                                      if( BackRef.matched ){ /* Alarm */
                                        VoiceSound = aValerie_Alarm[ Utility::getRandomIndex( aValerie_AlarmLength ) ];
                                      }
                                      else{
                                        BackRef = rReinforce.match( Input , Result );
                                        if( BackRef.matched ){ /* Reinforce */
                                          VoiceSound = aValerie_Reinforce[ Utility::getRandomIndex( aValerie_ReinforceLength ) ];
                                        }
                                        else{
                                          BackRef = rSearchAll.match( Input , Result );
                                          if( BackRef.matched ){ /* SearchAll */
                                            VoiceSound = aValerie_SearchAll[ Utility::getRandomIndex( aValerie_SearchAllLength ) ];
                                          }
                                          else{
                                            BackRef = rCombatToAlert.match( Input , Result );
                                            if( BackRef.matched ){ /* CombatToAlert */
                                              VoiceSound = aValerie_CombatToAlert[ Utility::getRandomIndex( aValerie_CombatToAlertLength ) ];
                                            }
                                            else{
                                              BackRef = rAlertToIdle.match( Input , Result );
                                              if( BackRef.matched ){ /* AlertToIdle */
                                                VoiceSound = aValerie_AlertToIdle[ Utility::getRandomIndex( aValerie_AlertToIdleLength ) ];
                                              }
                                              else{
                                                BackRef = rVehicleIn.match( Input , Result );
                                                if( BackRef.matched ){ /* VehicleIn */
                                                  VoiceSound = aValerie_VehicleIn[ Utility::getRandomIndex( aValerie_VehicleInLength ) ];
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }

            if( VoiceSound != NULL ){
              return VoiceSound;
            }
            else{
              FunLog::Log( FUNLOG_DEBUG , "- [Val]" );
              FunLog::Log( FUNLOG_DEBUG , "ERROR: UNHANDLED VOICE" );
              FunLog::Log( FUNLOG_DEBUG , Input );
            }
          }
        }
      }

      if( Effects::IsLanguagesRandomizer ){
        Normalized = string( Input );
        NormalizePath( Normalized );

        SoundLookup::iterator it;
        if( ( it = mLookupLanguages.find( Normalized.c_str( ) ) ) != mLookupLanguages.end( ) ){
          return SimilarLanguagesSound( it->second , Input );
        }
        else{
          std::ostringstream Stream;
          Stream << "ERROR: [IsLanguagesRandomizer] Could not find entry for [";
          Stream << Input;
          Stream << "] [";
          Stream << Normalized;
          Stream << "] ...";
          FunLog::Log( FUNLOG_DEBUG , Stream.str( ).c_str( ) );
        }
      }

    }
  }
  else if( strcmp( Input , InitTrigger ) ){
    pLookupLanguages = &mLookupLanguages;
    pLookupSounds = &mLookupSounds;
    StartupSoundDB( true );
  }

  return Input;
}
#include "../FunCry/FunCry.h"
#include "../CryCommon/ISound.h"

bool FunCry::PlaySound( const char *Target ){
  #ifndef FUNCRY_NO_SOUND
    FunLog::Log( FUNLOG_DEBUG , "PlaySound( ) | Begin" );

    const char *Path = Target != NULL && Target != "" ? Target : hkLoadSound::RandomSound_Languages( );
    ISound *Clip = FunCry::Sound->LoadSound( Path , FLAG_SOUND_2D | FLAG_SOUND_STEREO );
    if( Clip ){
      Clip->SetVolume( 100 );
      Clip->Play( );

      #ifdef FUNCRY_DETAIL_LOG
        FunLog::Log( FUNLOG_DETAIL , ( "Play sound [ " + Path + " ] Success" ).c_str( ) );
      #else
        FunLog::Log( FUNLOG_DEBUG , ( string( "Play sound [ " ) + Path + string( " ] Success" ) ).c_str( ) );
      #endif

      return true;
    }
    else{
      FunLog::Log( FUNLOG_PROBLEM , ( string( "Play sound [ " ) + Path + string( " ] Failure" ) ).c_str( ) );

      return false;
    }

    FunLog::Log( FUNLOG_DEBUG , "PlaySound( ) | Finish" );
  #endif

  return true;
}
