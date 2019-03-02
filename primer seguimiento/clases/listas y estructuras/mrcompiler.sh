

echo "MrRomo Compiler****" $1

file=$1
filec="${file//.c/ }"

echo "compilando $file"

mkdir output

gcc -o output/$filec -lm $file

./output/$filec