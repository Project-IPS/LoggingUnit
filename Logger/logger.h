#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <string>
#include"log_settings.h"
// #define SET_LOG

#ifdef SET_LOG
  #define LOG(f_, ...) vprintf(((std::string)f_+"\n").c_str(), ##__VA_ARGS__)
  #define LOGV(f_, ...) logv(f_, ##__VA_ARGS__)
  #define LOGI(f_, ...) logi(f_, ##__VA_ARGS__)
  #define LOGW(f_, ...) logw(f_, ##__VA_ARGS__)
  #define LOGE(f_, ...) loge(f_, ##__VA_ARGS__)

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
#else
  #define LOG(f_, ...) ((void)0)
  #define LOGI(f_, ...) ((void)0)
  #define LOGE(f_, ...) ((void)0)
  #define LOGV(f_, ...) ((void)0)
  #define LOGW(f_,...) ((void)0)
  #endif
#endif