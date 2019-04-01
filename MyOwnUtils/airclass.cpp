#include <iomanip>
#include <sstream>

#include "airclass.h"
#include "Welcome.h"
#include "cinclearbuffer.cpp"

constexpr auto PI = 3.14159265358979323;

StringCollectionVentilation::StringCollectionVentilation()
{
}

StringCollectionVentilation::~StringCollectionVentilation()
{
}

void TubeProtocol::setMeasurementPoint( const std::string& )
{
	std::cout << std::endl << std::setw(40) << printInsertMeasurementPoint;
	std::getline( std::cin, insertMeasurementPoint );
	this-> insertMeasurementPoint;
}

void TubeProtocol::setDiameter( const double& ) 
{	
	std::cout << std::endl << std::setw(30) << "Calculate the Circular Area" << std::endl << std::endl;
	std::cout << std::setw(36) << "Please insert the Diameter in mm:";
	diameter = readValue<double>();
	std::cout << std::endl;
	this-> diameter = diameter;
}

void TubeProtocol::setCalcCircularArea( const double& )
{
	this-> circularArea = PI * ( ( ( diameter / 1000 ) * ( diameter / 1000 ) ) / 4 );
}

void TubeProtocol::setSetPointAirVolume( const double& )
{
	std::cout << std::setw(17) << "Setpoint input" << std::endl << std::endl;
	std::cout << std::setw(48) << "Please insert the Airvolume Setpoint in m3/h:";
	setPointAirVolume = readValue<double>();
	this-> setPointAirVolume = setPointAirVolume;
}

void TubeProtocol::setMeasuredSpeed( const double& )
{	
	std::cout << std::endl << std::setw(44) << "Please insert the measured Speed in m/s:";
	measuredSpeed = readValue<double>();
	speedMeasurementsCollection.emplace_back( measuredSpeed );
	this-> measuredSpeed = measuredSpeed;
	std::cout << std::endl << std::setw(44) << "Do you want to enter another Speed? y/n:";
} 

void TubeProtocol::setV_Max( const double&  )
{
	if ( measuredSpeed > V_max ) { V_max = measuredSpeed; }
	this-> V_max;
}

void TubeProtocol::setV_Min( const double&  )
{
	if ( measuredSpeed < V_min ) { V_min = measuredSpeed; }
	this-> V_min;
}

void TubeProtocol::setV_Sum( const double&  )
{
	this-> sumMeasuredSpeed = sumMeasuredSpeed + measuredSpeed;
}

void TubeProtocol::setCounterSpeedIn( const double&  )
{
	this-> counterSpeedIn++;
}

void TubeProtocol::setCalcSpeedAvInTubes( const double& , const double& )
{
	this-> expAvTube = setPointAirVolume / circularArea / 3600;
}

void TubeProtocol::setAverageSpeed( const double&  )
{
	this-> averageSpeed = sumMeasuredSpeed / counterSpeedIn;
}

void TubeProtocol::setAirvolume( const double&  )
{
	this-> airVolume = averageSpeed * circularArea * 3600;
}

void TubeProtocol::setDeviation( const double&  )
{
	this-> deviation = ( (airVolume - setPointAirVolume) / setPointAirVolume ) * 100;
}

std::string TubeProtocol::getinsertMeasurementPoint() const
{
	return this-> insertMeasurementPoint;
}

std::string TubeProtocol::speedMeasurementsCollectionToString() const
{
	int counter{};
	int counter2{};
	int counter3{};

	std::stringstream sss;
	sss << std::setprecision(2) << std::fixed;

	for( const double vec :  this -> speedMeasurementsCollection )
	{
		counter++;
		counter2++;
		counter3++;
		if( counter == speedMeasurementsCollection.size() )
		{	
			sss << vec << " m/s";
			sss << std::endl;
			continue;
		}
		if( counter2 != speedMeasurementsCollection.size() && counter2 < 3 ) 
		{
			sss << vec << " m/s, "; 
		}
		if( counter3 == 3 && counter != speedMeasurementsCollection.size() )
		{	
			sss << vec << " m/s";
			sss << std::endl << "                             ";
			counter2 = 0;
			counter3 = 0;
		}
	}
	return sss.str();
}

