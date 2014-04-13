
#ifndef _CFG_RW_H_
#define _CFG_RW_H_

char *getCfgValueString(const char *fileName, const char *fieldName, char *defaultvalue);
int getCfgValueBool(const char *fileName, const char *fieldName, int defaultvalue);


#endif
