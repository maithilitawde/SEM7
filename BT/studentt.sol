// SPDX-License-Identifier: MIT
pragma solidity >=0.6.12 <0.9.0;

contract StudentData {

  struct Student{
    uint stud_id;
    string name;
    string department;
  }
  
  Student[] students;

  function addStudent(uint id , string memory stud_name , string memory stud_dept)  public {
    Student memory newStudent = Student(id, stud_name , stud_dept);
    students.push(newStudent);

  }

  function getData(uint id) public view returns(string memory , string memory)
  {
    for(uint i = 0 ; i<students.length ; i++)
    {
      if(students[i].stud_id == id)
      {
        return(students[i].name , students[i].department);
      }
    }
    return ("No Name Found" , "No Department Found");
  }

  function getNum() public view returns(uint)
  {
    return students.length;
  }

  receive() external payable { 
    students.push(Student(1 , 'ABC' , 'DEF'));
  }
}
      