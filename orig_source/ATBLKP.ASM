*  ASMBLR
*  *** THIS PROGRAM LAST MODIFIED FOR VERSION 4, MODIFICATION 0 ***
*
ATBLKP   START 0                  SUBPROGRAM ATBLKP(W,N,M)
*      *                          SEARCHES APT VOCABULARY AND
*      *                          SYNONYMS (IF ANY) FOR THE
*      *                          WORD STORED IN W. IF A VOCABULARY
*      *                          WORD OR SYNONYM IS DISCOVERED, W
*      *                          IS REPLACED BY THE PROTAPE CLASS
*      *                          AND SUBCLASS, AND THE ICLASS
*      *                          INFORMATION IS PLACED IN N. IF
*      *                          NOT, N IS SET TO ZERO. IF W IS
*      *                          A POSTPROCESSOR NAME (CLASS 30),
*      *                          W IS NOT REPLACED. IF M IS SET
*      *                          TO ONE, ONLY THE APT FIXED FIELD
*      *                          VOCABULARY IS SEARCHED.
*      *
         ENTRY ATBLKP
*      *
         EXTRN AXTABL,ASYNTB
*      *
         USING ATBLKP,15
         STM   2,6,28(13)         SAVE SOME GR'S
         LM    1,3,0(1)           LOAD PARAM. ADD. LIST
         XC    0(4,2),0(2)        CLEAR FOUND FLAG
         L     4,0(3)             FIXED FIELD FLAG IN GR4
         L     3,COMADD           ADD. OF VOCAB. TABLE
         LR    5,3
         AH    5,12(3)            LOW INDEX = END OF FIXED FIELD TABLE.
         BCT   4,NOFIX            CHECK FOR FIXED FIELD CALL
FIXF     LA    4,16               YES - INCREMENT TO GR4
         SR    5,4                REDUCE END OF LOOP BY 16
NOTYET   CLC   0(8,1),0(3)        IS THIS A FIXED FIELD WORD OR SYNONYM
         BC    8,GOTHIM           YES
         BXLE  3,4,NOTYET         NO
RET      LM    2,6,28(13)         RESTORE USED GR'S
         BCR   15,14              RETURN
NOFIX    LH    6,14(3)            LENGTH OF REG. VOCAB. TABLE
         AR    6,3                HIGH INDEX = END OF REG. VOCAB. TAB.
HALVE    LR    4,6                SAVE HIGH INDEX IN GR6
         LR    3,5                SAVE LOW INDEX IN GR5
         SR    4,3                DIFFERENCE
         SRL   4,5                HALVE
         SLL   4,4                X 16
         AR    3,4                ADD TO LOW INDEX
         CLC   0(8,1),0(3)        HAVE WE FOUND A VOCAB. WORD
         BC    8,GOTHIM           YES
         BC    4,LOW
         LR    5,3                COMPARE IS HIGH - RESET LOW INDEX
ENDIT    LTR   4,4                END OF VOCAB. SEARCH
         BC    6,HALVE            NO - HALVE TABLE AGAIN
         L     3,COMADD+4         YES - CHECK SYN TABLE - ADD. TO GR3
         CLI   803(3),0           ANY SYNONYMS
         BC    8,RET              NO
         L     5,800(3)           NO. OF SYN ENTRIES
         SLL   5,3                MULTIPLY FOR DOUBLE 8-BYTE ENTRIES
         AR    5,3                END OF SYN TABLE
         BC    15,FIXF            LOOK THROUGH SYN TABLE
LOW      LR    6,3                COMPARE IS LOW - RESET HIGH INDEX
         BC    15,ENDIT           CHECK FOR END
GOTHIM   LH    0,8(3)             SET UP ICLASS
         SLL   0,8
         STH   0,2(2)             CLASS
         LH    0,10(3)            AND
         STH   0,0(2)             SUBCLASS
         CLI   2(2),30            CHECK FOR POSTPROCESSOR NAME
         BC    8,RET              YES - ALL FINISHED
         LH    0,12(3)            NO - SET UP PROTAP
         ST    0,0(1)             SUBCLASS
         LH    0,14(3)            AND
         ST    0,4(1)             CLASS
         BC    15,RET             GO HOME
COMADD   DC    A(AXTABL,ASYNTB)
         END

