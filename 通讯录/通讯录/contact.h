#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 12//��/0��ҲҪ���ȥ
#define MAX_ADDRESS 100

enum opt
{
	EXIT,
	ADD,
	DEL,
	FIND,
	MOD,
	SHOW,
};

typedef struct P_Info
{
	//����
	char name[MAX_NAME];
	//�Ա�
	char sex[MAX_SEX];
	//����
	int age;
	//�绰
	char tel[MAX_TEL];//��Ϊ����
	//��ַ
	char address[MAX_ADDRESS];
}P_Info;



typedef struct Contact
{
	//ͨѶ¼
	P_Info *PI;	
	//ͨѶ¼�е�����
	int size;
	//ͨѶ¼�ռ�
	int capacity;
}Contact;

//��ʼ��ͨѶ¼
void InitContact(Contact* ct);
//�����ϵ��
void AddContact(Contact* ct);
//��ӡͨѶ¼
void ShowContact(const Contact* ct);
//ɾ����ϵ��
void DelContact(Contact* ct);
//������ϵ��
void FindContact(Contact* ct);
//�޸���ϵ��
void ModContact(Contact* ct);