/*
* tetris.h (1.0)
* ������Դ����
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-3-4
*/

#ifndef TETRIS_H
#define TETRIS_H

#define MAX_BLOCKS  19      //19�ַ�����״
#define FIRST_BLOCK_X   6   //��һ�������ķ����X����

extern const char *BG;      //����ͼ��
extern const char *BODY;    //����ͼ��

/* ����ṹ */
typedef struct _SHAPE{
    int offset_d;   //��ƫ����
    int offset_r;   //��ƫ����
    char box[2];    //16λ,ÿ4λ����ʾһ�������һ�У��� "0x88,0xc0"
    int next;       //�¸����η�����±�
}SHAPE;

/* һ������ */
typedef struct _BLOCK{
    int x;      //���Ͻ�����
    int y;      //
    int index;  //�������ͣ�BLOCK_PATTERN���±�:0-18��
}BLOCK;


/* ��ʼ����ǰ����BLOCKS */
void initBlocks(void);

/* �����µķ���
 * nΪ��0��18��ʱ��block����ֵΪn
 * ����blockȡ��� */
void getBlocks(int n);

/* ��ʼ���������� */
void initBG(void);

/* ���ñ�������
 * n=1:���ã� n=0:���
 */
void setBG(BLOCK b, int n);

/* ��Ⱦ��Ϸ���� */
void DrawBG(void);

/* ���blocks�Ƿ�Ϸ� */
int checkBlock(BLOCK b);

/*
 * ��ⷽ���Ƿ���԰���ָ�������ƶ�
 * 1:LEFT, 2:RIGHT, 3:DOWN
 */
int canMoveTo(int dir);

/*
 * ���ݷ����ƶ�����һ��
 * 1:LEFT, 2:RIGHT, 3:DOWN
*/
int setBlocks(int dir);

/* ���� */
void changeBlocks(void);

/* ������Ϸ���(����/GameOver) */
int checkResult(void);

#endif
