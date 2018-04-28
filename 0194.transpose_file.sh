# Given a text file file.txt, transpose its content.
# You may assume that each row has the same number of columns and each field is separated by the ' ' character.

# NF - Number of Field
# NR - Number of Record
# FS - Field Separator
# RS - Record Separator

awk '
{
    for(i=1;i<=NF;i++)
        a[NR,i]=$i
}
END{
    for(j=1;j<=NF;j++)
        for(k=1;k<=NR;k++)
            printf k==NR?a[k,j] RS:a[k,j] FS
}' file.txt
