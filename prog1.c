#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqlcpr.h>

EXEC SQL BEGIN DECLARE SECTION; //BEGIN
/* Another way to connect. */
char *username = "s091895"; //아이디
char *password = "sejong2212"; //비밀번호

/*선언부 INFO 테이블*/
	int INFO_INFONO;
	char INFO_INFONAME[100];
	int INFO_INFOBORN;
	char INFO_INFODOMAIN[100];

/* 선언부 PHOTO 테이블*/
	int PHOTO_PHOTONO;
	int PHOTO_PHOTODATE;
	int PHOTO_PHOTOWIDTH;
	int PHOTO_PHOTOHEIGHT;
	char PHOTO_PHOTOGRAPHER[100];
	char PHOTO_PHOTOINDENT[100];
	int PHOTO_PHOTOPRICE;
	int PHOTO_INFONO;
	

/* 선언부 NEWS 테이블*/
	int NEWS_NEWSNO;
	char NEWS_NEWSNAME[100];
	char NEWS_NEWSAUTHOR[100];
	int NEWS_NEWSMAGAZINENO;
	int NEWS_PHOTONO;
	int NEWS_INFONO;

EXEC SQL END DECLARE SECTION; //END

EXEC SQL INCLUDE SQLCA;


//초기화 
void init_table(){

		//모든 테이블의 튜플 삭제
	  EXEC SQL DELETE NEWS;
	  EXEC SQL DELETE PHOTO;
	  EXEC SQL DELETE INFO;
	
		/*초기 데이터 삽입 시작*/
		
		//INFO 테이블 데이터 삽입
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(1, '박찬호', 19801212, '스포츠');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(2, '메시', 19871205, '스포츠');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(3, '오세훈', 19701215, '정치');
	  EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(4, '다우', 18951201, '경제');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(5, '아인슈타인', 18600101, '과학');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(6, '김미진', 19850401, '사회');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(7, '심현섭', 19811212, '사회');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(8, '메르데자커', 19780622, '스포츠');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(9, '김연아', 19881212, '스포츠');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(10, '신정환', 19800421, '연예');
		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(11, '임현철', 19560101, '사회');
		  	
		//PHOTO 테이블 데이터 삽입  	
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(1,20000125,240,240,'김수현','-1',-1,4);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(2,20101223,240,240,'-1','중앙사진관',20000,1);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(3,19990110,240,240,'-1','중앙사진관',19000,2);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(4,19990120,240,240,'김수현','-1',-1,5); 
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(5,20000105,240,240,'김수현','-1',-1,3);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(6,20050505,480,480,'김수현','-1',-1,4);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(7,20061212,480,480,'김창남','-1',-1,7);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(8,20100523,480,480,'김창남','-1',-1,6);  	
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(9,20070830,480,480,'김창남','-1',-1,11);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(10,20050401,480,480,'-1','동양사진관',19000,8);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(11,20090101,480,480,'-1','동양사진관',21000,9);
		EXEC SQL INSERT INTO PHOTO (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT, PHOTOGRAPHER, PHOTOINDENT, PHOTOPRICE, INFONO)
		  		VALUES(12,20011201,480,480,'-1','동양사진관',20000,10);  	 		  		
		

		//NEWS 테이블 데이터 삽입
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(1,'박찬호 완봉승','김창연',105,2,1); 
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(2,'김미영 팀장 남자로 밝혀져','김창연',105,8,6);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(3,'메시 극적인 역전골','조호철',105,3,2);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(4,'이명박 4대강 사업의 결과','조호철',105,1,3);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(5,'입학사정관제의 문제점','조호철',108,7,7);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(6,'다우지수 폭락','김희철',108,6,4);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(7,'아인슈타인 유골 발견','김희철',108,4,5); 	
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(8,'서울시청 스케이트장 개장','김미현',108,5,3); 
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(9,'A모양 이혼','김미현',112,11,9);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(10,'세종대학교 대피소동','이지선',112,10,8);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(11,'세종대학교 입시 경쟁률 폭발','이지선',112,12,10);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(12,'북한 미사일 발사','이미진',113,9,11);
		EXEC SQL INSERT INTO NEWS(NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO , PHOTONO, INFONO)
		  		VALUES(13,'속보) 한국 극적인 역전승','임창정',113,12,1);		


		/*초기 데이터 삽입 끝*/
		
		//COMMIT - 모든 데이터를 데이터베이스에 저장하고 현재의 트랜잭션 종료
		EXEC SQL COMMIT WORK; 

}

