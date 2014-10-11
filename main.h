/*
* main.h (1.0)
* ��Ϸ��Դ����
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-3-4
*/

#ifndef MAIN_H
#define MAIN_H

#include "JR_Cursor.h"
#include "JR_KeyBoard.h"
#include "JR_Random.h"
#include "JR_timer.h"
#include "tetris.h"

#define ROW 15
#define COL 10

extern BLOCK curBlock;  //��ǰ����
extern BLOCK nextBlock; //��һ������
extern const SHAPE BLOCK_PATTERN[MAX_BLOCKS];
extern char BG_BOARD[ROW][COL+1]; //��Ϸ������־��0��δ��ռ�ã� 1���ѱ�ռ��
extern int BLOCKS_TOP;  //��ǰblocks����ߵ�
extern int TotalScore;  //��Ϸ����

/* ��Ϸ״̬ */
typedef enum _STATUS{
    WELCOME, GAMING, DIE, PAUSE, STOP
}STATUS;

/* ���� */
typedef enum _DIRECTION{
    NONE, LEFT, RIGHT, DOWN
}DIRECTION;

/* ��ĻԪ�� */
typedef struct _SHOWNODE{
    int x;
    int y;
    char text[3];
}SHOWNODE;


#endif
