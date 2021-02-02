#define _WIN32_WINNT _WIN32_WINNT_WINXP // Enables Windows XP compatibility
#include <iostream>
#include <fstream>
#include <iomanip>

#pragma pack(1)

using namespace std;

int AlterAmount;

bool LeapYearCheck(int Year) {
	return ((Year % 4 == 0 && Year % 100 != 0) || ( Year % 400 == 0));
}

int staff() {

	fstream dat_staff ("staff.dat", ios::in | ios::out | ios::binary);

	if ( dat_staff.is_open() ) {

		dat_staff.seekg (0, ios::end);
		auto filelength = dat_staff.tellg();

		int pos = 0;

		short newDay;
		short newYear;
		bool newLeapYear;

		int pos_dobDay;
		short dobDay;
		int pos_dobYear;		
		short dobYear;
		int pos_dobLeapYear;
		bool dobLeapYear;

		int pos_joinedDay;
		short joinedDay;
		int pos_joinedYear;
		short joinedYear;
		int pos_joinedLeapYear;
		bool joinedLeapYear;

		int pos_contractDay;
		short contractDay;
		int pos_contractYear;
		short contractYear;
		int pos_contractLeapYear;
		bool contractLeapYear;

		int pos_yobYear;
		short yobYear;
				
		while(pos < filelength) {

			pos_dobDay = pos + 60;
			pos_dobYear = pos + 62;
			pos_dobLeapYear = pos + 64;

			pos_joinedDay = pos + 75;
			pos_joinedYear = pos + 77;
			pos_joinedLeapYear = pos + 79;

			pos_contractDay = pos + 80;
			pos_contractYear = pos + 82;
			pos_contractLeapYear = pos + 84;

			pos_yobYear = pos + 90;

			/* Date of birth */

				// Year
				dat_staff.seekg(pos_dobYear, ios::beg);
				dat_staff.read((char*)&dobYear, 2);

				// Year of birth
				dat_staff.seekg(pos_yobYear, ios::beg);
				dat_staff.read((char*)&yobYear, 2);

				if (dobYear > 1900) {
					// Day
					dat_staff.seekg(pos_dobDay, ios::beg);
					dat_staff.read((char*)&dobDay, 2);
					// Leap year
					dat_staff.seekg(pos_dobLeapYear, ios::beg);
					dat_staff.read((char*)&dobLeapYear, 1);

					// Year
					newYear = dobYear - AlterAmount;
					if (newYear < 1901) { newYear = 1901; }
					// Leap year
					newLeapYear = LeapYearCheck(newYear);
					// Day
					if (dobDay > 59) { newDay = dobDay + (newLeapYear - LeapYearCheck(dobYear)); }
					else newDay = dobDay;

					// Day
					dat_staff.seekp(pos_dobDay, ios::beg);
					dat_staff.write((char*)&newDay, 2);
					// Year
					dat_staff.seekp(pos_dobYear, ios::beg);
					dat_staff.write((char*)&newYear, 2);
					// Leap year
					dat_staff.seekp(pos_dobLeapYear, ios::beg);
					dat_staff.write((char*)&newLeapYear, 1);

					/* Year of birth */
					dat_staff.seekp(pos_yobYear, ios::beg);
					dat_staff.write((char*)&newYear, 2);
				}
				else if (yobYear > 1900) {
					newYear = yobYear - AlterAmount;
					if (newYear < 1901) { newYear = 1901; }

					dat_staff.seekp(pos_yobYear, ios::beg);
					dat_staff.write((char*)&newYear, 2);
				}

			/* Date joined club */
				
				// Year
				dat_staff.seekg(pos_joinedYear, ios::beg);
				dat_staff.read((char*)&joinedYear, 2);				

				if (joinedYear > 1900) {
					// Day
					dat_staff.seekg(pos_joinedDay, ios::beg);
					dat_staff.read((char*)&joinedDay, 2);
					// Leap year
					dat_staff.seekg(pos_joinedLeapYear, ios::beg);
					dat_staff.read((char*)&joinedLeapYear, 1);

					// Year
					newYear = joinedYear - AlterAmount;
					if (newYear < 1901) { newYear = 1901; }
					// Leap year
					newLeapYear = LeapYearCheck(newYear);
					// Day
					if (joinedDay > 59) { newDay = joinedDay + (newLeapYear - LeapYearCheck(joinedYear)); }
					else newDay = joinedDay;

					// Day
					dat_staff.seekp(pos_joinedDay, ios::beg);
					dat_staff.write((char*)&newDay, 2);
					// Year
					dat_staff.seekp(pos_joinedYear, ios::beg);
					dat_staff.write((char*)&newYear, 2);
					// Leap year
					dat_staff.seekp(pos_joinedLeapYear, ios::beg);
					dat_staff.write((char*)&newLeapYear, 1);
				}

			/* Contract expiry date */

				// Year
				dat_staff.seekg(pos_contractYear, ios::beg);
				dat_staff.read((char*)&contractYear, 2);				

				if (contractYear > 1900) {
					// Day
					dat_staff.seekg(pos_contractDay, ios::beg);
					dat_staff.read((char*)&contractDay, 2);
					// Leap year
					dat_staff.seekg(pos_contractLeapYear, ios::beg);
					dat_staff.read((char*)&contractLeapYear, 1);

					// Year
					newYear = contractYear - AlterAmount;
					if (newYear < 1901) { newYear = 1901; }
					// Leap year
					newLeapYear = LeapYearCheck(newYear);
					// Day
					if (contractDay > 59) { newDay = contractDay + (newLeapYear - LeapYearCheck(contractYear)); }
					else newDay = contractDay;

					// Day
					dat_staff.seekp(pos_contractDay, ios::beg);
					dat_staff.write((char*)&newDay, 2);
					// Year
					dat_staff.seekp(pos_contractYear, ios::beg);
					dat_staff.write((char*)&newYear, 2);
					// Leap year
					dat_staff.seekp(pos_contractLeapYear, ios::beg);
					dat_staff.write((char*)&newLeapYear, 1);
				}

			pos += 116;
		}
		dat_staff.close();
		cout << "DONE" << endl;
	}

	else {
		cout << "ERROR: Unable to open file" << endl; 
		return 1;
	}

	return 0;
}