double TubeProtocol::getDiameter() const
{
	return this-> diameter;
}

double TubeProtocol::getCalcCircularArea() const
{
	return this-> circularArea;
}

double TubeProtocol::getSetPointAirVolume() const
{
	return this-> setPointAirVolume;
}

double TubeProtocol::getV_Max() const
{
	return this-> V_max;
}

double TubeProtocol::getV_Min() const
{
	return this-> V_min;
}

double TubeProtocol::getV_Sum() const
{
	return this-> sumMeasuredSpeed;
}
double TubeProtocol::getcounterSpeedIn() const
{
	return this-> counterSpeedIn;
}

double TubeProtocol::getCalcSpeedAvInTubes() const
{
	return this-> expAvTube;
}

double TubeProtocol::getSpeedAverage() const
{
	return this-> averageSpeed;
}

double TubeProtocol::getAirvolume() const
{
	return this-> airVolume;
}

double TubeProtocol::getDeviation() const
{
	return this-> deviation;
}

std::string TubeProtocol::toString() const
{
    std::stringstream ss;
	
	ss << std::setprecision(0) << std::fixed << std::setw(26) << "Measured Point:        "	<< std::setw(1)  << " " << std::setw(1)  << this->getinsertMeasurementPoint()	<< std::endl	<< std::endl;
	ss										 << std::setw(26) << "Measured Speeds        "	<< std::setw(3)  <<" = "<< this->speedMeasurementsCollectionToString()			<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(18) << "Calculated Data"			<< std::endl;								
	ss << std::setprecision(0) << std::fixed << std::setw(21) << "Setpoint AirVolume"		<< std::setw( 7) << "=" << std::setw(10) << this->getSetPointAirVolume()		<< " m3/h"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(11) << "Diameter"					<< std::setw(17) << "=" << std::setw(10) << this->getDiameter()					<< " mm"		<< std::endl;
	ss << std::setprecision(3) << std::fixed << std::setw(15) << "Circulararea"				<< std::setw(13) << "=" << std::setw(10) << this->getCalcCircularArea()			<< " m2"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw( 8) << "V-max"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Max()					<< " m/s"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw( 8) << "V-min"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Min()					<< " m/s"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw( 8) << "V-sum"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Sum()					<< " m/s"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(25) << "Number of measurements"	<< std::setw( 3) << "=" << std::setw(10) << this->getcounterSpeedIn()							<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(24) << printExpSpeed				<< std::setw( 4) << "=" << std::setw(10) << this->getCalcSpeedAvInTubes()		<< " m/s"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(15) << "Speedaverage"				<< std::setw(13) << "=" << std::setw(10) << this->getSpeedAverage()				<< " m/s"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(12) << "Airvolume"				<< std::setw(16) << "=" << std::setw(10) << this->getAirvolume()				<< " m3/h"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(12) << "Deviation"				<< std::setw(16) << "=" << std::setw(10) << this->getDeviation()				<< " %"			<< std::endl; 
 
    return ss.str();
}

TubeProtocol::~TubeProtocol()
{
}

void ExpSpeedAvInTubes::setDiameter( const double& ) 
{	
	std::cout << std::endl;
	std::cout << std::setw(36) << "Please insert the Diameter in mm:";
	diameter = readValue<double>();
	std::cout << std::endl;
	this-> diameter = diameter;
}

void ExpSpeedAvInTubes::setSetPointAirVolume( const double& )
{
	std::cout << std::setw(48) << "Please insert the Airvolume Setpoint in m3/h:";
	setPointAirVolume = readValue<double>();
	std::cout << std::endl;
	this-> setPointAirVolume = setPointAirVolume;
}

void ExpSpeedAvInTubes::setCalcSpeedAvInTubes( const double& , const double& )
{
	this-> expAvTube = setPointAirVolume / circularArea / 3600;
}

