#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqlcpr.h>

EXEC SQL BEGIN DECLARE SECTION; //BEGIN
/* Another way to connect. */
char *username = "s091895"; //���̵�
char *password = "sejong2212"; //��й�ȣ

/*����� INFO ���̺�*/
	int INFO_INFONO;
	char INFO_INFONAME[100];
	int INFO_INFOBORN;
	char INFO_INFODOMAIN[100];

/* ����� PHOTO ���̺�*/
	int PHOTO_PHOTONO;
	int PHOTO_PHOTODATE;
	int PHOTO_PHOTOWIDTH;
	int PHOTO_PHOTOHEIGHT;
	char PHOTO_PHOTOGRAPHER[100];
	char PHOTO_PHOTOINDENT[100];
	int PHOTO_PHOTOPRICE;
	int PHOTO_INFONO;
	

/* ����� NEWS ���̺�*/
	int NEWS_NEWSNO;
	char NEWS_NEWSNAME[100];
	char NEWS_NEWSAUTHOR[100];
	int NEWS_NEWSMAGAZINENO;
	int NEWS_PHOTONO;
	int NEWS_INFONO;

EXEC SQL END DECLARE SECTION; //END

EXEC SQL INCLUDE SQLCA;


//�ʱ�ȭ 
void init_table(){

		//��� ���̺��� Ʃ�� ����
	  EXEC SQL DELETE NEWS;
	  EXEC SQL DELETE PHOTO;
	  EXEC SQL DELETE INFO;
	
		/*�ʱ� ������ ���� ����*/
		
		//INFO ���̺� ������ ����
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(1, '����ȣ', 19801212, '������');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(2, '�޽�', 19871205, '������');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(3, '������', 19701215, '��ġ');
	  EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(4, '�ٿ�', 18951201, '����');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(5, '���ν�Ÿ��', 18600101, '����');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(6, '�����', 19850401, '��ȸ');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(7, '������', 19811212, '��ȸ');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(8, '�޸�����Ŀ', 19780622, '������');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(9, '�迬��', 19881212, '������');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(10, '����ȯ', 19800421, '����');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(11, '����ö', 19560101, '��ȸ');
		  	
		//PHOTO ���̺� ������ ����  	
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(1,20000125,240,240,'�����','-1',-1,4);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(2,20101223,240,240,'-1','�߾ӻ�����',20000,1);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(3,19990110,240,240,'-1','�߾ӻ�����',19000,2);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(4,19990120,240,240,'�����','-1',-1,5); 
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(5,20000105,240,240,'�����','-1',-1,3);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(6,20050505,480,480,'�����','-1',-1,4);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(7,20061212,480,480,'��â��','-1',-1,7);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(8,20100523,480,480,'��â��','-1',-1,6);  	
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(9,20070830,480,480,'��â��','-1',-1,11);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(10,20050401,480,480,'-1','���������',19000,8);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(11,20090101,480,480,'-1','���������',21000,9);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(12,20011201,480,480,'-1','���������',20000,10);  	 		  		
		

		//NEWS ���̺� ������ ����
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(1,'����ȣ �Ϻ���','��â��',105,2,1); 
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(2,'��̿� ���� ���ڷ� ������','��â��',105,8,6);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(3,'�޽� ������ ������','��ȣö',105,3,2);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(4,'�̸�� 4�밭 ����� ���','��ȣö',105,1,3);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(5,'���л��������� ������','��ȣö',108,7,7);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(6,'�ٿ����� ����','����ö',108,6,4);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(7,'���ν�Ÿ�� ���� �߰�','����ö',108,4,5); 	
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(8,'�����û ������Ʈ�� ����','�����',108,5,3); 
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(9,'A��� ��ȥ','�����',112,11,9);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(10,'�������б� ���Ǽҵ�','������',112,10,8);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(11,'�������б� �Խ� ����� ����','������',112,12,10);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(12,'���� �̻��� �߻�','�̹���',113,9,11);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(13,'�Ӻ�) �ѱ� ������ ������','��â��',113,12,1);		


		/*�ʱ� ������ ���� ��*/
		
		//COMMIT - ��� �����͸� �����ͺ��̽��� �����ϰ� ������ Ʈ����� ����
		EXEC SQL COMMIT WORK; 

}