int staff_history() {

	fstream dat_staff_history ("staff_history.dat", ios::in | ios::out | ios::binary);

	if ( dat_staff_history.is_open() ) {

		dat_staff_history.seekg (0, ios::end);
		auto filelength = dat_staff_history.tellg();

		int pos = 0;
		int pos_Year;

		short historyYear;
		short newYear;

		while(pos < filelength) {

			pos_Year = pos + 16;

			dat_staff_history.seekg(pos_Year, ios::beg);
			dat_staff_history.read((char*)&historyYear, 2);

			if (historyYear > 1900) {

				newYear = historyYear - AlterAmount;
				if (newYear < 1901) { newYear = 1901; }

				dat_staff_history.seekp(pos_Year, ios::beg);
				dat_staff_history.write((char*)&newYear, 2);
			}

			pos += 37;
		}
		dat_staff_history.close();
		cout << "DONE" << endl;
	}

	else {
		cout << "ERROR: Unable to open file" << endl; 
		return 1;
	}	

	return 0;
}

int club_comp_history() {

	fstream dat_club_comp_history ("club_comp_history.dat", ios::in | ios::out | ios::binary);

	if ( dat_club_comp_history.is_open() ) {

		dat_club_comp_history.seekg (0, ios::end);
		auto filelength = dat_club_comp_history.tellg();

		int pos = 0;
		int pos_Year;

		short historyYear;
		short newYear;

		while(pos < filelength) {

			pos_Year = pos + 28;

			dat_club_comp_history.seekg(pos_Year, ios::beg);
			dat_club_comp_history.read((char*)&historyYear, 2);

			if (historyYear > 1900) {

				newYear = historyYear - AlterAmount;
				if (newYear < 1901) { newYear = 1901; }

				dat_club_comp_history.seekp(pos_Year, ios::beg);
				dat_club_comp_history.write((char*)&newYear, 2);
			}

			pos += 30;
		}
		dat_club_comp_history.close();
		cout << "DONE" << endl;
	}

	else {
		cout << "ERROR: Unable to open file" << endl; 
		return 1;
	}	

	return 0;
}

