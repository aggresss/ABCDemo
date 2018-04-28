# Write a bash script to calculate the frequency of each word in a text file words.txt.
# For simplicity sake, you may assume:
#   words.txt contains only lowercase characters and space ' ' characters.
#   Each word must consist of lowercase characters only.
#   Words are separated by one or more whitespace characters.

awk '
{
    for(i=1;i<=NF;i++)
        words[$i]++
} 
END{
    for(word in words)
        print word,words[word]
}' RS="[ \n]+" words.txt  | sort -nrk2
