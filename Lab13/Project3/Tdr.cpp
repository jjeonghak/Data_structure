#include <iostream>
#include "Student.h"
#include "HashTable.h"

using namespace std;

int main() {
	Student stu[100];
	HashTable<Student> ht;
	Student item;
	bool found = false;
	char* studentName = new char[30];

	stu[0].InitValue(2003200111, (char*)"이웅재", 3.0);
	stu[1].InitValue(2004200121, (char*)"권오준", 3.2);
	stu[2].InitValue(2005200132, (char*)"김진일", 2.7);
	stu[3].InitValue(2006200140, (char*)"박완용", 4.1);
	stu[4].InitValue(2003200200, (char*)"최진영", 1.1);
	stu[5].InitValue(2003200209, (char*)"박완용", 3.5);
	stu[6].InitValue(2003200210, (char*)"김일성", 0.8);
	stu[7].InitValue(2001200201, (char*)"이승완", 1.8);
	stu[8].InitValue(2007200207, (char*)"정영재", 3.8);
	stu[9].InitValue(2001200215, (char*)"유지은", 3.3);

	for (int i = 0; i < 10; i++)
		ht.InsertItem(stu[i]);

	cout << "Enter Student name: ";
	cin >> studentName;
	item.InitValue(0, studentName, 0);
	ht.RetrieveItem(item, found);
	if (found == true) {
		cout << "Find Student: " << endl;
		item.Print(cout);
	}
	else
		cout << "Not Found\n";
	delete[] studentName;
	return 0;
}