int nation_comp_history() {

	fstream dat_nation_comp_history ("nation_comp_history.dat", ios::in | ios::out | ios::binary);

	if ( dat_nation_comp_history.is_open() ) {

		dat_nation_comp_history.seekg (0, ios::end);
		auto filelength = dat_nation_comp_history.tellg();

		int pos = 0;
		int pos_Year;

		short historyYear;
		short newYear;

		while(pos < filelength) {

			pos_Year = pos + 28;

			dat_nation_comp_history.seekg(pos_Year, ios::beg);
			dat_nation_comp_history.read((char*)&historyYear, 2);

			if (historyYear > 1900) {

				newYear = historyYear - AlterAmount;
				if (newYear < 1901) { newYear = 1901; }

				dat_nation_comp_history.seekp(pos_Year, ios::beg);
				dat_nation_comp_history.write((char*)&newYear, 2);
			}

			pos += 30;
		}
		dat_nation_comp_history.close();
		cout << "DONE" << endl;
	}

	else {
		cout << "ERROR: Unable to open file" << endl; 
		return 1;
	}	

	return 0;
}

int staff_comp_history() {

	fstream dat_staff_comp_history ("staff_comp_history.dat", ios::in | ios::out | ios::binary);

	if ( dat_staff_comp_history.is_open() ) {

		dat_staff_comp_history.seekg (0, ios::end);
		auto filelength = dat_staff_comp_history.tellg();

		int pos = 0;
		int pos_Year;

		short historyYear;
		short newYear;

		while(pos < filelength) {

			pos_Year = pos + 56;

			dat_staff_comp_history.seekg(pos_Year, ios::beg);
			dat_staff_comp_history.read((char*)&historyYear, 2);

			if (historyYear > 1900) {

				newYear = historyYear - AlterAmount;
				if (newYear < 1901) { newYear = 1901; }

				dat_staff_comp_history.seekp(pos_Year, ios::beg);
				dat_staff_comp_history.write((char*)&newYear, 2);
			}

			pos += 58;
		}
		dat_staff_comp_history.close();
		cout << "DONE" << endl;
	}

	else {
		cout << "ERROR: Unable to open file" << endl; 
		return 1;
	}	

	return 0;
}

int drafted_players() {

	fstream dat_drafted_players ("drafted_players.dat", ios::in | ios::out | ios::binary);

	if ( dat_drafted_players.is_open() ) {

		dat_drafted_players.seekg (0, ios::end);
		auto filelength = dat_drafted_players.tellg();

		int pos = 0;
		int pos_Year;

		short draftedYear;
		short newYear;

		while(pos < filelength) {

			pos_Year = pos + 16;

			dat_drafted_players.seekg(pos_Year, ios::beg);
			dat_drafted_players.read((char*)&draftedYear, 2);

			if (draftedYear > 1900) {

				newYear = draftedYear - AlterAmount;
				if (newYear < 1901) { newYear = 1901; }

				dat_drafted_players.seekp(pos_Year, ios::beg);
				dat_drafted_players.write((char*)&newYear, 2);
			}

			pos += 21;
		}		
		dat_drafted_players.close();
		cout << "DONE" << endl;
	}

	else {
		cout << "ERROR: Unable to open file" << endl; 
		return 1;
	}	

	return 0;
}