void ExpSpeedAvInTubes::setCalcCircularArea( const double& )
{
	this-> circularArea = PI * ( ( ( diameter / 1000 ) * ( diameter / 1000 ) ) / 4 );
}

double ExpSpeedAvInTubes::getDiameter() const	
{
	return this-> diameter;
}

double ExpSpeedAvInTubes::getSetPointAirVolume() const
{
	return this-> setPointAirVolume;
}

double ExpSpeedAvInTubes::getCalcSpeedAvInTubes() const
{
	return this-> expAvTube;
}

double ExpSpeedAvInTubes::getCalcCircularArea() const
{
	return this-> circularArea;
}

std::string ExpSpeedAvInTubes::toString() const
{
    std::stringstream ss;

	ss << std::setprecision(0) << std::fixed << std::setw(11) << "Diameter"				<< std::setw(17) << "=" << std::setw(10) << this->getDiameter()				<< " mm"	<< std::endl;
	ss << std::setprecision(3) << std::fixed << std::setw(15) << "Circulararea"			<< std::setw(13) << "=" << std::setw(10) << this->getCalcCircularArea()		<< " m2"	<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(21) << "Setpoint AirVolume"	<< std::setw( 7) << "=" << std::setw(10) << this->getSetPointAirVolume()	<< " m3/h"	<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(24) << printExpSpeed			<< std::setw( 4) << "=" << std::setw(10) << this->getCalcSpeedAvInTubes()	<< " m/s"	<< std::endl; 
 
    return ss.str();
}

ExpSpeedAvInTubes::~ExpSpeedAvInTubes()
{
}

void DuctProtocol::setMeasurementPoint( const std::string& )
{
	std::cout << std::endl << std::setw(40) << printInsertMeasurementPoint;
	std::getline( std::cin, insertMeasurementPoint );
	this->insertMeasurementPoint;
}

void DuctProtocol::setWidth( const double&  )
{
	std::cout << std::endl;
	std::cout << std::setw(33) << "Please insert the width in mm:";
	width = readValue<double>();
	std::cout << std::endl;
	this-> width = width;
}

void DuctProtocol::setHeight( const double&  )
{
	std::cout << std::setw(34) << "Please insert the height in mm:";
	height = readValue<double>();
	std::cout << std::endl;
	this-> height = height;
}

void DuctProtocol::setCalcOrthogonArea( const double& , const double& )
{
	this-> orthogonArea = ( ( width / 1000 ) * ( height / 1000 ) );
}

void DuctProtocol::setSetPointAirVolume( const double& )
{
	std::cout << std::setw(17) << "Setpoint input" << std::endl << std::endl;
	std::cout << std::setw(48) << "Please insert the Airvolume Setpoint in m3/h:";
	setPointAirVolume = readValue<double>();
	this-> setPointAirVolume = setPointAirVolume;
}

void DuctProtocol::setMeasuredSpeed( const double& )
{
	std::cout << std::endl << std::setw(44) << "Please insert the measured Speed in m/s:";
	measuredSpeed = readValue<double>();
	speedMeasurementsCollection.emplace_back( measuredSpeed );
	this-> measuredSpeed = measuredSpeed;
	std::cout << std::endl << std::setw(44) << "Do you want to enter another Speed? y/n:";
} 

void DuctProtocol::setV_Max( const double&  )
{
	if ( measuredSpeed > V_max ) { V_max = measuredSpeed; }
	this-> V_max;
}

void DuctProtocol::setV_Min( const double&  )
{
	if ( measuredSpeed < V_min ) { V_min = measuredSpeed; }
	this-> V_min;
}

void DuctProtocol::setV_Sum( const double&  )
{
	this-> sumMeasuredSpeed = sumMeasuredSpeed + measuredSpeed;
}

void DuctProtocol::setCounterSpeedIn( const double&  )
{
	this-> counterSpeedIn++;
}

