#ifndef _MENU_H
#define _MENU_H

#define DATABASE "stu.db"

void menu();
void info_show_st(sqlite3 *db);
void stu_find(sqlite3 *db);
void stu_update(sqlite3 *db);
void stu_insert(sqlite3 *db);

#endif
