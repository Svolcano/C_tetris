/*
* JR_Cursor.c (1.0)
* Console���Ĳ���
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-16
*/

#include "JR_Cursor.h"
#include <windows.h>


/* ������Ƶ�ָ��λ�� */
void JR_SetCursor(int x, int y){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hOut, pos);
}

/* ������Ƶ����Ͻ� */
void JR_SetCursorStart(){
    JR_SetCursor(0, 0);
}

/* ����������ƶ�N�� */
void JR_SetCursorRight(int n){
    COORD pos= {0, 0};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO cinfo = malloc(sizeof(PCONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(hOut, cinfo);
    pos.X = cinfo->dwCursorPosition.X + n;
    pos.Y = cinfo->dwCursorPosition.Y;
    SetConsoleCursorPosition(hOut, pos);
    free(cinfo);
}

/* ����������ƶ�N�� */
void JR_SetCursorLeft(int n){
    COORD pos= {0, 0};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO cinfo = malloc(sizeof(PCONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(hOut, cinfo);
    pos.X = cinfo->dwCursorPosition.X - n;
    pos.Y = cinfo->dwCursorPosition.Y;
    SetConsoleCursorPosition(hOut, pos);
    free(cinfo);
}

/* ����������ƶ�N�� */
void JR_SetCursorUp(int n){
    COORD pos= {0, 0};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO cinfo = malloc(sizeof(PCONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(hOut, cinfo);
    pos.X = cinfo->dwCursorPosition.X;
    pos.Y = cinfo->dwCursorPosition.Y - n;
    SetConsoleCursorPosition(hOut, pos);
    free(cinfo);
}

/* ����������ƶ�N�� */
void JR_SetCursorDown(int n){
    COORD pos= {0, 0};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_SCREEN_BUFFER_INFO cinfo = malloc(sizeof(PCONSOLE_SCREEN_BUFFER_INFO));
    GetConsoleScreenBufferInfo(hOut, cinfo);
    pos.X = cinfo->dwCursorPosition.X;
    pos.Y = cinfo->dwCursorPosition.Y + n;
    SetConsoleCursorPosition(hOut, pos);
    free(cinfo);
}
