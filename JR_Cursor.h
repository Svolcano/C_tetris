/*
* JR_Cursor.h (1.0)
* Console���Ĳ���
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-16
*/

#ifndef JR_CURSOR_H
#define JR_CURSOR_H

#define MAXCOL  79  //[0 - 79]


/* ������Ƶ�ָ��λ��*/
void JR_SetCursor(int x, int y);

/* ������Ƶ����Ͻ� */
void JR_SetCursorStart();

/* ����������ƶ�N�� */
void JR_SetCursorRight(int n);

/* ����������ƶ�N�� */
void JR_SetCursorLeft(int n);

/* ����������ƶ�N�� */
void JR_SetCursorUp(int n);

/* ����������ƶ�N�� */
void JR_SetCursorDown(int n);

#endif
