#ifndef _MENU_H
#define _MENU_H
#include <sqlite3.h>
#define DATABASE "stu.db"

void menu();
sqlite3 *open_create(void );
sqlite3 *sqlite_init();
void info_show_st(sqlite3 *db);
void stu_find(sqlite3 *db);
void stu_update(sqlite3 *db);
void stu_insert(sqlite3 *db);

#endif
