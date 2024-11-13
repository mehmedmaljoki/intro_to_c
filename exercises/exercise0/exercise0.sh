
# this should print "success"
true && (exit 0) && echo "success"
# this should print nothing
false || (exit 0) || echo "success"
# this shold also print nothing
(exit 0) && (exit 1) && echo "success"
# this should print "foobar\nsuccess"
echo "foobar" | grep "foo" && echo "success"
# this should print nothing
echo "foobar" | grep "fobar" && echo "success"

echo "---------------------"
echo "How do you have to modify the lines that print nothing so they print success?"
echo "---------------------"

# this should print "success"
true && (exit 0) && echo "success"
# this should print "success"
true && (exit 0) && echo "success"
# this shold also print "success"
(exit 0) && (exit 0) && echo "success"
# this should print "foobar\nsuccess"
echo "foobar" | grep "foo" && echo "success"
# this should print "foobar\nsuccess"
echo "foobar" | grep "foobar" && echo "success"


echo "---------------------"
echo "How do you get the lines that print success, to not print anything? (without removing echo)"
echo "---------------------"

# this should print "nothing"
true && (exit 1) && echo "success"
# this should print nothing
false || (exit 0) || echo "success"
# this shold also print nothing
(exit 0) && (exit 1) && echo "success"
# this should print "nothing"
echo "foobar" | grep "fob" && echo "success"
# this should print nothing
echo "foobar" | grep "fobar" && echo "success"


echo "---------------------"
echo "You can use the output of a command to build another command line: for example"

echo Today is a $(date +%A) and the month is $(date +%B)

echo "----- The file main.c is 535 bytes long ------"
filename="les.txt"
filename2="newLes.txt"
echo "The file $filename is $(wc -c < "$filename" | awk '{print $1}') bytes long"
echo "The file $filename2 is $(wc -c < "$filename2" | awk '{print $1}') bytes long"

echo "---------------------"
echo "Next, try printing a line that gives the combined length of multiple files, for example, all those ending in .c.
      It should print something like: The files list.c main.c combined are 2862 bytes long"
total_bytes=$(wc -c "$filename" "$filename2" | awk 'END {print $1}')
echo "The files $filename $filename2 combined are $total_bytes bytes long"



