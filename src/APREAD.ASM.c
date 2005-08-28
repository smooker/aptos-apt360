#include <assert.h>
#include <f2c.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define QT(x) #x
#define QUOTE(x) QT(x)
#define DIRECTORY_PATH_SPACE 100
void checkForTERMAC(char* card,FILE**);
int apread_(doublereal* inword ,integer* readmode,doublereal *segname ,integer *error)
{

	int i,j;
	char* directoryPath=QUOTE(TOP_BLD_DIR);

	char fullFileName[DIRECTORY_PATH_SPACE
			+8/*"/maclib/"*/
			+8/*sizeof doublereal*/+1];
 
	char card[82]={0};  
	char* inwordPtr;
	char* cardPtr;
	char* fileName= (char*)segname;
	static FILE* file=0;

	if( (strlen(directoryPath)) > (DIRECTORY_PATH_SPACE-1) ){
		fprintf(stderr,"error:maclib directory path too long\n");	
		exit();
	}

	strcpy(fullFileName,directoryPath);
	strcat(fullFileName,"/maclib/");

	if(*readmode==10)return 0;

	if(!file ){
		for(i=0,j=0;i<6;){//get rid of leading blanks:
			if(fileName[i]==' '){
				++i;
			}else{
				fileName[j]=fileName[i];
				++j, ++i;
			}	
		}
		fileName[j]=0;

		strcat(fullFileName,fileName);
		file= fopen(fullFileName,"r");
	}
	if(!file){
		*readmode=0;
		*error=31;
		return 0;
	}
	
// read a 'card': ------------

	inwordPtr=(char*)inword;
	for(i=0;i<96;++i){
		*inwordPtr=' ';
		inwordPtr++;
	}
	inwordPtr=(char*)inword;

	if(!feof(file)){
		fgets(card,82,file);
		//-------convert to upper case----------------
		for (i=0;i<81;++i){
			card[i]=(char)toupper((int)card[i]);
		}
		//--------------------------------------------
		cardPtr=card;
		card[82]=' ';//get rid of null char
		for(i=0;i<14;++i){
			for(j=0;j<6;++j){
				//remove any newlines
				if(*cardPtr!='\n') *inwordPtr=*cardPtr;
				else *inwordPtr=' ';
				cardPtr++;
				inwordPtr++;
			}
			inwordPtr+=2;//leave 2 blanks every 6 chars per original 
		}
		
		checkForTERMAC(card,&file);
	}else {
		fclose(file);
		file=0;
	}
	*error=0;
	return 0;
}

//-----------------------------------------------------------------------------
void checkForTERMAC(char* card,FILE** file)
{
	if(!strncmp(card,"TERMAC",6)){
		fclose(*file);
		*file=0;
	}
}




