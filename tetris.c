/*
* tetris.c (1.0)
* ��Ϸ��ʵ��
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-3-4
*/

#include "tetris.h"
#include "main.h"

BLOCK curBlock;             //��ǰ����
BLOCK nextBlock;            //��һ������
int BLOCKS_TOP = 0;         //��ǰblocks����ߵ�
int TotalScore = 0;         //��Ϸ����
char BG_BOARD[ROW][COL+1];  //��Ϸ������־��0��δ��ռ�ã� 1���ѱ�ռ��

/* ���巽������(����19��) */
const SHAPE BLOCK_PATTERN[MAX_BLOCKS] = {
/* 0 - 3
 *  �� �� �� ��                �� �� �� ��                �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                �� �� �� ��                �� �� �� ��
 */
  {1, 2, 0x88, 0xc0, 1}, {2, 1, 0xe8, 0x00, 2}, {1, 2, 0xc4, 0x40, 3}, {2, 1, 0x2e, 0x00, 0},
/* 4 - 7
 *  �� �� �� ��                �� �� �� ��                �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                �� �� �� ��                �� �� �� ��
 */
  {1, 2, 0x44, 0xc0, 5}, {2, 1, 0x8e, 0x00, 6}, {1, 2, 0xc8, 0x80, 7}, {2, 1, 0xe2, 0x00, 4},
/* 8 - 9
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 */
  {1, 2, 0x8c, 0x40, 9}, {2, 1, 0x6c, 0x00, 8},
/* 10 - 11
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 */
  {1, 2, 0x4c, 0x80, 11}, {2, 1, 0xc6, 0x00, 10},
/* 12 - 15
 *  �� �� �� ��                �� �� �� ��                 �� �� �� ��                 �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                 �� �� �� ��                 �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                 �� �� �� ��                 �� �� �� ��
 *  �� �� �� ��                �� �� �� ��                 �� �� �� ��                 �� �� �� ��
 */
  {2, 1, 0x4e, 0x00, 13}, {1, 2, 0x8c, 0x80, 14}, {2, 1, 0xe4, 0x00, 15}, {1, 2, 0x4c, 0x40, 12},
/* 16 - 17
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 *  �� �� �� ��                �� �� �� ��
 */
  {0, 3, 0x88, 0x88, 17}, {3, 0, 0xf0, 0x00, 16},
/* 18
 *  �� �� �� ��
 *  �� �� �� ��
 *  �� �� �� ��
 *  �� �� �� ��
 */
  {2, 2, 0xcc, 0x00, 18}
};

/* ��ʼ����ǰ����BLOCKS */
void initBlocks(void){
    curBlock.x = FIRST_BLOCK_X;
    curBlock.y = 0;
    curBlock.index = JR_randomIn(18);

    nextBlock.x = FIRST_BLOCK_X;
    nextBlock.y = 0;
    nextBlock.index = JR_randomIn(18);
}

/* �����µķ��� */
void getBlocks(int n){
    curBlock.x = nextBlock.x;
    curBlock.y = nextBlock.y;
    curBlock.index = nextBlock.index;

    if(n < 0 || n > 18)
        nextBlock.index = JR_randomIn(18);
    else
        nextBlock.index = n;
}

/* ��ʼ���������� */
void initBG(void){
    int i = 0, j = 0;
    for(i=0; i<ROW; i++)
        for(j=0; j<=COL; j++)
            BG_BOARD[i][j] = 0;
}

/* ���ñ�������
 * n=1:���ã� n=0:���
 */
void setBG(BLOCK b, int n){
    int i = 0, j = 0;
    int x = 0, y = 0;

    for(i=0; i<2; i++)
        for(j=0; j<8; j++)
            if(BLOCK_PATTERN[b.index].box[i] & (0x80>>j)){
                x = b.x + (j%4) * 2;
                y = b.y + (j/4) + 2*i;
                BG_BOARD[y][x/2] = n;
            }
}

