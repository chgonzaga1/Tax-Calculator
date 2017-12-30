#include<iostream>
#include<string>//dont forget to add the string library
#include<iomanip>//sets up setw
using namespace std;

const float fedTax = 0.15;
const float stateTax = 0.35;
const float ssnTax = 0.0575;
const float medTax = 0.0275;
const float healthIns = 75.00;

float contributeFunc(string,float);
float calculateNetPay(float, float, float, float, float, float);

int main()
{
	string name;
	float grossAmt,reducedFed,reducedSSN,reducedMed,reducedState;
	string ans;
	cout << "Hello!, Please enter the gross salary amount:";
	cin >> grossAmt;
	cout << "Please Enter Your Name: ";
	cin >> name;
	cout << "Do you wish to contribute to a 401k? , please type y for Yes, type n for No" << endl;
	cin >> ans;
	float mass = contributeFunc(ans, grossAmt);//you put mass just you can cout this baby
	cout << endl;

	reducedFed = grossAmt * fedTax;
	reducedSSN = grossAmt *ssnTax;
	reducedState = grossAmt*stateTax;
	reducedMed = grossAmt*medTax;


	float netPay = calculateNetPay(grossAmt, reducedFed, reducedSSN, reducedState, reducedMed, healthIns);

	cout << name << endl;
	cout << "------------------------------------------------------------------------" << endl;
	//This will set up into decimal places
	cout << right << "Gross Amount: " << setw(52) << "$"<<fixed<<setprecision(2)<<grossAmt<<endl;
	cout << right << "Federal Tax: " << setw(54) <<"$"<< fixed << setprecision(2) << reducedFed << endl;
	cout << right << "Social Security Tax: " << setw(46) << "$" << fixed << setprecision(2) << reducedSSN<< endl;
	cout << right << "State Tax: " << setw(55) << "$" << fixed << setprecision(2) << reducedState << endl;
	cout << right << "Medical Tax: " << setw(54) << "$" << fixed << setprecision(2) << reducedMed<< endl;
	cout << right << "401k Pension Plan: " << setw(48) << "$" << fixed << setprecision(2) << mass << endl;
	cout << right << "Health Insurance: " << setw(50) << "$" << fixed << setprecision(2) << healthIns << endl;
	cout << right << "Net Pay: " << setw(57) << "$" << fixed << setprecision(2) << netPay << endl;


	return 0;


}



float contributeFunc(string ans, float grossAmt)
{
	float pensionAmt;


	while (ans != "y" || ans != "n")
	{

		if (ans == "y")
		{
			pensionAmt = grossAmt * 0.05;
			return pensionAmt;
		}
		else if (ans == "n")
		{
			pensionAmt = 0;
			return pensionAmt;
		}
		else
		{
			cout << "You put the wrong input!!, Try that again" << endl;

		}

		cout << "Type y for yes or type n for no" <<endl;

		cin >> ans; // this will be a key factor the loop to stop or not


	}



}


//do this late!
//You may not need to use a function. Cause you may have to use a lot of them


float calculateNetPay(float grossAmt, float fedTax, float stateTax, float ssnTax, float medTax, float healthIns)

{



	return(grossAmt - fedTax - stateTax - ssnTax - medTax - healthIns);


}