void DuctProtocol::setCalcSpeedAvInDucts( const double& , const double& )
{
	this-> expAvDuct = setPointAirVolume / orthogonArea / 3600;
}

void DuctProtocol::setAverageSpeed ( const double&  )
{			
	this-> averageSpeed = sumMeasuredSpeed / counterSpeedIn;
}

void DuctProtocol::setAirvolume ( const double&  )
{			
	this-> airVolume = averageSpeed * orthogonArea * 3600;
}

void DuctProtocol::setDeviation ( const double&  )
{			
	this-> deviation =( (airVolume - setPointAirVolume) / setPointAirVolume ) * 100;
}

std::string DuctProtocol::getinsertMeasurementPoint() const
{
	return this-> insertMeasurementPoint;
}

std::string DuctProtocol::speedMeasurementsCollectionToString() const
{
	int counter{};
	int counter2{};
	int counter3{};

	std::stringstream sss;
	sss << std::setprecision(2) << std::fixed;

	for( const double vec :  this -> speedMeasurementsCollection )
	{
		counter++;
		counter2++;
		counter3++;
		if( counter == speedMeasurementsCollection.size() )
		{	
			sss << vec << " m/s";
			sss << std::endl;
			continue;
		}
		if( counter2 != speedMeasurementsCollection.size() && counter2 < 3 ) 
		{
			sss << vec << " m/s, "; 
		}
		if( counter3 == 3 && counter != speedMeasurementsCollection.size() )
		{	
			sss << vec << " m/s";
			sss << std::endl << "                             ";
			counter2 = 0;
			counter3 = 0;
		}
	}
	return sss.str();
}

double DuctProtocol::getSetPointAirVolume() const
{
	return this-> setPointAirVolume;
}

double DuctProtocol::getWidth() const
{
	return this-> width;
}

double DuctProtocol::getHeight() const
{
	return this-> height;
}

double DuctProtocol::getCalcOrthogonArea() const
{
	return this-> orthogonArea;
}

double DuctProtocol::getV_Max() const
{
	return this-> V_max;
}

double DuctProtocol::getV_Min() const
{
	return this-> V_min;
}

double DuctProtocol::getV_Sum() const
{
	return this-> sumMeasuredSpeed;
}
double DuctProtocol::getcounterSpeedIn() const
{
	return this-> counterSpeedIn;
}

double DuctProtocol::getCalcSpeedAvInDucts() const
{
	return this-> expAvDuct;
}

double DuctProtocol::getSpeedAverage() const
{
	return this-> averageSpeed;
}

double DuctProtocol::getAirvolume() const
{
	return this-> airVolume;
}

double DuctProtocol::getDeviation() const
{
	return this-> deviation;
}

std::string DuctProtocol::toString() const
{
    std::stringstream ss;

	ss << std::setprecision(0) << std::fixed << std::setw(26) << "Measured Point:        "  << std::setw(1)  << " " << std::setw(1)  << this->getinsertMeasurementPoint()	<< std::endl	<< std::endl;
	ss										 << std::setw(26) << "Measured Speeds        "	<< std::setw(3)  <<" = "<< this->speedMeasurementsCollectionToString()			<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(18) << "Calculated Data"			<< std::endl;								
	ss << std::setprecision(0) << std::fixed << std::setw(21) << "Setpoint AirVolume"		<< std::setw(7)  << "=" << std::setw(10) << this->getSetPointAirVolume()		<< " m3/h"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw( 8) << "Width"					<< std::setw(20) << "=" << std::setw(10) << this->getWidth()					<< " mm"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw( 9) << "Height"					<< std::setw(19) << "=" << std::setw(10) << this->getHeight()					<< " mm"		<< std::endl;
	ss << std::setprecision(3) << std::fixed << std::setw(15) << "Orthogonarea"				<< std::setw(13) << "=" << std::setw(10) << this->getCalcOrthogonArea()			<< " m2"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw( 8) << "V-max"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Max()					<< " m/s"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw( 8) << "V-min"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Min()					<< " m/s"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw( 8) << "V-sum"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Sum()					<< " m/s"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(25) << "Number of measurements"	<< std::setw( 3) << "=" << std::setw(10) << this->getcounterSpeedIn()							<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(24) << printExpSpeed				<< std::setw( 4) << "=" << std::setw(10) << this->getCalcSpeedAvInDucts()		<< " m/s"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(15) << "Speedaverage"				<< std::setw(13) << "=" << std::setw(10) << this->getSpeedAverage()				<< " m/s"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(12) << "Airvolume"				<< std::setw(16) << "=" << std::setw(10) << this->getAirvolume()				<< " m3/h"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(12) << "Deviation"				<< std::setw(16) << "=" << std::setw(10) << this->getDeviation()				<< " %"			<< std::endl; 
 
    return ss.str();
}

