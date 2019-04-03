#pragma once
#ifndef __CMDAPP_h__
#define __CMDAPP_h__

#ifdef CMDAPP_EXPORTS
#define CMDAPP_API __declspec(dllexport)
#else
#define CMDAPP_API __declspec(dllimport)
#endif // CMDLIBRARYDLL_EXPORTS

#include "cmdNode.h"

CMDAPP_API  NODE insert_file(string);
CMDAPP_API void delete_file(string);
CMDAPP_API  NODE insert_directory(string);
CMDAPP_API void delete_directory(string);
CMDAPP_API void clear_screen();
CMDAPP_API NODE change_directory(string);
CMDAPP_API string pwd();
CMDAPP_API string* list_of_files();

#endif // __CMDLIBRARY_h__