void update_data(){
	char table_name[100]={0,}; //테이블 명
	char property[100]={0,}; //속성값
	int attribute_num; //주키
	
	char update_attribute[100]={0,}; //변경될 속성값
	int update_attribute_int; //변경될 속성값
	
	printf("테이블 이름을 입력하세요 : ");
	scanf("%s",table_name); 
	
	printf("변경하고자하는 속성을 입력하세요 : ");
	scanf("%s",property);
	
	printf("변경할 주키를 입력하세요(primary_key) : ");
	scanf("%d",&attribute_num);
		
	if(strcmp(table_name,"INFO") == 0 || strcmp(table_name,"info") == 0 ){ //INFO
		
			if(strcmp(property,"INFONAME")==0 || strcmp(property,"infoname")==0){//INFONAME 수정
				printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%s",update_attribute);
				EXEC SQL UPDATE INFO  //SQL쿼리문 UPDATE 수정
							SET INFONAME=:update_attribute
		  				WHERE INFONO=:attribute_num; 
		  }
		 	else if(strcmp(property,"INFOBORN")==0 || strcmp(property,"infoborn")==0){//INFOBORN 수정
			 	printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE INFO  //SQL쿼리문 UPDATE 수정
							SET INFOBORN=:update_attribute_int
		  				WHERE INFONO=:attribute_num; 
		  }
		  else if(strcmp(property,"INFODOMAIN")==0 || strcmp(property,"infodomain")==0){//INFODOMAIN 수정
		  	printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%s",update_attribute);
				EXEC SQL UPDATE INFO  //SQL쿼리문 UPDATE 수정
							SET INFODOMAIN=:update_attribute
		  				WHERE INFONO=:attribute_num; 
		  }
		  		
		  EXEC SQL COMMIT WORK; 	//COMMIT 날려준다.
			
	}
	else if(strcmp(table_name,"PHOTO") == 0 || strcmp(table_name,"photo") == 0 ){ //PHOTO

			if(strcmp(property,"PHOTODATE")==0 || strcmp(property,"photodate")==0){//PHOTODATE 수정
				printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE PHOTO 
							SET PHOTODATE=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }		
		  else if(strcmp(property,"PHOTOWIDTH")==0 || strcmp(property,"photowidth")==0){//PHOTOWIDTH 수정
			  printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
			 	EXEC SQL UPDATE PHOTO
		  				SET PHOTOWIDTH=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }		
		  else if(strcmp(property,"PHOTOHEIGHT")==0 || strcmp(property,"photoheight")==0){//PHOTOHEIGHT 수정
			  printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
		  	EXEC SQL UPDATE PHOTO
		  				SET PHOTOHEIGHT=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }		
		  else if(strcmp(property,"PHOTOGRAPHER")==0 || strcmp(property,"photographer")==0){//PHOTOGRAPHER 수정
		  	printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%s",update_attribute);
		  	EXEC SQL UPDATE PHOTO
		  				SET PHOTOGRAPHER=:update_attribute
		  				WHERE PHOTONO=:attribute_num; 
		  }		
		  else if(strcmp(property,"PHOTOINDENT")==0 || strcmp(property,"photoindent")==0){//PHOTOINDENT 수정
		  	printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%s",update_attribute);
		  	EXEC SQL UPDATE PHOTO
		  				SET PHOTOINDENT=:update_attribute
		  				WHERE PHOTONO=:attribute_num; 
		  }	
		  else if(strcmp(property,"PHOTOPRICE")==0 || strcmp(property,"photoprice")==0){//PHOTOPRICE 수정
		 		printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
		  	EXEC SQL UPDATE PHOTO
		  				SET PHOTOPRICE=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }	
		  else if(strcmp(property,"INFONO")==0 || strcmp(property,"infono")==0){//INFONO 수정
		 		printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
		  	EXEC SQL UPDATE PHOTO
		  				SET INFONO=:update_attribute_int
		  				WHERE PHOTONO=:attribute_num; 
		  }	
		  EXEC SQL COMMIT WORK; 	//COMMIT 날려준다.
		
	}
	else if(strcmp(table_name,"NEWS") == 0 || strcmp(table_name,"news") == 0 ){//NEWS
			
			if(strcmp(property,"NEWSNAME")==0 || strcmp(property,"newsname")==0){//NEWSNAME 수정
				printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%s",update_attribute);
				EXEC SQL UPDATE NEWS  
							SET NEWSNAME=:update_attribute
		  				WHERE NEWSNO=:attribute_num;  
		  }		
		  else if(strcmp(property,"NEWSAUTHOR")==0 || strcmp(property,"newsauthor")==0){//NEWSAUTHOR 수정
		  	printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%s",update_attribute);
				EXEC SQL UPDATE NEWS 
							SET NEWSAUTHOR=:update_attribute
		  				WHERE NEWSNO=:attribute_num;  
		  }		
		  else if(strcmp(property,"NEWSMAGAZINENO")==0 || strcmp(property,"newsmagazineno")==0){//NEWSMAGAZINENO 수정
		 		printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE NEWS 
							SET NEWSMAGAZINENO=:update_attribute_int
		  				WHERE NEWSNO=:attribute_num;  
		  }		
		  else if(strcmp(property,"PHOTONO")==0 || strcmp(property,"photono")==0){//PHOTONO 수정
		  	printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE NEWS  
							SET PHOTONO=:update_attribute_int
		  				WHERE NEWSNO=:attribute_num;  
		  }		
		  else if(strcmp(property,"INFONO")==0 || strcmp(property,"infono")==0){//INFONO 수정
		 		printf("변경될 속성값을 입력하세요 (단, NULL이 들어갈 경우 -1을 입력하세요): ");
				scanf("%d",&update_attribute_int);
				EXEC SQL UPDATE NEWS  
							SET INFONO=:update_attribute_int
		  				WHERE NEWSNO=:attribute_num;  
		  }		
			
		  		
		  EXEC SQL COMMIT WORK; 	//COMMIT 날려준다.
	
	}
}
void delete_data(){
	char table_name[100]={0,}; //테이블 명
	int attribute_num;  //속성값 
	
	printf("테이블 이름을 입력하세요 : ");
	scanf("%s",table_name);
	
	printf("주키(기본키)의 값을 입력하세요 (단, 외래키로 참조되어 있을 시 삭제 불가): ");
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
				EXEC SQL DELETE FROM NEWS //기본키가 참조된게 없으므로 자기만 삭제하면 된다.
							WHERE NEWSNO=:attribute_num;
		  		
		  	EXEC SQL COMMIT WORK; 
	}
		
}
void insert_data(){
		char table_name[100]={0,};
	
		printf("테이블 이름을 입력하세요 : ");
		scanf("%s",table_name);
		
		if(strcmp(table_name,"INFO") == 0 || strcmp(table_name,"info") == 0 ){ //INFO
			
			printf("인물정보 고유번호  : ");
			scanf("%d",&INFO_INFONO);
			
			printf("이름 : ");
			scanf("%s",INFO_INFONAME);
			
			printf("생년월일 : ");
			scanf("%d",&INFO_INFOBORN);
			
			printf("영역 : ");
			scanf("%s",INFO_INFODOMAIN);
			
		 		EXEC SQL INSERT INTO INFO (INFONO, INFONAME, INFOBORN, INFODOMAIN)
		  		VALUES(:INFO_INFONO, :INFO_INFONAME, :INFO_INFOBORN, :INFO_INFODOMAIN);
		  		
		  	EXEC SQL COMMIT WORK; 	
	}
	
	else if(strcmp(table_name,"PHOTO") == 0 || strcmp(table_name,"photo") == 0 ){ //PHOTO
			
			printf("사진고유 번호 : ");
			scanf("%d",&PHOTO_PHOTONO);
			
			printf("날짜 : ");
			scanf("%d",&PHOTO_PHOTODATE);
			
			printf("가로크기 : ");
			scanf("%d",&PHOTO_PHOTOWIDTH);
			
			printf("세로크기 : ");
			scanf("%d",&PHOTO_PHOTOHEIGHT);
			
			printf("사진사이름 (외부에서 입력된 사진일 경우는 -1을 입력하세요.) : "); //내부 소속일 경우
			scanf("%s",PHOTO_PHOTOGRAPHER);
			
			printf("구입처 (신문사 소속사진사의 사진일 경우는 -1을 입력하세요.) : ");//외부 소속일 경우
			scanf("%s",PHOTO_PHOTOINDENT);
			
			printf("가격 (신문사 소속사진사의 사진일 경우는 -1을 입력하세요.): ");//외부 소속일 경우
			scanf("%d",&PHOTO_PHOTOPRICE);
			
			printf("인물정보고유번호 : (※ 주의 : 해당하는 인물정보가 없으면 삽입되지 않습니다.)");
			scanf("%d",&PHOTO_INFONO);
		
				EXEC SQL INSERT INTO PHOTO  (PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT,PHOTOGRAPHER,PHOTOINDENT,PHOTOPRICE,INFONO)
		 			 VALUES(:PHOTO_PHOTONO, :PHOTO_PHOTODATE, :PHOTO_PHOTOWIDTH, :PHOTO_PHOTOHEIGHT, :PHOTO_PHOTOGRAPHER, :PHOTO_PHOTOINDENT, :PHOTO_PHOTOPRICE, :PHOTO_INFONO);
		
		  EXEC SQL COMMIT WORK;

	}
	else if(strcmp(table_name,"NEWS") == 0 || strcmp(table_name,"news") == 0 ){//NEWS
			
			printf("기사 고유번호 : ");
			scanf("%d",&NEWS_NEWSNO);
			
			printf("제목 : ");
			scanf("%s",&NEWS_NEWSNAME);
			
			printf("작성자 : ");
			scanf("%s",NEWS_NEWSAUTHOR);
			
			printf("발간호 : ");
			scanf("%d",&NEWS_NEWSMAGAZINENO);
			
			printf("사진고유번호 : (※ 주의 : 해당하는 사진이 없으면 삽입되지 않습니다.) ");
			scanf("%d",&NEWS_PHOTONO);
			
			printf("인물정보고유번호: (※ 주의 : 해당하는 인물정보가 없으면 삽입되지 않습니다.)");
			scanf("%d",&NEWS_INFONO);
			
			EXEC SQL INSERT INTO NEWS  (NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO, PHOTONO, INFONO)
		 			 VALUES(:NEWS_NEWSNO, :NEWS_NEWSNAME, :NEWS_NEWSAUTHOR, :NEWS_NEWSMAGAZINENO, :NEWS_PHOTONO, :NEWS_INFONO);
		  		
		  EXEC SQL COMMIT WORK;
	
	}
}

