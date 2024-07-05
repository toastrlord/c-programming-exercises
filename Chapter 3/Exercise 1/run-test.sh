# for use with K&C Chapter 3 Exercise 1
#
cc $1 -o a.out
cc $2 -o b.out

echo $1:
echo $(time ./a.out)

echo $2:
echo $(time ./b.out)

