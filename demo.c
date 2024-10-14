#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct jincheng_type
{
	int pid;
	int youxian; // 优先级
	int daxiao;
	int zhuangtai;
	char info[10];
};
struct jincheng_type neicun[20];
int shumu = 0, guaqi = 0, pid, flag = 0;
void create()
{
	if (shumu >= 20)
		printf("\n内存已满，请先换出或杀死进程\n");
	else
	{
		int i;
		for (i = 0; i < 20; i++)
		{
			if (neicun[i].zhuangtai == 0)
				break; // 不存在进程
		}
		printf("\n请输入新进程pid\n");
		scanf("%d", &(neicun[i].pid));
		for (int j = 0; j < i; j++)
			　if (neicun[i].pid == neicun[j].pid)
			{
				　 printf("\n该进程已存在\n");
				return;
			}
		printf("\n请输入新进程优先级\n");
		scanf("%d", &(neicun[i].youxian));
		printf("\n请输入新进程大小\n");
		scanf("%d", &(neicun[i].daxiao));
		printf("\n请输入新进程内容\n");
		scanf("%s", &(neicun[i].info));
		　 neicun[i].zhuangtai = 1;
		shumu++;
	}
}
void run()
{
	for (int i = 0; i < 20; i++)
	{
		if (neicun[i].zhuangtai == 1)
		{
			printf("\npid=%d\t", neicun[i].pid);
			printf("youxian=%d\t", neicun[i].youxian);
			printf("daxiao=%d\t", neicun[i].daxiao);
			printf("zhuangtai=%d\t", neicun[i].zhuangtai);
			printf("info=%s", neicun[i].info);
			flag = 1;
		}
	}
	if (!flag)
		printf("\n当前没有运行进程\n");
}
void huanchu()
{
	if (!shumu)
	{
		printf("当前没有运行进程\n");
		return;
	}
	printf("\n输入换出进程的ID值");
	scanf("%d", &pid);
	for (int i = 0; i <= 20; i++)
	{
		if (pid == neicun[i].pid)
		{
			if (neicun[i].zhuangtai == 1)
			{
				neicun[i].zhuangtai = 2; // 挂起
				guaqi++;
				printf("\n已经成功换出进程");
			}
			else if (neicun[i].zhuangtai == 0)
				printf("\n要换出的进程不存在\n");
			else
				printf("\n要换出的进程已被挂起\n");
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		printf("\n要换出的进程不存在\n"); // flag用来标注进程是否存在
}
void kill()
{
	if (!shumu)
	{
		printf("当前没有运行的进程\n");
		return;
	}
	printf("\n输入要杀死进程的ID值");
	scanf("%d", &pid);
	for (int i = 0; i < 20; i++)
	{
		if (pid == neicun[i].pid)
		{
			if (neicun[i].zhuangtai == 1)
			{
				neicun[i].zhuangtai = 0;
				shumu--;
				printf("\n已成功杀死进程\n");
			}
			else if (neicun[i].zhuangtai == 0)
				printf("\n要杀死的进程不存在\n");
			else
				printf("\n要杀死的进程已被挂起\n");
			flag = 1;
			break;
		}
	}
	if (!flag)
		printf("\n要杀死的进程不存在\n"); // flag判断进程存不存在
}
void huanxing()
{
	if (!shumu)
	{
		printf("\n当前没有运行进程");
		return;
	}
	if (!guaqi)
	{
		printf("\n当前没有挂起进程\n");
		return;
	}
	printf("\n 输入pid: \n");
	scanf("%d", &pid);
	for (int i = 0; i < 20; i++)
	{
		if (pid == neicun[i].pid)
		{
			flag = 0;
			if (neicun[i].zhuangtai == 2)
			{
				neicun[i].zhuangtai = 1;
				guaqi--;
				printf("\n已经成功唤醒进程\n");
			}
			else if (neicun[i].zhuangtai == 0)
				printf("\n要唤醒进程不存在\n");
			else
				printf("\n要唤醒进程已被挂起\n");
			break;
		}
	}
	if (flag)
		printf("\n要唤醒进程不存在\n");
}
int main()
{
	int n = 1;
	int num;
	for (int i = 0; i < 20; i++)
		neicun[i].zhuangtai = 0;
	while (n)
	{
		printf("\n***********************************************************************");
		printf("\n*                        进程演示系统                                 *");
		printf("\n***********************************************************************");
		printf("\n              1.创建新的进程                  2.查看运行进程           ");
		printf("\n              3.换出某个进程                  4.杀死运行进程           ");
		printf("\n              5.唤醒某个进程                  6.退出系统               ");
		printf("\n***********************************************************************");
		printf("\n请选择(1~6)\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			create();
			break;
		case 2:
			run();
			break;
		case 3:
			huanchu();
			break;
		case 4:
			kill();
			break;
		case 5:
			huanxing();
			break;
		case 6:
			exit(0);
		default:
			n = 0;
		}
		flag = 0;
	}
}
