/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#include "FunCry.h"
#include "Logging.h"

void FunLog::Log( unsigned int Code , const char *Msg ){
  bool OK = false;
  //string Prefix = "[INVALID] ";
  switch( Code ){
    case FUNLOG_BASIC : {
      #ifdef FUNCRY_BASIC_LOG
        OK = true;
        //Prefix = "[BASIC] ";
      #endif
    }
    break;
    case FUNLOG_DETAIL : {
      #ifdef FUNCRY_DETAIL_LOG
        OK = true;
        //Prefix = "[DETAIL] ";
      #endif
    }
    break;
    case FUNLOG_RELEASE : {
      #ifdef FUNCRY_RELEASE_LOG
        OK = true;
        //Prefix = "[RELEASE] ";
      #endif
    }
    break;
    case FUNLOG_DEBUG : {
      #ifdef FUNCRY_DEBUG_LOG
        OK = true;
        Prefix = "[DEBUG] ";
      #endif
    }
    break;
    case FUNLOG_PROBLEM : {
      OK = true;
      //Prefix = "[PROBLEM] ";
    }
    break;
    case FUNLOG_ALWAYS : {
      OK = true;
      //Prefix = "";
    }
    break;
  }
  if(
    OK
    &&
    strcmp( Msg , "_Reset_Log_" ) != 0
    &&
    strcmp( Msg , "_Dump_Log_" ) != 0
  ){
    CryLogAlways( "%s" , ( string( "FunCry: " ) /* + Prefix */ + Msg ).c_str( ) );
  }
}
