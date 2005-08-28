*  ASMBLR
ATAPXC   START 0
         ENTRY TAPECH
BASE     EQU   *
TAPECH   SAVE  (2,12),T
         USING BASE,15
         L     3,0(1,0)      ADDRESS OF DATASET1
         L     4,4(1,0)      ADDRESS  OF DATASET2
         LD    0,0(3,0)
         LD    2,0(4,0)
         STD   0,0(4,0)
         STD   2,0(3,0)
         RETURN (14,12),T
         END

