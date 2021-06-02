#ifndef RECORDER_H
#define RECORDER_H

/*
	Purpose: An abstract entity class. Contains specs for all derived classes
*/

#include <string>
#include <vector>
#include "Reservation.h"

class Recorder
{
	public:
		Recorder(string="");
		virtual void update(Reservation *) = 0;
		void printRecords();
		

	protected:
		string name;
		vector<string> records;
};

#endif

#ifndef STAYREC_H
#define STAYREC_H

/*
	Purpose: An entity class. Stores stay records
*/

#include <string>
#include "Reservation.h"

class StayRecorder : public Recorder
{
	public:
		StayRecorder(string="");
		virtual void update(Reservation *);		

};

#endif

#ifndef GUESTREC_H
#define GUESTREC_H

/*
	Purpose: An entity class. Stores guest records
*/

#include <string>
#include "Reservation.h"

class GuestRecorder : public Recorder
{
	public:
		GuestRecorder(string="");
		virtual void update(Reservation *);		

};

#endif

#ifndef UPGRADEREC_H
#define UPGRADEREC_H

/*
	Purpose: An entity class. Stores upgrade records
*/

#include <string>
#include "Reservation.h"

class UpgradeRecorder : public Recorder
{
	public:
		UpgradeRecorder(string="");
		virtual void update(Reservation *);		

};

#endif
