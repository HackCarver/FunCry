/*
** FunCry
** 
** FunCry is licensed under the FunCry license
*/

#define FUNLOG_BASIC    0
#define FUNLOG_DETAIL   1
#define FUNLOG_RELEASE  2
#define FUNLOG_DEBUG    3
#define FUNLOG_PROBLEM  4
#define FUNLOG_ALWAYS   5
#define FUNLOG_LUA      6

namespace FunLog{
  extern void Log( unsigned int , const char * );
}