DuctProtocol::~DuctProtocol()
{
}

void ExpSpeedAvInDucts::setWidth( const double&  )
{
	std::cout << std::endl;
	std::cout << std::setw(33) << "Please insert the width in mm:";
	width = readValue<double>();
	std::cout << std::endl;
	this-> width = width;
}

void ExpSpeedAvInDucts::setHeight( const double&  )
{
	std::cout << std::setw(34) << "Please insert the height in mm:";
	height = readValue<double>();
	std::cout << std::endl;
	this-> height = height;
}

void ExpSpeedAvInDucts::setCalcOrthogonArea( const double& , const double& )
{
	this-> orthogonArea = ( ( width / 1000 ) * ( height / 1000 ) );
}

void ExpSpeedAvInDucts::setSetPointAirVolume( const double&  )
{
	std::cout << std::setw(48) << "Please insert the Airvolume Setpoint in m3/h:";
	setPointAirVolume = readValue<double>();
	std::cout << std::endl;
	this-> setPointAirVolume = setPointAirVolume;
}

void ExpSpeedAvInDucts::setCalcSpeedAvInDucts( const double& , const double& )
{
	this-> expAvDuct = setPointAirVolume / orthogonArea / 3600;
}

double ExpSpeedAvInDucts::getWidth() const
{
	return this-> width;
}

double ExpSpeedAvInDucts::getHeight() const
{
	return this-> height;
}

double ExpSpeedAvInDucts::getCalcOrthogonArea() const
{
	return this-> orthogonArea;
}

double ExpSpeedAvInDucts::getSetPointAirVolume() const
{
	return this-> setPointAirVolume;
}

double ExpSpeedAvInDucts::getCalcSpeedAvInDucts() const
{
	return this-> expAvDuct;
}

std::string ExpSpeedAvInDucts::toString() const
{
	std::stringstream ss;

	ss << std::setprecision(0) << std::fixed << std::setw( 8) << "Width"				<< std::setw(20) << "=" << std::setw(10) << this->getWidth()				<< " mm"	<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw( 9) << "Height"				<< std::setw(19) << "=" << std::setw(10) << this->getHeight()				<< " mm"	<< std::endl;
	ss << std::setprecision(3) << std::fixed << std::setw(15) << "Orthogonarea"			<< std::setw(13) << "=" << std::setw(10) << this->getCalcOrthogonArea()		<< " m2"	<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(21) << "Setpoint AirVolume"	<< std::setw( 7) << "=" << std::setw(10) << this->getSetPointAirVolume()	<< " m3/h"	<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(24) << printExpSpeed			<< std::setw( 4) << "=" << std::setw(10) << this->getCalcSpeedAvInDucts()	<< " m/s"	<< std::endl; 
 
	return ss.str();
}

ExpSpeedAvInDucts::~ExpSpeedAvInDucts()
{
}

void VAVProtocol::setMeasurementPoint( const std::string& )
{
	std::cout << std::endl << std::setw(40) << printInsertMeasurementPoint;
	std::getline( std::cin, insertMeasurementPoint );
	this-> insertMeasurementPoint;
}