void update_data(){
	char table_name[100]={0,}; //���̺� ��
	char property[100]={0,}; //�Ӽ���
	int attribute_num; //��Ű
	
	char update_attribute[100]={0,}; //����� �Ӽ���
	int update_attribute_int; //����� �Ӽ���
	
	printf("���̺� �̸��� �Է��ϼ��� : ");
	scanf("%s",table_name); 
	
	printf("�����ϰ����ϴ� �Ӽ��� �Է��ϼ��� : ");
	scanf("%s",property);
	
	printf("������ ��Ű�� �Է��ϼ���(primary_key) : ");
	scanf("%d",&attribute_num);
		
	if(strcmp(table_name,"INFO") == 0 || strcmp(table_name,"info") == 0 ){ //INFO
		
			if(strcmp(property,"INFONAME")==0 || strcmp(property,"infoname")==0){//INFONAME ����
				printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%s",update_attribute);
				EXEC SQL UPDATE INFO  //SQL������ UPDATE ����
							SET INFONAME=:update_attribute
		  				WHERE INFONO=:attribute_num; 
		  }
		 	else if(strcmp(property,"INFOBORN")==0 || strcmp(property,"infoborn")==0){//INFOBORN ����
			 	printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE INFO  //SQL������ UPDATE ����
							SET INFOBORN=:update_attribute_int
		  				WHERE INFONO=:attribute_num; 
		  }
		  else if(strcmp(property,"INFODOMAIN")==0 || strcmp(property,"infodomain")==0){//INFODOMAIN ����
		  	printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%s",update_attribute);
				EXEC SQL UPDATE INFO  //SQL������ UPDATE ����
							SET INFODOMAIN=:update_attribute
		  				WHERE INFONO=:attribute_num; 
		  }
		  		
		  EXEC SQL COMMIT WORK; 	//COMMIT �����ش�.
			
	}
	else if(strcmp(table_name,"PHOTO") == 0 || strcmp(table_name,"photo") == 0 ){ //PHOTO

			if(strcmp(property,"PHOTODATE")==0 || strcmp(property,"photodate")==0){//PHOTODATE ����
				printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE PHOTO 
							SET PHOTODATE=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }		
		  else if(strcmp(property,"PHOTOWIDTH")==0 || strcmp(property,"photowidth")==0){//PHOTOWIDTH ����
			  printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
			 	EXEC SQL UPDATE PHOTO
		  				SET PHOTOWIDTH=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }		
		  else if(strcmp(property,"PHOTOHEIGHT")==0 || strcmp(property,"photoheight")==0){//PHOTOHEIGHT ����
			  printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
		  	EXEC SQL UPDATE PHOTO
		  				SET PHOTOHEIGHT=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }		
		  else if(strcmp(property,"PHOTOGRAPHER")==0 || strcmp(property,"photographer")==0){//PHOTOGRAPHER ����
		  	printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%s",update_attribute);
		  	EXEC SQL UPDATE PHOTO
		  				SET PHOTOGRAPHER=:update_attribute
		  				WHERE PHOTONO=:attribute_num; 
		  }		
		  else if(strcmp(property,"PHOTOINDENT")==0 || strcmp(property,"photoindent")==0){//PHOTOINDENT ����
		  	printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%s",update_attribute);
		  	EXEC SQL UPDATE PHOTO
		  				SET PHOTOINDENT=:update_attribute
		  				WHERE PHOTONO=:attribute_num; 
		  }	
		  else if(strcmp(property,"PHOTOPRICE")==0 || strcmp(property,"photoprice")==0){//PHOTOPRICE ����
		 		printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
		  	EXEC SQL UPDATE PHOTO
		  				SET PHOTOPRICE=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }	
		  else if(strcmp(property,"INFONO")==0 || strcmp(property,"infono")==0){//INFONO ����
		 		printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
		  	EXEC SQL UPDATE PHOTO
		  				SET INFONO=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }	
		  EXEC SQL COMMIT WORK; 	//COMMIT �����ش�.
		
	}
	else if(strcmp(table_name,"NEWS") == 0 || strcmp(table_name,"news") == 0 ){//NEWS
			
			if(strcmp(property,"NEWSNAME")==0 || strcmp(property,"newsname")==0){//NEWSNAME ����
				printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%s",update_attribute);
				EXEC SQL UPDATE NEWS  
							SET NEWSNAME=:update_attribute
		  				WHERE NEWSNO=:attribute_num;  
		  }		
		  else if(strcmp(property,"NEWSAUTHOR")==0 || strcmp(property,"newsauthor")==0){//NEWSAUTHOR ����
		  	printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%s",update_attribute);
				EXEC SQL UPDATE NEWS 
							SET NEWSAUTHOR=:update_attribute
		  				WHERE NEWSNO=:attribute_num;  
		  }		
		  else if(strcmp(property,"NEWSMAGAZINENO")==0 || strcmp(property,"newsmagazineno")==0){//NEWSMAGAZINENO ����
		 		printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE NEWS 
							SET NEWSMAGAZINENO=:update_attribute_int
		  				WHERE NEWSNO=:attribute_num;  
		  }		
		  else if(strcmp(property,"PHOTONO")==0 || strcmp(property,"photono")==0){//PHOTONO ����
		  	printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE NEWS  
							SET PHOTONO=:update_attribute_int
		  				WHERE NEWSNO=:attribute_num;  
		  }		
		  else if(strcmp(property,"INFONO")==0 || strcmp(property,"infono")==0){//INFONO ����
		 		printf("����� �Ӽ����� �Է��ϼ��� (��, NULL�� �� ��� -1�� �Է��ϼ���): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE NEWS  
							SET INFONO=:update_attribute_int
		  				WHERE NEWSNO=:attribute_num;  
		  }		
			
		  		
		  EXEC SQL COMMIT WORK; 	//COMMIT �����ش�.
	
	}
}
void delete_data(){
	char table_name[100]={0,}; //���̺� ��
	int attribute_num;  //�Ӽ��� 
	
	printf("���̺� �̸��� �Է��ϼ��� : ");
	scanf("%s",table_name);
	
	printf("��Ű(�⺻Ű)�� ���� �Է��ϼ��� (��, �ܷ�Ű�� �����Ǿ� ���� �� ���� �Ұ�): ");
	scanf("%d",&attribute_num);
	
	if(strcmp(table_name,"INFO") == 0 || strcmp(table_name,"info") == 0 ){ //INFO

			EXEC SQL DELETE FROM INFO
						WHERE INFONO=:attribute_num;
		  EXEC SQL COMMIT WORK; 	
		  
	
	}
	else if(strcmp(table_name,"PHOTO") == 0 || strcmp(table_name,"photo") == 0 ){ //PHOTO

		    EXEC SQL DELETE FROM PHOTO
							WHERE PHOTONO=:attribute_num;
		  	EXEC SQL COMMIT WORK; 
	
	}
	else if(strcmp(table_name,"NEWS") == 0 || strcmp(table_name,"news") == 0 ){//NEWS
				EXEC SQL DELETE FROM NEWS //�⺻Ű�� �����Ȱ� �����Ƿ� �ڱ⸸ �����ϸ� �ȴ�.
							WHERE NEWSNO=:attribute_num;
		  		
		  	EXEC SQL COMMIT WORK; 
	}
		
}
void insert_data(){
		char table_name[100]={0,};
	
		printf("���̺� �̸��� �Է��ϼ��� : ");
		scanf("%s",table_name);
		
		if(strcmp(table_name,"INFO") == 0 || strcmp(table_name,"info") == 0 ){ //INFO
			
			printf("�ι����� ������ȣ  : ");
			scanf("%d",&INFO_INFONO);
			
			printf("�̸� : ");
			scanf("%s",INFO_INFONAME);
			
			printf("������� : ");
			scanf("%d",&INFO_INFOBORN);
			
			printf("���� : ");
			scanf("%s",INFO_INFODOMAIN);
			
		 		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(:INFO_INFONO, :INFO_INFONAME, :INFO_INFOBORN, :INFO_INFODOMAIN);
		  		
		  	EXEC SQL COMMIT WORK; 	
	}
	
	else if(strcmp(table_name,"PHOTO") == 0 || strcmp(table_name,"photo") == 0 ){ //PHOTO
			
			printf("�������� ��ȣ : ");
			scanf("%d",&PHOTO_PHOTONO);
			
			printf("��¥ : ");
			scanf("%d",&PHOTO_PHOTODATE);
			
			printf("����ũ�� : ");
			scanf("%d",&PHOTO_PHOTOWIDTH);
			
			printf("����ũ�� : ");
			scanf("%d",&PHOTO_PHOTOHEIGHT);
			
			printf("�������̸� (�ܺο��� �Էµ� ������ ���� -1�� �Է��ϼ���.) : "); //���� �Ҽ��� ���
			scanf("%s",PHOTO_PHOTOGRAPHER);
			
			printf("����ó (�Ź��� �Ҽӻ������� ������ ���� -1�� �Է��ϼ���.) : ");//�ܺ� �Ҽ��� ���
			scanf("%s",PHOTO_PHOTOINDENT);
			
			printf("���� (�Ź��� �Ҽӻ������� ������ ���� -1�� �Է��ϼ���.): ");//�ܺ� �Ҽ��� ���
			scanf("%d",&PHOTO_PHOTOPRICE);
			
			printf("�ι�����������ȣ : (�� ���� : �ش��ϴ� �ι������� ������ ���Ե��� �ʽ��ϴ�.)");
			scanf("%d",&PHOTO_INFONO);
		
				EXEC SQL INSERT INTO PHOTO  (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT,PHOTOGRAPHER,PHOTOINDENT,PHOTOPRICE,INFONO)
		 			 VALUES(:PHOTO_PHOTONO, :PHOTO_PHOTODATE, :PHOTO_PHOTOWIDTH, :PHOTO_PHOTOHEIGHT, :PHOTO_PHOTOGRAPHER, :PHOTO_PHOTOINDENT, :PHOTO_PHOTOPRICE, :PHOTO_INFONO);
		
		  EXEC SQL COMMIT WORK;

	}
	else if(strcmp(table_name,"NEWS") == 0 || strcmp(table_name,"news") == 0 ){//NEWS
			
			printf("��� ������ȣ : ");
			scanf("%d",&NEWS_NEWSNO);
			
			printf("���� : ");
			scanf("%s",&NEWS_NEWSNAME);
			
			printf("�ۼ��� : ");
			scanf("%s",NEWS_NEWSAUTHOR);
			
			printf("�߰�ȣ : ");
			scanf("%d",&NEWS_NEWSMAGAZINENO);
			
			printf("����������ȣ : (�� ���� : �ش��ϴ� ������ ������ ���Ե��� �ʽ��ϴ�.) ");
			scanf("%d",&NEWS_PHOTONO);
			
			printf("�ι�����������ȣ: (�� ���� : �ش��ϴ� �ι������� ������ ���Ե��� �ʽ��ϴ�.)");
			scanf("%d",&NEWS_INFONO);
			
			EXEC SQL INSERT INTO NEWS  (NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO, PHOTONO, INFONO)
		 			 VALUES(:NEWS_NEWSNO, :NEWS_NEWSNAME, :NEWS_NEWSAUTHOR, :NEWS_NEWSMAGAZINENO, :NEWS_PHOTONO, :NEWS_INFONO);
		  		
		  EXEC SQL COMMIT WORK;
	
	}
}

void print_table(){
	int dum;
	int i;
	
	printf("1) ���̺� ��ü���� ����\n");
	printf("2) �̸��� �޽��� ����� ������ϰ�, ��� ����� ���� ��¥�� ����Ͻÿ�.\n");
	printf("3) �߰�ȣ�� 105�� ����� �����, �� ��翡 ���� �ι��� �̸���, ������ ����ũ�⸦ ����Ͻÿ�.\n");
	printf("4) ������ �������� �ش��ϴ� �ι��� ���� ����̸���, ���� ��¥ �˻�\n");
	printf("5) �׸��� ���α��̰� 400 �̻��� ���� �߿� �߰�ȣ�� 110 ������ ��� ����� �� ��翡 ���� �ι� �̸��� ���� ���� ������ȣ�� ����϶�.\n");
	printf("6) ���� �۰���(Ȥ�� �����۰��� ���� ���)�� �׷�ȭ�ϰ�, �� �۰��� �ִ� ���� ���̰� 400�� �Ѵ� �����۰��� �ִ� �������� ����, ���� ����� �ֽ� �߰�ȣ, ���� ���̰� �  ���� �ι��� �������  �˻�\n");
	printf("7) �߰�ȣ�� �׷�ȭ�ϰ�, ���� ���� ���� ������ȣ�� 7������ �߰�ȣ�� ���Ͽ� �߰�ȣ, ���� ���� ���� ������ȣ, ���� �ι� �� ���� ���̰� � �ι��� ���������  �˻��϶�.\n");
	
	scanf("%d",&dum);
	switch(dum){
	case 1: //���̺� ��ü���� ��� 

			//INFO
			printf("info ���̺� ����\n");
			
			//curser ����
			EXEC SQL DECLARE info_curser CURSOR FOR
							SELECT INFONO,INFONAME,INFOBORN,INFODOMAIN 
							FROM INFO;
			//curser ����
			EXEC SQL OPEN info_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH info_curser
							INTO :INFO_INFONO, :INFO_INFONAME, :INFO_INFOBORN, :INFO_INFODOMAIN;
				printf("%d %s %d %s\n",INFO_INFONO,INFO_INFONAME,INFO_INFOBORN,INFO_INFODOMAIN);
			}
			EXEC SQL CLOSE info_curser;
	
		
			//PHOTO
			printf("\nPHOTO ���̺� ����\n");
			//curser ����
			EXEC SQL DECLARE photo_curser CURSOR FOR
							SELECT PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT,PHOTOGRAPHER,PHOTOINDENT,PHOTOPRICE,INFONO
							FROM PHOTO;
			//curser ����
			EXEC SQL OPEN photo_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH photo_curser
							INTO :PHOTO_PHOTONO, :PHOTO_PHOTODATE, :PHOTO_PHOTOWIDTH, :PHOTO_PHOTOHEIGHT, :PHOTO_PHOTOGRAPHER, :PHOTO_PHOTOINDENT, :PHOTO_PHOTOPRICE, :PHOTO_INFONO;
				printf("%d %d %d %d %s %s %d %d\n",PHOTO_PHOTONO, PHOTO_PHOTODATE, PHOTO_PHOTOWIDTH, PHOTO_PHOTOHEIGHT, PHOTO_PHOTOGRAPHER, PHOTO_PHOTOINDENT, PHOTO_PHOTOPRICE, PHOTO_INFONO);
			}
			EXEC SQL CLOSE photo_curser;


		 	//NEWS
		 	printf("\nNEWS ���̺� ����\n");
		  
			//curser ����
			EXEC SQL DECLARE news_curser CURSOR FOR
							SELECT NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO,PHOTONO,INFONO
							FROM NEWS;
			//curser ����
			EXEC SQL OPEN news_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH news_curser
							INTO :NEWS_NEWSNO, :NEWS_NEWSNAME, :NEWS_NEWSAUTHOR, :NEWS_NEWSMAGAZINENO, :NEWS_PHOTONO, :NEWS_INFONO;
				printf("%d %s %s %d %d %d\n",NEWS_NEWSNO, NEWS_NEWSNAME, NEWS_NEWSAUTHOR, NEWS_NEWSMAGAZINENO, NEWS_PHOTONO, NEWS_INFONO);
			}
			EXEC SQL CLOSE news_curser;
			
			break;
		  
	case 2://�̸��� �޽��� ����� ������ϰ�, ��� ����� ���� ��¥�� ����Ͻÿ�.
		
			//curser ����
			EXEC SQL DECLARE inf_curser CURSOR FOR //������ 
						select i.infoborn, n.newsname, p.photodate
						from info i,photo p,news n 
						where i.infono = n.infono and i.infono = p.infono and p.photono = n.photono  and i.infoname='�޽�';

			
						 	
			//curser ����
			EXEC SQL OPEN inf_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH inf_curser
							INTO :INFO_INFOBORN, :NEWS_NEWSNAME, :PHOTO_PHOTODATE; 
				printf("%d %s %d \n",INFO_INFOBORN,NEWS_NEWSNAME,PHOTO_PHOTODATE);
			}
			
			EXEC SQL CLOSE inf_curser;
			break;
	 
	case 3: //�߰�ȣ�� 105�� ����� �����, �� ��翡 ���� �ι��� �̸���, ������ ����ũ�⸦ ����Ͻÿ�.
	
			//curser ����
			EXEC SQL DECLARE news2_curser CURSOR FOR//������ 
						select newsname,infoname,photowidth
						from news n, info i, photo p 
						where n.photono = p.photono and i.infono = n.infono and i.infono = p.infono and newsmagazineno=105;

						 	
			//curser ����
			EXEC SQL OPEN news2_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH news2_curser
							INTO :NEWS_NEWSNAME, INFO_INFONAME, PHOTO_PHOTOWIDTH;
				printf("%s %s %d \n",NEWS_NEWSNAME,INFO_INFONAME,PHOTO_PHOTOWIDTH);
			}
			EXEC SQL CLOSE news2_curser;
			
			break;
			
	case 4://������ �������� �ش��ϴ� �ι��� ���� ����̸���, ���� ��¥ �˻�
			//curser ����
			EXEC SQL DECLARE news3_curser CURSOR FOR //������ 
							select n.newsname,p.photodate from news n, photo p,info i
 							where p.photono = n.photono and n.infono = i.infono and i.infono = p.infono and i.infono in ( select infono
						  																																														from info
		 									 																																										where infodomain = '������');
	
			//curser ����
			EXEC SQL OPEN news3_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH news3_curser
							INTO :NEWS_NEWSNAME,PHOTO_PHOTODATE;
				printf("%s %d \n",NEWS_NEWSNAME,PHOTO_PHOTODATE);
			}
			EXEC SQL CLOSE news3_curser;

	 		break;
	
	 		
	case 5: //�׸��� ���α��̰� 400 �̻��� ���� �߿� �߰�ȣ�� 110 ������ ��� ����� �� ��翡 ���� �ι� �̸��� ���� ���� ������ȣ(���� ������ �ִٸ�)�� ����϶�.

			//curser ����
			EXEC SQL DECLARE news4_curser CURSOR FOR //������ 
							SELECT n.newsname, i.infoname, p.photono
							FROM news n, photo p, info i
						 	WHERE n.photono = p.photono and n.infono = i.infono and i.infono = p.infono and n.NEWSMAGAZINENO <= 110 and n.photono in (select photono
		  																										from photo
		 																											where PHOTOWIDTH >= 400);
						 	
			//curser ����
			EXEC SQL OPEN news4_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH news4_curser
							INTO :NEWS_NEWSNAME, :INFO_INFONAME, :PHOTO_PHOTONO;
				printf("%s %s %d \n",NEWS_NEWSNAME, INFO_INFONAME, PHOTO_PHOTONO);
			}
			EXEC SQL CLOSE news4_curser;
			break;
			
	case 6: //���� �۰���(Ȥ�� �����۰��� ���� ���)�� �׷�ȭ�ϰ�, �� �۰��� �ִ� ���� ���̰� 400�� �Ѵ� �����۰��� �ִ� �������� ����, ���� ����� �ֽ� �߰�ȣ, ���� ���̰� �  ���� �ι��� �������  �˻�

			//curser ����
			EXEC SQL DECLARE photo1_curser CURSOR FOR //������ 
							SELECT p.photographer,MAX(p.photowidth), MAX(n.newsmagazineno), MAX(i.infoborn)
							FROM photo p, news n, info i
							where n.photono = p.photono and n.infono = i.infono and i.infono = p.infono
						 	group by p.photographer
 							having MAX(p.photowidth)>=400;
						 	
			//curser ����
			EXEC SQL OPEN photo1_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH photo1_curser
							INTO : PHOTO_PHOTOGRAPHER, :PHOTO_PHOTOWIDTH, :NEWS_NEWSMAGAZINENO, :INFO_INFOBORN;
				printf("%s %d %d %d \n",PHOTO_PHOTOGRAPHER, PHOTO_PHOTOWIDTH, NEWS_NEWSMAGAZINENO, INFO_INFOBORN);
			}
			EXEC SQL CLOSE photo1_curser;
			break;
			
		case 7: //�߰�ȣ�� �׷�ȭ�ϰ�, ���� ���� ���� ������ȣ�� 7������ �߰�ȣ�� ���Ͽ� �߰�ȣ, ���� ���� ���� ������ȣ, ���� �ι� �� ���� ���̰� � �ι��� ���������  �˻��϶�.

			//curser ����
			EXEC SQL DECLARE news5_curser CURSOR FOR //������ 
							SELECT n.NEWSMAGAZINENO, MIN(p.PHOTONO), MAX(i.infoborn)
							FROM photo p, news n, info i
							where n.photono = p.photono and n.infono = i.infono and i.infono = p.infono
						 	group by n.NEWSMAGAZINENO
 							having MIN(n.PHOTONO)<=7;
						 	
			//curser ����
			EXEC SQL OPEN news5_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser ��ġ
				EXEC SQL FETCH news5_curser
							INTO :NEWS_NEWSMAGAZINENO, :PHOTO_PHOTONO, :INFO_INFOBORN;
				printf("%d %d %d \n",NEWS_NEWSMAGAZINENO, PHOTO_PHOTONO, INFO_INFOBORN);
			}
			EXEC SQL CLOSE news5_curser;
			
			break;
			
	default: printf("�߸��Է��ϼ̽��ϴ�.\n");

	}
}

void ui(){
	printf("1) ���̺� ���� ����\n");
	printf("2) ������ �����ϱ�\n");
	printf("3) ������ �����ϱ�\n");
	printf("4) ������ �����ϱ�\n");
	printf("5) �����ͺ��̽� �ʱ�ȭ\n");
	printf("6) ������\n");
}

void main(){ 

	EXEC SQL CONNECT :username IDENTIFIED BY :password; //����� ID , PASSWORD �� ���� ��Ű�� 
	
	int dum,dummy;

	do{
		dummy = -1;
		ui();
		scanf("%d",&dum);
		switch(dum){
		case 1: print_table();break; //���
		case 2: insert_data();break; //����
		case 3: delete_data();break; //����
		case 4: update_data();break; //����
		case 5: init_table();break; //�ʱ�ȭ
		case 6: break; //������
		default: printf("�߸��Է��ϼ̽��ϴ�.\n"); //�߸��Է� 
		}

		while (dummy != 0 && dum!=6){
			printf("ó���޴������� ���ư��ðڽ��ϱ�? (�޴��� ���ư��÷��� 0 �� �����ֽʽÿ�.)");
			scanf("%d",&dummy);
		}
		
	}while(dum !=6);
}