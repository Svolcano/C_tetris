/*
* JR_timer.h (1.0)
* ���߳��еĶ�ʱ��
*
* By Eric-JR Chen
* diamont1001@163.com
* 2011-2-11
*/

#ifndef JR_TIMER_H
#define JR_TIMER_H


/* ��ȡCPUʱ��ms */
unsigned long JR_GetTicks(void);

/* ������ʱ�� */
void startTimer(void);

/* ֹͣ��ʱ�� */
void stopTimer(void);

/* �趨��ʱ����� */
void setTimer(int ms);

/* ÿ��Interval����һ�� */
void ontimer(void);

#endif
