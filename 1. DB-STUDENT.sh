#!/bin/bash

FILE="student.txt"
touch $FILE

while true
do

echo "========STUDENT DATABASE========"
echo "1. Add Student"
echo "2. View Student"
echo "3. Search Student"
echo "4. Update Student"
echo "5. Delete Student"
echo "6. Exit"
echo "================================="
echo -n "Enter your Choice: "
read choice

case $choice in

1)
echo -n "Enter the roll no.: "
read roll
echo -n "Enter the name: "
read name

echo "$roll,$name" >> FILE
echo "Record Added Successfully"
;;

2)
echo "========ALL RECORDS========"
cat $FILE
;;

3)
echo -n "Enter the roll no. to search: "
read roll
grep "^$roll," $FILE || echo "Data not Found"
;;

4) 
echo -n "Enter the roll no. to update: "
read roll
if grep -q "^$roll," $FILE; then
echo -n "Enter the new name: "
read newname
sed -i "s/^$roll,.*/$roll,$newname/" $FILE
echo "Record Updated successfully"
else
echo "Data not Found"
fi
;;

5)
echo -n "Enter the roll no. to delete: "
read roll
if grep -q "^$roll," $FILE; then
sed -i "/^$roll,/d" $FILE
echo "Record Deleted successfully"
else
echo "Data not Found"
fi
;;

6)
echo "Exiting...."
break
;;

*)
echo "Invalid Choice"
;;

esac
done