void VAVProtocol::setSetPointAirVolume( const double& )
{
	std::cout << std::endl;
	std::cout << std::setw(17) << "Setpoint input" << std::endl << std::endl;
	std::cout << std::setw(48) << "Please insert the Airvolume Setpoint in m3/h:";
	setPointAirVolume = readValue<double>();
	this-> setPointAirVolume = setPointAirVolume;
}

void VAVProtocol::setV_Nom( const double&  )
{
	std::cout << std::endl << std::setw(41) << "Please insert the V-Nom value in m3/h:";
	V_nom = readValue<double>();
	this-> V_nom;
}

void VAVProtocol::setV_Min( const double&  )
{
	std::cout << std::endl << std::setw(41) << "Please insert the V-Min value in m3/h:";
	V_min = readValue<double>();
	this-> V_min;
}

void VAVProtocol::setV_Max( const double&  )
{
	std::cout << std::endl << std::setw(41) << "Please insert the V-Max value in m3/h:";
	V_max = readValue<double>();
	this-> V_max;
}

void VAVProtocol::setDeputySignal( const std::string&  )
{
	do 
	{
		std::cout << std::endl << std::setw(26) << "Deputy Signal Selection"	  << std::endl << std::endl
				  << std::setw( 7)	<< "[1]" << std::setw(6) << "0-10" << std::setw(3) << "V " << std::endl
				  << std::setw( 7)	<< "[2]" << std::setw(6) << "2-10" << std::setw(3) << "V " << std::endl
				  << std::setw( 7)	<< "[3]" << std::setw(6) << "0-20" << std::setw(3) << "mA" << std::endl
				  << std::setw( 7)	<< "[4]" << std::setw(6) << "4-20" << std::setw(3) << "mA" << std::endl
				  << std::endl
				  << std::setw(28)	<< "Choose the Deputy Signal:";
		deputySig = readValue<int>();
		if( deputySig < 1 || deputySig > 4 )
		{
			ClearScreen();
			Welcome();
			AirVolMenu();
			std::cout << std::endl << std::setw(65) << "WARNING!!!! No Valid Entry!" << std::endl << std::endl;
		}
	} while( deputySig < 1 || deputySig > 4 );
	if     ( deputySig == 1 ) deputySigStr = "0-10 V " ;
	else if( deputySig == 2 ) deputySigStr = "2-10 V " ;
	else if( deputySig == 3 ) deputySigStr = "0-20 mA" ;
	else if( deputySig == 4 ) deputySigStr = "4-20 mA" ;
	this-> deputySigStr;
}

void VAVProtocol::setSpinDirection( const std::string& )
{
	do
	{
		std::cout << std::endl << std::setw(27) << "Spin-Direction Selection" << std::endl << std::endl
				  << std::setw( 7) << "[1]" <<std::setw(4)  << " cw" << std::endl
				  << std::setw( 7) << "[2]" << std::setw(5) << "ccw" << std::endl << std::endl
				  << std::setw(29) << "Choose the Spin-Direction:";
		spinDir = readValue<int>();
		if( spinDir < 1 || spinDir > 2 )
		{
			ClearScreen();
			Welcome();
			AirVolMenu();
			std::cout << std::endl << std::setw(65) << "WARNING!!!! No Valid Entry!" << std::endl;
		}
	} while( spinDir < 1 || spinDir > 2 );
	if     ( spinDir == 1 ) spinDirStr = "cw";
	else if( spinDir == 2 ) spinDirStr = "ccw";
	this-> spinDirStr;
}

void VAVProtocol::setMaxAirvolume ( const double&  )
{
	std::cout << std::endl << std::setw(45) << "Please insert the reading V-Max Airvolume:";
	maxAirVolume = readValue<double>();
	this-> maxAirVolume = maxAirVolume;
}

void VAVProtocol::setMinAirvolume ( const double&  )
{
	std::cout << std::endl << std::setw(45) << "Please insert the reading V-Min Airvolume:";
	minAirVolume = readValue<double>();
	this-> minAirVolume = minAirVolume;
}

