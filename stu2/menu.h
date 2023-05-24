#ifndef _MENU_H
#define _MENU_H

#define DATABASE "stu.db"

void menu();
int open_create(sqlite3 *db);
void info_show_st(sqlite3 *db);
void stu_find(sqlite3 *db);
void stu_update(sqlite3 *db);
void stu_insert(sqlite3 *db);

#endif
