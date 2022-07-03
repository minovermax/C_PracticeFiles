# enter file to run in WORKING_ON
export WORKING_ON="stack"

gcc $WORKING_ON.c -o $WORKING_ON
chmod 744 $WORKING_ON
./$WORKING_ON

# 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