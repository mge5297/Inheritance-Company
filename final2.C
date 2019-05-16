/**********************************************
* Program:  final1.C                          *
* Author:   HAPPY STUDENT                     *
* Date:     04/24/19                          *
*                                             *
* Abstract: Final, Spring '19, Part 2         *
**********************************************/
#include <iostream>
#include "Employee.h"

using namespace std;

int main() {
/*********************************************************************************
	This program does payroll information for the "Smith and Smiths" family
	business.  Mary Smith is the president of the company and her husband
	Joe draws a salary as vice-president.  (Everyone but the IRS knows
	that Joe never sets foot in the place!)  Mary has a handful of employees,
	as you will see from the code below.
*********************************************************************************/
	Employee Mary("MJS001", "Mary J. Smith", 5);
	Salary Joe("JJS001", "Joe J. Smith", 5, 100000.00, 'M');
	Manager John("JJS002", "John J. Smith", 4, 75000.00, 'B', "Camry", 2012, "NBR1SON");
	Technician Jane("JJS003", "Jane J. Smith", 4, 80000.00, 'B', "");
	Technician Jack("JJS004", "Jack J. Smith", 3, 70000.00, 'B', "MCSE");
	Hourly Lulu("LLL999", "Lulu L. Lindy", 1, 7.50);

	cout << endl << "Values of objects after they are defined:" << endl;
	cout << Mary << endl;
	cout << Joe << endl;
	cout << John << endl;
	cout << Jane << endl;
 	cout << Jack << endl;
	cout << Lulu << endl;

	cout << endl << "Then everyone gets paid: " << endl;
	cout << "Mary decided to take a \"cut\" ... $100,000.00." << endl;
 	Mary.Pay();
	cout << "Joe was paid $" << Joe.Pay() << endl;
	cout << "John was paid $" << John.Pay() << endl;
 	cout << "Jane was paid $" << Jane.Pay() << endl;
	cout << "Jack was paid $" << Jack.Pay() << endl;
	cout << "Lulu worked 8 hours, Monday through Friday." << endl;
	for (int i = 0; i < 5; i++)
		Lulu.TimeCardEntry(8.0);
	cout << "Then she worked 4.5 hours on Saturday, adding up to " <<
		Lulu.TimeCardEntry(4.5) << " hours." << endl;
	cout << "Lulu was paid $" << Lulu.Pay() << endl;

	cout << endl << "Values of objects after they have been paid:" << endl;
	cout << Mary << endl;
	cout << Joe << endl;
	cout << John << endl;
	cout << Jane << endl;
 	cout << Jack << endl;
	cout << Lulu << endl;

 	cout << endl;
	cout << endl << "Trying the rest of the member functions . . . " << endl;
	// At year end, Mary sees that she has had a GREAT year.  She takes another cut of
	//   the profits, gives Joe a nice travel budget and Jack a modest travel budget.
	//   She gives a bunch of salary increases, and John gets a
	//   new car.  Mary is feeling so happy about her profitable year that she even gives
	//   Lulu a 25 cent an hour raise.  She also sends the technicians away to school
 	//   for additional certifications.
	//   (John decides to get a new set of vanity plates on his own in the hopes of
	//   attracting women!)
	Mary.Pay();
	Joe.SetTravelBudget(15000.00);
 	Joe.SetSalary(120000.00);
	John.SetSalary(85000.00);
 	Jane.SetSalary(90000.00);
  	Jack.SetSalary(80000.00);
	Jack.SetTravelBudget(3000.00);
	if (Jack.SetPayFrequency('D'))
		cout << "Test 1 is NOT working." << endl;
	else
		cout << "Test 1 is working." << endl;
	if (Jack.SetPayFrequency('M'))
		cout << "Test 2 is working." << endl;
	else
		cout << "Test 2 is NOT working." << endl;
	Jack.Pay();
	John.NewCar("BMW", 2019);
	John.NewLicense("RICHGUY");
	Jane.AddCertification("J2EE", 1200.00);
	Jane.AddCertification("MCA", 890.00);
	Jane.AddCertification("CCIE", 520.00);
 	Jack.AddCertification("J2SE", 950.00);
	Lulu.SetPayRate(7.75);
	if (Jane.HasCertification("CCIE") && Jane.HasCertification("MCA"))
		cout << "Test 3 is working." << endl;
	else
		cout << "Test 3 is NOT working." << endl;
	if (Jack.HasCertification("CCIE") || Jack.HasCertification("MCA"))
		cout << "Test 4 is NOT working." << endl;
	else
		cout << "Test 4 is working." << endl;
	cout << "Lulu married Jack and they go on an expensive honeymoon." << endl;
	Lulu.SetName("Lulu L. Lindy-Smith");
	Jack.TripExpense(12534.99);
	
	// The following code tests out the overloaded + and ^ operators 
	cout << "Mary gives Lulu 2 more weeks vacation, making it " << Lulu + 2 << endl;
 	cout << "Mary also gives John 1 more week of vacation, making it " << John + 1 << endl;
	cout << "Mary gives Lulu a 10% pay increase, resulting in $" << (Lulu % .10) << endl;	

	cout << endl;	

	cout << endl << "Values after the other member functions have been tested:" << endl;
	cout << Mary << endl;
	cout << Joe << endl;
	cout << John << endl;
	cout << Jane << endl;
 	cout << Jack << endl;
	cout << Lulu << endl;

 	cout << endl << "The end!" << endl;
	
	// *************************************************************************************
	// ********************PART 2 OF THE FINAL STARTS HERE *********************************
	cout << "***********************************************" << endl;
	cout << "The end of part 1 that is.  Part 2 starts here." << endl;
	cout << "***********************************************" << endl;
	
	cout << "The two new \"getter\" methods give us " << Joe.GetName() << " and $" <<
			Joe.GetSalary() << " for Joe." << endl;
			
	Fulltime Jake("JJS005", "Jake Smith", 3, 10.50, 12);
	Parttime Jill ("JJS006", "Jill Smith", 0, 9.00, 29, true);
	
	cout << "The new objects after they are defined:" << endl; 
	cout << Jake << endl;
	cout << Jill << endl;
	
	
	cout << "After Jake has been there a year, he'll have " << Jake.Anniversary() 
					<< " years of Service." << endl;
	cout << "After a second year, he'll have " << Jake.Anniversary() << " years of Service." << endl;
	Jake.SetPayGrade(14);	// up Jake's pay grade
	Jake.SetPayRate(11.75);
	Jake.TimeCardEntry(40.00);	
	cout << "Jake was paid $" << Jake.Pay() << endl;
	Jill.TimeCardEntry(50.00);	
	cout << "Jill was paid $" << Jill.Pay() << endl;
	
	Jill.TimeCardEntry(25.00);	
	if (Jill.Schedule(4))
		cout << "Test 5 is working." << endl;
	else
		cout << "Test 5 is NOT working." << endl;
	if (Jill.Schedule(5))
		cout << "Test 6 is NOT working." << endl;
	else
		cout << "Test 6 is working." << endl;
	cout << "Jill graduated and is therefore no longer a student." << endl;
	Jill.Graduated();
	Jill.SetMaximum(35);
	cout << "Jill worked another " << (Jill ^ 10.00) << " hours." << endl;
	cout << "Jill worked a little longer, ending with " << (Jill ^ 3.08) 
					<< " hours this week." << endl;
	cout << "Jill was paid $" << Jill.Pay() << endl;
	if (Jake < Jill)
		cout << "Test 7 is working." << endl;
	else
		cout << "Test 7 is NOT working." << endl;
	if (Jane < Jane)
		cout << "Test 8 is NOT working." << endl;
	else
		cout << "Test 8 is working." << endl;
	cout << "\nThe new objects after some methods and overloaded operators:" << endl; 
	cout << Jake << endl;
	cout << Jill << endl;

	
	cout << "\nLet's pay everybody one more time." << endl;
	cout << "Mary decided to take another \"cut\" ... $100,000.00." << endl;
 	Mary.Pay();
	cout << "Joe was paid $" << Joe.Pay() << endl;
	cout << "John was paid $" << John.Pay() << endl;
 	cout << "Jane was paid $" << Jane.Pay() << endl;
	cout << "Jack was paid $" << Jack.Pay() << endl;
	cout << "Lulu worked 8 hours, Monday through Thursday, and 10 on Friday." << endl;
	for (int i = 0; i < 4; i++)
		Lulu.TimeCardEntry(8.0);
	Lulu ^ 10.00;	// She worked 10 more on Fridayu
	cout << "Lulu was paid $" << Lulu.Pay() << endl;
	Jake.TimeCardEntry(50.00);	
	cout << "Jake was paid $" << Jake.Pay() << endl;
	Jill.TimeCardEntry(25.00);	
	cout << "Jill was paid $" << Jill.Pay() << endl;
	
	cout << endl << "Values after the other member functions have been tested:" << endl;
	cout << Mary << endl;
	cout << Joe << endl;
	cout << John << endl;
	cout << Jane << endl;
 	cout << Jack << endl;
	cout << Lulu << endl;
	cout << Jake << endl;
	cout << Jill << endl;

 	cout << endl << "The end!" << endl;
	
 	return 0;
}

