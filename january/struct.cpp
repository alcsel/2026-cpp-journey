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
    student1.name = "(name)";
    student1.age = 20;
    student1.grade = '56';
    cout<<"Name: "<<student1.name<<endl;
    cout<<"Age: "<<student1.age<<endl;
    cout<<"Grade: "<<student1.grade<<endl;
    return 0;

}
