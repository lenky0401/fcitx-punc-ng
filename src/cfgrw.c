
#include <stdio.h>
#include <stdlib.h>

#include "cfgrw.h"

#include "iniparser/iniparser.h"

static char *getCfgFilePath(const char *fileName)
{
#define BUFF_SIZE (256)
	static char usrPath[BUFF_SIZE] = {0};
	char *homePath = getenv("HOME");
	snprintf(usrPath, BUFF_SIZE, "%s/.config/SogouPY/%s", homePath, fileName);
	return usrPath;
}

char *getCfgValueString(const char *fileName, const char *fieldName, char *defaultvalue)
{
    char *s;
    dictionary *ini;
#define VALUE_SIZE (128)
	static char val[VALUE_SIZE] = {0};

    if ((ini = iniparser_load(getCfgFilePath(fileName))) == NULL)
        return defaultvalue;

    if ((s = iniparser_getstring(ini, fieldName, defaultvalue)) == NULL)
    {
        iniparser_freedict(ini);
        return defaultvalue;
    }

    strcpy(val, s);

    iniparser_freedict(ini);

    return val;    
}

int getCfgValueBool(const char *fileName, const char *fieldName, int defaultvalue)
{
    int val;
    dictionary *ini;

    if ((ini = iniparser_load(getCfgFilePath(fileName))) == NULL)
        return defaultvalue;

    val = iniparser_getboolean(ini, fieldName, defaultvalue);

    iniparser_freedict(ini);

    return val;    
}


