TARGET	= prog1
CC	= gcc
PROC	= proc
LIB	= -L$(ORACLE_HOME)/lib -lclntsh
MYINC	= include/
CINC	= -I$(ORACLE_HOME)/precomp/public/ -I$(ORACLE_HOME)/rdbms/demo/ \
	-I$(ORACLE_HOME)/rdbms/public/ -I$(ORACLE_HOME)/network/public/ 
ORA_OPT         = PARSE=NONE RELEASE_CURSOR=YES MODE=ORACLE
CC_OPT          =
OBJECT         = $(TARGET).o
ORA_GARBAGE     = *.dcl *.cod *.cud *.lis

.SUFFIXES: .pc .c

.pc.c:
#$(PROC) $* INCLUDE=$(MYINC) $(PROCINC) $(ORA_OPT)
#$(PROC) SQLCHECK=SEMANTICS USERID=shlee/shlee $* 
	$(PROC) $* 

.c.o:
	$(CC) -c -o $*.o $*.c -I $(MYINC) $(CINC)

all : $(TARGET)

$(TARGET):      $(OBJECT)
	$(CC) -o $(TARGET) $(OBJECT) $(LIB)

clean:
	rm -f $(TARGET) $(OBJECT) $(ORA_GARBAGE)

