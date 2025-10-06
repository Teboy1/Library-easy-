#include <stdio.h>        //有个较大缺点......无法永久的数据存储和读取
#include <string.h>
                          //偏向于小型书馆，还未做到用户注册与登录(无法外借图书)
// 图书结构体
struct Book {
	int id;
	char name[50];
	char writer[30];
	float price;
};

struct Book books[100];  // 最多存储100本书
int count = 0;           // 当前图书的数量

// 显示菜单
void Menu(void) {
	printf("\n=== 简单图书管理系统 ===\n");
	printf("1. 添加图书\n");
	printf("2. 显示所有图书\n");
	printf("3. 查找图书\n");
	printf("4. 退出\n");
	printf("请选择: ");
}

// 添加图书
void addBook(void) {
	if (count >= 100) {
		printf("书库已满！\n");
		return;
	}
	
	printf("\n--- 添加图书 ---\n");
	printf("请输入图书ID: ");
	scanf("%d", &books[count].id);
	printf("请输入图书名称: ");
	scanf("%s", books[count].name);
	printf("请输入作者: ");
	scanf("%s", books[count].writer);
	printf("请输入价格: ");
	scanf("%f", &books[count].price);
	
	count++;
	printf("添加成功！\n");
}

// 显示所有图书
void ShowAllBooks(void) {
	if (count == 0) {    //无书籍时反馈给用户
		printf("书库是空的！\n");
		return;
	}
	
	printf("\n--- 所有图书 ---\n");
	printf("ID\t名称\t\t作者\t\t价格\n");
	printf("----------------------------------------\n");
	
	for (int i = 0; i < count; i++) {    //循环展示完所有已添加书籍
		printf("%d\t%s\t\t%s\t\t%.2f\n", 
			books[i].id, 
			books[i].name, 
			books[i].writer, 
			books[i].price);
	}
}

// 查找图书
void searchBook(void) {
	if (count == 0) {     //无书籍时反馈给用户
		printf("书库是空的！\n");
		return;
	}
	
	char name[50];        //限制书籍名称长度
	printf("\n请输入要查找的图书名称: ");
	scanf("%s", name);
	
	int found = 0;        //开始假设没找到书籍
	for (int i = 0; i < count; i++) {
		if (strcmp(books[i].name, name) == 0) {   //运用strcmp的前后两变量是否为0判断是否成功添加书籍
			printf("\n找到图书:\n");
			printf("ID: %d\n", books[i].id);
			printf("名称: %s\n", books[i].name);
			printf("作者: %s\n", books[i].writer);
			printf("价格: %.2f\n", books[i].price);
			found = 1;
			break;
		}
	}
	
	if (!found) {         //循环结束检测是否找到书籍         
		printf("没找到这本书！\n");
	}
}

int main(void) {
	int choice;
	
	printf("欢迎使用简单图书管理系统！\n");
	
	while(1) {             //用户输入1~4返回对应的输出
		Menu();
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			addBook();
			break;
		case 2:
			ShowAllBooks();
			break;
		case 3:
			searchBook();
			break;
		case 4:
			printf("谢谢使用！再见！\n");
			return 0;
		default:
			printf("输入错误，请重新选择！\n");
		}
	}
	return 0;
}