int club_histories() {

	fstream dat_club_histories ("club_histories.dat", ios::in | ios::out | ios::binary);

	if ( dat_club_histories.is_open() ) {

		dat_club_histories.seekg (0, ios::end);
		auto filelength = dat_club_histories.tellg();

		int pos = 0;
		int pos_Year;

		short historiesYear;
		short newYear;

		while(pos < filelength) {

			pos_Year = pos + 12;

			dat_club_histories.seekg(pos_Year, ios::beg);
			dat_club_histories.read((char*)&historiesYear, 2);

			if (historiesYear > 1900) {

				newYear = historiesYear - AlterAmount;
				if (newYear < 1901) { newYear = 1901; }

				dat_club_histories.seekp(pos_Year, ios::beg);
				dat_club_histories.write((char*)&newYear, 2);
			}

			pos += 58;
		}
		dat_club_histories.close();
		cout << "DONE" << endl;
	}

	else {
		cout << "ERROR: Unable to open file" << endl; 
		return 1;
	}	

	return 0;
}

int club_records() {

	fstream dat_club_records ("club_records.dat", ios::in | ios::out | ios::binary);

	if ( dat_club_records.is_open() ) {

		dat_club_records.seekg (0, ios::end);
		auto filelength = dat_club_records.tellg();

		int pos = 0;
		int pos_Year[15];

		short recordsYear;
		short newYear;

		while(pos < filelength) {

			pos_Year[0] = pos + 10;
			pos_Year[1] = pos + 13;
			pos_Year[2] = pos + 16;
			pos_Year[3] = pos + 20;
			pos_Year[4] = pos + 24;
			pos_Year[5] = pos + 28;
			pos_Year[6] = pos + 31;
			pos_Year[7] = pos + 35;
			pos_Year[8] = pos + 51;
			pos_Year[9] = pos + 67;
			pos_Year[10] = pos + 83;
			pos_Year[11] = pos + 98;
			pos_Year[12] = pos + 113;
			pos_Year[13] = pos + 129;
			pos_Year[14] = pos + 243;

			for (int i = 0; i < 15; ++i) {

				dat_club_records.seekg(pos_Year[i], ios::beg);
				dat_club_records.read((char*)&recordsYear, 2);

				if (recordsYear > 1900) {

					newYear = recordsYear - AlterAmount;
					if (newYear < 1901) { newYear = 1901; }

					dat_club_records.seekp(pos_Year[i], ios::beg);
					dat_club_records.write((char*)&newYear, 2);
				}
			}
			pos += 257;
		}
		dat_club_records.close();
		cout << "DONE" << endl;
	}

	else {
		cout << "ERROR: Unable to open file" << endl; 
		return 1;
	}	

	return 0;
}

int main() {

	cout << "http://www.ehmtheblueline.com/" << endl << endl
		 << "Custom Start Date Database Reversal Tool" << endl
		 << "Version 1.0" << endl
		 << "By Archibalduk" << endl << endl

		 << "Enter the start year of the CSD rosters to convert." << endl
		 << "E.g. if the rosters are designed for 2011/12 then enter 2011." << endl << endl

		 << "Enter start year of CSD rosters: ";

	short rostersYear;
	cin >> rostersYear;

	AlterAmount = rostersYear - 2006;

	cin.ignore();
	cout << endl << "The years will be decreased by " << AlterAmount << " years. Press ENTER to confirm." << endl;
	cin.get();

	cout << "Please wait..." << endl << endl;

	cout << setiosflags(ios::left);
	short col1 = 30;

	cout << setw(col1) << "staff.dat";
	staff();

	cout << setw(col1) << "staff_history.dat";
	staff_history();

	cout << setw(col1) << "club_comp_history.dat";
	club_comp_history();

	cout << setw(col1) << "nation_comp_history.dat";
	nation_comp_history();

	cout << setw(col1) << "staff_comp_history.dat";
	staff_comp_history();

	cout << setw(col1) << "drafted_players.dat";
	drafted_players();

	cout << setw(col1) << "club_histories.dat";
	club_histories();

	cout << setw(col1) << "club_records.dat";
	club_records();

	cout << endl << "Conversion complete."
		 << endl << endl << "Press ENTER to close this window.";
	cin.get();

	return 0;
}