//-----------------------------------------------------------------------------
/*
*  ASMBLR
*     *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 3 ***
APREAD   START 0
         PRINT NOGEN
*      *
*      * APREAD READS FROM THE PARTITIONED DATA SETS DEFINED IN THE
*      * APTSEG AND APTMAC DD STATEMENTS.  THE MEMBERS IN THE DEFINED
*      * DATA SETS MUST BE LEGITIMATE PART PROGRAMMING STATEMENTS WITH
*      * A LRECL OF 80 CHARACTERS.  THE BLKSIZE MAY BE ANY REASONABLE
*      * MULTIPLE OF 80 CHARACTERS AND THE RECFM MUST BE F OR FB.
*      *
*      * A READ SEGMENT IS INCLUDED IN PART PROGRAMS BY A READ/2,XXXXXX
*      * STATEMENT WHERE XXXXXX IS THE MEMBER NAME IN THE PDS.  THE
*      * SEGMENT IS PROCESSED SEQUENTIALLY UNTIL EODATA IS REACHED,
*      * AT WHICH TIME THE NORMAL MODE IS RESET.
*      *
*      * THE SYSTEM MACRO IS RETRIEVED ONLY FOR THE FIRST CALL TO THAT
*      * MACRO.  THE MACRO IS READ SEQUENTIALLY UNTIL A TERMAC
*      * IS FOUND.  IF NO TERMAC IS FOUND, AN ERROR IS FLAGGED AND THE
*      * NORMAL READ MODE IS RESET.
*      *
*      * PARAMETER LIST: (INWORD,IRDMOD,SEGNAM,JSUBER)
*      *
*      * INWORD - AREA ADDRESS WHERE RECORD IS TO BE STORED
*      * IRDMOD - =1, SEGMENT READ MODE; =-1, SYSTEM MACRO MODE
*      *          =2, LEAVE SEGMENT READ DATA IN A8 FORMAT
*      *          =10, CLOSE APTSEG AND APTMAC DCBS
*      * SEGNAM - ADDRESS OF 8-BYTE NAME OF MEMBER TO BE READ
*      * JSUBER - SET TO 31 IF MEMBER NOT FOUND; TO 32 ON I/O ERROR
*      *          SET TO 36 IF SYSTEM MACRO HAD NO TERMAC STATEMENT
*      *
*      *
*      *
         USING APREAD,12
         BC    15,12(15)
         DC    X'07'
         DC    C' APREAD'
         STM   14,12,12(13)       SAVE, ...
         LR    12,15
         LR    8,13
         LA    13,SA
         ST    13,8(8)
         ST    8,SA+4
         LM    2,5,0(1)           PICK UP PARAMETER ADDR LIST
         L     11,0(3)            LOAD IRDMOD VALUE
         C     11,=F'10'          TEST IF DATASETS ARE TO BE CLOSED
         BE    CLOSEMAC
         C     11,=F'-1'          TEST IF SYSTEM MACRO
         BH    SEGREAD
         LA    11,APTMAC          GET DCB ADDR FOR SYS1.APTMACRO
         LA    6,MACROBUF
         MVC   BLOCK(4),MACROBUF
         B     TESTOPEN
SEGREAD  LA    11,APTSEG          GET DCB ADDR FOR SYS1.APTSEG
         LA    6,SEGMTBUF
         MVC   BLOCK(4),SEGMTBUF
         USING IHADCB,11          BASE FOR DCB DSECT
TESTOPEN TM    DCBOFLGS,X'10'     TEST IF FILE OPEN
         BC    1,NEWOROLD         BRANCH IF YES
OPENDCB  OPEN  ((11),INPUT)
         TM    DCBOFLGS,X'10'     SUCCESSFULLY?
         BC    8,ERROR2           NO
         LH    0,DCBBLKSI         BLKSIZE TO GR0
         GETMAIN R,LV=(0)         GET STORAGE FOR RECORD BLOCK
         ST    1,BLOCK            SAVE ADD. OF BLOCK
         ST    1,0(6)             STORE ADDR OF GETMAIN AREA
FIND     LR    6,4                REG 4 CONTAINS ADDR OF MEMBER NAME
         LA    7,6                CANNOT HAVE 6 BLANKS IN NAME
         SR    8,8                BLANK COUNTER
ISBLNK   CLI   0(6),X'40'         CHECK FOR BLANK
         BC    6,NOBLNK           NO MORE BLANKS
         LA    8,1(8)             UP BLANK COUNTER
         LA    6,1(6)             UP INDEX
         BCT   7,ISBLNK           BACK FOR MORE
         BC    15,ERROR1          NO NAME GIVEN
NOBLNK   MVC   MEMBER+2(6),BLANKS BLANK OUT NAME AREA
         LA    7,7                SET
         SR    7,8                MOVE
         STC   7,*+5              LENGTH
         MVC   MEMBER(0),0(6)     PUT IN LEFT ADJUSTED MEMBER NAME
         MVC   MEMNAM(8),0(4)     MEMNAM = SEGNAM
         FIND  (11),MEMBER,D      ISSUE FIND TO POSITION DATASET
         LTR   15,15              SUCCESSFUL?
         BC    6,ERROR1           NO
         L     9,BLOCK            ADD. OF RECORD BLOCK TO GR9
GETBLK   XC    RECPNT,RECPNT      YES - RESET LOGICAL RECORD POINTER
         READ  SEGDECB,SF,(11),(9)
         CHECK SEGDECB            CHECK I/O OPERATION
         L     8,SEGDECB+16       ADDRESS OF STATUS INDICATOR
         LH    7,DCBBLKSI         BLKSIZE
         SH    7,14(8)            MINUS RESIDUAL COUNT
         STH   7,EOBPNT           YIELDS BYTES IN BLOCK
         USING INWORD,2           GR 2 CONTAINS REMOTE ARRAY ADD.
GETREC   LH    7,EOBPNT           PICK UP POINTER TO END-OF-BLOCK
         LH    6,RECPNT           LOGICAL RECORD POINTER
         L     9,BLOCK            ADD. OF RECORD BLOCK TO GR9
         CR    6,7                END OF BLOCK?
         BC    8,GETBLK           YES
         AR    9,6                NO - MOVE LOGICAL RECORD
         MVC   INWORD(80),0(9)    TO ARRAY
         LA    6,80(6)            INCREMENT LOGICAL RECORD
         STH   6,RECPNT           POINTER
         L     6,0(3)
         C     6,=F'2'            TEST IF RECORD SHOULD BE LEFT A8
         BE    RET                BRANCH IF YES
UNPAK    LA    6,6                UNPACK TO A6,A2 FORMAT
         LA    8,8
         LA    7,13               UNPACK TO 13 DOUBLE WORDS
         MVC   INWD14(2),INWD10+6 FORMAT WORD 13
         MVC   INWD14+2(6),BLANKS
         LA    9,INWD10           FROM ADD.
         LA    10,INWD13          TO ADD.
MOVEM    MVC   TEMP8(6),0(9)      MOVE TO TEMP. LOC. - AVOID CLOBBER
         MVC   0(8,10),TEMP8      MOVE TO INPUT ARRAY - ADD BLANKS
         SR    10,8               DECREMENT
         SR    9,6                POINTERS
         BCT   7,MOVEM            CONTINUE
RET      L     13,SA+4            RESTORE, ETC.
         LM    14,12,12(13)
         MVI   12(13),X'FF'
         BCR   15,14
ENDMEM   SR    6,6                END OF PDS MEMBER
         CLC   0(4,3),=F'-1'      TEST IF SYSTEM MACRO
         BNE   ZEROJSBR           BRANCH IF NOT SYSTEM MACRO
         LA    6,36               JSUBER = 36
ZEROJSBR ST    6,0(5)             SET JSUBER TO 0 OR 36
         XC    0(4,3),0(3)        SET IRDMOD TO ZERO
         MVC   MEMNAM(6),BLANKS   RESET MEMBER NAME
         BC    15,RET             RETURN HAPPY
NEWOROLD CLC   MEMNAM(8),0(4)     ARE WE ALREADY READING FROM THIS SEG.
         BE    GETREC             BRANCH IF YES
         B     FIND
ERROR1   LA    7,31               JSUBER = 31   (MEMBER NOT FOUND)
         BC    15,ERREX
ERROR2   LA    7,32               JSUBER = 32   (I/O ERROR)
ERREX    ST    7,0(5)             SET JSUBER TO ERROR NUMBER
         MVC   MEMNAM(6),BLANKS   RESET MEMBER NAME
         XC    0(4,3),0(3)        SET IRDMOD TO ZERO
         B     RET
CLOSEMAC LA    11,APTMAC
         TM    DCBOFLGS,X'10'     TEST IF SYSTEM MACRO LIBRARY IS OPEN
         BZ    CLOSESEG
         LH    0,DCBBLKSI
         L     1,MACROBUF
         FREEMAIN R,LV=(0),A=(1)  FREE GETMAIN AREA FOR SYSTEM MACROS
         CLOSE ((11))             CLOSE SYSTEM MACRO LIBRARY
CLOSESEG LA    11,APTSEG
         TM    DCBOFLGS,X'10'     TEST IF SEGMENT LIBRARY IS OPEN
         BZ    RET
         LH    0,DCBBLKSI
         L     1,SEGMTBUF
         FREEMAIN R,LV=(0),A=(1)  FREE GETMAIN AREA FOR SEGMENT READ
         CLOSE ((11))             CLOSE SEGMENT LIBRARY
         B     RET
APTSEG   DCB   DDNAME=APTSEG,DSORG=PO,EODAD=ENDMEM,MACRF=R,SYNAD=ERROR2
APTMAC   DCB   DDNAME=APTMAC,DSORG=PO,EODAD=ENDMEM,MACRF=R,SYNAD=ERROR2
         DS    0D
MEMBER   DS    D
MEMNAM   DC    CL8'        '
BLOCK    DS    F                  ADD. OF RECORD BLOCK
MACROBUF DC    F'0'
SEGMTBUF DC    F'0'
SA       DS    18F                GR SAVE AREA
EOBPNT   DS    H
RECPNT   DS    H
TEMP8    DS    CL6
BLANKS   DC    CL6'      '
INWORD   DSECT
         DS    9D
INWD10   DS    D
         DS    2D
INWD13   DS    D
INWD14   DS    D
         DCBD  DSORG=PO,DEVD=DA
         END
*/
