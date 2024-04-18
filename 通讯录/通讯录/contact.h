#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 12//‘/0’也要算进去
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
	//名字
	char name[MAX_NAME];
	//性别
	char sex[MAX_SEX];
	//年龄
	int age;
	//电话
	char tel[MAX_TEL];//改为数字
	//地址
	char address[MAX_ADDRESS];
}P_Info;



typedef struct Contact
{
	//通讯录
	P_Info *PI;	
	//通讯录中的人数
	int size;
	//通讯录空间
	int capacity;
}Contact;

//初始化通讯录
void InitContact(Contact* ct);
//添加联系人
void AddContact(Contact* ct);
//打印通讯录
void ShowContact(const Contact* ct);
//删除联系人
void DelContact(Contact* ct);
//查找联系人
void FindContact(Contact* ct);
//修改联系人
void ModContact(Contact* ct);