void VAVProtocol::setDeviation( const double& )
{
	this-> deviation = ( ( maxAirVolume - setPointAirVolume ) / setPointAirVolume ) * 100;
}

std::string VAVProtocol::getinsertMeasurementPoint() const
{
	return this-> insertMeasurementPoint;
}

double VAVProtocol::getSetPointAirVolume() const
{
	return this-> setPointAirVolume;
}

double VAVProtocol::getV_Nom() const
{
	return this-> V_nom;
}

double  VAVProtocol::getV_Min() const
{
	return this-> V_min;
}

double VAVProtocol::getV_Max() const
{
	return this-> V_max;
}

std::string  VAVProtocol::getDeputySignal() const
{
	return this-> deputySigStr;
}

 
std::string VAVProtocol::getSpinDirection() const
{
	return this-> spinDirStr;
}

double VAVProtocol::getMaxAirvolume() const
{
	return this-> maxAirVolume;
}

double VAVProtocol::getMinAirvolume() const
{
	return this-> minAirVolume;
}

double  VAVProtocol::getDeviation() const
{
	return this-> deviation;
}

std::string VAVProtocol::toString() const
{
	std::stringstream ss;

	ss << std::setprecision(0) << std::fixed << std::setw(26) << "Measured Point:        "	<< std::setw( 1) << " " << std::setw( 1) << this->getinsertMeasurementPoint()	<< std::endl	<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(15) << "VAV/VVS Data"			<< std::endl;								
	ss << std::setprecision(0) << std::fixed << std::setw(21) << "Setpoint AirVolume"		<< std::setw( 7) << "=" << std::setw(10) << this->getSetPointAirVolume() << " m3/h"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw( 8) << "V-Nom"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Nom()			 << " m3/h"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw( 8) << "V-Min"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Min()			 << " m3/h"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw( 8) << "V-Max"					<< std::setw(20) << "=" << std::setw(10) << this->getV_Max()			 << " m3/h"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(16) << "Deputy Signal"			<< std::setw(12) << "=" << std::setw(13) << this->getDeputySignal()						<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(17) << "Spin Direction"			<< std::setw(11) << "=" << std::setw(10) << this->getSpinDirection()					<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(18) << "V-Max Airvolume"			<< std::setw(10) << "=" << std::setw(10) << this->getMaxAirvolume()		 << " m3/h"		<< std::endl;
	ss << std::setprecision(0) << std::fixed << std::setw(18) << "V-Min Airvolume"			<< std::setw(10) << "=" << std::setw(10) << this->getMinAirvolume()		 << " m3/h"		<< std::endl;
	ss << std::setprecision(2) << std::fixed << std::setw(12) << "Deviation"				<< std::setw(16) << "=" << std::setw(10) << this->getDeviation()		 << " %"		<< std::endl; 
 
    return ss.str();
}

VAVProtocol::~VAVProtocol()
{
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VentilatorPressure::VentilatorPressure()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
}

VentilatorPressure::~VentilatorPressure()
{
}

Dummy8::Dummy8()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy8::~Dummy8()
{
}
Dummy9::Dummy9()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy9::~Dummy9()
{
}
Dummy10::Dummy10()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy10::~Dummy10()
{
}
Dummy11::Dummy11()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy11::~Dummy11()
{
}
Dummy12::Dummy12()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy12::~Dummy12()
{
}
Dummy13::Dummy13()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy13::~Dummy13()
{
}
Dummy14::Dummy14()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy14::~Dummy14()
{
}
Dummy15::Dummy15()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy15::~Dummy15()
{
}
Dummy16::Dummy16()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy16::~Dummy16()
{
}
Dummy17::Dummy17()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy17::~Dummy17()
{
}
Dummy18::Dummy18()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy18::~Dummy18()
{
}
Dummy19::Dummy19()
{
	std::cout << std::endl << printEmptyFunc << std::endl;
	std::cin.get();
}
Dummy19::~Dummy19()
{
}