/* ��Ⱦ��Ϸ���� */
void DrawBG(void){
    int i = 0, j = 0;
    JR_SetCursorStart();
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++)
            if(!BG_BOARD[i][j])
                printf("%s", BG);
            else
                printf("%s", BODY);
        printf("\t\t\t\t\t\t\n");
    }
    JR_SetCursor(0, ROW+1);
}

/* ���blocks�Ƿ�Ϸ� */
int checkBlock(BLOCK b){
    int i = 0, j = 0;
    //���߽�
    if( b.x < 0
     || (b.x + 8 -  BLOCK_PATTERN[b.index].offset_r*2) > COL*2
     || b.y > (ROW-4+BLOCK_PATTERN[b.index].offset_d)
       )
       return 0;

    //�����ײ
    for(i=0; i<2; i++){
        for(j=0; j<8; j++){
            if( (BLOCK_PATTERN[b.index].box[i] & (0x80 >> j))   //ת�����BLOCK�иõ�Ϊ��ʵ��
               && BG_BOARD[b.y+(j/4)+2*i][b.x/2+(j%4)]          //��ǰ�㣬BGΪ��ʵ��
                )
                return 0;
        }
    }
    return 1;
}

/*
 * ��ⷽ���Ƿ���԰���ָ�������ƶ�
 * 1:LEFT, 2:RIGHT, 3:DOWN
 */
int canMoveTo(int dir){
    BLOCK b;
    b.x = curBlock.x;
    b.y = curBlock.y;
    b.index = curBlock.index;
    switch(dir){
        case 1:     //LEFT
            b.x -= 2;
            break;
        case 2:     //RIGHT
            b.x += 2;
            break;
        case 3:     //DOWN
            b.y += 1;
            break;
    }
    setBG(curBlock, 0);
    if(checkBlock(b)){
        setBG(curBlock, 1);
        return 1;
    }
    setBG(curBlock, 1);
    return 0;
}

/*
 * ���ݷ����ƶ�����һ��
 * 1:LEFT, 2:RIGHT, 3:DOWN
*/
int setBlocks(int dir){
    BLOCK b;
    b.x = curBlock.x;
    b.y = curBlock.y;
    b.index = curBlock.index;
    switch(dir){
        case 1:     //LEFT
            b.x -= 2;
            break;
        case 2:     //RIGHT
            b.x += 2;
            break;
        case 3:     //DOWN
            b.y += 1;
            break;
    }
    setBG(curBlock, 0);
    if(checkBlock(b)){
        curBlock.x = b.x;
        curBlock.y = b.y;
        setBG(curBlock, 1);
        return 1;
    }
    setBG(curBlock, 1);
    return 0;
}

/* ���� */
void changeBlocks(void){
    BLOCK b;
    b.x = curBlock.x;
    b.y = curBlock.y;
    b.index = BLOCK_PATTERN[curBlock.index].next;
    setBG(curBlock, 0);
    if(checkBlock(b)){
        curBlock.index = b.index;
    }
    setBG(curBlock, 1);
}

/* ������Ϸ���(����/GameOver) */
int checkResult(void){
    int i = 0, j = 0, k = 0;
    int flag = 1;
    int counter = 1;

    BLOCKS_TOP = BLOCKS_TOP > curBlock.y ? curBlock.y : BLOCKS_TOP;
    BLOCKS_TOP = BLOCKS_TOP > 0 ? BLOCKS_TOP : 0;

    //����
    for(i=ROW-1; i>=BLOCKS_TOP; i--){
        flag = 1;
        for(j=0; j<COL; j++){
            if(!BG_BOARD[i][j]){
                flag = 0;
                j = COL;
            }
        }
        if(flag){
            for(j=i; j>BLOCKS_TOP; j--){
                for(k=0; k<COL; k++)
                    BG_BOARD[j][k] = BG_BOARD[j-1][k];
            }
            for(k=0; k<COL; k++)
                    BG_BOARD[BLOCKS_TOP][k] = 0;
            i = ROW;
            BLOCKS_TOP ++;
            //����
            TotalScore += (counter ++) * 100;
        }
    }
    DrawBG();

    if(BLOCKS_TOP <= 0)
        return 0;

    return 1;
}