void print_table(){
	int dum;
	int i;
	
	printf("1) 테이블 전체내용 보기\n");
	printf("2) 이름이 메시인 사람의 생년월일과, 기사 제목과 사진 날짜를 출력하시오.\n");
	printf("3) 발간호가 105인 기사의 제목과, 그 기사에 나온 인물의 이름과, 사진의 세로크기를 출력하시오.\n");
	printf("4) 영역이 스포츠에 해당하는 인물에 관한 기사이름과, 사진 날짜 검색\n");
	printf("5) 그림의 가로길이가 400 이상인 사진 중에 발간호가 110 이하인 기사 제목과 그 기사에 나온 인물 이름과 관련 사진 고유번호를 출력하라.\n");
	printf("6) 사진 작가별(혹은 사진작가가 없는 경우)로 그룹화하고, 각 작가의 최대 사진 길이가 400이 넘는 사진작가의 최대 사진가로 길이, 관련 기사의 최신 발간호, 가장 나이가 어린  관련 인물의 생년월일  검색\n");
	printf("7) 발간호로 그룹화하고, 가장 낮은 사진 고유번호가 7이하인 발간호에 대하여 발간호, 가장 낮은 사진 고유번호, 관련 인물 중 가장 나이가 어린 인물의 생년월일을  검색하라.\n");
	
	scanf("%d",&dum);
	switch(dum){
	case 1: //테이블 전체내용 출력 

			//INFO
			printf("info 테이블 보기\n");
			
			//curser 선언
			EXEC SQL DECLARE info_curser CURSOR FOR
							SELECT INFONO,INFONAME,INFOBORN,INFODOMAIN 
							FROM INFO;
			//curser 오픈
			EXEC SQL OPEN info_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH info_curser
							INTO :INFO_INFONO, :INFO_INFONAME, :INFO_INFOBORN, :INFO_INFODOMAIN;
				printf("%d %s %d %s\n",INFO_INFONO,INFO_INFONAME,INFO_INFOBORN,INFO_INFODOMAIN);
			}
			EXEC SQL CLOSE info_curser;
	
		
			//PHOTO
			printf("\nPHOTO 테이블 보기\n");
			//curser 선언
			EXEC SQL DECLARE photo_curser CURSOR FOR
							SELECT PHOTONO, PHOTODATE, PHOTOWIDTH, PHOTOHEIGHT,PHOTOGRAPHER,PHOTOINDENT,PHOTOPRICE,INFONO
							FROM PHOTO;
			//curser 오픈
			EXEC SQL OPEN photo_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH photo_curser
							INTO :PHOTO_PHOTONO, :PHOTO_PHOTODATE, :PHOTO_PHOTOWIDTH, :PHOTO_PHOTOHEIGHT, :PHOTO_PHOTOGRAPHER, :PHOTO_PHOTOINDENT, :PHOTO_PHOTOPRICE, :PHOTO_INFONO;
				printf("%d %d %d %d %s %s %d %d\n",PHOTO_PHOTONO, PHOTO_PHOTODATE, PHOTO_PHOTOWIDTH, PHOTO_PHOTOHEIGHT, PHOTO_PHOTOGRAPHER, PHOTO_PHOTOINDENT, PHOTO_PHOTOPRICE, PHOTO_INFONO);
			}
			EXEC SQL CLOSE photo_curser;


		 	//NEWS
		 	printf("\nNEWS 테이블 보기\n");
		  
			//curser 선언
			EXEC SQL DECLARE news_curser CURSOR FOR
							SELECT NEWSNO, NEWSNAME, NEWSAUTHOR, NEWSMAGAZINENO,PHOTONO,INFONO
							FROM NEWS;
			//curser 오픈
			EXEC SQL OPEN news_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH news_curser
							INTO :NEWS_NEWSNO, :NEWS_NEWSNAME, :NEWS_NEWSAUTHOR, :NEWS_NEWSMAGAZINENO, :NEWS_PHOTONO, :NEWS_INFONO;
				printf("%d %s %s %d %d %d\n",NEWS_NEWSNO, NEWS_NEWSNAME, NEWS_NEWSAUTHOR, NEWS_NEWSMAGAZINENO, NEWS_PHOTONO, NEWS_INFONO);
			}
			EXEC SQL CLOSE news_curser;
			
			break;
		  
	case 2://이름이 메시인 사람의 생년월일과, 기사 제목과 사진 날짜를 출력하시오.
		
			//curser 선언
			EXEC SQL DECLARE inf_curser CURSOR FOR //쿼리문 
						select i.infoborn, n.newsname, p.photodate
						from info i,photo p,news n 
						where i.infono = n.infono and i.infono = p.infono and p.photono = n.photono  and i.infoname='메시';

			
						 	
			//curser 오픈
			EXEC SQL OPEN inf_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH inf_curser
							INTO :INFO_INFOBORN, :NEWS_NEWSNAME, :PHOTO_PHOTODATE; 
				printf("%d %s %d \n",INFO_INFOBORN,NEWS_NEWSNAME,PHOTO_PHOTODATE);
			}
			
			EXEC SQL CLOSE inf_curser;
			break;
	 
	case 3: //발간호가 105인 기사의 제목과, 그 기사에 나온 인물의 이름과, 사진의 세로크기를 출력하시오.
	
			//curser 선언
			EXEC SQL DECLARE news2_curser CURSOR FOR//쿼리문 
						select newsname,infoname,photowidth
						from news n, info i, photo p 
						where n.photono = p.photono and i.infono = n.infono and i.infono = p.infono and newsmagazineno=105;

						 	
			//curser 오픈
			EXEC SQL OPEN news2_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH news2_curser
							INTO :NEWS_NEWSNAME, INFO_INFONAME, PHOTO_PHOTOWIDTH;
				printf("%s %s %d \n",NEWS_NEWSNAME,INFO_INFONAME,PHOTO_PHOTOWIDTH);
			}
			EXEC SQL CLOSE news2_curser;
			
			break;
			
	case 4://영역이 스포츠에 해당하는 인물에 관한 기사이름과, 사진 날짜 검색
			//curser 선언
			EXEC SQL DECLARE news3_curser CURSOR FOR //쿼리문 
							select n.newsname,p.photodate from news n, photo p,info i
 							where p.photono = n.photono and n.infono = i.infono and i.infono = p.infono and i.infono in ( select infono
						  																																														from info
		 									 																																										where infodomain = '스포츠');
	
			//curser 오픈
			EXEC SQL OPEN news3_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH news3_curser
							INTO :NEWS_NEWSNAME,PHOTO_PHOTODATE;
				printf("%s %d \n",NEWS_NEWSNAME,PHOTO_PHOTODATE);
			}
			EXEC SQL CLOSE news3_curser;

	 		break;
	
	 		
	case 5: //그림의 가로길이가 400 이상인 사진 중에 발간호가 110 이하인 기사 제목과 그 기사에 나온 인물 이름과 관련 사진 고유번호(관련 사진이 있다면)를 출력하라.

			//curser 선언
			EXEC SQL DECLARE news4_curser CURSOR FOR //쿼리문 
							SELECT n.newsname, i.infoname, p.photono
							FROM news n, photo p, info i
						 	WHERE n.photono = p.photono and n.infono = i.infono and i.infono = p.infono and n.NEWSMAGAZINENO <= 110 and n.photono in (select photono
		  																										from photo
		 																											where PHOTOWIDTH >= 400);
						 	
			//curser 오픈
			EXEC SQL OPEN news4_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH news4_curser
							INTO :NEWS_NEWSNAME, :INFO_INFONAME, :PHOTO_PHOTONO;
				printf("%s %s %d \n",NEWS_NEWSNAME, INFO_INFONAME, PHOTO_PHOTONO);
			}
			EXEC SQL CLOSE news4_curser;
			break;
			
	case 6: //사진 작가별(혹은 사진작가가 없는 경우)로 그룹화하고, 각 작가의 최대 사진 길이가 400이 넘는 사진작가의 최대 사진가로 길이, 관련 기사의 최신 발간호, 가장 나이가 어린  관련 인물의 생년월일  검색

			//curser 선언
			EXEC SQL DECLARE photo1_curser CURSOR FOR //쿼리문 
							SELECT p.photographer,MAX(p.photowidth), MAX(n.newsmagazineno), MAX(i.infoborn)
							FROM photo p, news n, info i
							where n.photono = p.photono and n.infono = i.infono and i.infono = p.infono
						 	group by p.photographer
 							having MAX(p.photowidth)>=400;
						 	
			//curser 오픈
			EXEC SQL OPEN photo1_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH photo1_curser
							INTO : PHOTO_PHOTOGRAPHER, :PHOTO_PHOTOWIDTH, :NEWS_NEWSMAGAZINENO, :INFO_INFOBORN;
				printf("%s %d %d %d \n",PHOTO_PHOTOGRAPHER, PHOTO_PHOTOWIDTH, NEWS_NEWSMAGAZINENO, INFO_INFOBORN);
			}
			EXEC SQL CLOSE photo1_curser;
			break;
			
		case 7: //발간호로 그룹화하고, 가장 낮은 사진 고유번호가 7이하인 발간호에 대하여 발간호, 가장 낮은 사진 고유번호, 관련 인물 중 가장 나이가 어린 인물의 생년월일을  검색하라.

			//curser 선언
			EXEC SQL DECLARE news5_curser CURSOR FOR //쿼리문 
							SELECT n.NEWSMAGAZINENO, MIN(p.PHOTONO), MAX(i.infoborn)
							FROM photo p, news n, info i
							where n.photono = p.photono and n.infono = i.infono and i.infono = p.infono
						 	group by n.NEWSMAGAZINENO
 							having MIN(n.PHOTONO)<=7;
						 	
			//curser 오픈
			EXEC SQL OPEN news5_curser;
			
			EXEC SQL WHENEVER NOT FOUND DO break;	 
			
			for(;;){
				//curser 패치
				EXEC SQL FETCH news5_curser
							INTO :NEWS_NEWSMAGAZINENO, :PHOTO_PHOTONO, :INFO_INFOBORN;
				printf("%d %d %d \n",NEWS_NEWSMAGAZINENO, PHOTO_PHOTONO, INFO_INFOBORN);
			}
			EXEC SQL CLOSE news5_curser;
			
			break;
			
	default: printf("잘못입력하셨습니다.\n");

	}
}

void ui(){
	printf("1) 테이블 내용 보기\n");
	printf("2) 데이터 삽입하기\n");
	printf("3) 데이터 삭제하기\n");
	printf("4) 데이터 변경하기\n");
	printf("5) 데이터베이스 초기화\n");
	printf("6) 끝내기\n");
}

void main(){ 

	EXEC SQL CONNECT :username IDENTIFIED BY :password; //사용자 ID , PASSWORD 로 연결 시키기 
	
	int dum,dummy;

	do{
		dummy = -1;
		ui();
		scanf("%d",&dum);
		switch(dum){
		case 1: print_table();break; //출력
		case 2: insert_data();break; //삽입
		case 3: delete_data();break; //삭제
		case 4: update_data();break; //수정
		case 5: init_table();break; //초기화
		case 6: break; //끝내기
		default: printf("잘못입력하셨습니다.\n"); //잘못입력 
		}

		while (dummy != 0 && dum!=6){
			printf("처음메뉴로으로 돌아가시겠습니까? (메뉴로 돌아가시려면 0 을 눌려주십시오.)");
			scanf("%d",&dummy);
		}
		
	}while(dum !=6);
}