#include<iostream>
#include<string>

using namespace std;
struct student  {
    string name;
    int age;
    char grade;
};
int main(){
    student student1;
    student1.name = "selim";
    student1.age = 19;
    student1.grade = '2';
    cout<<"Name: "<<student1.name<<endl;
    cout<<"Age: "<<student1.age<<endl;
    cout<<"Grade: "<<student1.grade<<endl;
    return 0;
}