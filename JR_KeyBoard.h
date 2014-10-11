/*
* JR_KeyBoard.h (1.0)
* ���̰������
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-14
*/

#ifndef JR_KEYBOARD_H
#define JR_KEYBOARD_H

/******** ��ֵ���� ********/
//���ϼ�ֵǰ�ò���
#define JR_KEY_PRE_F        0
#define JR_KEY_PRE_DIR      224

//�����
#define JR_KEY_UP           224072
#define JR_KEY_LEFT         224075
#define JR_KEY_RIGHT        224077
#define JR_KEY_DOWN         224080

//���Ƽ�
#define JR_KEY_ENTER        13
#define JR_KEY_SPACE        32
#define JR_KEY_ESC          27
#define JR_KEY_TAB          09
#define JR_KEY_BACKSPACE    08

//F����F1��F12�� F8����)
#define JR_KEY_F1           -59
#define JR_KEY_F2           -60
#define JR_KEY_F3           -61
#define JR_KEY_F4           -62
#define JR_KEY_F5           -63
#define JR_KEY_F6           -64
#define JR_KEY_F7           -65
//#define JR_KEY_F8           -59
#define JR_KEY_F9           -67
#define JR_KEY_F10          -68

#define JR_KEY_F11          2240133     //pre��ֵΪ224
#define JR_KEY_F12          2240134     //pre��ֵΪ224

/* ��⵱ǰ�Ƿ��м������룬�����¼�ֵJR_KeyValue */
int JR_AnyKeys(void);

/* ���ؼ�ֵASCII�� �� ��Ӧ�Զ����ֵ */
int JR_GetKeyNum(void);

/* ���ָ�����Ƿ��а��� */
int JR_IsKeyDown(const int key);


#endif
