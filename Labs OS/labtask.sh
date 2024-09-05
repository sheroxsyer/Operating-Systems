#!/bin/bash
echo "Grades And GPA Calculator"

# declare grade
read -p "Enter your grade: " grade

# declare gpa=0.0
gpa=0.0

case $grade in
    A)
        echo "Your Grade is A"
        echo "Your GPA is: 4.0"
        gpa=4.0
        ;;
    B)
        echo "Your Grade is B"
        echo "Your GPA is: 3.0"
        gpa=3.0
        ;;
    C)
        echo "Your Grade is C"
        echo "Your GPA is: 2.0"
        gpa=2.0
        ;;
    D)
        echo "Your Grade is D"
        echo "Your GPA is: 1.0"
        gpa=1.0
        ;;
    F)
        echo "Your Grade is F"
        echo "Your GPA is: 0.0"
        echo "Register for the course again next semester"
        ;;
    *)
        echo "Your Grade is Invalid"
        echo "Please type a valid Grade"
        ;;
esac

echo "Your GPA is: $gpa"
exit 0

