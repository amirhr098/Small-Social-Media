#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct us_st{
	int id,birthyear,birthmonth,followers[200],follow_num;
	char username[15],bio[150],message[150];
};

int number=0;
struct us_st user[200];


int check_user(int user1){
	int i;
	for(i=0;i<number;i++){
		if(user[i].id==user1) return i;
	}
	return -1;	
}
 
void Register(void){
	printf("Username: ");
	scanf("%s",&user[number].username);
	printf("Birth Year: ");
	scanf("%d",&user[number].birthyear);
	printf("Birth Month: ");
	scanf("%d",&user[number].birthmonth);
	printf("Bio: ");
	getchar();
	gets(user[number].bio);
	srand(time(0));
	user[number].id = rand();
	user[number].follow_num=0;
	user[number].followers[0]=0;
	printf("User ID: %d\n",user[number].id);
	number += 1;
}

void Publish(void){
	int user1;
	printf("User ID: ");
	scanf("%d",&user1);
	if(check_user(user1)!=-1){
		printf("Message: ");
		getchar();
		gets(user[check_user(user1)].message);
		printf("PUBLISHED.\n");
	}else{
		printf("User ID is not correct.\n");
	}
}

void Follow(void){
	int user1,user2,y;
	printf("User ID: ");
	scanf("%d",&user1);
	y=check_user(user1);
	if(y!=-1) {
		printf("User ID you want to Follow: ");
		scanf("%d",&user2);
		if(check_user(user2)!=-1) {
			user[y].followers[user[y].follow_num] = user2;
			user[y].follow_num+=1;
			printf("You: %d\tFollowed:%d\n",user1,user2);
		}else	printf("User ID is not correct.\n");
	}else	printf("User ID is not correct.\n");
}

void Show_Following(void){
	int user1,y,i;
	printf("User ID: ");
	scanf("%d",&user1);
	y=check_user(user1);
	if(y!=-1) {
		for(i=0;i<user[y].follow_num;i++){
			printf("Following-%d: %s\n",i+1,user[check_user(user[y].followers[i])].username);
		}
	} else printf("User ID is not correct.\n");
}

void Profile(void){
	int user1,y;
	printf("User ID: ");
	scanf("%d",&user1);
	y=check_user(user1);
	if(y!=-1) {
		printf("USER ID: %d\n",user1);
		printf("USERNAME: %s\n",user[y].username);
		printf("Birthday Time: %d-%d\n",user[y].birthyear,user[y].birthmonth);
		printf("Bio: %s\n",user[y].bio);
		printf("Followings: %d\n",user[y].follow_num);
	}else{
		printf("User ID is not correct.\n");
	}
}

void Get_Timeline(void){
	int user1,y,i,f;
	printf("User ID: ");
	scanf("%d",&user1);
	y=check_user(user1);
	if(y!=-1) {
		if(user[y].follow_num>0){
			for(i=0;i<user[y].follow_num;i++){
				f = check_user(user[y].followers[i]);
				printf("Username: %s\tUser ID: %d\n%s\n\n",user[f].username,user[f].id,user[f].message);
			}
		
		}else printf("No New Messages.\n");
	}else{
		printf("User ID is not correct.\n");
	}
}


int main() {
	int t;
	while(1){
	printf("\nPlease Select One Option: (Total Number of Users: %d)\n1) Register New User\n2) Publish Message\n3) Follow\n4) Show Followings\n5) Profile\n6) Get Timeline\n",number);
	scanf("%d",&t);
	switch(t){
		case 1:Register();
			break;
		case 2:Publish();
			break;
		case 3:Follow();
			break;	
		case 4:Show_Following();
			break;
		case 5:Profile();
			break;
		case 6:Get_Timeline();
		    break;
	  }
	}
	return 0;
}
