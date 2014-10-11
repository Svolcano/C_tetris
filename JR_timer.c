/*
* JR_timer.c (1.0)
* ���߳��еĶ�ʱ��
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-11
*/

#include "JR_timer.h"

static unsigned long JR_next_time=0xFFFFFFFF;
static unsigned long JR_Interval = 1000;	//��ʱ���������λ���룬Ĭ��1����

/* ��ȡCPUʱ��ms */
unsigned long JR_GetTicks(void){
    return clock();
}

/* ������ʱ�� */
void startTimer(void){
    JR_next_time = JR_GetTicks() + JR_Interval;
}

/* ֹͣ��ʱ�� */
void stopTimer(void){
    JR_next_time = 0xFFFFFFFF;
}

/* �趨��ʱ����� */
void setTimer(int ms){
    JR_Interval = ms;
}

/* ÿ��JR_Interval����һ�� */
void ontimer(void){
    if(JR_next_time > JR_GetTicks()) return ;
    JR_next_time += JR_Interval;

    //do something here
    extern void mainTimer(); //define in the main.c
    mainTimer();
}
