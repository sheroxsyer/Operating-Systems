    #include<iostream>
    using namespace std;
    int main() {
    	char grade;
    	double gpa=0.0;
    	cout<<"Enter your Grade=  ";
    	cin>>grade;
    	switch(grade) {
    		case'A':
    		  case'a':
    		  gpa=4.0;
    		cout<<"your GPA is "<<gpa;
    		break;
    		case'B':
    		    case'b':
    		    gpa=3.0;
    		cout<<"your GPA is "<<gpa;
    		break;
    		case'C':
    		     case'c':
    		     gpa=2.0;
    		cout<<"your GPA is "<<gpa;
    		break;
    		case'D':
    		      case'd':
    		      gpa=1.0;
    		cout<<"your GPA is "<<gpa;
    		break;
    		case'F':
    		       case'f':
    		       gpa=0.0;
    		cout<<"your GPA is "<<gpa;
    		break;
    		default:
    		    cout<<"invalid grade entered";
    		break;
    	}
    	return 0;
    }
