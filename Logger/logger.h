#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <string>
#include"log_settings.h"


#ifndef LOG
#define LOG(f_, ...) vprintf(((std::string)f_+"\n").c_str(), ##__VA_ARGS__)
#endif

#ifndef LOGV
#define LOGV(f_, ...) logv(f_, ##__VA_ARGS__)
#endif

#ifndef LOGI
#define LOGI(f_, ...) logi(f_, ##__VA_ARGS__)
#endif

#ifndef LOGW
#define LOGW(f_, ...) logw(f_, ##__VA_ARGS__)
#endif

#ifndef LOGE
#define LOGE(f_, ...) loge(f_, ##__VA_ARGS__)
#endif

void logv(const char *format, ...){
  va_list args;
  
  if(LOG_SETTINGS == "verbose"){
    va_start( args, format );
    LOG(format, args); 
    va_end( args );
  }
}

void logi(const char *format, ...){
  va_list args;
  
  if(LOG_SETTINGS == "verbose" || LOG_SETTINGS=="events"){
    va_start( args, format );
    LOG(format, args); 
    va_end( args );
  }
}

void logw(const char *format, ...){
  va_list args;
  
  if(LOG_SETTINGS == "verbose" || LOG_SETTINGS=="events" || LOG_SETTINGS=="warnings"){
    va_start( args, format );
    LOG(format, args); 
    va_end( args );
  }
}

void loge(const char *format, ...){
  va_list args;
  
  if(LOG_SETTINGS == "verbose" || LOG_SETTINGS=="events" || LOG_SETTINGS=="warnings" || LOG_SETTINGS=="errors"){
    va_start( args, format );
    LOG(format, args); 
    va_end( args );
  }
}

#endif